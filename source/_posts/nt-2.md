---
title: '笔记 - 整除分块, Dirichlet卷积, Dirichlet前缀和, 积性函数, Möbius反演, 杜教筛'
categories:
  - 程序设计
  - 数学
tags:
  - 数学
  - 程序设计
  - 笔记
  - 模板
  - 数论
  - 数论分块/整除分块
  - 数论函数
  - 积性函数
  - 完全积性函数
  - Dirichlet卷积
  - Dirichlet前缀和
  - Möbius反演
  - Euler函数
  - Möbius函数
  - 杜教筛
date: 2020-10-05 00:52:51
---
整除分块, Dirichlet卷积, Dirichlet前缀和, 积性函数, Möbius反演, 杜教筛

<!-- more -->

## 整除分块/数论分块

在讲之前, 我们先看两个定理

### <a href="#end-t-1.1" id="t-1.1">定理 - 1.1</a>

$$\forall a,b,c\in\Z,\left\lfloor{a\over bc}\right\rfloor=\left\lfloor{\left\lfloor{a\over b}\right\rfloor\over c}\right\rfloor$$

#### <a href="#t-1.1" id="p-t-1.1">证明</a>

注意到
$${a\over b}=\left\lfloor{a\over b}\right\rfloor+\left\{ {a\over b}\right\}$$

其中$\{ {a\over b}\}$是$a\over b$的小数部分

故
$$\begin{aligned}
  \left\lfloor{a\over bc}\right\rfloor&=\left\lfloor{a\over b}\cdot{1\over c}\right\rfloor\\
  &=\left\lfloor\left(\left\lfloor{a\over b}\right\rfloor+\left\{ {a\over b}\right\}\right){1\over c}\right\rfloor\\
  &=\left\lfloor{\left\lfloor{a\over b}\right\rfloor\over c}+\left\{ {a\over b}\right\}{1\over c}\right\rfloor\\
  &=\left\lfloor{\left\lfloor{a\over b}\right\rfloor\over c}\right\rfloor
\end{aligned}$$

<a href="#p-t-1.1" id="end-t-1.1">$\Box$</a>

### <a href="#end-t-1.2" id="t-1.2">定理 - 1.2</a>

对任意正整数$n$, $\lfloor{n\over i}\rfloor,~i=1,2,...,n$的取值不超过$\lfloor2\sqrt{n}\rfloor$种

即
$$\forall n\in\N^*,\left|\left\{\left\lfloor{n\over i}\right\rfloor\big|~i=1,2,...,n\right\}\right|\leqslant\lfloor2\sqrt{n}\rfloor$$

#### <a href="#t-1.2" id="p-t-1.2">证明</a>

当$i\leqslant\sqrt{n}$时, $\lfloor{n\over i}\rfloor$至多有$\sqrt{n}$种取值

当$i>\sqrt{n}$时, 有$\lfloor{n\over i}\rfloor\leqslant\sqrt{n}$, 此时$\lfloor{n\over i}\rfloor$也至多有$\sqrt{n}$种取值

所以$\lfloor{n\over i}\rfloor,~i=1,2,...,n$至多有$\lfloor2\sqrt{n}\rfloor$种取值

<a href="#p-t-1.2" id="end-t-1.2">$\Box$</a>

### 用途

整除分块主要是用于快速求$\sum_{i=1}^n\lfloor{n\over i}\rfloor$的算法

朴素求法的时间复杂度自然是$O(n)$

为了方便叙述, 我们举个例子:  
令$n=15$, $f(i)=\lfloor{n\over i}\rfloor$ 我们可列出下表
| $f(i)$ | $i$的范围 |
| ------ | --------- |
| 15     | $[1,1]$   |
| 7      | $[2,2]$   |
| 5      | $[3,3]$   |
| 3      | $[4,5]$   |
| 2      | $[6,7]$   |
| 1      | $[8,15]$  |

我们可以发现, $f$任一像对应的原象是一段区间, 所以我们可以考虑直接求出对应区间长度, 从而就能快速求值

该算法的流程如下:

1. 令区间左右端点分别为$l,r$, 答案为$S$
1. 初始时, $l\leftarrow1,S\leftarrow0$
1. 计算$r$
1. $S\leftarrow S+(r-l+1)\lfloor{n\over l}\rfloor$
1. $l\leftarrow r+1$, 若$l\leqslant n$则回到3

关键就在于如何求$r$

令$\lfloor{n\over l}\rfloor=k_l$, 不难发现
$$r=\max_{ik_l\leqslant n}\{i\}$$

显然
$$r=\left\lfloor{n\over k_l}\right\rfloor=\left\lfloor{n\over{\lfloor{n\over l}\rfloor} }\right\rfloor$$

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
int get_sum(int n) {
    int ans = 0;
    for(int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += n / l * (r - l + 1);
    }
    return ans;
}
```

</details>

### 时间复杂度

由 <a href="#t-1.2">定理 - 1.2</a> 可知是$O(\sqrt{n})$

### One more thing

- 如何求$\sum_{i=1}^{\min\{m,n\}}\lfloor{n\over i}\rfloor\lfloor{m\over j}\rfloor$

  只需令
  $$r=\min\left\{\left\lfloor{n\over{\lfloor{n\over l}\rfloor} }\right\rfloor,\left\lfloor{m\over{\lfloor{m\over l}\rfloor} }\right\rfloor\right\}$$
- 如何求$\sum_{i=1}^n\lfloor{n\over ai+b}\rfloor$

  令$\lfloor{n\over al+b}\rfloor=k_l$, 不难发现
  $$r=\max_{aik_l\leqslant n-bk_l}\{i\}$$

  显然
  $$r=\left\lfloor{n-bk_l\over ak_l}\right\rfloor$$

### 例题

- 洛谷 [P2261 [CQOI2007]余数求和](https://www.luogu.com.cn/problem/P2261)

## 数论函数

定义$A$为对其上元素定义了加法, 减法和乘法的非空集(或$A$是交换环), 则称函数$f:\N\to A$为数论函数

通俗来说就是满足如下要求的函数:

- 定义域为正整数
- 值域中任意两个元素的和, 差, 积均在值域中

### 举例

- $\pi(n):=[1,n]_{\text{Prime}}$
- $\varphi(n)$
- $\omega(n)$: $n$的本质不同质因子个数, $\omega(1)=1$
- $\epsilon(n):=[n=1]$

在后面的积性函数一章中也会提到许多例子

如果某个数论函数具有简单的表达式$f(n)$, 在不引起歧义的情况下我们也可以将其简写为$\{f(n)\}$, 如$\{1\}$, $\{n\}$

## Dirichlet卷积

对数论函数$f,g$, 定义其Dirichlet卷积为$f*g$, 满足:
$$(f*g)(n):=\displaystyle\sum_{d\mid n}f(d)g({n\over d})$$

如
$$(f*g)(10)=f(1)g(10)+f(2)g(5)+f(5)g(2)+f(10)g(1)$$

### 性质

令$f,g,h$是数论函数

1. 交换律: $f*g=g*f$
1. 结合律: $f*(g*h)=(f*g)*h$
1. 对加法的分配律: $f*(g+h)=f*g+f*h$
1. 存在单位元: $f*\epsilon=f$

下面对结合律进行证明 [另一篇证明](../draft/0001)

#### <a href="#end-t-3.1" id="t-3.1">定理 - 3.1</a> (结合律)

令$f,g,h$是数论函数, 则
$$f*(g*h)=(f*g)*h$$

##### <a href="#t-3.1" id="p-t-3.1">证明</a>

$$\begin{aligned}
  (f*(g*h))(n)&=\sum_{a\mid n}f(a)\sum_{b\mid{n\over a}}g(b)h({n\over ab})\\
  &=\sum_{abc=n}f(a)g(b)h(c)\\
  &=\sum_{a\mid n}\left(\sum_{b\mid a}f(b)g({a\over b})\right)h({n\over a})\\
  &=((f*g)*h)(n)
\end{aligned}$$

<a href="#p-t-3.1" id="end-t-3.1">$\Box$</a>

### 一些常用的等式

1. $\mu*\{1\}=\epsilon$ (<a href="#t-6.2">定理 - 6.2</a>)
1. $\varphi*\{1\}=\{n\}$
1. $\mu*\{n\}=\varphi$

证明略

### Dirichlet前缀和

用于解决如下问题:
给出$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 求$\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 其中
$$b_i=\sum_{j\mid i}a_j$$

#### 算法流程

设$x,y$的分解分别为$x=\prod_ip_i^{\alpha_i}, y=\prod_ip_i^{\beta_i}$

则$a_x$对$b_y$有贡献当且仅当$\forall i,\alpha_i\leqslant\beta_i$

预先筛出$[1,n]$中的素数即可更快地处理

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
int prime[N], cnt_prime;
int a[N], b[N];
void Dirichlet_sum(int n) {
    for (int i = 1; i <= n; ++i) b[i] = a[i];
    for (int i = 1; i <= cnt_prime; ++i)
        for (int j = 1; j * prime[i] <= n; ++j)
            b[j * prime[i]] += b[j];
}
```

