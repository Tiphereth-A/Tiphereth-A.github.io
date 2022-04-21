---
title: 笔记 - 线性空间
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
  - 线性同构
  - 直和
  - Vandermonde行列式
date: 2020-05-27 20:37:42
---
线性空间是基于集合的, 在集合的基础上又额外规定了各元素之间的关系

<!-- more -->

## 线性空间

### 定义

概括起来就是: 两个封闭, 八条法则

称代数系统$(V,+,\cdot,\mathbb{P})$(或者记成$(V,\oplus,\odot,\mathbb{P})$)为$V$关于$+,\cdot$构成$\mathbb{P}$上的线性空间, 当

1. 两种运算的封闭性
   1. $(\forall\alpha,\beta\in V),\alpha+\beta\in V$
   1. $(\forall\alpha\in V,k\in\mathbb{P}),k\alpha\in V$
1. 加法交换律: $(\forall\alpha,\beta\in V),\alpha+\beta=\beta+\alpha$
1. 加法结合律: $(\forall\alpha,\beta,\gamma\in V),(\alpha+\beta)+\gamma=\alpha+(\beta+\gamma)$
1. "零元": $(\exist\theta\in V,\forall\alpha\in V),\alpha+\theta=\alpha$
1. "逆元": $(\forall\alpha\in V,\exist-\alpha\in V),\alpha+(-\alpha)=\theta$
1. 数乘与加法的分配律(2条):
   1. 左:  
   $(\forall\alpha,\beta\in V,k\in\mathbb{P}),k\cdot(\alpha+\beta)=k\cdot\alpha+k\cdot\beta$
   1. 右:  
   $(\forall\alpha\in V,k,l\in\mathbb{P}),(k+l)\cdot\alpha=k\cdot\alpha+l\cdot\alpha$
1. 数乘结合律: $(\forall\alpha\in V,k,l\in\mathbb{P}),(kl)\cdot\alpha=k\cdot(l\cdot\alpha)$
1. "幺元": $(\exist 1\in\mathbb{P},\forall\alpha\in V),1\cdot\alpha=\alpha$

在不引起混淆的情况下可简记为$V$

### 简单性质

1. $\theta$唯一, 称其为零向量
1. $\forall\alpha\in V,-\alpha$唯一, 称其为$\alpha$的负向量
1. $(\exist0\in\mathbb{P},\forall\alpha\in V),0\alpha=\theta$
1. $(\forall k\in\mathbb{P}),k\theta=\theta$
1. $(\forall\alpha\in V),(-1)\alpha=-\alpha$
1. 无零因子: $(\forall\alpha\in V,k\in\mathbb{P}),k\alpha=\theta\implies k=0\lor\alpha=\theta$
1. 加法的消去律: $(\forall\alpha,\beta,\gamma\in V),\alpha+\beta=\alpha+\gamma\implies\beta=\gamma$

证明都是很简单的, 也很有抽象代数的味道

其中在证明某一代数系统为线性空间时, <u>加法的消去律可用来替代存在零向量和存在负向量两条条件</u>

简单说说消去律是怎么推出后者的

> 首先, 我们有$(\forall\alpha,\beta\in V),0\alpha+\alpha=(0+1)\alpha=1\alpha=\alpha,0\beta+\beta=\beta$
>
> 可推出$0\alpha+(\alpha+\beta)=\alpha+\beta,0\beta+(\alpha+\beta)=\beta+\alpha=\alpha+\beta$
>
> 即$0\alpha+(\alpha+\beta)=0\beta+(\alpha+\beta)$
>
> 从而$(\forall\alpha,\beta\in V),0\alpha=0\beta=:\theta$
>
> 此时$\theta$即为零向量
>
> 又$(\forall\alpha\in V),\alpha+(-1)\alpha=(1+(-1))\alpha=0\alpha=\theta$
>
> 故任意向量均存在负向量

