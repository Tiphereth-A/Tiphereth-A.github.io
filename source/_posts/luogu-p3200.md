---
title: '题解 - [Luogu P3200] [HNOI2009]有趣的数列'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 省选
  - HNOI
  - 递推
  - 数学
  - 数论
  - 素数/质数
  - 筛法
  - Euler筛
  - 组合数学
  - Catalan数
date: 2021-11-03 17:56:45
---

[题目链接](https://www.luogu.com.cn/problem/P3200)

<!-- more -->

## 原始题面

### 题目描述

我们称一个长度为 $2n$ 的数列是有趣的, 当且仅当该数列满足以下三个条件:

- 它是从 $1 \sim 2n$ 共 $2n$ 个整数的一个排列 $\{a_n\}_{n=1}^{2n}$;
- 所有的奇数项满足 $a_1<a_3< \dots < a_{2n-1}$, 所有的偶数项满足 $a_2<a_4< \dots <a_{2n}$;
- 任意相邻的两项 $a_{2i-1}$ 与 $a_{2i}$ 满足: $a_{2i-1}<a_{2i}$

对于给定的 $n$, 请求出有多少个不同的长度为 $2n$ 的有趣的数列. 因为最后的答案可能很大, 所以只要求输出答案对 $p$ 取模

### 输入输出格式

#### 输入格式

一行两个正整数 $n,p$

#### 输出格式

输出一行一个整数表示答案

### 输入输出样例

#### 输入样例 #1

```input1
3 10
```

#### 输出样例 #1

```output1
5
```

### 说明

【数据范围】

对于 $50\%$ 的数据, $1\le n \le 1000$;

对于 $100\%$ 的数据, $1\le n \le 10^6$, $1\le p \le 10^9$

【样例解释】

对应的5个有趣的数列分别为 (1,2,3,4,5,6), (1,2,3,5,4,6), (1,3,2,4,5,6), (1,3,2,5,4,6), (1,4,2,5,3,6)

## 题意简述

求

$$H_{n-1}\bmod p={ {2n\choose n}\over n+1}\bmod p$$

## 解题思路

首先筛出所有素数, 然后计算答案唯一分解式的各个幂次即可

注意到 $(ab)^c=a^cb^c$, 故这些幂次可以逆序线性递推得到

## 复杂度

$O(n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-03 17:56:45
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)
#define _rfor(i, r, l, vals...) for (decltype(r - l) i = (r), ##vals; i >= (l); --i)

const int N = 2e6 + 5, P = 1.5e5 + 5;

int prime[P], factor_prime;
int min_prime_factor[N];
inline void init_prime(const int& n = N - 1) {
    for (int i = 2; i <= n; ++i) {
        if (!min_prime_factor[i]) min_prime_factor[prime[++factor_prime] = i] = i;
        for (int j = 1; j <= factor_prime && i * prime[j] <= n; ++j) {
            min_prime_factor[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

i64 qpow(i64 a, i64 b, const i64& mod) {
    i64 res(1);
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (res *= a) %= mod;
    return res;
}

const auto __STATIC__ = []() { init_prime(); return 0.0; }();

int expon[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    i64 n, p;
    cin >> n >> p;
    _for(i, 2, n) expon[i] = -1;
    _for(i, n + 2, 2 * n) expon[i] = 1;
    _rfor(i, 2 * n, 2) if (min_prime_factor[i] < i) {
        expon[min_prime_factor[i]] += expon[i];
        expon[i / min_prime_factor[i]] += expon[i];
    }
    i64 ans = 1;
    _rfor(i, 2 * n, 2) if (min_prime_factor[i] == i)(ans *= qpow(i, expon[i], p)) %= p;
    cout << ans;
    return 0;
}
```

</details>
