---
title: 模板 - Gauss 整数
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数学
  - 数论
  - Gauss整数
date: 2022-08-22 19:00:54
---

基于 C++14, 实现了 Gauss 整数的四则运算

{% note info no-icon %}

**<a id="def">定义</a>** Gauss 整数: $\mathbb{Z}[\sqrt{-k}]:=\{a+b\sqrt{-k}|a,b\in\Bbb{Z}\}$, $k>0$

{% endnote %}

{% note warning %}

- 仅在 GCC 下测试过
- 没有防溢出措施, 建议使用时搭配 `modint`

{% endnote %}

{% note warning %}
<https://cplib.tifa-233.com/src/code/math/gint.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp gauss-int/GaussInt.hpp %}

</details>
