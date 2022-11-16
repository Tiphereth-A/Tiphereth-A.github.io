---
title: 图论笔记01 - 基础概念
date: 2022-07-01 04:00:27
categories:
  - 笔记
  - 数学
  - 图论
tags:
  - 数学
  - 笔记
  - 组合数学
  - 图论
  - 抽屉原理
  - 简单图
  - 有向图
  - 无限图
  - 可数无限图
  - 局部有限
  - 局部可数
  - 邻域
  - 补图
  - 自补图
  - 反图
  - 底图
  - 线图
  - 握手引理
  - 子图
  - 度矩阵
  - 邻接矩阵
  - 关联矩阵
  - 零图
  - 完全图
  - 二分图
  - 完全二分图
  - 圈图
  - 链图
  - 星图
  - 轮图
  - 正则图
  - 立方图
  - Petersen图
  - Platonic图
  - 超立方体
  - 超立方体图
  - 竞赛图
  - Ramsey定理
  - Ramsey数
---

本章主要介绍一些基础概念

<!-- more -->

## 定义

### 图与简单图

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** 一个**简单图**(simple graph) $G=\lang V(G),E(G)\rang$ 由一个非空有限集合 $V(G)$ 和一个有限集合 $E(G)$ 构成, 其中 $V(G)$ 称为简单图 $G$ 的**顶点集**(vertex-set), 其中的元素被称为**顶点**(vertex), $E(G)\subseteq V^2(G)$ 称为简单图 $G$ 的**边集**(edge-set), 其中的元素被称为**边**(edge), 边是无序的二元元素对

边 $e=\{u,v\}$ 可简写为 $uv$, 称 $e$**连接**(join) 顶点 $u,v$, 顶点 $u,v$ 为 $e$ 的**端点**(ends, endpoints)

{% endnote %}

类似的, 我们有

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 一个**一般图**(general graph) (可简称为**图**(graph)) $G=\lang V(G),E(G)\rang$ 由一个非空有限集合 $V(G)$ 和一个有限集合族 $E(G)$ 构成, 其中 $V(G)$ 称为图 $G$ 的**顶点集**(vertex-set), 其中的元素被称为**顶点**(vertex), $E(G)\subseteq V^2(G)$ 称为图 $G$ 的**边集**(edge-family), 其中的元素被称为**边**(edge), 边是无序的二元元素对

在图 $G$ 中, 若一条边的两个端点相同, 则称该边为**自环**(loops), 若有多条边的端点分别相同, 则称这些边为**重边**(multiple edges)

{% endnote %}

### 同构

{% note info no-icon %}

**<a id="def-1-3">定义 - 1-3</a>** 两个图 $G_1,G_2$ **同构**(isomorphism) 当且仅当

- 两图的顶点集之间存在双射
- 两图的边集之间存在双射

{% endnote %}

如

![](iso1.svg)

和

![](iso2.svg)

是同构的

### 连通

{% note info no-icon %}

**<a id="def-1-4">定义 - 1-4</a>** 若两图 $G_1,G_2$ 的点集不交, 则称 $G_1\cup G_2:=\lang V(G_1)\cup V(G_2), E(G_1)\cup E(G_2)\rang$ 为两图的**并**(union)

{% endnote %}

{% note info no-icon %}

**<a id="def-1-5">定义 - 1-5</a>** 称图 $G$ 是**连通**的(connected), 若 $G$ 不能表示称两个图的并, 否则称其为**不连通**的(disconnected), 若 $G$ 可以表示成若干个连通图的并, 则称这些连通图为 $G$ 的**部件**(components)

{% endnote %}

### 相邻, 度

{% note info no-icon %}

**<a id="def-1-6">定义 - 1-6</a>** 若图 $G$ 有边 $uv$ 此时称, 顶点 $u,v$**相邻**(adjacent), 顶点 $u,v$ 均与 $e$**相关联**(incident)

与点 $v$ 相邻的所有点构成点 $v$ 的**邻域**(neighborhood), 记作 $N(v)$

点集 $U$ 的邻域为与 $U$ 中至少一个点相邻的点构成的集合, 记作 $N(U)$

{% endnote %}

{% note info no-icon %}

**<a id="def-1-7">定义 - 1-7</a>** 顶点 $v$ 的**度**(degree) 为与其相关联的边的条数和自环个数的二倍的和, 记为 $\deg(v)$

