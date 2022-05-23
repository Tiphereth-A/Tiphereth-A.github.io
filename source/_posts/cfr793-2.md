---
title: "题解 - Codeforces Round #793 (Div. 2) (A-D)"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - 字符串
  - 数学
  - 构造
  - 图论
  - 回文字符串
  - 位运算
  - LIS
  - 树
  - 握手定理
date: 2022-05-23 14:24:10
---

[比赛链接](https://codeforces.com/contest/1682)

体验很好的构造场, 和某被称为 ['best of 2022'](https://codeforces.com/blog/entry/102961?#comment-913322) 的 [比赛](https://codeforces.com/contest/1684) 相比不知道高到哪里去了

<!-- more -->

## A - Palindromic Indices

### 原始题面

You are given a **palindromic** string $s$ of length $n$

You have to count the number of indices $i$ $(1 \le i \le n)$ such that the string after removing $s_i$ from $s$ still remains a palindrome

For example, consider $s$ = "aba"

1. If we remove $s_1$ from $s$, the string becomes "ba" which is not a palindrome
1. If we remove $s_2$ from $s$, the string becomes "aa" which is a palindrome
1. If we remove $s_3$ from $s$, the string becomes "ab" which is not a palindrome

A palindrome is a string that reads the same backward as forward. For example, "abba", "a", "fef" are palindromes whereas "codeforces", "acd", "xy" are not

### Input

The input consists of multiple test cases. The first line of the input contains a single integer $t$ $(1 \leq t \leq 10^3)$ — the number of test cases. Description of the test cases follows

The first line of each testcase contains a single integer $n$ $(2 \leq n \leq 10^5)$ — the length of string $s$

The second line of each test case contains a string $s$ consisting of lowercase English letters. It is guaranteed that $s$ is a palindrome

It is guaranteed that sum of $n$ over all test cases does not exceed $2 \cdot 10^5$

### Output

For each test case, output a single integer — the number of indices $i$ $(1 \le i \le n)$ such that the string after removing $s_i$ from $s$ still remains a palindrome

### Example

#### input

```input1
3
3
aba
8
acaaaaca
2
dd
```

#### output

```output1
1
4
2
```

### Note

The first test case is described in the statement

In the second test case, the indices $i$ that result in palindrome after removing $s_i$ are $3, 4, 5, 6$. Hence the answer is $4$

In the third test case, removal of any of the indices results in "d" which is a palindrome. Hence the answer is $2$

### 题意简述

给一个回文串, 问删掉一个字符后仍为回文串的方法数

### 解题思路

显然只能删靠近中心位置且和中心位置字符相同的字符

如果要是任意串的话需要搞个 Hash, 但回文串直接扫就行

### 复杂度

$O(n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1682A CodeForces/1682A/0.cpp %}

</details>

## B - AND Sorting

### 原始题面

You are given a permutation $p$ of integers from $0$ to $n-1$ (each of them occurs exactly once). Initially, the permutation is **not sorted** (that is, $p_i>p_{i+1}$ for at least one $1 \le i \le n - 1$)

The permutation is called $X$-sortable for some non-negative integer $X$ if it is possible to sort the permutation by performing the operation below some finite number of times:

- Choose two indices $i$ and $j$ $(1 \le i \lt j \le n)$ such that $p_i \& p_j = X$
- Swap $p_i$ and $p_j$

Here $\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND)

Find the **maximum** value of $X$ such that $p$ is $X$-sortable. It can be shown that there always exists some value of $X$ such that $p$ is $X$-sortable

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ $(1 \le t \le 10^4)$ — the number of test cases. Description of test cases follows

The first line of each test case contains a single integer $n$ $(2 \le n \le 2 \cdot 10^5)$ — the length of the permutation

The second line of each test case contains $n$ integers $p_1, p_2, ..., p_n$ ($0 \le p_i \le n-1$, all $p_i$ are distinct) — the elements of $p$. It is guaranteed that $p$ is not sorted

It is guaranteed that the sum of $n$ over all cases does not exceed $2 \cdot 10^5$

### Output

For each test case output a single integer — the maximum value of $X$ such that $p$ is $X$-sortable

### Example

#### input

```input1
4
4
0 1 3 2
2
1 0
7
0 1 2 3 5 6 4
5
0 3 2 1 4
```

#### output

```output1
2
0
4
1
```

### Note

In the first test case, the only $X$ for which the permutation is $X$-sortable are $X = 0$ and $X = 2$, maximum of which is $2$

Sorting using $X = 0$:

- Swap $p_1$ and $p_4$, $p = [2, 1, 3, 0]$
- Swap $p_3$ and $p_4$, $p = [2, 1, 0, 3]$
- Swap $p_1$ and $p_3$, $p = [0, 1, 2, 3]$

Sorting using $X = 2$:

- Swap $p_3$ and $p_4$, $p = [0, 1, 2, 3]$

In the second test case, we must swap $p_1$ and $p_2$ which is possible only with $X = 0$

### 题意简述

给一个非升序的排列, 若通过交换若干对按位与值为 $x$ 的数之后能变为升序则称是 $x$-可排序的, 问 $x$ 的最大值

### 解题思路

显然 $0\leq x<n$

显然要交换的数一定包含全部不满足 $p_i=i$ 的数, 而两个数按位与的结果不会比这两个数大, 所以所求即为全部不满足 $p_i=i$ 的数的按位与

### 复杂度

$O(n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1682B CodeForces/1682B/0.cpp %}

</details>

## C - LIS or Reverse LIS?

### 原始题面

You are given an array $a$ of $n$ positive integers

Let $\text{LIS}(a)$ denote the length of [longest strictly increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) of $a$. For example,

- $\text{LIS}([2, \underline{1}, 1, \underline{3}])$ = $2$
- $\text{LIS}([\underline{3}, \underline{5}, \underline{10}, \underline{20}])$ = $4$
- $\text{LIS}([3, \underline{1}, \underline{2}, \underline{4}])$ = $3$

We define array $a'$ as the array obtained after reversing the array $a$ i.e. $a' = [a_n, a_{n-1}, \ldots , a_1]$

The beauty of array $a$ is defined as $min(\text{LIS}(a),\text{LIS}(a'))$

Your task is to determine the maximum possible beauty of the array $a$ if you can rearrange the array $a$ arbitrarily

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ $(1 \leq t \leq 10^4)$ — the number of test cases. Description of the test cases follows

The first line of each test case contains a single integer $n$ $(1 \leq n \leq 2\cdot 10^5)$ — the length of array $a$

The second line of each test case contains $n$ integers $a_1,a_2, \ldots ,a_n$ $(1 \leq a_i \leq 10^9)$ — the elements of the array $a$

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$

### Output

For each test case, output a single integer — the maximum possible beauty of $a$ after rearranging its elements arbitrarily

### Example

#### input

```input1
3
3
6 6 6
6
2 5 4 5 2 4
4
1 3 2 2
```

#### output

```output1
1
3
2
```

### Note

In the first test case, $a$ = $[6, 6, 6]$ and $a'$ = $[6, 6, 6]$. $\text{LIS}(a) = \text{LIS}(a')$ = $1$. Hence the beauty is $min(1, 1) = 1$

In the second test case, $a$ can be rearranged to $[2, 5, 4, 5, 4, 2]$. Then $a'$ = $[2, 4, 5, 4, 5, 2]$. $\text{LIS}(a) = \text{LIS}(a') = 3$. Hence the beauty is $3$ and it can be shown that this is the maximum possible beauty

In the third test case, $a$ can be rearranged to $[1, 2, 3, 2]$. Then $a'$ = $[2, 3, 2, 1]$. $\text{LIS}(a) = 3$, $\text{LIS}(a') = 2$. Hence the beauty is $min(3, 2) = 2$ and it can be shown that $2$ is the maximum possible beauty

