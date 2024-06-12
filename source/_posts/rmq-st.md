---
title: 模板 - ST 表
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
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

{% note warning %}
<https://cplib.tifa-233.com/src/code/ds/st_array.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

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

{% icodeweb blog lang:cpp rmq-st/RMQ_ST.hpp %}

</details>

## 示例

- 洛谷 [P3865 【模板】ST 表](https://www.luogu.com.cn/problem/P3865)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:Luogu_P3865 Luogu/P3865/5.cpp %}

  </details>

- Codeforces [522D Closest Equals](https://codeforces.com/problemset/problem/522/D)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:CodeForces_522D CodeForces/522D/0.cpp %}

  </details>

- Codeforces [1691D Max GEQ Sum](https://codeforces.com/problemset/problem/1691/D)

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa_cpp title:CodeForces_1691D CodeForces/1691D/0.cpp %}

  </details>
