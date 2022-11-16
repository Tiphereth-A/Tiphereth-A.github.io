---
title: 集合论01 - 基本概念
categories:
  - 笔记
  - 数学
  - 集合论
tags:
  - 数学
  - 笔记
  - 集合论
  - 集合族
  - 集合列
  - 指标集
  - 关系
  - 二元关系
  - 多元关系
  - 对称差
  - 极限
  - 上极限
  - 下极限
  - 直积
date: 2021-03-27 17:34:32
---

本篇主要介绍集合论中的基础概念

<!-- more -->

集合是数学中无法被准确定义的概念之一

## 基本定义

### 集合族, 指标集

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** 令 $I$ 为一集合, 称
$$\{A_{\alpha}:\alpha\in I\}$$
为 **集合族**, 记作 $\{A_{\alpha}\}_{\alpha\in I}$

其中 $I$ 称为 **指标集**

当 $I=\mathbb{N}^+$ 时, 集合族也称作 **集合列**, 可简记为 $\{A_k\}$

{% endnote %}

### 二元关系

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 令 $A$ 为一集合, 称 $A\times A$ 的子集为 $A$ 上的一 **二元关系**

{% endnote %}

显然, $A$ 上的所有二元关系也构成集合, 我们令其为 $\mathscr{B}(A):=\mathscr{P}(A\times A)$

类似的, 我们可以定义多元关系, 此处略去不表

我们对二元关系定义几种性质

{% note info no-icon %}

**<a id="def-1-3">定义 - 1-3</a>** 设 $A$ 为一集合, $\sigma\in\mathscr{B}(A)$

1. 自反性: $(\forall a\in A),a~\sigma~a$
1. 反自反性: $(\forall a\in A),a~\overline{\sigma}~a$
1. 对称性: $(\forall a,b\in A),a~\sigma~b\iff b~\sigma~a$
1. 反对称性: $(\forall a,b\in A),a~\sigma~b~\&~b~\sigma~a\implies a=b$
1. 传递性: $(\forall a,b,c\in A),a~\sigma~b~\&~b~\sigma~c\implies a~\sigma~c$

{% endnote %}

### 对称差

{% note info no-icon %}

**<a id="def-1-4">定义 - 1-4</a>** 令 $A,B$ 为两集合, 称
$$(A\setminus B)\cup(B\setminus A)$$
为 $A$ 与 $B$ 的 **对称差集**, 记作 $A\triangle B$

{% endnote %}

显然, 对称差有如下性质:

1. $A\triangle\varnothing=A$, $A\triangle A=\varnothing$
1. $A\triangle A^c=X$, $A\triangle X=A^c$, 其中 $X$ 为全集
1. $A\triangle B=B\triangle A$
1. $(A\triangle B)\triangle C=A\triangle(B\triangle C)$
1. $A\cap(B\triangle C)=(A\cap B)\triangle (A\cap C)$
1. $A^c\triangle B^c=A\triangle B$
1. $A\triangle B=A\iff B=\varnothing$
1. $(\forall A,B),\exists_1 E~s.t.~E\triangle A=B$ ($E=A\triangle B$)

### 集合列的极限

众所周知, 极限是研究无限性质的重要工具, 我们首先对单调的集合列给出极限的定义

{% note info no-icon %}

**<a id="def-1-5">定义 - 1-5</a>**

- 设集合列 $\{A_k\}$ 满足
  $$A_k\subseteq A_{k+1},~\forall k\in\mathbb{N}^+$$
  则称其为 **递增集合列**, 定义 $\displaystyle\bigcup_{k=1}^{\infty}A_k$ 为该集合列的 **极限集**
- 设集合列 $\{A_k\}$ 满足
  $$A_k\supseteq A_{k+1},~\forall k\in\mathbb{N}^+$$
  则称其为 **递减集合列**, 定义 $\displaystyle\bigcap_{k=1}^{\infty}A_k$ 为该集合列的 **极限集**

{% endnote %}

{% note primary no-icon %}

**<a id="eg-1-1">例 - 1-1</a>** 设在 $\mathbb{R}$ 上有一函数列满足

- $$f_i(x)\leqslant f_{i+1}(x),~i\in\mathbb{N}^+$$
- $$\lim_{n\to\infty}f_n(x)=f(x)$$

