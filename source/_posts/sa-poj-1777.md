---
title: "题解 - [POJ 1777 等] Vivian's Problem"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - POJ
  - UVa
  - 数学
  - 数论
  - Mersenne素数
  - 状态压缩
  - 状压DP
date: 2020-07-27 22:58:08
---

题目链接

- [POJ 1777](https://vjudge.net/problem/POJ-1777/origin)
- [UVA 1323](https://vjudge.net/problem/UVA-1323/origin)

<!-- more -->

## 原始题面

### Description

The desire to explore the unknown has been a driving force in human history since the dawn of time. From the earliest documented accounts, ancient civilizations had explored the earth by sailing around. Early adventurers were motivated by religious beliefs, the desire conquest, the need to establish trade routes, and hunger for gold

You never know what will happen before the exploration. Neither does Bruce Lee. Someday, Mr.Lee entered a desolate tropical rainforest. And after several days' exploring, he came in front of a cave with something blinking in it. A beautiful girl named Vivian came out just before he tried to go into the cave. And Vivian told Mr. Lee that he must answer some questions before he entered the cave. As the best friend of Mr. Lee, you should help him to work it out

You will get $k$ positive integers $p_1, p_2 ... p_i ... p_k$ ($1 \leqslant i \leqslant k$) from Vivian. From these numbers, you can calculate $N, N=\prod_{i=1}^k p_i^{e_i}$ ($0 \leqslant ei \leqslant 10, \sum_{i=1}^ke_i\geqslant1, 1 \leqslant i \leqslant k$); you may decide the integers eias you wish. From one N, you can calculate corresponding $M$, which equals to the sum of all divisors of $N$. Now, you should tell Vivian whether or not there is an $M$ which is the power of $2$ ($1,2, 4, 8$, and $16$ … so on). If there's no $N$ can make M equal to the power of 2, tell Vivian "NO". If $M$ equals to some $2^x$, then show her the exponent ($x$). And if there are several $x$, only show her the largest one

### Input

Input contains several testcases. For each testcase, the first line contains only one integer $k$ ($0 < k \leqslant  100$), representing the number of positive integers. Then there are $k$ positive integers $p_1, p_2 ... p_i ... p_k$ ($1 < pi < 2^{31}, 1 \leqslant  i \leqslant  k$) in the second line, representing the given numbers

Input is terminated by end of file

### Output

For each testcase, you should output your result in a single line. If you can find N from the given numbers, output the largest exponent. Otherwise, output "NO". Extra spaces are not allowed

### Sample Input

```input1
1
2
3
2 3 4
```

### Sample Output

```output1
NO
2
```

### Source

Asia Guangzhou 2003

## 题意简述

给出一组数 $p_1,p_2,\dots,p_k$, 设 $N=\prod_{i=1}^kp_i^{e_i}$, 其中 $0\leqslant e_i\leqslant 10,i=1,2,...,k,~\sum_{i=1}^ke_i\geqslant 1$, $M$ 为 $N$ 的因子和, 问是否有一组数 $e_1,e_2,\dots,e_k$ 使得 $\log_2M\in\mathbb{N}$, 如果有, 输出可能的 $x$ 中的最大值

## 解题思路

我们首先有这样一条定理

### <a href="#end-t-1" id="t-1">定理 - 1</a>

$$M=2^{\sum_{i=1}^sx_i}\iff N=\prod_{i=1}^s(2^{x_i}-1),~2^{x_i}-1~\text{is}~\text{mersenne}~\text{prime}, i=1,2,...,s$$

<a href="#t-1" id="end-t-1">$\Box$</a>

其正确性是显然的

由这条定理, 我们只需判断能否选取一组数 $e_1,e_2,\dots,e_k\in\{0,1\}$ 使得 $N$ 为几个不同的 Mersenne 素数的乘积, 即在 $p_1,p_2,\dots,p_k$ 中选取一些数使得 $N$ 为几个不同的 Mersenne 素数的乘积

我们注意到在 $[1,2^{31}]$ 中只有 $8$ 个 Mersenne 素数, 分别为 $2^{2}-1,2^{3}-1,2^{5}-1,2^{7}-1,2^{13}-1,2^{17}-1,2^{19}-1,2^{31}-1$

因为 $N$ 与这些 Mersenne 素数之间的整除关系的状态种数较少, 所以这里我们可以考虑使用状压 DP

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:POJ_1777 POJ/1777/0.cpp %}

</details>
