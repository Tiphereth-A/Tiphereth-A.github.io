---
title: '题解 - [LightOJ 1282] Leading and Trailing'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - LightOJ
  - 数学
  - 快速幂
date: 2020-07-25 00:24:27
---
[题目链接](https://vjudge.net/problem/LightOJ-1282/origin)

<!-- more -->

## 简述题意

给定$n$和$k$, 输出$n^k$的前三位和后三位

## 解题思路

后三位直接用快速幂即可

前三位考虑取对数, 截取小数部分, 我们便可以通过这个还原出前三位了

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-25 00:24:27
 * @Description: LightOJ 1282
 * @Remark: pay attention of '(int)floor(...)' in line 29
 */

#include <cmath>

#include <cstdio>
using i64 = int64_t;
const int MOD = 1000;
i64 qpow(i64 a, i64 b, i64 mod = MOD) {
  i64 res = 1;
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (res *= a) %= mod;
  return res;
}
int main() {
  double _;
  int    kase;
  scanf("%d", &kase);
  for (int cnt = 1; cnt <= kase; ++cnt) {
    i64 a, k;
    scanf("%lld%lld", &a, &k);
    printf("Case %d: %d %03d\n", cnt, (int)floor(pow(10, modf(log10(a) * k, &_)) * 100), qpow(a, k));
  }
  return 0;
}
```

</details>
