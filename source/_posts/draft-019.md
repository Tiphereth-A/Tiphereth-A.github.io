---
title: "随笔 - C++ 元组的一些应用 (子元组, 流式 IO, 运算符重载)"
date: 2022-08-01 13:43:17
categories:
  - 随笔
  - C++
tags:
  - 随笔
  - C++
  - 元编程
  - 元组
  - 运算符重载
---

学模板元编程时写的一些玩具

{% note warning %}
需 C++17 及以上
{% endnote %}

<!-- more -->

## 子元组

{% include_code lang:cpp draft-019/tupleSUB.hpp %}

## 流式 IO

{% include_code lang:cpp draft-019/tupleIO.hpp %}

## 运算符重载

{% include_code lang:cpp draft-019/tupleOO.hpp %}
