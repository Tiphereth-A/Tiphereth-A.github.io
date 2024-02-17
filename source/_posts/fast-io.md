---
title: 模板 - 基于 fread / fwrite 的快读快写
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 常数优化
date: 2021-07-28 21:40:03
---

- 有符号/无符号整数
- 字符
- C 风格字符串
- `std::string`
- `std::pair`
- `std::tuple`

的输入输出, 支持流式写法

<!-- more -->

{% note warning %}
<https://cplib.tifa-233.com/src/code/util/fastio.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

~~实际上没什么应用价值, 开了 O2、关闭流同步、解绑、不使用 `std::endl` 等的 `std::cin` / `std::cout` 的性能已经和本模板差不多了, 就当作模板偏特化方面的练习了~~

经测试, 当数据规模在 1e7 及以上时, 该模板效率提升显著

{% note warning %}

- 仅在 GCC 下测试过, 推荐用于 **C++17** 及以上
- 为保障效率, 读入过程中遇到文件尾是**未预期**的, 绝大多数情况下读入过程中遇到文件尾会**死循环**

{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp fast-io/FastIO.hpp %}

</details>
