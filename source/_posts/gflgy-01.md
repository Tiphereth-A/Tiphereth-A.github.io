---
title: 生成函数01 - 简介
categories:
  - 笔记
  - 数学
  - 生成函数
tags:
  - 数学
  - 笔记
  - 组合数学
  - 生成函数
  - 核函数
  - 普通生成函数
  - 指数生成函数
  - Dirichlet生成函数
date: 2021-04-28 13:15:33
---

生成函数是一种描述数列的方法, 因其具有的诸多良好性质而被广泛应用

<!-- more -->

## 简介

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** 生成函数

令

- $\mathbb{P}$ 为一数域
- $\{a_n\}_{n=0}^{\infty}$ 为 $\mathbb{P}$ 上一数列
- $\{k_n\}_{n=0}^{\infty}$ 为一函数列, 值域为 $\mathbb{P}$ 的子集, 且在 $\mathbb{P}$ 上线性无关, 称作**核函数列**

称 $F(x)=\sum_{i=0}^{\infty}a_ik_i(x)$ 为数列 $\{a_n\}$ 在核函数列 $\{k_n\}$ 下的**生成函数**

{% endnote %}

核函数列的选取不同, 得到的生成函数也不同, 具有的性质也不同

下面定义一些常见的生成函数

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 普通生成函数, 指数生成函数, Dirichlet 生成函数

- 普通生成函数 (OGF): $k_n(x)=x^n$
- 指数生成函数 (EGF): $\displaystyle k_n(x)=\frac{x^n}{n!}$
- Dirichlet 生成函数 (DGF): $\displaystyle k_n(x)=\frac{1}{n^x}$

{% endnote %}

为了方便起见, 我们定义 $F_i(x)$ 为生成函数 $F$ 的第 $i$ 项