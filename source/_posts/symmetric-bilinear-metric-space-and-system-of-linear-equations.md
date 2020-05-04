---
title: 笔记 - 对称双线性度量空间与线性方程组
categories:
  - 笔记
  - 数学
  - 高等代数
tags:
  - 数学
  - 笔记
  - 代数
  - 高等代数
  - 线性空间
  - 度量空间
  - 线性函数
  - 双线性函数
  - 对称双线性度量空间
  - 线性方程组
  - Euclid空间
  - 最小二乘法
date: 2020-06-20 16:08:42
---

线性函数, 双线性函数, Euclid 空间等

<!-- more -->

## 线性空间上的线性和双线性函数

顾名思义, 线性函数就是具有线性的函数, 双线性函数就是具有双重线性的函数

因为这两个概念有许多相通之处, 故选用如下方式展示

### 基本定义

{% tabs define-1-base,1 %}

<!-- tab 线性函数 -->

> **定义** 线性函数
>
> 对映射$f:V\to\mathbb{P}$, 满足$(\forall\alpha,\beta\in V,k,l\in\mathbb{P}),~f(k\alpha+l\beta)=kf(\alpha)+lf(\beta)$

例如矩阵的迹$\operatorname{tr}A$

<!-- endtab -->
<!-- tab 双线性函数 -->

> **定义** 双线性函数
>
> 对映射$f:V\times V\to\mathbb{P}$, 满足
>
> - $(\forall\alpha,\beta,\gamma\in V,k,l\in\mathbb{P}),~f(k\alpha+l\beta,\gamma)=kf(\alpha,\gamma)+lf(\beta,\gamma)$
> - $(\forall\alpha,\beta,\gamma\in V,k,l\in\mathbb{P}),~f(\gamma,k\alpha+l\beta)=kf(\gamma,\alpha)+lf(\gamma,\beta)$

<!-- endtab -->

{% endtabs %}

### 表示向量/表示矩阵

{% tabs define-1-representation,1 %}

<!-- tab 线性函数 -->

> **定义** 表示向量
>
> 令$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$为$V$的一组基, 称
> $$(\def\enum#1{f(\epsilon_{ #1})}\enum{1},\enum{2},...,\enum{n})$$
> 为$f$在$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的**表示向量**

我们有如下定理

#### <a href="#end-t-1-1-1" id="t-1-1-1">定理 - 1-1-1</a>

$\eta:L(V,\mathbb{P})\to\mathbb{P}^n;~f\mapsto(\def\enum#1{f(\epsilon_{ #1})}\enum{1},\enum{2},...,\enum{n})$为双射

即所有线性函数的集合$L(V,\mathbb{P})$与$\mathbb{P}^n$同构

<a href="#t-1-1-1" id="end-t-1-1-1">$\Box$</a>

<!-- endtab -->
<!-- tab 双线性函数 -->

> **定义** 表示矩阵/度量矩阵
>
> 令$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$为$V$的一组基, 称
> $$(f(\epsilon_i,\epsilon_j))_{n\times n}$$
> 为$f$在$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的**表示矩阵**

我们有如下定理

#### <a href="#end-t-1-1-2" id="t-1-1-2">定理 - 1-1-2</a>

$\zeta:BL(V,\mathbb{P})\to\mathbb{P}^{n\times n};~f\mapsto(f(\epsilon_i,\epsilon_j))_{n\times n}$为双射

即所有双线性函数的集合$BL(V,\mathbb{P})$与$\mathbb{P}^{n\times n}$同构

<a href="#t-1-1-2" id="end-t-1-1-2">$\Box$</a>

<!-- endtab -->

{% endtabs %}

证明很简单, 读者可尝试自行补充

我们发现  
$\forall\alpha=\displaystyle\sum_{i=1}^nx_i\epsilon_i=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})X,\beta=\sum_{i=1}^ny_i\epsilon_i=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})Y\in V$  
都有
$$f(\alpha,\beta)=X^TAY$$
这样就将双线性函数的计算转换成了矩阵乘法, 这个形式很重要

### 零元

类比线性空间中的零元, 我们可定义零线性函数/零双线性函数

{% tabs define-1-zero,1 %}

<!-- tab 线性函数 -->

> **定义** 零线性函数
>
> 对于线性函数$f$, 若$(\forall\alpha\in V),~f(\alpha)=0$, 则称$f$为**零线性函数**, 记作$\bold{0}$

<!-- endtab -->
<!-- tab 双线性函数 -->

> **定义** 零双线性函数
>
> 对于双线性函数$f$, 若$(\forall\alpha,\beta\in V),~f(\alpha,\beta)=0$, 则称$f$为**零双线性函数**, 记作$\bold{0}$

<!-- endtab -->

{% endtabs %}

### 基底间的过渡

设$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$和$(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})$是$V$的两组基底, 过渡矩阵$T$使得

$$(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})T$$

{% tabs define-1-trans,1 %}

<!-- tab 线性函数 -->

若线性函数$f$在$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$和$(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的表示向量分别为$(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})$和$(\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 则

$$(\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{n})=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})T$$

因此$T$非奇异

<!-- endtab -->
<!-- tab 双线性函数 -->

