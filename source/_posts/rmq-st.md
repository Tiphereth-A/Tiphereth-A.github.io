---
title: 模板 - ST表
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - 数据结构
  - RMQ
  - ST表
date: 2022-05-11 12:07:50
---

基于 C++14 的 ST 表模板

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

<!-- more -->

## 成员函数简介

### 符号说明

- `data_t`: 元素类型
- `init_func`: 用于初始化的仿函数类型
- `query_func`: 用于查询的仿函数类型

### 简介

| 成员函数                                 | 功能   |
| ---------------------------------------- | ------ |
| `void clear()`                           | 清空   |
| `void init(size_t n)`                    | 初始化 |
| `data_t query(size_t l, size_t r) const` | 查询   |

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp rmq-st/RMQ_ST.hpp %}

</details>

## 示例

- 洛谷 [P3865 【模板】ST 表](https://www.luogu.com.cn/problem/P3865)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:Luogu_3865 Luogu/3865/5.cpp %}

  </details>

- CodeForces [522D Closest Equals](https://codeforces.com/problemset/problem/522/D)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:CodeForces_522D CodeForces/522D/0.cpp %}

  </details>