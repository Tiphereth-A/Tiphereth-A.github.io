---
title: 模板 - 矩阵
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - C++
  - 数学
  - 矩阵
  - Gauss消元
date: 2021-10-31 21:28:15
---

基于 C++14 标准, 实现了矩阵的四则运算, 求逆, 转置, 秩, 行列式与对输入输出流的支持

{% note warning %}
仅在 GCC 下测试过
{% endnote %}

<!-- more -->

## 使用说明

- 元素类型 `Tp` 须有接受 1 个整数的构造函数, 否则需手动偏特化 `Matrix::Matrix_helper::Zero` (零元) 与 `Matrix::Matrix_helper::One` (幺元)
- Gauss-Jordan 消元法有普通版与辗转相除版, 其中普通版推荐用于浮点数, 辗转相除版推荐用于 $\Z_m$, `gauss(a)` 与 `gauss_half(a)` 默认执行普通版, 若需执行辗转相除版需手动偏特化 `namespace Matrix::Matrix_helper::gauss_tag`, 示例见代码末尾的注释

  > 当然嫌麻烦也可以直接把 `protected` 里面的那四个函数暴露出来用, 记得同时修改 `det()`, `trans()`, `rank()`, `gauss()`, `gauss_half()`

## 成员函数&友元函数简介

### 符号说明

- `self`: 类自身的类型
- `data_t`: 元素类型
- `i`, `j`: 正整数
- `s`: 元素
- `a`, `b`: 类型为 `self` 的类
- `un`: 一元函数
- `bin`: 二元函数

### 简介

| 成员函数/友元函数                                            | 返回类型             | 功能                                                                                                                                   | 调用后是否改变当前类 |
| ------------------------------------------------------------ | -------------------- | -------------------------------------------------------------------------------------------------------------------------------------- | -------------------- |
| `self(i, j, equ)`                                            | -                    | 构造 `i` 行 `j` 列的矩阵, 以 `equ` 作为元素的 `operator==`, `i` 或 `j` 为 `0` 时抛出 `std::logic_error` 异常                           | -                    |
| `self(i, j, s, equ)`                                         | -                    | 构造 `i` 行 `j` 列的矩阵, 以 `equ` 作为元素的 `operator==`, 并将所有元素初始化为 `s`, `i` 或 `j` 为 `0` 时抛出 `std::logic_error` 异常 | -                    |
| `a.data(i, j)` / `a.data(i, j) const`                        | `data_t&`            | 返回 `a(i, j)`                                                                                                                         | 否                   |
| `a.clear()`                                                  | `self&`              | 清空并返回 `a`                                                                                                                         | 是                   |
| `a.get_row() const`                                          | `const std::size_t&` | 返回 `a` 的行数                                                                                                                        | 否                   |
| `a.get_col() const`                                          | `const std::size_t&` | 返回 `a` 的列数                                                                                                                        | 否                   |
| `a.transform_unary(un)`                                      | `self&`              | 将 `a` 中的所有元素 `a(i, j)` 改为 `un(a(i, j))`                                                                                       | 是                   |
| `a.transform_binary(b, bin)`                                 | `self&`              | 将 `a` 中的所有元素 `a(i, j)` 改为 `bin(a(i, j), b(i, j))`                                                                             | 是                   |
| `calc_unary(a, un)`                                          | `self`               | 返回 `un(a)`                                                                                                                           | -                    |
| `calc_binary(a, b, bin)`                                     | `self`               | 返回 `bin(a, b)`                                                                                                                       | -                    |
| `gauss(a)`                                                   | `std::ptrdiff_t`     | 对 `a` 应用 Gauss-Jordan 消元法, 将 `a` 化为准对角矩阵, 返回 $\operatorname{rk}(a)\cdot\operatorname{sgn}\det(a)$                      | 是                   |
| `gauss_half(a)`                                              | `std::ptrdiff_t`     | 对 `a` 应用 Gauss-Jordan 消元法, 将 `a` 化为准上三角矩阵, 返回 $\operatorname{rk}(a)\cdot\operatorname{sgn}\det(a)$                    | 是                   |
| `a.trans()`                                                  | `self`               | 返回 `a` 的转置矩阵                                                                                                                    | 否                   |
| `a.rank() const`                                             | `std::size_t`        | 返回 `a` 的秩                                                                                                                          | 否                   |
| `a.det() const`                                              | `data_t`             | 返回 `a` 的行列式值, 不存在时抛出 `std::runtime_error` 异常                                                                            | 否                   |
| `a.inverse() const`                                          | `self`               | 返回 `a` 的逆矩阵, 不存在时抛出 `std::runtime_error` 异常                                                                              | 否                   |
| `a.add(b)`, `a.minus(b)`, `a.multiply(b)`, `a.divide(b)`     | `self&`              | 逐元素四则运算                                                                                                                         | 是                   |
| `a.add(s)`, `a.minus(s)`, `a.multiply(s)`, `a.divide(s)`     | `self&`              | 逐元素四则运算                                                                                                                         | 是                   |
| `add(a, b)`, `minus(a, b)`, `multiply(a, b)`, `divide(a, b)` | `self&`              | 逐元素四则运算                                                                                                                         | -                    |
| `add(a, s)`, `minus(a, s)`, `multiply(a, s)`, `divide(a, s)` | `self&`              | 逐元素四则运算                                                                                                                         | -                    |

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp matrix/Matrix.hpp %}

</details>

## 示例

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp matrix/Matrix_exp.cpp %}

</details>
