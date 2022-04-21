---
title: "题解 - [LightOJ 1245] Harmonic Number (II)"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - LightOJ
  - 数学
  - 数论分块/整除分块
date: 2020-07-25 00:12:29
---

[题目链接](https://vjudge.net/problem/LightOJ-1245/origin)

<!-- more -->

## 简述题意

求$\displaystyle\sum_{i=1}^n\left\lfloor\frac{n}{i}\right\rfloor$

## 解题思路

数论分块模板题

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-25 00:12:29
 * @Description: LightOJ 1245
 */

#include <cstdio>
using i64 = int64_t;
int main() {
  int kase;
  scanf("%d", &kase);
  for (int cnt = 1; cnt <= kase; ++cnt) {
    i64 n;
    scanf("%lld", &n);
    i64 ans = 0;
    for (i64 l = 1, r = 0; l <= n; l = r + 1) {
      r = n / (n / l);
      ans += (r - l + 1) * (n / l);
    }
    printf("Case %d: %lld\n", cnt, ans);
  }
  return 0;
}
```

</details>
