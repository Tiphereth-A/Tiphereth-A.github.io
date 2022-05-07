---
title: 微分几何笔记00 - 基础知识与约定
categories:
  - 笔记
  - 数学
  - 微分几何
tags:
  - 数学
  - 笔记
  - 几何
  - 微分几何
  - Euclid空间
  - 向量函数
  - 参数曲线
  - 参数曲面
  - 正则参数曲线
  - 正则参数曲面
  - 内积
  - 外积
  - 混合积
  - Lagrange恒等式
  - 合同变换
  - 刚体运动
  - 反向刚体运动
date: 2022-01-19 14:19:59
---

本章主要列举一些前置知识与约定

<!-- more -->

{% button /article/contents/diff-geo/ ,返回目录, list %}

---

## 约定

如无特殊说明, 本笔记均遵循如下约定:

- 所有的讨论都在 $E^3$ 下, 即三维 Euclid 空间下
- 所有的标量函数均在 $C^3$ 内, 即三阶连续可微
- 所有的向量函数的每一个分量函数均在 $C^3$ 内
- 所有的向量均为行向量
- 向量函数

  - 参数曲线
    $$\textbf{r}(t):=(x(t),y(t),z(t))$$

    在本系列中, 我们要求其满足:

    - $\textbf{r}'(t)\ne 0,~\forall t$

    此时的参数曲线可被称为 **正则参数曲线**

  - 参数曲面
    $$\textbf{r}(u,v):=(x(u,v),y(u,v),z(u,v))$$

    在本系列中, 我们要求其满足:

    - $\textbf{r}_u\wedge\textbf{r}_v|_{(u_0,v_0)}\ne 0,~\forall u_0,v_0$

    此时的参数曲面可被称为 **正则参数曲面**

- 为了书写简便, 有时不会对向量加粗处理, 在涉及到向量运算时更为常见

## 内积, 外积, 混合积

定义与通常意义下的一致, 记号如下:

- 内积: $\lang u,v\rang$
- 外积: $u\wedge v$
- 混合积: $(u,v,w)$

  > 我知道这个记号和行向量冲突了, 但是一方面本笔记中混合积不会频繁出现, 另一方面这两个记号其实很难搞混, 所以就不另作区分了

我们有如下两个实用的结论

- Lagrange 恒等式:
  $$
  \lang v_1\wedge v_2,v_3\wedge v_4\rang=\begin{vmatrix}
    \lang v_1,v_3\rang & \lang v_2,v_3\rang\\
    \lang v_1,v_4\rang & \lang v_2,v_4\rang\\
  \end{vmatrix}
  $$
- 混合积的轮换恒等性: $(v_1,v_2,v_3)=(v_2,v_3,v_1)=(v_3,v_1,v_2)$

  进一步, 对于置换 $\sigma\in S^3$, 我们有

  $$(v_{\sigma(1)},v_{\sigma(2)},v_{\sigma(3)})=(-1)^{\pi(\sigma)}(v_1,v_2,v_3)$$

证明略

## 微分运算规则

- $$\mathrm{d}(\lambda\textbf{u}):=(\mathrm{d}\lambda)\textbf{u}+\lambda\mathrm{d}\textbf{u}$$
- $$\mathrm{d}\lang \textbf{u},\textbf{v}\rang:=\lang\mathrm{d}\textbf{u},\textbf{v}\rang+\lang \textbf{u},\mathrm{d}\textbf{v}\rang$$
- $$\mathrm{d}(\textbf{u}\wedge \textbf{v}):=\mathrm{d}\textbf{u}\wedge \textbf{v}+\textbf{u}\wedge\mathrm{d}\textbf{v}$$
- $$\mathrm{d}(\textbf{u},\textbf{v},\textbf{w}):=(\mathrm{d}\textbf{u},\textbf{v},\textbf{w})+(\textbf{u},\mathrm{d}\textbf{v},\textbf{w})+(\textbf{u},\textbf{v},\mathrm{d}\textbf{w})$$

## 合同变换, 刚体运动, 反向刚体运动

我们知道, $E^3$ 上的任意合同变换 $\mathcal{T}$ 均满足

$$\mathcal{T}(x)=xT+P$$

其中 $T$ 为 3 阶正交矩阵, $P\in E^3$

若 $T\in\textrm{SO}(3)$, 即 $\det T=1$, 则称该合同变换 $\mathcal{T}$ 为 **刚体运动**, 否则称该合同变换 $\mathcal{T}$ 为 **反向刚体运动**

简单来说就是: 刚体运动是旋转和平移的复合, 而反向刚体运动是反射变换后的刚体运动

---

{% button /article/contents/diff-geo/ ,返回目录, list %}

{% button /article/diff-geo/0001/ ,下一篇笔记, angle-double-right %}
