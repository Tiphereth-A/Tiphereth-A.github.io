---
title: 笔记 - 扩展中国剩余定理(exCRT)
categories:
  - 笔记
  - 算法竞赛
tags:
  - 算法竞赛
  - 笔记
  - 模板
  - 数学
  - 数论
  - 扩展中国剩余定理(exCRT)
  - exgcd
date: 2020-10-06 21:45:51
---

我们都知道, CRT 用于求解的方程组要求其模数必须两两互素, 而 exCRT 则没有这条限制

{% note warning %}
<https://cplib.tifa-233.com/src/code/nt/crt_mod.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

<!-- more -->

## 介绍

为什么 CRT 要求其模数必须两两互素?

因为 CRT 的关键便是构造这样的方程组

$$
\begin{cases}
  x\equiv1\pmod{m_i}\\
  x\equiv0\pmod{m_j}~(j\ne i)
\end{cases}
$$

此时的 $x=M_iN_i$, $M_i=\prod_{j=1,j\ne i}^km_j$, 而 $N_i$ 是 $M_i$ 关于 $m_i$ 的**逆元**

我们知道, 如果一个整数 $a$ 在模 $m$ 意义下有逆元, 其前提之一便是 $(a,m)=1$

在此处便是 $(M_i,m_i)=1$

故由最大公约数的性质, 此处的 $k$ 个模数 $m_1,m_2,\dots,m_k$ 必须两两互素

那么我们能不能摆脱这个限制条件呢?

当然可以!

这就要求我们在构建解的时候绕开 CRT 的证明, 另辟蹊径

我们观察下面的式子

$$
\begin{cases}
    x\equiv b_1\pmod{m_1}\\
    x\equiv b_2\pmod{m_2}
\end{cases}
$$

由同余定义, 我们有

$$
\begin{cases}
    m_1\mid x-b_1\\
    m_2\mid x-b_2
\end{cases}
$$

即存在整数 $k_1,k_2$ 使得

$$
x=m_1k_1+b_1=m_2k_2+b_2
$$

整理一下, 便有

$$
m_1k_1-m_2k_2=b_2-b_1\tag{1}
$$

此时我们便可以通过扩欧去解决 $(1)$ 式的可解性和一组可行解

更重要的是: 此时不需要 $(m_1,m_2)=1$

求出 $k_1,k_2$ 之后便可得到

$$
x\equiv m_1k_1+b_1\equiv m_2k_2+b_2\pmod{[m_1,m_2]}
$$

## 代码

{% icodeweb blog lang:cpp excrt/EXCRT.hpp %}
