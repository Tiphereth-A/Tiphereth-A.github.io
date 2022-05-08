---
title: 笔记 - Huffman 树与 Huffman 编码
categories:
  - 程序设计
  - 笔记
tags:
  - 程序设计
  - 笔记
  - 模板
  - 算法
  - 数据结构
  - 树
  - Huffman树
  - Huffman编码
date: 2021-07-15 18:41:12
---

Huffman 编码是一种基于 Huffman 树的, 按字符概率构造的, 能保证编码平均长度最短的编码方式

<!-- more -->

## 介绍

Huffman 树即为根结点到所有叶子结点的带权路径长度之和最小的树

### 构建方式

对于一棵 $k$ 叉的 Huffman 树, 我们首先要确保 结点个数 $n$ 满足 $(k-1)\mid(n-1)$, 否则我们可以补充若干个权值为 $0$ 的结点使其成立

首先按结点的权值排序, 然后取出 $k$ 个权值最小的结点合并为一个新结点并插入该序列, 新结点的权值为这 $k$ 个点权值之和, 直到序列中只剩下 $1$ 个结点为止

Huffman 编码通过对 Huffman 树进行层序遍历得到

## 例题

- [UOJ 130 - 【NOI2015】荷马史诗](https://uoj.ac/problem/130) -> {% post_link sa-uoj-130 题解 %}

## 代码 (K 叉 Huffman 树)

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp hfm-tree/Huffman_tree.hpp %}

</details>