对给定实数 $t$, 作集合列
$$E_n=\{x:f_n(x)>t\},~n\in\mathbb{N}^+$$

显然集合列 $\{E_n\}$ 递增, 且
$$\lim_{n\to\infty}E_n=\{x:f(x)>t\}$$

{% endnote %}

对一般的集合列, 我们可以参照 <a href="#def-1-5">定义 - 1-5</a> 给出上下极限的定义

{% note info no-icon %}

**<a id="def-1-6">定义 - 1-6</a>** 设 $\{A_k\}$ 为一集合列, 称

- $$\bigcap_{i=1}^{\infty}\bigcup_{k=i}^{\infty}A_k$$

  为 $\{A_k\}$ 的 **上极限集**, 记作 $\displaystyle\limsup_{k\to\infty}A_k$

- $$\bigcup_{i=1}^{\infty}\bigcap_{k=i}^{\infty}A_k$$

  为 $\{A_k\}$ 的 **下极限集**, 记作 $\displaystyle\liminf_{k\to\infty}A_k$

{% endnote %}

{% note primary no-icon %}

**<a id="eg-1-2">例 - 1-2</a>** 设 $E,F$ 为两集合,

$$
A_n=\begin{cases}
  E,&2\mid n\\
  F,&2\nmid n
\end{cases},~n\in\mathbb{N}^+
$$

则
$\displaystyle\limsup_{n\to\infty}A_n=E\cup F,~\liminf_{n\to\infty}A_n=E\cap F$

{% endnote %}

下列命题显然成立

{% note primary no-icon %}

**<a id="pb-1-1">命题 - 1-1</a>** 设 $E$ 为一集合, $\{A_k\}$ 为一集合列, 则

1. $$E\setminus\limsup_{n\to\infty}A_n=\liminf_{n\to\infty}(E\setminus A_n)$$
1. $$E\setminus\liminf_{n\to\infty}A_n=\limsup_{n\to\infty}(E\setminus A_n)$$

{% endnote %}

{% note success no-icon %}

**<a id="th-1-1">定理 - 1-1</a>** 若 $\{A_k\}$ 为一集合列, 则

1. $$\limsup_{n\to\infty}A_n=\{x:(\forall j\in\mathbb{N}^+,\exists k\geqslant j),~x\in A_k\}$$
1. $$\liminf_{n\to\infty}A_n=\{x:(\exists j\in\mathbb{N}^+,\forall k\geqslant j),~x\in A_k\}$$

即

- $\{A_k\}$ 的上限集是由属于 $\{A_k\}$ 中无限多集合的元素构成
- $\{A_k\}$ 的下限集是由不属于 $\{A_k\}$ 中有限多集合的元素构成

<details open>
<summary><font color='orange'>Proof</font></summary>

$$
\begin{aligned}
  x\in\limsup_{n\to\infty}A_n&\iff\forall j\in\mathbb{N}^+,~s.t.~x\in\bigcup_{k=j}^{\infty}A_k\\
  &\iff\forall j\in\mathbb{N}^+,\exists k\geqslant j,~x\in A_k
\end{aligned}
$$

$$
\begin{aligned}
  x\in\liminf_{n\to\infty}A_n&\iff\exists j\in\mathbb{N}^+,~s.t.~x\in\bigcap_{k=j}^{\infty}A_k\\
  &\iff\exists j\in\mathbb{N}^+,\forall k\geqslant j,~x\in A_k
\end{aligned}
$$

</details>

{% endnote %}

{% note success no-icon %}

**<a id="ifr-1-1">推论 - 1-1</a>** 若 $\{A_k\}$ 为一集合列, 则
$$\limsup_{n\to\infty}A_n\supseteq\liminf_{n\to\infty}A_n$$

{% endnote %}

### 直积

{% note info no-icon %}

**<a id="def-1-7">定义 - 1-7</a>** 令 $X,Y$ 为两集合, 称 $\{(x,y):x\in X,y\in Y\}$ 为 $X,Y$ 的**直积集**, 记作 $X\times Y$

$X\times X$ 也可记作 $X^2$

{% endnote %}

## 例题

{% note primary no-icon %}

### <a id="asm-1-1">题 - 1-1</a>

设 $\{f_n(x)\}$ 以及 $f(x)$ 为 $\mathbb{R}$ 上的函数

