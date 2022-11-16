---
title: "题解 - [Luogu P6613] 一阶微分方程"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - ODE
  - 多项式
  - 一阶线性ODE
  - 常数变易法
  - 一阶非线性ODE
  - Bernoulli微分方程
date: 2022-08-25 11:25:11
---

[题目链接](https://www.luogu.com.cn/problem/P6613)

<!-- more -->

## 原始题面

### 题目背景

题目中 $F'(x)$ 右侧的式子可以换成其它的, 这里为了方便测试, 是固定的

### 题目描述

已知多项式 $F(x),A(x),B(x)$, 满足:

$$\frac{\text dF(x)}{\text dx} \equiv A(x)\text e^{F(x)-1}+B(x) \pmod{x^n}$$
且 $F(0)=1$

给定 $A(x),B(x)$, 请求出 $F(x)$ 的前 $n$ 次项系数

答案对 $998244353$ 取模

### 输入格式

第一行一个正整数 $n$, 表示 $A(x),B(x)$ 的次数.  
第二行 $n+1$ 个整数, 由低到高表示 $A(x)$ 的系数.  
第三行 $n+1$ 个整数, 由低到高表示 $B(x)$ 的系数

### 输出格式

输出一行 $n+1$ 个整数, 由低到高表示 $F(x)$ 的系数

### 样例 #1

#### 样例输入 #1

```input1
9
2 9 8 7 3 6 5 4 1 12
23 9 8 7 4 6 1 3 2 5
```

#### 样例输出 #1

```output1
1 25 34 332748429 124783260 22560 624092696 904826719 284383572 50973515
```

### 提示

#### 数据规模与约定

对于 $30\%$ 的数据, $1\le n \le 5000$;  
对于 $100\%$ 的数据, $1\le n \le 10^5$

保证所有输入都在 $[0,998244353)$ 范围内

## 解题思路

简单的一阶非线性 ODE, 稍微仔细推一下

为简化公式, 在不引起歧义的情况下省略自变量, 所解方程为

$$F'=A\exp(F-1)+B\tag{1}$$

一个容易想到的尝试是令 $u=\exp(F-1)$, 则 $u'=\exp(F-1)F'$, 进而方程 $(1)$ 变为

$$u'=(Au+B)u\tag{2}$$

整理一下, 有

$$u'-Bu=Au^2\tag{2'}$$

此为 [Bernoulli 微分方程](https://en.wikipedia.org/wiki/Bernoulli_differential_equation) ($n=2$), 解法如下:

首先两边同除 $u^n=u^2$, 即

$$u^{-2}u'-Bu^{-1}=A$$

之后令 $v=u^{1-n}=u^{-1}$, 则 $v'=-u^nu'$, 即

$$v'+Bv=-A\tag{3}$$

这样只需解一个简单的一阶线性 ODE 即可

取函数 $\mu(x)$ 满足 $\mu B=\mu'$, 显然 $\mu$ 是存在的, 稍后给出具体形式

$(3)$ 式两边同乘 $\mu$ 后代入, 得

$$\mu v'+\mu' v=-\mu A\tag{4}$$

注意到 $(4)$ 式左边为 $(\mu v)'$, 进而

$$v=-\mu^{-1}\left(\int\mu A\mathrm{d}x+C\right)\tag{5}$$

其中 $C$ 为常数, 由 $F$ 初值确定

接下来我们考虑 $\mu$ 的形式, 显然 $(\ln\mu)'=\mu'/\mu=B$, 即 $\mu=\exp\int B\mathrm{d}x +C'$, 其中 $C'$ 为常数, 不妨取为 $0$

最后我们将 $v=\exp^{-1}(F-1)$ 和 $\mu$ 代入 $(5)$ 式, 最终结果即为

$$F=1+B-\ln\left(C-\int \left(\exp\int B(s)\mathrm{d}s\right)A\mathrm{d}x\right)\tag{6}$$

将 $F(0)=1$ 代入, 有 $C=1$

## 时间复杂度

$O(n\log n)$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P6613 Luogu/P6613/0.cpp %}

</details>
