---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 12)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - USACO
  - Codeforces
  - AtCoder
  - 数学
  - 数论
  - DP
  - 数据结构
  - LCS
  - Hash
  - 树状数组
  - 滚动数组
date: 2022-05-14 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.05.14-2022.05.20)

<!-- more -->

## GCD

[题目链接](https://oj.daimayuan.top/problem/871)

3 s, 1024 MB

### 题目描述

给定整数 $a$ 和 $m$,计算整数 $x$ 的数量,满足 $0\le x< m$ 同时 $gcd(a,m)= gcd(a+x,m)$

### 输入格式

第一行一个数字 $T$

接下来 $T$ 行 $2$ 个整数 $a,m$

### 输出格式

T 行, 每行一个数, 表示答案

### 样例输入

```input1
3
4 9
5 10
42 9999999967
```

### 样例输出

```output1
6
1
9999999966
```

### 数据规模

所有数据保证 $1\le T\le 50,1\le a< m\le 1e10$

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 最大连边数量 ([USACO2017FEB Why Did the Cow Cross the Road II](http://www.usaco.org/index.php?page=viewproblem2&cpid=721), 洛谷 P3657)

[题目链接](https://oj.daimayuan.top/problem/916)

5 s, 128 MB

### 题目描述

有两个长度为 $n$ 的排列 $A、B$

其中数的范围均为 $1 - n$. 若 $abs(A[i] - B[j]) \le 4$, 则 $A[i]$ 与 $B[j]$ 间可以连一条边

现要求在边与边不相交的情况下的最大的连边数量

例如样例中: 如果 $a_1$ 和 $b_2$ 连边 且 $a_2$ 和 $b_1$ 连边, 则这两条边相交

数据保证 $A,B$ 都是一个排列

### 输入格式

第一行一个整数 $n$

接下来 $n$ 行, 每行一个数字 $a_i$

接下来 $n$ 行, 每行一个数字 $b_i$

### 样例输入

```input1
6
1
2
3
4
5
6
6
5
4
3
2
1
```

### 样例输出

```output1
5
```

### 数据范围

$1 \le n \le 10^5$

### 解题思路

> 树状数组优化 LCS

设 $f(i,j)$ 表示左边 $[1,i]$, 右边 $[1,j]$ 范围内的最大值, 显然是个 LCS 类型的 DP, 有

$$f(i,j)=\max\{f(i,j-1),f(i-1,j),f(i-1,j-1)+[|a_i-b_j|\leq 4]\}$$

然后用树状数组维护前缀最值优化即可

### 复杂度

$O(n\log n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P3657 Luogu/P3657/0.cpp %}

</details>

## 序列中位数

[题目链接](https://oj.daimayuan.top/problem/877)

1 s, 1024 MB

### 题目描述

给定正整数 $N$, 求出 $1 \sim N - 1$ 中所有与 $N$ 互质的数构成的序列 的中位数

我们定义 : 一个长度为 $K$ 的序列的中位数是序列中第 $\lfloor\frac{K + 1}{2}\rfloor$ 大的数字. 且两个正整数 $a$ 与 $b$ 互质当且仅当 $gcd(a, b) = 1$

### 输入格式

第一行一个正整数 $T$, 表示数据组数

对于每组数据, 一行输入一个正整数 $N$

对于所有数据, 满足 $1 \leq T \leq 100$,$2 \leq N \leq 10^{18}$

### 输出格式

对于每组测试数据, 输出一行一个正整数, 表示答案

### 样例输入

```input1
3
6
10
19
```

### 样例输出

```output1
1
3
9
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 选元素 (数据加强版)

[题目链接](https://oj.daimayuan.top/problem/875)

1 s, 1024 MB

### 题目描述

给定一个长度为 $n$ 的整数序列 $a_1,a_2,…,a_n$

请你从中挑选 $x$ 个元素, 要求:

1. 原序列中的每一个长度为 $k$ 的连续子序列都至少包含一个被选中的元素
1. 满足条件 $1$ 的前提下, 所选 $x$ 个元素的相加之和应尽可能大. 输出最大可能和

### 输入格式

第一行包含三个整数 $n,k,x$

第二行包含 $n$ 个整数 $a_1,a_2,…,a_n$

### 输出格式

如果无法满足题目要求, 则输出 $−1$

否则, 输出一个整数, 表示所选元素的最大可能和

### 数据范围

所有测试点满足 $1≤k,x≤n≤2500, 1≤a_i≤10^9$

### 输入样例 1

```input1
5 2 3
5 1 3 10 1
```

### 输出样例 1

```output1
18
```

### 输入样例 2

```input2
6 1 5
10 30 30 70 10 10
```

### 输出样例 2

```output2
-1
```

### 输入样例 3

```input3
4 3 1
1 100 1 1
```

### 输出样例 3

```output3
100
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 最长上升子序列计数 (Bonus)

[题目链接](https://oj.daimayuan.top/problem/884)

1 s, 1024 MB

本题是 <http://oj.daimayuan.top/problem/326> 的加强版, 差别仅在于 $n$ 与 $a_i$ 的取值

### 题目描述

求最长上升子序列及其长度的问题已经相当普及, 本题希望你求解 最长上升子序列的个数

只要有序元组有一个值不同, 就称不同. 如 $[1, \color{green}{3}$$,\color{red}{3}$$, 0, 4]$ 中 $[1, \color{green}{3}$$, 4], [1,\color{red}{3}$$, 4]$ 算作两个答案

### 输入格式

输入包含两行, 第一行有一个整数 $n$, 表示序列 $\{a\}$ 的大小

接下来一行包含 $n$ 个用空格分隔的整数, 依次表示 $a_1, a_2, \cdots, a_n$

### 输出格式

输出最长上升子序列的个数

由于这个值可能很大, 你只需要输出其模余 $10^9 + 7$ 的结果

### 数据规模

-$1 \le n \le 4 \times 10 ^ 5$ -$a_i \in [-10 ^ 8, 10 ^ 8]$

### 样例 1 输入

```input1
5
1 3 3 0 4
```

### 样例 1 输出

```output1
2
```

### 样例 2 输入

```input2
8
1 2 4 2 4 7 3 4
```

### 样例 2 输出

```output2
5
```

### 解释

共包含:

$[1, 2, 4, 7] \times 3$

$[1, 2, 3, 4] \times 2$

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## LCM 与 GCD (CF1499D)

[题目链接](https://oj.daimayuan.top/problem/953)

3 s, 1024 MB

### 题目描述

给定三个正整数 $x,y,k$, 求满足 $x \times lcm(a,b) - y \times gcd(a,b) = k$ 的数对 $(a,b)$ 的数量 , 其中 $lcm(a,b)$ 是 $a,b$ 的最小公倍数 ,$gcd(a,b)$ 是 $a,b$ 的最大公约数

若 $a \neq b$ 那么 $(a,b)$ 与 $(b,a)$ 是两个不同的数对

### 输入格式

第一行一个整数 $t$, 表示数据组数.$(1 \leq t \leq 10^3)$

接下来 $t$ 行, 每行输入三个整数 $x,y,k$, 含义如题面所示.$( 1 \leq x,y,k \leq 10^7 )$

### 输出格式

输出 $t$ 行, 每行一个整数, 表示满足要求二元对的数量

### 样例输入

```input1
4
1 1 3
4 2 6
3 3 7
2 7 25
```

### 样例输出

```output1
4
3
0
8
```

### 解题思路

> 简单数论

显然有

$$\alpha (xpq-y)=k$$

其中 $p,q$ 互质

然后枚举 $k$ 的因子之后计算 $p,q$ 的对数即可

### 复杂度

$O(2K+t\sqrt{2k})$, 其中 $K=10^7$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1499D CodeForces/1499D/0.cpp %}

</details>

## 前缀集 (AtCoder abc250e)

[题目链接](https://oj.daimayuan.top/problem/930)

2 s, 512 MB

### 题目描述

定义序列 $a$ 的前缀集 $S(a, i)$ 为 `a[1]..a[i]` 这 i 个元素构成的集合

给定两个长为 $n$ 的序列 $a, b$

$m$ 次询问, 每次询问两个位置 i, j

请你判断 $a$ 的前缀集 $S(a, i)$ 和 $b$ 的前缀集 $S(b, i)$ 是否相同

### 输入描述

一行一个整数 $n(n\leq 5\times 10^5)$

两行, 一行 $n$ 个整数, 分别描述 $a, b(1\leq a_i,b_i\leq 10^9)$

一行一个整数 $m(m\leq 5\times 10^5)$

$m$ 行, 每行两个数 $i(1\leq i\leq n)$, $j(1\leq j \leq n)$, 表示询问 $S(a, i)$ 和 $S(b, j)$

### 输出描述

m 行, 如果相同输出 Y, 否则输出 N

### 样例输入

```input1
5
1 2 3 4 5
1 2 2 4 3
7
1 1
2 2
2 3
3 3
4 4
4 5
5 5
```

### 样例输出

```output1
Y
Y
Y
N
N
Y
N
```

### 原题链接

[戳我](https://atcoder.jp/contests/abc250/tasks/abc250_e)

### 解题思路

> Hash / Set

取 $S_A(i)=|\{a_1,a_2,...,a_i\}|$, 那么 $S(a,i)=S(b,j)\implies S_A(i)=S_B(j)$

若 $S_A(i)=S_B(j)$, 只需事先计算出来 $a,b$ 去重后当 $S_A(i)$ 取哪些值时才会相同即可

### 复杂度

$O(n+q)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:AtCoder_abc250e AtCoder/abc250_e/0.cpp %}

</details>