度为 $0$ 的点称为**孤立点**(isolated vertex)

度为 $1$ 的点称为**悬挂点**(pendant vertex, end-vertex)

{% endnote %}

我们不难证明如下定理:

{% note success no-icon %}

**<a id="th-1-1">定理 - 1-1</a>** (**握手引理**) 任意图的顶点度数和均为偶数

<details open>
<summary>证明</summary>

点的度数和为边条数的二倍

</details>

{% endnote %}

由此立得

{% note success no-icon %}

**<a id="coll-1-2">推论 - 1-2</a>** 任意图的奇度顶点必有偶数个

{% endnote %}

另外, 由抽屉原理, 我们可知有至少 $2$ 个顶点的简单图必有度相等的顶点

### 子图

{% note info no-icon %}

**<a id="def-1-8">定义 - 1-8</a>** 若 $V(G')\subseteq V(G)$ 且 $E(G')\subset E(G)$, 则称 $G'$ 为 $G$ 的**子图**(subgraph)

对于图 $G$, 取其中的顶点 $v$ 和边 $e$, 称

- $G-e$ 为 $G$ 删去 $e$ 后的子图
- $G-v$ 为 $G$ 删去 $v$ 和与 $v$ 关联的边后的子图
- $G\setminus e$ 为将 $e$ 的两个端点合并后的图

{% endnote %}

|       $G$       |      $G-e$       |      $G-v$       |  $G\setminus e$  |
| :-------------: | :--------------: | :--------------: | :--------------: |
| ![](subgh1.svg) | ![](subgh1e.svg) | ![](subgh1v.svg) | ![](subgh1s.svg) |

### 简单图的补图

{% note info no-icon %}

**<a id="def-1-9">定义 - 1-9</a>** 简单图 $G$ 的**补图**(complement) $\bar G$ 满足

- $V(\bar G)=V(G)$
- $e\in E(\bar G)\iff e\notin E(G)$

若一个图和自身的补图同构, 则称其为**自补图**(self-complementary)

{% endnote %}

|       $G$       |    $\bar G$     |
| :-------------: | :-------------: |
| ![](compl1.svg) | ![](compl2.svg) |

### 度矩阵, 邻接矩阵与关联矩阵

{% note info no-icon %}

**<a id="def-1-10">定义 - 1-10</a>** 设图 $G$ 的顶点标号为 $1..n$, 边标号为 $1..m$, 称

- **度矩阵**(degree matrix) $D$ 为 $n\times n$ 阶对角矩阵, 其中 $d_{ii}=\deg(i)$
- **邻接矩阵**(adjacency matrix) $A$ 为 $n\times n$ 阶矩阵, 其中 $a_{ij}$ 为连接点 $i,j$ 的边的总数
- **关联矩阵**(incidence matrix) $M$ 为 $n\times m$ 阶矩阵, 其中若点 $i$ 与边 $j$ 相关联, 则 $m_{ij}=1$, 否则 $m_{ij}=0$

{% endnote %}

度矩阵, 邻接矩阵与关联矩阵有很多性质, 如

{% note primary no-icon %}

**<a id="pb-1-1">命题 - 1-1</a>**

- 两简单图 $G,H$ 同构当且仅当存在排列矩阵 $P$ 使得

  $$A_G=PA_HP^T$$

{% endnote %}

### 有向图

{% note info no-icon %}

**<a id="def-1-11">定义 - 1-11</a>** 若图的边是有序的二元元素对, 则此时的图即为**有向图**(digraph), 此时的边又称为**弧**(arc)

{% endnote %}

无向图的若干概念均可类推到有向图上, 比如:

{% note info no-icon %}

**<a id="def-1-12">定义 - 1-12</a>** 有向图的度分为**入度**(inner degree) 和**出度**(outer degree), 分别表示从该点出发的边的条数和以该点结束的边的条数, 分别记作 $\operatorname{indeg}$, $\operatorname{outdeg}$ 或 $\deg_-$, $\deg_+$

{% endnote %}

类似地, 有向图的握手引理如下:

{% note success no-icon %}

**<a id="th-1-3">定理 - 1-3</a>** (**握手引理**) 任意一个有向图的入度和等于出度和

{% endnote %}

下面的两个概念仅适用于有向图

{% note info no-icon %}

**<a id="def-1-13">定义 - 1-13</a>** 去掉有向图边的方向后得到的无向图称为**底图**(undelying graph)

{% endnote %}

