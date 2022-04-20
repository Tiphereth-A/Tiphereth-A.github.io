---
title: 笔记 - 扩展中国剩余定理(exCRT)
categories:
  - 程序设计
  - 笔记
tags:
  - 程序设计
  - 笔记
  - 模板
  - 数学
  - 数论
  - 扩展中国剩余定理(exCRT)
  - exgcd
date: 2020-10-06 21:45:51
---

我们都知道, CRT用于求解的方程组要求其模数必须两两互素, 而exCRT则没有这条限制

> CRT的介绍参见 [链接](/article/nt-1/#%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86)

<!-- more -->
## 介绍

为什么CRT要求其模数必须两两互素?

因为我们在 [证明](article/nt-1/#t-6.1) 过程中即可发现, CRT的关键便是构造这样的方程组
$$\begin{cases}
  x\equiv1\pmod{m_i}\\
  x\equiv0\pmod{m_j}~(j\ne i)
\end{cases}$$
此时的$x=M_iN_i$, $M_i=\prod_{j=1,j\ne i}^km_j$, 而$N_i$是$M_i$关于$m_i$的**逆元**

我们知道, 如果一个整数$a$在模$m$意义下有逆元, 其前提之一便是$(a,m)=1$

> 逆元的介绍参见 [链接](/article/nt-1/#%E9%80%86%E5%85%83)

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
$$m_1k_1-m_2k_2=b_2-b_1\tag{1}$$
此时我们便可以通过扩欧去解决$(1)$式的可解性和一组可行解

更重要的是: 此时不需要$(m_1,m_2)=1$

求出$k_1,k_2$之后便可得到
$$x\equiv m_1k_1+b_1\equiv m_2k_2+b_2\pmod{[m_1,m_2]}$$

> 由同余的性质得出, 介绍参见 [链接](/article/nt-1/#%E6%80%A7%E8%B4%A8-3)

## 代码

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
