---
title: '题解 - [LightOJ 1259] Goldbach`s Conjecture'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - LightOJ
  - 数学
  - 数论
  - 素数/质数
  - 筛法
date: 2020-07-25 00:19:21
---
[题目链接](https://vjudge.net/problem/LightOJ-1259/origin)

<!-- more -->

## 简述题意

给定$n$, 统计满足如下条件的数对$(a,b)$个数

1. $a,b$均为素数
1. $a+b=n$
1. $a\leqslant b$

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-25 00:19:21
 * @Description: LightOJ 1259
 */

#include <cstdio>
const int N = 1e7 + 5, M = 1e6 + 5;
int  pri[M], cnt_pri;
bool vis[N];
int main() {
  // Euler筛
  for (int i = 2; i < N; ++i) {
    if (!vis[i])
      pri[++cnt_pri] = i;
    for (int j = 1; j <= cnt_pri && pri[j] * i < N; ++j) {
      vis[pri[j] * i] = 1;
      if (!(i % pri[j]))
        break;
    }
  }

  int kase;
  scanf("%d", &kase);
  for (int cnt = 1, n, sum; cnt <= kase; ++cnt) {
    sum = 0;
    scanf("%d", &n);
    for (int i = 1; pri[i] <= n / 2; ++i) sum += !vis[n - pri[i]];
    printf("Case %d: %d\n", cnt, sum);
  }
  return 0;
}
```

</details>
