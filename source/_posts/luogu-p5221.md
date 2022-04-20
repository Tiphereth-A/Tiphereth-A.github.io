---
title: '题解 - [Luogu P5221] Product'
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
date: 2021-06-02 13:25:23
---

[题目链接](https://www.luogu.com.cn/problem/P5221)

<!-- more -->

## 原始题面

### 题目背景

${\rm CYJian}$: "听说$gcd$和$\sum$套起来比较好玩？？那我就......"

### 题目描述

${\rm CYJian}$最近闲的玩起了$gcd$. 他想到了一个非常简单而有意思的式子:
$$\prod_{i=1}^N\prod_{j=1}^N\frac{lcm(i,j)}{gcd(i,j)}\ (\bmod\ 104857601)$$
${\rm CYJian}$已经算出来这个式子的值了. 现在请你帮他验算一下吧. ${\rm CYJian}$只给你$0.2s$的时间哦

### 输入输出格式

#### 输入格式

一行一个正整数$N$

#### 输出格式

一行一个正整数，表示答案模$104857601$的值

### 输入输出样例

#### 输入样例 #1

```input1
5
```

#### 输出样例 #1

```output1
585494
```

### 说明

样例解释:
| $\frac{lcm}{gcd}$ |   1   |   2   |   3   |   4   |   5   |
| :---------------: | :---: | :---: | :---: | :---: | :---: |
|       **1**       |   1   |   2   |   3   |   4   |   5   |
|       **2**       |   2   |   1   |   6   |   2   |  10   |
|       **3**       |   3   |   6   |   1   |  12   |  15   |
|       **4**       |   4   |   2   |  12   |   1   |  20   |
|       **5**       |   5   |  10   |  15   |  20   |   1   |

对于$30\%$的数据: $1 \leq N \leq 5000$

对于$100\%$的数据: $1 \leq N \leq 1000000$

## 解题思路

推式子

$$
\begin{aligned}
  \prod_{i=1}^n\prod_{j=1}^n {ij\over (i,j)^2}&={(n!)^{2n}\over\prod_{i=1}^n\prod_{j=1}^n(i,j)^2}\\
  &={(n!)^{2n}\over\prod_{d=1}^nd^{2\sum_{i=1}^{\lfloor{n\over d}\rfloor}\sum_{j=1}^{\lfloor{n\over d}\rfloor}[(i,j)=1]}}\\
  &={(n!)^{2n}\over\prod_{d=1}^nd^{2\sum_{e=1}^{\lfloor{n\over d}\rfloor}\mu(e)\lfloor{n\over de}\rfloor^2}}\\
\end{aligned}
$$

两层整除分块即可

## 时间复杂度

$O(n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-06-02 13:25:23
 * @Description: Luogu P5221
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define _for(i, l, r) for (decltype(l + r) i = (l); i <= (r); ++i)
const int N = 1e6 + 2, mod = 104857601;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
i64 inv(i64 a) { return qpow(a, mod - 2); }

int prime[N / 10], cnt;
bool vis[N];
int smu[N];
void seive(int n = N - 2) {
    smu[1] = 1;
    _for(i, 2, n) {
        if (!vis[i]) smu[prime[++cnt] = i] = -1;
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            smu[i * prime[j]] = -smu[i];
        }
    }
    _for(i, 2, n) smu[i] += smu[i - 1];
}

int main() {
    seive();
    int n;
    cin >> n;
    i64 ans = 1;
    _for(i, 2, n)(ans *= i) %= mod;
    ans = qpow(ans, 2 * n);
    i64 fl = 1, fr = 1;
    int il = 1, ir = 1;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        i64 exp = 0;
        for (int l2 = 1, r2, n2 = n / l; l2 <= n2; l2 = r2 + 1) {
            r2 = n2 / (n2 / l2);
            (exp += 1ll * (n2 / l2) * (n2 / l2) % (mod - 1) * (smu[r2] - smu[l2 - 1] + mod - 1) % (mod - 1)) %= mod - 1;
        }
        while (ir <= r) (fr *= ir++) %= mod;
        while (il < l) (fl *= il++) %= mod;
        (ans *= qpow(inv(fr) * fl % mod, exp * 2 % (mod - 1))) %= mod;
    }
    cout << ans << endl;
}
```

</details>
