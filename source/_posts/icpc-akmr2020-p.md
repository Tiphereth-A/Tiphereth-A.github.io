---
title: 题解 - 2020 ICPC 亚洲区域赛(昆明) 热身赛
categories:
  - 算法竞赛
  - 题解
  - ICPC
tags:
  - 算法竞赛
  - 题解
  - ICPC
  - 排序
  - 贪心
  - DP
  - 滚动数组
date: 2021-04-04 00:04:28
---

[比赛链接](https://ac.nowcoder.com/acm/contest/12548)

<!-- more -->

## 题目概览

| 题号 | 标题       | 做法 |
| ---- | ---------- | ---- |
| A    | Meditation | 排序 |
| B    | Rounds     | 贪心 |
| C    | Statues    | DP   |

## A - Meditation

1000ms / 256 MB

### 题目描述

![](A-1.png)

Luna had a stressful day and she wants to do a meditation routine that relaxes her well. Luna's routines are more or less relaxing and to determine how relaxing a routine is, Luna computes its score: the higher the score, the more relaxing it is!

Luna has graded each of the $n$ exercises with a positive integer and the score of a routine is simply the sum of the grades of its individual exercises. She gives you her list of graded exercises and asks you what is the maximal grade of a routine composed of $k$ different exercises

### 输入描述

The first line of the input contains two space-separated integers:$n$ and $k$
The $n$ following lines each contain a single integer, the $i+1$-th line containing the grade $g_i$ of the $i$-th exercise

### 输出描述

The output should contain a single line with a single integer: the maximal score of a routine composed of KKK different exercises

### 示例 1

#### 输入

```input1
5 3
10
22
7
3
10
```

#### 输出

```output1
42
```

#### 说明

We select the exercises 1, 2 and 5 which gives a total score of $10+22+10=42$

### 备注

$1\leq k \leq n \leq 100\,000$

$0\leq g_{i}\leq 10\,000$

### 题意简述

取前 $k$ 大个数求和

## B - Rounds

1000ms / 256 MB

### 题目描述

![](B-1.png)

The popular PefectSharp online group gathers fans of workouts and healthy lifestyle all over the world. Every group member has managed to gain a certain amount of credits for the trendy MV03 online sports platform, giving them access to various workout and relaxation resources

The amount of credits owned may however largely differ from one person to the other. Since PefectSharp members value sharing and solidarity, they decide to redispatch credits by playing the following game:

The $N$ group members are numbered from $1$ to $N$ and the game comprises $k$ rounds, for some integer $k$ such that $1 \leq k \leq N$. During the $i$-th round of the game, all members except member $i$ give $S$ credits to member $i$. The game may end after any round, and its outcome will be the minimum amount of credits held by a member of the group after that round

Your task is to figure out the maximum possible game outcome, across all possible game endings

### 输入描述

The first line of the input contains two integers $N$ and $S$.
Each of the $N$ following lines contains a single integer, the $i + 1$-th line containing the amount of credits Ciinitially owned by member $i$

### 输出描述

The output should contain a single integer value $C$ corresponding to the maximum possible game outcome

### 示例 1

#### 输入

```input1
3 10
24
42
38
```

#### 输出

```output1
28
```

#### 说明

The game proceeds as follows:

After round $1$ the amounts of credits held are $44, 32, 28$ and the minimum is $28$

After round $2$ the amounts of credits held are $34, 52, 18$ and the minimum is $18$

After round $3$ the amounts of credits held are $24, 42, 38$ and the minimum is $24$

The best possible outcome is therefore $28$, which corresponds to ending the game after round $1$

### 备注

$1\leq N \leq 100\,000$

$1\leq S \leq 100\,000\,000$

for all,$1\leq C_i \leq 100\,000\,000$ and $S \times (N-1) \leq C_i$

### 题意简述

有 $N$ 个人, 每人手里有一些积分, 在第 $i$ 回合时, 除了第 $i$ 个人, 每个人都要给第 $i$ 个人 $S$ 积分, 求每回合每个人积分最小值的最大值

### 解题思路

做过 [[NOIP2016 提高组] 蚯蚓](https://www.luogu.com.cn/problem/P2827) 的人应该立刻就能想到怎么贪心

每回合的操作等价于给第 $i$ 的人加 $NS$ 积分, 答案只会在初始值和间断点处取得

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:B misc/icpc-akmr2020-p/B/0.cpp %}

</details>

## C - Statues

1000ms / 256 MB

### 题目描述

![](C-1.jpg)

To escape the loneliness of working remotely everyday, Erika decided to try on a new hobby: sculpture. She already has a large collection of statues and the municipality has allowed her to show her art outside

Erika wants her statues to be well visible and thus each statue needs to be placed under a distinct street light. Further, the arrangement should be aesthetic which means that the statues should be placed by increasing size with the smallest statues near the beginning of the street and the biggest ones near the end

Erika placed her statues but she forgot to place them in increasing size and now she has to reposition them in accordance to both of her desires

The street has $N$ evenly spaced street lights numbered from $1$ at the beginning of the street to $N$ at the end of the street. You estimate the time required to move a statue of size $s$ from the street light $i$ to the light $j$ as taking Erika $s \times |i - j|$ units of time. You ask yourself, how much time does it take to reposition all statues knowing that she will use the fastest way possible? Note that she may put statues under street lights that do not have statues at the moment

### 输入描述

The first line of the input contains two space-separated integers: $N$ the number of street lights and $K$ the number of statues. The $K$ following lines each contains two space-separated integers, the $i + 1$-th line containing the integers $P_i$ and $S_i$ describing the $i$-th statue. $P_i$ gives the number of the street light under which the statue is and $S_i$ gives its size

### 输出描述

The output should contain a single line containing a single integer: the minimum amount of time needed to move statues such that each statue is under a different street light and such that the size of statues grows with the street light numbers under which they are

### 示例 1

#### 输入

```input1
3 3
1 3
2 2
3 1
```

#### 输出

```output1
8
```

#### 说明

Because there are as many street lights as there are statues we needto position the statue of size $1$ at street light $1$ (which takes $1\times |3-1|=2$ units of times), leave the statue of size $2$ at street light $2$, and move the statue of size $3$ to the street light $3$(which takes $3\times |1-3|=6$ units of times). In total this takes $8$ units of time

### 示例 2

#### 输入

```input1
4 3
2 2
3 2
4 1
```

#### 输出

```output1
3
```

#### 说明

The fastest way of fixing the ordering of statues is to move the statue of size 1 to the street light 1 for a total time of $1\times|4-1|=3$

### 备注

$1 \leq K \leq N \leq 5\,000$

for all $1 \leq i\leq K,1\leq S_{i}\leq 1\,000\,000,1\leq P_i \leq N$

### 解题思路

> 交第一发时
>
> 评测机: MLE
>
> 我: $5000^2\times2=5\times10^6$
>
> 队友 A: 应该是 T 了
>
> 队友 B: 应该是数组越界了

显然 $O(n^2)$ DP

如果 DP 数组元素的数据类型大小在 $32$ 位以上时会 MLE, 所以需要滚动数组

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:C misc/icpc-akmr2020-p/C/0.cpp %}

</details>
