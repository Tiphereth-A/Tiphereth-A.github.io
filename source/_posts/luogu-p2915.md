---
title: "题解 - [Luogu P2915] [USACO08NOV]奶牛混合起来Mixed Up Cows"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - USACO
  - DP
  - 状压DP
date: 2020-01-17 10:26:14
---

[题目链接](https://www.luogu.com.cn/problem/P2915)

<!-- more -->

## 原始题面

### 题目描述

Each of Farmer John's N (4 <= N <= 16) cows has a unique serial number S_i (1 <= S_i <= 25,000). The cows are so proud of it that each one now wears her number in a gangsta manner engraved in large letters on a gold plate hung around her ample bovine neck.

Gangsta cows are rebellious and line up to be milked in an order called 'Mixed Up'. A cow order is 'Mixed Up' if the sequence of serial numbers formed by their milking line is such that the serial numbers of every pair of consecutive cows in line differs by more than K (1 <= K <= 3400). For example, if N = 6 and K = 1 then 1, 3, 5, 2, 6, 4 is a 'Mixed Up' lineup but 1, 3, 6, 5, 2, 4 is not (since the consecutive numbers 5 and 6 differ by 1).

How many different ways can N cows be Mixed Up?

For your first 10 submissions, you will be provided with the results of running your program on a part of the actual test data.

POINTS: 200

约翰家有 $N$ 头奶牛, 第 $i$ 头奶牛的编号是 $S_i$, 每头奶牛的编号都是唯一的

这些奶牛最近在闹脾气, 为表达不满的情绪, 她们在挤奶的时候一定要排成混乱的队伍

在一只混乱的队伍中, 相邻奶牛的编号之差均超过 $K$

比如当 $K = 1$ 时, `1, 3, 5, 2, 6, 4` 就是一支混乱的队伍, 而 `1, 3, 6, 5, 2, 4` 不是, 因为 6 和 5 只差 1

请数一数, 有多少种队形是混乱的呢?

### 输入输出格式

#### 输入格式

- Line 1: Two space-separated integers: N and K

- Lines 2..N+1: Line i+1 contains a single integer that is the serial number of cow i: S_i

#### 输出格式

- Line 1: A single integer that is the number of ways that N cows can be 'Mixed Up'. The answer is guaranteed to fit in a 64 bit integer.

### 输入输出样例

#### 输入样例 #1

```input1
4 1
3
4
2
1
```

#### 输出样例 #1

```output1
2
```

### 说明/提示

The 2 possible Mixed Up arrangements are:

3 1 4 2

2 4 1 3

## 解题思路

令 $f(n,m)$ 表示以 $m$ 结尾, 状态为 $n$ 时的方案数. 若 $n\ \mathrm{And}\ 2^{i-1} \neq 0$, 则说明 $i$ 在队伍中

- 初始状态
  $$f(2^{i-1},i)=1$$
- 状态转移方程
  $$f(i,j)=\displaystyle\sum_{k} f(i\oplus\ 2^{k-1},k)$$
  其中 $1\leqslant k\leqslant n,\ i\ \mathrm{And}\ 2^{k-1}=0$
- 最终结果:
  $$\sum_{i=1}^n f(2^n-1,i)$$

## 时间复杂度

$O(n^2 2^n)$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P2915 Luogu/P2915/0.cpp %}

</details>
