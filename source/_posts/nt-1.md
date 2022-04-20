---
title: '笔记 - 整除, 素数, gcd & lcm, 同余, 逆元, CRT, exCRT'
categories:
  - 程序设计
  - 数学
tags:
  - 数学
  - 程序设计
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

对于整数$a,b$, 若$\exist k~s.t.~a=kb$, 则称$b$整除$a$, 记作$b\mid a$, 否则称$b$不整除$a$, 记作$b\nmid a$

### 性质

1. $a\mid b,b\mid c\implies a\mid c$
1. $a\mid b,b\mid a\implies a=\pm b$
1. $a\mid b,a\mid c\implies\forall x,y\in\Z,~a\mid bx+cy$

### 带余除法

#### <a href="#end-t-1.1" id="t-1.1">定理 - 1.1</a> (带余除法)

设$a,b\in\Z$, 且$b\geqslant1$, 则存在唯一的整数$q,r$使得
$$a=qb+r,r\in[0,b)\cap\N$$

##### <a href="#t-1.1" id="p-t-1.1">证明</a>

首先, 取$q=\lfloor{a\over b}\rfloor$, $r=a-qb$, 容易验证此时的$q,r$满足条件

下证唯一性, 假设又有一组整数$q',r'$使得$a=q'b-r',~r'\in[0,b)\cap\N$, 则

$$0=a-a=(q-q')b+(r-r')$$

因此$b\mid r-r'$

而$|r-r'|\in[0,b)\cap\N$, 故只能有$r-r'=0$, 即$r=r'$

此时$a-qb=a-q'b$, 有$q=q'$

<a href="#p-t-1.1" id="end-t-1.1">$\Box$</a>

接下来我们给出一个整数集的重要性质

#### <a href="#end-t-1.2" id="t-1.2">定理 - 1.2</a>

设$S$为非空整数集, 若$S$关于整数的加减法封闭, 即

- 若$a,b\in S$, 则$a\pm b\in S$

则存在唯一自然数$d$使得$S=d\Z:=\{da|a\in\Z\}$

> 条件中隐含了一点:
>
> - 若$a\in S$, 则$\forall c\in\Z,~ac\in S$

一般的, 若 $S$ 为主理想环, 则 $\exist_1 d\in\Z~s.t.~S=\lang d\rang$

##### <a href="#t-1.2" id="p-t-1.2">证明</a>

若$S=\{0\}$, 则只能取$d=0$

设$0\ne a\in S$, 则$0=a-a\in S,-a=(-1)\times a\in S$, 故此时$S$中必有正整数

由良序公理可知$S$中的所有正整数中必有最小值, 令$d$为$S$中的最小正整数, 下证$S=d\Z$

首先易得$d\Z\subseteq S$

之后我们在$S$中任取整数$a$做带余除法
$$a=qd+r,~q\in\Z,r\in[0,d)\cap\N$$
可知$r=a-qd\in S$, 而$d$为$S$中的最小正整数, 故必有$r=0$

这表明$a=qd\in d\Z$, 因此$S\subseteq d\Z$

最后, 注意到$d$为$S$中的最小正整数, 则满足$S=d\Z$的$d$一定是唯一的

<a href="#p-t-1.2" id="end-t-1.2">$\Box$</a>

### 例题

