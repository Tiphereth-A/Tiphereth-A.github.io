---
title: "模板 & 题解 - [Luogu P4000] 斐波那契数列"
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 模板
  - 数学
  - 数论
  - Fibonacci数列
  - Lucas数列
  - Fibonacci数列循环节
  - 二次剩余
  - 最大公约数
  - 最小公倍数
  - 高精度
  - 矩阵快速幂
date: 2021-12-22 20:54:01
---

[题目链接](https://www.luogu.com.cn/problem/P4000)

<!-- more -->

## 原始题面

### 题目描述

大家都知道, 斐波那契数列是满足如下性质的一个数列:

- $f_1 = 1$
- $f_2 = 1$
- $f_n = f_{n-1} + f_{n-2}$ ($n \geq 2$ 且 $n$ 为整数)
  请你求出 $f_n \mod p$ 的值

### 输入格式

- 第 1 行: 一个整数 $n$
- 第 2 行: 一个整数 $p$

### 输出格式

- 第 1 行: $f_n \mod p$ 的值

### 输入输出样例

#### 输入 #1

```input1
5
1000000007
```

#### 输出 #1

```output1
5
```

#### 输入 #2

```input2
10
1000000007
```

#### 输出 #2

```output2
55
```

### 说明/提示

对于 $100\%$ 的数据, $n \leq 10^{30000000}, p<2^{31}$

## 解题思路

科技题

先摆个论文: [The Period of the Fibonacci Sequence Modulo j](https://gradprogram.math.arizona.edu/~ura-reports/071/Campbell.Charles/Final.pdf)

这篇论文给出了找 Fibonacci 数列和 Lucas 数列循环节的方法 (实际上所有二阶递推数列都可以这样做)

简单来说就是这样:

- 考虑 $p$ 的唯一分解

  $$p=\prod_{i=1}^{\omega(p)}p_i^{\alpha_i}$$

  令 $l(p)$ 为 $F_n$ 模 $p$ 的循环节, 则

  $$l(p)=\operatorname{lcm}\{l(p_1^{\alpha_1}),l(p_2^{\alpha_2}),...,l(p_{\omega(p)}^{\alpha_{\omega(p)}})\}$$

- 对素数 $p$, 有如下定理:
  - $$l(p^n)\mid l(p)p^{n-1}$$
  - 若 $\left(\frac{5}{p}\right)=1$, 即 $p\equiv\pm 1\pmod{5}$, 则
    $$l(p)\mid p-1$$
  - 若 $\left(\frac{5}{p}\right)=-1$, 即 $p\equiv\pm 2\pmod{5}$, 则
    $$l(p)\mid 2(p+1)$$

> 代码里还有一些别的科技, 推荐看一看

## 复杂度

$O(\max\{\lg n,\sqrt p\})$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P4000 Luogu/P4000/0.cpp %}

</details>
