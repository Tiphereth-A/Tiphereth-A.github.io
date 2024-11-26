---
title: 笔记 - 线性基 (Hamel 基)
categories:
  - 笔记
  - 算法竞赛
tags:
  - 算法竞赛
  - 模板
  - 数学
  - 模板
  - 代数
  - 线性代数
  - 高等代数
  - 线性空间
  - 向量组
  - 线性组合
  - 线性表出
  - 线性相关
  - 线性无关
  - 极大线性无关组
  - 秩
  - 线性基
  - Hamel基
  - Zorn引理
  - 偏序集
  - 异或线性基
  - 实数线性基
  - Gauss消元法
date: 2022-09-12 00:54:15
---

本文主要介绍线性基的概念与重要性质, 以及在算法竞赛中的两种应用形式: "{% post_link xor-basis 异或线性基 %}" 和 "实数线性基"

前置知识: {% post_link linear-space 线性空间 %} 的定义

{% note info %}
本篇文章已迁移至 OI-wiki 的 [线性基](https://oi-wiki.org/math/linear-algebra/basis/) 页面中
{% endnote %}

<!-- more -->

## 基础概念

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** 对线性空间 $(V,+,\cdot,\Bbb{P})$,

1. 称 $a_1,a_2,\dots,a_n\in V$ 为 $V$ 的一个 **向量组**
1. 对于 $k_1,k_2,\dots,k_n\in\Bbb{P}$, 称

   $$
   \sum_{i=1}^nk_ia_i
   $$

   为向量组 $a_1,a_2,\dots,a_n$ 的一个 **线性组合**

1. 若向量 $\beta\in V$ 可以表示为向量组 $a_1,a_2,\dots,a_n$ 的一个线性组合, 则称 $\beta$ 能被向量组 $a_1,a_2,\dots,a_n$ **线性表出**
1. 对于 $k_1,k_2,\dots,k_n\in\Bbb{P}$, 若向量组 $a_1,a_2,\dots,a_n$ 满足

   $$
   \sum_{i=1}^nk_ia_i=\theta\iff k_i=0, i=1,2,\dots,n
   $$

   则称向量组 $a_1,a_2,\dots,a_n$ **线性无关**, 否则称向量组 $a_1,a_2,\dots,a_n$ **线性相关**

{% endnote %}

容易得到以下性质

{% note primary no-icon %}

**<a id="pb-1-1">性质 - 1-1</a>** 对线性空间 $(V,+,\cdot,\Bbb{P})$,

1. 若向量组的一部分线性相关, 则向量组线性相关

   若向量组线性无关, 则其任意非空部分均线性无关

1. 含 $\theta$ 的向量组线性相关
1. 向量组线性相关当且仅当向量组的某个向量可以由其余向量线性表出
1. 若向量 $\beta$ 可被向量组 $a_1,a_2,\dots,a_n$ 线性表出, 则表出方式唯一当且仅当向量组 $a_1,a_2,\dots,a_n$ 线性无关
1. 若向量组 $a_1,a_2,\dots,a_n$ 线性无关, 则向量 $\beta$ 可被向量组 $a_1,a_2,\dots,a_n$ 线性表出当且仅当向量组 $a_1,a_2,\dots,a_n,\beta$ 线性相关

{% endnote %}

{% note info no-icon %}

**<a id="def-1-2">定义 - 1-2</a>** 对线性空间 $(V,+,\cdot,\Bbb{P})$,

1. 对于向量组 $b_1,b_2,\dots,b_m$, 令 $\{a_1,a_2,\dots,a_n\}\subseteq\{b_1,b_2,\dots,b_m\}$, 若

   - 向量组 $a_1,a_2,\dots,a_n$ 线性无关
   - $\forall\beta\in\{b_1,b_2,\dots,b_m\}\setminus\{a_1,a_2,\dots,a_n\}$, 向量组

     $$
     a_1,a_2,\dots,a_n,\beta
     $$

     线性相关

   则称向量组 $a_1,a_2,\dots,a_n$ 为向量组 $b_1,b_2,\dots,b_m$ 中的一个 **极大线性无关组**. 类似地, 可定义线性空间 $V$ 的极大线性无关组

   规定向量组 $\theta,\theta,\dots,\theta$ 的极大线性无关组为空集

   称向量组 $b_1,b_2,\dots,b_m$ 的极大线性无关组的大小为向量组的 **秩**, 记作 $\operatorname{rank}\{b_1,b_2,\dots,b_m\}$, 规定 $\operatorname{rank}\{\theta,\theta,\dots,\theta\}=0$

1. 若向量组 $a_1,a_2,\dots,a_n$ 能线性表出向量组 $b_1,b_2,\dots,b_m$ 中的所有向量, 称向量组 $b_1,b_2,\dots,b_m$ 能被向量组 $a_1,a_2,\dots,a_n$ 线性表出
1. 若向量组 $a_1,a_2,\dots,a_n$ 能被向量组 $b_1,b_2,\dots,b_m$ 线性表出, 且向量组 $b_1,b_2,\dots,b_m$ 能被向量组 $a_1,a_2,\dots,a_n$ 线性表出, 则称两向量组 **等价**, 记作

   $$
   \{a_1,a_2,\dots,a_n\}\cong\{b_1,b_2,\dots,b_m\}
   $$

1. 称

   $$
   \left\{v=\sum_{i=1}^nk_ia_i:a_i\in V,k_i\in\Bbb{P},i=1,2,\dots,n\right\}
   $$

   为由向量组 $a_1,a_2,\dots,a_n$ 张成的线性空间, 记作 $\operatorname{span}\{a_1,a_2,\dots,a_n\}$

{% endnote %}

容易得到以下性质

{% note primary no-icon %}

**<a id="pb-1-2">性质 - 1-2</a>** 对线性空间 $(V,+,\cdot,\Bbb{P})$,

1. 设向量组 $a_1,a_2,\dots,a_n$ 能被线性表出向量组 $b_1,b_2,\dots,b_m$ 线性表出
   - 若 $n>m$, 则向量组 $a_1,a_2,\dots,a_n$ 线性相关
   - 若向量组 $a_1,a_2,\dots,a_n$ 线性无关, 则 $n\leq m$
1. 等价的线性无关向量组的大小相等

   向量组的任意极大线性无关组的大小均相等

1. 向量组线性无关当且仅当其秩等于其大小
1. 若向量组 $a_1,a_2,\dots,a_n$ 能被线性表出向量组 $b_1,b_2,\dots,b_m$ 线性表出, 则 $\operatorname{rank}\{a_1,a_2,\dots,a_n\}\leq\operatorname{rank}\{b_1,b_2,\dots,b_m\}$

   等价的向量组的秩相等

{% endnote %}

## 线性基

### 定义

{% note info no-icon %}

**<a id="def-2-1">定义 - 2-1</a>** (Hamel 基) 称线性空间 $(V,+,\cdot,\Bbb{P})$ 的极大线性无关组为 $V$ 的一组 **Hamel 基** 或 **线性基**, 简称 **基**

令 $V$ 的 **维数** 为基的势, 记作 $\dim V$

规定线性空间 $\{\theta\}$ 的基为空集

{% endnote %}

由 Zorn 引理, 我们可以证明:

{% note success no-icon %}

**<a id="th-2-1">定理 - 2-1</a>** 任意线性空间均存在 Hamel 基

{% endnote %}

证明思路即设线性空间 $V$ 的全体线性无关向量组为 $\mathscr{F}$, 显然其上元素关于集合的包含关系成偏序集, 容易验证其上任意全序子集均有上界, 故由 Zorn 引理, $\mathscr{F}$ 有极大元 $F$, 容易验证 $F$ 即为线性空间 $V$ 的 Hamel 基

另外, 由 <a href="#pb-1-1">性质 - 1-1</a>, 在线性空间 $V$ 中, 任取一组基 $A=\{a_i\}$, 则任意向量 $v$ 均可被其线性表示, 且表示方式唯一, 设

$$
v=\sum_i k_i a_i,~k_i\in\Bbb{P},i=1,2,\dots
$$

称有序组 $(k_1,k_2,\dots)$ 为 $v$ 在基 $A$ 下的 **坐标**

### 性质 (有限维线性空间下)

对于有限维线性空间 $V$, 设其维数为 $n$, 则

1. $V$ 中的任意 $n+1$ 个向量线性相关
1. $V$ 中的任意 $n$ 个线性无关的向量均为 $V$ 的基
1. 若 $V$ 中的任意向量均可被向量组 $a_1,a_2,\dots,a_n$ 线性表出, 则其是 $V$ 的一个基

   {% note warning no-icon %}

   **<a id="att-2-1">注意 - 2-1</a>** 此处未要求向量组 $a_1,a_2,\dots,a_n$ 线性无关

   {% endnote %}

   <details open>
   <summary>证明</summary>

   任取 $V$ 中的一组基 $b_1,b_2,\dots,b_n$, 由已知条件, 向量组 $b_1,b_2,\dots,b_n$ 可被 $a_1,a_2,\dots,a_n$ 线性表出, 故

   $$
   n=\operatorname{rank}\{b_1,b_2,\dots,b_n\}\leq\operatorname{rank}\{a_1,a_2,\dots,a_n\}\leq n
   $$

   因此 $\operatorname{rank}\{a_1,a_2,\dots,a_n\}=n$

   </details>

1. $V$ 中任意线性无关向量组 $a_1,a_2,\dots,a_m$ 均可通过插入一些向量使得其变为 $V$ 的一个基

## 应用

线性基在算法竞赛中的应用一般包含以下方面

1. 对给定的向量组, 找到一组极大线性无关组 (或其张成的线性空间的一组基)
1. 向给定的向量组插入某些向量, 在插入操作后的向量组中找到一组极大线性无关组 (或其张成的线性空间的一组基)
1. 对找到的一组极大线性无关组 (或基), 判断某向量能否被其线性表出
1. 求极大线性无关组 (或基) 的秩

若限定向量均在 $\mathbb{Z}_2^n$ 下, 则称找到的基为 **异或线性基**

若限定向量均在 $\mathbb{R}^n$ 下, 则称找到的基为 **实数线性基**

### 异或线性基

具体内容参见 {% post_link xor-basis 异或线性基 %}

### 实数线性基

实数线性基的构造可通过 Gauss 消元法构造出准上三角矩阵, 然后去除所有零向量即可

---

## 参考资料

- 高等代数（下）. 丘维声.
- [Hamel Basis -- from Wolfram MathWorld](https://mathworld.wolfram.com/HamelBasis.html)