另外一些零碎的定义, 如$G[\def\enum#1{\alpha_#1}\enum{1},\enum{2},...,\enum{n}]$就略去了

### 例子

1. $\mathbb{P}$上的$n$维向量对于向量的加法和$\mathbb{P}$中的数乘
1. $\mathbb{P}$上的$m\times n$矩阵对于矩阵的加法和$\mathbb{P}$中的数乘
1. 代数系统$(\mathbb{P}^2,\oplus,\odot,\mathbb{P})$, 其中
   - $(\forall(x_1,x_2),(y_1,y_2)\in\mathbb{P}^2),(x_1,x_2)\oplus(y_1,y_2):=(x_1+y_1,x_2+y_2+x_1y_1)$
   - $(\forall(x_1,x_2)\in\mathbb{P}^2,k\in\mathbb{P}),k\odot(x_1,x_2):=\left(kx_1,kx_2+\frac{k(k-1)}{2}x_1^2\right)$
  
   (没错这个真的是个线性空间)
1. 区间$[a,b]$上全体连续函数$C[a,b]$关于连续函数的加法和数与连续函数的数乘
1. 线性空间$V$上的全体线性变换$L(V)$关于线性变换的加法和数与线性变换的数乘

## 线性子空间

线性空间是基于集合的, 自然也会继承集合的许多概念, 当然这些概念需要重定义一下

### 定义

对于线性空间$V$, 称$V_1$为$V$的线性子空间, 若$\varnothing\ne V_1\subseteq V$(注意此处的$V$是集合), 同时$V_1$关于$\oplus,\odot$($V$构成$\mathbb{P}$上线性空间的两种合成)构成$\mathbb{P}$上的线性空间

简称为子空间, 记作$V_1\leqslant V$

如果把上述定义中的$\subseteq$换成$\subsetneqq$, 则可得到真子空间的定义, 记作$V_1<V$

注意子空间一定是**非空**的, 因为最小的线性空间是$\{\theta\}$

### <a href="#end-t-2-2-1" id="t-2-2-1">定理 - 2-1</a>(子空间判定定理)

令$V_1$为以线性空间的**非空**子集, 则$V_1$为$V$的子空间当且仅当加法和数乘封闭, 即

1. $(\forall\alpha,\beta\in V_1),\alpha+\beta\in V_1$
1. $(\forall\alpha\in V_1,k\in\mathbb{P}),k\alpha\in V_1$

证明很简单就省略了

<a href="#t-2-2-1" id="end-t-2-2-1">$\Box$</a>

### 子空间的交, 和与直和

类似集合的交, 我们可定义子空间的交为$V_1\cap V_2$, 显然其为$V_1,V_2$所有公共子空间的**最大子空间**

不过$V_1\cup V_2$就不一定是子空间了, $V_1\cup V_2$是子空间当且仅当$V_1\subseteq V_2$或$V_2\subseteq V_1$

子空间的和是这样定义的: $V_1+V_2:=\{\alpha_1+\alpha_2|\alpha_1\in V_1,\alpha_2\in V_2\}$, 显然这样定义出来的仍是子空间, 显然其为所有包含$V_1,V_2$的子空间中的**最小子空间**

进一步, 子空间的直和要求集合中所有元素的$\alpha_1,\alpha_2$的选取是**唯一**的, 记作$V_1\oplus V_2$ (我的课本上记作$V_1\dotplus V_2$, 不过$\dotplus$的辨识度太低, 所以我不是很喜欢这种写法)

正如集合的并和交可以推广到多个集合间, 子空间的并, 和与直和也是可以的

### <a href="#end-t-2-2" id="t-2-2">定理 - 2-2</a>(直和判定定理)

令$V$为线性空间, $V_1,V_2\leqslant V$, 则下列诸款等价:

1. $V_1+V_2$是直和
1. $V_1+V_2$中存在以向量$\beta$, 使得拆分为$V_1$和$V_2$中的向量和的方式唯一 (任意$\to$存在)
1. $\theta$拆分为$V_1$和$V_2$中的向量和的方式唯一
1. $V_1\cap V_2=\{\theta\}$
1. $\dim V_1+\dim V_2=\dim(V_1+V_2)$
1. 若$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m})$是$V_1$的一组基, $(\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n})$是$V_2$的一组基,  
则$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{m},\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n})$是$V_1+V_2$的一组基

#### <a href="#t-2-2" id="p-t-2-2">证明</a>

$1\implies2$, 显然

$2\implies3$,

令$\beta=\beta_1+\beta_2,\beta_1\in V_1,\beta_2\in V_2$, 若$\theta=\alpha_1+\alpha_2,~\alpha_1\ne\theta,\alpha_1\in V_1,\alpha_2\in V_2$, 则

