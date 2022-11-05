---
title: "集合论03 - 映射, 基数/势"
categories:
  - 笔记
  - 数学
  - 集合论
tags:
  - 数学
  - 笔记
  - 集合论
  - 映射
  - 基数/势
  - 特征函数
  - 对等
  - 不动点
  - 关系
  - 等价关系
  - 偏序关系
  - 映射分离定理
  - 分离集
  - Cantor-Bernstein定理
  - 可数集
  - 可列集
  - 无最大基数定理
  - 连续基数
  - 连续统假设
  - 广义连续统假设
  - ZF公理系统
date: 2021-03-27 17:36:32
---

本篇主要介绍映射与基数相关概念

<!-- more -->

## 映射

定义略

映射有如下简单性质

{% note primary no-icon %}

**<a id="pb-1-1">命题 - 1-1</a>**

1. 若 $A_1\subseteq A_2$, 则 $f(A_1)\subseteq f(A_2)$
1. $f\left(\bigcup_{\alpha\in I}A_\alpha\right)=\bigcup_{\alpha\in I}f(A_\alpha)$
1. $f\left(\bigcap_{\alpha\in I}A_\alpha\right)\subseteq\bigcap_{\alpha\in I}f(A_\alpha)$ (**注意**)
1. 若 $B_1\subseteq B_2$, 则 $f^{-1}(B_1)\subseteq f^{-1}(B_2)$
1. $f^{-1}\left(\bigcup_{\alpha\in I}B_\alpha\right)=\bigcup_{\alpha\in I}f^{-1}(B_\alpha)$
1. $f^{-1}\left(\bigcap_{\alpha\in I}B_\alpha\right)=\bigcap_{\alpha\in I}f^{-1}(B_\alpha)$
1. $f^{-1}(B^c)=(f^{-1}(B))^c$

{% endnote %}

### 集合的特征函数

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 对集合 $X$ 的子集 $A$, 令函数 $\chi_A:X\to\{0,1\}$

$$
\chi_A(x)=\begin{cases}
  1,&x\in A\\
  0,&x\in X\setminus A
\end{cases}
$$

称 $\chi_A$ 为定义在 $X$ 上的 $A$ 的**特征函数**

{% endnote %}

不难发现, 集合的特征函数在某种意义上可以代表集合本身, 比如 $A\subseteq B\iff\forall x\in X,\chi_A(x)\leqslant\chi_B(x)$

特征函数有如下简单性质

{% note primary no-icon %}

**<a id="pb-1-2">命题 - 1-2</a>**

1. $\chi_{A\cup B}=\chi_A+\chi_B-\chi_{A\cap B}$
1. $\chi_{A\cap B}=\chi_A\chi_B$
1. $\chi_{A\setminus B}=\chi_A(1-\chi_B)$
1. $\chi_{A\triangle B}=|\chi_A-\chi_B|$

{% endnote %}

### 习题

{% note primary no-icon %}

#### <a id="asm-1-1">题 - 1-1</a>

设 $f:X\to Y$ 为满射, 证明以下命题等价

1. $f$ 是双射
1. $\forall A,B\subseteq X,~f(A\cap B)=f(A)\cap f(B)$
1. $(\forall A,B\subseteq X,A\cap B=\varnothing),~f(A)\cap f(B)=\varnothing$
1. $\forall A\subseteq B\subseteq X,~f(B\setminus A)=f(B)\setminus f(A)$

<details>
<summary><font color='orange'>Proof</font></summary>

1. $\implies$ 2. 显然
2. $\implies$ 3. 显然
3. $\implies$ 4. 注意到 $f(A)\cap f(B\setminus A)=\varnothing$, 故 $f(B\setminus A)=f(B)\setminus f(A)$
4. $\implies$ 1. 反证

   若 $(\exists x_1,x_2\in X,x_1\ne x_2),~f(x_1)=f(x_2)$

   令 $A=\{x_1\},B=\{x_1,x_2\}$, 则 $\{f(x_2)\}=f(B\setminus A)=f(B)\setminus f(A)=\{f(x_1)\}$, 矛盾

</details>

{% endnote %}

{% note primary no-icon %}

#### <a id="asm-1-2">题 - 1-2</a> (单调映射的不动点)

