---
title: "题解 - [CodeForces 696 A] Lorenzo Von Matterhorn"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - 数据结构
  - 完全二叉树
date: 2020-07-25 00:48:00
---

[题目链接](https://codeforces.com/problemset/problem/696/A)

<!-- more -->

## 简述题意

给出一棵完全二叉树, 对其上任意结点$i$, 其子结点只能为$2i$和$2i+1$, 其父结点只能为$\lfloor\frac{i}{2}\rfloor$

处理两种操作

1. `1 u v w`: 将从`u`到`v`的最短路径经过的所有边加上权值`w` (权值不影响路径长度)
1. `2 u v`: 统计从`u`到`v`的最短路径经过的所有边权值之和

## 解题思路

对于树来说, 实现这两种操作我们自然会想到 LCA 之类的, 不过这道题有一个巧妙的解法可以绕过这些知识

我们用一个`map`来记录权值的变化, 在更新和查询权值时, 我们从`u`, `v`向上查找, 直到到达了`lca(u, v)`为止

由于这是在完全二叉树上, 我们并不需要去求`lca(u, v)`, 我们只需这样: 在每次循环的时候选`u`和`v`中编号较大的那个, 一边维护一边向上回溯, 当`u`和`v`相等的时候我们就已经维护到了`lca(u, v)`, 题目自然就解决了

## 代码

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-25 00:48:00
 * @Description: CF 696A
 */
map<i64, i64> m;

int main() {
  int kase;
  cin >> kase;
  i64 op, u, v, w;
  while (kase--) {
    cin >> op >> u >> v;
    if (op == 1) {
      cin >> w;
      while (u != v) {
        if (u > v) u ^= v ^= u ^= v;
        m[v] += w;
        v /= 2;
      }
    } else {
      i64 ans = 0;
      while (u != v) {
        if (u > v) u ^= v ^= u ^= v;
        ans += m[v];
        v /= 2;
      }
      cout << ans << endl;
    }
  }
}
```