$$\beta=\beta+\theta=(\beta_1+\alpha_1)+(\beta_2+\alpha_2)$$

而$\beta_1\ne\beta_1+\alpha_1$, 与条件矛盾

$3\implies4$,

令$\theta\ne\alpha\in V_1\cap V_2$, 则$\theta=\alpha+(-\alpha)$, 与条件矛盾

$4\implies1$,

若$V_1+V_2$不是直和, 则存在$\beta\in V_1+V_2$使得$\beta=\beta_1+\beta_2=\gamma_1+\gamma_2$,  
其中$\beta_1,\gamma_1\in V_1,\beta_2,\gamma_2\in V_2,(\beta_1,\beta_2)\ne(\gamma_1,\gamma_2)$

则

$$\theta\ne\beta_1-\gamma_1=\gamma_2-\beta_2\in V_1\cap V_2$$

与条件矛盾

1, 5, 6之间关系可由 <a href="#t-3-1">定理 - 3-1</a> 直接推得

<a href="#p-t-2-2" id="end-t-2-2">$\Box$</a>

实际证明$V=V_1\oplus V_2$时往往分为如下步骤:

1. 证明$V=V_1+V_2$, 多用双包含法证明
1. 证明$V_1+V_2$是直和

直和其实很有用, 它是研究线性空间结构的有力工具之一

## 基底, 维数, 坐标

基底也是研究线性空间结构的有力工具之一

本篇文章只讨论有限维的线性空间

### (有限)生成集与维数

令$V$为$\mathbb{P}$上一线性空间, $\varnothing\ne S\subseteq V$, 称$S$为$V$的生成集, 如果
$$(\forall\alpha\in V,\exist n\in\N^+,\def\enum#1{\alpha_#1}\enum{1},\enum{2},...,\enum{n}\in S,\def\enum#1{k_#1}\enum{1},\enum{2},...,\enum{n}\in\mathbb{P}),\alpha=\displaystyle\sum_{i=1}^nk_i\alpha_i$$

(就是能线性表出$V$中任意向量的一组向量)

$\operatorname{rk}S$即为$V$的维数, 记作$\dim V$

具有有限生成集的线性空间为**有限维**的线性空间

显然, $V$的一组**极大线性无关组含向量数**即为$V$的维数

### 基底与坐标

令$V$为$\mathbb{P}$上一线性空间, $\def\enum#1{\epsilon_#1}\enum{1},\enum{2},...,\enum{n}$为$V$的一组极大线性无关组, 则

$$(\forall\alpha\in V,\exist\def\enum#1{k_#1}\enum{1},\enum{2},...,\enum{n}\in\mathbb{P}),\alpha=\displaystyle\sum_{i=1}^nk_i\epsilon_i$$

则称有序向量组$(\def\enum#1{\epsilon_#1}\enum{1},\enum{2},...,\enum{n})$为$V$的一组基底

$(\def\enum#1{k_#1}\enum{1},\enum{2},...,\enum{n})\in\mathbb{P}^n$为$\alpha$在该基底下的坐标

显然基底有无穷多组

显然$n$维线性空间$V$中任意$n$个线性无关向量组均可构成一组基底

### 例子

1. $\mathbb{P}[x]$即为无限维的
1. $\{\theta\}$为0维的, 称作**平凡线性空间**
1. 对于$n$维线性空间$\mathbb{P}_n[x]$中向量$\alpha=f(x)=\displaystyle\sum_{i=0}^{n-1}a_ix^i$

   显然$(1,\def\enum#1{x^{ #1}}\enum{1},\enum{2},...,\enum{n-1})$为一组基底, 对应的坐标为$(a_0,\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n-1})$

   又由Taylor公式可得$f(x)=\displaystyle\sum_{i=0}^{n-1}{f^{(i)}(a)\over i!}(x-a)^i$

   故$\left(1,x-a,\def\enum#1{(x-a)^{ #1}}\enum{2},...,\enum{n-1}\right)$为一组基底, 对应的坐标为$(f(a),f'(a),...,{f^{(n-1)}(a)\over(n-1)!})$, 当$a=0$时, 即为前述情况

### <a href="#end-t-3-1" id="t-3-1">定理 - 3-1</a>**(维数公式)**

令$V$为有限维线性空间, $V_1,V_2\leqslant V$, 则

$$\dim(V_1+V_2)+\dim(V_1\cap V_2)=\dim V_1+\dim V_2$$

#### <a href="#t-3-1" id="p-t-3-1">证明</a>

令$\dim V_1=n_1,\dim V_2=n_2,\dim(V_1\cap V_2)=l$, 只需证$\dim(V_1+V_2)=n_1+n_2-l$

取$V_1\cap V_2$中一组基$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l})$, 其可在$V_1,V_2$中分别扩充为  
$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l},\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n_1-l}),(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l},\def\enum#1{\gamma_{ #1}}\enum{1},\enum{2},...,\enum{n_2-l})$

如果$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l},\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n_1-l},\def\enum#1{\gamma_{ #1}}\enum{1},\enum{2},...,\enum{n_2-l})$为$V_1+V_2$的一组基, 则命题得证

