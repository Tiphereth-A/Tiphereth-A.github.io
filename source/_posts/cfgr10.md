---
title: "题解 - [Codeforces Global Round 10](A - D & F)"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - CodeForces
  - 数学
  - 贪心
  - 模拟
date: 2020-08-18 14:51:12
---

[比赛链接](https://codeforces.com/contest/1392)

贪心 + 数学赛, 海星

<!-- more -->

## 题目概览

| 题目 | 知识点     |
| ---- | ---------- |
| A    | 贪心, 数学 |
| B    | 数学, 模拟 |
| C    | 贪心, 模拟 |
| D    | 贪心       |
| F    | 贪心, 数学 |

## A - Omkar and Password

Lord Omkar has permitted you to enter the Holy Church of Omkar! To test your worthiness, Omkar gives you a password which you must interpret!

A password is an array $a$ of $n$ positive integers. You apply the following operation to the array: pick any two adjacent numbers that are not equal to each other and replace them with their sum. Formally, choose an index $i$ such that $1≤i<n$ and $a_i≠a_i+1$, delete both $a_i$ and $a_i+1$ from the array and put $a_i+a_i+1$ in their place

For example, for array $[7,4,3,7]$ you can choose $i=2$ and the array will become $[7,4+3,7]=[7,7,7]$. Note that in this array you can't apply this operation anymore

Notice that one operation will decrease the size of the password by $1$. What is the shortest possible length of the password after some number (possibly $0$) of operations?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$($1≤t≤100$). Description of the test cases follows

The first line of each test case contains an integer $n$($1≤n≤2⋅10^5$) - the length of the password

The second line of each test case contains $n$ integers $a_1,a_2,…,a_n$ ($1≤a_i≤10^9$) - the initial contents of your password

The sum of $n$ over all test cases will not exceed $2⋅10^5$

### Output

For each password, print one integer: the shortest possible length of the password after some number of operations

### Example

#### Input

```input1
2
4
2 1 3 1
2
420 420
```

#### Output

```output1
1
2
```

### Note

In the first test case, you can do the following to achieve a length of $1$:

Pick $i=2$ to get $[2,4,1]$

Pick $i=1$ to get $[6,1]$

Pick $i=1$ to get $[7]$

In the second test case, you can't perform any operations because there is no valid $i$ that satisfies the requirements mentioned above

### 题意简述

给出一组正整数 $a$, 你可以选取其中相邻的两个不同的数, 并将靠左边的数替换为这两个数的和, 同时删除靠右边的数, 问对该组数 $a$ 持续进行该操作直到无法继续之后, 得到数组的最小长度

### 解题思路

如果这组数全部相等, 此时一定无法进行操作, 答案即为这组数的长度

否则, 这组数中一定存在最大值, 且一定存在一组相邻且不相等的数, 其中一个为最大值

对这两个数进行一次操作后, 我们得到的新数组中便存在唯一的最大值, 此时对它和与它相邻的数不断重复操作, 则最大值会越来越大, 且最后只剩下一个数

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1392A CodeForces/1392A/0.cpp %}

</details>

## B - Omkar and Infinity Clock

Being stuck at home, Ray became extremely bored. To pass time, he asks Lord Omkar to use his time bending power: Infinity Clock! However, Lord Omkar will only listen to mortals who can solve the following problem:

You are given an array $a$ of $n$ integers. You are also given an integer $k$. Lord Omkar wants you to do $k$ operations with this array

Define one operation as the following:

1. Set $d$ to be the maximum value of your array
1. For every $i$ from $1$ to $n$, replace $a_i$ with $d-a_i$

The goal is to predict the contents in the array after $k$

operations. Please help Ray determine what the final sequence will look like!

### Input

Each test contains multiple test cases. The first line contains the number of cases $t$($1≤t≤100$). Description of the test cases follows

The first line of each test case contains two integers $n$
and $k$ ($1≤n≤2⋅10^5,1≤k≤10^{18}$) – the length of your array and the number of operations to perform

The second line of each test case contains $n$ integers $a_1,a_2,...,a_n$ ($-10^9≤a_i≤10^9$) – the initial contents of your array

