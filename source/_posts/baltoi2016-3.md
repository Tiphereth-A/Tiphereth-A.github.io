---
title: "题解 - [BalticOI 2016 day1] [Luogu P4676] [LOJ 2782] Spiral"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - BalticOI
  - 洛谷
  - LOJ
  - 数学
date: 2018-06-09 21:23:49
---

题目链接

- [Luogu P4676](https://www.luogu.com.cn/problem/P4676)
- [LOJ 2782](https://loj.ac/p/2782)

<!-- more -->

## 原始题面

### 题目描述

A grid of size $(2n+1)\times(2n+1)$ has been constructed as follows. Number $1$ has been placed in the center square, number $2$ has been placed to the right of it, and the following numbers have been placed along the spiral counterclockwise.

Your task is to calculate answers for $q$ queries where the sum of numbers in an rectangular region in the grid is requested (modulo $10^9+7$). For example, in the following grid $n=2$ and the sum of numbers in the gray region is $74$ :

![](1.webp)

### 输入格式

The first input line contains two integers $n$ and $q$ : the size of the grid and the number of queries.

After this, there are $q$ lines, each containing four integers $x_1, y_1, x_2$ and $y_2$ ($-n\leq x_1\leq x_2\leq n, -n\leq y_1\leq y_2\leq n$). This means that you should calculate the sum of numbers in a rectangular region with corners $(x_1,y_1)$ and $(x_2,y_2)$.

### 输出格式

You should output the answer for each query (modulo $10^9+7$).

### 样例 #1

#### 样例输入 #1

```input1
2 3
0 -2 1 1
-1 0 1 0
1 2 1 2
```

#### 样例输出 #1

```output1
74
9
14
```

### 提示

In all subtasks $1\leq q\leq100$.

#### Subtask 1 (12 points)

- $1\leq n\leq1000$

#### Subtask 2 (15 points)

- $1\leq n\leq10^9$

- $x_1=x_2$ and $y_1=y_2$

#### Subtask 3 (17 points)

- $1\leq n\leq10^5$

#### Subtask 4 (31 points)

- $1\leq n\leq10^9$

- $x_1=y_1=1$

#### Subtask 5 (25 points)

- $1\leq n\leq10^9$

## 题意简述

给一个螺旋矩阵, 每次询问给出一个子矩阵, 问子矩阵中的元素和

## 解题思路

大力分讨

## 复杂度

$O(q)$

## 代码参考

{% icodeweb blog lang:cpp baltoi2016-3/std.cpp %}
