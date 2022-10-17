---
title: 随笔 - 运用 MATLAB 基于 Lotka-Volterra 模型模拟种群演化
categories:
  - 随笔
tags:
  - 随笔
  - 数学
  - MATLAB
  - ODE
  - Malthus模型
  - Logistic模型
  - Lotka-Volterra模型
  - Euler方法
  - Runge-Kutta方法
date: 2021-01-09 23:53:22
---

本篇讲述了如何应用 MATLAB 对三种群的 Lotka-Volterra 模型进行模拟并可视化

<!-- more -->

## 几种基本的种群动力学模型

### 单种群模型

#### Malthus 模型

假设种群数量 $x(t)$ 是时间 $t$ 的连续可微函数, 种群的出生率与死亡率之差 $\epsilon$ 为常数, 即

$$
\frac{x(t+\Delta t)-x(t)}{\Delta t}=\epsilon x(t)
$$

令 $\Delta t\to 0$, 就得到 Malthus 模型

$$
\begin{cases}
  \displaystyle{\mathrm{d}x\over\mathrm{d}t}=\epsilon x\\
  x(0)=x_0
\end{cases}\tag{1}
$$

容易解得

$$
x(t)=x_0e^{\epsilon t}\tag{2}
$$

由 $\text{(2)}$ 可知, 种群数量按指数规律无限增长。而现实中的种群由于受到生存空间等种种约束不可能无限增长, 因此, Malthus 模型必须进行修正

#### Logistic 模型

假设种群在空间内均匀分布, 种群中所有个体不分大小都相同, 世代重叠, 没有迁出和迁入, 种群大小 (数量或密度) $x(t)$ 是连续可微函数. 则 $x(t)$ 的动态变化就可用动力学方程

$$
{\mathrm{d}x\over\mathrm{d}t}=(b-d)x\tag{3}
$$

描述, 其中 $b$ 为出生率, $d$ 为死亡率

在 $\text{(3)}$ 成立的条件下, 资源的供给始终为常数, 且对每个个体的分配是均等的. 当种群规模 (数量或密度) 增大时, 每个个体资源的平均分配量必然减少, 从而使种群规模的增长率 $\epsilon$ 减少. Verhulst 假设种群规模的相对增长率 $\frac{1}{x}{\mathrm{d}x\over\mathrm{d} t}$ 是种群的线性减少函数, 从而得到 Logistic 模型

$$
{\mathrm{d}x\over\mathrm{d}t}=rx\left(1-\frac{x}{k}\right)\tag{4}
$$

其中

- $r>0$ 为种群的**内禀增长率**, 反映了物种内在的特性
- $k>0$ 反映了资源丰富的程度, 当 $x=k$ 时, 种群的规模不再增大. 因而 $k$ 表示环境能容纳此种群个体的最大规模, 称为**环境容纳量**

### 多种群模型

同一自然环境中, 经常有多种生物共存, 对相互影响非常大的生物种群, 我们无法割裂开来单独讨论, 故必须弄清楚它们之间相互关系, 一起进行研究, 这就导出了多种群的模型

#### 两种群相互作用的 Lotka-Volterra 模型

用 $u_1(t),u_2(t)$ 分别表示两种群在 $t$ 时刻的数量或密度, 考察各自的相对增长率 $\frac{1}{u_1}{\mathrm{d}u_1\over\mathrm{d} t}$, $\frac{1}{u_2}{\mathrm{d}u_2\over\mathrm{d} t}$, 由于我们需要考虑到种群内自身发展规律和种群间相互作用的影响两个方面, 故两种群相互作用的模型常用形式是

$$
\begin{cases}
  \frac{1}{u_1}{\mathrm{d}u_1\over\mathrm{d} t}=f_1(u_1)+g_1(u_2)\\
  \frac{1}{u_2}{\mathrm{d}u_2\over\mathrm{d} t}=f_2(u_1)+g_2(u_2)
\end{cases}\tag{5}
$$

其中

- $f_1(u_1),g_2(u_2)$ 分别表示各种群自身的相对增长率
- $f_2(u_1),g_1(u_2)$ 分别表示另一种群对这一种群的影响

这四个函数根据具体对象和环境确定

若假设 $f_1(u_1),f_2(u_1),g_1(u_2),g_2(u_2)$ 都是线性的, 则得到两种群相互作用的 Lotka-Volterra 模型

