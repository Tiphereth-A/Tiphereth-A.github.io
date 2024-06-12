---
title: 模板 - Miller-Rabin 素性检验与 Pollard-Rho 算法
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数学
  - 随机化
  - 素数/质数
  - 素性检验
  - Miller-Rabin算法
  - Pollard-Rho算法
date: 2021-11-11 00:51:43
---

包含以 $O(k\log^3n)$ 的时间复杂度对一个数进行素性检验的 Miller-Rabin 算法和期望以 $O(n^\frac{1}{4})$ 的时间复杂度找出一个数最大素因子的 Pollard-Rho 算法

原理略

{% note warning %}

- 仅在 GCC 下测试过
- 求 `gcd` 的函数若在低于 C++17 下会调用非标准函数

{% endnote %}

<!-- more -->

{% note warning %}
<https://cplib.tifa-233.com/src/code/nt/is_prime.hpp>, <https://cplib.tifa-233.com/src/code/nt/pfactors.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp p-test-mrpr/Pollard_rho.hpp %}

</details>
