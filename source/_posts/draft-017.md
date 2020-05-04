---
title: "随笔 - n 结点二叉搜索树计数问题"
date: 2021-12-16 02:43:17
categories:
  - 随笔
  - 数学
tags:
  - 随笔
  - 数学
  - 数据结构
  - 二叉树
  - 二叉搜索树
  - 生成函数
  - 组合数学
  - Catalan数
---

求 $n$ 个结点构成的二叉搜索树的形态总数

<!-- more -->

我们知道对于相同的数组 $\{a_i\}$, 由其构建的二叉搜索树的中序遍历结果唯一, 故本问题等价于求 $n$ 个结点构成的二叉树的形态总数

设 $n$ 个结点构成的二叉树的形态总数为 $f_n$, 首先 $f(0)=1$

当 $n>0$ 时, 不难得出如下结论

$$
f_n=\sum_{i=0}^{n-1}f_if_{n-i-1}
$$

即枚举左子树的结点个数递推即可

接下来我们计算 $f_n$ 的通项公式

设序列 $\{f_n\}$ 的生成函数为 $F(x)$, 则

$$
\begin{aligned}
    F(x)&=\sum_{n=0}^{\infty}f_nx^n\\
    &=1+\sum_{n=1}^{\infty}\sum_{i=0}^{n-1}f_if_{n-i-1}x^n\\
    &=1+x\left(\sum_{i=0}^{\infty}f_ix^i\right)\left(\sum_{n=0}^{\infty}f_nx^n\right)\\
    &=1+xF^2(x)
\end{aligned}\tag{1}
$$

从而得到

$$
\begin{aligned}
    F(x)={1\pm\sqrt{1-4x}\over 2x}={2\over 1\mp\sqrt{1-4x}}
\end{aligned}\tag{2}
$$

考虑 $F(0)$, 一方面, $F(0)=f_0=1$, 另一方面, 当且仅当

$$
F(x)={2\over 1+\sqrt{1-4x}}
$$

时, $F(x)$ 在 $x=0$ 处收敛, 因此

$$
F(x)={2\over 1+\sqrt{1-4x}}={1-\sqrt{1-4x}\over 2x}\tag{3}
$$

即为 $\{f_n\}$ 生成函数的封闭形式

接下来我们求其展开形式. 首先我们有

$$
\begin{aligned}
    (1-4x)^{1\over 2}&=\sum_{n=0}^{\infty}{ {1\over 2}\choose n}(-4x)^n\\
    &=1+\sum_{n=1}^{\infty}(-1)^{n-1}{(2n-3)!!\over 2^nn!}(-4x)^n\\
    &=1-2\sum_{n=1}^{\infty}{(2n-2)!\over n!(n-1)!}x^n
\end{aligned}\tag{4}
$$

将 $(4)$ 式代入 $(3)$ 式, 有

$$
\begin{aligned}
    F(x)&={1-\sqrt{1-4x}\over 2x}\\
    &=\sum_{n=1}^{\infty}{(2n-2)!\over n!(n-1)!}x^{n-1}\\
    &=\sum_{n=0}^{\infty}{(2n)!\over n!(n+1)!}x^n
\end{aligned}\tag{5}
$$

故

$$
f_n={(2n)!\over n!(n+1)!}={ {2n\choose n}\over n+1}\tag{6}
$$

即为所求. 本数列为 Catalan 数列
