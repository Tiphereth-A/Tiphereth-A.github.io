---
title: "题解 - [LightOJ 1282] Leading and Trailing"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - LightOJ
  - 数学
  - 快速幂
date: 2020-07-25 00:24:27
---

[题目链接](https://vjudge.net/problem/LightOJ-1282/origin)

<!-- more -->

## 简述题意

给定 $n$ 和 $k$, 输出 $n^k$ 的前三位和后三位

## 解题思路

后三位直接用快速幂即可

前三位考虑取对数, 截取小数部分, 我们便可以通过这个还原出前三位了

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:LightOJ_1282 LightOJ/1282/0.cpp %}

</details>
