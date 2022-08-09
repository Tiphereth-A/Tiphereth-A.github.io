---
title: 模板 - string 转 uint 的一种快速算法
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 算法
  - 常数优化
date: 2021-12-21 21:21:01
---

基于 C++14 标准, 一种高效的十进制字符串转无符号整数的算法

{% note warning %}
仅在小端 CPU 下正确
{% endnote %}

{% note warning %}

- 仅在 GCC 下测试过
- 推荐用于 64 位系统

{% endnote %}

<!-- more -->

参见 [Fast numeric string to int – Johnny Lee – Improving stuff one bit at a time](https://johnnylee-sde.github.io/Fast-numeric-string-to-int/)

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp fast-str2uint/dec2uint_mod.hpp %}

</details>
