---
title: "笔记 - 整除, 素数, gcd & lcm, 同余, 逆元, CRT, exCRT"
categories:
  - 笔记
  - 算法竞赛
  - 数学
tags:
  - 数学
  - 算法竞赛
  - 笔记
  - 模板
  - 数论
  - 整除
  - 素数/质数
  - 筛法
  - Eratosthenes筛
  - Euler筛
  - 最大公约数
  - 最小公倍数
  - 辗转相除法
  - Bézout定理
  - 同余
  - exgcd
  - Wilson定理
  - Fermat小定理
  - Euler定理
  - 逆元
  - 中国剩余定理(CRT)
  - 扩展中国剩余定理(exCRT)
  - 构造
date: 2020-10-04 01:14:43
---

整除, 素数, 最大公约数 & 最小公倍数, 同余, 逆元, 中国剩余定理

<!-- more -->

## 整除

对于整数 $a,b$, 若 $\exists k~s.t.~a=kb$, 则称 $b$ 整除 $a$, 记作 $b\mid a$, 否则称 $b$ 不整除 $a$, 记作 $b\nmid a$

### 性质

1. $a\mid b,b\mid c\implies a\mid c$
1. $a\mid b,b\mid a\implies a=\pm b$
1. $a\mid b,a\mid c\implies\forall x,y\in\mathbb{Z},~a\mid bx+cy$

### 带余除法

#### <a href="#end-t-1.1" id="t-1.1">定理 - 1.1</a> (带余除法)

设 $a,b\in\mathbb{Z}$, 且 $b\geqslant1$, 则存在唯一的整数 $q,r$ 使得

$$
a=qb+r,r\in[0,b)\cap\mathbb{N}
$$

##### <a href="#t-1.1" id="p-t-1.1">证明</a>

首先, 取 $q=\lfloor\frac{a}{b}\rfloor$, $r=a-qb$, 容易验证此时的 $q,r$ 满足条件

下证唯一性, 假设又有一组整数 $q',r'$ 使得 $a=q'b-r',~r'\in[0,b)\cap\mathbb{N}$, 则

$$
0=a-a=(q-q')b+(r-r')
$$

因此 $b\mid r-r'$

而 $|r-r'|\in[0,b)\cap\mathbb{N}$, 故只能有 $r-r'=0$, 即 $r=r'$

此时 $a-qb=a-q'b$, 有 $q=q'$

<a href="#p-t-1.1" id="end-t-1.1">$\Box$</a>

接下来我们给出一个整数集的重要性质

#### <a href="#end-t-1.2" id="t-1.2">定理 - 1.2</a>

设 $S$ 为非空整数集, 若 $S$ 关于整数的加减法封闭, 即

- 若 $a,b\in S$, 则 $a\pm b\in S$

则存在唯一自然数 $d$ 使得 $S=d\mathbb{Z}:=\{da|a\in\mathbb{Z}\}$

> 条件中隐含了一点:
>
> - 若 $a\in S$, 则 $\forall c\in\mathbb{Z},~ac\in S$

一般的, 若 $S$ 为主理想环, 则 $\exists_1 d\in\mathbb{Z}~s.t.~S=\lang d\rang$

##### <a href="#t-1.2" id="p-t-1.2">证明</a>

若 $S=\{0\}$, 则只能取 $d=0$

设 $0\ne a\in S$, 则 $0=a-a\in S,-a=(-1)\times a\in S$, 故此时 $S$ 中必有正整数

由良序公理可知 $S$ 中的所有正整数中必有最小值, 令 $d$ 为 $S$ 中的最小正整数, 下证 $S=d\mathbb{Z}$

首先易得 $d\mathbb{Z}\subseteq S$

之后我们在 $S$ 中任取整数 $a$ 做带余除法

$$
a=qd+r,~q\in\mathbb{Z},r\in[0,d)\cap\mathbb{N}
$$

可知 $r=a-qd\in S$, 而 $d$ 为 $S$ 中的最小正整数, 故必有 $r=0$

