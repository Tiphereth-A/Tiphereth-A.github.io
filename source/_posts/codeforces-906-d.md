---
title: "题解 - [CodeForces 906 D] Power Tower"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - 数学
  - 数论
  - 递归
  - 快速幂
  - 扩展Euler定理
date: 2020-12-18 22:43:39
---

[题目链接](https://codeforces.com/problemset/problem/906/D)

<!-- more -->

## 原始题面

time limit per test: 4.5 seconds  
memory limit per test: 256 megabytes  
input: standard input  
output: standard output

### Description

Priests of the Quetzalcoatl cult want to build a tower to represent a power of their god. Tower is usually made of power-charged rocks. It is built with the help of rare magic by levitating the current top of tower and adding rocks at its bottom. If top, which is built from $k-1$ rocks, possesses power $p$ and we want to add the rock charged with power $w_k$ then value of power of a new tower will be $\{w_k\}^p$

Rocks are added from the last to the first. That is for sequence $w_1, ..., w_m$ value of power will be
$$w_1^{w_2^{\cdot^{\cdot^{\cdot^{w_m}}}}}$$
After tower is built, its power may be extremely large. But still priests want to get some information about it, namely they want to know a number called cumulative power which is the true value of power taken modulo $m$. Priests have $n$ rocks numbered from $1$ to $n$. They ask you to calculate which value of cumulative power will the tower possess if they will build it from rocks numbered $l, l + 1, ..., r$

### Input

First line of input contains two integers $n$ ($1 ≤ n ≤ 10^5$) and $m$ ($1 ≤ m ≤ 10^9$)

Second line of input contains $n$ integers $w_k$ ($1 ≤ w_k ≤ 10^9$) which is the power of rocks that priests have

Third line of input contains single integer $q$ ($1 ≤ q ≤ 10^5$) which is amount of queries from priests to you

kth of next $q$ lines contains two integers $l_k$ and $r_k$ ($1 ≤ l_k ≤ r_k ≤ n$)

### Output

Output $q$ integers. k-th of them must be the amount of cumulative power the tower will have if is built from rocks $l_k, l_{k + 1}, ..., r_k$

### Example

#### Input

```input1
6 1000000000
1 2 2 3 3 3
8
1 1
1 6
2 2
2 3
2 4
4 4
4 5
4 6
```

#### Output

```output1
1
1
2
4
256
3
27
597484987
```

### Note

$3^{27} = 7625597484987$

## 题意简述

给出$n,m,\def\enum#1{w_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 有$q$组询问, 每次给出$l,r$, 问
$$w_l^{w_{l+1}^{\cdot^{\cdot^{\cdot^{w_r}}}}}\bmod m$$

## 解题思路

由扩展 Euler 定理

$$
a^b\equiv\begin{cases}
  a^{b\bmod\varphi(m)+\varphi(m)},&(a,m)>1,b>\varphi(m)\\
  a^{b\bmod\varphi(m)},&\texttt{otherwise}\\
\end{cases}\pmod m
$$

递归求解即可

## 复杂度

$$\Theta\left(\log m+\sum_{i=1}^q\min\{r_i-l_i+1,\log m\}\right)\implies O(q\log m)$$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-12-18 22:43:39
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int N = 1e5 + 5;

int calc_phi(int p) {
    int ans = p;
    for (int i = 2; i <= sqrt(p); ++i)
        if (p % i == 0) {
            ans = ans / i * (i - 1);
            while (p % i == 0) p /= i;
        }
    if (p > 1) ans = ans / p * (p - 1);
    return ans;
}

i64 qpow(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    a > mod ? (a %= mod) += mod : 0;
    for (; b; b >>= 1, (a *= a) > mod ? (a %= mod) += mod : 0)
        if (b & 1) (res *= a) > mod ? (res %= mod) += mod : 0;
    return res;
}

int w[N];
unordered_map<int, int> phi;

i64 dfs(int l, int r, int x, i64 p) {
    if (x > r || p == 1) return 1;
    return qpow(w[x], dfs(l, r, x + 1, phi[p]), p);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", w + i);
    int _m = m;
    phi[1] = 1;
    while (_m > 1) {
        phi[_m] = calc_phi(_m);
        _m = phi[_m];
    }
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", dfs(l, r, l, m) % m);
    }
    return 0;
}
```

</details>
