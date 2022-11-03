---
title: 随笔 - 根据给定序列构造周期数列 (附 MATLAB 程序)
categories:
  - 随笔
  - 数学
tags:
  - 数学
  - 随笔
  - 数列
  - MATLAB
  - 周期数列
  - 线性方程组
  - Vandermonde行列式
date: 2021-10-21 00:43:45
---

对于给定的一个序列 $[\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{m}]$, 如何构造数列 $\{f_n\}$ 满足 $\{f_n\}$ 为周期为 $m$ 的数列且 $f_i=a_i,~\forall i\in 1..m$

例如数列
$$\color{brown}f_n=\frac{2}{3}\left(-\sqrt{3}\sin\frac{\pi n}{3}-\cos\frac{\pi n}{3}+\sqrt{3}\sin\frac{2\pi n}{3}+2\cos\frac{2\pi n}{3}+\cos\pi n+4\right)$$

以 6 为周期且 $\color{brown}(f_1,...,f_6)=(1,1,4,5,1,4)$

<!-- more -->

## 构造方法

这里给出一种构造方法

显然 $f_n=\sum_{i=0}^{m-1}c_i\omega_m^{i(n-1)}$ 是一个周期为 $m$ 的数列, 其中 $\omega_m=e^\frac{2\pi i}{m}$ 为 $m$ 次本原单位根

接下来我们只需令 $f_{1..m}=a_{1..m}$ 即可

显然我们有

$$
\begin{bmatrix}
  1&1&1&...&1\\
  1&\omega&\omega^2&...&\omega^{m-1}\\
  1&\omega^2&\omega^4&...&\omega^{2(m-1)}\\
  \vdots&\vdots&\vdots&\ddots&\vdots\\
  1&\omega^{m-1}&\omega^{2(m-1)}&...&\omega^{(m-1)^2}\\
\end{bmatrix}\begin{bmatrix}
  c_0\\c_1\\c_2\\...\\c_{m-1}
\end{bmatrix}=\begin{bmatrix}
  a_1\\a_2\\a_3\\...\\a_m
\end{bmatrix}
$$

注意到系数矩阵为 Vandermonde 行列式, 故该方程组一定有唯一解

## MATLAB 程序

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab draft-014/cycle_sequence_generator.m %}

</details>