这表明 $a=qd\in d\mathbb{Z}$, 因此 $S\subseteq d\mathbb{Z}$

最后, 注意到 $d$ 为 $S$ 中的最小正整数, 则满足 $S=d\mathbb{Z}$ 的 $d$ 一定是唯一的

<a href="#p-t-1.2" id="end-t-1.2">$\Box$</a>

### 例题

- 设 $n$ 是大于 1 的整数, 证明: $\displaystyle\sum_{i=1}^n\frac{1}{i}$ 不是整数
- 洛谷 [P2651 添加括号 III](https://www.luogu.com.cn/problem/P2651)

## 素数/质数

即只能被 1 和其自身整除且大于 1 的数

不满足上述条件, 但大于 1 的数称为合数

1 既不是素数也不是合数

### <a href="#end-t-2.1" id="t-2.1">定理 - 2.1</a>

素数有无限多个

#### <a href="#t-2.1" id="p-t-2.1">证明</a> (Euclid)

假设素数只有有限个, 记作 $a_1,a_2,\dots,a_n$

考虑 $N=\prod_{i=1}^np_i+1$, 显然 $N>2$

由于 $N\ne p_i,i=1,2,...,n$, 故必有 $N$ 必有素因子 $p$

但 $p_i\nmid N,i=1,2,...,n$, 故 $p$ 是 $p_1,p_2,\dots,p_n$ 以外的素数, 这与假设矛盾

<a href="#p-t-2.1" id="end-t-2.1">$\Box$</a>

### 唯一分解定理

#### <a href="#end-t-2.2" id="t-2.2">定理 - 2.2</a>

所有大于 1 的整数均可分解为有限个素数的乘积, 若不计各素数出现的顺序, 则这种分解唯一

证明略

<a href="#t-2.2" id="end-t-2.2">$\Box$</a>

### 素数分布

如果令 $\pi(n)$ 表示 $[1,n]$ 中的素数个数, 则我们有

$$
\pi(n)\sim\frac{n}{\ln n}~(n\to\infty)
$$

或者写成

$$
\lim_{n\to\infty}{\pi(n)\over\frac{n}{\ln n}}=1
$$

证明略

### 素数判定

这里给出一个简单的做法

首先, 我们不难证明: 若 $n$ 是合数, 则其必有一个因子 $d\in(1,\sqrt n]\cap\mathbb{N}$

所以对于要判定的整数`n`, 我们只需在`2..sqrt(n)`中枚举整数`i`验证即可

{% icodeweb blog lang:cpp nt-1/is_prime.cpp %}

时间复杂度: $O(\sqrt n)$

有没有更好的方法呢?

我们有时间复杂度为 $O(k\log^3n)$ 的 Miller-Rabin 算法进行素性检验[^1], 其中 $k$ 为用于检验的数的个数[^2]

因其原理涉及到后面要讲的概念, 故此处略去相关讲解

> Miller-Rabin 算法和用于质因数分解的 Pollard-Rho 算法的模板 -> {% post_link p-test-mrpr %}

[^1]: 可以用 FFT 优化到 $O(k\log^2 n\log\log n\log\log\log n)$ , 参见 [此处](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Complexity)

[^2]: 若广义 Riemann 猜想(GRH)得到证实, 则可将检验的数换为 $2..2\lfloor\log^2 n\rfloor$ 从而使复杂度变为 $O(\log^5n)$, 参见 [此处](https://www.ams.org/mcom/1990-55-191/S0025-5718-1990-1023756-8/S0025-5718-1990-1023756-8.pdf)

### 素数筛法

如何求出 $[1,n]$ 中的所有素数?

最朴素的做法就是对 `1..n` 中的每个数分别应用上述素数判定法, 时间复杂度: $O(n\sqrt n)$

接下来我们介绍两种更加高效的算法: Eratosthenes 筛法 和 Euler 筛法

#### Eratosthenes 筛法

又称埃氏筛

我们注意到这样的事实: 合数 $x$ 的倍数也是合数

所以我们可以这样操作:

- `2..n`从小到大枚举, 如果当前枚举的数没被标记为合数, 我们就认为这个数是素数
  - 如果这个数是素数, 我们将其倍数标记为合数

{% icodeweb blog lang:cpp nt-1/Eratosthenes_sieve.cpp %}

##### 时间复杂度

易知

$$
T(n)=\sum_{p\in\{prime\}\cap[2,n]}\left\lfloor\frac{n}{i}\right\rfloor
$$

而

$$
\begin{aligned}
  O(T(n))&=O\left(\sum_{p\in\{prime\}\cap[2,n]}\left\lfloor\frac{n}{i}\right\rfloor\right)\\
  &=O\left(n\sum_{p\in\{prime\}\cap[2,n]}\left\lfloor\frac{1}{p}\right\rfloor\right)\\
  &=O(n\log\log n)
\end{aligned}
$$

故时间复杂度为 $O(n\log\log n)$

#### Euler 筛法

我们发现在 Eratosthenes 筛法中, 有些数会被多次标记为合数, 我们能不能做到只标记一次呢?

当然可以!

{% icodeweb blog lang:cpp nt-1/Euler_sieve.cpp %}

##### 时间复杂度

因为每个数只被标记一次, 所以时间复杂度显然为 $O(n)$

### 例题

- 洛谷 [P3383 【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)
- 洛谷 [P2926 [USACO08DEC]Patting Heads S](https://www.luogu.com.cn/problem/P2926)
- 洛谷 [P1835 素数密度](https://www.luogu.com.cn/problem/P1835)

## 最大公约数 & 最小公倍数

对于两个**不全为零**的**整数**$a,b$

最大公约数即为 $a,b$ 中最大的正公因数, 记作 $(a,b)$, 或者 $\gcd(a,b)$

最小公倍数即为 $a,b$ 中最小的正公倍数, 记作 $[a,b]$, 或者 $\operatorname{lcm}(a,b)$

写成式子就是

$$
(a,b):=\max\{d\in\mathbb{N}^*|d\mid a,d\mid b\}
$$

$$
[a,b]:=\min\{d\in\mathbb{N}^*|a\mid d,b\mid d\}
$$

这一组概念自然可以推广到多个整数之间

$$
(a_1,a_2,\dots,a_n):=\max\{d\in\mathbb{N}^*|d\mid a_i,~i=1,2,...,n\}
$$

$$
[a_1,a_2,\dots,a_n]:=\min\{d\in\mathbb{N}^*|a_i\mid d,~i=1,2,...,n\}
$$

### 性质

1. $[a,b](a,b)=|ab|$

#### 最大公约数

1. $(a,b)=(b,a)=(|a|,b)=(|a|,|b|)$
1. 当 $a\ne 0$ 时, $(a,a)=|a|$
1. 若 $a_1\ne 0$, 则 $(a_1,a_2,\dots,a_n)=((a_{1},a_{2}),a_{3},...,a_{n})$
1. $\forall l\in\mathbb{Z},~(a,b)=(a,b+la)$
1. $\forall m\in\mathbb{N}^*,~m(a_1,a_2,\dots,a_n)=(ma_1,ma_2,\dots,ma_n)$
1. 若 $(a_1,a_2,\dots,a_n)=d$, 则 $(\frac{a_1}{d},\frac{a_2}{d},...,\frac{a_n}{d})=1$
1. 对于整数 $m$, 若 $(a_i,m)=1,~i=1,2,...,n$, 则 $(\prod_{i=1}^na_i,m)=1$
1. 设 $a_1,a_2,\dots,a_n$ 是不全为零的整数, $(a_1,a_2,\dots,a_n)=d$, 则
   $$
   \left\{\sum_{i=1}^na_ix_i\bigg|x_i\in\mathbb{Z},i=1,2,...,n\right\}=d\mathbb{Z}
   $$
1. 设 $c\in\mathbb{Z}/\{0\},a,b\in\mathbb{Z}$, 若 $c\mid ab,(c,b)=1$, 则 $c\mid a$
   - 特别地, 若 $p$ 为素数, $p\mid ab$, 则 $p\mid a$ 或 $p\mid b$

下面对性质 8 给出证明

##### <a href="#end-t-3.1" id="t-3.1">定理 - 3.1</a>(性质 8, Bézout 定理)

设 $a_1,a_2,\dots,a_n$ 是不全为零的整数, $(a_1,a_2,\dots,a_n)=d$, 则

$$
S:=\left\{\sum_{i=1}^na_ix_i\bigg|x_i\in\mathbb{Z},i=1,2,...,n\right\}=d\mathbb{Z}
$$

###### <a href="#t-3.1" id="p-t-3.1">证明</a>

由 <a href="#t-1.2">定理 - 1.2</a> 可知, 存在正整数 $a$ 使得 $S=a\mathbb{Z}$, 接下来只需证 $a=d$

一方面, $d$ 是 $S$ 中所有数的因子, 而 $a\in S$, 故 $d\mid a$

另一方面, 注意到 $a_1,a_2,\dots,a_n\in S$, 故 $a$ 是 $a_1,a_2,\dots,a_n$ 的公因子, 即有

$$
a\mid(a_1,a_2,\dots,a_n)=d
$$

因此 $a=d$

<a href="#p-t-3.1" id="end-t-3.1">$\Box$</a>

#### 最小公倍数

1. $[a_1,a_2,\dots,a_n]=[[a_1,a_2],a_3,...,a_n]$
1. $\forall m\in\mathbb{N}^*,~[ma_1,ma_2,\dots,ma_n]=m[a_1,a_2,\dots,a_n]$
1. 若 $a_1,a_2,\dots,a_n$ 两两互素, 则 $[a_1,a_2,\dots,a_n]=|\prod_{i=1}^na_i|$

### 求法

求最小公倍数只需求出最大公约数即可

而由于 $\forall l\in\mathbb{Z},~(a,b)=(a,b+la)$, 我们可推出:

- 若 $b\ne 0$, 则 $(a,b)=(b,a\bmod b)$

之后我们便可递归下去, 当 $b=0$ 时, 答案即为 $a$

这就是**辗转相除法**

{% icodeweb blog lang:cpp nt-1/gcd.cpp %}

#### 时间复杂度

我们知道, $b\to a \bmod b$ 这个过程中, $b$ 的值大致可认为是减半, 所以时间复杂度为 $O(\log n)$

最坏情况即为对两相邻的 Fibonacci 数求最大公约数

> Fibonacci 数的定义如下:
>
> $$
> F_i:=\begin{cases}
> 0,&i=0\\
> 1,&i=1\\
> F_{i-1}+F_{i-2},&i>1
> \end{cases}
> $$
>
> 容易求得
>
> $$
> F_n=\frac{\phi^n-(1-\phi)^n}{\sqrt 5},~\phi={1+\sqrt{5}\over2}
> $$

计算 $(F_{n+1},F_{n})$ 需要 $n$ 次迭代, 此时的时间复杂度也为 $O(\log n)$

> 实际上求 gcd 是有 $O(1)$ 算法的, 此次略去

### 扩展 Euclid (exgcd)

用于对给定的 $a,b,c$, 寻找 $ax+by=c$ 的一组可行解

首先, 由 <a href="#t-3.1">Bézout 定理</a>, 若 $(a,b)\nmid c$, 则该方程无解

接下来, 令 $d=\frac{c}{(a,b)}$, 则求出 $ax+by=(a,b)$ 的一组解 $x=x',y=y'$ 后, 容易得知 $x=dx',y=dy'$ 即为 $ax+by=c$ 的一组解

另外, 若 $ax+by=c$ 有一组解 $x=x',y=y'$, 则

$$
\begin{cases}
  x=x'-bt\\
  y=y'+at
\end{cases}(t\in\mathbb{Z})
$$

也为该方程的解, 所以方程 $ax+by=c$ 若有解, 则必有无数组解

经过如下分析, 我们发现: 求出方程 $ax+by=(a,b)$ 的一组解是关键, 下面给出求法

#### 求法

考虑这两个式子

$$
\begin{aligned}
  ax+by&=(a,b)\\
  bx'+(a\bmod b)y'&=(b,a\bmod b)=(a,b)
\end{aligned}
$$

注意到

$$
a\bmod b=a-\left\lfloor\frac{a}{b}\right\rfloor b
$$

故

$$
ax+by=bx'+(a-\left\lfloor\frac{a}{b}\right\rfloor b)y'
$$

可知

$$
\begin{cases}
  x=y'\\
  y=x'-\left\lfloor\frac{a}{b}\right\rfloor y'
\end{cases}
$$

接下来不断向下迭代即可, 直到 $b=0$, 此时显然有 $x=1,y=0$

{% icodeweb blog lang:cpp nt-1/exgcd.cpp %}

时间复杂度仍为 $O(\log n)$

### 例题

- 洛谷 [P1072 Hankson 的趣味题](https://www.luogu.com.cn/problem/P1072)
- 洛谷 [P2158 [SDOI2008]仪仗队](https://www.luogu.com.cn/problem/P2158)
- 洛谷 [P4549 【模板】裴蜀定理](https://www.luogu.com.cn/problem/P4549)
- 洛谷 [P5656 【模板】二元一次不定方程(exgcd)](https://www.luogu.com.cn/problem/P5656)
- 洛谷 [P3951 小凯的疑惑 / [蓝桥杯 2013 省]买不到的数目](https://www.luogu.com.cn/problem/P3951) -> {% post_link luogu-p3951 题解 %}

## 同余

若 $t\mid a-b$, 则称 $a$ 与 $b$ 模 $t$ 同余, 记作 $a\equiv b\pmod t$

若 $t\nmid a-b$, 则称 $a$ 与 $b$ 模 $t$ 不同余, 记作 $a{\equiv}\llap{/\,} b\pmod t$

我们称 $\mathbb{Z}_m:=\{\overline{0},\overline{1},...,\overline{m-1}\}$ 为模 $m$ 剩余类

显然, 同余关系是一种等价关系, 剩余类即为其截面

### 性质

设 $a,b,c,d\in\mathbb{Z}$, $m\in\mathbb{N}^*$, $p$ 为素数

1. $a\equiv a\pmod m$
1. $a\equiv b\pmod m\implies b\equiv a\pmod m$
1. $a\equiv b\pmod m,b\equiv c\pmod m\implies a\equiv c\pmod m$
1. $a\equiv b\pmod m,c\equiv d\pmod m\implies a\pm c\equiv b\pm d\pmod m,ac\equiv bd\pmod m$
1. $ac\equiv bc\pmod m\implies a\equiv b\pmod{~\frac{m}{(c,m)}}$, 特别地, 若 $(c,m)=1$, 则 $a\equiv b\pmod{m}$
1. $a\equiv b\pmod m\implies\forall d\mid m,a\equiv b\pmod d$
1. $a\equiv b\pmod m\iff ad\equiv bd\pmod{md}$
1. $a\equiv b\pmod{m_i},i=1,2,...,n\implies a\equiv b\pmod{[m_1,m_2,\dots,m_n]}$
1. 令 $f(x)=\sum_{i=0}^na_ix^i,~a_1\in\mathbb{Z},i=0,1,...,n$, 则若 $a\equiv b\pmod m$, 则 $f(a)\equiv f(b)\pmod m$

另外在这里列出三条重要定理

1. **Wilson 定理**:

   $$
   (p-1)!\equiv-1\pmod p
   $$

1. **Fermat 小定理**: 若 $(a,p)=1$, 则

   $$
   a^{p-1}\equiv1\pmod p
   $$

1. **Euler 定理**: 若 $(a,m)=1$, 则

   $$
   a^{\varphi(m)}\equiv1\pmod m
   $$

   其中 $\varphi(n)$ 为 Euler 函数, 指的是 $[1,n]$ 中所有与 $n$ 互素的数的个数

   > 这里简单写写 Euler 函数的性质
   >
   > - 若 $p$ 为素数, $a$ 为自然数, 则 $\varphi(p^a)=p^a-p^{a-1}$
   >
   >   特别地, $\varphi(p)=p-1$
   >
   > - 若 $(m,n)=1$, 则 $\varphi(mn)=\varphi(m)\varphi(n)$

   不难发现: Euler 定理 即为 Fermat 定理 的推广

   > Wilson 定理, Fermat 小定理, Euler 定理 和后面要讲的 中国剩余定理 合称初等数论四大定理

接下来给出性质 4 和 5 的证明

#### <a href="#end-t-4.1" id="t-4.1">定理 - 4.1</a> (性质 4)

$a\equiv b\pmod m,c\equiv d\pmod m\implies a\pm c\equiv b\pm d\pmod m,ac\equiv bd\pmod m$

##### <a href="#t-4.1" id="p-t-4.1">证明</a>

由 $a\equiv b\pmod m,c\equiv d\pmod m$ 可得 $m\mid a-b$ 及 $m\mid c-d$

于是

$$
\begin{cases}
  m\mid (a-b)\pm(c-d)=(a\pm c)-(b\pm d)\\
  m\mid (a-b)c+(c-d)b=ac-bd
\end{cases}
$$

因此

$$
\begin{cases}
  a\pm c\equiv b\pm d\pmod m\\
  ac\equiv bd\pmod m
\end{cases}
$$

<a href="#p-t-4.1" id="end-t-4.1">$\Box$</a>

#### <a href="#end-t-4.2" id="t-4.2">定理 - 4.2</a> (性质 5)

$ac\equiv bc\pmod m\implies a\equiv b\pmod{~\frac{m}{(c,m)}}$, 特别地, 若 $(c,m)=1$, 则 $a\equiv b\pmod{m}$

##### <a href="#t-4.2" id="p-t-4.2">证明</a>

由 $ac\equiv bc\pmod m$ 可得 $m\mid(a-b)c$, 故有

$$
\frac{m}{(c,m)}\bigg|(a-b)\frac{c}{(c,m)}
$$

而 $(\frac{m}{(c,m)},\frac{c}{(c,m)})=1$, 故 $\frac{m}{(c,m)}\mid a-b$, 即

$$
a\equiv b\pmod{~\frac{m}{(c,m)}}
$$

<a href="#p-t-4.2" id="end-t-4.2">$\Box$</a>

性质 4 说明我们在同余意义下加法, 减法和乘法可以照常运算, 但是由于性质 5, 除法并不能随意去运算, 在逆元章节中我们将进行进一步讨论

---

这里附上 Wilson 定理和 Euler 定理的证明

#### <a href="#end-t-4.3" id="t-4.3">定理 - 4.3</a> (Wilson 定理)

$$
(p-1)!\equiv-1\pmod p
$$

##### <a href="#t-4.3" id="p-t-4.3">证明</a>

当 $p=2$ 时, 定理显然成立, 以下设 $p\geqslant 3$, 令 $\mathbb{Z}_p:=\{\overline{0},\overline{1},...,\overline{p-1}\}$ 即证 $\mathbb{Z}_p/\{0\}$ 中所有元素之积为 $\overline{-1}$

我们知道, $\mathbb{Z}_p/\{0\}$ 中每个元素都是可逆的, 即 $\forall a\in\mathbb{Z}_p/\{0\},~a^{-1}\in\mathbb{Z}_p/\{0\}$, 显然 $a^{-1}$ 的逆元为 $a$

而 $aa^{-1}=\overline{1}$, 故 $\mathbb{Z}_p/\{0\}$ 中彼此互逆的元素每对乘积为 $1$

之后考虑 $a=a^{-1}$ 的情况, 此时有 $a^2=\overline{1}$, 即 $a=\overline{1}$ 或 $a=\overline{-1}$

故 $(p-1)!\equiv-1\pmod p$

<a href="#p-t-4.3" id="end-t-4.3">$\Box$</a>

> 在讲到原根时会给出另一个证明

#### <a href="#end-t-4.4" id="t-4.4">定理 - 4.4</a> (Euler 定理)

若 $(a,m)=1$, 则

$$
a^{\varphi(m)}\equiv1\pmod m
$$

##### <a href="#t-4.4" id="p-t-4.4">证明</a>

设 $\mathbb{Z}_m^*:=\{a\in\mathbb{Z}_m|(a,m)=1\}=\{a_0,a_1,\dots,a_{\varphi(m)}\}$

由 $(a,m)=1$ 可知 $\overline{a}\in\mathbb{Z}_m^*$, 从而 $\mathbb{Z}_m^*=\{aa_0,aa_1,\dots,aa_{\varphi(m)}\}$

从而在群 $\mathbb{Z}_m^*$ 中

$$
\prod_{i=1}^{\varphi(m)}a_i=\prod_{i=1}^{\varphi(m)}aa_i=a^{\varphi(m)}\prod_{i=1}^{\varphi(m)}a_i
$$

两边约去 $\prod_{i=1}^{\varphi(m)}a_i$, 即得 $a^{\varphi(m)}\equiv1\pmod m$

<a href="#p-t-4.4" id="end-t-4.4">$\Box$</a>

### 例题

- 洛谷 [P4942 小凯的数字](https://www.luogu.com.cn/problem/P4942)
- HDU [2973 YAPTCHA](https://vjudge.net/problem/HDU-2973/origin)

## 逆元

设 $m$ 为正整数, $(a,m)=1$, 称 $a$ 的逆元为方程 $ax\equiv 1\pmod m$ 的解, 记作 $a^{-1}$

可以看出, 模剩余类下的逆元就像是有理数意义下一个数的倒数

### 性质

1. 若 $(a,m)=(b,m)=1$, 则 $a\equiv b\pmod m\iff a^{-1}\equiv b^{-1}\pmod m$

   > 这条性质等价于:
   >
   > - 对一个数求逆元, 其结果唯一
   > - 方程 $ax\equiv 1\pmod m,~(a,m)=1$ 的解唯一

### 求法

1. exgcd

   扩欧求的是 $ax+by=c$ 的解, 此时我们令 $b=m$, $c=(a,m)=1$, 则有

   $$
   ax+my=1
   $$

   即

   $$
   ax\equiv 1\pmod m
   $$

   这个 $x$ 就是 $a$ 的逆元

   时间复杂度:$O(\log m)$

1. Fermat 小定理 / Euler 定理

   由 $a^{\varphi(m)}\equiv 1\pmod m$ 可知 $a^{\varphi(m)-1}\equiv a^{-1}\pmod m$, 故所求逆元即为 $a^{\varphi(m)-1}$

   时间复杂度:$O(\log m)$

   一般来说更推荐用扩欧求逆元, 因为计算 $\varphi(m)$ 相对麻烦一些

1. 筛法

   用于求 $[1,n]$ 模 $p$ 逆元的方法

   首先, $1$ 的逆元是 $1$

   然后考虑 $p$ 对 $i$ 做带余除法 $p=ki+j,j\in[0,i)\cap\mathbb{N}$, 在模 $p$ 意义下即有

   $$
   \begin{aligned}
     ki+j&\equiv0\pmod p\\
     i^{-1}&\equiv-kj^{-1}\pmod p\\
     i^{-1}&\equiv-\left(\frac{p}{i}\right)(p\bmod i)^{-1}\pmod p
   \end{aligned}
   $$

   {% icodeweb blog lang:cpp nt-1/inverse_n1.cpp %}

1. 求任意 $n$ 个数模 $p$ 的逆元

   对于任意 $n$ 个数 $a_1,a_2,\dots,a_n$, 我们可以这样求出其逆元

   1. 令 $s_i=\prod_{j=1}^ia_j$
   1. 求出 $s_n$ 的逆元, 记作 $v_n$
   1. 注意到
      $$
      \begin{cases}
        v_{i-1}&=v_ia_i\\
        a_i^{-1}&=v_is_{i-1}
      \end{cases},i=1,2,...,n-1
      $$
      故此时 $a_1,a_2,\dots,a_n$ 的逆元便可求得

   {% icodeweb blog lang:cpp nt-1/inverse_n2.cpp %}

   时间复杂度:$O(n+\log p)$

### 例题

- 洛谷 [P1593 因子和](https://www.luogu.com.cn/problem/P1593)
- 洛谷 [P3811 【模板】乘法逆元](https://www.luogu.com.cn/problem/P3811)
- 洛谷 [P5431 【模板】乘法逆元 2](https://www.luogu.com.cn/problem/P5431)
- 洛谷 [P7887 「MCOI-06」Existence of Truth](https://www.luogu.com.cn/problem/P7887) -> {% post_link luogu-p7887 题解 %}
- LOJ [161 乘法逆元 2](https://loj.ac/problem/161)

## 中国剩余定理

用于求解一类线性同余方程组的方法

### <a href="#end-t-6.1" id="t-6.1">定理 - 6.1</a> (中国剩余定理)

设 $m_1,m_2,\dots,m_k$ 是两两互素的正整数, 则对任意整数 $b_1,b_2,\dots,b_k$, 方程组

$$
\begin{cases}
  x\equiv b_i\pmod{m_i}\\
  i=1,2,...,k
\end{cases}\tag{6.1-1}
$$

必有解, 且其全部解模 $\prod_{i=1}^k m_i$ 同余

#### <a href="#t-6.1" id="p-t-6.1">证明</a>

令 $M=\prod_{i=1}^km_i$

证明是构造性的, 我们首先尝试求解方程组

$$
\begin{cases}
  x\equiv1\pmod{m_i}\\
  x\equiv0\pmod{m_j}~(j\ne i)
\end{cases}
$$

容易发现 $x\mid M_i:=\frac{M}{m_i}$, 令 $x=M_iy$, 则可得到方程

$$
M_iy\equiv1\pmod{m_i}
$$

显然 $y\equiv M_i^{-1}\pmod{m_i}$, 令 $N_i=y$, 则 $x=M_iN_i$

此时我们进行大胆猜想: 最后结果可能是

$$
x\equiv\sum_{i=1}^kb_iM_iN_i\pmod M
$$

容易验证其确实是方程组 $(6.1-1)$ 的解, 令其为 $A$

假设 $x\equiv B\pmod M$ 也是方程组 $(6.1-1)$ 的解, 则有

$$
A-B\equiv0\pmod{m_i},~i=1,2,...,k
$$

这说明方程组 $(6.1-1)$ 的全部解模 $M$ 同余

<a href="#p-t-6.1" id="end-t-6.1">$\Box$</a>

### 扩展中国剩余定理 (exCRT)

为什么 CRT 要求其模数必须两两互素?

因为我们在 <a href="#t-6.1">定理 - 6.1</a> 证明过程中即可发现, CRT 的关键便是构造这样的方程组

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
m_1k_1-m_2k_2=b_2-b_1\tag{*}
$$

此时我们便可以通过扩欧去解决 $(*)$ 式的可解性和一组可行解

更重要的是: 此时不需要 $(m_1,m_2)=1$

求出 $k_1,k_2$ 之后便可得到

$$
x\equiv m_1k_1+b_1\equiv m_2k_2+b_2\pmod{[m_1,m_2]}
$$

{% icodeweb blog lang:cpp excrt/EXCRT.hpp %}

### 例题

- 洛谷 [P3868 [TJOI2009]猜数字](https://www.luogu.com.cn/problem/P3868)
- 洛谷 [P4774 [NOI2018] 屠龙勇士](https://www.luogu.com.cn/problem/P4774)

---

## 参考

- 冯克勤, 初等数论及应用, 北京师范大学出版社, 2003.7
- <https://oi-wiki.org/math/prime/>
- <https://oi-wiki.org/math/sieve/>
- <https://oi-wiki.org/math/inverse>