- 设$n$是大于1的整数, 证明: $\displaystyle\sum_{i=1}^n{1\over i}$不是整数
- 洛谷 [P2651 添加括号III](https://www.luogu.com.cn/problem/P2651)

## 素数/质数

即只能被1和其自身整除且大于1的数

不满足上述条件, 但大于1的数称为合数

1既不是素数也不是合数

### <a href="#end-t-2.1" id="t-2.1">定理 - 2.1</a>

素数有无限多个

#### <a href="#t-2.1" id="p-t-2.1">证明</a> (Euclid)

假设素数只有有限个, 记作$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$

考虑$N=\prod_{i=1}^np_i+1$, 显然$N>2$

由于$N\ne p_i,i=1,2,...,n$, 故必有$N$必有素因子$p$

但$p_i\nmid N,i=1,2,...,n$, 故$p$是$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{n}$以外的素数, 这与假设矛盾

<a href="#p-t-2.1" id="end-t-2.1">$\Box$</a>

### 唯一分解定理

#### <a href="#end-t-2.2" id="t-2.2">定理 - 2.2</a>

所有大于1的整数均可分解为有限个素数的乘积, 若不计各素数出现的顺序, 则这种分解唯一

证明略

<a href="#t-2.2" id="end-t-2.2">$\Box$</a>

### 素数分布

如果令$\pi(n)$表示$[1,n]$中的素数个数, 则我们有
$$\pi(n)\sim{n\over\ln n}~(n\to\infty)$$

或者写成
$$\lim_{n\to\infty}{\pi(n)\over{n\over\ln n}}=1$$

证明略

### 素数判定

这里给出一个简单的做法

首先, 我们不难证明: 若$n$是合数, 则其必有一个因子$d\in(1,\sqrt n]\cap\N$

所以对于要判定的整数`n`, 我们只需在`2..sqrt(n)`中枚举整数`i`验证即可

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
bool is_prime(int n) {
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); ++i)
       if(n % i == 0) return false;
    return true;
}
```

</details>

时间复杂度: $O(\sqrt n)$

有没有更好的方法呢?

我们有时间复杂度为 $O(k\log^3n)$ 的 Miller-Rabin 算法进行素性检验[^1], 其中 $k$ 为用于检验的数的个数[^2]

因其原理涉及到后面要讲的概念, 故此处略去相关讲解

> Miller-Rabin 算法和用于质因数分解的 Pollard-Rho 算法的模板 [点此](../p-test-mrpr/)

[^1]: 可以用 FFT 优化到 $O(k\log^2 n\log\log n\log\log\log n)$ , 参见 [此处](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Complexity)
[^2]: 若广义 Riemann 猜想(GRH)得到证实, 则可将检验的数换为 $2..2\lfloor\log^2 n\rfloor$ 从而使复杂度变为 $O(\log^5n)$, 参见 [此处](https://www.ams.org/mcom/1990-55-191/S0025-5718-1990-1023756-8/S0025-5718-1990-1023756-8.pdf)

### 素数筛法

如何求出$[1,n]$中的所有素数?

最朴素的做法就是对 `1..n` 中的每个数分别应用上述素数判定法, 时间复杂度: $O(n\sqrt n)$

接下来我们介绍两种更加高效的算法: Eratosthenes 筛法 和 Euler 筛法

#### Eratosthenes 筛法

又称埃氏筛

我们注意到这样的事实: 合数$x$的倍数也是合数

所以我们可以这样操作:

- `2..n`从小到大枚举, 如果当前枚举的数没被标记为合数, 我们就认为这个数是素数
  - 如果这个数是素数, 我们将其倍数标记为合数

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
void Eratosthenes_sieve(int n) {
    for (int i = 2; i <= n; ++i)
        if (!vis[i]) {
            prime[++cnt] = i;
            for (int j = i * 2; j <= n; j += i) vis[j] = 1;
        }
}
```

</details>

##### 时间复杂度

易知
$$T(n)=\sum_{p\in\{prime\}\cap[2,n]}\left\lfloor{n\over i}\right\rfloor$$

而
$$\begin{aligned}
  O(T(n))&=O\left(\sum_{p\in\{prime\}\cap[2,n]}\left\lfloor{n\over i}\right\rfloor\right)\\
  &=O\left(n\sum_{p\in\{prime\}\cap[2,n]}\left\lfloor{1\over p}\right\rfloor\right)\\
  &=O(n\log\log n)
\end{aligned}$$

故时间复杂度为$O(n\log\log n)$

#### Euler 筛法

我们发现在 Eratosthenes 筛法中, 有些数会被多次标记为合数, 我们能不能做到只标记一次呢?