显然$V_1+V_2=G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l},\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n_1-l},\def\enum#1{\gamma_{ #1}}\enum{1},\enum{2},...,\enum{n_2-l}]$

则只需证明$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l},\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n_1-l},\def\enum#1{\gamma_{ #1}}\enum{1},\enum{2},...,\enum{n_2-l}$线性无关即可

考虑$\displaystyle\sum_{i=1}^lk_i\alpha_i+\sum_{i=1}^{n_1-l}p_i\beta_i+\sum_{i=1}^{n_2-l}q_i\gamma_i=\theta$

则$\displaystyle\sum_{i=1}^lk_i\alpha_i+\sum_{i=1}^{n_1-l}p_i\beta_i=\sum_{i=1}^{n_2-l}(-q_i)\gamma_i=:\alpha$

可知等式左端$\in V_1$, 右端$\in V_2$, 故$\alpha\in V_1\cap V_2$

$\alpha$可写成$\displaystyle\sum_{i=1}^lr_i\alpha_i$

则  
$\displaystyle\sum_{i=1}^lr_i\alpha_i+\sum_{i=1}^{n_2-l}q_i\gamma_i=\theta\implies r_i=q_j=0,~i=1,2,...,l;j=1,2,...,n_2-l$

此式说明$\alpha=\theta$, 故$k_i=p_j=0,~i=1,2,...,l;j=1,2,...,n_1-l$

因此$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{l},\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n_1-l},\def\enum#1{\gamma_{ #1}}\enum{1},\enum{2},...,\enum{n_2-l}$线性无关

<a href="#p-t-3-1" id="end-t-3-1">$\Box$</a>

这个公式很重要

### 例题

#### <a href="#end-prob-3-1" id="prob-3-1">习题 - 3-1</a>

令$W$是$\mathbb{P}$上的$n$维线性空间$\mathbb{P}^n$的非平凡子空间, 证明:  
若关于$W$的每个向量$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})$均或者$\def\enum#1{\alpha_{ #1}}\enum{1}=\enum{2}=...=\enum{n}=0$, 或者$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}\ne0$, 则$\dim W=1$

##### <a href="#prob-3-1" id="p-prob-3-1">解</a>

假设$\dim W\geqslant2$, 则$W$中存在两线性无关向量$\alpha=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}),\beta=(\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{n})$满足

$$(\exist1<i\leqslant n),k:=\frac{a_1}{b_1}\ne\frac{a_i}{b_i}$$

从而$\alpha-k\beta=(0,...,a_i-kb_i,...,a_n-kb_n)\in W, a_i-kb_i\ne0$, 矛盾!

故$\dim W=1$

<a href="#p-prob-3-1" id="end-prob-3-1">$\Box$</a>

#### <a href="#end-prob-3-2" id="prob-3-2">习题 - 3-2</a>

证明:  
$W=\{f(x)\in\R[x]|f(1)=0;\partial f(x)\leqslant n~or~f(x)=0\}$
为$\R$上线性空间, 并求出其一组基底

##### <a href="#prob-3-2" id="p-prob-3-2">解</a>

容易验证$W$为$\R$上线性空间

$(\forall f(x)=\displaystyle\sum_{i=0}^na_ix^i\in W),f(1)=0\implies a_0=-\sum_{i=1}^na_i\implies f(x)=\sum_{i=1}^na_i(x^i-1)$

又 $\displaystyle\sum_{i=1}^nk_i(x^i-1)=0\implies k_1=k_2=...=k_n=0$

