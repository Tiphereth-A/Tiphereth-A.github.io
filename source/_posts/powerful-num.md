---
title: 笔记 - Powerful number 与 Powerful number 筛
categories:
  - 算法竞赛
  - 笔记
tags:
  - 算法竞赛
  - 数学
  - 算法
  - 模板
  - 数论
  - 数论函数
  - 积性函数
  - Dirichlet卷积
  - Powerful number
  - Powerful number筛
date: 2021-04-26 12:58:33
---

Powerful number 筛是一种能在最佳 $O(\sqrt n)$ 的时间下求一类积性函数前缀和的不稳定方法

<!-- more -->

## Powerful number

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** Powerful number

令 $n\in\Z$ 的唯一分解式为 $n=\prod_{i=1}^{\omega(n)}p_i^{\alpha_i}$, 若 $\forall i\in[1,\omega(n)]_{\N},~\alpha_i>1$, 则称 $n$ 为 **Powerful number**

{% endnote %}

Powerful number 有如下性质

{% note success no-icon %}

**<a id="th-1-1">定理 - 1-1</a>** $n$ 为 Powerful number $\iff~\exist a,b\in\Z, n=a^2b^3$

{% note %}

<details open="open">
<summary><font color='orange'>Proof</font></summary>

令 $P_n:=\{(p_i,\alpha_i):p_i\in\text{Prime}^+,~p_i^{\alpha_i}\mid n,~p_i^{\alpha_i+1}\nmid n\}$

- $\implies$:

  令

  - $P_1'=\{(p_i,\alpha_i)\in P_n:2\mid\alpha_i\}$
  - $P_2'=\{(p_i,\alpha_i)\in P_n:2\nmid\alpha_i\}$

  则
  $$P_n=P_1'\cup P_2',~P_1'\cap P_2'=\varnothing$$

  令

  - $$a=\prod_{(p,\alpha)\in P_1'}p^\frac{\alpha}{2}\prod_{(p,\alpha)\in P_2'}p^\frac{\alpha-3}{2}$$
  - $$b=\prod_{(p,\alpha)\in P_2'}p$$

  则
  $$n=\prod_{i=1}^{\omega(n)}p_i^{\alpha_i}=a^2b^3$$

- $\impliedby$:

  $$n=a^2b^3=\prod_{(p,\alpha)\in P_a}p^{2\alpha}\cdot\prod_{(p,\alpha)\in P_b}p^{3\alpha}=\prod_{(p,\alpha)\in P_n}p^\alpha$$

  不难发现 $\forall(p,\alpha)\in P_n,\alpha>1$

</details>

{% endnote %}
{% endnote %}

{% note success no-icon %}

**<a id="th-1-2">定理 - 1-2</a>**
$$|\{m\in\Z_n:m~\text{is}~\text{powerful}~\text{number}\}|=O(\sqrt{n})$$

{% note %}

<details open="open">
<summary><font color='orange'>Proof</font></summary>

$$|\{m\in\Z_n:m~\text{is}~\text{powerful}~\text{number}\}|=O\left(\int_1^{\sqrt{n}}\sqrt[3]\frac{n}{x^2}\mathrm{d}x\right)=O(\sqrt{n})$$

</details>

{% endnote %}
{% endnote %}

## Powerful number 筛

对积性函数 $f$, 我们要找到积性函数 $g$ 满足 $g(p)=f(p)$

令积性函数 $h=f*g^{-1}$

显然, $f(p)=h(p)g(1)+h(1)g(p)=h(p)+f(p)$, 故 $h(n)\ne 0\implies n$ 为 Powerful number

我们有

$$\sum_{i=1}^nf(i)=\sum_{i=1}^n(h*g)(i)=\sum_{i=1}^nh(i)\sum_{j=1}^{\lfloor\frac{n}{i}\rfloor}g(j)$$

所以只需枚举 $O(\sqrt{n})$ 个 Powerful number, 暴力求出对应的 $h$ 值, 并求 $g$ 的前缀和即可求出 $f$ 的前缀和

## 模板

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp powerful-num/main.cpp %}

</details>

## 例题

1. [LOJ 6053 简单的函数](https://loj.ac/p/6053) -> {% post_link loj-6053 题解 %}

## 参考资料

- <https://www.cnblogs.com/clockwhite/p/14453866.html>
