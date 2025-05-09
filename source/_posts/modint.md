---
title: 模板 - 自动取模的整数类 (mod_int)
categories:
  - 算法竞赛
  - 模板
tags:
  - 算法竞赛
  - 模板
  - C++
  - 数学
date: 2021-10-26 22:44:15
---

即 $\mathbb{Z}_m$

基于 C++14 标准, 实现了四则运算, 逆元与对输入输出流的支持

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

{% note warning %}
<https://cplib.tifa-233.com/src/code/math/mint.hpp>, <https://cplib.tifa-233.com/src/code/math/mint_s30.hpp>, <https://cplib.tifa-233.com/src/code/math/mint_s63.hpp>, <https://cplib.tifa-233.com/src/code/math/mint_d31.hpp>, <https://cplib.tifa-233.com/src/code/math/mint_d63.hpp> 存放了笔者对该算法/数据结构的最新实现, 其中使用了 Montgomery 约乘, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## 成员函数&友元函数简介

### 符号说明

- `self`: 类自身的类型
- `data_t`: 存储整数的类型
- `mod_t`: 模的类型
- `a`, `b`: 类型为 `self` 的类
- `un`: 一元函数
- `bin`: 二元函数

### 简介

| 成员函数/友元函数                | 返回类型  | 功能                                                                            | 调用后是否改变当前类 |
| -------------------------------- | --------- | ------------------------------------------------------------------------------- | -------------------- |
| `a.data()` / `a.data() const`    | `data_t&` | 返回存储的整数                                                                  | 否                   |
| `a.get_mod() const`              | `mod_t`   | 返回模数                                                                        | 否                   |
| `a.no_check_mod()`               | `self&`   | 对 `a.data()` 取模, 不检查正负                                                  | 是                   |
| `a.safe_mod()`                   | `self&`   | 对 `a.data()` 取模, 检查正负                                                    | 是                   |
| `a.transform_unary(un)`          | `self&`   | 将 `a.data()` 改为 `un(a.data())`, 对结果取模                                   | 是                   |
| `a.transform_unary_raw(un)`      | `self&`   | 将 `a.data()` 改为 `un(a.data())`, 不对结果取模                                 | 是                   |
| `a.transform_binary(b, bin)`     | `self&`   | 将 `a.data()` 改为 `bin(a.data(), b.data())`, 对结果取模                        | 是                   |
| `a.transform_binary_raw(b, bin)` | `self&`   | 将 `a.data()` 改为 `bin(a.data(), b.data())`, 不对结果取模                      | 是                   |
| `calc_unary(a, un)`              | `self`    | 返回存储 `un(a.data())` 的类, 对结果取模                                        | -                    |
| `calc_unary_raw(a, un)`          | `self`    | 返回存储 `un(a.data())` 的类, 不对结果取模                                      | -                    |
| `calc_binary(a, b, bin)`         | `self`    | 返回存储 `bin(a.data(), b.data())` 的类, 对结果取模                             | -                    |
| `calc_binary_raw(a, b, bin)`     | `self`    | 返回存储 `bin(a.data(), b.data())` 的类, 不对结果取模                           | -                    |
| `a.inverse() const`              | `self`    | 返回 `a.data()` 模 `a.get_mod()` 的逆元, 不存在时抛出 `std::runtime_error` 异常 | 否                   |

## 代码

{% icodeweb blog lang:cpp modint/ModInteger.hpp %}

## 示例

{% icodeweb blog lang:cpp modint/ModInteger_exp.cpp %}
