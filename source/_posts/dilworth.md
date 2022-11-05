---
title: "笔记 - Dilworth 定理 & Mirsky 定理"
categories:
  - 笔记
  - 数学
tags:
  - 算法竞赛
  - 笔记
  - 数学
  - 代数
  - 抽象代数
  - 偏序
  - 偏序集
  - 全序
  - 全序集
  - 良序
  - 良序集
  - 链
  - 反链
  - Hasse图
  - Dilworth定理
  - Mirsky定理
  - Erdős-Szekeres定理
date: 2022-10-31 22:18:28
---

Dilworth 定理描述了偏序集的独立集个数和最大全序子集的关系

<!-- more -->

## 前置知识

### 偏序集

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** (偏序集) 若集合 $S$ 上有一关系 $\preceq$ 满足:

1. (自反性): $a\preceq a$, $\forall a\in S$
1. (反对称性): $a\preceq b \land b\preceq a\implies a=b$, $\forall a,b\in S$
1. (传递性): $a\preceq b \land b\preceq c\implies a\preceq c$, $\forall a,b,c\in S$

则称 $S$ 是**偏序集**, $\preceq$ 为其上一偏序

若两元素间具有偏序, 则称这两个元素是可比的

进一步, 若

- 对 $S$ 的任意有**有限非空子集** $T$ 均有最小元, 则称 $S$ 为**全序集**, 对应的偏序也称为全序

  > $T$ 有最小元等价于 $T$ 中任意两个元素均可比

- 对 $S$ 的任意**非空子集** $T$ 均有最小元, 则称 $S$ 为**良序集**, 对应的偏序也称为良序

{% endnote %}

因为偏序是 $\leq$ 的抽象, 所以有时候方便起见也会将偏序记作 $\leq$

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 对偏序集 $S$ 和其上的偏序 $\preceq$

- 称其上一全序子集 $T$ 为**链**
- 若其上一子集 $T$ 中任意两个元素均不可比, 则称 $T$ 为**反链**

{% endnote %}

### Hasse 图

Hasse 图是偏序集的一种直观表示方式

{% note info no-icon %}

**<a id="def-1-3">定义 - 1-3</a>** (Hasse 图) 对偏序集 $S$ 和其上的偏序 $\preceq$, 其对应的 Hasse 图定义为满足如下条件的有向图 $G=(V,E)$:

- $V=S$
- $(a,b)\in E$ 当且仅当 $a\preceq b$ 且 $\nexists c\in S~s.t.~a\preceq c\preceq b$

{% endnote %}

比如对集合 $S=\{\varnothing,\{x\},\{y\},\{z\},\{x,y\},\{y,z\},\{x,z\},\{x,y,z\}\}$ 和其上的偏序 $\subseteq$, 其对应的 Hasse 图如下:

![](hasse.svg)

## Dilworth 定理与 Mirsky 定理

Dilworth 定理和 Mirsky 定理的形式"对偶", 让我们先从比较容易证明的 Mirsky 定理开始

### Mirsky 定理

{% note success no-icon %}

**<a id="th-2-1">定理 - 2-1</a>** (Mirsky 定理) 对有限偏序集 $S$ 和其上的偏序 $\preceq$, 其上的**最长链长度**等于最小的**反链覆盖数**

> 对一个集合 $S$, 令 $\Lambda$ 为 $S$ 的一个覆盖 (即满足 $\bigcup_{\lambda\in\Lambda}\lambda=S$ 的集合), 这里的覆盖数指的是 $|\Lambda|$

<details open>
<summary>证明</summary>

设 $S$ 的最长链长度为 $d$, 则由定义, 最小反链覆盖数显然至少为 $d$

令 $f(s)$ 为以 $s$ 为最小元的最长链长度, 注意到若 $f(s)=f(t)$ 则 $s$ 与 $t$ 不可比, 则 $\forall n\in\N^+$, $f^{-1}(n)$ 是一条反链

