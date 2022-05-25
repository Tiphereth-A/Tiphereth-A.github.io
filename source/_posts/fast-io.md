---
title: 模板 - 基于 fread / fwrite 的快读快写
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - C++
  - 常数优化
date: 2021-07-28 21:40:03
---

基于 C++ 14, 实现了 有符号整数、无符号整数、字符、C 风格字符串、`std::string` 的输入输出

<!-- more -->

~~实际上没什么应用价值, 开了 O2、关闭流同步、解绑、不使用 `std::endl` 等的 `std::cin` / `std::cout` 的性能已经和本模板差不多了, 就当作模板偏特化方面的练习了~~

经测试, 当数据规模在 1e7 及以上时, 该模板效率提升显著

{% note warning %}

仅在 GCC 下测试过

{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp fast-io/FastIO.hpp %}

</details>