{% note info no-icon %}

**<a id="def-1-14">定义 - 1-14</a>** 将有向图边的方向反向后得到的有向图称为**反图**(converse, transpose graph)

{% endnote %}

### 线图

{% note info no-icon %}

**<a id="def-1-15">定义 - 1-15</a>** 简单图 $G$ 的**线图**(line graph) $L(G)$ 是满足如下条件的图:

- $L(G)$ 的点集和 $G$ 的边集同构
- $L(G)$ 中两点相邻当且仅当 $G$ 中对应的边有公共端点

{% endnote %}

### 无限图

{% note info no-icon %}

**<a id="def-1-16">定义 - 1-16</a>** **无限图**(infinite graph) 是点集为无限集合或边集为无限集合的图

若无限图的点集和边集均可数, 则称其为**可数无限图**(countable graph)

{% endnote %}

{% note info no-icon %}

**<a id="def-1-17">定义 - 1-17</a>** 若无限图所有点的度数均有限, 则称该图为**局部有限**(locally finite)的

若无限图所有点的度数均可数, 则称该图为**局部可数**(locally countable)的

{% endnote %}

下面给出一个基本定理

{% note success no-icon %}

**<a id="th-1-4">定理 - 1-4</a>** 局部可数的连通无限图是可数无限图

<details open>
<summary>证明</summary>

在局部可数的连通无限图 $G$ 中任取一点 $v$, 设 $N_0=\{v\}, N_1=N(N_0)$, $N_2=N(N_1),...$, 则 $N_1,N_2,...$ 均可数, 且由连通性可得

$$V(G)=\bigcup_{i=0}^{\infty}N_i$$

因此 $G$ 是可数无限图

</details>

{% endnote %}

{% note success no-icon %}

**<a id="coll-1-5">推论 - 1-5</a>** 局部有限的连通无限图是可数无限图

{% endnote %}

## 例子

### 零图

{% note info no-icon %}

**<a id="def-1-18">定义 - 1-18</a>** **零图**(null graph) $N_n$

边集为空的的图

{% endnote %}

### 完全图

{% note info no-icon %}

**<a id="def-1-19">定义 - 1-19</a>** **完全图**(complete graph) $K_n$

任意两点均相邻的简单图

{% endnote %}

完全图和零图互为补图

### 竞赛图

{% note info no-icon %}

**<a id="def-1-20">定义 - 1-20</a>** **竞赛图**(tournament)

底图是完全图的有向图

{% endnote %}

{% note primary no-icon %}

**<a id="pb-1-2">命题 - 1-2</a>** 竞赛图的入度平方和等于出度平方和

<details open>
<summary><font color='orange'>Hint</font></summary>

考虑 $\sum_v\operatorname{indeg}^2(v)-\sum_v\operatorname{outdeg}^2(v)$

</details>

{% endnote %}

{% note primary no-icon %}

**<a id="pb-1-3">命题 - 1-3</a>** $n$ 个顶点的竞赛图的邻接矩阵的秩为 $n$ 或 $n-1$, 且若秩为 $n$, 则其为 Hamilton 图, 否则为半 Hamilton 图

{% endnote %}

### 二分图

{% note info no-icon %}

**<a id="def-1-21">定义 - 1-21</a>** **二分图**(bipartitle graph)

$G=\lang A,B,E(G)\rang$ 满足

- $V(G)=A\cup B$
- $A\cap B=\varnothing$
- $E(G)\cap (A^2\cup B^2)=\varnothing$

{% endnote %}

类似地, 可以定义

- 完全二分图 $K_{s,t}$
- $k$ 分图
- 完全 $k$ 分图

### 圈图

{% note info no-icon %}

**<a id="def-1-22">定义 - 1-22</a>** **圈图**(cycle graph) $C_n$

任意点的度均为 $2$ 的连通图

{% endnote %}

### 链图

{% note info no-icon %}

**<a id="def-1-23">定义 - 1-23</a>** **链图**(chain graph, path graph)

$P_n=C_n-e$, $\exists e\in E(C_n)$

{% endnote %}

### 星图

{% note info no-icon %}

**<a id="def-1-24">定义 - 1-24</a>** **星图**(star graph) $S_n$

$\exists_1 v\in V(S_n)$ 使得

- $\deg(v)=n-1$
- $\forall v'\in V(S_n)\setminus\{v\},\deg(v')=1$

{% endnote %}

