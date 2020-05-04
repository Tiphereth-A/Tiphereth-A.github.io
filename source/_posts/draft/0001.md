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

$\;$

<!-- more -->

在证明卷积的结合律时, 会涉及到二重求和的处理

$$
\begin{aligned}
  f*(g*h)(n)&=\sum_{e|n}f(e)\sum_{d'|\frac{n}{e}}g(d')h(\frac{n}{d'e})\\
  &=\sum_{e|n}\sum_{d'|\frac{n}{e}}f(e)g(d')h(\frac{n}{d'e})\\
  &=\sum_{d|n}\sum_{e|d}f(e)g(\frac{d}{e})h(\frac{n}{d})\\
  (&=\sum_{abc=n}f(a)g(b)h(c))
\end{aligned}
$$

其中第二个等号与第三个等号的转化值得注意, 它分为如下过程:

$$\sum_{e\mid n}\sum_{d'\mid\frac{n}{e}}\xrightarrow[(1)]{d'\to\frac{d}{e}}\sum_{e\mid n}\sum_{\frac{d}{e}\mid\frac{n}{e}}\xrightarrow[(2)]{}\sum_{e\mid n}\sum_{e\mid d\mid n}\xrightarrow[(3)]{\text{交换求和号}}\sum_{d\mid n}\sum_{e\mid d}$$

> $\displaystyle\sum_{\frac{d}{e}\mid\frac{n}{e}}$的下标用`\frac{d }{e} \mid \frac{n }{e}`会出 bug, 要用`\frac{d}{e} \mid \frac{n}{e}`, 不知道为什么

其中:

- (1) 就是换元

- (2) 依赖如下定理:

### <a href="#end-t-1" id="t-1">定理 - 1</a>

$$\frac{d}{e}\mid \frac{n}{e}\iff e\mid d\mid n$$

#### <a href="#t-1" id="p-t-1">证明</a>

- $\implies$

  一方面, $\displaystyle\frac{d}{e}\mid \frac{n}{e}\implies (e\cdot\frac{d}{e})\mid (e\cdot\frac{n}{e})\implies d\mid n$

  另一方面, $\frac{d}{e}\in\Z\implies e\mid d$

  故$e\mid d\mid n$

- $\impliedby$

  由$e\mid d\mid n$可知$\displaystyle\frac{n}{e},\frac{n}{d},\frac{d}{e}\in\Z$

  又$\displaystyle\frac{n}{e}=\frac{n}{d}\cdot\frac{d}{e}$

  故$\displaystyle\frac{d}{e}\mid \frac{n}{e}$

  <a href="#p-t-1" id="end-t-1">$\Box$</a>

- (3) 即是交换枚举顺序, 即 先枚举$e$后枚举$d\longrightarrow$先枚举$d$后枚举$e$

  交换前即为先枚举$n$的因子$e$, 再枚举$d$满足既是$n$的**因子**也是$e$的**倍数**

  交换后即为先枚举$n$的因子$d$, 再枚举$e$满足既是$n$的**因子**也是$d$的**因子**, 即枚举$d$的因子$e$
