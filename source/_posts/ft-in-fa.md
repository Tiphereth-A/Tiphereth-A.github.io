---
title: 科普 - 更高更妙视角下的Fourier变换
date: 2022-09-03 04:00:27
categories:
  - 科普
  - 数学
tags:
  - 数学
  - 科普
  - 代数
  - 拓扑
  - 高等代数
  - 泛函分析
  - Fourier变换
  - Fourier逆变换
  - Iverson括号
  - 空间
  - 线性空间
  - 内积
  - 范数
  - 双线性函数
  - 共轭双线性函数
  - 内积空间
  - 赋范线性空间
  - Banach空间
  - Hilbert空间
  - 线性基
  - Hamel基
  - Schauder基
  - Hilbert基
  - Fourier系数
  - 正交补
  - 正交集
  - 正交规范集
  - Taylor公式
  - Jordan-von Neumann定理
---

从泛函分析的视角重新认识 Fourier 变换

<!-- more -->

## 引入

我们先来回顾一下高中讲的内积:

!["二维空间"下的内积](2d-ortho.svg)

如图, 向量 $\vec u$, $\vec v$ 的内积为 $\vec v$ 的模长乘 $\vec u$ 在 $\vec v$ 上投影的模长, 即

$$(\vec u,\vec v)=|\vec u||\vec v|\cos\alpha$$

相信大家对此再熟悉不过了

高中阶段的二维空间的横纵轴似乎永远是垂直的, 那如果横纵轴不垂直, 内积会怎样呢?

![横纵轴不垂直的"二维空间"](2d-general.svg)

实际上, 内积的计算方法并没有改变, 只不过此时 $\vec u$ 在 $\vec v$ 上投影的模长变成了下图的 $\vec x$, 从而答案变为

$$(\vec u,\vec v)=|\vec x||\vec v|$$

![横纵轴不垂直的"二维空间"下的内积](2d-general-ans.svg)

经过一些简单的计算, 不难得出

$$\vec x=(\cos\alpha-\sin\alpha\cot\beta)\vec v$$

最终

$$(\vec u,\vec v)=|\vec u||\vec v|(\cos\alpha-\sin\alpha\cot\beta)$$

我们注意到这个内积的形式要比横纵轴垂直时的内积复杂许多

## 什么是"空间"

### 引入

你可能觉得横纵轴不垂直的二维空间是一个非常奇怪的东西, 那接下来请思考一个问题: 什么是"空间"? 或者换一个问法: "空间"是由什么构成的?

让我们从大家最熟悉的三维空间出发, 先罗列一些三维空间的性质

- 一个三维空间里有无数的三维向量, 每个向量都可以用一个三元元组 $(x,y,z)$ 表示
- 三维空间里的向量之间有若干种运算, 如向量的加法

在现代数学的观点中, 空间是具有某些**结构**的**集合**, 在本篇文章中, "结构"可以简单理解成集合上的运算

回到上面提到的"三维空间"[^1], 此时我们可以给"三维空间"下一个定义:

[^1]: 准确来说三维实 Euclidean 空间, 其是一种三维实线性空间, 线性空间的定义参见 {% post_link linear-space %}

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** "三维空间"定义为元组 $(V,\R,+,\cdot)$, 其中

- $V:=\{(x,y,z)|x,y,z\in\R\}$
- $+$ 为加法, 满足

  $$+:V\times V\to V;((x_1,y_1,z_1),(x_2,y_2,z_2))\mapsto (x_1+x_2,y_1+y_2,z_1+z_2)$$

- $\cdot$ 为数乘, 满足

  $$\cdot:\R\times V\to V;(k,(x,y,z))\mapsto (kx,ky,kz)$$

在不引起歧义的情况下简记为 $V$

另外, 我们还需补充一些定义:

- 基向量: $\vec e_1,\vec e_2,\vec e_3\in V$, 若 $a\vec e_1+b\vec e_2+c\vec e_3=\vec 0\iff a=b=c=0$, 则称 $\vec e_1,\vec e_2,\vec e_3$ 为一组基向量, 简称一组**基**
- 内积: $\vec a=(x_1,y_1,z_1)\in V,\vec b=(x_2,y_2,z_2)\in V$, 定义其内积 $(\vec a,\vec b)$ 为 $x_1x_2+y_1y_2+z_1z_2$
- 模长(范数): $\vec a\in V$, 定义其模长(范数) $|\vec a|$ 为 $\sqrt{(\vec a,\vec a)}$
- 角度: $\vec a,\vec b\in V$, 定义 $\vec a$ 到 $\vec b$ 的夹角 $\lang\vec a,\vec b\rang$ 为 $\arccos\frac{(\vec a,\vec b)}{|\vec a||\vec b|}$

注意: 这里我们是用**内积**去定义**范数**和**角度**, 因为有的空间中可以定义内积, 但不可以定义范数和角度

{% endnote %}

### 正交

接下来我们讨论一下"垂直"这一概念

实际上, 在我们定义了角度之后, "垂直" 自然也被定义了, 但是并不是所有空间都能如此顺利地定义一个角度出来, 而 "垂直" 似乎可以在不定义角度的前提下定义 (因为 "垂直" 只是要求角度为一个特定的值, 这启发我们可以尝试不用角度定义 "垂直", 而是将 "垂直 = $90\degree$" 视作 "垂直" 的性质)

还是回到我们熟悉的三维空间中, 基向量的选取方式很多, 但是有一类基向量非常特殊, 它们有两条额外的性质:

- 模长为 $1$
- 基向量之间两两垂直

用内积表示即为

$$(\vec e_i,\vec e_j)=[i=j]$$

其中 $[]$ 为 Iverson 括号

我们称满足上述性质的基为 **单位正交基**

"单位" 一词容易理解, 即 $(\vec a,\vec a)=1$

若 $(\vec a,\vec b)=0$, 则称两向量 **正交**, 记作 $\vec a\perp\vec b$

不难发现, 若两向量正交, 则按角度的定义, 两向量的角度为 $90\degree$, 这样我们的目的便达成了

### 结语

可能你会觉得上面的内容来得有些奇怪, 但接下来我们便可以看到这样做的好处了

比如我们在这个定义下我们可以很容易地定义并研究难以想象的高维空间

又如空间的基础是集合和运算, 而集合完全可以不是实数集, 我们可以在很多"奇奇怪怪"的集合上建立空间, 比如:

- 矩阵 $\R^{m\times n}$ 组成的集合与矩阵的加法和数乘构成线性空间
- 区间 $[a,b]$ 上的全体连续函数组成的集合 (记作 $C[a,b]$) 与函数的加法和数乘构成线性空间

## 函数与空间

以下内容默认线性空间 $(V,\Bbb{P},+,\cdot)$ 中的数域 $\Bbb{P}$ 只能是实数域 $\R$ 或复数域 $\Complex$

### 内积与范数

接下来我们讨论一类函数组成的集合, 看看它上面的空间会是什么样的

在继续之前我们需要对内积和范数下严格的定义

{% note info no-icon %}

**<a id="def-2-1">定义 - 2-1</a>** (双线性函数) 若线性空间 $(V,\Bbb{P},+,\cdot)$ 上的函数

$$f:V\times V\to\Bbb{P}$$

满足

- $f(\alpha_1x_1+\alpha_2x_2,y)=\alpha_1 f(x_1,y)+\alpha_2 f(x_2,y)$
- $f(x,\alpha_1y_1+\alpha_2y_2)=\alpha_1 f(x,y_1)+\alpha_2 f(x,y_2)$

则称其是一个 **双线性函数**

{% endnote %}

{% note info no-icon %}

**<a id="def-2-2">定义 - 2-2</a>** (共轭双线性函数) 若线性空间 $(V,\Bbb{P},+,\cdot)$ 上的函数

$$f:V\times V\to\Bbb{P}$$

满足

- $f(\alpha_1x_1+\alpha_2x_2,y)=\alpha_1 f(x_1,y)+\alpha_2 f(x_2,y)$
- $f(x,\alpha_1y_1+\alpha_2y_2)=\overline{\alpha_1}f(x,y_1)+\overline{\alpha_2}f(x,y_2)$

则称其是一个 **共轭双线性函数**

{% endnote %}

{% note info no-icon %}

