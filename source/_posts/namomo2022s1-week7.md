---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 7)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - CodeForces
  - 贪心
date: 2022-04-09 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.04.09-2022.04.15)

<!-- more -->

## 画画 (CF1638D)

[题目链接](https://oj.daimayuan.top/problem/701)

3 s, 512 MB

### 题目描述

现有一个 $n \times m$ 的画布, 上面每一个单元格 $(i,j)$ 都有一个正整数表示的颜色 $c_{i, j}$, $(1\le c_{i,j} \le n\times m)$

你可以在一个 $n\times m$ 的空白画布上进行以下操作至多 $n \times m$ 次:

在画布上选择一个 $2 \times 2$ 的正方形, 将这整个正方形涂成任意一种颜色 $p$, $1\le p\le n \times m$

所有单元格必须至少涂一次. 一个单元格可以多次绘制. 在这种情况下, 它的最终颜色将是最后一种颜色

现在问是否有一种方案使得你最后染色的画布与画布 $c$ 相同. 如果不存在合法的染色方案请输出 -1

### 输入格式

输入的第一行包含两个整数 $n$ 和 $m$, $(2\le n,m \le 1000)$, 表示画布的尺寸

接下来 $n$ 行, 每行 $m$ 个整数, 第 $i$ 行第 $j$ 个整数表示 $c_{i, j}$, $(1\le c_{i, j}\le n \times m)$, 表示画布每一个单元格的颜色

### 输出格式

如果没有解决方案, 请输出一行一个整数 -1

否则, 在第一行输出一个整数 $q$, $(1\le q \le n \times m)$, 表示操作次数

接下来, 按顺序输出操作, 输出 $q$ 行, 每行三个整数 $x, y, p$, 表示你选择的正方形坐上角 $(x,y)$, $(1\le x \le n - 1, 1 \le y \le m - 1)$, 以及这个方格将会染成的颜色 $p$

如果存在多个解决方案, 请输出任何一个

### 样例 1 输入

```input1
4 4
5 5 3 3
1 1 5 3
2 2 5 4
2 2 4 4
```

### 样例 1 输出

```output1
6
1 3 3
3 3 4
2 2 5
1 1 5
2 1 1
3 1 2
```

### 样例 2 输入

```input2
3 4
1 1 1 1
2 2 3 1
2 2 1 1
```

### 样例 2 输出

```output2
-1
```

### 解释

对于第一个输入这是一种合法的染色方案:

![](701-1.png)

对于第二个输入不可能找到一种合适的解决方案

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1638D CodeForces/1638D/0.cpp %}

</details>

## 数字替换

