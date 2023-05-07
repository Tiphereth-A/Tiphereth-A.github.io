---
title: 拟阵简介（unfin）
date: 2023-05-01 08:00:24
categories:
  - 笔记
  - 数学
tags:
  - 数学
  - 笔记
  - 组合数学
  - 图论
  - 拟阵
---

拟阵最早由 Hassler Whitney 于 1935 年作为线性相关的推广提出。拟阵理论在组合数学、最优化、图论等领域有很多应用。拟阵可以用来证明贪心算法的正确性，如 Kruskal 算法、匈牙利算法等。

<!-- more -->

## 定义

拟阵有许多等价定义，为方便起见，我们先给出基于独立集的定义。

### 拟阵

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>（基于独立集的拟阵定义）**

定义 $M=(E,\mathcal{I})$，其中 $E$ 是有限集合，$\mathcal{I}$ 是 $E$ 的子集族。若 $\mathcal{I}$ 满足：

1. $\varnothing\in\mathcal{I}$
2. $\forall A'\subset A\subset E$，$A\in\mathcal{I}\implies A'\in\mathcal{I}$（遗传性，hereditary property）
3. 若 $A,B\in\mathcal{I}$ 且 $|A|>|B|$，则存在 $x\in A\setminus B$ 使得 $B\cup\{x\}\in\mathcal{I}$（独立集的交换性，independent set exchange property）

则称 $M$ 是（有限）**拟阵**（matroid），$E$ 称为**基础集**（ground set），$\mathcal{I}$ 称为独立集族（independent sets）。

对拟阵 $M=(E,\mathcal{I})$，若 $A\in\mathcal{I}$，则称 $A$ 为**独立集**（independent set），否则称为**相关集**（dependent）。

{% endnote %}

为便于理解，我们在此先给出一个简单的例子。