设 $X$ 为一非空集合, $f:\mathscr{P}(X)\to\mathscr{P}(X)$, 若 $(\forall A,B\in\mathscr{P}(X),A\subseteq B),~f(A)\subseteq f(B)$, 则 $\exists T\in\mathscr{P}(X),f(T)=T$

<details>
<summary><font color='orange'>Proof</font></summary>

令
$$T=\bigcup_{A\in\mathscr{P}(X);A\subseteq f(A)}A$$
则
$$f(T)=T$$

一方面, 由 $A\subseteq T$ 知 $A\subseteq f(A)\subseteq f(T)$, 进而
$$T=\bigcup_{A\in\mathscr{P}(X);A\subseteq f(A)}A\subseteq f(T)$$

另一方面, 由 $T\subseteq f(T)$ 知 $f(T)\subseteq f(f(T))$, 进而 $f(T)\subseteq T$

</details>

{% endnote %}

{% note primary no-icon %}

#### <a id="asm-1-3">题 - 1-3</a>

设 $f:X\to Y$, $g:Y\to X$, 若 $\forall x\in X,g(f(x))=x$, 则 $f$ 是单射, $g$ 是满射

<details>
<summary><font color='orange'>Proof</font></summary>

$\forall x\in X,g(f(x))=x\implies\forall x\in X,\exists y=f(x)\in Y,g(y)=x\implies g$ 为满射

又 $(\forall x_1,x_2\in X, f(x_1)=f(x_2)),~x_1=g(f(x_1))=g(f(x_2))=x_2$

故 $f$ 为单射

</details>

{% endnote %}

## 集合的基数/势

在定义集合的基数之前, 我们需要明确集合的对等

### 集合的对等

对于有限集, 我们很容易能比较两集合的大小, 但对于无限集来说, 事情便不是那么容易, 这是因为我们还不清楚如何才能认为两无限集"大小相等"

考虑双射的性质, 一个自然的想法便是: 若两集合间可以建立起一个双射, 则我们认为这两个集合"大小相等"

{% note info no-icon %}

**<a id="def-2-1">定义 - 2-1</a>** 对两集合 $A,B$, 若存在双射 $f:A\to B$, 则称集合 $A,B$ **对等**, 记为 $A\sim B$

{% endnote %}

显然, 集合间的对等是一个等价关系

{% note primary no-icon %}

**<a id="eg-2-1">例 - 2-1</a>** $(\mathbb{N}^+)^2\sim\mathbb{N}^+$, 考虑整数的唯一分解定理, 我们可以取 $f(i,j)=2^{i-1}(2j-1),~i,j\in\mathbb{N}^+$

{% endnote %}

{% note primary no-icon %}

**<a id="eg-2-2">例 - 2-2</a>** $(-1,1)\sim\reals$, 可以取
$$f=\frac{x}{1-x^2},~x\in(-1,1)$$

{% endnote %}

下面介绍一个证明集合对等的重要方法: <a href="#th-2-1">Cantor-Bernstein 定理</a>

{% note danger no-icon %}

**<a id="lm-2-1">引理 - 2-1</a>** (映射分解定理, Banach)

若有 $f:X\to Y$, $g:Y\to X$, 则存在分解
$$X=A\cup A',Y=B\cup B'$$
满足

- $A\cap A'=\varnothing=B\cap B'$
- $f(A)=B$
- $g(B')=A'$

<details open>
<summary><font color='orange'>Proof</font></summary>

我们把 $f(A)=B,Y\setminus B=B',g(B')=A'$ 合起来, 得到
$$A'=g(Y\setminus f(A))$$

而 $A\cap A'=\varnothing\iff A\cap g(Y\setminus f(A))=\varnothing$

所以我们考虑构造 $A$ 使得

- $A\cap g(Y\setminus f(A))=\varnothing$
- $A\cup A'=X$

我们令满足 $E\cap g(Y\setminus f(E))=\varnothing$ 的 $E$ 为**分离集**, 其中 $E\subseteq X$ 且 $Y\setminus f(E)\ne\varnothing$

记所有分离集组成的集合为 $\Gamma$

考虑 $A=\bigcup_{E\in\Gamma}E$, 则

- $A\in\Gamma$, 即 $A$ 为 $\Gamma$ 中的最大元

  $\forall E\in\Gamma$, 由于 $E\subseteq A$, 则
  $$E\cap g(Y\setminus f(E))=\varnothing\implies E\cap g(Y\setminus f(A))=\varnothing\implies A\cap g(Y\setminus f(A))=\varnothing$$