It is guaranteed that the sum of $n$ over all test cases does not exceed $2⋅10^5$

### Output

For each case, print the final version of array $a$
after $k$ operations described above

### Example

#### Input

```input1
3
2 1
-199 192
5 19
5 -1 4 2 0
1 2
69
```

#### Output

```output1
391 0
0 6 1 3 5
0
```

### Note

In the first test case the array changes as follows:

- Initially, the array is [-199,192]. $d=192$
- After the operation, the array becomes $[d-(-199),d-192]=[391,0]$

### 题意简述

给出一组整数 $a$, 定义操作如下:

- 设 $a$ 中的最大值为 $d$, 将 $a$ 中所有元素 $a_i$ 替换为 $d-a_i$

问经过 $k$ 次操作之后的数组 $a$ 是什么样的

### 解题思路

看到 $k$ 的范围就知道这个变换肯定有循环节

我们可以这样做

- 如果 $a$ 中全为非负数, 我们不难发现其循环节长度就是 $2$
- 如果 $a$ 中存在负数, 则经过一次变换后就会变为非负数

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1392B CodeForces/1392B/0.cpp %}

</details>

## C - Omkar and Waterslide

Omkar is building a waterslide in his water park, and he needs your help to ensure that he does it as efficiently as possible

Omkar currently has $n$ supports arranged in a line, the $i$-th of which has height $a_i$. Omkar wants to build his waterslide from the right to the left, so his supports must be nondecreasing in height in order to support the waterslide. In $1$ operation, Omkar can do the following: take any **contiguous subsegment** of supports which is **nondecreasing by heights** and add $1$ to each of their heights

Help Omkar find the minimum number of operations he needs to perform to make his supports able to support his waterslide!

An array $b$ is a subsegment of an array $c$ if $b$ can be obtained from $c$ by deletion of several (possibly zero or all) elements from the beginning and several (possibly zero or all) elements from the end

An array $b_1,b_2,…,b_n$ is called nondecreasing if $b_i≤b_{i+1}$ for every $i$ from $1$ to $n-1$

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$
($1≤t≤100$). Description of the test cases follows

The first line of each test case contains an integer $n$
($1≤n≤2⋅10^5$) - the number of supports Omkar has

The second line of each test case contains $n$
integers $a_1,a_2,...,a_n$ ($0≤ai≤10^9$) - the heights of the supports

It is guaranteed that the sum of $n$ over all test cases does not exceed $2⋅10^5$

### Output

For each test case, output a single integer - the minimum number of operations Omkar needs to perform to make his supports able to support his waterslide

### Example

#### Input

```input1
3
4
5 3 2 5
5
1 2 3 5 3
3
1 1 1
```

#### Output

```output1
3
2
0
```

### Note

The subarray with which Omkar performs the operation is bolded

In the first test case:

- First operation:

  $[5,3,\bold{2},5]→[5,3,\bold{3},5]$

- Second operation:

  $[5,\bold{3,3},5]→[5,\bold{4,4},5]$

- Third operation:

  $[5,\bold{4,4},5]→[5,\bold{5,5},5]$

In the third test case, the array is already nondecreasing, so Omkar does $0$ operations

### 题意简述

给出一组非负整数 $a$, 给出一组数 $a$, 定义操作如下:

- 选择其中任何一段不下降子区间并将其上所有数 $+1$

我们可以使用最少的操作来将该数列变为不下降的数列, 输出这个不下降的数列

### 解题思路

~~第一眼看这题目, 这不就是积木大赛吗~~

这题的贪心策略和积木大赛很像

- 当 $a$ 是整体是非下降的时候

  直接输出

- 当 $a$ 是整体是非上升的时候, 如

  ![](C-sol-1.png)

  直接填平就好

- 其他情况, 如
  ![](C-sol-2.png)

  我们可以按如下步骤化为上一种情况

  1. 填平  
     ![](C-sol-3.png)
     得
     ![](C-sol-4.png)
  1. 填平  
     ![](C-sol-5.png)
     得
     ![](C-sol-6.png)

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1392C CodeForces/1392C/0.cpp %}

</details>

## D - Omkar and Bed Wars

