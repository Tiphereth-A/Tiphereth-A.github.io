---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 8)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - Codeforces
date: 2022-04-16 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.04.16-2022.04.22)

<!-- more -->

## Rad

[题目链接](https://oj.daimayuan.top/problem/744)

3 s, 1024 MB

### 题目描述

定义

$$
rad(n)=\prod_{\begin{matrix} p|n\\ p\in Prime \end{matrix}}p
$$

给定整数 $n$, 若存在两个正整数 $a$,$b$,满足 $a+b=n$,同时 rad($a\times b \times n$)< $n$,输出 YES, 否则输出 NO

### 输入格式

第一行一个数字 $T$

接下来 $T$ 行每行输入 $1$ 个整数 $n$

### 输出格式

每行输出 YES 或 NO

### 样例输入

```input1
3
4
18
30
```

### 样例输出

```output1
YES
YES
NO
```

### 数据规模

所有数据保证 $1\le T \le 10,1\le n \le 1e18$

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 吃蛋糕

[题目链接](https://oj.daimayuan.top/problem/675)

1 s, 1024 MB

### 题目描述

有 $n$ 个盘子, 分别是 $1,2,...,n$, 第 $i$ 个盘子里面装了 $a_i(1 \le a_i \le 3)$ 个蛋糕, 小 $N$ 会每次按照下面的方式吃蛋糕, 直到蛋糕吃完

每次等概率的从 $n$ 个盘子中挑选一个, 假设选中了第 $i$ 个盘子, 如果第 $i$ 个盘子里面有蛋糕, 那么小 $N$ 会吃掉一个, 如果第 $i$ 个盘子里面没有蛋糕, 小 $N$ 什么也不做

请你求出吃掉所有的蛋糕的期望次数

### 输入格式

第一行一个数字 $n$

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$

### 输出格式

输出吃掉所有的蛋糕的期望次数, 误差小于等于 $10^{-9}$ 被视为正确

### 样例输入

```input1
2
1 2
```

### 样例输出

```output1
4.5
```

### 数据规模

所有数据保证 $1\leq n\leq 300, 1 \leq a_i \leq 3$

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 排列

[题目链接](https://oj.daimayuan.top/problem/746)

1 s, 1024 MB

### 题目描述

有 $N$ 个骑士, 他们的初始攻击力分别为 $a_1, a_2, ... , a_n$. 并且每个骑士都有一个增益能力 $b_i$

对于每个骑士, 他都会选择一名其他骑士(不包含自己), 使被选择骑士的攻击力增加 $b_i$

判断是否有一种骑士的排列, 不管骑士如何选择增益的对象, 都满足骑士的攻击力从左到右是不增的

### 输入格式

第一行一个正整数 $T$, 表示数据组数

对于每组数据 第一行一个正整数 $N$, 表示骑士的个数

接下来 $N$ 行, 每行两个整数. 第 $i$ 行表示 $a_i$ 和 $b_i$. 即骑士 $i$ 的初始攻击力和增益能力

### 输出格式

对于每组数据, 如果能存在一种排列骑士的方案满足要求, 就输出 Yes

否则 输出 No

### 数据范围

对于所有数据, 满足 $1 \leq T \leq 1000$, $2 \leq N \leq 100$, $0 \leq a_i, b_i \leq 10^6$

### 样例输入

```input1
3
2
15 25
10 5
3
7 0
7 3
10 0
3
10 10
20 20
30 30
```

### 样例输出

```output1
Yes
Yes
No
```

### 样例解释

对于第一组数据, 由于 $N = 2$, 所以骑士的攻击力最后一定有 $35, 20$. 显然存在方案

对于第二组数据, 我们可以构造骑士排列为 $10, 7, 7$ 其中增益能力为 $3$ 的骑士放在最后一个. 这样一来无论增益能力为 $3$ 的骑士如何选择, 都满足要求

对于第三组数据, 我们可以证明没有满足要求的方案, 于是输出 No

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 石子游戏 II

[题目链接](https://oj.daimayuan.top/problem/738)

1 s, 64 MB

### 题目描述

Alice 和 Bob 正在玩一个关于石子的游戏

共有 $n$ 堆石子, 其中第 $i$ 堆最初含有 $a_i$ 个石子

他们轮流执行下列操作之一, 从 Alice 开始

- 把一堆个数为奇数的石子分成两堆, 两堆都不能空
- 把两堆个数为偶数的石子合成一堆

不能执行任何操作的人将输掉游戏

假设 Alice 和 Bob 都足够聪明, 你知道谁会赢得游戏吗?

### 输入格式

第一行包含一个整数 $n$ ($1\leq n \leq 10^6$)

第二行包含 $n$ 个正整数 $a_1,\dots,a_n$ ($1\leq a_1,\dots,a_n \leq 10^9$)

### 输出格式

Alice 或 Bob, 表示最终赢家

### 样例输入

```input1
2
2 2
```

### 样例输出

```output1
Alice
```

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## Cow and Snacks (CF1209D)

[题目链接](https://oj.daimayuan.top/problem/807)

1 s, 128 MB

### 题目描述

农场正在举办一场派对!

有编号从 $1$ 开始的 $n$ 种小吃, 每种小吃只有一份. 有 $m$ 个客人会来, 每个客人有两种最喜欢的口味

农场主可以以某种方式让客人排队依次前来

每个客人来到农场时, 会把他喜欢的口味的小吃全部吃掉, 如果没有他喜欢的口味, 那么他就会伤心地离开

请问令客人如何排队, 能使伤心的客人最少? 输出最少的伤心的客人的数量

### 输入格式

第一行输入两个整数 $n, m$ $(2 \leq n \leq 10^5, 1 \leq m \leq 10^5)$ , 分别为小吃的数量和客人的数量

接下来 $m$ 行, 每行输入两个整数 $x_i, y_i$ $(1 \leq x_i, y_i \leq n, x_i \neq y_i)$ , 为编号为 $i$ 的客人喜欢的两种小吃的编号

### 输出格式

输出一个整数, 为最少的伤心的客人的数量

### 输入样例

```input1
5 4
1 2
4 3
1 4
3 4
```

### 输出样例 1

```output1
1
```

### 输入样例 2

```input2
6 5
2 3
2 1
3 4
6 5
4 5
```

### 输出样例 2

```output2
0
```

### 样例解释

在第 $1$ 组样例中, 可以让客人按照 $3, 1, 2, 4$ 的顺序排队, 3 号客人会吃掉小吃 1 和小吃 4, 然后 1 号客人会吃掉小吃 2, 2 号客人吃掉小吃 3, 4 号客人吃不到喜欢的小吃伤心的离开了, 所以答案为 1

在第 $2$ 组样例中, 可以按照 $2, 1, 3, 5, 4$ 的顺序排队, 没有客人会伤心

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 合法括号串

[题目链接](https://oj.daimayuan.top/problem/813)

1 s, 1024 MB

### 题目描述

给定一个长度为 $n$ 的括号串 $S$ , 有 $m$ 次询问 , 每次询问区间 $[l,r]$ 中的最长子序列长度, 满足是合法括号串

括号串为只由 $($ 和 $)$ 组成的字符串

合法括号串的定义如下:

- 空串是合法括号串
- 如果 $S$ 是合法括号串 , 那么 $(S)$ 是合法括号串
- 如果 $S$ , $T$ 是合法括号串 , 那么 $ST$ 是合法括号串

### 输入格式

第一行两个整数 $n,m$ , 含义如题面所示. $(1 \leq n , m \leq 10^5)$

第二行一个字符串 $S$ , 保证 $S$ 中只包含 $($ 和 $)$

接下来 $m$ 行 , 每行两个整数 $l,r$ , 含义如题面所示. $(1 \leq l \leq r \leq n)$

### 输出格式

输出共 $m$ 行 , 第 $i$ 行表示第 $i$ 次询问的答案

### 样例输入

```input1
10 5
))()()()))
6 10
7 8
7 7
7 8
4 9
```

### 样例输出

```output1
2
2
0
2
4
```

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 矩阵操作

[题目链接](https://oj.daimayuan.top/problem/804)

2 s, 1024 MB

### 题目描述

有一个 $n \times m$ 的整数矩阵 A, 其中每个数字范围都在 $[0, k)$

对于一次操作, 你可以执行下列两种操作中的一种

1. 对于任意一行 $i$, 你可以把第 $i$ 行中的所有数 $A_{i, t}$ 变为 $(A_{i, t}+1) \ mod \ k$
1. 对于任意一列 $j$, 你可以把第 $j$ 列中的所有数 $A_{t, j}$ 变为 $(A_{t, j}+1) \ mod \ k$

给定 $n, m, k, A$

是否能通过若干次上面的操作, 将 A 变为全 0 矩阵, 如果可以, 输出最小操作数, 否则, 输出-1

### 输入描述

一行三个整数 $1\leq n\leq 2000, 1\leq m \leq 2000, 1\leq k\leq 10^9$

接下来 $n$ 行每行 $m$ 个数, 表示矩阵 A 的初始状态

### 输出描述

一行, 如果可以输出操作数, 否则输出-1

### input1

```input1
3 3 10
0 0 9
0 0 9
9 9 8
```

### output1

```output1
2
```

### input2

```input2
3 3 10
1 0 9
0 0 9
9 9 8
```

### output2

```output2
-1
```

### 原题链接

[戳我](https://ac.nowcoder.com/acm/contest/30896/C)

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>