故 $(x-1,\def\enum#1{x^{ #1}-1}\enum{2},...,\enum{n})$即为$W$上的一组基底

<a href="#p-prob-3-2" id="end-prob-3-2">$\Box$</a>

## 坐标变换

同一个线性空间有多组基, 一组基中的所有向量能被另一组基线性表出, 本节便研究向量的坐标在不同基之间的转化

### 类矩阵

$V$的一组基底$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$被称作**类矩阵**, 因为其一些性质与矩阵类似

1. 分配律:
   1. 左:  
   $(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})A+(\def\enum#1{\beta_{ #1}}\enum{1},\enum{2},...,\enum{n})A=(\def\enum#1{\alpha_{ #1}+\beta_{ #1}}\enum{1},\enum{2},...,\enum{n})A$
   1. 右:  
   $(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})A+(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})B=(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})(A+B)$
1. 数乘的交换律: $k(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})A=(\def\enum#1{k\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})A=(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})(kA)$
1. 矩阵乘法的结合律: $[(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})A]B=(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})AB$

但由于线性空间的向量不一定是列向量, 故类矩阵不一定能看作矩阵分块

有了类矩阵的概念, 我们就可以得到向量的另一种记法

设向量$\alpha$在$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的坐标为$(\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 则$\alpha$可记作

$$\alpha=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})\begin{bmatrix}
   x_1\\x_2\\\vdots\\x_n
\end{bmatrix}$$

### 过渡矩阵

设$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$和$(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$是$V$的两组基底, 则$\exist T\in\mathbb{P}^{n\times n}$使得

$$(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})T\tag{1}$$

则称$T$为$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$到$(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$的过渡矩阵

显然, $T$是可逆的, 否则$(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$线性相关

### 坐标变换

设向量$\alpha$在$(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n}),(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$下的坐标分别为$(\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}),(\def\enum#1{x'_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 则

$$\begin{aligned}
   \alpha=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})\begin{bmatrix}
      x_1\\x_2\\\vdots\\x_n
   \end{bmatrix}&=(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})\begin{bmatrix}
      x'_1\\x'_2\\\vdots\\x'_n
   \end{bmatrix}\\
   &=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})T\begin{bmatrix}
      x'_1\\x'_2\\\vdots\\x'_n
   \end{bmatrix}\\
   &=(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})(T\begin{bmatrix}
      x'_1\\x'_2\\\vdots\\x'_n
   \end{bmatrix})
\end{aligned}$$

故

$$\begin{bmatrix}
      x_1\\x_2\\\vdots\\x_n
   \end{bmatrix}=T\begin{bmatrix}
      x'_1\\x'_2\\\vdots\\x'_n
   \end{bmatrix}
$$

此即为$\alpha$的坐标变换公式

(在之后的笔记中我们可以看到, $T$对应一个线性变换$\bold{T}$)

### 过渡矩阵的求法

1. 定义
1. 若线性空间为$\mathbb{P}^n$, 则类矩阵即为矩阵, 式(1)即为$B=AT$, 则$T=A^{-1}B$
1. 若已知$n$个线性无关向量$\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}$在两基底下的坐标, 则求法同上

## (线性)同构

同构自然也是研究线性空间结构的有力工具之一

如果两套代数系统同构, 那么两者的许多基于运算的性质就都是相通的了

线性空间上的同构定义与通常意义上的同构定义一致, 即  
称两线性空间$V_1$与$V_2$同构, 若存在**双射**$f:V_1\to V_2$满足

1. $(\forall\alpha,\beta\in V_1,k,l\in\mathbb{P}),f(k\alpha+l\beta)=kf(\alpha)+lf(\beta)$

   (即保持加法和数乘)

称上述$f$为同构映射, 记$V_1$与$V_2$同构为$V_1\cong V_2$

容易证明同构是**等价关系**, 即满足自反性, 对称性, 传递性

证明两线性空间同构即寻找同构映射

我们有一个很重要的定理

### <a id="t-5-1">定理 - 5-1</a>

设$V$为在$\mathbb{P}$上的$n$维线性空间, 则 $V\cong\mathbb{P}^n$

这也正好说明了我们把线性空间中的元素称为向量的合理性

这个同构映射很好构造, 证明就略去了

由此我们可以得到一条重要推论

### <a id="ifr-5-1">推论 - 5-1</a>