Omkar is playing his favorite pixelated video game, Bed Wars! In Bed Wars, there are $n$ players arranged in a circle, so that for all $j$ such that $2≤j≤n$, player $j-1$ is to the left of the player $j$, and player $j$ is to the right of player $j-1$. Additionally, player $n$ is to the left of player 1, and player $1$ is to the right of player $n$

Currently, each player is attacking either the player to their left or the player to their right. This means that each player is currently being attacked by either $0$, $1$, or $2$ other players. A key element of Bed Wars strategy is that if a player is being attacked by exactly $1$ other player, then they should logically attack that player in response. If instead a player is being attacked by $0$ or $2$ other players, then Bed Wars strategy says that the player can logically attack either of the adjacent players

Unfortunately, it might be that some players in this game are not following Bed Wars strategy correctly. Omkar is aware of whom each player is currently attacking, and he can talk to any amount of the $n$

players in the game to make them instead attack another player - i. e. if they are currently attacking the player to their left, Omkar can convince them to instead attack the player to their right; if they are currently attacking the player to their right, Omkar can convince them to instead attack the player to their left

Omkar would like all players to be acting logically. Calculate the minimum amount of players that Omkar needs to talk to so that after all players he talked to (if any) have changed which player they are attacking, all players are acting logically according to Bed Wars strategy

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$($1≤t≤104$). The descriptions of the test cases follows

The first line of each test case contains one integer $n$($3≤n≤2⋅10^5$) - the amount of players (and therefore beds) in this game of Bed Wars

The second line of each test case contains a string $s$
of length $n$. The $j$-th character of $s$ is equal to `L` if the $j$-th player is attacking the player to their left, and `R` if the $j$-th player is attacking the player to their right

It is guaranteed that the sum of $n$ over all test cases does not exceed $2⋅10^5$

### Output

For each test case, output one integer: the minimum number of players Omkar needs to talk to to make it so that all players are acting logically according to Bed Wars strategy

It can be proven that it is always possible for Omkar to achieve this under the given constraints

### Example

#### Input

```input1
5
4
RLRL
6
LRRRRL
8
RLLRRRLL
12
LLLLRRLRRRLL
5
RRRRR
```

#### Output

```output1
0
1
1
3
2
```

### Note

In the first test case, players $1$ and $2$ are attacking each other, and players $3$ and $4$ are attacking each other. Each player is being attacked by exactly $1$ other player, and each player is attacking the player that is attacking them, so all players are already being logical according to Bed Wars strategy and Omkar does not need to talk to any of them, making the answer $0$

In the second test case, not every player acts logically: for example, player $3$ is attacked only by player $2$, but doesn't attack him in response. Omkar can talk to player $3$ to convert the attack arrangement to `LRLRRL`, in which you can see that all players are being logical according to Bed Wars strategy, making the answer $1$

### 题意简述

$n$ 个人站成一圈, 编号 $0,1,2,...,n-1$, 第 $(i+1)\bmod n$ 个人在第 $i$ 个人右边, 他们会攻击某个相邻的人, 定义操作如下:

- 选择一个人, 调转其攻击方向

经过若干次操作后, 这 $n$ 个人满足

- 如果他被 $1$ 个人攻击, 则他会攻击攻击他的人
- 如果他被 $0$ 个或 $2$ 个人攻击, 则他可以攻击任意相邻的人

给出这 $n$ 个人的初始攻击方向, 问最小操作数

### 解题思路

当我看到这题的 tag 有 dp 和 string suffix structures 时我是震惊的

其实我们只需让环中没有 $3$ 个连续的`L`或`R`即可

我们这样操作

- 若存在 $4$ 个及以上连续的的`L`或`R`, 将第 $3$ 个人的方向调转
- 若存在 $3$ 个连续的的`L`或`R`, 将第 $2$ 个人的方向调转

容易证明这样操作即是最优操作

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1392D CodeForces/1392D/0.cpp %}

</details>

## F - Omkar and Landslide

Omkar is standing at the foot of Celeste mountain. The summit is $n$ meters away from him, and he can see all of the mountains up to the summit, so for all $1≤j≤n$ he knows that the height of the mountain at the point $j$ meters away from himself is $h_j$ meters. It turns out that for all $j$ satisfying $1≤j≤n-1, h_j<h_{j+1}$(meaning that heights are strictly increasing)

