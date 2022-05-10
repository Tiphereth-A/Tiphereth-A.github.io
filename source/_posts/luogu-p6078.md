---
title: "题解 - [Luogu P6078] [CEOI2004] Sweets"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 数学
  - 组合数学
  - 生成函数
date: 2022-05-10 01:15:51
---

[题目链接](https://www.luogu.com.cn/problem/P6078)

<!-- more -->

## 原始题面

### 题目描述

John 得到了 $n$ 罐糖果. 不同的糖果罐, 糖果的种类不同 (即同一个糖果罐里的糖果种类是相同的, 不同的糖果罐里的糖果的种类是不同的). 第 $i$ 个糖果罐里有 $m_{i}$ 个糖果. John 决定吃掉一些糖果, 他想吃掉至少 $a$ 个糖果, 但不超过 $b$ 个. 问题是 John 无法确定吃多少个糖果和每种糖果各吃几个. 有多少种方法可以做这件事呢?

### 输入输出格式

#### 输入格式

输入共 $n+1$ 行: 第一行读入 $n$, $a$, $b$. 接下来 $n$ 行, 一行一个数, 代表 $m_{i}$

#### 输出格式

仅一行, 表示 John 能够选择的满足以上条件的吃掉糖果的方法数, 答案对 $2004$ 取模

### 输入输出样例

#### 输入样例 #1

```input1
2 1 3
3
5
```

#### 输出样例 #1

```output1
9
```

### 说明

#### 数据范围及限制

对于 $100\%$ 的数据, 保证 $1\leq n \leq 10$, $0\leq a \leq b \leq 10^7$, $0 \leq m_{i} \leq 10^6$

#### 说明

本题译自 [Central European Olympiad in Informatics 2004](https://www.oi.edu.pl/old/php/ceoi2004.php?module=show&file=news) [Day 1](https://www.oi.edu.pl/old/php/ceoi2004.php?module=show&file=tasks) [T2 Sweets](https://www.oi.edu.pl/old/ceoi2004/problems/swe.pdf)

## 解题思路

显然要转成 OGF, 题目即求

$$\prod_{k=1}^n\sum_{j=0}^{m_k}x^j$$

的 $x^a$ 到 $x^b$ 项的系数和

整理一下

$$
\begin{aligned}
  \prod_{k=1}^n\sum_{j=0}^{m_k}x^j&=\prod_{k=1}^n\frac{1-x^{m_k+1}}{1-x}\\
  &=(1-x)^{-n}\prod_{k=1}^n(1-x^{m_k+1})\\
  &=\left(\sum_{i=0}^{\infty}\binom{n+i-1}{i}x^i\right)\prod_{k=1}^n(1-x^{m_k+1})\\
\end{aligned}
$$

由于

$$\sum_{i=s-l+1}^s\binom{n+i-1}{i}=\binom{n+s}{n}-\binom{n+s-k}{n}$$

所以直接 DFS 即可

## 复杂度

$O(n2^n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa title:Luogu_6078 lang:cpp Luogu/6078/0.cpp %}

</details>