</details>

#### 时间复杂度

分析方法和 Eratosthenes 筛法一致, 为$O(n\log\log n)$

### 例题

- 洛谷 [P5495 Dirichlet 前缀和](https://www.luogu.com.cn/problem/P5495)

## 积性函数

满足$\forall m, n\in\Bbb{N}^*,(m,n)=1\implies f(mn)=f(m)f(n)$的$f(n)$

### 性质

1. $f,g$为积性函数$\implies\ fg,\displaystyle{f\over g},f*g$为积性函数

   > 即积性函数关于乘法, 除法, 卷积封闭

下面给出性质1的证明

#### <a href="#end-t-4.1" id="t-4.1">定理 - 4.1</a> (性质1)

$f,g$为积性函数$\implies\ fg,\displaystyle{f\over g},f*g$为积性函数

##### <a href="#t-4.1" id="p-t-4.1">证明</a>

此处只给出$f*g$是积性函数的证明

令$h=f*g$, $(m,n)=1$, 则

$$\begin{aligned}
   h(mn)&=\sum_{d\mid mn}f(d)g({mn\over d})\\
   &=\sum_{d_1\mid m}\sum_{d_2\mid n}f(d_1d_2)g({m\over d_1}{n\over d_2})\\
   &=\sum_{d_1\mid m}\sum_{d_2\mid n}f(d_1)f(d_2)g({m\over d_1})g({n\over d_2})\\
   &=\left(\sum_{d_1\mid m}f(d_1)g({m\over d_1})\right)\left(\sum_{d_2\mid n}f(d_2)g({n\over d_2})\right)\\
   &=h(m)h(n)
\end{aligned}$$

<a href="#p-t-4.1" id="end-t-4.1">$\Box$</a>

### 例子

1. $\epsilon(n):=[n=1]$
1. $\operatorname{id}_k(n):=n^k$
   - $e(n):=\operatorname{id}_0(n)=\{1\}$
   - 恒等映射: $\operatorname{id}(n):=\operatorname{id}_1(n)$
1. $\sigma_k(n):=\displaystyle\sum_{d\mid n}d^k=\operatorname{id}_k*\{1\}$
   - 因子个数: $\tau(n):=\sigma_0(n)$
   - 因子和: $\sigma(n):=\sigma_1(n)$
1. Euler函数: $\varphi(n):=\displaystyle\sum_{i=1}^n[(i,n)=1]$
1. Möbius函数: $\mu(n):=[\forall p\in\text{Prime}^+,p^2\nmid n]*(-1)^{\omega(n)}$

Euler函数和Möbius函数积性的证明在后面给出, 下面给出$\tau$和$\sigma$积性的证明

#### <a href="#end-t-4.2" id="t-4.2">定理 - 4.2</a>

$\tau(n)$和$\sigma(n)$是积性函数

##### <a href="#t-4.2" id="p-t-4.2">证明</a>

令$m,n$为两互素正整数, 则
$$\tau(mn)=\sum_{d_1\mid m}\sum_{d_2\mid n}1=\left(\sum_{d_1\mid m}1\right)\left(\sum_{d_2\mid n}1\right)=\tau(m)\tau(n)$$
$$\sigma(mn)=\sum_{d_1\mid m}\sum_{d_2\mid n}d_1d_2=\left(\sum_{d_1\mid m}d_1\right)\left(\sum_{d_2\mid n}d_2\right)=\sigma(m)\sigma(n)$$

<a href="#p-t-4.2" id="end-t-4.2">$\Box$</a>

#### <a href="#end-ifr-4.3" id="ifr-4.3">推论 - 4.3</a>

设$n$的标准分解式为$n=\prod_{i=1}^rp_i^{\alpha_i}$, 则
$$\tau(n)=\prod_{i=1}^r(\alpha_i+1)$$
$$\sigma(n)=\prod_{i=1}^r{p_i^{\alpha_i+1}-1\over p_i-1}$$

<a href="#ifr-4.3" id="end-ifr-4.3">$\Box$</a>

### 完全积性函数

满足$\forall m, n\in\Bbb{N}^*,f(mn)=f(m)f(n)$的$f(n)$

## Euler函数

记作$\varphi(n)$, 指的是$[1,n]$中所有与$n$互素的数

### 性质

1. $\varphi(n)$是积性函数
1. (1的推论) 若$n$为奇数, 则$\varphi(2n)=\varphi(n)$
1. 若$p$为素数, $a$为自然数, 则$\varphi(p^a)=p^a-p^{a-1}$

   特别地, $\varphi(p)=p-1$
1. (1,3的推论) 设$n=\prod_{i=1}^{\omega(n)}p_i^{\alpha_i}$, 则
   $$\varphi(n)=\prod_{i=1}^{\omega(n)}p_i^{\alpha_i}\left(1-{1\over p_i}\right)=n\prod_{i=1}^{\omega(n)}{p_i-1\over p_i}$$
1. 当$n>2$时, $\varphi(n)$为偶数

下面给出性质1的证明

#### <a href="#end-t-5.1" id="t-5.1">定理 - 5.1</a> (性质1)

$\varphi(n)$是积性函数

##### <a href="#t-5.1" id="p-t-5.1">证明</a>

设$n,m$是互素的正整数, 我们将$\{0,1,...,mn-1\}$如下列出
$$\begin{matrix}
  0&1&...&m-1\\
  m&m+1&...&2m-1\\
  \vdots&\vdots&\ddots&\vdots\\
  (n-1)m&(n-1)m+1&...&mn-1
\end{matrix}$$

考察第$j$列的数$im+j,~i=0,1,...,n-1$, 其均属于模$m$的同余类$\overline{j},~j=0,1,...,m-1$, 故共有$\varphi(m)$列中的数与$m$互素

考察第$j$行的数$in+j,~i=0,1,...,m-1$, 其均属于模$n$的同余类$\overline{j},~j=0,1,...,n-1$, 故共有$\varphi(n)$行中的数与$m$互素

不难发现, 只有同时在这$\varphi(m)$列和$\varphi(n)$行中的数才和$mn$互素

故$\varphi(mn)=\varphi(m)\varphi(n)$

<a href="#p-t-5.1" id="end-t-5.1">$\Box$</a>

### 求法

1. 单个数

   按$\varphi(n)=n\prod_{i=1}^{\omega(n)}{p_i-1\over p_i}$计算即可

   <details>
   <summary><font color='orange'>Show code</font></summary>

    ```cpp
    int euler_phi(int n) {
        int ans = n;
        for (int i = 2; i <= sqrt(n); ++i)
            if (n % i == 0) {
                ans = ans / i * (i - 1);
                while (n % i == 0) n /= i;
            }
        if (n > 1) ans = ans / n * (n - 1);
        return ans;
    }
    ```

   </details>

1. 筛法 (以Euler筛为例)

   依据积性和$\varphi(p^a)=p^a-p^{a-1}$计算

   <details>
   <summary><font color='orange'>Show code</font></summary>

    ```cpp
    void Euler_sieve(int n) {
        phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                prime[++cnt] = i;
                phi[i] = i - 1;
            }
            for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
                vis[i * prime[j]] = 1;
                phi[i * prime[j]] = phi[i] * prime[j];
                if (i % prime[j] == 0) break;
                phi[i * prime[j]] -= phi[i];
            }
        }
    }
    ```

   </details>

### 例题

- 洛谷 [P2568 GCD](https://www.luogu.com.cn/problem/P2568)
- 洛谷 [P2398 GCD SUM](https://www.luogu.com.cn/problem/P2398)

## Möbius函数

记作$\mu(n)$, 设$n=\prod_{i=1}^{\omega(n)}p_i^{\alpha_i}$, 则
$$\mu(n)=\begin{cases}
  0,&\exist i\in[1,\omega(n)],~s.t.~\alpha_i>1\\
  (-1)^{\omega(n)},&otherwise
\end{cases}$$

或者说, $\mu(n)$满足如下条件:

1. 若$n$中有平方因子, 则$\mu(n)=0$

   平方因子即满足$\exist a\in\Z^*, a^2\mid n$的因子

   显然, $n$中有平方因子等价于$n$中有平方素因子
1. 若$n$中无平方因子, 则$\mu(n)=(-1)^{\omega(n)}$, $\omega(n)$即为$n$的本质不同素因子个数

### 性质

1. $\mu$是积性函数
1. $$\sum_{d\mid n}\mu(d)=\epsilon(n)$$
   即
   $$\mu*\{1\}=\epsilon$$
1. (2的推论) $\displaystyle[(x,y)=1]=\sum_{d\mid (x,y)}\mu(d)$

下面给出性质1和性质2的证明

#### <a href="#end-t-6.1" id="t-6.1">定理 - 6.1</a> (性质1)

$\forall m,n\in\N^*,~(m,n)=1\implies\mu(mn)=\mu(m)\mu(n)$

##### <a href="#t-6.1" id="p-t-6.1">证明</a>

设$n,m$是互素的正整数, 若$m$或$n$有平方因子, 则$\mu(mn)=0=\mu(m)\mu(n)$

否则, 设
$$m=\prod_{i=1}^rp_i,n=\prod_{i=1}^sq_i$$
其中$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{r},\def\enum#1{q_{ #1}}\enum{1},\enum{2},...,\enum{s}$是两两不同的素数

从而$mn=(\prod_{i=1}^rp_i)(\prod_{i=1}^sq_i)$是$r+s$个不同素数的乘积, 有
$$\mu(mn)=(-1)^{r+s}=(-1)^r(-1)^s=\mu(m)\mu(n)$$

<a href="#p-t-6.1" id="end-t-6.1">$\Box$</a>

#### <a href="#end-t-6.2-2" id="t-6.2">定理 - 6.2</a> (性质2)

$$\mu*\{1\}=\epsilon$$

令
$$f(n)=(\mu*\{1\})(n)=\sum_{d\mid n}\mu(d)$$
易得 $f(1)=\mu(1)=1$

接下来不妨令$n$为大于$1$的整数, 下面给出两种证法

##### <a href="#t-6.2" id="p-t-6.2-1">证明 - 1</a> (直接证)

对于大于$1$的整数$n$做标准分解$n=\prod_{i=1}^rp_i^{\alpha_i}$, 则$f(n)$是$\mu(d)$的和, 其中$d$是$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{r}$中一部分素数的乘积

令$D_{i}$表示$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{r}$中某$i$个数的乘积构成的集合, 则$\forall d\in D_i,~\mu(d)=(-1)^i$

而
$$|D_i|={r\choose i}={r!\over i!(r-i)!}$$

因此
$$f(n)=\sum_{i=1}^r{r\choose i}(-1)^i=(1-1)^r=0$$

<a href="#p-t-6.2-1" id="end-t-6.2-1">$\Box$</a>

##### <a href="#t-6.2" id="p-t-6.2-2">证明 - 2</a> (积性)

由$f=\mu*\{1\}$可知, $f$必为积性函数

另一方面, $\epsilon$也为积性函数

因此, 我们只需证
$$\forall p\in\text{Prime}^+,\forall\alpha\in\N^*,~f(p^{\alpha})=\epsilon(p^{\alpha})$$

对上述的$p$和$\alpha$, 一方面, $\epsilon(p^{\alpha})=0$

另一方面,
$$\begin{aligned}
  f(p^{\alpha})&=\sum_{i=0}^{\alpha}\mu(p^i)\\
  &=\mu(1)+\mu(p)\\
  &=0
\end{aligned}$$

因此命题得证

<a href="#p-t-6.2-2" id="end-t-6.2-2">$\Box$</a>

### 求法

1. 单个数

   很少出现, 直接按定义即可
1. 筛法 (以Euler筛为例)

   基于积性和定义

   <details>
   <summary><font color='orange'>Show code</font></summary>

    ```cpp
    void Euler_sieve(int n) {
        mu[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                prime[++cnt] = i;
                mu[i] = -1;
            }
            for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
                vis[i * prime[j]] = 1;
                mu[i * prime[j]] = 0;
                if (i % prime[j] == 0) break;
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    ```

   </details>

## Möbius反演

### <a href="#end-t-7.1" id="t-7.1">定理 - 7.1</a>

对于数论函数$f,g$, 有
$$f=g*\{1\}\iff g=f*\mu$$

或者写成
$$\forall n\in\N^*,~f(n)=\sum_{d\mid n}g(d)\iff g(n)=\sum_{d\mid n}f(d)\mu\left({n\over d}\right)$$

#### <a href="#t-7.1" id="p-t-7.1">证明</a>

如果用卷积证明的话十分简洁
$$f=g*\{1\}\iff f*\mu=g*\{1\}*\mu=g*\epsilon=g$$

但这里我们给出不使用卷积运算法则的证明方法, 因为这是交换求和次序的绝佳练习, 交换求和次序也是应用Möbius反演解题的重要操作

在这里复述一遍命题
$$\forall n\in\N^*,~f(n)=\sum_{d\mid n}g(d)\tag{1}$$
$$\forall n\in\N^*,~g(n)=\sum_{d\mid n}f(d)\mu\left({n\over d}\right)\tag{2}$$

我们要证的即为$(1)\iff(2)$

先证$(1)\implies(2)$

若$(1)$成立, 则有
$$\sum_{d\mid n}f(d)\mu\left({n\over d}\right)=\sum_{d\mid n}\sum_{e\mid d}g(e)\mu\left({n\over d}\right)\tag{3}$$

之后我们交换求和号, 即改变元素的枚举顺序

当前$(3)$式是先枚举$n$的因子$d$, 再枚举$d$的因子$e$  
我们要改写成先枚举$n$的因子$e$, 再枚举$d$, 此时的$d$是$n$的因子, 同时也是$e$的倍数

从而在交换求和号之后变为
$$\sum_{e\mid n}\sum_{e\mid d\mid n}g(e)\mu\left({n\over d}\right)=\sum_{e\mid n}g(e)\sum_{e\mid d\mid n}\mu\left({n\over d}\right)\tag{4}$$

为什么要这么做呢?

这样做是因为$\displaystyle\sum_{e\mid d\mid n}\mu\left({n\over d}\right)$是可以很容易求出来的, 具体操作如下:

令$d'={d\over e}$, 则条件$e\mid d\mid n$等价于$d'\mid{n\over e}$

而
$${n\over d}={n\over e}\cdot{e\over d}={ {n\over e}\over d'}$$

因此固定$e$, 则有
$$\begin{aligned}
  \sum_{e\mid d\mid n}\mu\left({n\over d}\right)&=\sum_{d'\mid{n\over e}}\mu\left({ {n\over e}\over d'}\right)\\
  &=\sum_{d'\mid{n\over e}}\mu\left(d'\right)\\
  &=\epsilon(d')
\end{aligned}$$

此式表明$\displaystyle\sum_{e\mid d\mid n}\mu\left({n\over d}\right)$只有在$e$取$n$时才为$1$, 其余时为$0$

所以$(4)$式的最终结果即为$g(n)$, 此时命题$(2)$成立

我们把步骤合并起来

若$(1)$成立, 则有
$$\begin{aligned}
  \sum_{d\mid n}f(d)\mu\left({n\over d}\right)&=\sum_{d\mid n}\sum_{e\mid d}g(e)\mu\left({n\over d}\right)\\
  &=\sum_{e\mid n}\sum_{e\mid d\mid n}g(e)\mu\left({n\over d}\right)\\
  &=\sum_{e\mid n}g(e)\sum_{e\mid d\mid n}\mu\left({n\over d}\right)\\
  &\xlongequal{d'=d/e}\sum_{e\mid n}g(e)\sum_{d'\mid{n\over e}}\mu\left({ {n\over e}\over d'}\right)\\
  &=\sum_{e\mid n}g(e)\sum_{d'\mid{n\over e}}\mu(d')\\
  &=\sum_{e\mid n}g(e)\epsilon(d')\\
  &=\sum_{e\mid n}g(e)\epsilon\left({d\over e}\right)\\
  &=g(n)
\end{aligned}$$

类似可证$(1)\impliedby(2)$, 简要列出步骤
$$\begin{aligned}
  \sum_{d\mid n}g(d)&=\sum_{d\mid n}\sum_{e\mid d}\mu\left({d\over e}\right)f(e)\\
  &=\sum_{e\mid n}f(e)\sum_{e\mid d\mid n}\mu\left({d\over e}\right)\\
  &\xlongequal{d'=d/e}\sum_{e\mid n}f(e)\sum_{d'\mid{n\over e}}\mu(d')\\
  &=f(n)
\end{aligned}$$

<a href="#p-t-7.1" id="end-t-7.1">$\Box$</a>

### 例题

- 洛谷 [P6810 「MCOI-02」Convex Hull 凸包](https://www.luogu.com.cn/problem/P6810)
- 洛谷 [P3327 [SDOI2015]约数个数和](https://www.luogu.com.cn/problem/P3327)
  > 提示: $d(ij)=\sum_{x\mid i}\sum_{y\mid j}[(x,y)=1]$
- 洛谷 [P6222 「P6156 简单题」加强版](https://www.luogu.com.cn/problem/P6222)
  > 题解(P6156) [见此](/article/luogu-p6156)
- 洛谷 [P5221 Product](https://www.luogu.com.cn/problem/P5221)
  > 题解 [见此](/article/luogu-p5221)
- 洛谷 [P3704 [SDOI2017]数字表格](https://www.luogu.com.cn/problem/P3704)
  > 题解 [见此](/article/luogu-p3704)
- 洛谷 [P5518 [MtOI2019]幽灵乐团 / 莫比乌斯反演基础练习题](https://www.luogu.com.cn/problem/P5518)
- 洛谷 [P2522 [HAOI2011]Problem b](https://www.luogu.com.cn/problem/P2522)
- 洛谷 [P2257 YY的GCD](https://www.luogu.com.cn/problem/P2257)

## 杜教筛

杜教筛是一种在亚线性时间复杂度的求数论函数前缀和的算法

首先我们有如下定理

### <a href="#end-t-8.1" id="t-8.1">定理 - 8.1</a>

设$f,g$是数论函数, $S(n):=\sum_{i=1}^nf(i)$, 则
$$g(1)S(n)=\sum_{i=1}^n(f*g)(i)-\sum_{i=2}^ng(i)S\left(\left\lfloor{n\over i}\right\rfloor\right)$$

#### <a href="#t-8.1" id="p-t-8.1">证明</a>

$$\begin{aligned}
  \sum_{i=1}^n(f*g)(i)&=\sum_{i=1}^n\sum_{d\mid i}f(d)g\left({i\over d}\right)\\
  &=\sum_{d=1}^ng(d)\sum_{i=1}^{\lfloor{n\over d}\rfloor}f(i)\\
  &=\sum_{d=1}^ng(d)S\left(\left\lfloor{n\over d}\right\rfloor\right)\\
  &=g(1)S(n)+\sum_{i=2}^ng(i)S\left(\left\lfloor{n\over i}\right\rfloor\right)
\end{aligned}$$

<a href="#p-t-8.1" id="end-t-8.1">$\Box$</a>

如果我们选取的$g$, 使$\sum_{i=1}^n(f*g)(i)$和$g$的前缀和都能方便地算出来, 那么我们就可以方便地算出$S(n)$

### 伪代码

$
\begin{array}{l|l}
  1 & \textbf{function} ~ \texttt{sum\_of\_f}(n)\\
  2 & \qquad a \gets \texttt{sum\_of\_f*g}(n) \\
  3 & \qquad l \gets 2\\
  4 & \qquad \textbf{while} ~ l \leqslant n \\
  5 & \qquad \qquad r \gets \left\lfloor {n \over \left\lfloor {n \over l} \right\rfloor} \right\rfloor\\
  6 & \qquad \qquad a \gets a-(\texttt{sum\_of\_g}(r)-\texttt{sum\_of\_g}(l-1))\cdot\texttt{sum\_of\_f}(\left\lfloor {n \over l} \right\rfloor)\\
  7 & \qquad \qquad l \gets r+1\\
  8 & \qquad \textbf{end} ~ \textbf{while} \\
  9 & \textbf{return} ~ a \\
\end{array}
$

### 时间复杂度

设求出$S(n)$的时间函数为$T(n)$, 则

$$\begin{aligned}
  O(T(n))&=O\left(\sum_{i=1}^{\sqrt n}\left(O(\sqrt{i})+O\left(\sqrt{n\over i}\right)\right)\right)\\
  &=O\left(\int_1^{\sqrt{n}}\left(\sqrt{x}+\sqrt{n\over x}\right)\mathrm{d}x\right)\\
  &=O(n^{3\over 4})
\end{aligned}$$

如果我们能够预处理出$S(i),~i=1,2,...,m$, 设预处理的时间复杂度为$O(W(m))$, 则时间复杂度可变为
$$\begin{aligned}
  O(T(n))&=O\left(\sum_{i=1}^{\lfloor{n\over m}\rfloor}O\left(\sqrt{n\over i}\right)+W(m)\right)\\
  &=O\left(\int_1^{\lfloor{n\over m}\rfloor}\sqrt{n\over x}\mathrm{d}x+W(m)\right)\\
  &=O\left({n\over\sqrt m}+W(m)\right)
\end{aligned}$$

以线性筛作为预处理方式为例, 此时$O(W(m))=O(m)$  
由平均值不等式可知, 当$m=({n\over2})^{2\over 3}$时, 其时间复杂度最小, 为$O(n^{2\over 3})$

> $\displaystyle{n\over\sqrt m}+m={n\over2\sqrt m}+{n\over2\sqrt m}+m\geqslant\sqrt[3]{ {n\over2\sqrt m}\cdot{n\over2\sqrt m}\cdot m}=\sqrt[3]{n^2\over4}$
>
> 当${n\over2\sqrt m}=m$, 即$m=({n\over2})^{2\over 3}$时取得最小值

### 例题

- 洛谷 [P4213 【模板】杜教筛（Sum）](https://www.luogu.com.cn/problem/P4213)
- 第六届团体程序设计天梯赛 [L3-3 可怜的简单题](https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652366)
  > 题解 [见此](/article/gplt2021-l3-3)

---

## 参考

- 冯克勤, 初等数论及应用, 北京师范大学出版社, 2003.7
- <https://blog.csdn.net/gdhy9064/article/details/90112836>
- <https://oi-wiki.org/math/euler/>
- <https://oi-wiki.org/math/mobius/>
- <https://www.luogu.com.cn/blog/WDLGZH2017/solution-p5495>
- <https://gypsophila.blog.luogu.org/dls-tql>