Suddenly, a landslide occurs! While the landslide is occurring, the following occurs: every minute, if $h_j+2≤h_{j+1}$
, then one square meter of dirt will slide from position $j+1$ to position $j$, so that $h_{j+1}$ is decreased by $1$ and $h_j$ is increased by $1$. These changes occur simultaneously, so for example, if $h_j+2≤h_{j+1}$ and $h_{j+1}+2≤h_j+2$ for some $j$, then $h_j$ will be increased by $1$, $h_j+2$ will be decreased by $1$, and $h_{j+1}$ will be both increased and decreased by $1$, meaning that in effect $h_{j+1}$ is unchanged during that minute

The landslide ends when there is no $j$ such that $h_j+2≤h_{j+1}$. Help Omkar figure out what the values of $h_1,…,h_n$

will be after the landslide ends. It can be proven that under the given constraints, the landslide will always end in finitely many minutes

Note that because of the large amount of input, it is recommended that your code uses fast IO

### Input

The first line contains a single integer $n$
($1≤n≤10^6$)

The second line contains $n$ integers $h_1,h_2,…,h_n$ satisfying $0≤h_1<h_2<⋯<h_n≤10^{12}$ - the heights

### Output

Output $n$ integers, where the $j$-th integer is the value of $h_j$ after the landslide has stopped

### Example

#### Input

```input1
4
2 6 7 8
```

#### Output

```output1
5 5 6 7
```

### Note

Initially, the mountain has heights $2,6,7,8$

In the first minute, we have $2+2≤6$, so $2$ increases to $3$ and $6$ decreases to $5$, leaving $3,5,7,8$

In the second minute, we have $3+2≤5$
and $5+2≤7$, so $3$ increases to $4$, $5$ is unchanged, and $7$ decreases to $6$, leaving $4,5,6,8$

In the third minute, we have $6+2≤8$, so $6$ increases to $7$ and $8$ decreases to $7$, leaving $4,5,7,7$

In the fourth minute, we have $5+2≤7$, so $5$ increases to $6$ and $7$ decreases to $6$, leaving $4,6,6,7$

In the fifth minute, we have $4+2≤6$, so $4$ increases to $5$ and $6$ decreases to $5$, leaving $5,5,6,7$

In the sixth minute, nothing else can change so the landslide stops and our answer is $5,5,6,7$

### 题意简述

给出一组严格递增的数 $a$, 如果 $a_i+2\leqslant a_{i+1}$, 则将 $a_{i+1}$ 减 $1$, $a_i$ 加 $1$, 输出不能进行上述操作后的 $a$

### 解题思路

> 比赛花 1h 写了堆 shit 还 wa 了, 菜 我 菜

设 $S=\sum_{i=1}^n a_i$, 我们可以证明:

- 最后结果只与 $S$ 和 $n$ 有关, 或者说, 对于相同的 $S$ 和 $n$, 最后结果是相同的
- 最后结果只有一对相邻数的值相等, 其余均满足: 后一项=前一项 $+1$

要注意这些性质**不具有平凡性**, 正是由于初始的 $a$ 严格递增, 才有了这些性质

由这些, 我们便可以这样生成结果:

- 首先令 $a_i=i$, 这样还有 $S-\frac{n(n+1)}{2}$ 个数没有分配
- 接着把每个 $a_i$ 都加上 $\lfloor{S-\frac{n(n+1)}{2}\over n}\rfloor$, 这样还有 $(S-\frac{n(n+1)}{2})\bmod n$ 个数没有分配
- 最后便把这 $(S-\frac{n(n+1)}{2})\bmod n$ 个数分配给 $a_1,...,a_{(S-\frac{n(n+1)}{2})\bmod n}$

写在一起就是

$$a_i=i+\left\lfloor{S-\frac{n(n+1)}{2}\over n}\right\rfloor+\left[i\leqslant\left(S-\frac{n(n+1)}{2}\right)\bmod n\right],~i=1,2,...,n$$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1392F CodeForces/1392F/0.cpp %}

</details>
