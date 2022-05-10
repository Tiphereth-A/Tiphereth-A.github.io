---
title: "题解 - [Luogu P3524] [POI2011]IMP-Party"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - POI
  - 图论
  - 团
  - 随机化
date: 2020-11-04 16:32:04
---

[题目链接](https://www.luogu.com.cn/problem/P3524)

<!-- more -->

## 原始题面

### 题目描述

plain Byteasar intends to throw up a party

Naturally, he would like it to be a success. Furthermore, Byteasar is quite certain that to make it so it suffices if all invited guests know each other. He is currently trying to come up with a list of his friends he would like to invite

Byteasar has $n$ friends, where $n$ is divisible by 3

plain Fortunately, most of Byteasar's friends know one another

Furthermore, Byteasar recalls that he once attended a party where there were $\frac{2}{3}n$ of his friends, and where everyone knew everyone else

Unfortunately, Byteasar does not quite remember anything else from that party

In particular, he has no idea which of his friends attended it

Byteasar does not feel obliged to throw a huge party, but he would like to invite at least \frac{n}{3} of his friends

He has no idea how to choose them, so he asks you for help

### 输入输出格式

#### 输入格式

In the first line of the standard input two integers, $n$ and $m$ ($3\le n\le 3\ 000$, $\frac{\frac{2}{3}n(\frac{2}{3}n-1)}{2}\leq m\leq \frac{n(n-1)}{2}$), are given,separated by a single space. These denote the number of Byteasar's friends and the number of pairs of his friends who know each other, respectively

Byteasar's friends are numbered from 1 to $n$

Each of the following $m$ lines holds two integers separated by a single space

The numbers in line no. $i+1$ (for $i=1,2,...,m$) are $a_i$ and $b_i$($1\le a_i<b_i\le n$), separated by a single space, which denote that the persons $a_i$ and $b_i$ know each other. Every pair of numbers appears at most once on the input

#### 输出格式

In the first and only line of the standard output your program should print $\frac{n}{3}$ numbers, separated by single spaces, in increasing order. These number should specify the numbers of Byteasar's friends whom he should invite to the party. As there are multiple solutions, pick one arbitrarily

### 输入输出样例

#### 输入样例 #1

```input
6 10
2 5
1 4
1 5
2 4
1 3
4 5
4 6
3 5
3 4
3 6
```

#### 输出样例 #1

```output
2 4
```

## 题意简述

给定一张 n 个点 m 条边的图$n\equiv 0(mod\ 3)$, 保证存在一个大小为$\frac{2}{3}n$的团, 要求输出一个大小为$\frac{n}{3}$的团

## 解题思路

讲一个效率和正确率都很高的非完美算法

我们发现如果团内每个点的度往往都大于不在团内每个点的度

所以我们自然想到把所有点按度降序排个序然后取前$n\over3$个输出

但是这样是有 [反例](https://www.luogu.com.cn/discuss/show/272368) 的

> 我们可以构造这样的图
>
> ```input
> 9 24
> 1 3
> 1 5
> 1 6
> 2 5
> 2 6
> 3 4
> 3 5
> 5 6
> 2 1
> 2 3
> 6 3
> 4 1
> 2 4
> 4 5
> 4 6
> 7 9
> 8 9
> 9 3
> 9 2
> 9 5
> 9 4
> 9 6
> 1 7
> 1 8
> ```
>
> 画出来是这样的:
>
> ![](1.png)
>
> 我们发现$1$和$9$的度是$7$, $7$和$8$的度是$2$, 其余点的度是 $6$
>
> 按这样的做法就会输出
>
> ```output
> 1 x 9
> ```
>
> 其中$x\in\{2,3,4,5,6\}$
>
> 而$1$和$9$没有边, 所以这是错误答案

我们观察这个反例可以发现如果我们把取点策略换成: 在前$2n\over 3$个点里随机取$n\over3$的点, 就有很大概率正确

所以我们搞个 Las Vegas 随机就好了(本篇题解只是单纯的单次`shuffle`, 并没有加 Las Vegas 随机)

不考虑输入部分的话, 时间复杂度主要在排序上, 也就是$O(n\log n)$, 这是比正解快的 (输入部分的时间复杂度是 $O(n^2)$)

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa title:Luogu_3524 lang:cpp Luogu/3524/0.cpp %}

</details>
