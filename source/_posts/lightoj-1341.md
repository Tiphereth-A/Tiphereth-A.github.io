---
title: "题解 - [LightOJ 1341] Aladdin and the Flying Carpet"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - LightOJ
  - 数学
  - 素数/质数
  - 数论
  - 筛法
date: 2020-07-25 00:29:43
---

[题目链接](https://vjudge.net/problem/LightOJ-1341/origin)

<!-- more -->

## 简述题意

给定$a$和$b$, 输出所有满足下列条件的数对$(c,d)$的个数

1. $cd=a$
1. $b\leqslant c\leqslant d$

## 解题思路

直接暴力求解会超时, 我们可以先预处理素数表, 这样就可以了

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:LightOJ_1341 LightOJ/1341/0.cpp %}

</details>
