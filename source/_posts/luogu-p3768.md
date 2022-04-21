---
title: '题解 - [Luogu P3768] 简单的数学题'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 数学
  - 数论
  - Möbius反演
  - 杜教筛
  - 数论分块/整除分块
date: 2021-11-08 18:38:23
---

强烈谴责这种起无意义标题的做法

[题目链接](https://www.luogu.com.cn/problem/P3768)

<!-- more -->

## 原始题面

### 题目描述

由于出题人懒得写背景了, 题目还是简单一点好

输入一个整数 $n$ 和一个整数 $p$, 你需要求出:

$$\left(\sum_{i=1}^n\sum_{j=1}^n ij \gcd(i,j)\right) \bmod p$$

其中 $\gcd(a,b)$ 表示 $a$ 与 $b$ 的最大公约数

### 输入输出格式

#### 输入格式

一行两个整数 $p,n$

#### 输出格式

一行一个整数表示答案

### 输入输出样例

#### 输入样例 #1

```input1
998244353 2000
```

### 输出样例 #1

```output1
883968974
```

### 说明

对于20%的数据, $n \leq 1000$

对于30%的数据, $n \leq 5000$

对于60%的数据, $n \leq 10^6$, 时限1s

对于另外20%的数据, $n \leq 10^9$, 时限3s

对于最后20%的数据, $n \leq 10^{10}$, 时限4s

对于100%的数据, $5 \times 10^8 \leq p \leq 1.1 \times 10^9$ 且 $p$ 为质数

## 解题思路

推式子

$$
\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^n ij (i,j)&\equiv\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor} ij [(i,j)=1]\pmod p\\
  &\equiv\sum_{d=1}^nd^3\sum_{e=1}^{\lfloor\frac{n}{d}\rfloor}e^2\mu(e)\sum_{i=1}^{\lfloor\frac{n}{de}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{de}\rfloor} ij\pmod p\\
  &\overset{D=de}{\equiv}\sum_{D=1}^n\left({\lfloor\frac{n}{d}\rfloor\left(\lfloor\frac{n}{d}\rfloor+1\right)\over 2}\right)^2D^2\varphi(D)\pmod p\\
\end{aligned}
$$

令 $f(n)=n^2\varphi(n)$, 用杜教筛求 $S(n):=\sum_{i=1}^nf(i)$

令 $g(n)=n^2$, 有

$$\begin{aligned}
 S(n)=g(1)S(n)&=\sum_{i=1}^n(f*g)(i)-\sum_{i=2}^ng(i)S\left(\left\lfloor\frac{n}{d}\right\rfloor\right)\\
  &=\left(\frac{n(n+1)}{2}\right)^2-\sum_{i=2}^ni^2S\left(\left\lfloor\frac{n}{d}\right\rfloor\right)
\end{aligned}$$

## 时间复杂度

首先以 $O(m)$ 的时间复杂度预处理出 $S(1..m)$ (线性筛, $f$ 是积性的所以可以做到)

则时间复杂度为

$$O\left(O(m)+\int_1^{\sqrt n}O\left(\frac{x}{\sqrt m}\right)\mathrm{d}x\right)=O\left(m+\frac{x}{\sqrt m}\right)$$

选取合适的 $m$ 后即为 $O(n^\frac{2}{3})$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-08 18:38:23
 * @Description: Luogu P3768
 */
#include <bits/stdc++.h>
using namespace std;

namespace Du_seive {
using data_type = int64_t;

const int N = 6e6 + 1, P = N / 10 + 1;
data_type sf[N];
std::unordered_map<data_type, data_type> sum_f;

data_type prime[P], prime2[P], prime3[P], cnt;
bool vis[N];

inline void init(const data_type& p, const data_type& n = N - 1) {
    sf[1] = 1;
    for (data_type i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime[++cnt] = i;
            prime3[cnt] = (prime2[cnt] = i * i % p) * i % p;
            sf[i] = (prime3[cnt] + p - prime2[cnt]) % p;
        }
        for (data_type j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            sf[i * prime[j]] = sf[i] * prime3[j] % p;
            if (i % prime[j] == 0) break;
            (sf[i * prime[j]] += p - sf[i] * prime2[j]) %= p;
        }
    }
    for (data_type i = 2; i <= n; ++i) (sf[i] += sf[i - 1]) %= p;
}

inline constexpr data_type sum_g(data_type n, const data_type& p) {
    n %= p;
    return n * (n + 1) / 2 % p * (2 * n + 1) % p * ((p + p * (p % 3 == 1) + 1) / 3) % p;
}
inline constexpr data_type sum_conv_g_f(data_type n, const data_type& p) {
    n %= p;
    data_type _ = n * (n + 1) / 2 % p;
    return _ * _ % p;
}

data_type get_sum_f_mul_g1(const data_type& n, const data_type& p) {
    if (n < N) return sf[n];
    if (sum_f[n]) return sum_f[n];
    data_type ans = sum_conv_g_f(n, p);
    for (data_type l = 2, r = 0; l <= n; l = r + 1) {
        r = n / (n / l);
        (ans += p - (sum_g(r, p) + p - sum_g(l - 1, p)) % p * get_sum_f_mul_g1(n / l, p) % p) %= p;
    }
    return sum_f[n] = ans;
}
}  // namespace Du_seive
using Du_seive::get_sum_f_mul_g1;
using Du_seive::init;

using i64=int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 n, p;
    cin >> p >> n;
    init(p);
    i64 ans = 0;
    for (i64 l = 1, r = 0; l <= n; l = r + 1) {
        r = n / (n / l);
        (ans += (get_sum_f_mul_g1(r, p) + p - get_sum_f_mul_g1(l - 1, p)) % p * Du_seive::sum_conv_g_f(n / l, p) % p) %= p;
    }
    cout << ans << '\n';
    return 0;
}
```

</details>
