---
title: "随笔 - Miller-Rabin + Pollard-Rho 分解质因子的时间复杂度分析"
date: 2024-11-29 20:43:13
categories:
  - 随笔
  - 算法竞赛
tags:
  - 随笔
  - 算法竞赛
  - 数学
  - 数论
  - Miller-Rabin算法
  - Pollard-Rho算法
  - 素数/质数
  - 素性检验
  - Ramanujan和
  - 凹函数
  - Jensen不等式
---

省流版: $O\left(n^{1/4}\right)$

<!-- more -->

我们考虑这样的代码

{% icodeweb blog lang:python draft-020/pfactors.cpp %}

其中

- `is_prime_miller_rabin` 为基于 Miller-Rabin 算法的质数判断, 时间复杂度为 $O\left(n^{1/4}\right)$
- `pollard_rho` 为 Pollard-Rho 算法, 返回入参的一个非平凡因子, 期望时间复杂度为 $O\left(p^{1/2}\right)$, 其中 $p$ 为 $n$ 的最小质因子, 不难发现 Pollard-Rho 算法的期望时间复杂度为 $O\left(n^{1/4}\right)$
- 回调函数 `callback` 的时间复杂度为 $O(1)$

我们尝试计算 `pfactors` 的时间复杂度, 设其为 $O(T(n))$, 则有

$$
O(T(n)) = \begin{cases}
  O\left(n^{1/4}\right),&n<2\lor n\in\mathbb{P},\\
  O\left(n^{1/4}+T(d)+T(n/d)\right),&\text{otherwise},
\end{cases}
$$

其中 $d$ 为 $n$ 的某个非平凡因子, $T(d)$ 没法直接处理, 我们用均值代替:

$$
\begin{aligned}
  T(d)+T(n/d)&\xlongequal{\exists C>0}C\dfrac{\sum_{1<d<n;d\mid n}(T(d)+T(n/d))}{\sum_{1<d<n;d\mid n}1}\\
  &=2C\dfrac{\sum_{1<d<n;d\mid n}T(d)}{\sum_{1<d<n;d\mid n}1}
\end{aligned}
$$

所以

$$
O(T(n)) = \begin{cases}
  O\left(n^{1/4}\right),&n<2\lor n\in\mathbb{P},\\
  O\left(n^{1/4}+\dfrac{\sum_{1<d<n;d\mid n}T(d)}{\sum_{1<d<n;d\mid n}1}\right),&\text{otherwise},
\end{cases}
$$

我们希望证明 $O(T(n))=O\left(n^{1/4}\right)$, 不难发现若

$$
O\left(\dfrac{\sum_{d\mid n}d^{1/4}}{\sum_{d\mid n}1}\right)=O\left(\dfrac{\sigma_{1/4}(n)}{\sigma_{0}(n)}\right)=O\left(n^{1/4}\right)\tag{1}
$$

成立, 则可以通过数学归纳法证明

我们知道, 当 $k>0$ 时

$$
\sigma_k(n)=\zeta(k+1)n^k\sum_{m=1}^{\infty}\frac{c_m(n)}{m^{k+1}}\tag{2}
$$

其中 $c_q(n)=\displaystyle\sum_{1\leq a\leq q;(a,q)=1}\mathrm{e}^{(2\pi\mathrm{i}an)/q}$ 为 [Ramanujan 和](https://en.wikipedia.org/wiki/Ramanujan_sum), 所以这个看起来是有搞头的, 不过 $(2)$ 式涉及到级数, 看起来就不好用, 所以我们不会用 $(2)$ 式去证 $(1)$ 式, 而是一个更简单的做法

注意到 $f(x)=x^{1/4}$ 是凹函数, 所以我们考虑 Jensen 不等式

$$
\begin{aligned}
  \dfrac{\sum_{d\mid n}d^{1/4}}{\sum_{d\mid n}1}&\leq\left(\dfrac{\sum_{d\mid n}d}{\sum_{d\mid n}1}\right)^{1/4}\\
  &=\left(\dfrac{\sigma_1(n)}{\sigma_0(n)}\right)^{1/4}\\
  &=O\left(\left(\dfrac{n\log\log n}{\log n}\right)^{1/4}\right)\\
  &\xlongequal{\exists\epsilon>0} O\left(n^{1/4-\epsilon}\right)
\end{aligned}
$$

综上所述, `pfactors` 的时间复杂度为 $O\left(n^{1/4}\right)$
