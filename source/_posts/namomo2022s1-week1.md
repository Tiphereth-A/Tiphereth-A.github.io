---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 1)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - Codeforces
  - POJ
  - HDU
  - 贪心
  - 位运算
  - 数据结构
  - 数学
  - 组合数学
  - DP
  - 区间DP
  - 滚动数组
  - 单调栈
  - 树
  - LCA
  - 异或
  - 抽屉原理
  - 可持久化线段树/主席树
date: 2022-02-26 21:44:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.02.26-2022.03.04)

<!-- more -->

## 子串的最大差 (CF817D)

[题目链接](https://oj.daimayuan.top/problem/436)

1 s, 1024 MB

定义序列的最大差为序列中最大数与最小数的差. 比如 $(3,1,4,5,6)$ 的最大差为 $6 - 1 = 5$, $(2,2)$ 的最大差为 $2 - 2 = 0$

定义一个序列的子串为该序列中连续的一段序列

给定一个长度为 $n$ 的数组 $a_1,a_2,\dots ,a_n$, 请求出这个序列的所有子串的最大差之和

### 输入格式

第一行一个数字 $n$

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$

### 输出格式

一个数, 表示答案

### 样例输入

```input1
3
1 2 3
```

### 样例输出

```output1
4
```

### 数据规模

所有数据保证 $1\leq n\leq 500000, 0 \leq a_i \leq 10^8$

### 解题思路

> DP + 单调栈

即求
$$\sum_{i=1}^n\sum_{j=1}^i\left(\max_{x\in i..j}\{a_x\}-\min_{x\in i..j}\{a_x\}\right)$$

令

- $$L_i=\max(\{0\}\cup\{x<i\mid a_x>a_i\})$$
- $$R_i=\min(\{n+1\}\cup\{x>i\mid a_x>a_i\})$$
- $$l_i=\max(\{0\}\cup\{x<i\mid a_x<a_i\})$$
- $$r_i=\min(\{n+1\}\cup\{x>i\mid a_x<a_i\})$$

则

$$
\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^i\left(\max_{x\in i..j}\{a_x\}-\min_{x\in i..j}\{a_x\}\right)&=\sum_{i=1}^n\sum_{j=1}^i\max_{x\in i..j}\{a_x\}-\sum_{i=1}^n\sum_{j=1}^i\min_{x\in i..j}\{a_x\}\\
  &=\sum_{i=1}^n a_i(R_i-i)(i-L_i)-\sum_{i=1}^n a_i(r_i-i)(i-l_i)
\end{aligned}
$$

然后用单调栈把 $L_i,R_i,l_i,r_i$ 求出来即可

### 复杂度

$O(n)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_817D CodeForces/817D/0.cpp %}

</details>

## no crossing (CF793D)

[题目链接](https://oj.daimayuan.top/problem/437)

1 s, 1024 MB

给出一个有向图, 找一条恰好经过 $k$ 个点的最短路径, 要求每次选的边不能跃过之前已经经过的节点. 即对于路径中的边 $x \rightarrow y$, 不存在以前经过的点 $t$ 使得三者的编号满足 $\min(x,y) \leq t \leq \max(x,y)$

### 输入格式

第一行三个数字 $n,k,m$

接下来 $m$ 行, 每行 $3$ 个整数 $a_i,b_i,c_i$ 表示存在一条从 $a_i \rightarrow b_i$, 长度为 $c_i$ 的有向边

### 输出格式

一个数, 表示答案. 如果不存在任何一条路径满足条件, 则输出 $-1$

### 样例 1 输入

```input1
7 4 4
1 6 2
6 2 2
2 4 2
2 7 1
```

### 样例 1 输出

```output1
6
```

### 样例 2 输入

```input2
4 3 4
2 1 2
1 3 2
3 4 2
4 1 1
```

### 样例 2 输出

```output2
3
```

### 数据规模

所有数据保证 $1\leq n,k\leq 100, 0 \leq m \leq 2000, 1 \leq a_i,b_i \leq n, 1 \leq c_i \leq 1000$

### Note

样例一的最短路径为 $1 \rightarrow 6 \rightarrow 2 \rightarrow 4$. $1 \rightarrow 6 \rightarrow 2 \rightarrow 7$ 是不正确的, 因为 $2 < 6 < 7$

### 解题思路

> 区间 DP + 滚动数组

如果可以跃过之前经过的结点, 那直接对邻接矩阵求个快速幂就可以了

在有了上述约束后, 我们不难发现随着走的步数越来越多, 可以走的范围是越来越小的

所以我们这样设计状态方程

令

- $f(k,u,v)$ 表示走了 $k$ 步时, 可以走的范围为 $(\min\{u,v\},\max\{u,v\})$, 目前在 $v$ 处的最短路
- $d(u,v)$ 为 $u$ 到 $v$ 的边权, 若两点不相邻则为 $\infty$

则

$$
f(k,u,v)=\begin{cases}
  \min_{x>v}\{f(k-1,u,x)+d(x,v),f(k-1,x,u)+d(u,v)\},&u<v\\
  \min_{x<v}\{f(k-1,u,x)+d(x,v),f(k-1,x,u)+d(u,v)\},&u>v\\
\end{cases}
$$

显然可以用滚动数组把 $k$ 这一维优化一下

### 复杂度

$O(n^3k)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_793D CodeForces/793D/0.cpp %}

