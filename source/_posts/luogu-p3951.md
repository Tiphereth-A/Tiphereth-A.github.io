---
title: '题解 - [Luogu P3951] 小凯的疑惑 / [蓝桥杯2013省]买不到的数目'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - NOIp
  - NOIp提高组
  - 蓝桥杯
  - 数学
  - 数论
  - Bézout定理
  - 构造
date: 2020-10-04 12:27:01
---
[题目链接](https://www.luogu.com.cn/problem/P3951)

<!-- more -->

## 原始题面

### 题目描述

小凯手中有两种面值的金币, 两种面值均为正整数且彼此互素. 每种金币小凯都有 无数个. 在不找零的情况下, 仅凭这两种金币, 有些物品他是无法准确支付的. 现在小 凯想知道在无法准确支付的物品中, 最贵的价值是多少金币？注意：输入数据保证存在 小凯无法准确支付的商品

### 输入格式

两个正整数 $a$ 和 $b$, 它们之间用一个空格隔开, 表示小凯中金币的面值

### 输出格式

一个正整数 $N$, 表示不找零的情况下, 小凯用手中的金币不能准确支付的最贵的物品的价值

### 输入样例 #1

```input1
3 7
```

### 输出样例 #1

```output1
11
```

### 说明

【输入输出样例 1 说明】

小凯手中有面值为$3$和$7$的金币无数个, 在不找零的前提下无法准确支付价值为$1, 2,4,5,8,11$ 的物品, 其中最贵的物品价值为 $11$, 比 $11$ 贵的物品都能买到, 比如：

$12 = 3 \times 4 + 7 \times 0$

$13 = 3 \times 2 + 7 \times 1$

$14 = 3 \times 0 + 7 \times 2$

$15 = 3 \times 5 + 7 \times 0$

【数据范围与约定】

对于 $30\%$的数据： $1 \le a,b \le 50$

对于 $60\%$的数据： $1 \le a,b \le 10^4$

对于 $100\%$的数据：$1 \le a,b \le 10^9$

## 题意简述

对于给定的正整数$a,b,(a,b)=1$, 找到最大的正整数$n$满足
$$\nexists x,y\in\N,~s.t.~ax+by=n\tag{1}$$

## 解题思路

由Bézout定理, 我们知道, 如果$x,y$是在整数范围内的, 那么这个$n$是不存在的

但这题将$x,y$限制在了正整数范围内, Bézout定理就不能用了

我们这样考虑:

如果$n$满足$(1)$, 那么要想让$n$最大, 我们首先需要让$x=-1$或者$y=-1$

假设$x=-1$, 此时设$y=y'$

我们有通式
$$\begin{cases}
    x=-1+bt\\
    y=y'-at
\end{cases}$$

因为$b>1$, $x$随$t$严格单调递增, $y$随$t$严格单调递减

所以要想让$n$满足$(1)$, 我们需要让$y$在$t=1$时为负数

即$y'-a<0\implies y'<a$

由于$y'$是整数, 所以$y'$最大只能取$a-1$

此时对应的$n$即为$a\times(-1)+b(a-1)=ab-a-b$

如果假设$y=-1$, 也可推得相似结论

因为我们在这过程中取的都是最大值, 所以$ab-a-b$即为满足$(1)$的最大的$n$

接下来证明: 对任意大于$ab-a-b$的整数$n$均不满足$(1)$

设$ax_0+by_0=n,~x_0\geqslant 0$, 则只需证$y_0\geqslant 0$

取$x_0=n\bmod b$, 则$x_0\in[0,b-1]$, 有

$$\begin{aligned}
  by_0&=n-ax_0\\
  &\geqslant n-a(b-1)\\
  &>ab-a-b-a(b-1)\\
  &=-b
\end{aligned}$$

即$b(y_0+1)>0$, 从而有$y_0\geqslant 0$

代码略