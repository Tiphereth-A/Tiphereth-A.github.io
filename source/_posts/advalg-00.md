---
title: 高等代数笔记 - 基础知识
categories:
  - 笔记
  - 数学
  - 高等代数
tags:
  - 数学
  - 笔记
  - 代数
  - 高等代数
  - 群
  - 环
  - 域
date: 2020-07-14 23:29:59
---

本章主要列举一些前置知识

随用随补

<!-- more -->

{% post_link advanced-algebra 返回目录 %}

## 群, 环, 域

> **定义** 群
>
> 称代数系统$\lang G,\cdot\rang$为**群**, 若满足
>
> 1. 封闭性: $\forall a,b\in G,a\cdot b\in G$
> 2. 结合律: $\forall a,b,c\in G,(a\cdot b)\cdot c=a\cdot(b\cdot c)$
> 3. 单位元: $\exist e\in G,\forall a\in G,~s.t.~e\cdot a = a\cdot e = a$
> 4. 逆元: $\forall a\in G,\exist b\in G,~s.t.~a\cdot b = b\cdot a = e$, 此处$e$为单位元
>
> 其中$G$为非空集合, $\cdot$为$G$上一二元运算

- 如果上述 4 个条件只有 1 和 2 成立, 我们称代数系统$\lang G,\cdot\rang$为**半群**
- 如果二元运算$\cdot$还满足**交换律**($\forall a,b\in G,a\cdot b=b\cdot a$), 则称群$(G,\cdot)$为**交换群**或**Abel 群**

---

> **定义** 环
>
> 称代数系统$\lang G,+,\cdot\rang$为**环**, 若满足
>
> 1. $\lang G,+\rang$构成交换群
> 2. $\lang G,\cdot\rang$构成半群
> 3. $\cdot$对$+$的分配律:
>    $$
>    \forall a,b,c\in G,\begin{cases}
>      a\cdot (b+c) = a\cdot b+a\cdot c\\
>      (b+c)\cdot a = b\cdot a+c\cdot a
>    \end{cases}
>    $$

---

> **定义** 域
>
> 称代数系统$\lang G,+,\cdot\rang$为**域**, 若满足
>
> 1. $\lang G,+\rang$构成交换群
> 2. $\lang G/\{e\},\cdot\rang$构成交换群, 其中$e$为群$\lang G,+\rang$的单位元
> 3. $\cdot$对$+$的分配律:
>    $$
>    \forall a,b,c\in G,\begin{cases}
>      a\cdot (b+c) = a\cdot b+a\cdot c\\
>      (b+c)\cdot a = b\cdot a+c\cdot a
>    \end{cases}
>    $$

具体参见抽象代数(可能会开坑)