### 题意简述

对给定的数列, 问重排后正序严格 LIS 和逆序严格 LIS 较小值的最大值为多少

### 解题思路

不难发现若一个数重复出现了超过 2 次, 那么其中只有 2 个数会产生贡献, 所以要离散化之后去掉这些数

一个普遍的错误构造方法是排成单峰, Hack:

```text
1
5
1 1 2 3 3
```

这个的最优排列是 `1 3 2 3 1`, 答案是 `3`

实际上正序严格 LIS 和逆序严格 LIS 最多只能有一个公共的数, 所以答案即为 $a+\lceil b/2\rceil$, 其中 $a$ 为出现 2 次及以上的数的个数, $b$ 为出现 1 次的数的个数

### 复杂度

$O(n\log n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1682C CodeForces/1682C/0.cpp %}

</details>

## D - Circular Spanning Tree

### 原始题面

There are $n$ nodes arranged in a circle numbered from $1$ to $n$ in the clockwise order. You are also given a binary string $s$ of length $n$

Your task is to construct a tree on the given $n$ nodes satisfying the two conditions below or report that there such tree does not exist:

- For each node $i$ $(1 \le i \le n)$, the degree of node is even if $s_i = 0$ and odd if $s_i = 1$
- No two edges of the tree intersect internally in the circle. The edges are allowed to intersect on the circumference

