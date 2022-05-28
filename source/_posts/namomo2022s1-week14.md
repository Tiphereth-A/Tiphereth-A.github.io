---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 14)
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 代码源
  - CodeForces
  - 数学
  - Young表
  - 二分图染色
date: 2022-05-28 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.05.28-2022.06.03)

<!-- more -->

## 序列中 ab 的个数 (CF1268B)

[题目链接](https://oj.daimayuan.top/problem/964)

3 s, 1024 MB

### 题目描述

给一个图表, 图表是一个直方图, $n$列的高度分别为$a_1, a_2, \dots, a_n$$(a_1 \ge a_2 \ge a_3 .... \ge a_n)$, 你有许多大小为 $1 \times 2$ 的多米诺骨牌(可以旋转), 不重叠最多可以放置多少个呢

### 输入格式

第一行一个数字 $n$

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$

### 输出格式

一个数, 表示答案

### 样例输入

```input1
5
3 2 2 2 1
```

### 样例输出

```output1
4
```

### 数据规模

所有数据保证 $1\leq n\leq 300000, 1 \leq a_i \leq 300000$

### 解题思路

> 二分图染色

结论题, 如果 Young 表二分图染色后黑白两色的格子数相等, 则可以用骨牌密铺

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1268B CodeForces/1268B/0.cpp %}

</details>
