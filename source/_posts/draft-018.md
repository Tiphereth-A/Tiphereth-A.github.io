---
title: "随笔 - C++ 的高维向量"
date: 2023-04-16 02:43:13
categories:
  - 随笔
  - C++
tags:
  - 随笔
  - C++
  - 模板元编程
---

为了方便写高维数组以及初始化, 就简单封了一个结构体

{% note warning %}
<https://cplib.tifa-233.com/include/util/ndvec.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## 代码

{% icodeweb blog lang:cpp draft-018/ndvector.hpp %}

## 测试

{% icodeweb blog lang:cpp draft-018/ndvector_test.cpp %}
