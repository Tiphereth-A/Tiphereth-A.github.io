---
title: 图论笔记02 - 路与圈
date: 2022-07-01 08:00:27
categories:
  - 笔记
  - 数学
  - 图论
tags:
  - 数学
  - 笔记
  - 组合数学
  - 图论
  - 路径
  - 迹
  - 简单路径
  - 圈
  - 三角形
  - 围长
  - 不连通集/边割
  - 极小边割
  - 平凡边割
  - 边连通度
  - 桥
  - 分离集/点割
  - 割点
  - 点连通度
  - Menger定理
  - Euler圈
  - Euler路
  - Hamilton圈
  - Hamilton路
---

本章主要进一步介绍连通性, 路与圈相关的内容

<!-- more -->

## 路径, 迹, 简单路径, 圈

{% note info no-icon %}

**<a id="def-2-1">定义 - 2-1</a>**

- **路径**(walk): 若序列 $v_0\to v_1\to...\to v_n$ 中, $\forall i=0..n-1$, $v_i$ 与 $v_{i+1}$ 相邻, 则称该序列为一条路径

  称 $v_0$ 为**起点**(initial vertex), $v_n$ 为**终点**(final vertex), $n$ 为路径的**长度**(length)

- **迹**(trail): 若一条路径经过的边没有重复, 则称其为迹
- **简单路径**(path): 若一条迹经过的点没有重复 (起点和终点重复的情况除外), 则称其为简单路径

若一条路径(迹, 简单路径)的起点和终点相同, 则称其为**闭路径**(**闭迹**, **闭简单路径**), 闭简单路径又叫**圈**(cycle)

另外, 我们将长度为 3 的圈称为**三角形**(triangle)

{% endnote %}

例如, 对于下图

![conn1](conn1.svg)

- $v\to w\to x\to y\to z\to z\to x$ 是迹
- $v\to w\to x\to y\to z\to x\to v$ 是闭迹
- $v\to w\to x\to y\to z$ 是简单路径
- $v\to w\to x\to y\to v$ 是圈

{% note info no-icon %}

**<a id="def-2-2">定义 - 2-2</a>** 对于图 $G$, 定义

- $\delta(G):=\min\{\deg(v):v\in V(G)\}$
- $\Delta(G):=\max\{\deg(v):v\in V(G)\}$
- **围长**(girth) $g(G)$: $G$ 的最短圈长度, 若 $G$ 没有圈, 则 $g(G)=0$
- **距离**(distance) $d(x,y)$: 为 $x,y$ 之间所有路径中的最短长度, 若 $x,y$ 之间不存在路径, 则 $d(x,y)=\infty$
- **直径**(diameter) $\operatorname{diam}(G):=\max\{d(u,v):u,v\in G\}$

{% endnote %}

{% note success no-icon %}

**<a id="th-2-1">定理 - 2-1</a>**

- 若图 $G$ 满足 $\delta(G)\geq 2$, 则 $G$ 中笔有一条长为 $\delta(G)$ 的路和长为 $\delta(G)+1$ 的圈
- 若图 $G$ 有圈, 则 $g(G)\leq 2\operatorname{diam}(G)+1$

{% endnote %}

{% note success no-icon %}

**<a id="th-2-2">定理 - 2-2</a>** 一个图是二分图当且仅当图中所有的圈都是偶长的

<details open>
<summary>证明</summary>

- $\implies$: 假设 $v_0\to v_1\to...\to v_n$ 是一个圈, 只需按下标的奇偶性来划分即可
- $\impliedby$: 不妨假设图是连通的, 任取一个点 $v$, 考虑其他点和 $v$ 的最短距离, 将与 $v$ 距离是偶数的点和 $v$ 划分到同一组, 剩下的划分为另一组, 不难发现这两个划分不交且所有点都能划分到这两组中

</details>

{% endnote %}

{% note success no-icon %}

**<a id="th-2-3">定理 - 2-3</a>** 若简单图 $G$ 有 $n$ 个顶点, $m$ 条边, $k$ 个部件, 则

$$n-k\leq m\leq \frac{(n-k)(n-k+1)}{2}$$

{% endnote %}

