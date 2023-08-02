---
title: 模板 - 基于 std::valarray 实现的矩阵
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数学
  - 矩阵
  - Gauss消元
date: 2022-08-02 10:28:15
---

基于 C++17 标准, 实现了矩阵的运算, 求逆, 转置, 秩, 行列式, Gauss 消元, 支持流式 IO

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

<!-- more -->

## 使用说明

- 元素类型 `Tp` 须有接受 1 个整数的构造函数, `Tp{0}` 需为零元, `Tp{1}` 需为幺元
- Gauss-Jordan 消元法有普通版, 辗转相除版与异或版, 其中普通版推荐用于浮点数, 辗转相除版推荐用于整数, 异或版推荐用于 `bool`, 这三种实现分别位于 `Matrix::matrix`, `Matrix::matrix_int`, `Matrix::matrix_bool` 中

## 成员函数&友元函数列表

{% include_code lang:cpp matrix-valarray/Matrix.h %}

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp matrix-valarray/Matrix.hpp %}

</details>

## 示例

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp matrix-valarray/Matrix_exp.cpp %}

</details>

- 洛谷 P2447 [[SDOI2010] 外星千足虫](https://www.luogu.com.cn/problem/P2447)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:Luogu_P2447 Luogu/P2447/0.cpp %}

  </details>
