---
title: "题解 - [BalticOI 2016 day1] [Luogu P4674] [LOJ 2780] Bosses"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - BalticOI
  - 洛谷
  - LOJ
  - 贪心
  - 图论
  - 生成树
  - BFS
date: 2018-06-09 21:23:47
---

题目链接

- [Luogu P4674](https://www.luogu.com.cn/problem/P4674)
- [LOJ 2780](https://loj.ac/p/2780)

<!-- more -->

## 原始题面

### 题目描述

A company of $n$ employees is due for a restructuring. In the resulting hierarchy,represented as a rooted tree, every node will be the boss of its children.

Each employee has a list of bosses they will accept. In addition, all employees mustbe assigned a salary. The salary must be a positive integer, and the salary of eachboss must be larger than the sum of salaries of their immediate subordinates.

Your task is to structure the company so that all above conditions hold, and the sumof all the salaries is as small as possible.

### 输入格式

The first input line contains an integer $n$ : the number of employees. The employees are numbered $1,2,...,n$

.After this, the input contains $n$ lines that describe the preferences of the employees.The $i$th such line contains an integer $k_i$ , followed by a list of $k_i$ integers. The list consists of all employees that the $i$th employee accepts as their boss.

### 输出格式

You should output the lowest total salary among all valid restructurings. You can assume that at least one solution exists.

### 样例 #1

#### 样例输入 #1

```input1
4
1 4
3 1 3 4
2 1 2
1 3
```

#### 样例输出 #1

```output1
8
```

### 提示

#### Subtask 1 (22 points)

- $2\leq n \leq 10$

- $\sum^n_{i=1}k_i\leq 20$

#### Subtask 2 (45 points)

- $2\leq n \leq 100$

- $\sum^n_{i=1}k_i\leq 200$

#### Subtask 3 (33 points)

- $2\leq n \leq 5000$

- $\sum^n_{i=1}k_i\leq 10000$

## 题意简述

构造一棵带点权的树, 要求父结点权值不小于子结点权值和, 且所有点权均为正, 问合法的树的最小点权和

## 解题思路

对于一棵合法的树, 不难发现最小点权和即为所有点深度的和

所以我们应该让构造的树深度尽可能小, 那么很自然就可以想到 BFS

## 复杂度

$O(n\sum k_i)$

## 代码参考

{% icodeweb blog lang:cpp baltoi2016-1/std.cpp %}
