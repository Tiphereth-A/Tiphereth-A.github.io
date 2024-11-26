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

{% note warning %}
<https://cplib.tifa-233.com/src/code/util/fastio.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

{% note warning %}

- 仅在 GCC 下测试过, 推荐用于 **C++17** 及以上
- 为保障效率, 读入过程中遇到文件尾是**未预期**的, 绝大多数情况下读入过程中遇到文件尾会**死循环**

{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp fast-io/FastIO.hpp %}

</details>