[题目链接](https://oj.daimayuan.top/problem/731)

2 s, 256 MB

### 题目描述

维护一个数列, 这个数列初始为空

对于这个数列, 总共有 $q$ 次操作, 每次操作分为如下两个种类:

$1\ x$, 意为在数列末尾加一个数字

$2\ x\ y$, 意为将当前数列中所有值为 $x$ 的数的值替换成 $y$

请在 $q$ 次操作后, 输出这个数列

### 输入格式

第 $1$ 行一个数字 $q$, 表示有 $q$ 个操作

第 $2$ 行至 $q+1$ 行每行输入一个操作

### 输出格式

一行, 表示最后得到的数列

### 样例输入

```input1
7
1 3
1 1
2 1 2
1 2
1 1
1 2
2 1 3
```

### 样例输出

```output1
3 2 2 3 2
```

### 数据规模

$1\leq q,x,y\leq 5 \times 10^5$

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 游戏

[题目链接](https://oj.daimayuan.top/problem/712)

1 s, 1024 MB

### 题目描述

Alice 和 Bob 在玩一个游戏. 有一个长为$N$, 宽为$M$的棋盘, 他们轮流在棋盘上的空位置放置一个棋子. 当一位玩家放置完棋子后, 如果对于棋盘上任意一块$K * K$的区域, 都存在至少一个棋子. 那么游戏结束, 最后放置的玩家获胜. Alice 先放棋子, 在他们的操作都是最优的情况下, 求出谁会赢得这场游戏

### 输入格式

第一行三个正整数$N$, $M$和$K$. ($N \leq M$)

### 输出格式

一行一个字符串, 在 Alice 先操作的情况下, 如果 Alice 获胜, 输出"Alice". 否则, 输出"Bob"

### 数据范围

对于所有数据, 满足: $1 \leq N \leq 3000$, $1 \leq N \leq M \leq 10^5$, 且$1 \leq K \leq N$

### 样例输入 1

```input1
1 2 1
```

### 样例输出 1

```output1
Bob
```

### 样例输入 2

```input2
3 3 2
```

### 样例输出 2

```output2
Alice
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 合适数对 (数据加强版)

[题目链接](https://oj.daimayuan.top/problem/733)

1 s, 1024 MB

### 题目描述

给定一个长度为 $n$ 的正整数数列 $a_{1}, a_{2}, \ldots, a_{n}$ 和一个正整数 $k_{\text {.  }}$ 请你判断共有多少个数对 $(l, r)$ 同时满足:

- $1\leq l < r \leq n$
- 存在一个整数 $x$ 使得 $a_{l} \times a_{r}=x^{k}$ 成立

### 输入格式

第一行包含两个整数 $n, k_{\text {.  }}$ 第二行包含 $n$ 个正整数 $a_{1}, a_{2}, \ldots, a_{n}$

### 输出格式

一个整数, 表示满足条件的数对的数量

### 数据范围

所有测试点满足 $2 \leq n \leq 10^{6},  2 \leq k \leq 100 ,  1 \leq a_{i} \leq 10^{7}$

### 输入样例

```input1
6 3
1 3 9 8 24 1
```

### 输出样例

```output1
5
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## Fence Painting (CF1481C)

[题目链接](https://oj.daimayuan.top/problem/735)

1 s, 128 MB

### 题目描述

有编号从 $1$ 开始的 $n$ 块木板, 第 $i$ 块木板的颜色是 $a_i$, 你希望把第 $i$ 块木板的颜色染成 $b_i$

有 $m$ 个画家会依次来工作, 第 $j$ 个画家会把某一块木板染成颜色 $c_j$, 你可以指定他们染哪一块, 但是不能不染

判断能否把所有木板都染成目标颜色, 如果能, 输出方案

### 输入格式

多组测试数据

第一行输入一个整数 $T$ $(1 \leq T \leq 10000)$

对于每组测试数据第一行输入两个整数 $n, m$ $(1 \leq n, m \leq 100000)$ 用空格隔开

接下来一行输入 $n$ 个整数为 $a_i$ $(1 \leq a_i \leq n)$

接下来一行输入 $n$ 个整数为 $b_i$ $(1 \leq b_i \leq n)$

接下来一行输入 $m$ 个整数为 $c_i$ $(1 \leq c_i \leq n)$

数据保证 $\sum n, \sum m \leq 100000$

### 输出格式

对于每组测试数据, 如果不能染成目标颜色输出一行 NO

如果能染成目标颜色首先输出一行 YES

接下来一行输出 $m$ 个整数, 表示第 $j$ 个到来的画家染编号为多少的画板, 有多种满足条件的方案可以输出任意一种

### 输入样例

```input1
6
1 1
1
1
1
5 2
1 2 2 1 1
1 2 2 1 1
1 2
3 3
2 2 2
2 2 2
2 3 2
10 5
7 3 2 1 7 9 4 2 7 9
9 9 2 1 4 9 4 2 3 9
9 9 7 4 3
5 2
1 2 2 1 1
1 2 2 1 1
3 3
6 4
3 4 2 4 1 2
2 3 1 3 1 1
2 2 3 4
```

### 输出样例

```output1
YES
1
YES
2 2
YES
1 1 1
YES
2 1 9 5 9
NO
NO
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 质区间长度

[题目链接](https://oj.daimayuan.top/problem/737)

1 s, 1024 MB

### 题目描述

对于一个区间 $[l , r]$ 和$k$, 称其为质区间当且仅当该区间内质数个数至少为$k$个

给定区间$[l , r]$和$k$, 请找到一个最小$len$, 使得对于任意$x \in [l , r - len + 1]$, 都有$[x , x + len - 1]$是质区间

### 输入格式

一行三个整数$l , r , k$, 含义如题面所示$( 1 \leq l \leq r \leq 10^6 , 0 \leq k \leq 10^6 ) $

### 输出格式

输出一行一个整数$len $

若不存在这样的$len$, 则输出$-1 $

### 样例输入

```input1
6 14 2
```

### 样例输出

```output1
6
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 最长有趣子序列

[题目链接](https://oj.daimayuan.top/problem/741)

1 s, 1024 MB

### 题目描述

定义一个序列是有趣的当且仅当他相邻两项的与不为 0

即对一个长为$n$的序列$\{a\}$, 满足$\forall x< n\ a[x]\&a[x+1] \neq 0$

现在给你一个长为$n$的序列$\{a\}$, 请问最长的有趣子序列的长度是多少

### 输入描述

一行一个整数$1\leq n \leq 10^6$

接下来一行 n 个整数$1 \leq a_i \leq 2^{31} - 1$

### 输出描述

一行一个整数, 用于描述最长有趣子序列的长度

### 样例输入

```input1
3
1 2 3
```

### 样例输出

```output1
2
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>
