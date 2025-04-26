---
title: "题解 - [Luogu P3768] 简单的数学题"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - 数论
  - Iverson括号
  - Möbius反演
  - 杜教筛
  - 数论分块/整除分块
date: 2021-11-08 18:38:23
---

强烈谴责这种起无意义标题的做法

[题目链接](https://www.luogu.com.cn/problem/P3768)

<!-- more -->

## 原始题面

### 题目描述

由于出题人懒得写背景了, 题目还是简单一点好

输入一个整数 $n$ 和一个整数 $p$, 你需要求出:

$$
\left(\sum_{i=1}^n\sum_{j=1}^n ij \gcd(i,j)\right) \bmod p
$$

其中 $\gcd(a,b)$ 表示 $a$ 与 $b$ 的最大公约数

### 输入输出格式

#### 输入格式

一行两个整数 $p,n$

#### 输出格式

一行一个整数表示答案

### 输入输出样例

#### 输入样例 #1

```input1
998244353 2000
```

### 输出样例 #1

```output1
883968974
```

### 说明

对于 20%的数据, $n \leq 1000$

对于 30%的数据, $n \leq 5000$

对于 60%的数据, $n \leq 10^6$, 时限 1s

对于另外 20%的数据, $n \leq 10^9$, 时限 3s

对于最后 20%的数据, $n \leq 10^{10}$, 时限 4s

对于 100%的数据, $5 \times 10^8 \leq p \leq 1.1 \times 10^9$ 且 $p$ 为质数

## 解题思路

推式子

$$
\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^n ij (i,j)&\equiv\sum_{d=1}^nd^3\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor} ij [(i,j)=1]\pmod p\\
  &\equiv\sum_{d=1}^nd^3\sum_{e=1}^{\lfloor\frac{n}{d}\rfloor}e^2\mu(e)\sum_{i=1}^{\lfloor\frac{n}{de}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{de}\rfloor} ij\pmod p\\
  &\overset{D=de}{\equiv}\sum_{D=1}^n\left({\lfloor\frac{n}{d}\rfloor\left(\lfloor\frac{n}{d}\rfloor+1\right)\over 2}\right)^2D^2\varphi(D)\pmod p\\
\end{aligned}
$$

令 $f(n)=n^2\varphi(n)$, 用杜教筛求 $S(n):=\sum_{i=1}^nf(i)$

令 $g(n)=n^2$, 有

$$
\begin{aligned}
 S(n)=g(1)S(n)&=\sum_{i=1}^n(f*g)(i)-\sum_{i=2}^ng(i)S\left(\left\lfloor\frac{n}{d}\right\rfloor\right)\\
  &=\left(\frac{n(n+1)}{2}\right)^2-\sum_{i=2}^ni^2S\left(\left\lfloor\frac{n}{d}\right\rfloor\right)
\end{aligned}
$$

## 时间复杂度

首先以 $O(m)$ 的时间复杂度预处理出 $S(1..m)$ (线性筛, $f$ 是积性的所以可以做到)

则时间复杂度为

$$
O\left(O(m)+\int_1^{\sqrt n}O\left(\frac{x}{\sqrt m}\right)\mathrm{d}x\right)=O\left(m+\frac{x}{\sqrt m}\right)
$$

选取合适的 $m$ 后即为 $O(n^\frac{2}{3})$

## 代码参考

{% icodeweb cpa_cpp title:Luogu_P3768 Luogu/P3768/0.cpp %}
