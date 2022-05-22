---
title: "随笔 - C++ 中的 std::transform 用法 (C++11)"
categories:
  - 随笔
  - C++
tags:
  - 随笔
  - C++
date: 2021-01-26 18:31:47
---

简要记录 `std::transform` 的用法

<!-- more -->

## 声明

{% tabs tabs_1,1 %}

<!-- tab 一元 -->

{% include_code lang:cpp draft-008/unary.cpp %}

<!-- endtab -->
<!-- tab 二元 -->

{% include_code lang:cpp draft-008/binary.cpp %}

<!-- endtab -->

{% endtabs %}

## 作用

{% tabs tabs_2,1 %}

<!-- tab 一元 -->

对 `[__first,__last)` 内的元素应用 `__unary_op`, 并将结果储存在以 `__result` 开头的区域内

<!-- endtab -->
<!-- tab 二元 -->

对 `[__first1,__last1)` 和 `[__first2,__first2+__last1-__first1)` 内的元素应用 `__binary_op`, 并将结果储存在以 `__result` 开头的区域内

<!-- endtab -->

{% endtabs %}

### Tips

以下程序和示例程序等价

{% include_code lang:cpp draft-008/main.cpp %}

此处要注意一点, 因为 `using namespace std;`, 致使 `<cctype>` 中的 `toupper` 和 `<locale>` 中的 `std::toupper` 发生混淆, 此时需要加 `::` 限定作用域

---

## 主要参考资料

- [std::transform - cppreference.com](https://en.cppreference.com/w/cpp/algorithm/transform)
