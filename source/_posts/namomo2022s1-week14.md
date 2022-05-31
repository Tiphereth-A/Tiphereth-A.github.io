---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 14)
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 代码源
  - CodeForces
  - 数学
  - 组合数学
  - 分块
  - 三分
  - 字符串
  - DP
  - Hash
  - KMP
  - Z算法
  - Young表
  - 二分图染色
date: 2022-05-28 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.05.28-2022.06.03)

<!-- more -->

## 序列中 ab 的个数 (CF1268B)

[题目链接](https://oj.daimayuan.top/problem/964)

3 s, 1024 MB

### 题目描述

给一个图表, 图表是一个直方图, $n$列的高度分别为$a_1, a_2, \dots, a_n$$(a_1 \ge a_2 \ge a_3 .... \ge a_n)$, 你有许多大小为 $1 \times 2$ 的多米诺骨牌(可以旋转), 不重叠最多可以放置多少个呢

### 输入格式

第一行一个数字 $n$

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$

### 输出格式

一个数, 表示答案

### 样例输入

```input1
5
3 2 2 2 1
```

### 样例输出

```output1
4
```

### 数据规模

所有数据保证 $1\leq n\leq 300000, 1 \leq a_i \leq 300000$

### 解题思路

> 二分图染色

结论题, 如果 Young 表二分图染色后黑白两色的格子数相等, 则可以用骨牌密铺

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1268B CodeForces/1268B/0.cpp %}

</details>

## 单词合并 (CF1200E)

[题目链接](https://oj.daimayuan.top/problem/958)

2 s, 256 MB

### 题目描述

$xyq$ 有 $n$ 个单词, 他想把这个 $n$ 个单词变成一个句子

具体来说就是从左到右依次把两个单词合并成一个单词

合并两个单词的时候, 要找到最大的$i(i\ge0)$, 满足第一个单词的长度为$i$ 的后缀和第二个单词长度为$i$ 的前缀相等, 然后把第二个单词第$i$ 位以后的部分接到第一个单词后面

请你输出最后合并后的单词

### 输入描述

第一行一个整数 $n(n\leq 10^5)$ 表示单词的个数

接下来一行 $n$ 个字符串 $s$, 字符串之间用空格分割, 分别代表每个单词. 保证字符串总长不超过$10^6$

### 输出描述

一行一个字符串表示合并后的答案

### 输入样例

```input1
5
sample please ease in out
```

### 输出样例

```output1
sampleaseinout
```

### 解题思路

> Z 算法 / Hash

板子题, 把合并的字符串和当前输入的字符串拼起来跑个 KMP 即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1200E CodeForces/1200E/0.cpp %}

</details>

## 不降子数组游戏 (CodeForces Gym 102984D)

[题目链接](https://oj.daimayuan.top/problem/886)

3 s, 1024 MB

### 题目描述

Yuto 和 Platina 准备玩一个不降子数组游戏

具体的, 给定一个长度为$N$的数组$A$, 和区间限制$L$和$R$

Yuto 首先在$[L, R]$中选择一个数字, 并展示给 Platina 看

随后 Platina 也会选择一个在$[L, R]$中的数字

我们不妨设 Yuto 选择了数字$a$, Platina 选择了数字$b$

这局游戏的得分是$A[min(a,b):max(a,b)]$的不降子数组的个数. ($A[l:r]$表示由数组$A$下标从$l$到$r$这一连续段构成的新数组)

注: 数组$B$的子数组是从$B$的头尾连续删除若干(可以为空)个元素后得到的新数组

Yuto 想要得分尽可能的小, Platina 想要得分尽可能的大

他们将会在一个数组上游戏$Q$次, 对于每次游戏, 请输出最后游戏的得分

### 输入格式

第一行输入一个正整数$N$, 表示数组$A$的长度

接下来一行$N$个正整数, 分别表示$A_1$, $A_2$, ... , $A_N$

第三行输入一个正整数$Q$, 表示游戏进行的次数

接下来$Q$行, 每一行输入两个正整数, 分别表示$L$和$R$

对于所有数据, 满足$1 \leq N, Q \leq 5 \times 10^5$, $1 \leq A_i \leq 10^9$ 且 $1 \leq L \leq R \leq N$

### 输出格式

对于每次游戏, 输出一个正整数, 表示游戏最后的得分

### 样例输入

```input1
8
7 10 3 1 9 5 5 2
5
1 5
2 2
5 8
1 8
3 5
```

### 样例输出

```output1
4
1
4
7
3
```

### 解题思路

> 三分 + 分块

首先将数组分成递增的若干段, 如对于样例分为 `[7 10] [3] [1 9] [5 5] [2]` 五段, 然后每一段都可以很容易地求出得分, 进而用一个前缀和即可方便地求出某一段区间的得分

对于单次查询, 显然无论先手选什么, 后手必选端点, 而且不难发现得分对先手选的点是单峰函数, 所以直接三分即可

### 复杂度

$O(N+Q\log N)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_Gym_102984D CodeForces/102984D/0.cpp %}

</details>

## 子串（数据加强版）([牛客练习赛 98 D](https://ac.nowcoder.com/acm/contest/11188/D))

[题目链接](https://oj.daimayuan.top/problem/922)

1 s, 1024 MB

### 题目描述

给定一个长度为 $n$ 的 $01$ 串, 问有多少种划分, 使得每一个划分出来的子串的 $1$ 的个数组成的序列是回文的, 答案对 $998244353$ 取模

### 输入格式

第一行一个正整数 $n$, 表示 $01$ 串的长度

第二行为一个长度为 $n$ 的 $01$ 串

### 输出格式

合法的划分方案数对 $998244353$ 取模的值

### 样例输入

```input1
3
101
```

### 样例输出

```output1
4
```

### 样例解释

合法的划分方案为：$[101],[10,1],[1,01],[1,0,1]$, 其中 $1$ 的个数组成的序列为 $[2],[1,1],[1,1],[1,0,1]$, 这些序列都是回文的

### 数据规模

$1\leq n\leq 2500$

### 解题思路

> 组合数学

似乎加强版是想让大家写 $O(n^2)$ DP, 然而这题有线性做法

我们从两边向内找一对 $1$ 所在的位置, 设这两个 $1$ 外侧的若干的 $0$ 分别有 $x,y$ 个, 那么一对 $1$ 和这些 $0$ 对答案产生的贡献为

$$\sum_{k=0}^{\min\{x,y\}}\binom{x}{k}\binom{y}{k}$$

然后把这些 $0$ 和 $1$ 删去, 继续直到找不到两个 $1$ 为止, 此时有两种情况:

- 只剩 $1$ 个 $1$

  ![](1403-2.svg)

  设这个 $1$ 左右的 $0$ 分别有 $x,y$ 个, 不难发现这些 $0$ 对答案产生的贡献为
  $$\sum_{k=0}^{\min\{x,y\}}\binom{x}{k}\binom{y}{k}$$

- 没有 $1$

  ![](1403-3.svg)

  设这些 $0$ 有$x$个, 不难发现这些 $0$ 对答案产生的贡献为 $2^x$

例如, 下图的答案为

$$\left(\sum_{k=0}^{\min\{2,4\}}\binom{x}{k}\binom{y}{k}\right)\left(\sum_{k=0}^{\min\{2,1\}}\binom{x}{k}\binom{y}{k}\right)2^2=1200$$

![](1403-1.svg)

### 复杂度

$O(n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Daimayuan_922 Daimayuan/922/1.cpp %}

</details>