当然可以!

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
void Euler_sieve(int n) {
    for(int i = 2; i <= n; ++i) {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1;j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = true;
            // 换言之, i 之前被 prime[j] 筛过了
            // 由于 prime 里面质数是从小到大的, 所以 i 乘上其他的质数的结果一定也
            // 是 prime[j] 的倍数 它们都被筛过了, 就不需要再筛了, 所以这里直接
            // break 掉就好了
            if(i % prime[j] == 0) break;
        }
    }
}
```

</details>

##### 时间复杂度

因为每个数只被标记一次, 所以时间复杂度显然为$O(n)$

### 例题

- 洛谷 [P3383 【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383)
- 洛谷 [P2926 [USACO08DEC]Patting Heads S](https://www.luogu.com.cn/problem/P2926)
- 洛谷 [P1835 素数密度](https://www.luogu.com.cn/problem/P1835)

## 最大公约数 & 最小公倍数

对于两个**不全为零**的**整数**$a,b$

最大公约数即为$a,b$中最大的正公因数, 记作$(a,b)$, 或者$\gcd(a,b)$

最小公倍数即为$a,b$中最小的正公倍数, 记作$[a,b]$, 或者$\operatorname{lcm}(a,b)$

写成式子就是

$$(a,b):=\max\{d\in\N^*|d\mid a,d\mid b\}$$
$$[a,b]:=\min\{d\in\N^*|a\mid d,b\mid d\}$$

这一组概念自然可以推广到多个整数之间

$$(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}):=\max\{d\in\N^*|d\mid a_i,~i=1,2,...,n\}$$
$$[\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}]:=\min\{d\in\N^*|a_i\mid d,~i=1,2,...,n\}$$

### 性质

1. $[a,b](a,b)=|ab|$

#### 最大公约数

1. $(a,b)=(b,a)=(|a|,b)=(|a|,|b|)$
1. 当$a\ne 0$时, $(a,a)=|a|$
1. 若$a_1\ne 0$, 则$(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})=((\enum{1},\enum{2}),\enum{3},...,\enum{n})$
1. $\forall l\in\Z,~(a,b)=(a,b+la)$
1. $\forall m\in\N^*,~m(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})=(\def\enum#1{ma_{ #1}}\enum{1},\enum{2},...,\enum{n})$
1. 若$(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})=d$, 则$(\def\enum#1{ {a_{ #1}\over d}}\enum{1},\enum{2},...,\enum{n})=1$
1. 对于整数$m$, 若$(a_i,m)=1,~i=1,2,...,n$, 则$(\prod_{i=1}^na_i,m)=1$
1. 设$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$是不全为零的整数, $(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})=d$, 则
   $$\left\{\sum_{i=1}^na_ix_i\bigg|x_i\in\Z,i=1,2,...,n\right\}=d\Z$$
1. 设$c\in\Z/\{0\},a,b\in\Z$, 若$c\mid ab,(c,b)=1$, 则$c\mid a$
   - 特别地, 若$p$为素数, $p\mid ab$, 则$p\mid a$或$p\mid b$

下面对性质8给出证明

##### <a href="#end-t-3.1" id="t-3.1">定理 - 3.1</a>(性质8, Bézout定理)

设$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$是不全为零的整数, $(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})=d$, 则
$$S:=\left\{\sum_{i=1}^na_ix_i\bigg|x_i\in\Z,i=1,2,...,n\right\}=d\Z$$

###### <a href="#t-3.1" id="p-t-3.1">证明</a>

由 <a href="#t-1.2">定理 - 1.2</a> 可知, 存在正整数$a$使得$S=a\Z$, 接下来只需证$a=d$

一方面, $d$是$S$中所有数的因子, 而$a\in S$, 故$d\mid a$

另一方面, 注意到$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}\in S$, 故$a$是$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$的公因子, 即有
$$a\mid(\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n})=d$$

因此$a=d$

<a href="#p-t-3.1" id="end-t-3.1">$\Box$</a>

#### 最小公倍数

1. $[\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}]=[[\enum{1},\enum{2}],\enum{3},...,\enum{n}]$
1. $\forall m\in\N^*,~[\def\enum#1{ma_{ #1}}\enum{1},\enum{2},...,\enum{n}]=m[\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}]$
1. 若$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$两两互素, 则$[\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}]=|\prod_{i=1}^na_i|$

### 求法

求最小公倍数只需求出最大公约数即可

而由于$\forall l\in\Z,~(a,b)=(a,b+la)$, 我们可推出:

- 若$b\ne 0$, 则$(a,b)=(b,a\bmod b)$

之后我们便可递归下去, 当$b=0$时, 答案即为$a$

这就是**辗转相除法**

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
int gcd(int a,int b) { return b == 0 ? a : gcd(b, a % b); }
```

