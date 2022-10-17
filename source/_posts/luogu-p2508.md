---
title: "题解 - [Luogu P2508] [HAOI2008]圆上的整点"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 省选
  - HAOI
  - 数学
  - 数论
  - Fermat二平方和定理
  - Gauss整数
date: 2021-10-29 03:09:51
---

[题目链接](https://www.luogu.com.cn/problem/P2508)

<!-- more -->

## 原始题面

### 题目描述

求一个给定的圆 $(x^2+y^2=r^2)$, 在圆周上有多少个点的坐标是整数

### 输入格式

r

### 输出格式

整点个数

### 样例 #1

#### 样例输入 #1

```input1
4
```

#### 样例输出 #1

```output1
4
```

### 提示

$r\leq 2000 000 000$

## 解题思路

显然我们只需要考虑第一象限的情况, 设

$$r^2=2^{2\alpha_2}\prod_{p\in\{x\in\text{Prime}^+|x=4k+3\}}p^{2\alpha_p}\prod_{q=\in\{x\in\text{Prime}^+|x=4k+1\}}q^{2\alpha_q}$$

我们知道任意素数都能分解为一对共轭的 Gauss 整数的乘积, 且由 [Fermat 二平方和定理](https://en.wikipedia.org/wiki/Fermat's_theorem_on_sums_of_two_squares), 只有 $q$ ($4k+1$ 型素数) 能分解为两正整数的平方和

不难发现答案即为

$$\prod_{q=\in\{x\in\text{Prime}^+|x=4k+1\}}(2\alpha_q+1)$$

最后乘 4 即为所求

## 复杂度

$O\left(\sqrt{r}\right)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P2508 Luogu/P2508/1.cpp %}

</details>