- $A\cup A'=X$

  若 $\exists x_0\in X,~s.t.~x\notin A\cup A'$, 令 $A_0=A\cup\{x_0\}$, 则 $B\subseteq f(A_0),B'\supseteq Y\setminus f(A_0)$, 从而有

  $$g(Y\setminus f(A_0))\subseteq A'\implies A_0\cap g(Y\setminus f(A_0))=\varnothing$$
  这与 $A$ 为 $\Gamma$ 中的最大元矛盾

</details>

{% endnote %}

{% note success no-icon %}

**<a id="th-2-1">定理 - 2-1</a>** (Cantor-Bernstein 定理)

若 $X$ 与 $Y$ 的某个真子集对等, $Y$ 与 $X$ 的某个真子集对等, 则 $X\sim Y$

<details open>
<summary><font color='orange'>Proof (Banach)</font></summary>

题设换句话说就是:

> 若 $\exists f:X\to Y, g:Y\to X$ 为单射, 则 $X\sim Y$

根据 <a href="#lm-2-1">引理 - 2-1</a> 知, 存在分解
$$X=A\cup A',Y=B\cup B'$$
满足

- $A\cap A'=\varnothing=B\cap B'$
- $f(A)=B$
- $g(B')=A'$

令

$$
F(x)=\begin{cases}
  f(x),&x\in A\\
  g^{-1}(x),&x\in A'
\end{cases}
$$

注意到 $f:A\to B,g^{-1}:A'\to B'$ 为双射, 故 $F(x)$ 为双射, 从而 $X\sim Y$

</details>

{% endnote %}

{% note success no-icon %}

**<a id="ifr-2-1">推论 - 2-1</a>** 设集合 $A,B,C$ 满足

$$C\subset B\subset A$$
则 $B\sim C\implies B\sim A$

{% endnote %}

{% note primary no-icon %}

**<a id="eg-2-3">例 - 2-3</a>** $[-1,1]\sim\reals$

注意到
$$(-1,1)\subset[-1,1]\subset\reals$$

由 <a href="#eg-2-2">例 - 2-2</a> 立得 $[-1,1]\sim\reals$

{% endnote %}

### 常见基数

在定义完集合间的对等关系后, 我们终于可以定义一些集合的基数了

#### 自然数集/可列集的基数

{% note info no-icon %}

**<a id="def-2-2">定义 - 2-2</a>** 我们记

$$|\mathbb{N}|=\alef_0$$

其中 $\alef$ 为希伯来字母 Alef, 下标 $0$ 是因为 $\mathbb{N}$ 是基数最小的无限集

{% endnote %}

下面的定理证明了 $\mathbb{N}$ 是基数最小的无限集

{% note success no-icon %}

**<a id="th-2-2">定理 - 2-2</a>** 任一无限集必包含可列子集

<details open>
<summary><font color='orange'>Proof</font></summary>

在无限集 $E$ 中任取一元素 $e_1$, 接着在无限集 $E\setminus\{e_1\}$ 中任取一元素 $e_2$, 一直这样取下去, 便可得到

$$\{e_n\}\subseteq E$$

</details>

{% endnote %}

下面列举几条可列集基数的相关性质 (真命题), 因为可列集和 $\mathbb{N}$ 对等, 故下文一些地方会以 $\mathbb{N}$ 指代可列集

{% note primary no-icon %}

**<a id="pb-2-1">命题 - 2-1</a>** 设 $A$ 为有限集, $B$ 为可列集, 则 $A\cup B$ 为可列集

{% endnote %}

{% note primary no-icon %}

**<a id="pb-2-2">命题 - 2-2</a>**

$$\mathbb{N}^n\sim\mathbb{N}$$

> 只需找 $n$ 个不等素数 $p_1,p_2,\dots,p_n$, 建立映射
>
> $$f:\mathbb{N}^n\to\mathbb{N};(\alpha_0,\alpha_1,\dots,\alpha_n)\mapsto\prod_{i=1}^np_i^{\alpha_i}$$
>
> 即可

{% endnote %}

{% note primary no-icon %}

**<a id="pb-2-3">命题 - 2-3</a>**
$$\bigcup_{n=1}^{\infty}\mathbb{N}^n\sim\mathbb{N}$$

{% endnote %}

{% note primary no-icon %}

**<a id="pb-2-4">命题 - 2-4</a>**

$$|\Bbb{Q}|=|\mathbb{Z}|=|\mathbb{N}|=\alef_0$$

{% endnote %}

{% note primary no-icon %}

**<a id="pb-2-6">命题 - 2-6</a>**
$$|\mathbb{R}|\ne|\mathbb{N}|$$

{% endnote %}

---

{% note info no-icon %}

**<a id="def-2-3">定义 - 2-3</a>**

- 有限集和可列集统称为 **可数集**
- 有限集可称为 **可数有限集**
- 可列集可称为 **可数无限集**

{% endnote %}

下面给出几个例子

{% note primary no-icon %}

**<a id="eg-2-4">例 - 2-4</a>** $\mathbb{R}$ 中互不相交的开区间族为可数集

> 因为任一开区间里均可找到一个有理数

{% endnote %}

{% note primary no-icon %}

**<a id="eg-2-5">例 - 2-5</a>** $\mathbb{R}$ 上单调函数的不连续点集为可数集

> 以单调递增函数 $f(x)$ 为例, 对任意不连续点 $x_i$, 均有
>
> $$f(x_i-0)<f(x_i+0)$$
>
> 则 $x_i$ 对应开区间 $(f(x_i-0),f(x_i+0))$, 显然开区间列 $\{(f(x_i-0),f(x_i+0))\}$ 内的元素两两不交

{% endnote %}

{% note primary no-icon %}

**<a id="eg-2-6">例 - 2-6</a>** 设 $f(x)$ 是定义在 $\mathbb{R}$ 上的实值函数, 则
$$\{x\in\mathbb{R}:\lim_{y\to x}f(y)=+\infty\}$$
是可数集

> 令 $g(x)=\arctan f(x)$, 则原点集变为
> $$\left\{x\in\mathbb{R}:\lim_{y\to x}g(y)=\frac{\pi}{2}\right\}$$

{% endnote %}

{% note primary no-icon %}

**<a id="eg-2-7">例 - 2-7</a>** (无理点连续, 有理点间断的递增函数)

记 $(a,b)_{\Bbb{Q}}=:\{r_n\}$, 取 $\{c_n\}$ 使得

- $c_i>0,~i=1,2,...$
- $\sum_{i=1}^{\infty}c_i<+\infty$

作函数
$$f(x)=\sum_{r_n<x}c_n$$

易知

- $f(x)$ 递增
- $f(x)$ 在 $(a,b)_{\mathbb{R}\setminus\Bbb{Q}}$ 上连续
- $f(x)$ 在 $(a,b)_{\Bbb{Q}}$ 上不连续, 且
  $$f(r_n+0)-f(r_n-0)=c_n,~n=1,2,...$$

{% endnote %}

---

{% note success no-icon %}

**<a id="th-2-3">定理 - 2-3</a>** 设 $E\subset\mathbb{R}$ 为可列集, 则
$$\exists x_0\in\mathbb{R},E\cap(E+x_0)=\varnothing$$

<details open>
<summary><font color='orange'>Proof</font></summary>

若 $x'\in E\cap(E+x_0)$, 则
$$\exists x''\in E,|x'-x''|=x_0$$

即

$$(\forall x_0\in\mathbb{R},\exists x',x''\in E),~x_0=x'-x''$$

该命题显然错误

</details>

{% endnote %}

{% note success no-icon %}

**<a id="th-2-4">定理 - 2-4</a>** 若 $A$ 是基数为 $\alpha$ 的无限集, $B$ 是可数集, 则 $A\cup B$ 的基数仍为 $\alpha$

<details open>
<summary><font color='orange'>Proof</font></summary>

不妨设

- $B=\{b_n\}$
- $A\cap B=\varnothing$
- $A=A_1\cup A_2$, $A_1\cap A_2=\varnothing$
- $A_1=\{a_n\}$

建立映射 $f:A\cup B\to A$ 满足

- $f(a_i)=a_{2i},~\forall a_i\in A_1$
- $f(b_i)=a_{2i-1},~\forall b_i\in B_1$
- $f(x)=x,~\forall x\in A_2$

显然 $f$ 为双射

</details>

{% endnote %}

{% note success no-icon %}

**<a id="th-2-5">定理 - 2-5</a>** $A$ 为无限集的充要条件为 $A$ 与其某真子集对等

<details open>
<summary><font color='orange'>Proof</font></summary>

充分性显然

必要性: 任取 $A$ 中的非空有限子集 $B$, 由 <a href="#th-2-4">定理 - 2-4</a> 知
$$A\sim(A\setminus B)$$

</details>

{% endnote %}

{% note primary no-icon %}

**<a id="eg-2-8">例 - 2-8</a>** $(a,b)$ 上的凸函数 $f(x)$ 所有不可导点构成的点集是可数集

<details>
<summary><font color='orange'>Proof</font></summary>

由 $f(x)$ 是 $(a,b)$ 上的凸函数知

$$\forall x\in(x_1,x_2)\subseteq(a,b),~f(x)\leqslant\frac{(x_2-x)f(x_1)-(x-x_1)f(x_2)}{x_2-x_1}$$

即

$$\frac{f(x)-f(x_1)}{x-x_1}\leqslant\frac{f(x_2)-f(x)}{x_2-x}$$

又

$$\forall x'\in(x,x_2),~\frac{f(x')-f(x)}{x'-x}\leqslant\frac{f(x_2)-f(x)}{x_2-x}$$

故

$$\lim_{x'\to x^+}\frac{f(x')-f(x)}{x'-x}=f'_+(x)<+\infty$$

同理, $-\infty<f'_-(x)$, 进而

$$-\infty<f'_-(x)\leqslant f'_+(x)<+\infty$$

由 <a href="#eg-2-4">例 - 2-4</a> 知命题成立

</details>

{% endnote %}

#### 实数集的基数

首先, 我们考虑非空集合和其幂集是否对等

在有限集下显然是否定的, 那无限集呢?

我们有如下定理

{% note success no-icon %}

**<a id="th-2-6">定理 - 2-6</a>** (无最大基数定理) 若 $A$ 为非空集合, 则 $|A|<|\mathscr{P}(A)|$

进一步, 我们记 $|\mathscr{P}(A)|=2^{|A|}$, 则

$$|A|<2^{|A|}$$

<details open>
<summary><font color='orange'>Proof</font></summary>

假设 $A\sim\mathscr{P}(A)$, 则存在双射 $f:A\to\mathscr{P}(A)$

取集合
$$B=\{x\in A:x\notin f(x)\}$$

则
$$\exists y\in A,~s.t.~f(y)=B\in\mathscr{P}(A)$$

而

- 若 $y\in B$, 则 $y\notin f(y)=B$
- 若 $y\notin B=f(y)$, 则 $y\in B$

这与 $f$ 是双射矛盾, 实际上, $f$ 最多只能是满射, 从而 $|A|<|\mathscr{P}(A)|$

</details>

{% endnote %}

我们可以自然地得出一个推论

{% note success no-icon %}

**<a id="ifr-2-2">推论 - 2-2</a>** 对非空集合 $E$, $\mathscr{P}(E)$ 不是可列集

{% endnote %}

---

在 <a href="#pb-2-6">命题 - 2-6</a> 中, 我们提到实数集和自然数集不对等, 实际上

$$|\reals|=2^{|\mathbb{N}|}=2^{\alef_0}$$

我们会在下一篇中给出证明

进而

{% note info no-icon %}

**<a id="def-2-4">定义 - 2-4</a>** 我们令 $|\reals|=c$, 称 $c$ 为**连续基数**

{% endnote %}

我们对无限集基数补充一个定义

{% note info no-icon %}

**<a id="def-2-5">定义 - 2-5</a>** 记 $\alef_n$ 为大于 $\alef_{n-1}$ 的最小基数

{% endnote %}

接下来我们自然就有了一个问题: $c=2^{\alef_0}\xlongequal{?}\alef_1$

恭喜, 我们现在发现了一个知名问题! 这正是 Hilbert 列出的 23 个数学问题[^1]之首: **连续统假设**问题

{% note primary no-icon %}

**<a id="pb-2-7">命题 - 2-7</a>** (连续统假设)
$$c=\alef_1$$

{% endnote %}

连续统假设问题即为该假设是否成立

在 Zemelo-Frankl 集合论公理系统下, 前人已经证明了该假设具有**相容性** (不能证明该假设不真, Godel, 1940) 和**独立性** (不能用其他公理证明该假设, Cohen, 1963)

之后便又有了一个问题: 是否存在一个公理系统, 使得连续统假设的真伪性确定

此处不做展开, 有兴趣的读者可以自行查阅相关资料

另外, 我们还有广义的连续统假设

{% note primary no-icon %}

**<a id="pb-2-8">命题 - 2-8</a>** (广义连续统假设)
$$\alef_i=2^{\alef_{i-1}},~\forall i\in\mathbb{N}^+$$

{% endnote %}

### 习题

{% note primary no-icon %}

#### <a id="asm-2-1">题 - 2-1</a>

若 $A\subseteq B$ 且 $A\sim(A\cup C)$, 证明 $B\sim(B\cup C)$

<details>
<summary><font color='orange'>Proof</font></summary>

由题设知, 存在双射 $f:A\to A\cup C$

对该映射补充定义 $f(x)=x,~\forall x\in B\setminus A$

此时该映射为 $B\to B\cup C$ 的双射

故 $B\sim (B\cup C)$

</details>

{% endnote %}

{% note primary no-icon %}

#### <a id="asm-2-2">题 - 2-2</a>

设 $f(x)$ 在 $(a,b)$ 可导, 且 $(a,b)\setminus\{x:f'(x)=0\}$ 为可数集, 证明 $f(x)$ 为常数

<details>
<summary><font color='orange'>Proof</font></summary>

令

- $(a,b)\setminus\{x:f'(x)=0\}=A=\{a_n\}$
- $a<a_1<a_2<\cdots<b$
- $(a,b)\setminus A=B$
- $A_i=(a_i,a_{i+1})$, 则 $B=\bigcup A_i$

显然, $\forall x\in A_i,f(x)=c_i$ 为常数

而由 $f(x)$ 在 $(a,b)$ 连续知 $f_+(a_i)=f_-(a_i)$

故 $c_i=c_{i+1},~i=1,2,...$, 命题得证

</details>

{% endnote %}

{% note primary no-icon %}

#### <a id="asm-2-3">题 - 2-3</a>

设无限集 $E\subseteq(0,1)$, 若在 $E$ 中任取不同的数组成的无穷正项级数总是收敛的, 证明 $E$ 是可数集

<details>
<summary><font color='orange'>Proof</font></summary>

取 $E_n=\{x\in E:x\geqslant\frac{1}{n}\},~n=2,3,...$, 则 $E=\bigcup_{n=2}^{\infty}E_n$

显然 $E_n$ 为可数集, 否则可以取出数列 $\{a_n\}$ 使得级数 $\sum a_n\geqslant\sum\frac{1}{n}=+\infty$

故命题得证

</details>

{% endnote %}

{% note primary no-icon %}

#### <a id="asm-2-4">题 - 2-4</a>

设 不可数集 $E\subseteq\mathbb{R}^2$, 证明 $\exists x_0\in E,~s.t.~\forall B(x_0,r),E\cap B(x_0,r)$ 不可数

其中 $B(x_0,r)$ 指圆心为 $x_0$, 半径为 $r$ 的开球

<details>
<summary><font color='orange'>Proof</font></summary>

若 $\exists x_0\in E,~s.t.~\forall B(x_0,r),E\cap B(x_0,r)$ 可数

则取正有理数半径 $r_x$, 有
$$E=\bigcup_{r_x\in\Bbb{Q}^+}(E\cap B(x_0,r_x))$$

该式说明 $E$ 可数, 与题设矛盾

</details>

{% endnote %}

## 常见数系的基数

| 数系           | 基数      | 数系           | 基数 |
| -------------- | --------- | -------------- | ---- |
| $\mathbb{N}$   | $\alef_0$ | $\mathbb{R}$   | $c$  |
| $\mathbb{Z}$   | $\alef_0$ | $\mathbb{R}^n$ | $c$  |
| $\Bbb{Q}$      | $\alef_0$ | $\mathbb{C}$   | $c$  |
| $\mathbb{N}^n$ | $\alef_0$ | 超越数集       | $c$  |
| 代数数集       | $\alef_0$ |                |

[^1]: <https://mathcs.clarku.edu/~djoyce/hilbert/problems.html>