</details>

#### 时间复杂度

我们知道, $b\to a \bmod b$这个过程中, $b$的值大致可认为是减半, 所以时间复杂度为$O(\log n)$

最坏情况即为对两相邻的Fibonacci数求最大公约数

> Fibonacci数的定义如下:
> $$F_i:=\begin{cases}
> 0,&i=0\\
> 1,&i=1\\
> F_{i-1}+F_{i-2},&i>1
> \end{cases}$$
> 容易求得
> $$F_n={\phi^n-(1-\phi)^n\over\sqrt 5},~\phi={1+\sqrt{5}\over2}$$

计算$(F_{n+1},F_{n})$需要$n$次迭代, 此时的时间复杂度也为$O(\log n)$

> 实际上求gcd是有$O(1)$算法的, 此次略去

### 扩展Euclid (exgcd)

用于对给定的$a,b,c$, 寻找$ax+by=c$的一组可行解

首先, 由 <a href="#t-3.1">Bézout 定理</a>, 若$(a,b)\nmid c$, 则该方程无解

接下来, 令$d={c\over(a,b)}$, 则求出$ax+by=(a,b)$的一组解$x=x',y=y'$后, 容易得知$x=dx',y=dy'$即为$ax+by=c$的一组解

另外, 若$ax+by=c$有一组解$x=x',y=y'$, 则
$$\begin{cases}
  x=x'-bt\\
  y=y'+at
\end{cases}(t\in\Z)$$
也为该方程的解, 所以方程$ax+by=c$若有解, 则必有无数组解

经过如下分析, 我们发现: 求出方程$ax+by=(a,b)$的一组解是关键, 下面给出求法

#### 求法

考虑这两个式子
$$\begin{aligned}
  ax+by&=(a,b)\\
  bx'+(a\bmod b)y'&=(b,a\bmod b)=(a,b)
\end{aligned}$$

注意到
$$a\bmod b=a-\left\lfloor{a\over b}\right\rfloor b$$

故
$$ax+by=bx'+(a-\left\lfloor{a\over b}\right\rfloor b)y'$$

可知
$$\begin{cases}
  x=y'\\
  y=x'-\left\lfloor{a\over b}\right\rfloor y'
\end{cases}$$