$\mathbb{P}$上线性空间$V_1,V_2$同构$\iff\dim V_1=\dim V_2$

### 例题

#### <a href="#end-prob-5-1" id="prob-5-1">习题 - 5-1</a>

设$V$为$n$维线性空间, 证明:  
存在$V$的无限子集$S$, 使得$S$中任意$n$个向量是线性无关的

##### <a href="#prob-5-1" id="p-prob-5-1">解</a>

这类题往往可以通过$V$与$\mathbb{P}^n$同构并利用Vandermonde行列式等解决

注意到 $\mathbb{P}^n$中形如

$$(1,a,a^2,...,a^{n-1}),a\in\N^*$$

的向量有无限个

这些向量中的任意$n$个均可构成非0的Vandermonde行列式, 故这些向量线性无关

又由$n$维线性空间与$\mathbb{P}^n$同构可知命题成立

<a href="#p-prob-5-1" id="end-prob-5-1">$\Box$</a>

#### <a href="#end-prob-5-2-2" id="prob-5-2">习题 - 5-2</a>

设$V$为$n$维线性空间, 证明:  
若$V_i<V,~i=1,2,...,m$, 则存在$\alpha\in V$使得$\alpha\notin V_i,~i=1,2,...,m$

本题给出两种证明方法, 以凸显同构的强大之处

##### <a href="#prob-5-2" id="p-prob-5-2-1">解 - 1</a>(数学归纳法)

- 当$m=1$时, 命题显然成立
- 当$m=2$时, 取$\alpha\in V/V_1$, 若$\alpha\notin V_2$, 则命题成立, 否则$\exist\beta\in V/V_2$

   可知$k\alpha+\beta\notin V_2,\forall k\in\mathbb{P}$, 否则可推出$(k\alpha+\beta)-k\alpha=\beta\in V_2$

   取$k_1,k_2\in\mathbb{P},k_1\ne k_2$

   则$k_1\alpha+\beta\in V_1$和$k_2\alpha+\beta\in V_1$不同时成立, 否则可推出  
   $(k_1\alpha+\beta)-(k_2\alpha+\beta)=(k_1-k_2)\alpha\in V_1$

   因此当$m=2$时命题成立

- 假设$m-1$时命题成立, 则$(\exist\alpha\in V),\alpha\notin V_i,i=1,2,...,m-1$, 若$\alpha\notin V_m$, 则命题成立, 否则$\exist\beta\in V/V_m$

   可知$k\alpha+\beta\notin V_m,\forall k\in\mathbb{P}$, 否则可推出$(k\alpha+\beta)-k\alpha=\beta\in V_m$

   取$k_1,k_2\in\mathbb{P},k_1\ne k_2$

   则$k_1\alpha+\beta\in V_i$和$k_2\alpha+\beta\in V_i$不同时成立, $(i=1,2,...,m-1)$, 否则可推出$(k_1\alpha+\beta)-(k_2\alpha+\beta)=(k_1-k_2)\alpha\in V_i$

   此时取$m$个不相等的数$k_1,k_2,...,k_m$, 可知  
   $(\exist k\in\{k_1,k_2,...,k_m\}),k\alpha+\beta\notin V_i,i=1,2,...,m-1$, 又由$k\alpha+\beta\notin V_m$可知该向量即为所求

<a href="#p-prob-5-2-1" id="end-prob-5-2-1">$\Box$</a>

##### <a href="#prob-5-2" id="p-prob-5-2-2">解 - 2</a>(同构)

注意到 $\mathbb{P}^n$中形如

$$(1,a,a^2,...,a^{n-1}),a\in\N^*$$

的向量有无限个

这些向量中的任意$n$个均可构成非0的Vandermonde行列式, 故这些向量线性无关

而$\def\enum#1{V_{ #1}}\enum{1},\enum{2},...,\enum{s}$最多只需使用其中$m(n-1)$个向量张成, 故在$V$中总能找到满足要求的向量

<a href="#p-prob-5-2-2" id="end-prob-5-2-2">$\Box$</a>

## 线性方程组的解空间

如果线性方程组为**齐次线性方程组**, 则其解构成一线性空间, 我们把它称作**解空间**, 反之不然

这个结论是显然的

进一步, 我们有如下定理:

### <a href="#end-t-6-1" id="t-6-1">定理 - 6-1</a>

