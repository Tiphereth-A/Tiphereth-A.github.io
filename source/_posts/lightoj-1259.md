---
title: "题解 - [LightOJ 1259] Goldbach`s Conjecture"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - LightOJ
  - 数学
  - 数论
  - 素数/质数
  - 筛法
date: 2020-07-25 00:19:21
---

[题目链接](https://vjudge.net/problem/LightOJ-1259/origin)

<!-- more -->

## 简述题意

给定 $n$, 统计满足如下条件的数对 $(a,b)$ 个数

1. $a,b$ 均为素数
1. $a+b=n$
1. $a\leqslant b$

## 代码

{% icodeweb cpa_cpp title:LightOJ_1259 LightOJ/1259/0.cpp %}
