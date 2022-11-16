---
title: "题解 - [Luogu P1829] [国家集训队]Crash的数字表格 / JZPTAB"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 国家集训队
  - 数学
  - 数论
  - Iverson括号
  - Möbius反演
date: 2021-06-04 20:59:51
---

[题目链接](https://www.luogu.com.cn/problem/P1829)

<!-- more -->

## 原始题面

### 题目描述

今天的数学课上, Crash 小朋友学习了最小公倍数 (Least Common Multiple). 对于两个正整数 $a$ 和 $b$, $\text{lcm}(a,b)$ 表示能同时整除 $a$ 和 $b$ 的最小正整数. 例如, $\text{lcm}(6, 8) = 24$

回到家后, Crash 还在想着课上学的东西, 为了研究最小公倍数, 他画了一张 $ n \times m$ 的表格. 每个格子里写了一个数字, 其中第 $i$ 行第 $j$ 列的那个格子里写着数为 $\text{lcm}(i, j)$

看着这个表格, Crash 想到了很多可以思考的问题. 不过他最想解决的问题却是一个十分简单的问题: 这个表格中所有数的和是多少. 当 $n$ 和 $m$ 很大时, Crash 就束手无策了, 因此他找到了聪明的你用程序帮他解决这个问题. 由于最终结果可能会很大, Crash 只想知道表格里所有数的和 $\bmod 20101009$ 的值

### 输入输出格式

#### 输入格式

输入包含一行两个整数, 分别表示 $n$ 和 $m$

#### 输出格式

输出一个正整数, 表示表格中所有数的和 $\bmod 20101009$ 的值

### 输入输出样例

#### 输入样例 #1

```input1
4 5
```

#### 输出样例 #1

```output1
122
```

### 说明

#### 样例输入输出 1 解释

该表格为:

| $1$ | $2$ | $3$  | $4$  | $5$  |
| :-: | :-: | :--: | :--: | :--: |
| $2$ | $2$ | $6$  | $4$  | $10$ |
| $3$ | $6$ | $3$  | $12$ | $15$ |
| $4$ | $4$ | $12$ | $4$  | $20$ |

#### 数据规模与约定

- 对于 $30\%$ 的数据, 保证 $n, m \le 10^3$
- 对于 $70\%$ 的数据, 保证 $n, m \le 10^5$
- 对于 $100\%$ 的数据, 保证 $1\le n,m \le 10^7$

## 解题思路

推式子, 不妨设 $n\leqslant m$

$$
\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^m\frac{ij}{(i,j)}&=\sum_{d=1}^nd\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^{\lfloor\frac{m}{d}\rfloor}[(i,j)=1]ij\\
  &=\sum_{d=1}^nd\sum_{e=1}^{\lfloor\frac{n}{d}\rfloor}\mu(e)e^2{\lfloor\frac{n}{de}\rfloor(\lfloor\frac{n}{de}\rfloor+1)\over 2}{\lfloor\frac{m}{de}\rfloor(\lfloor\frac{m}{de}\rfloor+1)\over 2}\\
\end{aligned}
$$

懒得继续推了, 现在已经可以两次数论分块解决了, 要是接着推就是令 $D=de$ 然后一次数论分块

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P1829 Luogu/P1829/0.cpp %}

</details>
