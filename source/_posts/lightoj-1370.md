---
title: "题解 - [LightOJ 1370] Bi-shoe and Phi-shoe"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - LightOJ
  - 数学
  - 数论
  - 素数/质数
  - 筛法
  - Euler函数
date: 2020-07-25 00:39:08
---

[题目链接](https://vjudge.net/problem/LightOJ-1341/origin)

<!-- more -->

## 简述题意

给出一组数$a_i$, 对于每个数均可找到满足这样条件的数$f_i$: $\varphi(f_i)\geqslant a_i$, 求

$$\sum_{i=1}^n(f_i)_{min}$$

## 解题思路

根据 Euler 函数的性质, 我们可以很容易地推知: 对于$a_i$, 只要找不小于$a_i+1$的最小素数即可

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:LightOJ_1370 LightOJ/1370/0.cpp %}

</details>
