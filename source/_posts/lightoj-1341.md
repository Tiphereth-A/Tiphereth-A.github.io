---
title: "题解 - [LightOJ 1341] Aladdin and the Flying Carpet"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - LightOJ
  - 数学
  - 素数/质数
  - 数论
  - 筛法
date: 2020-07-25 00:29:43
---

[题目链接](https://vjudge.net/problem/LightOJ-1341/origin)

<!-- more -->

## 简述题意

给定$a$和$b$, 输出所有满足下列条件的数对$(c,d)$的个数

1. $cd=a$
1. $b\leqslant c\leqslant d$

## 解题思路

直接暴力求解会超时, 我们可以先预处理素数表, 这样就可以了

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-25 00:29:43
 * @Description: LightOJ 1341
 */

#include <cstdio>
using i64 = int64_t;
const int N = 1e6 + 5;
int  pri[N], cnt_pri;
bool vis[N];
int main() {
  for (int i = 2; i < N; ++i)
    if (!vis[i]) {
      pri[++cnt_pri] = i;
      for (int j = 2; i * j < N; ++j) vis[i * j] = 1;
    }
  int kase;
  scanf("%d", &kase);
  for (int cnt = 1; cnt <= kase; ++cnt) {
    i64 area, a;
    scanf("%lld%lld", &area, &a);
    if (area < a * a) {
      printf("Case %d: 0\n", cnt);
      continue;
    }
    i64 n = area, sum = 1;
    for (i64 i = 1, ans; i <= cnt_pri && pri[i] * pri[i] <= n; ++i) {
      if (!(n % pri[i])) {
        ans = 0;
        while (!(n % pri[i])) {
          ++ans;
          n /= pri[i];
        }
        sum *= ans + 1;
      }
    }
    sum >>= n <= 1;
    for (i64 i = 1; i < a; ++i) if (!(area % i)) sum--;
    printf("Case %d: %lld\n", cnt, sum);
  }
  return 0;
}
```

</details>