### 轮图

{% note info no-icon %}

**<a id="def-1-25">定义 - 1-25</a>** **轮图**(wheel graph) $W_n$

$\exists_1 v\in V(W_n)$ 使得

- $\deg(v)=n-1$
- $W_n-v=C_{n-1}$

{% endnote %}

### 正则图

{% note info no-icon %}

**<a id="def-1-26">定义 - 1-26</a>** $k$-**正则图**($k$-regular graph)

所有顶点的度均为 $k$ 的图称为 $k$-正则图

{% endnote %}

显然奇正则图的顶点数为偶数

$k$-正则图的线图是 $2k-2$-正则图

### 立方图

{% note info no-icon %}

**<a id="def-1-27">定义 - 1-27</a>** **立方图**(cubic graph)

$3$-正则图

{% endnote %}

### Petersen 图

![](petersen.svg)

> From https://www.integral-domain.org/lwilliams/Resources/tikzsnippets.php, 给出的这三个图同构

经常用于构造反例

### Platonic 图

又叫正多面体图, 一共有五种

![](platonic.svg)

> From https://www.integral-domain.org/lwilliams/Resources/tikzsnippets.php

### 超立方体图

{% note info no-icon %}

**<a id="def-1-28">定义 - 1-28</a>** **超立方体图**($k$-cube graph) $Q_n$

- $V(Q_n)=\{\overline{a_1a_2...a_n}:a_i\in\{0,1\},\forall i\in 1..n\}$
- $E(Q_n)=\{\{\overline{a_1a_2...a_n},\overline{b_1b_2...b_n}\}:\exists_1 i\in 1..n, a_x=b_x\iff x=i \}$

{% endnote %}

不难发现

- $Q_n$ 可以和 $n$ 维超立方体一一对应
- $Q_n$ 是二分图

![](cube4.svg)

> $Q_4$, From https://www.integral-domain.org/lwilliams/Resources/tikzsnippets.php

## Ramsey 定理

{% note success no-icon %}

**<a id="th-1-6">定理 - 1-6</a>** (Ramsey 定理) 对任意 $6$ 顶点的图 $G$, $C_3$ 要么是 $G$ 的子图, 要么是 $\bar G$ 的子图

<details open>
<summary>证明</summary>

考虑对 $K_6$ 的边染色, 将 $G$ 中的所有边在 $K_6$ 中的对应均染为红色, 其余染为蓝色, 接下来只需证明无论如何染色, 最终都会染出同色三角形即可

由抽屉原理, 对于任意一个点, 与其关联的 $5$ 条边中要么有 $3$ 条是红色, 要么有 $3$ 条是蓝色, 那么对于这 $3$ 条相同颜色的边来说, 不难发现其另一边的端点两两之间的边无论如何染色, 最终都会出现同色三角形

</details>

{% endnote %}

{% note info no-icon %}

**<a id="def-1-29">定义 - 1-29</a>** **Ramsey 数** $R(k,m)$ 为最小的正整数 $n$ 满足: 对任意的 $n$ 顶点的简单图 $G$, 要么 $K_k$ 是 $G$ 的子图, 要么 $K_m$ 是 $\bar G$ 的子图

{% endnote %}

我们可以得到两条性质:

- $R(k,m)=R(m,k)$
- 若 $k,m\geq 2$, 则 $R(k,m)\leq R(k-1,m)+R(k,m-1)$

根据 <a href="#t-1-6">定理 - 1-6</a>, 我们知道 $R(3,3)\leq 6$

不难验证 $R(3,3)=6$

### 目前已知的 Ramsey 数

> From <https://mathworld.wolfram.com/RamseyNumber.html>

| $n$ | $k$ | $R(n,k)$ | Reference                   |
| --- | --- | -------- | --------------------------- |
| 3   | 3   | 6        | Greenwood and Gleason 1955  |
| 3   | 4   | 9        | Greenwood and Gleason 1955  |
| 3   | 5   | 14       | Greenwood and Gleason 1955  |
| 3   | 6   | 18       | Graver and Yackel 1968      |
| 3   | 7   | 23       | Kalbfleisch 1966            |
| 3   | 8   | 28       | McKay and Min 1992          |
| 3   | 9   | 36       | Grinstead and Roberts 1982  |
| 4   | 4   | 18       | Greenwood and Gleason 1955  |
| 4   | 5   | 25       | McKay and Radziszowski 1995 |