若双线性函数$f$在$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$和$(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的表示矩阵分别为$A$和$B$, 则

$$B=T^TAT$$

因此$T$非奇异, **称$\operatorname{rk}A$为$f$的秩**

<!-- endtab -->

{% endtabs %}

---

接下来我们定义一些特殊的双线性函数, 我们可以从这些函数具有的性质中感受到其与矩阵的密切关系

### 非奇异双线性函数

> **定义** 非奇异双线性函数
>
> 称$f$是**非奇异的**, 若
> $$(\forall\alpha\in V/\{\theta\},~\exist\beta\in V),~f(\alpha,\beta)\ne0$$

#### <a href="#end-t-1-2" id="t-1-2">定理 - 1-2</a>

下列命题等价

1. $f$是非奇异的
1. $f$在$V$**任意**基底下的度量矩阵是非奇异的
1. $f$在$V$**某一**基底下的度量矩阵是非奇异的
1. $(\forall\alpha\in V/\{\theta\},~\exist\beta\in V),~f(\beta,\alpha)\ne0$ (**对称性**)

##### <a href="#t-1-2" id="p-t-1-2">证明</a>

$1\iff2:$

$$
\begin{aligned}
  (\forall\alpha\in V,~\forall\beta\in V,~f(\alpha,\beta)=0\implies\alpha=0)&\iff(\forall X\in\mathbb{P}^n,~\forall Y\in\mathbb{P}^n,~X^TAY=0\implies X=0)\\
  &\iff(\forall X\in\mathbb{P}^n,~X^TA=0\implies X=0)
\end{aligned}
$$

$2\iff3:$ 显然

$2\iff4:$ 参照$1\iff2$

<a href="#p-t-1-2" id="end-t-1-2">$\Box$</a>

### 对称双线性函数

> **定义** 对称双线性函数
>
> 称$f$是**对称的**, 若
> $$(\forall\alpha,\beta\in V),~f(\alpha,\beta)=f(\beta,\alpha)$$

#### <a href="#end-t-1-3" id="t-1-3">定理 - 1-3</a>

下列命题等价

1. $f$是对称的
1. $f$在$V$**任意**基底下的度量矩阵是对称的
1. $f$在$V$**某一**基底下的度量矩阵是对称的

证明参照 <a href="#t-1-2">定理 - 1-2</a>

<a href="#t-1-3" id="end-t-1-3">$\Box$</a>

### 斜对称双线性函数

> **定义** 斜对称双线性函数
>
> 称$f$是**斜对称的**, 若
> $$(\forall\alpha,\beta\in V),~f(\alpha,\beta)=-f(\beta,\alpha)$$

### 正定双线性函数

> **定义** 正定双线性函数
>
> 称$f$是**正定的**, 若
> $$(\forall\alpha\in V/\{\theta\}),~f(\alpha,\alpha)>0$$

我们将在 [Euclid 空间](#euclid空间) 见到它

它有类似 <a href="#t-1-2">定理 - 1-2</a>, <a href="#t-1-3">定理 - 1-3</a> 的定理 (<a href="#t-3-4">定理 - 3-4</a>)

---

### 正交与正交基

> **定义** 正交
>
> 对双线性函数$f$, 称$\alpha,\beta\in V$**正交**, 若$f(\alpha,\beta)=0$

---

> **定义** 正交基底
>
> 一组基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$称作**正交基底**, 若$(\forall 1\leqslant i,j\leqslant n,i\ne j), f(\epsilon_i,\epsilon_j)=0$

#### <a href="#end-t-1-4" id="t-1-4">定理 - 1-4</a>

对任意线性空间$V$和其上的**对称**双线性函数$f$, 正交基底总是存在  
进而$f$在该基底下的度量矩阵为对角矩阵, 对角线上的非零元素个数为$f$的秩

##### <a href="#t-1-4" id="p-t-1-4">证明</a>

- 若$f$是零函数, 则$V$上任意基底均为所求
- 若$f$是非零函数, 即
  $$(\exist\alpha,\beta\in V),~f(\alpha,\beta)\ne0$$

  由  
  $f(\alpha,\beta)=\displaystyle\frac{1}{2}\left(f(\alpha+\beta,\alpha+\beta)-f(\alpha,\alpha)-f(\beta,\beta)\right)$ (这里利用了$f$的对称性)  
  可知

  $$(\exist\epsilon\in V),~f(\epsilon,\epsilon)\ne0\tag{1.4.1}$$

  接下来对$\dim V$应用第二数学归纳法

  - 当$\dim V=1$时, 任意基底均为所求
  - 若对$1\leqslant\dim V\leqslant n-1$的情况命题都成立, 考察$\dim V=n$的情形

    对$(1.4.1)$中的$\epsilon$, 将其扩充为$V$的一组基底$(\epsilon,\def\enum#1{\eta_{ #1}}\enum{2},...,\enum{n})$

    令$\epsilon_i'=\displaystyle \eta_i-\frac{f(\eta_i,\epsilon)}{f(\epsilon,\epsilon)}\epsilon,\qquad i=2,3,...,n$

    则$(\epsilon,\def\enum#1{\epsilon'_{ #1}}\enum{2},...,\enum{n})$为$V$的基底, 且  
    $f(\epsilon,\epsilon_i')=0,\qquad i=2,3,...,n$

    因此

    $$(\forall\alpha\in G[\def\enum#1{\epsilon'_{ #1}}\enum{2},...,\enum{n}]),~f(\epsilon,\alpha)=0\tag{1.4.2}$$

    又显然$V=G[\epsilon]\oplus G[\def\enum#1{\epsilon'_{ #1}}\enum{2},...,\enum{n}]$

    考虑$f|_{G[\def\enum#1{\epsilon'_{ #1}}\enum{2},...,\enum{n}]}$, 由归纳假设, $G[\def\enum#1{\epsilon'_{ #1}}\enum{2},...,\enum{n}]$中有正交基底$(\def\enum#1{\epsilon_{ #1}}\enum{2},...,\enum{n})$

    故由$(1.4.2)$式可得$(\epsilon,\def\enum#1{\epsilon_{ #1}}\enum{2},...,\enum{n})$为$V$的一组正交基底

<a href="#p-t-1-4" id="end-t-1-4">$\Box$</a>

#### <a href="#end-ifr-1-4-1" id="ifr-1-4-1">推论 - 1-4-1</a>

- 令$V$为$\Complex$上一$n$维线性空间, $f$为$V$上一对称双线性函数, 则存在正交基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$使得对$V$上的任意向量$\alpha=\sum_{i=1}^nx_i\epsilon_i,\beta=\sum_{i=1}^ny_i\epsilon_i$均有

  $$f(\alpha,\beta)=\sum_{i=1}^rx_iy_i$$

  其中$r=\operatorname{rk}f$

- 若$V$为$\R$上一$n$维线性空间, 其余同上, 则

  $$f(\alpha,\beta)=\sum_{i=1}^px_iy_i-\sum_{i=p+1}^rx_iy_i$$

另一种写法:

- 对于前者, $f$的度量矩阵为$\operatorname{diag}\{\underbrace{1,...,1}_{\operatorname{rk}f},0,...,0\}$
- 对于后者, $f$的度量矩阵为$\operatorname{diag}\{\underbrace{1,...,1}_{p},\underbrace{-1,...,-1}_{\operatorname{rk}f-p},0,...,0\}$

##### <a href="#ifr-1-4-1" id="p-ifr-1-4-1">证明</a>

若$V$为$\R$上一$n$维线性空间, 则由 <a href="#t-1-4">定理 - 1-4</a> 可知,  
存在正交基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 使得$f$的度量矩阵为$\operatorname{diag}\{\def\enum#1{d_{ #1}}\enum{1},\enum{2},...,\enum{p},\def\enum#1{-d_{ #1}}\enum{p+1},\enum{p+2},...,\enum{r},0,...,0\}$, 其中$\def\enum#1{d_{ #1}}\enum{1},\enum{2},...,\enum{r}>0,~0\leqslant p\leqslant r\leqslant n$

考虑$f(\epsilon_i,\epsilon_i)=(-1)^{[i>p]}d_i,~1\leqslant i\leqslant r$

令$\displaystyle\epsilon'_i={\epsilon_i\over\sqrt{d_i}}$, 则$f(\epsilon'_i,\epsilon'_i)=(-1)^{[i>p]}$

容易验证$(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{r},\def\enum#1{\epsilon_{ #1}}\enum{r+1},\enum{r+2},...,\enum{n})$为正交基底

故在正交基底$(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{r},\def\enum#1{\epsilon_{ #1}}\enum{r+1},\enum{r+2},...,\enum{n})$下, $f$的度量矩阵为$\operatorname{diag}\{\underbrace{1,...,1}_{p},\underbrace{-1,...,-1}_{\operatorname{rk}f-p},0,...,0\}$

我们可以注意到负号产生的原因是$\sqrt{\phantom{-}}$要求被开方数非负, 而在$\Complex$上没有这个限制, 故在$\Complex$上即为$\operatorname{diag}\{\underbrace{1,...,1}_{\operatorname{rk}f},0,...,0\}$

<a href="#p-ifr-1-4-1" id="end-ifr-1-4-1">$\Box$</a>

在后面还有进一步的讨论

### 习题

#### <a href="#end-prob-1-1" id="prob-1-1">习题 - 1-1</a>

令$V$为$\mathbb{P}$上一$n$维线性空间, $\def\enum#1{f_{ #1}}\enum{1},\enum{2},...,\enum{k}$为$V$上$k$个线性函数, 证明:

1. $$W=\{\alpha\in V|f_i(\alpha)=0\}\leqslant V$$
   称$W$为$\def\enum#1{f_{ #1}}\enum{1},\enum{2},...,\enum{k}$的**零化子空间**
1. 若$W\leqslant V$, 则存在$V$上$k$个线性函数$\def\enum#1{f_{ #1}}\enum{1},\enum{2},...,\enum{k}$使得$W$为$\def\enum#1{f_{ #1}}\enum{1},\enum{2},...,\enum{k}$的零化子空间

##### <a href="#prob-1-1" id="p-prob-1-1">解</a>

1. 首先, $\theta\in W$

   又, 若$\alpha,\beta\in W$, 即$f_i(\alpha)=f_i(\beta)=0,~i=1,2,...,k$

   则$(\forall s,t\in\mathbb{P}),~f_i(s\alpha+t\beta)=sf_i(\alpha)+tf_i(\beta)=0,~i=1,2,...,k$

   因此$W\leqslant V$
   1

   - 若$W=V$, 则令$f(\alpha)=0,~\forall\alpha\in V$, $W$为$f$的零化子空间
   - 若$W=\{\theta\}$, 则$W$为$L(V,\mathbb{P})$的零化子空间
   - 若$\dim W=r\in[1,n)$, 取$W$的一组基$\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{r}$, $V$的一组基$\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n}$

     令$f_i(\epsilon_j)=\delta_{ij},~i,j=1,2,...,n$

     取$\def\enum#1{f_{ #1}}\enum{r+1},\enum{r+2},...,\enum{n}$构成的零化子空间$M$

     则$(\forall\alpha\in W),~\alpha\in M$, 即$W\subseteq M$

     又取$\alpha=\sum_{i=1}^nk_i\epsilon_i\in M$, 由$f_i(\alpha)=k_i,~i=1,2,...,n$可知$k_i=0,i=r+1,r+2,...,n$

     故$\alpha\in W$, 即$M\subseteq W$

     因此$W$是$\def\enum#1{f_{ #1}}\enum{r+1},\enum{r+2},...,\enum{n}$的零化子空间

<a href="#p-prob-1-1" id="end-prob-1-1">$\Box$</a>

#### <a href="#end-prob-1-2" id="prob-1-2">习题 - 1-2</a>

令$V$是复线性空间, $\dim V\geqslant 2$, $f$为$V$上一对称双线性函数, 证明:

1. $$(\exist\theta\ne\zeta\in V),~f(\zeta,\zeta)=0$$
1. 若$f$非奇异, 则存在线性无关向量$\zeta,\eta$使得
   $$f(\zeta,\eta)=1,f(\zeta,\zeta)=f(\eta,\eta)=0$$

##### <a href="#prob-1-2" id="p-prob-1-2">解</a>

1. 由$\dim V\geqslant2$可知, 存在$\alpha,\beta\in V$使得$\alpha,\beta$线性无关

   设$f(\alpha,\alpha)=a,f(\beta,\beta)=b$

   - 若$a=0$或$b=0$, 则命题得证
   - 若$a,b$均不为$0$, 考虑
     $$f(\alpha+t\beta,\alpha+t\beta)=f(\alpha,\alpha)+2tf(\alpha,\beta)+t^2f(\beta,\beta)$$
     此时$t$有根$t_1$, 故令$\zeta=\alpha+t_1\beta$, 则$f(\zeta,\zeta)=0$

1. 由 1 知, $(\exist\theta\ne\zeta\in V),~f(\zeta,\zeta)=0$

   取$\zeta\ne\xi'\in V/\{\theta\}$, 由$f$非奇异知$f(\zeta,\xi')=b\ne0$

   令$\xi=\displaystyle\frac{\xi'}{b}$

   - 若$f(\xi,\xi)=0$, 则命题得证
   - 若$f(\xi,\xi)\ne0$, 考虑$f(\xi+t\zeta,\xi+t\zeta)$

     $f(\zeta,\xi+t\zeta)=1$

     由 1 知, $t$有根$t_1$使得$f(\xi+t_1\zeta,\xi+t_1\zeta)=0$

     令$\eta=\xi+t_1\zeta$即可

<a href="#p-prob-1-2" id="end-prob-1-2">$\Box$</a>

## 对称双线性度量空间与线性方程组可解的几何解释

说实话, 我挺讨厌这种万物都往方程组上靠的做法

### 对称双线性度量空间

就是有**非奇异对称双线性函数**的线性空间

特别的, 当$\mathbb{P}=\R$时即称其为**伪 Euclid 空间**

显然, 这个非奇异对称双线性函数是**满秩**的, 即

#### <a href="#end-prop-2-1" id="prop-2-1">命题 - 2-1</a>

$n$维对称双线性度量空间$V$存在正交基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 使得$V$上的非奇异对称双线性函数$f$有

- $f(\epsilon_i,\epsilon_i)\ne0,~i=1,2,...,n$
- $f(\epsilon_i,\epsilon_j)=0,~1\leqslant i,j\leqslant n,i\ne j$

<a href="#prop-2-1" id="end-prop-2-1">$\Box$</a>

### 正交补空间

在继续讨论线性方程组之前, 我们先引入正交补的概念

> **定义** 正交补(空间)
>
> 对$n$维对称双线性度量空间$V=(V,+,\cdot,\mathbb{P},f)$和$V_1\leqslant V$, 称
> $$\{\alpha\in V|(\forall\beta\in V_1),~f(\alpha,\beta)=0\}$$
> 为$V_1$的正交补(空间), 记作$V_1^\perp$
>
> 显然$V_1^\perp\leqslant V$

由定义立得

#### <a href="#end-prop-2-2" id="prop-2-2">命题 - 2-2</a>

- 若$\dim V_1=0$, 则$V_1^\perp=V$
- 若$\dim V_1=r\geqslant1$, 且$(\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{r})$为$V_1$的一组基, 则
  $$V_1^\perp=\{\alpha\in V|f(\alpha,\beta_i)=0,~i=1,2,...,r\}$$

  即$V_1^\perp$为$\begin{cases}
    f(\alpha,\beta_i)=0\\i=1,2,...,r
  \end{cases}$的解集

若令$f$在基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的表示矩阵为$A$, $\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{r}$的坐标分别为$\def\enum#1{B_{ #1}}\enum{1},\enum{2},...,\enum{r},~\alpha$的坐标为$X$, 则上述方程组可表示为

$$X^TA(\def\enum#1{B_{ #1}}\enum{1},\enum{2},...,\enum{r})=\theta$$

另外, $V_1^\perp$与上式的解空间$S$同构

<a href="#prop-2-2" id="end-prop-2-2">$\Box$</a>

#### <a href="#end-t-2-1" id="t-2-1">定理 - 2-1</a>

若$V$为$n$维对称双线性度量空间, $V_1\leqslant V$, 则

1. $\dim V_1+\dim V_1^\perp=\dim V$
2. $(V_1^\perp)^\perp=V_1$

##### <a href="#t-2-1" id="p-t-2-1">证明</a>

当$\dim V_1=0$时, 易知命题成立

当$\dim V_1=r\geqslant1$时,

1. 只需证$\dim S=n-r$

   $S$即为$(\def\enum#1{B_{ #1}}\enum{1},\enum{2},...,\enum{r})^TAX=\theta$的解空间 (等式两边取转置)

   令$B=(\def\enum#1{B_{ #1}}\enum{1},\enum{2},...,\enum{r})^T$, 则$\dim S=n-r\iff\operatorname{rk} BA=r$

   而$\operatorname{rk}B=r$, 由$A$可逆知$\operatorname{rk}BA=\operatorname{rk}B=r$

   因此$\dim S=n-r$

1. 由 1 知, $\dim V_1^\perp=n-r,~\dim~(V_1^\perp)^\perp=r=\dim V_1$

   又$V_1\subseteq(V_1^\perp)^\perp$

   故$(V_1^\perp)^\perp=V_1$

<a href="#p-t-2-1" id="end-t-2-1">$\Box$</a>

#### <a href="#end-atten-2-1-1" id="atten-2-1-1">注意 - 2-1-1</a>

未必有$V_1\cap V_1^\perp=\{\theta\}$, 即未必有$V=V_1\oplus V_1^\perp$

如在$\Complex^2$上引入$f((x_1,y_1),(x_2,y_2))=x_1x_2+y_1y_2$, 显然可构成对称双线性度量空间, 而取$V_1=G[(1,i)]$, 显然$V_1=V_1^\perp$

<a href="#atten-2-1-1" id="end-atten-2-1-1">$\Box$</a>

### 线性方程组可解的几何解释

进入正题

本节将在$n$维对称双线性度量空间$\mathbb{P}^n(E)$中讨论
$$AX=\theta\tag{2.3.1}$$
和
$$AX=B\tag{2.3.2}$$

其中$\mathbb{P}^n(E)$表示$\mathbb{P}^n$连同在自然基底下度量矩阵为$E$的双线性函数$f_E$所构成的对称双线性度量空间, 显然有

$$f_E([\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}]^T,[\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{n}]^T)=\sum_{i=1}^na_ib_i$$

- 齐次线性方程组$(2.3.1)$可记作

  $$
  \begin{cases}
    f_E(A_i^T,X)=0\\
    i=1,2,...,m
  \end{cases}
  $$

  其中$A_i=(\def\enum#1{a_{i #1}}\enum{1},\enum{2},...,\enum{n}),~i=1,2,...,m$

  令$V_1=G[\def\enum#1{A_{ #1}^T}\enum{1},\enum{2},...,\enum{m}]$, 则上述齐次线性方程组的解空间恰为$V_1^\perp$

- 非齐次线性方程组$(2.3.2)$有解$\iff\operatorname{rk}(\def\enum#1{A^{ #1}}\enum{1},\enum{2},...,\enum{n})=\operatorname{rk}(\def\enum#1{A^{ #1}}\enum{1},\enum{2},...,\enum{n},B)\iff B\in G[\def\enum#1{A^{ #1}}\enum{1},\enum{2},...,\enum{n}]$

  其中$A^i=(\def\enum#1{a_{ #1i}}\enum{1},\enum{2},...,\enum{m})^T,~i=1,2,...,n$

  考虑$(2.3.2)$的转置齐次线性方程组

  $$A^TY=\theta\tag{2.3.3}$$

  由上一部分的讨论可知, $(2.3.3)$的解空间为$G[\def\enum#1{A^{ #1}}\enum{1},\enum{2},...,\enum{n}]^\perp$

  故$B\in G[\def\enum#1{A^{ #1}}\enum{1},\enum{2},...,\enum{n}]\iff B$与$(2.3.3)$的解空间正交

  这可以作为一个定理

#### <a href="#end-t-2-2" id="t-2-2">定理 - 2-2</a>

非齐次线性方程组$(2.3.2)$有解当且仅当$B$与$(2.3.3)$的解空间正交

<a href="#p-t-2-2" id="end-t-2-2">$\Box$</a>

### 习题

#### <a href="#end-prob-2-1" id="prob-2-1">习题 - 2-1</a>

令$V$为$\mathbb{P}$上一$n$维线性空间, $V_1<V,\zeta\notin V_1$, $f$为$V$上一对称双线性函数, 证明:
$$(\exist0\ne\eta\in V_1+G[\zeta]),(\forall\alpha\in V_1),~f(\eta,\alpha)=0$$

##### <a href="#prob-2-1" id="p-prob-2-1">解</a>

即证$\theta\ne\eta\in(V_1+G[\zeta])\cap V_1^\perp$

设$\dim V_1=r$, 则$\dim(V_1+G[\zeta])=r+1,~\dim V_1^\perp=n-r$

故$\dim((V_1+G[\zeta])\cap V_1^\perp)\ne0$

<a href="#p-prob-2-1" id="end-prob-2-1">$\Box$</a>

## Euclid 空间

> **定义** Euclid 空间
>
> 令$V$为实线性空间, 若其上一对称双线性函数$f$满足**正定性**, 则称$V$连同$f$构成**Euclid 空间**
>
> 称$f$为**内积**, 记作$(~,~)$, $f(\alpha,\beta)$可简记为$(\alpha,\beta)$

显然 Euclid 空间是伪 Euclid 空间

> **例 - 1**
>
> 定义$f$如下:
> $$f(g(x),h(x))=\int_a^bf(x)g(x)\mathrm{d}x$$
> 易证$f$是内积, $C[a,b]$连同$f$构成 Euclid 空间

### 向量的长度与夹角 (度量)

Euclid 空间有一个很好的性质, 就是我们可以在其上定义向量的长度, 夹角等在直观几何中的概念  
这一点即使是在一般的伪 Euclid 空间都是做不到的

> **定义** 长度
>
> 令$V$为一 Euclid 空间, $\alpha\in V$, 称$\sqrt{(\alpha,\alpha)}$为$\alpha$的**长度**, 记作$|\alpha|$

---

> **定义** 单位向量
>
> 假设同上, 称$\alpha$为**单位向量**, 若$|\alpha|=1$
>
> 如果$\alpha\ne\theta$, 则$\displaystyle\frac{\alpha}{|\alpha|}:=\frac{1}{|\alpha|}\alpha$为单位向量

---

在定义夹角之前, 我们需要证明$\displaystyle\frac{|(\alpha,\beta)|}{|\alpha||\beta|}\leqslant1$

在高中数学中, 这个形式等价于$\displaystyle\left|\sum_{i=1}^na_ib_i\right|\leqslant\sqrt{\sum_{i=1}^na_i^2}\sqrt{\sum_{i=1}^nb_i^2}$, 这就是大名鼎鼎的 Cauchy 不等式

到了 Euclid 空间, 我们自然也会考虑是否能将 Cauchy 不等式推广过来

很幸运, 这是可行的

#### <a href="#end-t-3-1" id="t-3-1">定理 - 3-1</a> (Cauchy-Bunjakovski-Schwarz 不等式)

令$V$为一 Euclid 空间, 则对其上任意非零向量$\alpha,\beta$, 均有
$$\frac{|(\alpha,\beta)|}{|\alpha||\beta|}\leqslant1$$
等号成立当且仅当$\alpha,\beta$线性相关

> 若写成$|(\alpha,\beta)|\leqslant|\alpha||\beta|$, 则不需限制$\alpha,\beta$非零

##### <a href="#t-3-1" id="p-t-3-1">证明</a>

考察$\alpha-k\beta,~k\in\R$, 由内积的正定性可得

$$k^2(\beta,\beta)-2k(\alpha,\beta)+(\alpha,\alpha)\leqslant0$$

此式表明判别式非正, 即$(\alpha,\beta)^2-(\alpha,\alpha)(\beta,\beta)\leqslant0$

亦即
$$\frac{|(\alpha,\beta)|}{|\alpha||\beta|}\leqslant1$$

当$\alpha,\beta$线性相关时, 上式等号显然成立  
反之, 若上式等号成立, 则$(\exist t_0\in\R),~(\alpha-t_0\beta,\alpha-t_0\beta)=0$, 可得$\alpha-t_0\beta=0$, 即$\alpha,\beta$线性相关

<a href="#p-t-3-1" id="end-t-3-1">$\Box$</a>

Cauchy-Bunjakovski-Schwarz 不等式有两个著名的实例

- $$\left|\sum_{i=1}^na_ib_i\right|\leqslant\sqrt{\sum_{i=1}^na_i^2}\sqrt{\sum_{i=1}^nb_i^2}$$
- $$\left|\int_a^bf(x)g(x)\mathrm{d}x\right|\leqslant\sqrt{\int_a^bf^2(x)\mathrm{d}x}\sqrt{\int_a^bg^2(x)\mathrm{d}x}$$

---

接下来给出夹角的定义

> **定义** 夹角
>
> 令$V$为一 Euclid 空间, $\alpha,\beta\in V/\{\theta\}$, 称$\displaystyle\arccos\frac{(\alpha,\beta)}{|\alpha||\beta|}\in[0,\pi]$为$\alpha$和$\beta$的**夹角**, 记作$\langle\alpha,\beta\rangle$

接下来我们可以尝试把我们熟知的, 与长度和角度相关的几何定理都推广到 Euclid 空间了 (其实, 在 <a href="#ifr-3-2">推论 - 3-2</a> 的保障下, 我们可以更大胆些)

#### <a href="#end-t-3-2" id="t-3-2">定理 - 3-2</a>

令$V$为一 Euclid 空间, $\alpha,\beta\in V$, 则

1. $|\alpha+\beta|\leqslant|\alpha|+|\beta|$ (三角不等式)
1. $(\alpha,\beta)=0\implies|\alpha+\beta|^2=|\alpha|^2+|\beta|^2$ (勾股定理)
   > 可推广为
   > $$((\forall1\leqslant i,j\leqslant m,i\ne j),~(\alpha_i,\alpha_j)\ne0),~\left|\sum_{i=1}^ma_i\right|^2=\sum_{i=1}^m|\alpha_i|^2$$

##### <a href="#t-3-2" id="p-t-3-2">证明</a>

1. 由 <a href="#t-3-1">定理 - 3-1</a>,
   $$|\alpha+\beta|^2=(\alpha,\alpha)+2(\alpha,\beta)+(\beta,\beta)\leqslant|\alpha|^2+2|\alpha||\beta|+|\beta|^2=(|\alpha|+|\beta|)^2$$
1. $$|\alpha+\beta|^2=(\alpha,\alpha)+(\beta,\beta)=|\alpha|^2+|\beta|^2$$

<a href="#p-t-3-2" id="end-t-3-2">$\Box$</a>

### 标准正交基底

简单来说, 就是满足其所有基向量都是单位向量的一组正交基底

> **定义** 标准正交基底
>
> 称$n$维 Euclid 空间上的一组基$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$是**标准正交**的, 若
>
> - $|\epsilon_i|=1,~i=1,2,...,n$
> - $(\epsilon_i,\epsilon_j)=0,~i,j=1,2,...,n,i\ne j$

容易验证, $n$维 Euclid 空间存在标准正交基, 而且我们还可以将其上任意基底标准正交化

#### <a href="#end-t-3-3" id="t-3-3">定理 - 3-3</a> (标准正交化)

若$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})$为$n$维 Euclid 空间上的一组基, 则其上存在标准正交基$(\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n})$使得

$$G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{i}]=G[\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{i}],~i=1,2,...,n$$

##### <a href="#t-3-3" id="p-t-3-3">证明</a>

观察定理形式可知是用归纳法证的

该证法也是构造性的

- 令$\beta'_1=\alpha_1$, 则$G[\beta'_1]=G[\alpha_1]$
- 令$\beta'_2=\alpha_2+k\beta'_1$使得$(\beta'_2,\beta'_1)=0$, 可推知当且仅当
  $$k=-\frac{(\alpha_2,\beta'_1)}{(\beta'_1,\beta'_1)}$$
  时此式成立

  由$\beta'_2=\alpha_2+k\beta'_1=\alpha_2+k\alpha_1$可知$\beta'_1,\beta'_2$线性无关, 故$G[\beta'_1,\beta'_2]=G[\alpha_1,\alpha_2]$

- 假设已找到$m<n$个两两正交的向量$\def\enum#1{\beta'_{ #1}}\enum{1},\enum{2},...,\enum{m}$满足条件

  令
  $$\beta'_{m+1}=\alpha_{m+1}+\sum_{i=1}^mk_i\beta'_i$$
  使得
  $$(\beta'_{m+1},\beta'_i)=0,~i=1,2,...,m$$
  即
  $$(\alpha_{m+1},\beta'_i)+k_i(\beta'_i,\beta'_i)=0,~i=1,2,...,m$$
  上式成立当且仅当
  $$k_i=-{(\alpha_{m+1},\beta'_i)\over(\beta'_i,\beta'_i)},~i=1,2,...,m$$

  又可知$\beta'_{m+1}$是$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m+1}$的线性组合, $\beta'_{m+1}\ne\theta$

  因此$G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m+1}]=G[\def\enum#1{\beta'_{ #1}}\enum{1},\enum{2},...,\enum{m+1}]$

因此我们可以找到一组正交基$(\def\enum#1{\beta'_{ #1}}\enum{1},\enum{2},...,\enum{n})$满足  
$$G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{i}]=G[\def\enum#1{\beta'_{ #1}}\enum{1},\enum{2},...,\enum{i}],~i=1,2,...,n$$

> 上述过程即 Schmidt 正交化

又令$\beta_i=\displaystyle\frac{1}{|\beta'_i|}\beta'_i,~i=1,2,...,n$, 命题即得证

<a href="#p-t-3-3" id="end-t-3-3">$\Box$</a>

应用 <a href="#t-3-3">定理 - 3-3</a> 的方法即可将任意基底标准正交化

此方法本质上还是矩阵乘法

#### <a href="#end-ifr-3-1" id="ifr-3-1">推论 - 3-1</a>

令$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$为$n$维 Euclid 空间$V$的一组标准正交基, 则

- $V$的内积的度量矩阵为$E$
- 若$\alpha,~\beta\in V$在其上的坐标分别为$A=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})^T,~B=(\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{n})^T$, 则
  $$(\alpha,\beta)=\sum_{i=1}^na_ib_i=A^TB$$

<a href="#ifr-3-1" id="end-ifr-3-1">$\Box$</a>

接下来是一个与内积证明和性质有关的定理

#### <a href="#end-t-3-4" id="t-3-4">定理 - 3-4</a>

令$V$为$n$维实线性空间, $f$是$V$上一双线性函数, 则下列命题等价:

1. $f$为$V$上的内积
1. $f$在$V$的任意基底下的度量矩阵$A$正定, 即存在可逆矩阵$P$使得$A=P^TP$
1. $f$在$V$的某一基底下的度量矩阵$A$正定

##### <a href="#t-3-4" id="p-t-3-4">证明</a>

$1\implies2:$

可知$V$连同$f$构成 Euclid 空间

故由 <a href="#ifr-3-1">推论 - 3-1</a> 可知, 存在标准正交基$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$使得$f$的度量矩阵为$E$

任取$V$上一组基底$(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})Q$, 易知$Q$可逆, 则$f$在该基底下的度量矩阵$A=Q^TEQ=Q^TQ$

$2\implies3:$ 显然

$3\implies1:$

不妨设该基底为$(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})$

假设$f$在该基底下的度量矩阵为$A=Q^TQ=Q^TEQ$, 则$E=(Q^{-1})^TAQ^{-1}$

故存在基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})=(\def\enum#1{\eta_{ #1}}\enum{1},\enum{2},...,\enum{n})Q^{-1}$使得$f$的度量矩阵为$E$

显然$f$是对称正定双线性函数, 即$f$为$V$上的内积

<a href="#p-t-3-4" id="end-t-3-4">$\Box$</a>

### Euclid 空间的同构

> **定义** Euclid 空间同构映射
>
> 令$V,V'$为两个 Euclid 空间, 称$V$到$V'$的同构映射$f$是$V$到$V'$的**Euclid 空间同构映射**, 若
> $$(\forall\alpha,\beta\in V),~(f(\alpha),f(\beta))=(\alpha,\beta)$$
> 此时, 称$V$与$V'$是同构的

显然这个同构也是等价关系

#### <a href="#end-t-3-5" id="t-3-5">定理 - 3-5</a>

两有限维 Euclid 空间$V,V'$同构当且仅当$\dim V=\dim V'$

##### <a href="#t-3-5" id="p-t-3-5">证明</a>

$\implies$: 显然

$\impliedby$:

只需证$n$维 Euclid 空间$V$同构于$\R^n$

令$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$为$V$的一组标准正交基, 建立映射

$$f_{\{\epsilon_i\}_{i=1}^n}:\alpha\mapsto(\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n})^T\in\R^n,~\alpha=\sum_{i=1}^nx_i\epsilon_i\in V$$

易知$f_{\{\epsilon_i\}_{i=1}^n}$是$V$到$\R^n$的线性同构映射

任取$\alpha=\sum_{i=1}^nx_i\epsilon_i,\beta=\sum_{i=1}^ny_i\epsilon_i$, 均有

$$
\begin{aligned}
  (\alpha,\beta)&=\sum_{i=1}^nx_iy_i\\
  &=((\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n})^T,(\def\enum#1{y_{ #1}}\enum{1},\enum{2},...,\enum{n})^T)\\
  &=(f_{\{\epsilon_i\}_{i=1}^n}(\alpha),f_{\{\epsilon_i\}_{i=1}^n}(\beta))
\end{aligned}
$$

<a href="#p-t-3-5" id="end-t-3-5">$\Box$</a>

基于这个定理, 我们有一个重要且有用的推论

#### <a href="#end-ifr-3-2" id="ifr-3-2">推论 - 3-2</a>

在 Euclid 空间中, 所有关于两个或三个向量的命题均可在三维直观几何空间验证

##### <a href="#ifr-3-2" id="p-ifr-3-2">证明</a>

在 Euclid 空间中, 两个或三个向量可生成维数不超过 3 的 Euclid 空间, 由 <a href="#t-3-5">定理 - 3-5</a> 可知其与三维直观几何空间或其子空间同构

而 Euclid 空间中的命题均可只用空间说的加法, 实数乘和内积描述, 因此只需在三维直观几何空间中验证就行

<a href="#p-ifr-3-2" id="end-ifr-3-2">$\Box$</a>

---

在本章的最后, 我们另给出一组定理

#### <a href="#end-t-3-6" id="t-3-6">定理 - 3-6</a>

令$V$为一$n$维 Euclid 空间, $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}\in V$, 则有如下平行的事实

1. 若$\alpha_i\ne\theta,~(\alpha_i,\alpha_j)=0,~i,j=1,2,...,m,~i\ne j$, 则$m\leqslant n$
1. 若$(\alpha_i,\alpha_j)<0,~i,j=1,2,...,m,~i\ne j$, 则$m\leqslant n+1$
1. 若$(\alpha_i,\alpha_j)>0,~i,j=1,2,...,m,~i\ne j$, 则不存在映射$f:\Z^+\to\Z^+$满足$m\leqslant f(n)$

又在线性相关的角度, 我们可以注意到更深刻的事实

1. 条件蕴含$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性无关
1. 条件蕴含$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$的任意真子组线性无关

##### <a href="#t-3-6" id="p-t-3-6">证明</a>

1. 设$\exist k_i\in\R,~i=1,2,...,m,~s.t.~\displaystyle\sum_{i=1}^mk_i\alpha_i=\theta$

   则
   $$k_j(\alpha_j,\alpha_j)=-(\alpha_j,\sum_{i=1,~i\ne j}^mk_i\alpha_i)=0,~j=1,2,...,m$$

   而$(\alpha_j,\alpha_j)>0$, 故$k_j=0,~j=1,2,...,m$

   因此$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性无关

   因此$m\leqslant n$

1. 不妨设$m=n+2$

   则
   $$\exist k_i\in\R,~i=1,2,...,n+1,\sum_{i=1}^{n+1}k_i^2\ne0,~s.t.~\sum_{i=1}^{n+1}k_i\alpha_i=\theta$$

   此时$(\alpha_{n+2},\sum_{i=1}^{n+1}k_i\alpha_i)=0$

   此式说明$\def\enum#1{k_{ #1}}\enum{1},\enum{2},...,\enum{n+1}$中有正有负, 不妨设
   $$k_i>0,k_j<0,~i=1,2,...,s,~j=s+1,s+2,...,t,~1\leqslant s<t\leqslant n+1$$
   则$\sum_{i=1}^sk_i\alpha_i=-\sum_{i=s+1}^tk_i\alpha_i$

   而
   $$(\sum_{i=1}^sk_i\alpha_i,-\sum_{i=s+1}^tk_i\alpha_i)=-\sum_{i=1}^s\sum_{j=s+1}^t(k_i\alpha_i,k_j\alpha_j)<0$$

   这与点积的正定性矛盾, 故$m\leqslant n+1$

   类似地, 我们可证明$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$的任意真子组线性无关

   只需证$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m-1}$线性无关

   设$\exist k_i\in\R,~i=1,2,...,m-1,~s.t.~\displaystyle\sum_{i=1}^{m-1}k_i\alpha_i=\theta$

   此时$(\alpha_m,\sum_{i=1}^{m-1}k_i\alpha_i)=0$

   此式说明要么$\def\enum#1{k_{ #1}}\enum{1},\enum{2},...,\enum{m-1}$中有正有负, 要么$\def\enum#1{k_{ #1}}\enum{1},\enum{2},...,\enum{m-1}$均为$0$

   - 若情况为后者, 则命题得证
   - 若情况为前者, 不妨设

     $$k_i>0,k_j<0,~i=1,2,...,s,~j=s+1,s+2,...,t,~1\leqslant s<t\leqslant m-1$$
     则$\sum_{i=1}^sk_i\alpha_i=-\sum_{i=s+1}^tk_i\alpha_i$

     而
     $$(\sum_{i=1}^sk_i\alpha_i,-\sum_{i=s+1}^tk_i\alpha_i)=-\sum_{i=1}^s\sum_{j=s+1}^t(k_i\alpha_i,k_j\alpha_j)<0$$

     这与点积的正定性矛盾, 故情况只能为后者

1. 由条件知 $\alpha_i\ne\theta,i=1,2,...,m$

   假设$f$存在

   - 当$n=1$时, $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$中任意两个向量均线性相关, 不妨设  
     $\alpha_i=k_i\alpha_1,~i=1,2,3,...m$, 显然$k_1=1$

     假设$f(1)\in\Z^+$, 令$m=f(1)$, $k\in\Z^+/\{\def\enum#1{k_{ #1}}\enum{1},\enum{2},...,\enum{m}\}$, $\beta=k\alpha_1$

     则$(\beta,\alpha_i)=kk_i(\alpha_1,\alpha_1)>0,~i=1,2,...,m$

     即满足条件的向量组长度至少为$f(1)+1$, 与$m\leqslant f(n)$矛盾!

     因此$1\notin D(f)$

   - 当$n\geqslant2$时, $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$中存在两向量线性无关, 设其为$\alpha'_1,\alpha'_2$

     假设$f(n)\in\Z^+$, 令$m=f(n)$

     令$\beta_k=\alpha'_1+k\alpha'_2,~k=1,2,...,m$, 则其中必有一向量$\beta_{k'}$满足$\beta_{k'}\ne\alpha_i,~i=1,2,...,m$

     此时有$(\beta_{k'},\alpha_i)=(\alpha'_1,\alpha_i)+k'(\alpha'_2,\alpha_i)>0,~i=1,2,...,m$

     即满足条件的向量组长度至少为$f(n)+1$, 与$m\leqslant f(n)$矛盾!

     因此$n\notin D(f)$

   因此$D(f)=\varnothing$, $f$不存在

<a href="#p-t-3-6" id="end-t-3-6">$\Box$</a>

### 习题

#### <a href="#end-prob-3-1" id="prob-3-1">习题 - 3-1</a>

令$V$为一$n$维 Euclid 空间, $\alpha$为$V$中一向量, 证明:

1. $f(\beta)=(\beta,\alpha)$定义$V$上一线性函数
1. 若$g(\eta):=(\eta,\beta),~\beta\ne\alpha$, 则$f\ne g$
1. 对于$V$上任一线性函数$f$, 都存在向量$\alpha$, 使得$f$可由$f(\eta)=(\eta,\alpha)$定义

##### <a href="#prob-3-1" id="p-prob-3-1">解</a>

1. 显然
1. 若$f=g$, 则$(f-g)(\alpha-\beta)=(\alpha-\beta,\alpha-\beta)=0$, 矛盾
1. 任取$V$上一组基$\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 设$f(\epsilon_i)=t_i,~i=1,2,...,n$

   考虑方程组

   $$
   \begin{bmatrix}
     (\epsilon_1,\epsilon_1)&(\epsilon_1,\epsilon_2)&...&(\epsilon_1,\epsilon_n)\\
     (\epsilon_2,\epsilon_1)&(\epsilon_2,\epsilon_2)&...&(\epsilon_2,\epsilon_n)\\
     \vdots&\vdots&\ddots&\vdots\\
     (\epsilon_n,\epsilon_1)&(\epsilon_n,\epsilon_2)&...&(\epsilon_n,\epsilon_n)\\
   \end{bmatrix}\begin{bmatrix}
     k_1\\k_2\\\vdots\\k_n
   \end{bmatrix}=\begin{bmatrix}
     t_1\\t_2\\\vdots\\t_n
   \end{bmatrix}
   $$

   由$((\epsilon_i,\epsilon_j))_{n\times n}$的正定性可知方程组有唯一解, 令$\alpha=\displaystyle\sum_{i=1}^nk_i\epsilon_i$

   则$(\epsilon_i,\alpha)=t_i=f(\epsilon_i)$

   从而$(\forall\eta\in V),~f(\eta)=(\eta,\alpha)$

<a href="#p-prob-3-1" id="end-prob-3-1">$\Box$</a>

## 向量到子空间的距离与线性方程组的最小二乘法

若无明确说明, 本章内容均在**有限维 Euclid 空间**内进行讨论

### 向量在子空间的正射影

我们在 <a href="#t-2-1">定理 - 2-1</a> 得知$\dim V_1+\dim V_1^\perp=\dim V$, 而如果$V$是$n$维 Euclid 空间, 我们有更进一步的结论

#### <a href="#end-t-4-1" id="t-4-1">定理 - 4-1</a>

令$V$为一$n$维 Euclid 空间, 则$\forall V_1\leqslant V$, 均有
$$V=V_1\oplus V_1^\perp$$

##### <a href="#t-4-1" id="p-t-4-1">证明</a>

设$\alpha\in V_1\cap V_1^\perp$, 则$(\alpha,\alpha)=0$, 由内积的正定性可得$\alpha=\theta$, 因此$V_1\cap V_1^\perp=\{\theta\}$

又$V_1+V_1^\perp\subseteq V$, $\dim V_1+\dim V_1^\perp=\dim V$

因此$V=V_1\oplus V_1^\perp$

<a href="#p-t-4-1" id="end-t-4-1">$\Box$</a>

有了这个定理, 我们就可在 Euclid 空间定义正射影了

> **定义** 正射影
>
> 令$V$为一$n$维 Euclid 空间, $V_1\leqslant V$, 则$\forall\alpha\in V_1,~\alpha$均有唯一分解
> $$\alpha=\alpha_1+\alpha_2,~\alpha_1\in V_1,\alpha_2\in V_1^\perp$$
> 称$\alpha_1$为$\alpha$在$V_1$上的**正射影**

### 向量到子空间的距离

> **定义** 向量间距离
>
> 令$V$为一$n$维 Euclid 空间, $\alpha,\beta\in V$, 称$d(\alpha,\beta):=|\alpha-\beta|$为$\alpha$与$\beta$的**距离**

类似在直观几何空间中的距离, Euclid 空间中的距离也有如下性质

- $(\forall\alpha,\beta\in V),~d(\alpha,\beta)=d(\beta,\alpha)$
- $(\forall\alpha,\beta\in V),~d(\alpha,\beta)\geqslant0$, 等号成立当且仅当$\alpha=\beta$
- $(\forall\alpha,\beta,\gamma\in V),~d(\alpha,\beta)\leqslant d(\alpha,\gamma)+d(\beta,\gamma)$ (三角不等式)

在三维直观几何空间中, 一点到一平面的最短距离即是该点到垂足的连线, 在 Euclid 空间中表现为

#### <a href="#end-t-4-2" id="t-4-2">定理 - 4-2</a>

令$V$为一$n$维 Euclid 空间, $V_1\leqslant V,\alpha\in V$, $\alpha_1\in V_1$为$\alpha$在$V_1$上的正射影, 则
$$(\forall\beta\in V_1,\beta\ne\alpha_1),~d(\alpha,\alpha_1)<d(\alpha,\beta)$$

##### <a href="#t-4-2" id="p-t-4-2">证明</a>

$\alpha-\beta=(\alpha-\alpha_1)+(\alpha_1-\beta),~\alpha_1-\beta\in V_1,\alpha-\alpha_1\in V_1^\perp$  
故$|\alpha-\beta|^2=|\alpha-\alpha_1|^2+|\alpha_1-\beta|^2$

由$|\alpha_1-\beta|^2>0$可知$|\alpha-\beta|^2>|\alpha-\alpha_1|^2$

因此$d(\alpha,\alpha_1)<d(\alpha,\beta)$

<a href="#p-t-4-2" id="end-t-4-2">$\Box$</a>

因此, 我们可在 Euclid 空间下定义向量到子空间的距离

> **定义** 向量到子空间的距离
>
> 假设如 <a href="#t-4-2">定理 - 4-2</a>, 称$d(\alpha,\alpha_1)$为$\alpha$到$V_1$的**距离**

---

我们要求向量到子空间的距离, 只需要求向量到正射影的距离即可

接下来将会给出正射影的求法

首先我们需要定义一个特殊矩阵

> **定义** Gram 矩阵
>
> 令$V$为一$n$维 Euclid 空间, $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}\in V$, 称
> $$((\alpha_i,\alpha_j))_{m\times m}$$
> 为$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$的**Gram 矩阵**, 记作$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})$

接下来我们就可以给出做法了

#### <a href="#end-t-4-3" id="t-4-3">定理 - 4-3</a>

令$V$为一$n$维 Euclid 空间, $V_1=G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}]\leqslant V$, $\alpha\in V$, $X=(\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{m})^T\in\R^m$

则
$$\gamma=(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})X=\sum_{i=1}^mx_i\alpha_i\tag{4-3.1}$$
为$\alpha$在$V_1$上的正射影当且仅当  
$$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})X=(\def\enum#1{(\alpha,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{m})^T\tag{4-3.2}$$

##### <a href="#t-4-3" id="p-t-4-3">证明</a>

显然$\alpha$的正射影$\gamma$一定存在, 则

$$
\begin{aligned}
  (\text{4-3.1})&\iff \left(\alpha-\sum_{i=1}^mx_i\alpha_i\right)\in V_1^\perp\\
  &\iff 0=(\alpha_j,\alpha-\sum_{i=1}^mx_i\alpha_i)=(\alpha,\alpha_j)-\sum_{i=1}^mx_i(\alpha_j,\alpha_i),~j=1,2,...,m\\
  &\iff G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})X=(\def\enum#1{(\alpha,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{m})^T
\end{aligned}
$$

<a href="#p-t-4-3" id="end-t-4-3">$\Box$</a>

这里补充一点, <a href="#t-4-3">定理 - 4-3</a> 条件里并未限制$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性无关

- 若$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性无关, 则$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})$即为内积在$V_1$的度量矩阵, 则$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})$是正交矩阵, $|G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})|\ne0$, 因此方程$(\text{4-3.2})$的解唯一
  - 若$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$是一组标准正交基, 则$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})=E$, 此时
    $$X=(\def\enum#1{(\alpha,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{m})^T$$
- 若$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性相关, 则$X$的解显然不唯一

### 最小二乘法

这是个很有用的理论, 不过放到这有点突兀, 姑且当作前面内容的应用吧

在实际应用中, 线性方程组$AX=B,~A\in\R^{m\times n}$由于测量精度等原因往往无解, 即
$$\sum_{i=1}^n(b_1-\sum_{j=1}^na_{ij}x_j)^2\ne0\tag{4.1}$$
此时, 我们则需要寻找一组实数$\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$使得式$(4.1)$左端的值最小  
这样的$\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$即为$AX=B$的**最小二乘解**

下面我们将在$m$维 Euclid 空间讨论该问题

将$A$按列分块, $A=(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}),~\alpha_i\in\R^m,i=1,2,...,n$

