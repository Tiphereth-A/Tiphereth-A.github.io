---
title: "题解 - [CodeForces 1637 F] Towers"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - 树
  - 贪心
date: 2022-03-02 10:02:42
---

[题目链接](https://codeforces.com/problemset/problem/1637/F)

<!-- more -->

## 原始题面

time limit per test: 2 seconds

memory limit per test: 256 megabytes

input: standard input

output: standard output

You are given a tree with $n$ vertices numbered from $1$ to $n$. The height of the $i$-th vertex is $h_i$. You can place any number of towers into vertices, for each tower you can choose which vertex to put it in, as well as choose its efficiency. Setting up a tower with efficiency $e$ costs $e$ coins, where $e > 0$

It is considered that a vertex $x$ gets a signal if for some pair of towers at the vertices $u$ and $v$ ($u \neq v$, but it is allowed that $x = u$ or $x = v$) with efficiencies $e_u$ and $e_v$, respectively, it is satisfied that $\min(e_u, e_v) \geq h_x$ and $x$ lies on the path between $u$ and $v$

Find the minimum number of coins required to set up towers so that you can get a signal at all vertices

### Input

The first line contains an integer $n$ ($2 \le n \le 200\,000$) — the number of vertices in the tree

The second line contains $n$ integers $h_i$ ($1 \le h_i \le 10^9$) — the heights of the vertices

Each of the next $n-  1$ lines contain a pair of numbers $v_i, u_i$ ($1 \le v_i, u_i \le n$) — an edge of the tree. It is guaranteed that the given edges form a tree

### Output

Print one integer — the minimum required number of coins
Examples

### Input

```input1
3
1 2 1
1 2
2 3
```

### Output

```output1
4
```

### Input

```input2
5
1 3 3 1 3
1 3
5 4
4 3
2 3
```

### Output

```output2
7
```

### Input

```input3
2
6 1
1 2
```

### Output

```otuput3
12
```

### Note

In the first test case it's optimal to install two towers with efficiencies $2$ at vertices $1$ and $3$

In the second test case it's optimal to install a tower with efficiency $1$ at vertex $1$ and two towers with efficiencies $3$ at vertices $2$ and $5$

In the third test case it's optimal to install two towers with efficiencies $6$ at vertices $1$ and $2$

## 题意简述

在一棵无根树上放若干个塔, 每个塔有权值 $e$, 树上结点自带权值 $h$, 要求树上任意结点均在某两个塔之间的简单路径上, 且这两个塔的权值均不小于该结点的权值, 求塔权值的最小和

## 解题思路

显然塔应都放在叶子结点上

为方便起见, 我们让权值最大的点为根节点, 令其为 $r$, 此时我们只需让叶子结点里有两个塔的权值为 $h_r$ 即可

我们考虑一条从根节点到叶子结点的链, 其中根结点的一端相当于有了一个权值为 $h_r$ 的塔, 那么另一端只需放一个权值为该链上的结点权值次大值的塔即可

> 这有 2500 ?

## 复杂度

$O(n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa title:CodeForces_1637F lang:cpp CodeForces/1637F/0.cpp %}

</details>