Note that all edges are drawn as straight line segments. For example, edge $(u, v)$ in the tree is drawn as a line segment connecting $u$ and $v$ on the circle

A tree on $n$ nodes is a connected graph with $n - 1$ edges

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ $(1 \leq t \leq 2\cdot 10^4)$ — the number of test cases. Description of the test cases follows

The first line of each test case contains a single integer $n$ $(2 \leq n \leq 2\cdot 10^5)$ — the number of nodes

The second line of each test case contains a binary string $s$ of length $n$

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$

### Output

For each test case, if there does not exist a tree that satisfies the given conditions, then output "`NO`" (without quotes), otherwise output "`YES`" followed by the description of tree

You can output each letter in any case (for example, "`YES`", "`Yes`", "`yes`", "`yEs`", "`yEs`" will be recognized as a positive answer)

If there exists a tree, then output $n - 1$ lines, each containing two integers $u$ and $v$ $(1 \leq u,v \leq n, u \neq v)$ denoting an edge between $u$ and $v$ in the tree. If there are multiple possible answers, output any

### Example

#### input

```input1
3
4
0110
2
10
6
110110
```

#### output

```output1
YES
2 1
3 4
1 4
NO
YES
2 3
1 2
5 6
6 2
3 4
```

### Note

In the first test case, the tree looks as follows:

![](D-1.png)

In the second test case, there is only one possible tree with an edge between $1$ and $2$, and it does not satisfy the degree constraints

In the third test case,

![](D-2.png)

### 题意简述

在一个圆上的 $n$ 等分点上建树, 要求

- 每条边都在圆内且不相交
- 每个点度数的奇偶性满足要求

### 解题思路

由握手定理, 奇度点的个数必须有且仅有偶数个的时候才能建树

若所有点都是奇度点, 则随便找个根连一个菊花就行

否则找一偶度点为根即可

> 赛时写的奇度点为根, 巨难写, 花了我几乎整场比赛的时间
>
> 我太菜了

### 复杂度

$O(n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1682D CodeForces/1682D/0.cpp %}

</details>

## E - Unordered Swaps

### 原始题面

Alice had a permutation $p$ of numbers from $1$ to $n$. Alice can swap a pair $(x, y)$ which means swapping elements at positions $x$ and $y$ in $p$ (i.e. swap $p_x$ and $p_y$). Alice recently learned her first sorting algorithm, so she decided to sort her permutation in the **minimum** number of swaps possible. She wrote down all the swaps in the order in which she performed them to sort the permutation on a piece of paper

