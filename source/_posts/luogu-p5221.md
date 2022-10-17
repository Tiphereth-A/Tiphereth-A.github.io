---
title: "题解 - [Luogu P5221] Product"
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
date: 2021-06-02 13:25:23
---

[题目链接](https://www.luogu.com.cn/problem/P5221)

<!-- more -->

## 原始题面

### 题目背景

${\rm CYJian}$: "听说 $gcd$ 和 $\sum$ 套起来比较好玩？？那我就......"

### 题目描述

${\rm CYJian}$ 最近闲的玩起了 $gcd$. 他想到了一个非常简单而有意思的式子:
$$\prod_{i=1}^N\prod_{j=1}^N\frac{lcm(i,j)}{gcd(i,j)}\ (\bmod\ 104857601)$$
${\rm CYJian}$ 已经算出来这个式子的值了. 现在请你帮他验算一下吧. ${\rm CYJian}$ 只给你 $0.2s$ 的时间哦

### 输入输出格式

#### 输入格式

一行一个正整数 $N$

#### 输出格式

一行一个正整数，表示答案模 $104857601$ 的值

### 输入输出样例

#### 输入样例 #1

```input1
5
```

#### 输出样例 #1

```output1
585494
```

### 说明

样例解释:

| $\frac{lcm}{gcd}$ |  1  |  2  |  3  |  4  |  5  |
| :---------------: | :-: | :-: | :-: | :-: | :-: |
|       **1**       |  1  |  2  |  3  |  4  |  5  |
|       **2**       |  2  |  1  |  6  |  2  | 10  |
|       **3**       |  3  |  6  |  1  | 12  | 15  |
|       **4**       |  4  |  2  | 12  |  1  | 20  |
|       **5**       |  5  | 10  | 15  | 20  |  1  |

对于 $30\%$ 的数据: $1 \leq N \leq 5000$

对于 $100\%$ 的数据: $1 \leq N \leq 1000000$

## 解题思路

推式子

$$
\begin{aligned}
  \prod_{i=1}^n\prod_{j=1}^n \frac{ij}{(i,j)^2} & =\frac{(n!)^{2n}}{\prod_{i=1}^n\prod_{j=1}^n(i,j)^2} \\
  & =\frac{(n!)^{2n}}{\prod_{d=1}^nd^{2\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}[(i,j)=1]}} \\
  & =\frac{(n!)^{2n}}{\prod_{d=1}^nd^{2\sum_{e=1}^{\lfloor\frac{n}{d}\rfloor}\mu(e)\lfloor\frac{n}{de}\rfloor^2}} \\
\end{aligned}
$$

两层整除分块即可

## 时间复杂度

$O(n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P5221 Luogu/P5221/0.cpp %}

</details>
