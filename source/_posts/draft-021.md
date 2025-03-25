---
title: "随笔 - 关于 C++ 模板的部分特化"
categories:
  - 笔记
tags:
  - C++
  - 模板
date: 2025-02-25 18:19:37
---

有一天你想对容器重载运算符, 但是却出现了神秘问题

<!-- more -->

在日复一日地对容器书写

{% icodeweb blog lang:cpp draft-021/for.cpp %}

后, 你终于受不了了, 于是你决定写一个重载来一劳永逸地解决这个问题

{% icodeweb blog lang:cpp draft-021/overload.cpp %}

一切看起来都是那么美好, 直到你尝试输出一个字符串. 在你输出字符串时, 编译器拒绝了你的代码, 并说你的重载和

{% icodeweb blog lang:cpp draft-021/sign.cpp %}

撞车了

为什么会这样呢? 答案在于部分模板特化的 [匹配规则](https://en.cppreference.com/w/cpp/language/partial_specialization#Partial_ordering), 简单来说, 编译器不能确定你的重载和 `<string>` 里的重载哪个更特殊, 画成 Hasse 图是这样的:

![](fig1.svg)

注意到你的 <font color=blue>重载</font> 和 `<string>` 里的 <font color=red>重载</font> 是不可比的, 所以在匹配时无法决定哪个优先级更高

因此正确的写法应该是这样:

{% icodeweb blog lang:cpp draft-021/overload2.cpp %}

## 参考资料

- [Partial template specialization - cppreference.com](https://en.cppreference.com/w/cpp/language/partial_specialization)