对于$\mathbb{P}^n$上的任意$t$维子空间$S_0$, 均存在齐次线性方程组, 使得其解空间恰为$S_0$

(全体齐次线性方程组与全体线性子空间构成满同态)

#### <a href="#t-6-1" id="p-t-6-1">证明</a>

显然,

- 当$t=0$时, 任意满秩的$n$元齐次线性方程组均满足条件
- 当$t=n$时, 系数矩阵为$O$的$n$元齐次线性方程组满足条件

现讨论$0<t=\dim S_0<n$的情况

取$S_0$的一组基底$(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{t}),~\alpha_i=(\def\enum#1{a_{i{ #1}}}\enum{1},\enum{2},...,\enum{n}),~i=1,2,...,t$

则$\operatorname{rk}(a_{ij})_{t\times n}=t$

齐次线性方程组

$$(a_{ij})_{t\times n}\begin{bmatrix}
   x_1\\x_2\\\vdots\\x_n
\end{bmatrix}=\theta$$

有$n-t$个解$\beta_i=(\def\enum#1{b_{i{ #1}}}\enum{1},\enum{2},...,\enum{n})^T,~i=1,2,...,n-t$张成解空间

故齐次线性方程组

$$(b_{ij})_{(n-t)\times n}\begin{bmatrix}
   x_1\\x_2\\\vdots\\x_n
\end{bmatrix}=\theta$$

有$t$个解$\alpha_i=(\def\enum#1{a_{i{ #1}}}\enum{1},\enum{2},...,\enum{n}),~i=1,2,...,t$张成解空间

<a href="#p-t-6-1" id="end-t-6-1">$\Box$</a>

### 例题

#### <a href="#end-prob-6-1" id="prob-6-1">习题 - 6-1</a>

证明: $n$维线性空间的任何真子空间均可表示成若干个$n-1$维子空间的交

##### <a href="#prob-6-1" id="p-prob-6-1">解</a>

上面我们已经证明了: 对于任意$r$维子空间, 均存在系数矩阵的秩为$n-r$的齐次线性方程组, 使得其解空间恰为该子空间

特别的, 对任意$n-1$维子空间, 均存在齐次线性方程, 使得其解空间恰为该子空间

另外, 子空间的交在齐次线性方程组中即为方程组的合并

那么结论就显然成立了

<a href="#p-prob-6-1" id="end-prob-6-1">$\Box$</a>

#### <a href="#end-prob-6-2" id="prob-6-2">习题 - 6-2</a>

令$f(x),g(x)\in\mathbb{P}[x],(f(x),g(x))=1,A\in\mathbb{P}^{n\times n}$, 证明:  
齐次线性方程组$f(A)g(A)X=0$的解空间$V$是$f(A)X=0,g(A)X=0$的解空间$V_1,V_2$的直和, 其中$X=(\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n})^T$

##### <a href="#prob-6-2" id="p-prob-6-2">解</a>

- 注意到  
   $\alpha\in V_1,\beta\in V_2\implies f(A)\alpha=g(A)\beta=0\implies f(A)g(A)\alpha=f(A)g(A)\beta=0\implies\alpha,\beta\in V$

   故$V_1,V_2\leqslant V$

- 又由$(f(x),g(x)=1$知$\exist u(x),v(x)\in\mathbb{P}[x]$使得$f(A)u(A)+g(A)v(A)=E$

   则$\forall\alpha\in V,\alpha=f(A)u(A)\alpha+g(A)v(A)\alpha\xlongequal[\alpha_2=g(A)v(A)\alpha]{\alpha_1=f(A)u(A)\alpha}\alpha_1+\alpha_2$

   可得$g(A)\alpha_1=u(A)(f(A)g(A)\alpha)=0$, 故$\alpha_1\in V_2$, 同理$\alpha_2\in V_1$, 因此$V=V_1+V_2$

- 又令$\beta\in V_1\cup V_2$, 则有$f(A)\beta=g(A)\beta=0$

   于是$\beta=(f(A)u(A)+g(A)v(A))\beta=0$, 即$V_1\cup V_2=\{0\}$

   因此$V=V_1\oplus V_2$

<a href="#p-prob-6-2" id="end-prob-6-2">$\Box$</a>

---

## 参考资料

- 高等代数教程/郭聿琦, 岑嘉评, 王正攀编著. ——北京: 科学出版社, 2014. 7
