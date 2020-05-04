---
title: 随笔 - 一些数学公式
categories:
  - 随笔
  - 数学
tags:
  - 随笔
  - 数学
  - Möbius反演
  - Fibonacci数列
date: 2021-05-07 14:05:47
---

记录一些杂七杂八的数学公式

<!-- more -->

## 关于取整函数

- $$
  \lfloor x\rfloor=\begin{cases}
    \displaystyle x+\frac{\arctan\cot\pi x}{\pi}-\frac{1}{2},&x\notin\Z\\
    x,&x\in\Z
  \end{cases}
  $$

## 莫反相关结论

- $$\sum_{i=1}^n\sum_{j=1}^m(i,j)^k=\sum_{D=1}^{\min\{n,m\}}\left\lfloor\frac{n}{D}\right\rfloor\left\lfloor\frac{m}{D}\right\rfloor\{\operatorname{id}_k*\mu\}(D)$$
- $$\{\operatorname{id}_k*\mu\}(p^s)=p^{ks}-p^{k(s-1)}$$

## 关于 Fibonacci 数列

- $$(f_n,f_m)=f_{(n,m)}$$

## 杂项

- $$e(e+\pi)^e(2e + \pi)^e+\frac{e}{(\pi^e-e)(e+e^\pi-\pi^e)}\approx 114514.1919810$$
