---
title: "题解 - [Luogu P2413] yyy loves physics IV"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - 物理
  - 电路
  - 表达式求值
date: 2018-04-06 21:02:28
---

[题目链接](https://www.luogu.com.cn/problem/P2413)

<!-- more -->

## 题意简述

给出一个电路和电路上所有元件的断路概率, 计算该电路断路的概率

## 解题思路

设 $P(A_{i}),i=1,2,...,n$ 分别为元件 1, 元件 2, ..., 元件 n 断路的概率

在纸上简单画一画就会发现：

$n$ 个串联元件/电路断路的概率为:

$$
P\left(\bigcup_{i=1}^{n} A_{i}\right)=1-\prod_{i=1}^n(1-P(A_i))
$$

$n$ 个并联元件/电路断路的概率为:

$$
P\left(\bigcap_{i=1}^{n} A_{i}\right)=\prod_{i=1}^nP(A_i)
$$

于是这个问题就转换成只含有`+ * ( )`及数字的表达式求值问题了