For example,

- $[(2, 3), (1, 3)]$ is a valid swap sequence by Alice for permutation $p = [3, 1, 2]$ whereas $[(1, 3), (2, 3)]$ is not because it doesn't sort the permutation. Note that we cannot sort the permutation in less than $2$ swaps
- $[(1, 2), (2, 3), (2, 4), (2, 3)]$ cannot be a sequence of swaps by Alice for $p = [2, 1, 4, 3]$ even if it sorts the permutation because $p$ can be sorted in $2$ swaps, for example using the sequence $[(4, 3), (1, 2)]$

Unfortunately, Bob shuffled the sequence of swaps written by Alice

You are given Alice's permutation $p$ and the swaps performed by Alice in arbitrary order. Can you restore the correct sequence of swaps that sorts the permutation $p$? Since Alice wrote correct swaps before Bob shuffled them up, it is guaranteed that there exists some order of swaps that sorts the permutation

### Input

The first line contains $2$ integers $n$ and $m$ $(2 \le n \le 2 \cdot 10^5, 1 \le m \le n - 1)$ — the size of permutation and the minimum number of swaps required to sort the permutation

The next line contains $n$ integers $p_1, p_2, ..., p_n$ ($1 \le p_i \le n$, all $p_i$ are distinct) — the elements of $p$. It is guaranteed that $p$ forms a permutation

Then $m$ lines follow. The $i$-th of the next $m$ lines contains two integers $x_i$ and $y_i$ — the $i$-th swap $(x_i, y_i)$

It is guaranteed that it is possible to sort $p$ with these $m$ swaps and that there is no way to sort $p$ with less than $m$ swaps

### Output

Print a permutation of $m$ integers — a valid order of swaps written by Alice that sorts the permutation $p$. See sample explanation for better understanding

In case of multiple possible answers, output any

### Examples

#### input

```input1
4 3
2 3 4 1
1 4
2 1
1 3
```

#### output

```output1
2 3 1
```

#### input

```input2
6 4
6 5 1 3 2 4
3 1
2 5
6 3
6 4
```

#### output

```output2
4 1 3 2
```

### Note

In the first example, $p = [2, 3, 4, 1]$, $m = 3$ and given swaps are $[(1, 4), (2, 1), (1, 3)]$

There is only one correct order of swaps i.e $[2, 3, 1]$

1. First we perform the swap $2$ from the input i.e $(2, 1)$, $p$ becomes $[3, 2, 4, 1]$
1. Then we perform the swap $3$ from the input i.e $(1, 3)$, $p$ becomes $[4, 2, 3, 1]$
1. Finally we perform the swap $1$ from the input i.e $(1, 4)$ and $p$ becomes $[1, 2, 3, 4]$ which is sorted

In the second example, $p = [6, 5, 1, 3, 2, 4]$, $m = 4$ and the given swaps are $[(3, 1), (2, 5), (6, 3), (6, 4)]$

One possible correct order of swaps is $[4, 2, 1, 3]$

1. Perform the swap $4$ from the input i.e $(6, 4)$, $p$ becomes $[6, 5, 1, 4, 2, 3]$
1. Perform the swap $2$ from the input i.e $(2, 5)$, $p$ becomes $[6, 2, 1, 4, 5, 3]$
1. Perform the swap $1$ from the input i.e $(3, 1)$, $p$ becomes $[1, 2, 6, 4, 5, 3]$
1. Perform the swap $3$ from the input i.e $(6, 3)$ and $p$ becomes $[1, 2, 3, 4, 5, 6]$ which is sorted

There can be other possible answers such as $[1, 2, 4, 3]$

### 题意简述

