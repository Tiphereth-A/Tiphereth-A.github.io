---
title: '题解 - [Luogu P6156] 简单题'
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
date: 2021-06-02 13:25:11
---

强烈谴责这种起无意义标题的做法

[题目链接](https://www.luogu.com.cn/problem/P6156)

<!-- more -->

## 原始题面

### 题目背景

zbw 遇上了一道题, 由于他急着去找 qby, 所以他想让你来帮他做

### 题目描述

给你 $n,k$ 求下式的值:
$$\sum\limits_{i=1}^n\sum\limits_{j=1}^n(i+j)^kf(\gcd(i,j))\gcd(i,j)$$
其中 $\gcd(i,j)$ 表示 $i,j$ 的最大公约数

$f$ 函数定义如下:

如果 $k$ 有平方因子 $f(k)=0$, 否则 $f(k)=1$

> 就是 $\mu^2$

**Update:平方因子定义 如果存在一个整数 $k(k>1),k^2|n$ 则 $k$ 是 $n$ 的一个平方因子**

**请输出答案对 $998244353$ 取模的值**

### 输入输出格式

#### 输入格式

一行两个整数 $n,k$

#### 输出格式

一行一个整数, 表示答案对 $998244353$ 取模后的值

### 输入输出样例

#### 输入样例 #1

```input1
3 3
```

#### 输出样例 #1

```output1
1216
```

#### 输入样例 #2

```input2
2 6
```

#### 输出样例 #2

```output2
9714
```

#### 输入样例 #3

```input3
18 2
```

#### 输出样例 #3

```output3
260108
```

#### 输入样例 #4

```input4
143 1
```

#### 输出样例 #4

```output4
7648044
```

### 说明

|   测试点    |         $n$         |      $k$      |
| :---------: | :-----------------: | :-----------: |
|    $1,2$    |     $\leq10^3$      |  $\leq10^3$   |
|    $3,4$    | $\leq2 \times 10^3$ | $\leq10^{18}$ |
|  $5 \sim8$  | $\leq5 \times 10^4$ | $\leq10^{18}$ |
|     $9$     | $\leq 5\times10^6$  |     $=1$      |
|   $10,11$   | $\leq 5\times10^6$  |     $=2$      |
|   $12,13$   | $\leq 5\times10^6$  |  $\leq10^3$   |
| $14 \sim20$ | $\leq 5\times10^6$  | $\leq10^{18}$ |

对于 $100\%$ 的数据, $1 \leq n \leq 5 \times 10^6$, $1 \leq k \leq 10^{18}$

**Update on 2020/3/16:** 时间调至 $1$s,卡掉了 $O(n\log k)$,$O(n\log mod)$ 的做法

## 解题思路

推式子

$$
\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^n(i+j)^k\mu^2((i,j))(i,j)&=\sum_{d=1}^nd^{k+1}\mu^2(d)\sum_{i=1}^{\lfloor{n\over d}\rfloor}\sum_{j=1}^{\lfloor{n\over d}\rfloor}(i+j)^k[(i,j)=1]\\
  &=\sum_{d=1}^nd^{k+1}\mu^2(d)\sum_{e=1}^{\lfloor{n\over d}\rfloor}e^k\mu(e)\sum_{i=1}^{\lfloor{n\over de}\rfloor}\sum_{j=1}^{\lfloor{n\over de}\rfloor}(i+j)^k\\
  &\xlongequal[D=de]{S(x)=\sum_{i=1}^x\sum_{j=1}^x(i+j)^k}\sum_{D=1}^nD^kS\left(\left\lfloor{n\over D}\right\rfloor\right)(\mu*\{\operatorname{id}\mu^2\})(D)
\end{aligned}
$$

其中

- $$S(n)=\sum_{i=1}^{2n}(-1)^{[i>n]}\sum_{j=1}^ij^k$$
- $$(\mu*\{\operatorname{id}\mu^2\})(p^k)=\begin{cases}
    1,&k=0\\
    p-1,&k=1\\
    -p,&k=2\\
    0,&k>2
  \end{cases}$$

## 时间复杂度

$O(n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-06-02 13:25:11
 * @Description: Luogu P6156
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define _for(i, l, r) for (decltype(l + r) i = (l); i <= (r); ++i)
const int N = 1e7 + 5, mod = 998244353;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int prime[N], cnt;
bool vis[N];
i64 sf[N], sik[N];
void seive(int n, i64 k) {
    sf[1] = sik[1] = 1;
    _for(i, 2, n) {
        if (!vis[i]) {
            prime[++cnt] = i;
            sf[i] = i - 1;
            sik[i] = qpow(i, k);
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            sik[i * prime[j]] = sik[i] * sik[prime[j]] % mod;
            sf[i * prime[j]] = sf[i] * (prime[j] - 1) % mod;
            if (i % prime[j] == 0) {
                sf[i * prime[j]] = ((i / prime[j]) % prime[j]) ? (mod - prime[j]) * sf[i / prime[j]] % mod : 0;
                break;
            }
        }
    }
    _for(i, 2, n) {
        sf[i] = (sf[i - 1] + sik[i] * sf[i] % mod) % mod;
        (sik[i] += sik[i - 1]) %= mod;
    }
    _for(i, 2, n)(sik[i] += sik[i - 1]) %= mod;
}

i64 s(int n) { return ((sik[n * 2] - 2 * sik[n] % mod) % mod + mod) % mod; }

int main() {
    int n;
    i64 k;
    cin >> n >> k;
    k %= mod - 1;
    seive(n * 2, k);
    i64 ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        (ans += (((sf[r] - sf[l - 1]) % mod + mod) % mod) * s(n / l)) %= mod;
    }
    cout << ans;
}
```

</details>