---
title: "题解 - [Luogu P3704] [SDOI2017]数字表格"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 省选
  - SDOI
  - 数学
  - 数论
  - Möbius反演
date: 2021-06-02 13:24:59
---

[题目链接](https://www.luogu.com.cn/problem/P3704)

<!-- more -->

## 原始题面

### 题目背景

Doris 刚刚学习了 fibonacci 数列. 用 $f_i$ 表示数列的第 $i$ 项, 那么
$$f_0=0,f_1=1$$
$$f_n=f_{n-1}+f_{n-2},n\geq 2$$

### 题目描述

Doris 用老师的超级计算机生成了一个 $n\times m$ 的表格, 第 $i$ 行第 $j$ 列的格子中的数是 $f_{\gcd(i,j)}$, 其中 $\gcd(i,j)$ 表示 $i,j$ 的最大公约数. Doris 的表格中共有 $n\times m$ 个数, 她想知道这些数的乘积是多少. 答案对 $10^9+7$ 取模

### 输入输出格式

#### 输入格式

**本题单个测试点内有多组测试数据**. 输入的第一行是一个整数 $T$, 表示测试数据的组数. 接下来 $T$ 行, 每行两个整数 $n, m$, 表示一组数据

#### 输出格式

对于每组数据, 输出一行一个整数表示答案

### 输入输出样例

#### 输入样例 #1

```input1
3
2 3
4 5
6 7
```

#### 输出样例 #1

```output1
1
6
960
```

### 说明

数据规模与约定

- 对于 $10\%$ 的数据, 保证 $n,m\leq 10^2$
- 对于 $30\%$ 的数据, 保证 $n,m\leq 10^3$
- 另有 $30\%$ 的数据, 保证 $T\leq 3$
- 对于 $100\%$ 的数据, 保证 $1 \leq T\leq 10^3$, $1\leq n,m\leq 10^6$

## 解题思路

推式子, 不妨设 $n\geqslant m$

$$
\begin{aligned}
  \prod_{i=1}^n\prod_{j=1}^mf_{(i,j)}&=\prod_{d=1}^n\prod_{i=1}^{\lfloor\frac{n}{d}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{d}\rfloor}f_d^{[(i,j)=1]}\\
  &=\prod_{d=1}^nf_d^{\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{m}{d}\rfloor}[(i,j)=1]}\\
  &=\prod_{d=1}^nf_d^{\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{m}{d}\rfloor}\sum_{e\mid (i,j)}\mu(e)}\\
  &=\prod_{d=1}^nf_d^{\sum_{e=1}^{\lfloor\frac{n}{d}\rfloor}\mu(e)\lfloor\frac{n}{de}\rfloor\lfloor\frac{m}{de}\rfloor}\\
  &\xlongequal{D=de}\prod_{D=1}^n\bigg(\prod_{d\mid D}f_d^{\mu(\frac{D}{d})}\bigg)^{\lfloor\frac{n}{D}\rfloor\lfloor\frac{m}{D}\rfloor}
\end{aligned}
$$

其中 $\prod_{d\mid D}f_d^{\mu(\frac{D}{d})}$ 部分可以 $O(n\log n)$ 求出, 之后就是整除分块了

## 时间复杂度

$O(n\log n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P3704 Luogu/P3704/0.cpp %}

</details>