$$
\begin{cases}
  {\mathrm{d}u_1\over\mathrm{d} t}=u_1(a_1+b_1u_1+c_1u_2)\\
  {\mathrm{d}u_2\over\mathrm{d} t}=u_2(a_2+b_2u_1+c_2u_2)
\end{cases}
\tag{6}
$$

其中

- $a_1,a_2$ 分别是种群 $u_1,u_2$ 的内禀增长率, 其正负由它们各自的食物来源而确定

  以 $a_1$ 为例, 当 $u_1$ 的食物是 $u_2$ 以外的时候, $a_1\geqslant0$; 当 $u_1$ 的食物仅有 $u_2$ 的时候, $a_1\leqslant0$

- $b_1,c_2$ 是反映种内竞争的参数, 故 $b_1,c_2\leqslant0$
- $b_2,c_1$ 是反映种群间相互作用的参数, 一般分为如下情况:
  - 互利共生型：$b_2,c_1\geqslant0$
  - 捕食型: 当 $u_1$ 以 $u_2$ 为食时, $b_2\leqslant0, c_1\geqslant0$
  - 竞争型: $b_2,c_1\leqslant0$

#### 三种群相互作用的 Lotka-Volterra 模型

我们可以用同样的方法得到三种群相互作用的 Lotka-Volterra 模型, 即

$$
{\mathrm{d}\bm{u}\over\mathrm{d}t}=\bm{u}(\bm{a}_0+\bm{A}\bm{u})^T\tag{7}
$$

其中

- $\bm{u}:=(u_1,u_2,u_3)^T$
- $\bm{a}_0:=(a_{10},a_{20},a_{30})^T$
- $\bm{A}:=(a_{ij})_{3\times3}$

参数含义同上

## 微分方程数值解法

求微分方程
$${\mathrm{d}y\over\mathrm{d}x}=f(x,y)$$
数值解的基本思想如下:

考虑 $y_{n+1}$ 在 $(x_n,y_n)$ 处的 Taylor 展开

$$
y_{n+1}=y_n+hf(\epsilon,y(\epsilon)),~x_n<\epsilon<x_{n+1},h=x_{n+1}-x_n
$$

称 $f(\epsilon,y(\epsilon))$ 为区间 $(x_n,x_{n+1})$ 上的**平均斜率**, 记作 $k^*$

根据 $k^*$ 选取方式的不同, 我们有如下数值算法:

- Euler 方法: 取
  $$k^*=f(x_n,y_n)$$
- 改进的 Euler 方法: 取
  $$k^*={f(x_n,y_n)+f(x_{n+1},y_n+hf(x_n,y_n))\over2}$$
- Runge-Kutta 方法: 在区间 $(x_n,x_{n+1})$ 中取若干个点, 将其斜率的加权平均和作为 $k^*$

  一般最常用的算法是四阶 Runge-Kutta 方法, 即:

  $$
  \begin{cases}
    \displaystyle y_{n+1}=y_n+h\frac{k_1+2k_2+2k_3+k_4}{6}\\
    k_1=f(x_n,y_n)\\
    k_2=f(x_{n+\frac{1}{2}},y_n+\frac{h}{2}k_1)\\
    k_3=f(x_{n+\frac{1}{2}},y_n+\frac{h}{2}k_2)\\
    k_4=f(x_{n+1},y_n+hk_3)
  \end{cases}
  $$

本篇采用了 Euler 方法和四阶 Runge-Kutta 方法进行计算

## MATLAB 程序实现

- 主程序
  <details>
  <summary><font color='orange'>Show code</font></summary>

  {% include_code lang:matlab draft-007/main.m %}

  </details>

- Euler 方法
  <details>
  <summary><font color='orange'>Show code</font></summary>

  {% include_code lang:matlab draft-007/euler_solve.m %}

  </details>

- 四阶 Runge-Kutta 方法
  <details>
  <summary><font color='orange'>Show code</font></summary>

  {% include_code lang:matlab draft-007/rk4_solve.m %}

  </details>

## 效果

以

$$
\begin{aligned}
  \bm{u}_0&=(4,2,1)^T\\
  \bm{a}_0&=(1,0,-1)^T\\
  \bm{A}&=\begin{bmatrix}
    0&-0.8&-0.2\\
    0.8&0&-0.8\\
    0.2&0.8&0
  \end{bmatrix}\\
\end{aligned}
$$

为例

### 种群数量随时间的变化

![](amount.svg)

### 相空间图

![](phase-space.svg)
