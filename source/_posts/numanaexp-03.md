---
title: 数值分析实验 - 函数逼近与曲线拟合
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
  - 算法
  - 曲线拟合
  - 最小二乘法
date: 2021-04-22 23:05:47
---

数值分析实验 3 - 函数逼近与曲线拟合

<!-- more -->

## 实验要求和目的

在某冶炼过程中, 根据统计数据的含碳量与时间关系, 试求含碳量 $y$ 与时间 $t$ 的拟合曲线

| $t~(\text{min})$     | 0    | 5    | 10   | 15   | 20   | 25   |
| -------------------- | ---- | ---- | ---- | ---- | ---- | ---- |
| $y~(\times 10^{-4})$ | 0    | 1.27 | 2.16 | 2.86 | 3.44 | 3.87 |
| $t~(\text{min})$     | 30   | 35   | 40   | 45   | 50   | 55   |
| $y~(\times 10^{-4})$ | 4.15 | 4.37 | 4.51 | 4.58 | 4.02 | 4.64 |

要求

1. 用最小二乘法进行曲线拟合
1. 近似解析表达式为 $\varphi(t)=a_1t+a_2t^2+a_3t^3$
1. 打印出拟合函数 $\varphi(t)$, 并打印出 $\varphi(t_j)$ 与 $y(t_j)$ 的误差, $j=1,2,...,12$
1. 另外选取一个近似表达式, 尝试拟合效果的比较
1. \*绘制出曲线拟合图

## 计算公式

- 最小二乘法原理 (参见 {% post_link symmetric-bilinear-metric-space-and-system-of-linear-equations %})

  令 $A=(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}),~\alpha_i\in\R^m,i=1,2,...,n$, 寻找 $AX=B$ 的最小二乘解 $(\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n})^T$ 即为寻找一组实数 $\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$ 使得
  $$\left|B-\sum_{i=1}^nx_i\alpha_i\right|^2=\sum_{i=1}^n\left(b_1-\sum_{j=1}^na_{ij}x_j\right)^2\tag{1}$$
  的值最小

  此时取的 $\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$ 只需使 $\sum_{i=1}^nx_i\alpha_i$ 为 $B$ 在 $G[\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}]$ 的正射影

  这样的 $\def\enum#1{x_{ #1}}\enum{1},\enum{2},...,\enum{n}$ 是且仅是
  $$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})X=(\def\enum#1{(B,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{n})^T\tag{2}$$
  的解, 其中 $G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})$ 为 $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n}$ 的 Gram 矩阵

  又
  $$G(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{n})=A^TA$$
  $$(\def\enum#1{(B,\alpha_{ #1})}\enum{1},\enum{2},...,\enum{n})^T=A^TB$$

  因此式 $(2)$ 即为
  $$A^TAX=A^TB\tag{3}$$

  由正射影的存在性可知该方程一定可解, 其解为 $X=(A^TA)^{-1}A^TB$

## 程序设计

### 主程序

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-03/main.m %}

</details>

### 最小二乘法函数文件

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-03/lsmfit.m %}

</details>

## 结果讨论和分析

### 结果

- 拟合函数 1:

  $3.5168482\times10^{-9}x^3 - 5.2948459\times10^{-6}x^2 + 2.6568799\times10^{-4}x$

  - 误差:

    | $t$        | 0           | 5          | 10          | 15          | 20          | 25          |
    | ---------- | ----------- | ---------- | ----------- | ----------- | ----------- | ----------- |
    | $\epsilon$ | 0.00000000  | 0.00000695 | -0.00000026 | -0.00000527 | -0.00000372 | -0.00000124 |
    | $t$        | 30          | 35         | 40          | 45          | 50          | 55          |
    | $\epsilon$ | -0.00000048 | 0.00000493 | 0.00001035  | 0.00001414  | -0.00004233 | 0.00001929  |

- 拟合函数 2:

  $3.4364154\times10^{-9}x^3 - 5.2155622\times10^{-6}x^2 + 2.6339853\times10^{-4}x + 1.7838828\times10^{-5}$

  - 误差:

    | $t$        | 0           | 5          | 10          | 15          | 20          | 25          |
    | ---------- | ----------- | ---------- | ----------- | ----------- | ----------- | ----------- |
    | $\epsilon$ | -0.00000178 | 0.00000613 | -0.00000046 | -0.00000513 | -0.00000345 | -0.00000100 |
    | $t$        | 30          | 35         | 40          | 45          | 50          | 55          |
    | $\epsilon$ | -0.00000036 | 0.00000489 | 0.00001018  | 0.00001393  | -0.00004244 | 0.00001950  |

- 图像

  ![](fig1.svg)

### 分析

- 可以发现两个拟合函数图像几近重合
- 在测试中发现当选用多项式拟合时, 次数过小则误差较大, 次数较大则对趋势的预测不够合理, 且更易受到干扰

  ![](fig2.svg)