证明: 使 $f_n(x)$ 不收敛到 $f(x)$ 的一切点 $x$ 组成的集合为
$$D=\bigcup_{k=1}^{\infty}\bigcap_{N=1}^{\infty}\bigcup_{n=N}^{\infty}\left\{x:|f_n(x)-f(x)|\geqslant\frac{1}{k}\right\}$$

<details open>
<summary><font color='orange'>Proof</font></summary>

若 $f_n(x_0)$ 不收敛到 $f(x_0)$, 则
$$\exists k\in\mathbb{N}^+,\forall N\in\mathbb{N}^+,\exists n\geqslant N,~s.t.~|f_n(x_0)-f(x_0)|\geqslant\frac{1}{k}$$

令 $E_{n,k}=\left\{x:|f_n(x)-f(x)|\geqslant\frac{1}{k}\right\}$, 则
$$\exists k\in\mathbb{N}^+,x_0\in\limsup_{n\to\infty}E_{n,k}$$
反之, $\forall k\in\mathbb{N}^+,x\in\limsup_{n\to\infty}E_{n,k}$ 显然不是收敛点

从而
$$x_0\in\bigcup_{k=1}^{\infty}\limsup_{n\to\infty}E_{n,k}=\bigcup_{k=1}^{\infty}\bigcap_{N=1}^{\infty}\bigcup_{n=N}^{\infty}\left\{x:|f_n(x)-f(x)|\geqslant\frac{1}{k}\right\}=D$$

</details>

{% endnote %}

{% note primary no-icon %}

### <a id="asm-1-2">题 - 1-2</a>

设 $\{f_n(x)\}$ 以及 $f(x)$ 为 $\mathbb{R}$ 上的函数, 且 $\lim_{n\to\infty}f_n(x)=f(x)$

证明:
$$\forall t\in\mathbb{R},\{x:f(x)\leqslant t\}=\bigcap_{k=1}^{\infty}\bigcup_{N=1}^{\infty}\bigcap_{n=N}^{\infty}\left\{x:f_n(x)<t+\frac{1}{k}\right\}$$

<details open>
<summary><font color='orange'>Proof</font></summary>

令 $E_{n,k}=\left\{x:f_n(x)<t+\frac{1}{k}\right\}$, 则

$$
\begin{aligned}
  x_0\in\{x:f(x)\leqslant t\}\iff&\lim_{n\to\infty}f_n(x_0)=f(x_0)\leqslant t\\
  \iff&\forall k\in\mathbb{N}^+,\exists N\in\mathbb{N}^+,\forall n\geqslant N,~f_n(x_0)<t+\frac{1}{k}\\
  \iff&\forall k\in\mathbb{N}^+,x_0\in\liminf_{n\to\infty}E_{n,k}\\
  \iff&x_0\in\bigcap_{k=1}^{\infty}\liminf_{n\to\infty}E_{n,k}=\bigcap_{k=1}^{\infty}\bigcup_{N=1}^{\infty}\bigcap_{n=N}^{\infty}\left\{x:f_n(x)<t+\frac{1}{k}\right\}
\end{aligned}
$$

</details>

{% endnote %}

{% note primary no-icon %}

### <a id="asm-1-3">题 - 1-3</a>

设 $a_n\to a~(n\to\infty)$

证明:
$$\bigcap_{k=1}^{\infty}\bigcup_{N=1}^{\infty}\bigcap_{n=N}^{\infty}\left(a_n-\frac{1}{k},a_n+\frac{1}{k}\right)=a$$

<details open>
<summary><font color='orange'>Proof</font></summary>

令 $E_{n,k}=\left(a_n-\frac{1}{k},a_n+\frac{1}{k}\right)$, 则

$$
\begin{aligned}
  a_0\in\bigcap_{k=1}^{\infty}\bigcup_{N=1}^{\infty}\bigcap_{n=N}^{\infty}\left(a_n-\frac{1}{k},a_n+\frac{1}{k}\right)=\bigcap_{k=1}^{\infty}\liminf_{n\to\infty}E_{n,k}
  \iff&\forall k\in\mathbb{N}^+,a_0\in\liminf_{n\to\infty}E_{n,k}\\
  \iff&a\leqslant a_0\leqslant a\\
  \iff&a_0=a
\end{aligned}
$$

</details>

{% endnote %}
