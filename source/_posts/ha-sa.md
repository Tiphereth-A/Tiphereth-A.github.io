---
title: 模板 - 模拟退火
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 随机化
  - 随机化算法
  - 模拟退火
date: 2021-11-11 19:20:54
---

基于 C++14 的模拟退火模板, 支持通过重排序给定序列和按给定范围生成序列两种方式, 推荐使用前者

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

<!-- more -->

{% note warning %}
<https://cplib.tifa-233.com/src/code/opt/heuristic_sa.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ha-sa/Simulated_annealing.hpp %}

</details>
