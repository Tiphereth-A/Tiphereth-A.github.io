---
title: "题解 - [Luogu P7486] 「Stoi2031」彩虹"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - 数论
  - Iverson括号
  - Möbius反演
  - 素数/质数
  - 筛法
  - Euler筛
  - 数论分块/整除分块
date: 2023-05-16 08:25:11
---

喜欢我 $\prod_i\prod_j [i,j]^{[i,j]}$ 吗 😁

[题目链接](https://www.luogu.com.cn/problem/P7486)

<!-- more -->

## 原始题面

### 题目背景

> 你要离开 我知道很简单 你说依赖 是我们的阻碍 就算放开 那能不能别没收我的爱 就当我最后才明白 ——《彩虹》

### 题目描述

虹是一个喜欢幻想的女孩子. 她认为两个正整数 $i,j$ 的 **依赖值** 为 $\operatorname{lcm}(i,j)^{\operatorname{lcm}(i,j)}$. 她定义所有满足 $l \le i \le r,l \le j \le r$ 的 $i,j$ 的 **依赖值** 之积为两个正整数 $l,r$ 的 **阻碍值**. 现在她给了你一个正整数 $n$, 并 $t$ 次询问你两个满足 $1 \le l \le r \le n$ 的正整数 $l,r$ 的 **阻碍值** $ans\bmod{32465177}$

### 输入格式

第一行两个正整数 $t,n$

接下来 $t$ 行, 每行两个正整数 $l_i,r_i$, 表示一次询问

### 输出格式

对于每组询问输出一个整数表示答案

### 样例 #1

#### 样例输入 #1

```input1
3 7
1 3
2 3
7 7
```

#### 样例输出 #1

```output1
21072733
12145631
823543
```

### 提示

#### 简述版题意

给定 $l,r$, 求 $\prod\limits_{i=l}^{r}\prod\limits_{j=l}^{r}\operatorname{lcm}(i,j)^{\operatorname{lcm}(i,j)} \bmod{32465177}$. 多次询问

#### 样例解释

对于第 $1$ 次询问, $ans=1^1 \times (2^2)^3 \times (3^3)^3 \times (6^6)^2$, $ans \bmod{32465177}=21072733$;

对于第 $2$ 次询问, $ans=2^2 \times 3^3 \times (6^6)^2$, $ans \bmod{32465177}=12145631$;

对于第 $3$ 次询问, $ans=7^7=823543$

#### 数据范围

对于 $30\%$ 的数据, $1 \le n \le 10^3,t=1$;

对于 $60\%$ 的数据, $1 \le n \le 10^5,t=1$;

对于 $100\%$ 的数据, $1 \le n \le 10^6,1 \le t \le 10,1 \le l_i \le r_i \le n$

## 解题思路

设

$$
S(n,m)=\prod_{i=1}^n\prod_{j=1}^m[i,j]^{[i,j]}
$$

不妨设 $n\leq m$, 所求即为

$$
\frac{S(r,r)S(l-1,l-1)}{S(l-1,r)^2}
$$

推式子

$$
\begin{aligned}
  S(n,m)&=\prod_{i=1}^n\prod_{j=1}^m[i,j]^{[i,j]}\\
  &=\prod_{i=1}^n\prod_{j=1}^m\left(\frac{ij}{(i,j)}\right)^{\frac{ij}{(i,j)}}\\
  &=\prod_{d=1}^n\prod_{i=1}^{\lfloor\frac{n}{d}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{d}\rfloor}(ijd)^{ijd[(i,j)=1]}\\
  &=\prod_{d=1}^n\prod_{e=1}^{\lfloor\frac{n}{d}\rfloor}\prod_{i=1}^{\lfloor\frac{n}{de}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{de}\rfloor}(ijde^2)^{ijde^2\mu(e)}\\
  &\xlongequal{D=de}\prod_{D=1}^n\prod_{e\mid D}\prod_{i=1}^{\lfloor\frac{n}{D}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{D}\rfloor}(ijDe)^{ijDe\mu(e)}
\end{aligned}
$$

即

$$
S(n,m)=\prod_{d=1}^n\prod_{e\mid d}\prod_{i=1}^{\lfloor\frac{n}{d}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{d}\rfloor}(ijde)^{ijde\mu(e)}
$$

接着推

$$
\begin{aligned}
  S(n,m)&=\prod_{d=1}^n\prod_{e\mid d}\prod_{i=1}^{\lfloor\frac{n}{d}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{d}\rfloor}(ijde)^{ijde\mu(e)}\\
  &=\prod_{d=1}^n\prod_{e\mid d}\left(\prod_{i=1}^{\lfloor\frac{n}{d}\rfloor}\prod_{j=1}^{\lfloor\frac{m}{d}\rfloor}(ij)^{ij}\right)^{de\mu(e)}\prod_{d=1}^n\prod_{e\mid d}(de)^{de\mu(e)\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{m}{d}\rfloor}ij}\\
  &\xlongequal[s(n)=\sum_{i=1}^n i=\frac{n(n+1)}{2}]{H(n)=\prod_{i=1}^n i^i}\prod_{d=1}^n\prod_{e\mid d}\left(H\left(\left\lfloor\frac{n}{d}\right\rfloor\right)^{s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}H\left(\left\lfloor\frac{m}{d}\right\rfloor\right)^{s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)}\right)^{de\mu(e)}\prod_{d=1}^n\prod_{e\mid d}(de)^{de\mu(e)s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}\\
  &\xlongequal[h(n)=(\{\operatorname{id}\mu\}*\{1\})(n)]{g(m,n)=H(n)^{s(m)}H(m)^{s(n)}}\prod_{d=1}^ng\left(\left\lfloor\frac{n}{d}\right\rfloor,\left\lfloor\frac{m}{d}\right\rfloor\right)^{dh(d)}\prod_{d=1}^nd^{dh(d)s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}\prod_{d=1}^n\prod_{e\mid d}e^{de\mu(e)s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}\\
  &\xlongequal{k(n)=\prod_{e\mid n}e^{e\mu(e)}}\prod_{d=1}^ng\left(\left\lfloor\frac{n}{d}\right\rfloor,\left\lfloor\frac{m}{d}\right\rfloor\right)^{dh(d)}\prod_{d=1}^nd^{dh(d)s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}\prod_{d=1}^nk(d)^{ds\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}\\
  &=\prod_{d=1}^n\left(g\left(\left\lfloor\frac{n}{d}\right\rfloor,\left\lfloor\frac{m}{d}\right\rfloor\right)^{h(d)}\left(d^{h(d)}k(d)\right)^{s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}\right)^{d}\\
  &=\prod_{d=1}^ng\left(\left\lfloor\frac{n}{d}\right\rfloor,\left\lfloor\frac{m}{d}\right\rfloor\right)^{dh(d)}\prod_{d=1}^n\left(d^{dh(d)}k(d)^d\right)^{s\left(\left\lfloor\frac{n}{d}\right\rfloor\right)s\left(\left\lfloor\frac{m}{d}\right\rfloor\right)}
\end{aligned}
$$

之后预处理一下后整除分块即可

## 时间复杂度

$O(n\log n+t\sqrt{n}\log n)$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P7486 Luogu/P7486/0.cpp %}

</details>
