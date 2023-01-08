---
title: 随笔 - Laplace算子的旋转不变性
categories:
  - 随笔
  - 数学
tags:
  - 数学
  - 随笔
  - Nabla算子
  - Hessian矩阵
  - Laplace算子
  - 旋转不变性
date: 2021-09-23 00:08:45
---

一道练习题

<!-- more -->

{% note success no-icon %}

**<a id="th">定理</a>** (Laplace 算子的旋转不变性)

令

- $O=(o_{ij})_{n\times n}\in\mathbb{R}^{n\times n}$ 是正交矩阵
- $x=(x_1,x_2,\dots,x_n)^T\in\mathbb{R}^n$
- $y=Ox=(y_1,y_2,\dots,y_n)^T\in\mathbb{R}^n$

则

$$
\Delta_x=\Delta_y
$$

其中

- $$
  \Delta_x:=\sum_{i=1}^n\frac{\partial^2}{\partial x_i^2}
  $$
- $$
  \Delta_y:=\sum_{i=1}^n\frac{\partial^2}{\partial y_i^2}
  $$

---

**Proof** 显然

$$
y_i=\sum_{j=1}^no_{ij}x_j,\ \forall i=1..n
$$

故我们有

$$
\frac{\partial}{\partial x_i}=\sum_{j=1}^n\frac{\partial}{\partial y_j}\frac{\partial y_j}{\partial x_i}=\sum_{j=1}^no_{ji}\frac{\partial}{\partial y_j}
$$

考虑 Hessian 矩阵

$$
\nabla^2_x=\left(\frac{\partial^2}{\partial x_j\partial x_i}\right)_{n\times n}=\left(\sum_{l=1}^n\sum_{k=1}^no_{lj}o_{ki}\frac{\partial^2}{\partial y_l\partial y_k}\right)_{n\times n}
$$

则

$$
\begin{aligned}
  \Delta_x&=\operatorname{tr}(\nabla^2_x)\\
  &=\sum_{l=1}^n\sum_{k=1}^n\left(\sum_{i=1}^no_{li}o_{ki}\right)\frac{\partial^2}{\partial y_l\partial y_k}\\
  &=\sum_{l=1}^n\sum_{k=1}^n\delta_{kl}\frac{\partial^2}{\partial y_l\partial y_k}\\
  &=\sum_{k=1}^n\frac{\partial^2}{\partial y_k^2}\\
  &=\Delta_y
\end{aligned}
$$

{% endnote %}
