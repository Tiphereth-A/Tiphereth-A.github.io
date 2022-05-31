---
title: 笔记 - Cantor展开与逆Cantor展开
categories:
  - 程序设计
  - 笔记
tags:
  - 程序设计
  - 算法
  - 笔记
  - 模板
  - 数学
  - 组合数学
  - Cantor展开
  - 逆Cantor展开
  - 树状数组
  - 平衡树
date: 2020-11-14 00:12:11
---

洛谷给我推了个模板题, 就顺便补一下笔记

Cantor 展开是用于求排列字典序的算法, 逆 Cantor 展开即根据字典序还原排列的算法

<!-- more -->

## 一些定义

- $\Z_a^b:=[a,b]\cap\Z$

  在不引起歧义的情况下, 可将$\Z_a^b$简记为$a..b$

- $f_n:=((n-1)!,(n-2)!,...,1!,0!)\in\N^n$
- $1..n$的排列: 称$A:=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})\in(\Z_1^n)^n$为$1..n$的排列, 若
  $$\{\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}\}=\{1,2,...,n\}$$

  为了方便下文叙述, 我们定义

  - $1..n$的所有排列组成的集合为$S_n$

    显然$|S_n|=n!$

  - 对$1..n$的排列$A=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})$,
    $$D_i(A):=\{(d_1,d_2,...,d_n)\in S_n~|~d_i<a_i;~\forall j\in \Z_1^{i-1}, d_j=a_j\}$$

    在不引起歧义的情况下, 可将$D_i(A)$简记为$D_i$

- $1..n$排列的字典序: 对$1..n$的排列$A=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 定义其序号为
  $$d(A)=\left|\bigcup_{i=1}^nD_i(A)\right|+1=\sum_{i=1}^n|D_i(A)|+1$$

  显然

  - $d(1,2,...,n)=1$
  - $d(n,n-1,...,1)=n!$

- 对$1..n$的排列$A=(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 定义$P_A:=(\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 其中$p_i=|\{a_j~|~a_j<a_i,\forall j\in\Z_i^n\}|,~i=1,2,...,n$

  如$P_{(3,2,1,4)}=(2,1,0,0)$

  显然$p_i\leqslant n-i$

## Cantor 展开

Cantor 展开即对$1..n$的排列$A$求$d(A)$的算法

我们有如下定理

### <a href="#end-t-1" id="t-1">定理 - 1</a>

对任意$1..n$的排列$A$, $|D_i(A)|=p_i(n-i)!$

#### <a href="#t-1" id="p-t-1">证明</a>

由乘法原理立得

<a href="#p-t-1" id="end-t-1">$\Box$</a>

自然的, 我们有推论

### <a href="#end-ifr-1" id="ifr-1">推论 - 1</a>

对任意$1..n$的排列$A$, $d(A)=P_Af_n^T+1=\sum_{i=1}^n p_i(n-i)!+1$

#### <a href="#ifr-1" id="p-ifr-1">证明</a>

$$d(A)=\sum_{i=1}^n|D_i(A)|+1=\sum_{i=1}^n p_i(n-i)!+1$$

<a href="#p-ifr-1" id="end-ifr-1">$\Box$</a>

设求$P_A$的时间复杂度为$O(P(n))$, 则该算法的时间复杂度是$O(P(n)+n)$, 所以算法复杂度的瓶颈就在于如何快速求$P_A$

显然暴力做法的复杂度是$O(n^2)$, 我们也可以使用树状数组将其优化到$O(n\log n)$

所以该算法的复杂度即为$O(n\log n)$

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp cantor-exp/Cantor_expansion.hpp %}

</details>

## 逆 Cantor 展开

逆 Cantor 展开即对$1..n$的排列$A$, 已知$d(A)$求$A$的算法

首先我们有定理

### <a href="#end-t-2" id="t-2">定理 - 2</a>

$$\forall n\in\N^+,~n!=\sum_{i=0}^{n-1}i\cdot i!$$

#### <a href="#t-2" id="p-t-2">证明</a>

$$
\begin{aligned}
  n!&=(n-1+1)\cdot(n-1)!\\
  &=(n-1)\cdot(n-1)!+(n-1)!\\
  &=(n-1)\cdot(n-1)!+(n-2)!\cdot(n-2)!+(n-3)!\\
  &...\\
  &=\sum_{i=0}^{n-1}i\cdot i!
\end{aligned}
$$

<a href="#p-t-2" id="end-t-2">$\Box$</a>

也就是说, $n!=\sum_{i=1}^n(n-i)\cdot (n-i)!\geqslant\sum_{i=1}^np_i(n-i)!$

此式说明, 对于给定的$d(A)$
$$p_i=\left\lfloor{d(A)-\sum_{j=1}^{i-1}p_j(n-j)!-1\over (n-i)!}\right\rfloor$$

显然$P_A$可以$O(n)$求得

设根据$P_A$求$A$的时间复杂度为$O(P'(n))$, 则该算法的时间复杂度为$O(P'(n)+n)$, 所以算法复杂度的瓶颈就在于如何快速根据$P_A$求$A$

显然暴力做法的复杂度是$O(n^2)$, 我们也可以使用平衡树等将其优化到$O(n\log n)$

所以该算法的复杂度即为$O(n\log n)$

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp cantor-exp/inverse_Cantor_expansion.hpp %}

</details>

## 例题

- 洛谷 [P5367 【模板】康托展开](https://www.luogu.com.cn/problem/P5367)
- 洛谷 [P3014 [USACO11FEB]Cow Line S](https://www.luogu.com.cn/problem/P3014)
- [CF501D Misha and Permutations Summation](https://codeforces.com/problemset/problem/501/D) -> {% post_link cf501d 题解 %}

---

## 参考资料

- <https://zhuanlan.zhihu.com/p/272721663>
- <https://www.luogu.com.cn/blog/_post/53743>