接下来不断向下迭代即可, 直到$b=0$, 此时显然有$x=1,y=0$

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}
```

</details>

时间复杂度仍为$O(\log n)$

### 例题

- 洛谷 [P1072 Hankson 的趣味题](https://www.luogu.com.cn/problem/P1072)
- 洛谷 [P2158 [SDOI2008]仪仗队](https://www.luogu.com.cn/problem/P2158)
- 洛谷 [P4549 【模板】裴蜀定理](https://www.luogu.com.cn/problem/P4549)
- 洛谷 [P5656 【模板】二元一次不定方程(exgcd)](https://www.luogu.com.cn/problem/P5656)
- 洛谷 [P3951 小凯的疑惑 / [蓝桥杯2013省]买不到的数目](https://www.luogu.com.cn/problem/P3951) -> [**题解**](../luogu-p3951/#more)

## 同余

若$t\mid a-b$, 则称$a$与$b$模$t$同余, 记作$a\equiv b\pmod t$

若$t\nmid a-b$, 则称$a$与$b$模$t$不同余, 记作$a{\equiv}\llap{/\,} b\pmod t$

我们称 $\Z_m:=\{\def\enum#1{\overline{ #1}}\enum{0},\enum{1},...,\enum{m-1}\}$ 为模 $m$ 剩余类

显然, 同余关系是一种等价关系, 剩余类即为其截面

### 性质

设$a,b,c,d\in\Z$, $m\in\N^*$, $p$为素数

1. $a\equiv a\pmod m$
1. $a\equiv b\pmod m\implies b\equiv a\pmod m$
1. $a\equiv b\pmod m,b\equiv c\pmod m\implies a\equiv c\pmod m$
1. $a\equiv b\pmod m,c\equiv d\pmod m\implies a\pm c\equiv b\pm d\pmod m,ac\equiv bd\pmod m$
1. $ac\equiv bc\pmod m\implies a\equiv b\pmod{~{m\over(c,m)}}$, 特别地, 若$(c,m)=1$, 则$a\equiv b\pmod{m}$
1. $a\equiv b\pmod m\implies\forall d\mid m,a\equiv b\pmod d$
1. $a\equiv b\pmod m\iff ad\equiv bd\pmod{md}$
1. $a\equiv b\pmod{m_i},i=1,2,...,n\implies a\equiv b\pmod{[\def\enum#1{m_{ #1}}\enum{1},\enum{2},...,\enum{n}]}$
1. 令$f(x)=\sum_{i=0}^na_ix^i,~a_1\in\Z,i=0,1,...,n$, 则若$a\equiv b\pmod m$, 则$f(a)\equiv f(b)\pmod m$

另外在这里列出三条重要定理

1. **Wilson定理**:
   $$(p-1)!\equiv-1\pmod p$$

1. **Fermat小定理**: 若$(a,p)=1$, 则
   $$a^{p-1}\equiv1\pmod p$$

1. **Euler定理**: 若$(a,m)=1$, 则
   $$a^{\varphi(m)}\equiv1\pmod m$$
   其中$\varphi(n)$为Euler函数, 指的是$[1,n]$中所有与$n$互素的数的个数

   > 这里简单写写Euler函数的性质
   >
   > - 若$p$为素数, $a$为自然数, 则$\varphi(p^a)=p^a-p^{a-1}$
   >
   >   特别地, $\varphi(p)=p-1$
   > - 若$(m,n)=1$, 则$\varphi(mn)=\varphi(m)\varphi(n)$

   不难发现: Euler定理 即为 Fermat定理 的推广
   > Wilson定理, Fermat小定理, Euler定理 和后面要讲的 中国剩余定理 合称初等数论四大定理

接下来给出性质4和5的证明

#### <a href="#end-t-4.1" id="t-4.1">定理 - 4.1</a> (性质4)

$a\equiv b\pmod m,c\equiv d\pmod m\implies a\pm c\equiv b\pm d\pmod m,ac\equiv bd\pmod m$

##### <a href="#t-4.1" id="p-t-4.1">证明</a>

由$a\equiv b\pmod m,c\equiv d\pmod m$可得$m\mid a-b$及$m\mid c-d$

于是
$$\begin{cases}
  m\mid (a-b)\pm(c-d)=(a\pm c)-(b\pm d)\\
  m\mid (a-b)c+(c-d)b=ac-bd
\end{cases}$$
因此
$$\begin{cases}
  a\pm c\equiv b\pm d\pmod m\\
  ac\equiv bd\pmod m
\end{cases}$$
<a href="#p-t-4.1" id="end-t-4.1">$\Box$</a>

#### <a href="#end-t-4.2" id="t-4.2">定理 - 4.2</a> (性质5)

$ac\equiv bc\pmod m\implies a\equiv b\pmod{~{m\over(c,m)}}$, 特别地, 若$(c,m)=1$, 则$a\equiv b\pmod{m}$

##### <a href="#t-4.2" id="p-t-4.2">证明</a>

由$ac\equiv bc\pmod m$可得$m\mid(a-b)c$, 故有
$${m\over(c,m)}\bigg|(a-b){c\over(c,m)}$$

而$({m\over(c,m)},{c\over(c,m)})=1$, 故${m\over(c,m)}\mid a-b$, 即
$$a\equiv b\pmod{~{m\over(c,m)}}$$

<a href="#p-t-4.2" id="end-t-4.2">$\Box$</a>

性质4说明我们在同余意义下加法, 减法和乘法可以照常运算, 但是由于性质5, 除法并不能随意去运算, 在逆元章节中我们将进行进一步讨论

---

这里附上Wilson定理和Euler定理的证明

#### <a href="#end-t-4.3" id="t-4.3">定理 - 4.3</a> (Wilson定理)

$$(p-1)!\equiv-1\pmod p$$

##### <a href="#t-4.3" id="p-t-4.3">证明</a>

当$p=2$时, 定理显然成立, 以下设$p\geqslant 3$, 令$\Z_p:=\{\def\enum#1{\overline{ #1}}\enum{0},\enum{1},...,\enum{p-1}\}$即证$\Z_p/\{0\}$中所有元素之积为$\overline{-1}$

我们知道, $\Z_p/\{0\}$中每个元素都是可逆的, 即$\forall a\in\Z_p/\{0\},~a^{-1}\in\Z_p/\{0\}$, 显然$a^{-1}$的逆元为$a$

而$aa^{-1}=\overline{1}$, 故$\Z_p/\{0\}$中彼此互逆的元素每对乘积为$1$

之后考虑$a=a^{-1}$的情况, 此时有$a^2=\overline{1}$, 即$a=\overline{1}$或$a=\overline{-1}$

故$(p-1)!\equiv-1\pmod p$

<a href="#p-t-4.3" id="end-t-4.3">$\Box$</a>

> 在讲到原根时会给出另一个证明

#### <a href="#end-t-4.4" id="t-4.4">定理 - 4.4</a> (Euler定理)

若$(a,m)=1$, 则
$$a^{\varphi(m)}\equiv1\pmod m$$

##### <a href="#t-4.4" id="p-t-4.4">证明</a>

设$\Z_m^*:=\{a\in\Z_m|(a,m)=1\}=\{\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{\varphi(m)}\}$

由$(a,m)=1$可知$\overline{a}\in\Z_m^*$, 从而$\Z_m^*=\{\def\enum#1{aa_{ #1}}\enum{1},\enum{2},...,\enum{\varphi(m)}\}$

从而在群$\Z_m^*$中
$$\prod_{i=1}^{\varphi(m)}a_i=\prod_{i=1}^{\varphi(m)}aa_i=a^{\varphi(m)}\prod_{i=1}^{\varphi(m)}a_i$$

两边约去$\prod_{i=1}^{\varphi(m)}a_i$, 即得$a^{\varphi(m)}\equiv1\pmod m$

<a href="#p-t-4.4" id="end-t-4.4">$\Box$</a>

### 例题

- 洛谷 [P4942 小凯的数字](https://www.luogu.com.cn/problem/P4942)
- HDU [2973 YAPTCHA](https://vjudge.net/problem/HDU-2973/origin)

## 逆元

设$m$为正整数, $(a,m)=1$, 称$a$的逆元为方程$ax\equiv 1\pmod m$的解, 记作$a^{-1}$

可以看出, 模剩余类下的逆元就像是有理数意义下一个数的倒数

### 性质

1. 若$(a,m)=(b,m)=1$, 则$a\equiv b\pmod m\iff a^{-1}\equiv b^{-1}\pmod m$

   > 这条性质等价于:
   >
   > - 对一个数求逆元, 其结果唯一
   > - 方程$ax\equiv 1\pmod m,~(a,m)=1$的解唯一

### 求法

1. exgcd

   扩欧求的是$ax+by=c$的解, 此时我们令$b=m$, $c=(a,m)=1$, 则有
   $$ax+my=1$$
   即
   $$ax\equiv 1\pmod m$$
   这个$x$就是$a$的逆元

   时间复杂度:$O(\log m)$
1. Fermat小定理 / Euler定理

   由$a^{\varphi(m)}\equiv 1\pmod m$可知$a^{\varphi(m)-1}\equiv a^{-1}\pmod m$, 故所求逆元即为$a^{\varphi(m)-1}$

   时间复杂度:$O(\log m)$

   一般来说更推荐用扩欧求逆元, 因为计算$\varphi(m)$相对麻烦一些
1. 筛法

   用于求$[1,n]$模$p$逆元的方法

   首先, $1$的逆元是$1$

   然后考虑$p$对$i$做带余除法$p=ki+j,j\in[0,i)\cap\N$, 在模$p$意义下即有
   $$\begin{aligned}
     ki+j&\equiv0\pmod p\\
     i^{-1}&\equiv-kj^{-1}\pmod p\\
     i^{-1}&\equiv-\left({p\over i}\right)(p\bmod i)^{-1}\pmod p
   \end{aligned}$$

   <details>
   <summary><font color='orange'>Show code</font></summary>

   ```cpp
   inv[1] = 1;
   for (int i = 2; i <= n; ++i) inv[i] = (int64_t)(p - p / i)  * inv[p % i] % p;
   ```

   </details>
1. 求任意$n$个数模$p$的逆元

   对于任意$n$个数$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 我们可以这样求出其逆元

   1. 令$s_i=\prod_{j=1}^ia_j$
   1. 求出$s_n$的逆元, 记作$v_n$
   1. 注意到
      $$\begin{cases}
        v_{i-1}&=v_ia_i\\
        a_i^{-1}&=v_is_{i-1}
      \end{cases},i=1,2,...,n-1$$
      故此时$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$的逆元便可求得

   <details>
   <summary><font color='orange'>Show code</font></summary>

   ```cpp
   s[0] = inv[1] = 1;
   for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
   for (int i = n, v = qpow(s[n], p - 2); i > 1; v = v * a[i--] % p) inv[i] = v * s[i - 1] % p;
   ```

   </details>

   时间复杂度:$O(n+\log p)$

### 例题

- 洛谷 [P1593 因子和](https://www.luogu.com.cn/problem/P1593)
- 洛谷 [P3811 【模板】乘法逆元](https://www.luogu.com.cn/problem/P3811)
- 洛谷 [P5431 【模板】乘法逆元2](https://www.luogu.com.cn/problem/P5431)
- 洛谷 [P7887 「MCOI-06」Existence of Truth](https://www.luogu.com.cn/problem/P7887) -> [**题解**](../luogu-p7887/#more)
- LOJ [161 乘法逆元 2](https://loj.ac/problem/161)

## 中国剩余定理

用于求解一类线性同余方程组的方法

### <a href="#end-t-6.1" id="t-6.1">定理 - 6.1</a> (中国剩余定理)

设$\def\enum#1{m_{ #1}}\enum{1},\enum{2},...,\enum{k}$是两两互素的正整数, 则对任意整数$\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{k}$, 方程组
$$\begin{cases}
  x\equiv b_i\pmod{m_i}\\
  i=1,2,...,k
\end{cases}\tag{6.1-1}$$
必有解, 且其全部解模$\prod_{i=1}^k m_i$同余

#### <a href="#t-6.1" id="p-t-6.1">证明</a>

令$M=\prod_{i=1}^km_i$

证明是构造性的, 我们首先尝试求解方程组
$$\begin{cases}
  x\equiv1\pmod{m_i}\\
  x\equiv0\pmod{m_j}~(j\ne i)
\end{cases}$$

容易发现$x\mid M_i:={M\over m_i}$, 令$x=M_iy$, 则可得到方程
$$M_iy\equiv1\pmod{m_i}$$

显然$y\equiv M_i^{-1}\pmod{m_i}$, 令$N_i=y$, 则$x=M_iN_i$

此时我们进行大胆猜想: 最后结果可能是
$$x\equiv\sum_{i=1}^kb_iM_iN_i\pmod M$$

容易验证其确实是方程组$(6.1-1)$的解, 令其为$A$

假设$x\equiv B\pmod M$也是方程组$(6.1-1)$的解, 则有
$$A-B\equiv0\pmod{m_i},~i=1,2,...,k$$
这说明方程组$(6.1-1)$的全部解模$M$同余

<a href="#p-t-6.1" id="end-t-6.1">$\Box$</a>

### 扩展中国剩余定理 (exCRT)

为什么CRT要求其模数必须两两互素?

因为我们在 <a href="#t-6.1">定理 - 6.1</a> 证明过程中即可发现, CRT的关键便是构造这样的方程组
$$\begin{cases}
  x\equiv1\pmod{m_i}\\
  x\equiv0\pmod{m_j}~(j\ne i)
\end{cases}$$
此时的$x=M_iN_i$, $M_i=\prod_{j=1,j\ne i}^km_j$, 而$N_i$是$M_i$关于$m_i$的**逆元**

我们知道, 如果一个整数$a$在模$m$意义下有逆元, 其前提之一便是$(a,m)=1$

在此处便是$(M_i,m_i)=1$

故由最大公约数的性质, 此处的$k$个模数$\def\enum#1{m_{ #1}}\enum{1},\enum{2},...,\enum{k}$必须两两互素

那么我们能不能摆脱这个限制条件呢?

当然可以!

这就要求我们在构建解的时候绕开CRT的证明, 另辟蹊径

我们观察下面的式子
$$\begin{cases}
    x\equiv b_1\pmod{m_1}\\
    x\equiv b_2\pmod{m_2}
\end{cases}$$

由同余定义, 我们有
$$\begin{cases}
    m_1\mid x-b_1\\
    m_2\mid x-b_2
\end{cases}$$

即存在整数$k_1,k_2$使得
$$x=m_1k_1+b_1=m_2k_2+b_2$$
整理一下, 便有
$$m_1k_1-m_2k_2=b_2-b_1\tag{*}$$
此时我们便可以通过扩欧去解决$(*)$式的可解性和一组可行解

更重要的是: 此时不需要$(m_1,m_2)=1$

求出$k_1,k_2$之后便可得到
$$x\equiv m_1k_1+b_1\equiv m_2k_2+b_2\pmod{[m_1,m_2]}$$

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
namespace EXCRT {
using T = int64_t;
T abs(T a) { return a < 0 ? -a : a; }
T mod_mul(T a, T b, T mod) {
    T res = 0;
    for (; b; b >>= 1, (a += a) %= mod)
        if (b & 1) (res += a) %= mod;
    return res;
}
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
T exgcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

bool solve_2equ(T b1, T b2, T m1, T m2, T& x, T& M) {
    ((b1 %= m1) += m1) %= m1;
    ((b2 %= m2) += m2) %= m2;
    T g = gcd(m1, m2), r = b2 - b1;
    M = m1 / g * m2;
    if (abs(r) % g) return false;
    T k1, k2;
    exgcd(m1, m2, k1, k2);
    if (r < 0) k1 = -k1;
    ((k1 %= M) += M) %= M;
    k1 = mod_mul(k1, abs(r) / g, M);
    x = ((mod_mul(k1, m1, M) + b1) % M + M) % M;
    return true;
}

bool excrt(T b[], T m[], const int len, T& res) {
    T pre_b = b[1], pre_m = m[1];
    T now_b, now_m;
    for (int i = 2; i <= len; ++i) {
        now_b = b[i];
        now_m = m[i];
        if (!solve_2equ(pre_b, now_b, pre_m, now_m, pre_b, pre_m))
            return false;
    }
    res = pre_b;
    return true;
}
}  // namespace EXCRT
using EXCRT::excrt;
```

</details>

### 例题

- 洛谷 [P3868 [TJOI2009]猜数字](https://www.luogu.com.cn/problem/P3868)
- 洛谷 [P4774 [NOI2018] 屠龙勇士](https://www.luogu.com.cn/problem/P4774)

---

## 参考

- 冯克勤, 初等数论及应用, 北京师范大学出版社, 2003.7
- <https://oi-wiki.org/math/prime/>
- <https://oi-wiki.org/math/sieve/>
- <https://oi-wiki.org/math/inverse>