考虑有限线性空间 $V$（如 $(\mathbf{Z}_{7})^{3}$），定义 $\mathcal{I}$ 为包含 $V$ 中全部线性无关子集的子集族，则由线性无关的性质可知 $\mathcal{I}$ 满足上述的三条性质，故 $(V,\mathcal{I})$ 为一拟阵。这个拟阵是向量拟阵，在 [下文](#线性拟阵向量拟阵) 我们会进一步介绍。

接下来我们给出一些基本概念。

### 同构

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 对拟阵 $M_1=(E_1,\mathcal{I}_1)$ 和 $M_2=(E_2,\mathcal{I}_2)$，若存在双射 $f:E_1\to E_2$ 使得

$$
A\in\mathcal{I}_1\iff f(A)\in\mathcal{I}_2,\quad \forall A\subseteq E_1
$$

则称 $M_1$ 和 $M_2$ **同构**。

类似可定义拟阵的单同态和满同态。

{% endnote %}

### 基

{% note info no-icon %}

**<a id="def-1-3">定义 - 1-3</a>** 对拟阵 $M=(E,\mathcal{I})$，若 $B\in\mathcal{I}$，但 $\nexists B'\supset B$ 使得 $B'\in\mathcal{I}$（即极大独立集），则称 $B$ 为拟阵 $M$ 的**基**（basis）。

称 $\mathcal{B}(M)$ 或 $\mathcal{B}$ 为拟阵 $M$ 中所有基构成的集合。

{% endnote %}

### 圈

{% note info no-icon %}

**<a id="def-1-4">定义 - 1-4</a>** 对拟阵 $M=(E,\mathcal{I})$，若 $C\notin\mathcal{I}$，但 $\forall C'\subset C$ 均有 $C'\in\mathcal{I}$（即极小相关集），则称 $C$ 为拟阵 $M$ 的**圈**（circuit）。

称 $\mathcal{C}(M)$ 或 $\mathcal{C}$ 为拟阵 $M$ 中所有圈构成的集合。

{% endnote %}

### 秩函数

{% note info no-icon %}

**<a id="def-1-5">定义 - 1-5</a>** 对拟阵 $M=(E,\mathcal{I})$，定义函数 $r(A)=\max\{|X|:X\subseteq A, X\in\mathcal{I}\},,~\forall A\subseteq E$，称其为拟阵 $M$ 的**秩函数**（rank function）。

称 $r(M)=r(E)$ 为拟阵 $M$ 的**秩**（rank）。

若 $r(A\cup\{x\})=r(A)$，则称 $x$ 与 $A$ 相关（$x\in E$），记作 $x\sim A$

{% endnote %}

### 闭包算子与闭集

{% note info no-icon %}

**<a id="def-1-6">定义 - 1-6</a>** 对拟阵 $M=(E,\mathcal{I})$，定义 $\operatorname{cl}(A)=\{x\in E:r(A)=r(A\cup\{x\})\},~\forall A\subseteq E$，称其为**闭包算子**（closure operator）。

称 $\operatorname{cl}(A)$ 为 $A$ 的**闭包**（closure/span）。

若 $A=\operatorname{cl}(A)$，则称 $A$ 为拟阵 $M$ 的**闭集**（closed/flat/subspace）。

{% endnote %}

## 性质

### 基的性质

{% note primary no-icon %}

**<a id="prop-2-1">性质 - 2-1</a>** 对拟阵 $M=(E,\mathcal{I})$，

1. 拟阵的极大独立集是最大独立集，即 $\forall B_1,B_2\in\mathcal{B}(M)$，$|B_1|=|B_2|$
2. （1 的推论）$\forall B\in\mathcal{B}(M)$，$\nexists B'\in\mathcal{B}(M)$ 使得 $B'\subset B$
3. 对任意 $X\in\mathcal{I}$ 均存在 $B\in\mathcal{B}(M)$ 使得 $X\subseteq B$
4. 在 $\mathcal{B}(M)$ 中任取两个基 $B_1$，$B_2$，设 $a\in B_1\setminus B_2$，则存在 $b\in B_2\setminus B_1$ 使得 $(B_1\setminus \{a\})\cup\{b\}\in\mathcal{B}(M)$（基的交换性，basis exchange property）

{% endnote %}

不难发现基的概念和线性空间中的基对应。

### 圈的性质

{% note primary no-icon %}

**<a id="prop-2-2">性质 - 2-2</a>** 对拟阵 $M=(E,\mathcal{I})$，

1. $\forall C\in\mathcal{C}(M),x\in C$，$C\setminus\{x\}\in\mathcal{I}$
   1. （1 的推论）$\forall C\in\mathcal{C}(M)$，$\nexists C'\in\mathcal{C}(M)$ 使得 $C'\subset C$
2. $\forall X\notin\mathcal{I}$，$\exists C\subseteq X$ 使得 $C\in\mathcal{C}(M)$
3. $\forall C_1,C_2\in\mathcal{C}(M),x\in C_1\cap C_2$，令 $X=(C_1\cap C_2)\setminus\{x\}$，则 $\exists C\in\mathcal{C}(M)$ 使得 $C\subseteq X$

{% endnote %}

### 秩函数的性质

{% note primary no-icon %}

**<a id="prop-2-3">性质 - 2-3</a>** 对拟阵 $M=(E,\mathcal{I})$，

1. $r(\varnothing)=0$
2. $r(X)\leq r(X\cup\{x\})\leq r(X)+1,\quad \forall X\subseteq E;x\in E$

   1. （2 的推论）$\forall X'\subseteq X\subseteq E$，

      $$
      0\leq r(X)-r(X')\leq |X\setminus X'|
      $$

3. 若 $r(X\cup\{x\})=r(X\cup\{y\})=r(X)$, 则 $r(X\cup\{x\}\cup\{y\})=r(X),\quad \forall X\subseteq E;x,y\in E$
4. （3 的推论）$\forall X_1,X_2\subseteq E$，若 $\forall x\in X_2$ 均有 $r(X_1\cup\{x\})=r(X_1)$，则

   $$
   r(X_1\cup X_2)=r(X_1)
   $$

5. 函数 $r:2^E\to \mathbf{Z}^+$ 是秩函数当且仅当以下诸款成立：
   1. $\forall X\subseteq E$，$0\leq r(X)\leq |X|$
   2. $\forall X\subseteq Y\subseteq E$，$r(X)\leq r(Y)$
   3. $\forall X,Y\subseteq E$，$r(X\cup Y)+r(X\cap Y)\leq r(X)+r(Y)$（次模性）

{% endnote %}

不难发现秩和秩函数的概念和线性空间中的秩对应。

### 闭包算子的性质

{% note primary no-icon %}

**<a id="prop-2-4">性质 - 2-4</a>** 对拟阵 $M=(E,\mathcal{I})$，

1. $\forall X\subseteq E,x\in\operatorname{cl}(X)$，$\operatorname{cl}(X)=\operatorname{cl}(X\cup\{x\})$
2. $\forall A\subseteq E$，令 $X$ 为 $A$ 的极大独立子集，则 $\operatorname{cl}(X)=\operatorname{cl}(A)$
   1. （3 的推论）$\forall X,Y\subseteq E$，$r(X)=r(Y)\implies\operatorname{cl}(X)=\operatorname{cl}(Y)$
   2. （3 的推论）$\forall X\subseteq E$，$r(X)=r(\operatorname{cl}(X))$
3. $\forall x\in E,X\subseteq E$，$x\in\operatorname{cl}(X)$ 当且仅当 $x\in X$ 或存在圈 $C$ 使得 $C\setminus X=\{x\}$
4. 算子 $\operatorname{cl}:2^E\to 2^E$ 是闭包算子当且仅当以下诸款成立：
   1. $\forall X\subseteq E$，$X\subseteq\operatorname{cl}(X)$
   2. $\forall X\subseteq Y\subseteq E$，$\operatorname{cl}(X)\subseteq\operatorname{cl}(Y)$
   3. $\forall X\subseteq E$，$\operatorname{cl}(X)=\operatorname{cl}(\operatorname{cl}(X))$
   4. $\forall a,b\in E,X\subseteq E$，$a\in\operatorname{cl}(X\cup\{b\})\setminus\operatorname{cl}(X)\implies b\in\operatorname{cl}(X\cup\{a\})\setminus\operatorname{cl}(X)$（Mac Lane–Steinitz 交换性，Mac Lane–Steinitz exchange property）

{% endnote %}

不难发现闭包和线性空间中的闭包对应。

## 例子

### 均匀拟阵

{% note info no-icon %}

**<a id="def-3-1">定义 - 3-1</a>** 对有限集合 $E$ 和自然数 $k$，定义 $\mathcal{I}$ 为 $E$ 中所有满足 $|A|\leq k$ 的子集 $A$ 构成的集族，则称拟阵 $(E,\mathcal{I})$ 为**均匀拟阵**（uniform matroid），其秩为 $k$，记含 $n$ 个元素且秩为 $k$ 的均匀拟阵为 $U_{k,n}$

{% endnote %}

### 线性拟阵/向量拟阵

{% note info no-icon %}

**<a id="def-3-2">定义 - 3-2</a>** 对线性空间 $V$ 的有限子集 $E$，定义 $\mathcal{I}$ 为 $E$ 中所有线性无关子集构成的子集族，则称拟阵 $(E,\mathcal{I})$ 为**线性拟阵**（linear matroid）/**向量拟阵**（vector matroid）

{% endnote %}

### 图拟阵

{% note info no-icon %}

**<a id="def-3-3">定义 - 3-3</a>** 对有限图 $G=\langle V,E\rangle$，定义 $\mathcal{I}$ 为 $E$ 的某些子集构成的子集族，这些子集满足对任意 $A\subseteq E$，$A$ 在 $\mathcal{I}$ 中当且仅当 $A$ 无环，则称拟阵 $(E,\mathcal{I})$ 为**图拟阵**（graphic matroid）

若图 $G$ 连通，则其图拟阵的基是生成树，圈是简单环。

{% endnote %}

### 代数拟阵

{% note info no-icon %}

**<a id="def-3-4">定义 - 3-4</a>** 对域 K$ 和其子域 $F$，令 $E\subset K$，定义 $\mathcal{I}$ 为 $E$ 的某些子集构成的子集族，这些子集满足对任意 $A\subseteq E$，$A$ 在 $\mathcal{I}$ 中当且仅当扩域 $F(A)$ 的超越次数等于 $|A|$，则称拟阵 $(E,\mathcal{I})$ 为**代数拟阵**（algebraic matroid）

{% endnote %}

### 划分拟阵

## 运算

### 对偶拟阵

### 拟阵的和

### 拟阵的并

## 相关算法

### 求拟阵的并

### 求拟阵的交

## 应用

### Kruskal 算法的正确性证明

## 例题

- [洛谷 P3974 [TJOI2015]组合数学](https://www.luogu.com.cn/problem/P3974) -> {% post_link luogu-p3974 题解 %}

## 参考文献与链接

- Introduction to Graph Theory (5th Edition) : Wilson, Robin J.
- [Matroid - Wikipedia](https://en.wikipedia.org/wiki/Matroid)
- [\[Tutorial\] Matroid intersection in simple words - Codeforces](https://codeforces.com/blog/entry/69287)
- [从拟阵基础到 Shannon 开关游戏 - zghtyarecrenj 的博客 - 洛谷博客](https://www.luogu.com.cn/blog/zght/matroid)