**<a id="def-2-3">定义 - 2-3</a>** (内积) 若线性空间 $(V,\Bbb{P},+,\cdot)$ 上的共轭双线性函数

$$(\cdot,\cdot):V\times V\to\Bbb{P}$$

满足

- (正定性) $(x,x)\geq 0,~\forall x\in V$, $(x,x)=0\iff x=\vec 0$
- (共轭对称性) $(x,y)=\overline{(y,x)},~\forall x,y\in V$

  > 实际上本条要求是多余的
  >
  > 若 $q$ 是 $(\cdot,\cdot)$ 诱导的二次型, 则 $q(x)\in\R,~\forall x\in V\iff(x,y)=\overline{(y,x)},~\forall x,y\in V$

则称其是一个 **内积**, 有内积的线性空间称为 **内积空间**

{% endnote %}

{% note info no-icon %}

**<a id="def-2-4">定义 - 2-4</a>** (范数/模) 若线性空间 $(V,\Bbb{P},+,\cdot)$ 上的函数 $\lVert\cdot\rVert:V\to\R$ 满足:

- (正定性) $\lVert x\rVert\geq 0,~\forall x\in V$, $\lVert x\rVert=0\iff x=\vec 0$
- (齐次性) $\lVert ax\rVert=|a|\lVert x\rVert,~\forall x\in V,\forall a\in\Bbb{P}$
- (三角不等式) $\lVert x+y\rVert\leq\lVert x\rVert+\lVert y\rVert,~\forall x,y\in V$

则称其是一个 **范数**, 有范数的线性空间称为 **赋范线性空间**

{% endnote %}

不难发现若线性空间 $(V,\Bbb{P},+,\cdot)$ 上有内积 $(\cdot,\cdot)$, 则 $\lVert x\rVert:=(x,x)^{\frac{1}{2}}$ 是一个范数

而若想在赋范线性空间上引入内积, 则需要如下定理

{% note success no-icon %}

**<a id="th-2-1">定理 - 2-1</a>** (Jordan-von Neumann 定理) 在完备的赋范线性空间 $(V,\lVert\cdot\rVert)$ 中, 若可在 $V$ 上引入内积 $(\cdot,\cdot)$ 满足对任意 $x\in V$ 均有 $(x,x)^{\frac{1}{2}}=\lVert x\rVert$, 范数 $\lVert\cdot\rVert$ 必须且仅须满
足如下的平行四边形等式:

$$\lVert x+y\rVert^2+\lVert x-y\rVert^2=2(\lVert x\rVert^2+\lVert y\rVert^2),~\forall x,y\in V$$

> 完备的赋范线性空间即 Banach 空间, 为简化理解, 本篇文章不介绍完备性的概念, 本文章中保证提到的所有具体的内积空间和赋范线性空间都是完备的. 另外, 完备的内积空间也叫 Hilbert 空间

<details open>
<summary>证明</summary>

必要性显然, 充分性可验证

$$
(x,y)=\begin{cases}
  \frac{1}{4}\left(\lVert x+y\rVert^2-\lVert x-y\rVert^2\right),&\Bbb{P}=\R\\
  \frac{1}{4}\left(\lVert x+y\rVert^2-\lVert x-y\rVert^2+i\lVert x+iy\rVert^2-i\lVert x-iy\rVert^2\right),&\Bbb{P}=\Complex
\end{cases}
$$

具体过程略

</details>

{% endnote %}

### 再探基与正交

这里我们将基的定义严格化

{% note info no-icon %}

**<a id="def-2-5">定义 - 2-5</a>** 在线性空间 $V$ 中, 若集合 $B:=\{\vec b_1,\vec b_2,...\}\subseteq V\setminus\{\vec 0\}$ 满足

- $\forall v\in V,\exist_1 \alpha_1,\alpha_2,... \in\Bbb{P},~s.t.~\sum_{i}\alpha_i\vec b_i=v$

