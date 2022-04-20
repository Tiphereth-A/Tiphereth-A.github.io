---
title: '题解 - [AtCoder ARC051B] 互除法'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - AtCoder
  - 数学
  - 最大公约数
  - Fibonacci数列
date: 2018-07-22 19:12:06
---

[题目链接](https://atcoder.jp/contests/arc051/tasks/arc051_b)

<!-- more -->

## 题意简述

给出$n$, 输出一组数$a,b$, 使得`gcd(a, b)`的递归次数为$n$

其中`gcd(a, b)`定义如下, `counter`即为递归次数

```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}
```

## 解题思路

考虑欧几里得算法的最坏情况, 即a,b为两个相邻的斐波那契数

令$T(a,b)$为对$a,b$求$gcd$递归层数

Fibonacci数列 $F_n:=\begin{cases}
  1,& n\leqslant 1\\
  F_{n-1}+F_{n-2},& n>1
\end{cases}$

则有

$$T(F_{n-1},F_n)=n$$

用数学归纳法可以证明

所以只需要输出$F_{n-1}$和$F_n$即可
