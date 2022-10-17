---
title: "笔记 - 二次剩余,legendre符号与二次互反律"
categories:
  - 笔记
  - 数学
  - 初等数论
tags:
  - 数学
  - 笔记
  - 数论
  - 二次剩余
  - Legendre符号
  - 二次互反律
date: 2020-04-19 11:02:38
---

## 二次剩余

满足 $\exists x\in\Bbb{Z}_m,\ s.t.\ x^2\equiv a\pmod m$ 的 $a$ 为模 $p$ 的二次剩余

- 以下所有内容假定**模数为奇素数**

<!--more-->

## 性质

1. 来自 {% post_link primitive-root-and-discrete-logarithm %} 中 3.1.2 的特化

   1. $a$ 为模 $m$ 的二次剩余 $\iff 2\mid\operatorname{ind}_ga\iff a^\frac{m-1}{2}\equiv1\pmod m$
   1. $a$ 为模 $m$ 的二次剩余

      $\implies|\{x|x^2\equiv a\pmod m\}|=2,\{x|x^2\equiv a\pmod m\}=\{\overline{g^{ {\operatorname{ind}_ga\over 2}+i\frac{m-1}{2} } }|i=0,1\}$

   1. 模 $m$ 的二次剩余共 $\frac{m-1}{2}$ 个, 分别为 $a\equiv g^{2i},i=0,...,\frac{m-3}{2}$; 模 $m$ 的非二次剩余共 $\frac{m-1}{2}$ 个, 分别为 $a\equiv g^{2i+1},i=0,...,\frac{m-3}{2}$

1. 在 $p\nmid ab$ 时, $(\frac{ab}{p})=(\frac{a}{p})(\frac{b}{p})$

## Legendre 符号

$\displaystyle\Big(\frac{a}{p}\Big)=\begin{cases}
  0&,p\mid a\\
  1&,p\nmid a\land\exists x\in\Bbb{Z}_p,\ s.t.\ x^2\equiv a\pmod p\\
  -1&,p\nmid a\land\nexists x\in\Bbb{Z}_p,\ s.t.\ x^2\equiv a\pmod p\\
\end{cases}$

$\displaystyle\Big(\frac{a}{p}\Big)\equiv a^\frac{p-1}{2}\pmod p$

$(\frac{-1}{p})=(-1)^\frac{p-1}{2}=\begin{cases}
  1&,p\equiv1\pmod 4\\
  -1&,p\equiv3\pmod 4\\
\end{cases}$

### 性质

1. $(\frac{ab}{p})=(\frac{a}{p})(\frac{b}{p})$ (完全积性)
1. $a\equiv b\pmod p\implies(\frac{a}{p})=(\frac{b}{p})$
1. $x^2\equiv a\pmod p$ 的解数为 $1+(\frac{a}{p})$
1. Gauss 引理(证明用途更大, 略)

## 二次互反律

设 $p\ne q$

$$
(\frac{p}{q})(\frac{q}{p})=(-1)^{ \frac{p-1}{2}\frac{q-1}{2} }=\begin{cases}
  -1&,p\equiv q\equiv3\pmod 4\\
  1&,otherwise
\end{cases}
$$
