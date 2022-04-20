---
title: '笔记 - 二次剩余,legendre符号与二次互反律'
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

满足$\exists x\in\Bbb{Z}_m,\ s.t.\ x^2\equiv a\pmod m$的$a$为模$p$的二次剩余

- 以下所有内容假定**模数为奇素数**

<!--more-->

## 性质

1. 来自[数论笔记-原根与指数(离散对数)](../primitive-root-and-discrete-logarithm)中3.1.2的特化
   1. $a$为模$m$的二次剩余$\iff 2\mid\operatorname{ind}_ga\iff a^{m-1\over 2}\equiv1\pmod m$
   1. $a$为模$m$的二次剩余  

      $\implies|\{x|x^2\equiv a\pmod m\}|=2,\{x|x^2\equiv a\pmod m\}=\{\overline{g^{ {\operatorname{ind}_ga\over 2}+i{m-1\over 2} } }|i=0,1\}$
   1. 模$m$的二次剩余共${m-1\over 2}$个, 分别为$a\equiv g^{2i},i=0,...,{m-3\over 2}$; 模$m$的非二次剩余共${m-1\over 2}$个, 分别为$a\equiv g^{2i+1},i=0,...,{m-3\over 2}$
1. 在$p\nmid ab$时, $({ab\over p})=({a\over p})({b\over p})$

## Legendre符号

$\displaystyle\Big({a\over p}\Big)=\begin{cases}
  0&,p\mid a\\
  1&,p\nmid a\land\exists x\in\Bbb{Z}_p,\ s.t.\ x^2\equiv a\pmod p\\
  -1&,p\nmid a\land\nexists x\in\Bbb{Z}_p,\ s.t.\ x^2\equiv a\pmod p\\
\end{cases}$

$\displaystyle\Big({a\over p}\Big)\equiv a^{p-1\over 2}\pmod p$

$({-1\over p})=(-1)^{p-1\over 2}=\begin{cases}
  1&,p\equiv1\pmod 4\\
  -1&,p\equiv3\pmod 4\\
\end{cases}$

### 性质

1. $({ab\over p})=({a\over p})({b\over p})$ (完全积性)
1. $a\equiv b\pmod p\implies({a\over p})=({b\over p})$
1. $x^2\equiv a\pmod p$的解数为$1+({a\over p})$
1. Gauss引理(证明用途更大, 略)

## 二次互反律

设$p\ne q$

$$({p\over q})({q\over p})=(-1)^{ {p-1\over2}{q-1\over2} }=\begin{cases}
  -1&,p\equiv q\equiv3\pmod 4\\
  1&,otherwise
\end{cases}$$
