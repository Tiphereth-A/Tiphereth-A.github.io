---
title: "题解 - [POJ 2356 等] Find a multiple"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - POJ
  - Ural
  - 数学
  - 计数
  - 抽屉原理
  - 前缀和
date: 2020-07-31 20:58:31
---

题目链接

- [POJ 2356](https://vjudge.net/problem/POJ-2356/origin)
- [Ural 1032](https://vjudge.net/problem/URAL-1032/origin)

<!-- more -->

## 原始题面

### Description

The input contains N natural (i.e. positive integer) numbers ( N <= 10000 ). Each of that numbers is not greater than 15000. This numbers are not necessarily different (so it may happen that two or more of them will be equal). Your task is to choose a few of given numbers ( 1 <= few <= N ) so that the sum of chosen numbers is multiple for N (i.e. N \* k = (sum of chosen numbers) for some natural number k)

### Input

The first line of the input contains the single number N. Each of next N lines contains one number from the given set

### Output

In case your program decides that the target set of numbers can not be found it should print to the output the single number 0. Otherwise it should print the number of the chosen numbers in the first line followed by the chosen numbers themselves (on a separate line each) in arbitrary order

If there are more than one set of numbers with required properties you should print to the output only one (preferably your favorite) of them

### Sample Input

```input1
5
1
2
3
4
1
```

### Sample Output

```output1
2
2
3
```

### Source

Ural Collegiate Programming Contest 1999

## 题意简述

给出 $n$ 个数, 取其中的一个子集, 使得该子集中所有元素的和是 $n$ 的自然数倍

## 解题思路

对这 $n$ 个数求其模 $n$ 意义下的前缀和 `sum[1..n]` , 如果其中有一个 `sum[i] == 0` , 则所求子集即为从第 `1` 个到第 `i` 个的所有元素

否则 `sum[1..n]` 均在 $[1,n-1]$ 内, 此时由抽屉原理可知, 必有两前缀和相等, 即存在 $1\leqslant i<j\leqslant n$ 使得 `sum[i] == sum[j]`, 此时所求子集即为从第 `i + 1` 个到第 `j` 个的所有元素

## 复杂度

$O(n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:POJ_2356 POJ/2356/0.cpp %}

</details>