给定一段对换序列和一个排列, 要求给出对换序列的一个排列, 使得能够使给定的排列变为升序且此时的对换序列是能使得给定的排列变为升序的最短对换序列

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## F - MCMF?

### 原始题面

You are given two integer arrays $a$ and $b$ ($b_i \neq 0$ and $|b_i| \leq 10^9$). Array $a$ is sorted in **non-decreasing** order

The cost of a subarray $a[l:r]$ is defined as follows:

- If $ \sum\limits\_{j = l}^{r} b_j \neq 0$, then the cost is not defined
- Otherwise:
  - Construct a bipartite flow graph with $r-l+1$ vertices, labeled from $l$ to $r$, with all vertices having $b_i \lt 0$ on the left and those with $b_i \gt 0$ on right. For each $i, j$ such that $l \le i, j \le r$, $b_i<0$ and $b_j>0$, draw an edge from $i$ to $j$ with infinite capacity and cost of unit flow as $|a_i-a_j|$
  - Add two more vertices: source $S$ and sink $T$
  - For each $i$ such that $l \le i \le r$ and $b_i<0$, add an edge from $S$ to $i$ with cost $0$ and capacity $|b_i|$
  - For each $i$ such that $l \le i \le r$ and $b_i>0$, add an edge from $i$ to $T$ with cost $0$ and capacity $|b_i|$
  - The cost of the subarray is then defined as the minimum cost of maximum flow from $S$ to $T$

You are given $q$ queries in the form of two integers $l$ and $r$. You have to compute the cost of subarray $a[l:r]$ for each query, modulo $10^9 + 7$

If you don't know what the minimum cost of maximum flow means, read here

### Input

The first line of input contains two integers $n$ and $q$ $(2 \leq n \leq 2\cdot 10^5, 1 \leq q \leq 2\cdot10^5)$ — length of arrays $a$, $b$ and the number of queries

The next line contains $n$ integers $a_1,a_2 \ldots a_n$ ($0 \leq a_1 \le a_2 \ldots \le a_n \leq 10^9)$ — the array $a$. It is guaranteed that $a$ is sorted in **non-decreasing** order

The next line contains $n$ integers $b_1,b_2 \ldots b_n$ $(-10^9\leq b_i \leq 10^9, b_i \neq 0)$ — the array $b$

The $i$-th of the next $q$ lines contains two integers $l_i,r_i$ $(1\leq l_i \leq r_i \leq n)$. It is guaranteed that $ \sum\limits\_{j = l_i}^{r_i} b_j = 0$

### Output

For each query $l_i$, $r_i$ — print the cost of subarray $a[l_i:r_i]$ modulo $10^9 + 7$

### Example

#### input

```input1
8 4
1 2 4 5 9 10 10 13
6 -1 1 -3 2 1 -1 1
2 3
6 7
3 5
2 6
```

#### output

```output1
2
0
9
15
```

### Note

In the **first query**, the maximum possible flow is $1$ i.e one unit from source to $2$, then one unit from $2$ to $3$, then one unit from $3$ to sink. The cost of the flow is $0 \cdot 1 + |2 - 4| \cdot 1 + 0 \cdot 1 = 2$

In the **second query**, the maximum possible flow is again $1$ i.e from source to $7$, $7$ to $6$, and $6$ to sink with a cost of $0 \cdot |10 - 10| \cdot 1 + 0 \cdot 1 = 0$

In the **third query**, the flow network is shown on the left with capacity written over the edge and the cost written in bracket. The image on the right shows the flow through each edge in an optimal configuration

![](F-1.png)

Maximum flow is $3$ with a cost of $0 \cdot 3 + 1 \cdot 1 + 4 \cdot 2 + 0 \cdot 1 + 0 \cdot 2 = 9$

In the **fourth query**, the flow network looks as –
![](F-2.png)

The minimum cost maximum flow is achieved in the configuration –
![](F-3.png)

The maximum flow in the above network is 4 and the minimum cost of such flow is 15

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>
