---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 12)
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 代码源
  - CodeForces
  - 数学
  - DP
  - 概率DP
  - 期望
date: 2022-05-21 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.05.21-2022.05.27)

<!-- more -->

## 序列中 ab 的个数 (CF908D)

[题目链接](https://oj.daimayuan.top/problem/915)

5 s, 1024 MB

### 题目描述

给三个整数$k,pa,pb$, 最初有一个空序列,每一秒都可以执行以下操作, 以$pa$ $/$ $(pa+pb)$的概率将$a$添加到末尾或者以$pb$ $/$ $(pa+pb)$的概率将$b$添加到末尾, 一旦至少出现 k 个子序列$ab$, 就停止操作, 求最终子序列$ab$的期望次数, 输出一个整数$mod$ $(1e9+7)$

### 输入格式

一行输入三个整数$k,pa,pb$

### 输出格式

一个数, 表示答案。

### 样例 1 输入

```input1
3 1 4
```

### 样例 1 输出

```output1
370000006
```

### 样例 2 输入

```input2
1 1 1
```

### 样例 2 输出

```output2
2
```

### 数据规模

所有数据保证 $1 \le k \le 1000 ,1 \le pa,pb \le 1e6$

### 解题思路

> 概率 DP

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_908D CodeForces/908D/0.cpp %}

</details>
