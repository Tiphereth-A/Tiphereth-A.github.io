---
title: 随笔 - 从卷积的结合律看多重求和
categories:
  - 随笔
  - 数学
tags:
  - 数学
  - 随笔
  - 数论
  - 卷积
date: 2020-05-28 13:02:58
---

在证明卷积的结合律时, 会涉及到二重求和的处理

<!-- more -->

$$
\begin{aligned}
  f*(g*h)(n)&=\sum_{e|n}f(e)\sum_{d'|\frac{n}{e}}g(d')h\left(\frac{n}{d'e}\right)\\
  &=\sum_{e|n}\sum_{d'|\frac{n}{e}}f(e)g\left(d'\right)h\left(\frac{n}{d'e}\right)\\
  &=\sum_{d|n}\sum_{e|d}f(e)g\left(\frac{d}{e}\right)h\left(\frac{n}{d}\right)\\
  &=\sum_{abc=n}f(a)g(b)h(c)
\end{aligned}
$$

其中第二个等号与第三个等号的转化值得注意, 它分为如下过程:

$$
\sum_{e\mid n}\sum_{d'\mid\frac{n}{e}}\xrightarrow[(1)]{d'\to\frac{d}{e}}\sum_{e\mid n}\sum_{\frac{d}{e}\mid\frac{n}{e}}\xrightarrow[(2)]{}\sum_{e\mid n}\sum_{e\mid d\mid n}\xrightarrow[(3)]{\text{Swap}}\sum_{d\mid n}\sum_{e\mid d}
$$

其中:

- $(1)$ 就是换元

- $(2)$ 依赖如下定理:

  {% note success no-icon %}

  **<a id="th-1-1">定理 - 1-1</a>**

  $$
  \frac{d}{e}\mid \frac{n}{e}\iff e\mid d\mid n
  $$

  <details open>
  <summary>证明</summary>

  - $\implies$

    一方面

    $$
    \frac{d}{e}\mid \frac{n}{e}\implies \left(e\cdot\frac{d}{e}\right)\mid \left(e\cdot\frac{n}{e}\right)\implies d\mid n
    $$

    另一方面

    $$
    \frac{d}{e}\in\mathbb{Z}\implies e\mid d
    $$

    故 $e\mid d\mid n$

  - $\impliedby$

    由 $e\mid d\mid n$ 可知

    $$
    \frac{n}{e},\frac{n}{d},\frac{d}{e}\in\mathbb{Z}
    $$

    又

    $$
    \frac{n}{e}=\frac{n}{d}\cdot\frac{d}{e}
    $$

    故

    $$
    \frac{d}{e}\mid \frac{n}{e}
    $$

  </details>

  {% endnote %}

- $(3)$ 即是交换枚举顺序, 即 先枚举 $e$ 后枚举 $d\longrightarrow$ 先枚举 $d$ 后枚举 $e$

  交换前即为先枚举 $n$ 的因子 $e$, 再枚举 $d$ 满足既是 $n$ 的**因子**也是 $e$ 的**倍数**

  交换后即为先枚举 $n$ 的因子 $d$, 再枚举 $e$ 满足既是 $n$ 的**因子**也是 $d$ 的**因子**, 即枚举 $d$ 的因子 $e$
