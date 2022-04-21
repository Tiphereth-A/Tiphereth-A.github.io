---
title: '题解 - [AtCoder ARC110D] Binomial Coefficient is Fun'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - AtCoder
  - 数学
  - 组合数学
date: 2020-12-06 19:02:01
---
[题目链接](https://atcoder.jp/contests/arc110/tasks/arc110_d)

<!-- more -->

## 原始题面

Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 600 points

### Problem Statement

We have a sequence $A$ of $N$ non-negative integers

Compute the sum of $\prod_{i=1}^N\binom{B_i}{A_i}$
over all sequences $B$ of $N$ non-negative integers whose sum is at most $M$, and print it modulo ($10^9+7$)

Here, $\binom{B_i}{A_i}$
, the binomial coefficient, denotes the number of ways to choose $A_i$ objects from $B_i$ objects, and is 0 when $B_i<A_i$

### Constraints

- All values in input are integers
- $1≤N≤2000$
- $1≤M≤10^9$
- $0≤A_i≤2000$

### Input

Input is given from Standard Input in the following format:

$N\ M\\A_1\ A_2\ ...\ A_N$

### Output

Print the sum of $\prod_{i=1}^N\binom{B_i}{A_i}$, modulo ($10^9+7$)

### Sample Input 1

```input1
3 5
1 2 1
```

### Sample Output 1

```output1
8
```

There are four sequences B
such that $\prod_{i=1}^N\binom{B_i}{A_i}$ is at least 1:

- $B=\{1,2,1\}$, where $\prod_{i=1}^N\binom{B_i}{A_i}=\binom{1}{1}×\binom{2}{2}×\binom{1}{1}=1$
- $B=\{2,2,1\}$, where $\prod_{i=1}^N\binom{B_i}{A_i}=\binom{2}{1}×\binom{2}{2}×\binom{1}{1}=2$
- $B=\{1,3,1\}$, where $\prod_{i=1}^N\binom{B_i}{A_i}=\binom{1}{1}×\binom{3}{2}×\binom{1}{1}=3$
- $B=\{1,2,2\}$, where $\prod_{i=1}^N\binom{B_i}{A_i}=\binom{1}{1}×\binom{2}{2}×\binom{2}{1}=2$

The sum of these is $1+2+3+2=8$

### Sample Input 2

```input2
10 998244353
31 41 59 26 53 58 97 93 23 84
```

### Sample Output 2

```output2
642612171
```

## 题意简述

给定正整数$n,m$和$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 求
$$\sum_{\begin{smallmatrix}
  b_1,b_2,...,b_n>0\\\\
  \sum_{i=1}^nb_i\leqslant m
\end{smallmatrix}}\prod_{i=1}^n\binom{b_i}{a_i}$$

## 解题思路

不难发现该问题等价于如下问题

给出$m$个相同的小球和$n$个盒子, 盒子编号为$1,2,...,n$, 将小球放入盒子中, 要求第$i$个盒子至少放$a_i$个球, 接下来给每个盒子中的小球标号, 并分别在第$i$个盒子里取出$a_i$种, 问一共有多少种取法

先取出$\sum_{i=1}^na_i$个球放进盒子里, 此时问题可转化为

将$m-\sum_{i=1}^na_i$个相同的球放入$n+\sum_{i=1}^na_i$个有编号盒子(允许盒子为空)的方案数 (考虑插空法易得)

所以最终答案即为
$${m+n\choose m-\sum_{i=1}^na_i}={m+n\choose\sum_{i=1}^na_i+n}$$