</details>

## Dis

[题目链接](https://oj.daimayuan.top/problem/451)

1 s, 512 MB

给出 $n$ 个点的一棵树, 每个点有各自的点权, 多次询问两个点简单路径所构成点集的异或和

### 输入格式

第一行两个数字 $n$ 和 $m$, $n$ 表示点数, $m$ 表示询问次数

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$, 表示每个点的点权

接下来 $n-1$ 行, 每行两个整数 $u,v$, 表示点 $u$ 和点 $v$ 之间存在一条边

再接下来 $m$ 行, 每行两个整数 $u,v$, 表示询问点 $u$ 到点 $v$ 的简单路径所构成点集的异或和

### 输出格式

输出 $m$ 行, 对于每个询问, 输出一行

### 样例输入

```input1
7 3
0 1 2 3 4 5 6
1 2
1 3
2 4
2 5
3 6
3 7
4 6
4 7
5 6
```

### 样例输出

```output1
5
6
2
```

### 数据规模

所有数据保证 $1\leq n,m \leq 200000, 1 \leq a_i \leq 10^6$

### 解题思路

> LCA

LCA 板子题, 略

## 选数 (POJ2356)

[题目链接](https://oj.daimayuan.top/problem/456)

1 s, 1024 MB

给定 $N$ 个正整数 $a_1, a_2, \dots, a_n$ . 要求从其中选出若干数字, 使得这些数字的和 $mod$ $N = 0$ (对于每个下标能且只能选择一次)

### 输入格式

第一行一个数字 $N$, 表示数字个数

接下来一行 $N$ 个整数 $a_1, a_2, \dots, a_n$, 表示这 $N$ 个数

### 输出格式

第一行输出 $M$, 表示选择的数的个数

第二行输出 $M$ 个正整数, 用空格隔开, 表示这些数字的下标

如果有多种方案满足要求, 输出任意一种

如果没有满足要求的方案 输出 $-1$

### 样例输入

```input1
4
1 3 2 5
```

### 样例输出

```output1
2
2 4
```

### 样例解释

$3 + 5 = 8$, $8 \ mod \ 4 = 0$

### 数据规模

所有数据保证 $1\leq N \leq 100000, 1 \leq a_i \leq 10^9$

### 解题思路

> 抽屉原理

以前写过题解, 参见 {% post_link sa-poj-2356 %}

## 序列操作 (CF1198B)

[题目链接](https://oj.daimayuan.top/problem/452)

1 s, 1024 MB

给定一个长度为 $n$ 的序列 $a_1,a_2,\dots ,a_n$

你需要进行两种操作:

1. $1$ $x$ $y$——将第 $x$ 个数变为 $y$

2. $2$ $y$——将所有小于 $y$ 的数修改为 $y$

共执行 $q$ 次操作, 输出执行完所有操作后的序列

### 输入格式

第一行两个数字 $n$, $q$ $(1 \leq n,q \leq 10^6)$

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$. $(0 \leq a \leq 10^9)$

接下来 $q$ 行, 每行表示一个操作: $1$ $x$ $y$ 或 $2$ $y$ $(1 \leq x \leq n, 0 \leq y \leq 10^9)$

### 输出格式

一行整数, 表示操作完后的序列, 用空格分隔

### 样例输入

```input1
5 5
3 6 14 16 12
2 13
2 16
1 1 1
1 2 14
2 11
```

### 样例输出

```output1
11 14 16 16 16
```

### 解题思路

> 别线段树了, O(n) 离线它不香嘛

注意到本题的操作 2 是全局的, 而且所有操作是离线的, 所以没必要用数据结构

我们可以记录操作 2 修改后的最大值, 并且开个 `vis` 数组记录当前的数是否被操作 1 修改过, 然后正向或反向暴力一遍即可

### 复杂度

$O(n)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1198B CodeForces/1198B/0.cpp %}

</details>

## 数数 (HDU4417)

[题目链接](https://oj.daimayuan.top/problem/464)

1 s, 1024 MB

在给定 $N$ 长的数组 $\{A\}$ 中进行 $Q$ 次询问 $[L_i, R_i]$ 区间中不大于 $H_i$ 的元素个数

共包含 $T$ 组数据

### 输入格式

输入就像下面这样:

```plaintext
T
N Q
A1 A2 A3 ... AN
L1 R1 H1
L2 R2 H2
..
LQ RQ HQ
..
```

### 输出格式

$T$ 组数据, 每组都输出一行, 包含 $Q$ 个以空格分隔的整数, 表示答案

### 样例输入

```input1
1
10 3
0 5 2 7 5 4 3 8 7 7
3 9 6
4 6 0
2 4 2
```

### 样例输出

```output1
4 0 1
```

样例说明: $A[3..9] = [\underline{2}, 7, \underline{5, 4, 3,} 8, 7]$, 其中不大于 $6$ 的元素数量为 $4$

### 数据规模

- $1 \le N, Q \le 10^5$
- $0 \le A_i, H \le 10^9$
- $1 \le L \le R \le N$

数据保证 $\sum N, Q \le 10 ^ 5$

### 解题思路

> 我错了, DS 是真的香

懒得想离线做法了, 直接套主席树完事

### 复杂度

$O((n+q)\log n)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:HDU_4417 HDU/4417/0.cpp %}

</details>

## Minimum Or Spanning Tree (CF1624G)

[题目链接](https://oj.daimayuan.top/problem/464)

1 s, 1024 MB

给出 $n$ 个点, $m$ 条边的无向图, 每条边连接 $u,v$ 两个端点, 边权为 $w$, 求图的生成树的最小代价

在这道题中, 我们定义一棵生成树的代价为他所有边的边权按位或得到的值

### 输入格式

第一行两个数字 $n$ 和 $m$ , $n$ 表示点数, $m$ 表示图的边数

接下来 $m$ 行 , 每行三个整数 $u,v,w$, 表示点 $u$ 和点 $v$ 之间存在一条边权为 $w$ 的边

### 输出格式

一行, 描述生成树的最小代价

### 样例输入

```input1
5 7
4 2 7
2 5 8
3 4 2
3 2 1
2 4 2
4 1 2
1 2 2
```

### 样例输出

```output1
10
```

### 数据规模

所有数据保证 $1\leq u,v\leq n\leq 2\cdot 10^5, n-1\leq m \leq 4\cdot 10^5 , 1 \leq w\leq 10^9$ 且至少存在一棵生成树

### 解题思路

> 贪心

一般来说, 求按位与和按位或的最大值都可以从高往低贪心处理

假设当前我们考虑到了第 $i$ 位, 我们只需要考虑所有不会使答案增大的边构成的图是否连通即可

### 复杂度

$O((n+m)\log\max w)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1624G CodeForces/1624G/0.cpp %}

</details>
