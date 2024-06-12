---
title: 数值分析实验 - Hamming 级数求和
categories:
  - 笔记
  - 数学
  - 数值分析
  - 实验报告
tags:
  - 笔记
  - 数学
  - 数值分析
  - 实验报告
  - MATLAB
  - C++
  - Hamming级数
  - 递推
date: 2021-04-16 20:30:47
---

数值分析实验 1 - Hamming 级数求和

<!-- more -->

## 实验要求

令

$$
\psi(x)=\sum_{k=1}^{\infty}\frac{1}{k(k+x)}\tag{1}
$$

取 $x=0.0,~0.1,~0.2~,...,300.0$, 计算在这 $3001$ 个值下所有的 $\psi(x)$, 并将误差控制在 $1.0\rm{e-}10$ 范围

## 分析

直接计算的耗时往往过长 (见 <a href="#exp1-1">直接计算的误差及复杂度分析</a>), 故需要进行优化

本文给出了一种将绝大多数数据通过线性递推计算, 从而以极快的运算速度完成运算的算法

## 计算公式

注意到

- $$
  \psi(0)=\sum_{k=1}^{\infty}\frac{1}{k^2}=\frac{\pi^2}{6}\tag{2}
  $$
- 当 $x\ne0$ 时

  $$
  \psi(x)=\sum_{k=1}^{\infty}\frac{1}{k(k+x)}=\frac{1}{x}\sum_{k=1}^{\infty}\left(\frac{1}{k}-\frac{1}{k+x}\right)\tag{3}
  $$

  注意到, 当 $x\geqslant1$ 时

  $$
  \begin{aligned}
    x~\psi(x)&=\sum_{k=1}^{\infty}\frac{1}{k}-\sum_{k=1}^{\infty}\frac{1}{k+x}\\
    &=\sum_{k=1}^{\infty}\frac{1}{k}-\sum_{k=1}^{\infty}\frac{1}{k+x-1}+\frac{1}{x}\\
    &=(x-1)~\psi(x-1)+\frac{1}{x}
  \end{aligned}
  $$

  则有

  $$
  \psi(x)=\frac{x-1}{x}\psi(x-1)+\frac{1}{x^2}\tag{4}
  $$

对于 $0<x<1$ 的点, 我们这样考虑

注意到

$$
\sum_{k=a+1}^{\infty}\frac{1}{k^m}<\int_a^{\infty}{\mathrm{d}k\over k^m}\tag{5}
$$

我们需要取满足

$$
\int_a^{\infty}{\mathrm{d}k\over k^m}\leqslant\epsilon=10^{-10}\tag{6}
$$

的最小 $a$ 值, 且让其尽可能小 (至少小于 $10^7$)

容易解得

$$
a\geqslant(\epsilon(m-1))^\frac{1}{1-m}=\sqrt[m-1]{10^{10}\over m-1},\qquad m>1\tag{7}
$$

当 $m=3$ 时, $a\geqslant 7.0711\times10^4$

这启发我们应尝试将级数 $\psi(x)$ 分母项的次数升高到 $3$ 次

注意到

- $$
  \psi(1)=\sum_{k=1}^{\infty}\frac{1}{k(k+1)}=1\tag{8}
  $$

我们设级数

$$
\psi_1(x)=\frac{\psi(x)-\psi(1)}{1-x}=\sum_{k=1}^{\infty}\frac{1}{k(k+1)(k+x)}\tag{9}
$$

则可将

$$
(1-x)\sum_{k=1}^{a_3}\frac{1}{k(k+1)(k+x)}+1\tag{10}
$$

视为 $\psi(x)$ 的近似值, 其中 $a_3\geqslant 70711$, 下面代码中取 $71000$

所以最终的计算公式如下

$$
\psi(x)=\begin{cases}
  \frac{\pi^2}{6},&x=0\\
  (1-x)\sum_{k=1}^{a_3}\frac{1}{k(k+1)(k+x)}+1,&0<x<1\\
  \frac{x-1}{x}\psi(x-1)+\frac{1}{x^2},&x\geqslant 1
