---
title: 数值分析实验 - 解线性方程组的迭代法
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
  - 线性方程组
  - Jacobi迭代法
  - Gauss-Seidol迭代法
  - SOR方法
date: 2021-06-22 23:03:26
---

数值分析实验 6 - 解线性方程组的迭代法

<!-- more -->

## 目的和意义

### 问题提出

对 {% post_link numanaexp-05 %} 所列目的和意义的线性方程组, 试分别选用 Jacobi 迭代法, Gauss-Seidol 迭代法和 SOR 方法计算其解

### 要求

1. 体会迭代法求解线性方程组, 并能与消去法做以比较;
1. 分别对不同精度要求, 如 $\epsilon=10^{-3},10^{-4},10^{-5}$, 由迭代次数体会该迭代法的收敛快慢;
1. 对方程组 2, 3 使用 SOR 方法时, 选取松弛因子 $\omega=0.8, 0.9, 1, 1.1, 1.2$ 等, 试看对算法收敛性的影响, 并能找出你所选用的松弛因子的最佳者;
1. 给出各种算法的设计程序和计算结果

### 目的和意义

1. 通过上机计算体会迭代法求解线性方程组的特点, 并能和消去法比较;
1. 运用所学的迭代法算法, 解决各类线性方程组, 编出算法程序;
1. 体会上机计算时, 终止步骤 $\|x^{(k+1)}-x^{(k)}\|_{\infty}<\epsilon$ 或 $k>$ (予给的迭代次数), 对迭代法敛散性的意义;
1. 体会初始解 $x^{(0)}$, 松弛因子的选取, 对计算结果的影响

## 计算公式

令

$$
A=D-L-U
$$

其中

- $$
  D=\begin{bmatrix}
    a_{11}\\
    &a_{22}\\
    \phantom{\vdots}&&\ddots\\
    &&&a_{nn}
  \end{bmatrix}
  $$
- $$
  L=\begin{bmatrix}
    0\\
    -a_{21}&0\\
    \vdots&\vdots&\ddots\\
    -a_{n1}&-a_{n2}&\dots&0
  \end{bmatrix}
  $$
- $$
  U=\begin{bmatrix}
    0&-a_{12}&\dots&-a_{1n}\\
    &0&\dots&-a_{2n}\\
    &&\ddots&\vdots\\
    &&&0
  \end{bmatrix}
  $$

### Jacobi 迭代法

令

$$
G=D^{-1}(L+U)
$$

则

$$
x^{(k+1)}=Gx^{(k)}+D^{-1}b
$$

收敛条件为 $\rho(G)<1$

### Gauss-Seidol 迭代法

令

$$
G=(D-L)^{-1}U
$$

则

$$
x^{(k+1)}=Gx^{(k)}+(D-L)^{-1}b
$$

收敛条件为 $\rho(G)<1$

### SOR 方法

令

$$
G=(D-\omega L)^{-1}((1-\omega)D+\omega U)
$$

则

$$
x^{(k+1)}=Gx^{(k)}+\omega(D-\omega L)^{-1}b
$$

收敛条件为 $\rho(G)<1$

## 程序设计

### 主程序

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-06/main.m %}

</details>

### Jacobi 迭代法

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-06/jacobi.m %}

</details>

### Gauss-Seidol 迭代法

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-06/gauss_seidol.m %}

</details>

### SOR 方法

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-06/sor.m %}

</details>

## 结果讨论和分析

### 结果

> 方程组的解经验证符合要求, 为节省篇幅而略去

- $\epsilon=10^{-3}$ 时的迭代次数

  |                         | 方程组 1 | 方程组 2 | 方程组 3 |
  | ----------------------- | -------- | -------- | -------- |
  | Jacobi 迭代法           | 不收敛   | 不收敛   | 15       |
  | Gauss-Seidol 迭代法     | 不收敛   | 1256     | 7        |
  | SOR 方法 ($\omega=0.8$) | 不收敛   | 1895     | 10       |
  | SOR 方法 ($\omega=1.2$) | 不收敛   | 842      | 9        |

- $\epsilon=10^{-4}$ 时的迭代次数

  |                         | 方程组 1 | 方程组 2 | 方程组 3 |
  | ----------------------- | -------- | -------- | -------- |
  | Jacobi 迭代法           | 不收敛   | 不收敛   | 15       |
  | Gauss-Seidol 迭代法     | 不收敛   | 1692     | 9        |
  | SOR 方法 ($\omega=0.8$) | 不收敛   | 2551     | 13       |
  | SOR 方法 ($\omega=1.2$) | 不收敛   | 1132     | 11       |

- $\epsilon=10^{-5}$ 时的迭代次数

  |                         | 方程组 1 | 方程组 2 | 方程组 3 |
  | ----------------------- | -------- | -------- | -------- |
  | Jacobi 迭代法           | 不收敛   | 不收敛   | 15       |
  | Gauss-Seidol 迭代法     | 不收敛   | 2129     | 11       |
  | SOR 方法 ($\omega=0.8$) | 不收敛   | 3207     | 16       |
  | SOR 方法 ($\omega=1.2$) | 不收敛   | 1423     | 13       |

- SOR 方法中, 方程组 2 的迭代次数与 $\omega$ 的变化图像

  ![](2e-3.svg)
  ![](2e-4.svg)
  ![](2e-5.svg)

- SOR 方法中, 方程组 3 的迭代次数与 $\omega$ 的变化图像

  ![](3e-3.svg)
  ![](3e-4.svg)
  ![](3e-5.svg)

### 结论

- SOR 方法中
  - 对于方程组 2, $\omega=1.9$ 时的迭代步数最小, 且与 $\omega=0.8$ 时的迭代步数差别较大
  - 对于方程组 3, $\omega=1.0$ 时的迭代步数最小, 不同 $\omega$ 之间迭代步数差别不大
