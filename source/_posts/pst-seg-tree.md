---
title: 模板 - 可持久化线段树(主席树)
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数据结构
  - 线段树
  - 可持久化线段树/主席树
date: 2021-11-01 15:18:10
---

基于 C++14 标准, 实现了初始化, 单点修改与查询

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

{% note warning %}
<https://cplib.tifa-233.com/src/code/ds/persistent_segtree.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## 代码

{% icodeweb blog lang:cpp pst-seg-tree/Persistable_seg_tree.hpp %}

## 示例

- [洛谷 P3919 【模板】可持久化线段树 1（可持久化数组）](https://www.luogu.com.cn/problem/P3919)

  > 由于 64 位系统下的迭代器大小为 8 字节, 故该模板在部分测试点会 MLE, 解决方案就是把 `index_t` 换成 `uint32_t` 并将内部索引方式改成数组即可

  {% icodeweb blog lang:cpp pst-seg-tree/Persistable_seg_tree_exp.cpp %}

  > 附大数据的生成器 (from <https://www.luogu.com.cn/discuss/354067>)

  {% icodeweb blog lang:cpp pst-seg-tree/data_gen.cpp %}
