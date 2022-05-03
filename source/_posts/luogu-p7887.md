---
title: 题解 - 「MCOI-06」Existence of Truth
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 数学
  - 数论
  - 逆元
  - 递推
date: 2021-10-05 23:23:44
---

[题目链接](https://www.luogu.com.cn/problem/P7887)

<!-- more -->

## 原始题面

### 题目描述

可能存在一个非负整数数序列 $a_1,a_2,\dots,a_n$ 使得 $0\le a_i<10^9+7$

给定 $x_1,x_2,\dots,x_n$, $y_1,y_2,\dots,y_n$, $z_1,z_2,\dots,z_n$, 已知对于 $1\le i\le n$ 满足:

$$x_i\left(\sum_{j=1}^ia_j\right)+y_i\left(\sum_{j=i}^na_j\right)\equiv z_i\pmod{10^9+7}$$

求 $a_1,a_2,\dots,a_n$

### 输入输出格式

#### 输入格式

> **本题有多组数据**

第一行一个正整数 $T$, 表示表示数据的组数. 对于每一组数据:

第一行一个正整数 $n$

接下来 $n$ 行, 每行三个正整数 $x_i,y_i,z_i$

#### 输出格式

对于每一组数据, 依次输出:

第一行一个非负整数 $k$, 为合法解数量

如果 $k=1$, 第二行输出 $n$ 个非负整数, 依次为 $a_1,a_2,\dots,a_n$

### 输入输出样例

#### 输入样例 #1

```input1
2
3
3 1 9
2 2 16
1 3 15
6
3 6 246
5 7 283
2 7 179
4 6 214
8 7 337
3 5 151
```

#### 输出样例 #1

```output1
1
1 2 3
1
8 8 0 6 7 8
```

#### 说明

##### 数据规模与约定

> **本题采用捆绑测试**

- Subtask 1 (10 pts): $n=1$
- Subtask 2 (19 pts): $\sum n\le100$
- Subtask 3 (19 pts): $x_i=y_i=1$
- Subtask 4 (22 pts): 保证有**唯一解**
- Subtask 5 (30 pts): 无特殊限制

对于所有数据:

- $1\le n,\sum n\le 2\times10^5$;
- $1\le x_i,y_i<10^9+7$;
- $0\le z_i<10^9+7$

## 解题思路

令

- $A_0=0$
- $A_n=\sum_{i=1}^na_i$
- $Y_i=-y_ix_i^{-1}$
- $Z_i=z_ix_i^{-1}$

则原式变为

$$x_iA_i+y_i(A_n-A_{i-1})\equiv z_i\pmod{10^9+7}$$

有

$$A_i\equiv Z_i+Y_i(A_n-A_{i-1})\pmod{10^9+7}$$

不难观察出 $\exist \{Z'_n\},\{Y'_n\}$ 使得
$$A_i=Z'_i+Y'_iA_n$$

顺次递推求出 $\{Z'_n\}$, $\{Y'_n\}$ 之后求出 $\{A_n\}$, $\{a_n\}$ 即可

另外注意由 $A_n=Z'_n+Y'_nA_n$ 来判断解的个数

## 时间复杂度

$O(n+\log p)=O(n)$, 其中 $p=1e9+7$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-05 23:23:44
 * @Description: Luogu P7887
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<i64, i64>;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)
#define _rfor(i, r, l, vals...) for (decltype(r - l) i = (r), ##vals; i >= (l); --i)

const int OFFSET = 5;
const int N = 2e5 + OFFSET;
const int MOD = 1e9 + 7;

template <typename T = i64>
T inverse(T a, T b = MOD - 2, T mod = MOD) {
    T res = 1;
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (res *= a) %= mod;
    return res;
}

i64 x[N], y[N], z[N];
i64 mx[N] = {1}, inv[N];
pii coeff[N];
i64 ans[N];

pii operator*(const pii& lhs, i64 rhs) {
    pii ret(lhs);
    (ret.first *= rhs) %= MOD;
    (ret.second *= rhs) %= MOD;
    return ret;
}
pii operator+(const pii& lhs, const pii& rhs) {
    return pii((lhs.first + rhs.first) % MOD, (lhs.second + rhs.second) % MOD);
}

void solve() {
    int n;
    cin >> n;
    _for(i, 1, n) cin >> x[i] >> y[i] >> z[i];

    _for(i, 1, n) mx[i] = mx[i - 1] * x[i] % MOD;
    inv[n] = inverse(mx[n]);
    _rfor(i, n, 1) inv[i - 1] = inv[i] * x[i] % MOD;
    _for(i, 1, n)(inv[i] *= mx[i - 1]) %= MOD;

    _for(i, 1, n) coeff[i] = {MOD - y[i], z[i]};
    coeff[1] = coeff[1] * inv[1];
    _for(i, 2, n) coeff[i] = (coeff[i - 1] * y[i] + coeff[i]) * inv[i];
    if (coeff[n].first == 1) {
        cout << (coeff[n].second ? 0 : MOD) << '\n';
        return;
    }

    ans[n] = coeff[n].second * inverse(MOD + 1 - coeff[n].first) % MOD;
    _for(i, 1, n - 1) ans[i] = (coeff[i].second + coeff[i].first * ans[n] % MOD) % MOD;
    cout << "1\n";
    _for(i, 1, n) cout << (ans[i] - ans[i - 1] + MOD) % MOD << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    cin >> _t;
    while (_t--) solve();
    return 0;
}
```

</details>
