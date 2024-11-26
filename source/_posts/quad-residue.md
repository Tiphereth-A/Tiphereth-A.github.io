---
title: 模板 - Legendre 符号 & 二次剩余
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数学
  - 数论
  - Legendre符号
  - 二次剩余
date: 2021-12-31 13:06:27
---

基于 C++17 标准, 对给定的整数 $n,p$, 若 $\left(\frac{n}{p}\right)\ne1$ 则返回 `std::nullopt`, 否则返回方程 $x^2\equiv n\pmod p$ 的一个根

{% note warning %}
代码中使用了 `__builtin_ctzll`
{% endnote %}

{% note warning %}
<https://cplib.tifa-233.com/src/code/nt/qresidue.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp quad-residue/quad_r.hpp %}

</details>
