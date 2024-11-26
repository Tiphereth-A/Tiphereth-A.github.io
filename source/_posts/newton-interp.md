---
title: 模板 - Newton 插值
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数学
  - 数值分析
  - 插值
  - Newton插值
date: 2022-08-28 21:28:15
---

基于 C++17 标准, 实现了环上的 Newton 插值算法

{% note warning %}

- 仅在 GCC 下测试过
- 插入横坐标相同的点会导致除 0 从而 RE
  {% endnote %}

{% note warning %}
<https://cplib.tifa-233.com/src/code/math/interp_newton_n2.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## Newton 插值

对给定的点 $(x_0,y_0),(x_1,y_1),\dots,(x_{n-1},y_{n-1})$, Newton 插值得到的结果为

$$
f(x)=f[x_0]+\sum_{i=1}^{n-1}f[x_0,x_1,\dots,x_i]\prod_{k=0}^{i-1}(x-x_i)
$$

其中 $f[x_0,x_1,\dots,x_i]$ 为有限差分, 定义如下:

- $f[x_i]=y_i$
- $f[x_i,x_{i+1},\dots,x_j]=\dfrac{f[x_i,x_{i+1},\dots,x_{j-1}]-f[x_{i+1},x_{i+2},\dots,x_j]}{x_i-x_j}$

显然, 相比 Lagrange 插值和 Neville 插值, Newton 插值可以做到 $O(n)$ 的单点插入, 且形式更加简单易懂

## 使用说明

环 `T` 须有接受 1 个整数的构造函数, `T{0}` 需为零元, `T{1}` 需为幺元

## 时间复杂度

- 单点插入: $O(n)$, $n$ 为已经插入的点的个数
- 求值: $O(n)$, $n$ 为已经插入的点的个数

## 成员函数列表

{% icodeweb blog lang:cpp newton-interp/NewtonInterp.h %}

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp newton-interp/NewtonInterp.hpp %}

</details>

## 示例

- 洛谷 P4463 [[集训队互测 2012] calc](https://www.luogu.com.cn/problem/P4463)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:Luogu_P4463 Luogu/P4463/0.cpp %}

  </details>