\end{cases}\tag{11}
$$

时间复杂度为 $\Theta(a_3+n)$

## 程序设计

### C++ 程序

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp numanaexp-01/main.cpp %}

</details>

### MATLAB 程序

#### 主程序

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-01/main.m %}

</details>

#### 计算函数

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-01/calc_fast.m %}

</details>

#### 误差检验函数

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-01/error_judge.m %}

</details>

## 结果讨论和分析

### <a id="exp1-1">直接计算的误差及复杂度分析</a>

令

$$
\psi^*(x)=\sum_{k=1}^a\frac{1}{k(k+x)}\tag{12}
$$

注意到

- $$
  \sum_{k=a+1}^{\infty}\frac{1}{k(k+x)}<\int_a^{\infty}{\mathrm{d}k\over k(k+x)}=\frac{\ln(a+x)-\ln a}{x}\tag{13}
  $$
- $$
  \frac{\ln(a+x)-\ln a}{x}\leqslant\epsilon\implies a\geqslant{x\over e^{x\epsilon}-1}\tag{14}
  $$
- 当 $x\ll\frac{1}{\epsilon}$ 时,
  $$
  {x\over e^{x\epsilon}-1}\approx\frac{1}{\epsilon}\tag{15}
  $$

> 本实验中, $x_{max}=300.0,~\epsilon=1.0\rm{e-}10$

故 $a$ 大致取 $\frac{1}{\epsilon}$ 即可保证 $\psi(x)$ 的绝对误差 $|E(\psi(x))|\leqslant\epsilon$, 实验结果也符合这一估计

则直接计算的时间复杂度为

$$
\Theta\left(\sum_{x=1}^n\left(0.1x+\frac{1}{\epsilon}\right)\right)=\Theta\left(\frac{n}{\epsilon}+n^2\right)
$$

其中

- $n$ 为 $x$ 样本点的个数, 本实验中即为 $3001$
- $\epsilon$ 为误差范围, 本实验中即为 $1.0\rm{e-}10$

可以发现, 由于 $\epsilon$ 很小, 所以直接计算的耗时会很长. 在每秒执行 $1\rm{e}8$ 次运算的计算机上预计花费一天多的时间才能完成计算

### 进一步的优化方案

- 通过提高 $m$ 来减小 $a$
  我们知道, 在满足误差要求的条件下, $a$ 和 $m$ 满足如下关系(即式 $(7)$):

  $$
  a\geqslant\sqrt[1-m]{\epsilon(m-1)}=\sqrt[m-1]{10^{10}\over m-1},\qquad m>1
  $$

  容易得知, $f(x)=\sqrt[1-m]{\epsilon(m-1)},~(m>1)$ 是严格递减的凸函数, 且有下表

  | $m$ | $\lceil f(m)\rceil$ | $m\lceil f(m)\rceil$ |
  | --- | ------------------- | -------------------- |
  | $2$ | $10^{10}$           | $2\times 10^{10}$    |
  | $3$ | $70711$             | $212133$             |
  | $4$ | $1494$              | $5976$               |
  | $5$ | $224$               | $1120$               |
  | $6$ | $73$                | $438$                |
  | $7$ | $35$                | $245$                |
  | $8$ | $21$                | $168$                |

  由于计算每个数的时候都会做至少 $m\lceil f(m)\rceil$ 次乘法, 且考虑累计误差的影响, 我们只考虑 $m=4$ 的情况

  令

  $$
  \psi_2(x)=\frac{\psi_1(x)-\psi_1(2)}{2-x}\tag{16}
  $$

  由式 $(9)$, 有

  $$
  \psi_2(x)=\sum_{k=1}^{\infty}\frac{1}{k(k+1)(k+2)(k+x)}\tag{17}
  $$

  则可将

  $$
  (1-x)\left((2-x)\sum_{k=1}^{a_4}\frac{1}{k(k+1)(k+2)(k+x)}+\frac{1}{4}\right)+1\tag{18}
  $$

  视为 $\psi(x)$ 的近似值, 其中 $a_4\geqslant 1494$, 推荐取 $1500$
