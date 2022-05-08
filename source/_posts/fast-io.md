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

实现了 有符号算术类型、无符号算术类型、C 风格字符串、`std::string` 的读入和有符号算术类型、无符号算术类型、`char`、`std::string` 的输出

<!-- more -->

~~实际上没什么应用价值, 开了 O2、关闭流同步、解绑、不使用 `std::endl` 等的 `std::cin` / `std::cout` 的性能已经和本模板差不多了, 就当作模板偏特化方面的练习了~~

经测试, 当数据规模在 1e7 及以上时, 该模板效率提升显著

{% note warning %}

- 若使用了 `FastIO::print()`, 记得后面跟上 `FastIO::flush();`
- 为了保证性能, `FastIO::print(char)` 内部没有添加防溢出机制, 若需要频繁调用 `FastIO::print(char)`, 请记得补充
- `FastIO::print(const std::string&)` 里有 `[[unlikely]]` 注解, 若不使用 C++20 请删除
  > 讲道理用 C++20 的 `concept` 写模板偏特化更舒服些, 但笔者懒得再写了

{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp fast-io/FastIO.hpp %}

</details>