则称 $B$ 为 $V$ 的一组 **线性基**/**Hamel 基**, $B$ 的大小(势)称为 $V$ 的 **维度**

{% endnote %}

另外, 我们补充一些与正交相关的概念

{% note info no-icon %}

**<a id="def-2-6">定义 - 2-6</a>** 对于内积空间 $B$

- 令 $M\subseteq B$, 若 $x\in B$ 满足 $x\perp m,\forall m\in M$, 则称 $x$ 与 $M$ 正交, 记作 $x\perp M$
- 令 $M\subseteq B$, 称
  $$\{x\in B|x\perp M\}$$
  为 $M$ 的 **正交补**, 记作 $M^{\perp}$
- 令 $M=\{m_\alpha\}\subseteq B\setminus\{0\}$, 若
  $$m_\alpha\perp m_\beta,\forall \alpha\ne\beta$$

  则称 $M$ 为 **正交集**

  若 $M^{\perp}=\{0\}$, 则称其为完备的

  若 $\lVert e_\alpha\rVert=1,~\forall e_\alpha\in M$, 则称其为 **正交规范集**

{% endnote %}

进而, 我们可以定义 Hilbert 基

{% note info no-icon %}

**<a id="def-2-7">定义 - 2-7</a>** (Hilbert 基) 对于内积空间 $B$, 取其中的一个正交规范集 $M=\{m_\alpha\}$, 若 $\forall x\in B$ 都有如下表示:

$$x=\sum_{\alpha}(x,m_\alpha)m_\alpha$$

则称 $M$ 为 **Hilbert 基**, 称 $\{(x,m_\alpha)|m_\alpha\in M\}$ 为 **Fourier 系数**

{% endnote %}

### 一类函数构成的空间

接下来让我们进入正题

考虑函数 $u:[0,2\pi]\to\Complex_{\infty}$ 我们要求 $|u(x)|^2$ 在 $[0,2\pi]$ 上可积, 令 $u$ 组成的集合为 $L^2([0,2\pi];\Complex)$

在 $L^2([0,2\pi];\Complex)$ 上定义内积

$$(u,v):=\int_0^{2\pi}u(x)\overline{v(x)}\mathrm{d}x$$

定义范数

$$\lVert u\rVert:=(u,u)^{\frac{1}{2}}$$

则其构成一个完备的赋范线性空间 (Hilbert 空间)

我们考虑这个空间的基, 由 Taylor 公式,

$$\{x^i:i\in\N\}$$

是一个基, 但不是 Hilbert 基, 令其为 $B_p$

而

$$\{e^{ikx}|k\in\N\}$$

是一个 Hilbert 基, 令其为 $B_f$

## Fourier 变换

对于任意两个 $L^2([0,2\pi];\Complex)$ 中的函数 $u,v$, 我们考虑其在$B_p$ 和 $B_f$ 的系数

设
$$u(x)=\sum_{k=0}^{\infty}\xi_kx^k=\sum_{k=0}^{\infty}\psi_k e^{ikx}$$
$$v(x)=\sum_{k=0}^{\infty}\rho_kx^k=\sum_{k=0}^{\infty}\mu_k e^{ikx}$$

之后我们考虑 $uv$ 在$B_p$ 和 $B_f$ 的系数, 可以得到

$$u(x)v(x)=\sum_{k=0}^{\infty}\left(\textcolor{3700cc}{\sum_{j=0}^k\xi_j\rho_{k-j}}\right)x^k=\sum_{k=0}^{\infty}\textcolor{a50040}{\psi_k\mu_k} e^{ikx}$$

> $\psi_k=(u(x),e^{ikx}), \mu_k=(v(x),e^{ikx})\implies \psi_k\mu_k=(u(x)v(x),e^{ikx})$ (按 $B_p$ 下的系数拆分 $u,v$ 再合并)

我们注意到计算 <font color="3700cc">靛蓝色</font> 部分的时间复杂度为 $O(k)$, 而计算 <font color="a50040">枣红色</font> 部分的时间复杂度为 $O(1)$

联系我们在 [引入](#引入) 中提到的两个坐标系下内积的差异, 我们很容易便可以发现正交基的巨大优势

回到本节, 将 $B_p$ 下的系数变为 $B_f$ 下的系数即为 **Fourier 变换**, 反之即为 **Fourier 逆变换**

---

## 参考资料

- 高等代数教程. 郭聿琦, 岑嘉评, 王正攀.
- 泛函分析. 张恭庆, 林源渠.
