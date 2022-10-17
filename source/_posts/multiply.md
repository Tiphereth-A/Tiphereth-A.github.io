---
title: 倍增 - 扩展快速幂
categories:
  - 算法竞赛
  - 笔记
tags:
  - 算法竞赛
  - 算法
  - 倍增
  - 快速幂
  - RMQ
  - LCA
  - 基环内/外向树
date: 2020-04-27 13:48:01
---

想不到吧, 倍增还能和快速幂联系到一起

<!-- more -->

在开始之前, 让我们先明确一些定义

## 定义

1. $m$ 元运算: 一个 $A^m\to A$ 的映射
1. 对一元运算 $\phi,\nu$

   1. 恒等运算: $e:A\to A;a\mapsto a$
   1. 乘法: $(\phi\circ\nu)(a):=\phi(\nu(a))$

      在不引起歧义的情况下可记作 $\phi\nu(a)$

      该运算显然具有结合律

   1. 乘方: $\phi^n(a):=\begin{cases}
     e(a),&n=0\\
     \phi^{n-1}\phi(a),&n>0
   \end{cases}(n\in\mathbb{N})$
   1. $\phi_k:=\phi^{2^k}$

1. 对二元运算 $\tau$
   1. 对 $l,r\in\mathbb{N},l\leqslant r$, 定义 $\tau[l,r]:=\begin{cases}
  \tau(l,l),&l=r\\
  \tau(l,\tau[l+1,r]),&otherwise
\end{cases}$

## 概述

倍增是一种针对特定运算的优化策略, 可以使复杂度从 $O(n)$ 降至 $O(\log n)$

特定运算即具有**结合律**的运算

## 倍增

注意到

- $\phi_{n+1}=\phi_n\phi_n,\forall n\in\mathbb{N}$
- $\phi^n=\displaystyle\sum_{i=0}^{\lfloor\log_2n\rfloor}b_i\phi_i,\forall n=\overline{b_{\lfloor\log_2n\rfloor}...b_1b_0}_{(2)}\in\mathbb{N}^+$

故我们可以先 $O(\log n)$ 预处理出 $\phi_k$, 便可以 $O(\log n)$ 的复杂度算出 $\phi^n$

这就是倍增的思想

倍增也就是**运算的快速幂**, 这也就是标题的含义了

### 实现

- 预处理

  $\begin{array}{l|l}
    1 & \textbf{function}~ \text{Initialize}()\\
    2 & \quad \textbf{for}~ i \gets 0 ~\textbf{to}~ constant ~\textbf{do} \\
    3 & \quad \quad \textbf{for}~ j \gets minimun ~\textbf{to}~ maximum ~\textbf{do}\\
    4 & \quad \quad \quad \phi_{i,j} \gets \phi_{i-1,\phi_{i-1,j}} \\
    5 & \quad \quad \textbf{end}~\textbf{for} \\
    6 & \quad \textbf{end}~\textbf{for} \\
    7 & \quad \textbf{return}~ \phi \\
    8 & \textbf{end}~\textbf{function}
  \end{array}$

- 计算 $\phi^n(a)$

  $\begin{array}{r|l:l}
  1 & \textbf{function}~ \text{Query}(\phi,n,a)\\
  2 & \quad \textbf{for}~ i \gets 0 ~\textbf{to}~ constant ~\textbf{do} \\
  3 & \quad \quad \textbf{if}~ n ~\text{and}~ 2^i=2^i ~\textbf{then}~ a \gets \phi_{i,a} \\
  4 & \quad \textbf{end}~\textbf{for} \\
  5 & \quad \textbf{return}~ a \\
  6 & \textbf{end}~\textbf{function}
  \end{array}$

## 应用

### 快速幂

只有理论上的意义, 即快速幂和倍增二者之间的关系

### ST 表

ST 表是用于解决**可重复性贡献问题**的数据结构[^1]

可重复性贡献问题即在 $\tau(x,x)=x$ 且 $\tau$ 满足结合律时询问 $\tau[l,r]$

二元运算是不能直接上倍增的, 但我们可以将其转化成一元运算

定义 $\phi_k(l)=\tau[l,l+2^k-1]$, 此时就可以用倍增了

$\begin{array}{l|l}
  1 & \textbf{function}~ \text{Initialize}(array,\tau,l,r)\\
  2 & \quad length \gets \lfloor\log_2(r-l+1)\rfloor\\
  3 & \quad \textbf{for}~ i \gets l ~\textbf{to}~ r ~\textbf{do} \\
  4 & \quad \quad \phi_{0,i} \gets array_i\\
  5 & \quad \textbf{end}~\textbf{for} \\
  6 & \quad \textbf{for}~ i \gets 1 ~\textbf{to}~ length ~\textbf{do} \\
  7 & \quad \quad \textbf{for}~ j \gets l ~\textbf{to}~ r-2^i+1 ~\textbf{do}\\
  8 & \quad \quad \quad \phi_{i,j} \gets \tau(\phi_{i-1,j},\phi_{i-1,j+2^{i-1}}) \\
  9 & \quad \quad \textbf{end}~\textbf{for} \\
  10 & \quad \textbf{end}~\textbf{for} \\
  11 & \quad \textbf{return}~ \phi \\
  12 & \textbf{end}~\textbf{function} \\
  13 & \\
  14 & \textbf{function}~ \text{Query}(\phi,\tau,l,r)\\
  15 & \quad length \gets \lfloor\log_2(r-l+1)\rfloor\\
  16 & \quad \textbf{return}~ \tau(\phi_{length,l},\phi_{length,r-2^{length}+1}) \\
  17 & \textbf{end}~\textbf{function}
\end{array}$

### LCA

### 基环内/外向树 dp

[^1]: [ST 表 - OI Wiki](https://oi-wiki.org/ds/sparse-table/)