进而不难得出 $f^{-1}(1),\dots,f^{-1}(d)$ 是一个反链覆盖, 从而最小反链覆盖数至多为 $d$

</details>

{% endnote %}

这个定理可以结合 Hasse 图直观理解: 我们可以找到 Hasse 图上的一条最长链, 然后一个最小反链覆盖中的每一条反链都恰好包含一个最长链上的元素

![](mirsky.svg)

### Dilworth 定理

{% note success no-icon %}

**<a id="th-2-2">定理 - 2-2</a>** (Dilworth 定理) 对有限偏序集 $S$ 和其上的偏序 $\preceq$, 其上的**最长反链长度**等于最小的**链覆盖数**

另外, 我们将有限偏序集 $S$ 的最长反链长度称作 $S$ 的宽度

<details open>
<summary>证明</summary>

考虑数学归纳法

当 $|S|\leq 3$ 时, 命题显然成立

假设命题对所有元素个数小于 $|S|$ 的偏序集都成立, 令 $S$ 的最长反链长度为 $d$

若 $|S|$ 中所有元素均不可比, 则命题显然成立

否则在 $S$ 中取一条长度大于 1 的链, 令其中的最小元为 $m$, 最大元为 $M$

若 $T:=S\setminus\{m,M\}$ 中的最长反链长度不超过 $d-1$, 则 $T$ 显然可被 $d-1$ 条链覆盖, 进而 $S$ 可被这 $d-1$ 条链再加上链 $\{m,M\}$ 覆盖, 命题成立

否则说明 $T:=S\setminus\{m,M\}$ 中的最长反链长度也为 $d$, 令这条反链为 $A$

我们考虑如下两个集合:

$$S^+:=\{x\in S:x\geq a,~\exists a\in A\}$$
$$S^-:=\{x\in S:x\leq a,~\exists a\in A\}$$

我们不难发现如下性质:

- $S^+\cup S^-=S$
- $S^+\cap S^-=A$
- $|S^+|<|S|$, $|S^-|<|S|$ (因为 $m\notin S^+$, $M\notin S^-$)

对 $S^+$ 和 $S^-$ 都应用归纳假设, 则这两个集合的最小链覆盖数为 $d$, 且这些链中恰好包含一个 $A$ 中的元素 $a$, 设这些链分别为 $C_a^+$, $C_a^-$

则 $\{C_a:=C_a^-\cup\{a\}\cup C_a^+\}$ 是 $S$ 的一个最小链覆盖, 命题得证

</details>

{% endnote %}

### 应用 - Erdős-Szekeres 定理

{% note success no-icon %}

**<a id="th-2-3">定理 - 2-3</a>** (Erdős-Szekeres 定理) 含至少 $rs+1$ 个元素的实数序列 $\{a_i\}$ 要么有一个长为 $r+1$ 的上升子序列, 要么有一个长为 $s+1$ 的下降子序列

<details open>
<summary>证明</summary>

我们将序列转为偏序集, 其中 $a_i\preceq a_j:=i\leq j\land a_i\leq a_j$

假设该偏序集的宽度不超过 $s+1$, 则由 <a href="#th-2-2">Dilworth 定理</a> 可知该偏序集可以被至多 $s$ 条链覆盖

若这些链的长度都不超过 $r$, 则序列所含元素数至多为 $rs$, 与条件矛盾

</details>

{% endnote %}

## 例题

- 洛谷 [P1020 [NOIP1999 普及组] 导弹拦截](https://www.luogu.com.cn/problem/P1020)
- 洛谷 [P3974 [TJOI2015] 组合数学](https://www.luogu.com.cn/problem/P3974) -> {% post_link luogu-p3974 题解 %}

## 参考资料

- [Dilworth's Theorem | Brilliant Math & Science Wiki](https://brilliant.org/wiki/dilworths-theorem/)
