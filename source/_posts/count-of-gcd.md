---
title: 笔记 - 关于 gcd 求和与计数的问题
categories:
  - 笔记
  - 数学
tags:
  - 程序设计
  - 笔记
  - 数学
  - 数论
  - 最大公约数
  - Möbius反演
date: 2021-06-08 13:18:28
---

总结一些 Möbius 反演中一些关于 gcd 求和与计数问题的解法

<!-- more -->

## 直接求和

即形如
$$\sum_{\nu\in\prod_{i=1}^m[1,n_i]_\N}f(\nu)g(\gcd\nu)$$
的和式, 其中

- $\nu=(\def\enum#1{v_{ #1}}\enum{1},\enum{2},...,\enum{m})\in\prod_{i=1}^m[1,n_i]_\N$
- $\gcd\nu:=\gcd_{i=1}^m v_i$

令 $n_0=\min_{i=1}^mn_i$, $g_n=\gcd_{i=1}^mn_i$, 则我们可以按如下方法处理

$$
\begin{aligned}
  \sum_{\nu\in\prod_{i=1}^m[1,n_i]_\N}f(\nu)g(\gcd\nu)&=\sum_{d=1}^{n_0}g(d)\sum_{\nu\in\prod_{i=1}^m[1,n_i]_\N}f[\nu](\gcd\nu=d)&(1)\\
  &=\sum_{d=1}^{n_0}g(d)\sum_{\nu\in\prod_{i=1}^m[1,\lfloor\frac{n_i}{d}\rfloor]_\N}f[d\nu](\gcd\nu=1)&(2)\\
  &=\sum_{d=1}^{n_0}g(d)\sum_{\nu\in\prod_{i=1}^m[1,\lfloor\frac{n_i}{d}\rfloor]_\N}f(d\nu)\sum_{e\mid\gcd\nu}\mu(e)&(3)\\
  &=\sum_{d=1}^{n_0}g(d)\sum_{e=1}^{ \frac{g_n}{d}}\mu(e)\sum_{\nu\in\prod_{i=1}^m[1,\lfloor\frac{n_i}{de}\rfloor]_\N}f(de\nu)&(4)\\
  &\xlongequal[D=de]{F(x)=\sum_{\nu\in\prod_{i=1}^m[1,\lfloor\frac{n_i}{x}\rfloor]_\N}f(x\nu)}\sum_{D=1}^{n_0}F(D)(g*\mu)(D)&(5)\\
\end{aligned}
$$

其中

- $(1)$: 枚举因子 $d$
- $(2)$: 将 $[\gcd\nu=d]$ 化为 $[\gcd\nu=1]$, 以便于使用等式
  $$\mu*\{1\}=\epsilon$$
- $(3)$: 使用上述等式
- $(4)$: 交换求和号顺序
- $(5)$: 变量代换

由 $F(x)$ 的定义, 我们发现该和式可以使用数论分块来加速

实际题目中,

- $(g*\mu)(D)$ 往往是积性函数, 如果不是, 由于 $\mu$ 的存在, 其值也往往能在线性筛时候筛出
- $f(\nu)$ 往往都具有很好的性质, 比如是齐次的, 甚至可以很容易写出前缀和的表达式

### 例题

- 洛谷 [P6222 「P6156 简单题」加强版](https://www.luogu.com.cn/problem/P6222) -> {% post_link luogu-p6156 题解(P6156) %}
- 洛谷 [P5221 Product](https://www.luogu.com.cn/problem/P5221) -> {% post_link luogu-p5221 题解 %}
- 洛谷 [P3704 [SDOI2017]数字表格](https://www.luogu.com.cn/problem/P3704) -> {% post_link luogu-p3704 题解 %}
- 洛谷 [P5518 [MtOI2019]幽灵乐团 / 莫比乌斯反演基础练习题](https://www.luogu.com.cn/problem/P5518)

## 统计 gcd 在某集合内的向量数

即形如
$$\sum_{\nu\in\prod_{i=1}^m[1,n_i]_\N}[\gcd\nu\in K=\{\def\enum#1{k_{ #1}}\enum{1},\enum{2},...,\enum{s}\}]$$
的和式, 其中

- $\nu=(\def\enum#1{v_{ #1}}\enum{1},\enum{2},...,\enum{m})\in\prod_{i=1}^m[1,n_i]_\N$
- $\gcd v:=\gcd_{i=1}^m v_i$

令 $n_0=\min_{i=1}^mn_i$, $g_n=\gcd_{i=1}^mn_i$, 则我们可以按如下方法处理

$$
\begin{aligned}
  \sum_{\nu\in\prod_{i=1}^m[1,n_i]_\N}[\gcd\nu\in K]&=\sum_{k\in K}\sum_{\nu\in\prod_{i=1}^m[1,n_i]_\N}[\gcd\nu=k]\\
  &=\sum_{D=1}^{n_0}\left(\prod_{i=1}^m\left\lfloor\frac{n_i}{D}\right\rfloor\right)\sum_{k\mid D;~k\in K}\mu\left(\frac{D}{k}\right)
\end{aligned}
$$

> 具体推导看上一节即可, 可看作 $f(x)=1$, $g(x)=\epsilon(x)$ 的特例

### 例题

- 洛谷 [P2522 [HAOI2011]Problem b](https://www.luogu.com.cn/problem/P2522)
- 洛谷 [P2257 YY 的 GCD](https://www.luogu.com.cn/problem/P2257)
