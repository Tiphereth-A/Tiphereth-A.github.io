---
title: 模板 - 红黑树
categories:
  - 笔记
tags:
  - 数学
  - 模板
  - 数据结构
  - 平衡树
  - 顺序统计树
  - 二叉搜索树
  - 红黑树
date: 2024-11-27 09:23:57
---

红黑树是一种平衡树, 是 C++ `std::(multi)?(set|map)`, Java `Tree(Set|Map)` 的底层实现

代码参考了 `pb_ds` 的设计方式, 时空均略优于 `pb_ds`

{% note info %}
这里的代码实际上是 order-statistic tree, 即每个结点都记录了对应子树的大小, 因此支持查找排名以及根据排名反查数据
{% endnote %}

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

{% note warning %}
<https://cplib.tifa-233.com/src/code/ds/rbtree.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## 设计与使用

参考了 `pb_ds` 的设计方式, 使用了 Mixin Classes, `balance_tree<K, bst_tag>` 即为二叉搜索树, `balance_tree<K, rbt_tag>` 即为红黑树

具体来说, 代码中把一般的平衡树/顺序统计树操作 (遍历, `(lower|upper)_bound`, `order_of_key`, `find_by_order` 等) 和红黑树的操作 (旋转, 插入和删除的性质维护等) 解耦. 又由于红黑树的插入/删除可以视为先按二叉搜索树的方式插入/删除, 再进行平衡维护操作, 故代码中也将这两部分解耦, 并让 `rbt_tag` 继承 `bst_tag` 来提高代码复用率

使用方式类似 `pb_ds` 的 `__gnu_pbds::tree`, 只是没有将维护子树大小的部分解耦出来

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp rbtree/rbtree.hpp %}

</details>

## 示例

洛谷 P6136 [【模板】普通平衡树（数据加强版）](https://www.luogu.com.cn/problem/P6136)

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P6136 Luogu/P6136/3.cpp %}

</details>

---

## 参考

- <https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/tree_based_containers.html>
- Introduction to Algorithms, Fourth Edition
- <https://en.wikipedia.org/wiki/Red%E2%80%93black_tree>