有
$$AX=\sum_{i=1}^nx_i\alpha_i\in G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}]\leqslant\R^m$$

而式$(4.1)$左端用内积的语言描述即为
$$(B-\sum_{i=1}^nx_i\alpha_i,B-\sum_{i=1}^nx_i\alpha_i)=|B-\sum_{i=1}^nx_i\alpha_i|^2\tag{4.2}$$

要使式$(4.2)$的值最小, 只需$d(B,\sum_{i=1}^nx_i\alpha_i)$最小

此时取的$\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$即要使$\sum_{i=1}^nx_i\alpha_i$为$B$在$G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}]$的正射影

这样的$\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$是且仅是
$$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})X=(\def\enum#1{(B,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{n})^T\tag{4.3}$$
的解

又
$$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})=A^TA$$
$$(\def\enum#1{(B,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{n})^T=A^TB$$

因此式$(4.3)$即为
$$A^TAX=A^TB\tag{4.4}$$

由正射影的存在性可知该方程一定可解, 其解为$X=(A^TA)^{-1}A^TB$

$(4.4)$的可解性也可通过$\operatorname{rk}(A^TA)=\operatorname{rk}((A^TA,A^TB))$推得  
(注意到$\forall A\in\R^{m\times n},AX=0$与$A^TAX=0$同解)

### 习题

#### <a href="#end-prob-4-1" id="prob-4-1">习题 - 4-1</a>

令$V$为一$n$维 Euclid 空间, $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}\in V$, 证明:  
$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性无关当且仅当$|G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})|\ne0$

##### <a href="#prob-4-1" id="p-prob-4-1">解</a>

- $\impliedby$:

  设$\displaystyle\sum_{i=1}^nk_i\alpha_i=\theta$

  则$\displaystyle\sum_{i=1}^nk_i(\alpha_j,\alpha_i)=0,~j=1,2,...,n$

  即
  $$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})(\def\enum#1{k_{ #1}}\enum{1},\enum{2},...,\enum{n})^T=O\tag{4-1.1}$$

  由$|G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})|\ne0$知该方程只有零解

  故$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m}$线性无关

- $\implies$:

  假设$|G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})|=0$, 则方程$(\text{4-1.1})$有非零解

  即$(\sum_{i=1}^nk_i\alpha_i,\alpha_j)=0,~j=1,2,...,n$

  可得$(\sum_{i=1}^nk_i\alpha_i,\sum_{i=1}^nk_i\alpha_i)=0$

  因此$\sum_{i=1}^nk_i\alpha_i=0$, 与条件矛盾

<a href="#p-prob-4-1" id="end-prob-4-1">$\Box$</a>

---

## 参考资料

- 高等代数教程/郭聿琦, 岑嘉评, 王正攀编著. ——北京: 科学出版社, 2014. 7