{% note success no-icon %}

**<a id="coll-2-4">推论 - 2-4</a>** 若有 $n$ 个顶点的简单图有至少 $(n-1)(n-2)/2$ 条边, 则该图连通

{% endnote %}

## 连通性

{% note info no-icon %}

**<a id="def-2-3">定义 - 2-3</a>**

- **不连通集/边割**(disconnecting set/edge cut): 若 $E_0\subseteq E(G)$ 满足 $G-E_0$ 不连通, 则称 $E_0$ 为不连通集/边割
- **极小边割**(cutset): 若边割 $E_0$ 的任意真子集均不是边割, 则称 $E_0$ 为极小边割
- 若极小边割 $E_0=\{e\}$, 则称 $e$ 为**桥**(bridge)
- 定义 $\lambda(G)$ 为 $G$ 的最小边割的大小, 称为**边连通度**(edge-connectivity)
- 若 $\lambda(G)\geq k$, 则称 $G$ 是 $k$-**边连通**($k$-edge-connected)的

- $E(X,Y)$ 为图 $G$ 中边的端点分别落在点集 $X,Y$ 的所有边的集合
- $e(X,Y)=|E(X,Y)|$, $e(X)=e(X,X)$
- $\partial(X):=E(X,V(G)\setminus X)$, 显然 $\parallel(X)$ 是边割

  不难得出
  $$|\partial(X)|=\sum_{v\in V(G)}\deg(v)-2e(X)$$

- **平凡边割**: 对于无自环图 $G$, 任取一点 $v$, 称 $\partial(v)$ 是平凡边割, 显然 $|\partial(v)|=\deg(v)$

{% endnote %}

显然

- $\lambda(K_n)=n-1$
- $\lambda(P_n)=1$
- $\lambda(C_n)=2$
- $\lambda(K_{n,m})=\min\{n,m\}$

{% note success no-icon %}

**<a id="th-2-5">定理 - 2-5</a>** 两个极小边割的对称差是边割

{% endnote %}

{% note success no-icon %}

**<a id="th-2-6">定理 - 2-6</a>** 称所有点的度均为奇数的图 $G$ 为奇图, 则

$$|\partial(X)|\equiv|X|\pmod 2,~\forall X\subset V(G)$$

{% endnote %}

{% note info no-icon %}

**<a id="def-2-4">定义 - 2-4</a>**

- **分离集/点割**(disconnecting set/vertex cut): 若 $V_0\subseteq V(G)$ 满足 $G-V_0$ 不连通, 则称 $V_0$ 为分离集 /点割
- 若点割 $V_0=\{v\}$, 则称 $v$ 为**割点**(cut-vertex)
- 定义 $\kappa(G)$ 为 $G$ 的最小点割的大小, 称为 **(点)连通度**(vertex-connectivity)
- 若 $\kappa(G)\geq k$, 则称 $G$ 是 $k$-**(点)连通**($k$-connected)的

{% endnote %}

显然

- $\kappa(K_n)=n-1$
- $\kappa(P_n)=1$
- $\kappa(C_n)=2$
- $\kappa(K_{n,m})=\min\{n,m\}$

---

关于连通度, 我们有如下的 Menger 定理

{% note success no-icon %}

**<a id="th-2-7">定理 - 2-7</a>** (Menger, 1927)

- 图 $G$ 是 $k$-边连通的当且仅当图中任意两个**不相同**的点之间都有 $k$ 条路径, 且这些路径之间的任意两条均没有公共边
- 至少有 $k+1$ 个点的图 $G$ 是 $k$-连通的当且仅当图中任意两个点之间都有 $k$ 条路径, 且这些路径之间的任意两条除起点和终点外没有公共点

{% endnote %}

具体证明将在图的匹配中讲解

---

另外, 对任意连通图, 我们有如下结论

{% note success no-icon %}

**<a id="th-2-8">定理 - 2-8</a>** 对任意连通图 $G$,

$$\kappa(G)\leq\lambda(G)\leq\delta(G)$$

<details open>
<summary>证明</summary>

</details>

{% endnote %}

## Euler 圈, Euler 路

## Hamilton 圈, Hamilton 路
