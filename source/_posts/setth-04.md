---
title: "集合论04 - R^n 上的点集"
categories:
  - 笔记
  - 数学
  - 集合论
tags:
  - 数学
  - 笔记
  - 集合论
  - 点集
  - 直径
  - 有界集
  - 矩体
  - 方体
  - 开矩体
  - 闭矩体
  - 开球
  - 邻域
  - 闭球
  - 球面
  - 聚点/极限点
  - 导集
  - 孤立点
  - Bolzano-Weierstrass定理
  - 闭集
  - 开集
  - Borel集
  - Cantor集
date: 2021-03-27 17:38:32
---

本篇主要介绍 $\mathbb{R}^n$ 上点集的相关概念, 并会介绍 $\mathbb{R}^n$ 上的一些特殊点集

<!-- more -->

欧氏空间的相关定义略, 详情请参照高等代数相关章节

## 一些概念

本章将给出一大堆定理 (建议当字典用)

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** 设 $E\subseteq\mathbb{R}^n$, 称

$$
\operatorname{diam}(E):=\sup\{|x-y|:x,y\in E\}
$$

为 $E$ 的**直径**

若 $\operatorname{diam}(E)<+\infty$, 则称 $E$ 为**有界集**

{% endnote %}

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 设

- $x_0\in\mathbb{R}^n$
- $\delta\in\mathbb{R}^+$

则

- 称点集

  $$
  \{x\in\mathbb{R}^n:|x-x_0|<\delta\}
  $$

  为以 $x_0$ 为中心, $\delta$ 为半径的**开球** (或 $x_0$ 的**邻域**), 记为 $B(x_0,\delta)$

- 称点集

  $$
  \{x\in\mathbb{R}^n:|x-x_0|\leqslant\delta\}
  $$

  为以 $x_0$ 为中心, $\delta$ 为半径的**闭球**, 记为 $C(x_0,\delta)$

- 称点集

  $$
  \{x\in\mathbb{R}^n:|x-x_0|=\delta\}
  $$

  为以 $x_0$ 为中心, $\delta$ 为半径的**球面**

{% endnote %}

{% note info no-icon %}

**<a id="def-1-3">定义 - 1-3</a>** 设

- $a_i,b_i\in\mathbb{R},~i=1,2,...,n$
- $a_i<b_i,~i=1,2,...,n$

则

- 称点集
  $$
  \prod_{i=1}^n(a_i,b_i)
  $$
  为 $\mathbb{R}^n$ 上的**开矩体**
- 称点集
  $$
  \prod_{i=1}^n[a_i,b_i]
  $$
  为 $\mathbb{R}^n$ 上的**闭矩体**

另外, 称 $b_i-a_i$ 为矩体的**边长**, 若矩体各边长相等, 则称该矩体为**方体**

矩体常用 $I$, $J$ 等表示, 其**体积**用 $|I|$, $|J|$ 等表示

显然, 对于矩体 $I=\prod_{i=1}^n(a_i,b_i)$, 有

- $$
  \operatorname{diam}(I)=\left(\sum_{i=1}^n(b_i-a_i)^2\right)^\frac{1}{2}
  $$
- $$
  |I|=\prod_{i=1}^n(b_i-a_i)
  $$

{% endnote %}

{% note info no-icon %}

**<a id="def-1-4">定义 - 1-4</a>** 设 $x_k\in\mathbb{R}^n,~k=1,2,...$, 若

$$
\exists x\in\mathbb{R}^n,~s.t.~\lim_{k\to\infty}|x_k-x|=0
$$

则称点列 $\{x_k\}$ 为 $\mathbb{R}^n$ 中的**收敛点列**, 称 $x$ 为其**极限**, 简记为

$$
\lim_{k\to\infty}x_k=x
$$

{% endnote %}

不难证明 $\mathbb{R}^n$ 上的 Cauchy 收敛定理, 故此处省略

{% note info no-icon %}

**<a id="def-1-5">定义 - 1-5</a>** 设 $E\subseteq\mathbb{R}^n$

- 若

  $$
  \exists x\in\mathbb{R}^n,\exists \{x_k\}\subseteq E,~s.t.~\lim_{k\to\infty}x_k=x
  $$

  则称 $x$ 为 $E$ 的**聚点** (或**极限点**)

  $E$ 上的全体聚点称为 $E$ 的**导集**, 记为 $E'$

- 若

  $$
  \exists x\in E,\forall \{x_k\}\subseteq E,~s.t.~\lim_{k\to\infty}x_k\ne x
  $$

  则称 $x$ 为 $E$ 的**孤立点**, 显然 $x\in E\setminus E'$

{% endnote %}

{% note primary no-icon %}

**<a id="eg-1-1">例 - 1-1</a>** 设 $E=\{\sqrt{m}-\sqrt{n}:m,n\in\mathbb{N}\}$, 则 $E'=\mathbb{R}$

注意到 $\forall x\in\mathbb{R}$, 令

$$
x_n=\sqrt{\lfloor (x+n)^2\rfloor}-\sqrt{n^2}
$$

则

$$
\sqrt{(x+n)^2-1}-n<x_n<x
$$

显然

$$
\lim_{n\to\infty}x_n=x
$$

{% endnote %}

{% note success no-icon %}

**<a id="th-1-1">定理 - 1-1</a>** 设 $E\subseteq\mathbb{R}^n$, 则

$$
x\in E'\iff\forall\delta>0,~(B(x,\delta)\setminus\{x\})\cap E\ne\varnothing
$$

证明略

{% endnote %}

{% note success no-icon %}

**<a id="th-1-2">定理 - 1-2</a>** 设 $E_1,E_2\subseteq\mathbb{R}^n$, 则

$$
(E_1\cup E_2)'=E_1'\cup E_2'
$$

证明略

{% endnote %}

{% note success no-icon %}

**<a id="th-1-3">定理 - 1-3</a>** (Bolzano-Weierstrass 定理)

$\mathbb{R}^n$ 中任一有界无限点集均至少有一个聚点

<details open>
<summary><font color='orange'>Proof</font></summary>

对 $\mathbb{R}$ 上的 Bolzano-Weierstrass 定理用数学归纳法即可

</details>

{% endnote %}

### 习题

{% note primary no-icon %}

#### <a id="asm-1-1">题 - 1-1</a>

证明: 设 $\{a_n\}$ 为 $\mathbb{R}$ 中的有界点列, 且

$$
|a_{n+1}-a_n|\geqslant 1,~n=1,2,...
$$

则 $\{a_n\}$ 可能有无穷多个聚点

<details open>
<summary><font color='orange'>Proof</font></summary>

令

$$
a_n=\begin{cases}
  \frac{1}{p}+\frac{1}{q},&2\nmid n\\
  \frac{1}{p}+\frac{1}{q}+4,&2\mid n\\
\end{cases},~p,q=1,2,...;n=1,2,...
$$

其中 $(p,q)$ 随 $\lfloor\frac{n+1}{2}\rfloor$ 递增按

$$
(1,1)\to(1,2)\to(2,1)\to(3,1)\to(2,2)\to(1,3)\to(1,4)\to...
$$

顺序赋值

则

- $$
  \{a_n\}'=\left\{ \frac{1}{n}\right\}
  $$
- $$
  |a_{n+1}-a_n|\geqslant 1,~n=1,2,...
  $$

</details>

{% endnote %}

## 一些基本点集

### 闭集

### 开集

### Borel 集

### Cantor 集
