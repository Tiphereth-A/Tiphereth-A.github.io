---
title: 随笔 - Chicken McNugget定理 (麦乐鸡定理)
categories:
  - 随笔
  - 数学
tags:
  - 数学
  - 随笔
  - 数论
  - Chicken McNugget定理
  - Bézout定理
  - Fermat小定理
date: 2022-10-16 22:17:45
---

两个整数的正线性组合所不能表示的最大数是多少?

<!-- more -->

{% note success no-icon %}

**<a id="th-1-1">定理 - 1-1</a>** (Chicken McNugget 定理) 对任意两个 **互素** 的正整数 $a,b$, 令

$$A=\mathbb{Z}\setminus\{ax+by:x,y\in\mathbb{N}\}$$

则

$$\max A=ab-a-b$$

{% endnote %}

## 直观理解

|        $0\bmod a$        |        $1\bmod a$        |        $2\bmod a$        |         $\dots$          |            $\dots$             |         $\dots$          |      $(a-1)\bmod a$      |
| :----------------------: | :----------------------: | :----------------------: | :----------------------: | :----------------------------: | :----------------------: | :----------------------: |
|      $\xcancel{0b}$      |           $1$            |           $2$            |         $\dots$          |            $\dots$             |         $\dots$          |          $a-1$           |
|     $\xcancel{0b+a}$     |         $\dots$          |
| $\xcancel{\phantom{0b}}$ |                          |                          |      $\xcancel{1b}$      |            $\dots$             |                          |
|         $\vdots$         |                          |                          |         $\vdots$         |
| $\xcancel{\phantom{0b}}$ |                          |                          | $\xcancel{\phantom{1b}}$ |            $\dots$             |      $\xcancel{2b}$      |                          |
|         $\vdots$         |                          |                          |         $\vdots$         |                                |         $\vdots$         |                          |
| $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ |           $(a-1)b-a$           | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ |
| $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{(a-1)b-a}}$ | $\xcancel{\phantom{0b}}$ | $\xcancel{\phantom{0b}}$ |

## 证明

如果 $n\in A$, 那么要想让 $n$ 最大, 我们首先需要让 $x=-1$ 或者 $y=-1$

假设 $x=-1$, 此时设 $y=y'$

我们有通式

$$
\begin{cases}
    x=-1+bt\\
    y=y'-at
\end{cases}
$$

因为 $b>1$, $x$ 随 $t$ 严格单调递增, $y$ 随 $t$ 严格单调递减

所以要想让 $n\in A$, 我们需要让 $y$ 在 $t=1$ 时为负数

即

$$y'-a<0\implies y'<a$$

由于 $y'$ 是整数, 所以 $y'$ 最大只能取 $a-1$

此时对应的 $n$ 即为

$$a\times(-1)+b(a-1)=ab-a-b$$

如果假设 $y=-1$, 也可推得相似结论

因为我们在这过程中取的都是最大值, 所以 $ab-a-b$ 即为 $\max A$

接下来证明: $n\notin A~(\forall n>ab-a-b)$

设 $ax_0+by_0=n,~x_0\geqslant 0$, 则只需证 $y_0\geqslant 0$

取 $x_0=n\bmod b$, 则 $x_0\in[0,b-1]$, 有

$$
\begin{aligned}
  by_0&=n-ax_0\\
  &\geqslant n-a(b-1)\\
  &>ab-a-b-a(b-1)\\
  &=-b
\end{aligned}
$$

即 $b(y_0+1)>0$, 从而有 $y_0\geqslant 0$

## 推论

{% note success no-icon %}

**<a id="coll-1-1">推论 - 1-1</a>** 对任意整数 $k$, $k\in A$ 和 $ab-a-b-k\in A$ 恰有一个成立

{% endnote %}

## 推广

{% note success no-icon %}

**<a id="th-1-2">定理 - 1-2</a>** 对任意两个正整数 $a,b$, 令

$$A=\mathbb{Z}\setminus\{ax+by:x,y\in\mathbb{N}\}$$

则

$$\max A=\operatorname{lcm}\{a,b\}-a-b$$

<details open>
<summary>证明</summary>

注意到

$$ax+by=\gcd\{a,b\}\left(x\frac{a}{\gcd\{a,b\}}+y\frac{b}{\gcd\{a,b\}}\right)$$

对括号内的部分应用 <a href="#th-1-1">定理 - 1-1</a>, 则

$$
\begin{aligned}
  \max A&=\gcd\{a,b\}\left(\frac{ab}{\gcd^2\{a,b\}}-\frac{a}{\gcd\{a,b\}}-\frac{b}{\gcd\{a,b\}}\right)\\
  &=\operatorname{lcm}\{a,b\}-a-b
\end{aligned}
$$

</details>

{% endnote %}

## 参考资料

- [Art of Problem Solving](https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem)
