---
title: '题解 - [Hydro #H1060] 绝世傻逼题'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - Hydro
  - 数学
  - 数论
  - Möbius反演
date: 2021-12-01 18:38:35
---

雀食

[题目链接](https://hydro.ac/p/H1060)

<!-- more -->

## 原始题面

### 题目描述

给定 $D,R,E,A,M$ 求:

$$\newcommand{\lcm}{\operatorname{lcm}}\sum_{d=1}^D\sum_{r=1}^R\sum_{e=1}^E\sum_{a=1}^A\sum_{m=1}^M\frac{\begin{matrix}\gcd(d,r,e)\gcd(d,r,a)\gcd(d,r,m)\gcd(d,e,a)\gcd(d,e,m)\\\gcd(d,a,m)\gcd(r,e,a)\gcd(r,e,m)\gcd(r,a,m)\gcd(e,a,m)\end{matrix}}{\begin{matrix}\gcd(\lcm(d,r),\lcm(d,e),\lcm(d,a),\lcm(d,m),\\\lcm(r,e),\lcm(r,a),\lcm(r,m),\lcm(e,a),\lcm(e,m),\\\lcm(a,m))^3\gcd(\lcm(d,r,e),\lcm(d,r,a),\lcm(d,r,m),\\\lcm(d,e,a),\lcm(d,e,m),\lcm(d,a,m),\lcm(r,e,a),\\\lcm(r,e,m),\lcm(r,a,m),\lcm(e,a,m))\end{matrix}}$$

答案对 $10^9+7$ 取模

### 输入格式

> **本题输入含有多组数据**

第一行一个正整数 $T$, 代表数据组数量。

接下来 $T$ 行, 每行五个正整数, 分别代表 $D,R,E,A,M$

### 输出格式

输出 $T$ 个正整数, 代表对应数据组答案

### 输入输出样例

#### 输入 #1

```input1
3
1 1 1 1 1
5 6 7 8 9
5642228 7263010 8833976 5087685 6171346
```

#### 输出 #1

```output1
1
82488
510550839
```

### 说明/提示

数据规模与约定

> **本题采用捆绑测试**

Subtask 1 (2 pts): $D,R,E,A,M\le10$

Subtask 2 (41 pts): $D,R,E,A,M\le100$

Subtask 3 (57 pts): 没有特殊限制

对于所有数据, $1\le T\le2000$, $1\le D,R,E,A,M\le5\times10^7$

## 题意简述

求

$$\sum_{(d,r,e,a,m)\in S}{\prod_{c}(\alpha,\beta)\over\gcd_{c}{}^3\{[\alpha,\beta]\}\gcd_{c}\{[\alpha,\beta,\gamma]\}}$$

其中

- $S=[1,D]\times[1,R]\times[1,E]\times[1,A]\times[1,M]$
- 下标的 $c$ 代表该算子枚举的是所有组合

## 解题思路

原题式子是真的丑, 用唯一分解定理算算就能得出是

$$\sum_{(d,r,e,a,m)\in S}\gcd{}^6\{d,r,e,a,m\}$$

然后就是经典套路变形

设

- $n=\min\{D,R,E,A,M\}$
- $\def\f#1{\lfloor\frac{ #1}{x}\rfloor}F(x)=\f{D}\f{R}\f{E}\f{A}\f{M}$

则所求为

$$\sum_{d=1}^nF(d)(\{n^6\}*\mu)(d)$$

然后大力数论分块搞搞就行了

另外注意常数, 我卡了半天常才过

~~std 的速度比我的快了一倍多, 不知道怎么写的, 反正卡过了就完事了~~

## 复杂度

$O(N+T\sqrt N)$, 其中 $N=\max\{D,R,E,A,M\}$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-12-01 18:38:35
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int OFFSET = 1;
const int N = 5e7 + OFFSET, P = 6002268 + OFFSET;
const int MOD = 1e9 + 7;

bool vis[N];
int f[N];
int prime[P], cnt_prime;

inline constexpr i128 pow6(int k) {
    k = (1ll * k * k) % MOD;
    return (i128)k * k * k % MOD;
}

inline void init_prime(const int& n = N - 1) {
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i])
            f[prime[++cnt_prime] = i] = pow6(i) - 1;
        for (int j = 1; j <= cnt_prime && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            f[i * prime[j]] = f[i] * pow6(prime[j]) % MOD;
            if (f[i * prime[j]] >= MOD) f[i * prime[j]] -= MOD;
            if (i % prime[j] == 0) break;
            if ((f[i * prime[j]] -= f[i]) < 0) f[i * prime[j]] += MOD;
        }
    }
    for (int i = 2; i <= n; ++i)
        if ((f[i] += f[i - 1]) >= MOD) f[i] -= MOD;
}

auto __STATIC__ = []() {
    init_prime();
    return 0.0;
}();

inline constexpr int F(const int x, const int d, const int r, const int e, const int a, const int m) {
    return (i128)(d / x) * (r / x) * (e / x) * (a / x) % MOD * (m / x) % MOD;
}

int _m;
i128 ans;
int d, r, e, a, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    cin >> _t;
    while (_t--) {
        cin >> d >> r >> e >> a >> m;
        _m = min({d, r, e, a, m});
        ans = 0;
        for (int _l = 1, _r; _l <= _m; _l = _r + 1) {
            _r = min({d / (d / _l), r / (r / _l), e / (e / _l), a / (a / _l), m / (m / _l)});
            ans += 1ll * (f[_r] - f[_l - 1] + MOD) * F(_l, d, r, e, a, m) % MOD;
        }
        cout << (int)(ans % MOD) << '\n';
    }
    return 0;
}
```

</details>
