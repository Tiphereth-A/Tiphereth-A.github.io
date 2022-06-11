---
title: 题解 - ICPC North Central NA Regional Contest 2019
categories:
  - 程序设计
  - 题解
  - ICPC
tags:
  - 程序设计
  - 题解
  - ICPC
  - Kattis
  - 贪心
  - 搜索
  - 数学
  - 构造
  - 计算几何
  - 图论
  - 计数
  - 最小圆覆盖
  - 组合数学
  - 前缀和
  - 最短路
  - 网络流
  - 最小费用流
  - DFS
date: 2021-03-07 18:11:53
---

比赛链接:

- [Kattis](https://ncna19.kattis.com/problems)
- [牛客](https://ac.nowcoder.com/acm/contest/12606)

<!-- more -->

<style>
.illustration {
  float: right;
  padding-left: 20px;
}
.description {
  color: #898992;
  font-style: italic;
  font-family: "Merriweather", serif;
  font-size: 12px;
  text-align: right;
  margin-top: 5px;
}
.figure {
  display: block;
  float: none;
  margin-left: auto;
  margin-right: auto;
  font-family: "Merriweather", serif;
  font-size: 14px;
  line-height: 24px;
  margin-bottom: 20px;
}
.figure.caption {
  margin-top: 15px;
}
</style>

## 题目概览

| 题目 | 难度[^1] | 知识点       |
| ---- | -------- | ------------ |
| A    | 6.6      | 最小圆覆盖   |
| B    | 6.5      | 网络流       |
| C    | 5.7      | DFS          |
| D    | 1.7      | 数学         |
| E    | 8.1      | 贪心         |
| F    | 5.5      | 前缀和       |
| G    | 4.9      | 组合数学     |
| H    | 5.2      | 贪心, 最短路 |
| I    | 6.5      | 构造, DFS    |
| J    | 1.7      | 模拟         |
| K    | 7.5      | ~~乱搞~~     |

> u1s1, 我觉得这个难度值略奇怪, 一道很简单的贪心, 难度居然比网络流高 1.6, 比最小圆覆盖高 1.5

---

> 2022.02.23 UPD: 这难度值应该没问题, 刚又做了 E, 发现这个思路并不是特别好想

## 其他题解

### 官方版

{% pdf /archives/icpc-ncna2019/NCNA19slides.pdf 600px %}

### 兰州大学版

{% pdf /archives/icpc-ncna2019/solutions-lzu.pdf 600px %}

## A - Weird Flecks, But OK

### 原始题面

<div style="width:25.00%" class="illustration">
  <img src="A-1.png" alt="">
</div>

An artist who wanted to create an installation where his works appeared to be floating in midair has cast a large cube of clear acrylic to serve as a base. Unfortunately, during the casting, some small flecks of dirt got into the mix, and now appear as a cluster of pinpoint flaws in the otherwise clear cube

He wants to drill out the portion of the cube containing the flaws so that he can plug the removed volume with new, clear acrylic. He would prefer to do this in one drilling step. For stability's sake, the drill must enter the cube only once, perpendicular to one of its faces. The cube's faces are parallel to the coordinate axes

Given the $(x,y,z)$ positions of the flaws, and treating the size of the flaws as negligible, what is the smallest diameter drill bit that can be used to remove the flaws in one operation??

#### Input

The first line of input contains an integer $N$ denoting the number of flaws. $3≤N≤5000$

This is followed by $N$ lines of input, each containing three real numbers in the range $-1000.0…1000.0$, denoting the $(x,y,z)$ coordinates of a single flaw. Each number contains at most $6$ digits following a decimal point. The decimal point may be omitted if all succeeding digits are zero

#### Output

Print the diameter of the smallest drill bit that would remove all the flaws

The answer is considered correct if the absolute or relative error is less than $10^{-4}$

#### Sample Input 1

```input1
3
1.0 0.0 1.4
-1.0 0.0 -1.4
0.0 1.0 -0.2
```

#### Sample Output 1

```output1
2.0000000000
```

#### Sample Input 2

```input2
5
1.4 1.0 0.0
-0.4 -1.0 0.0
-0.1 -0.25 -0.5
-1.2 0.0 0.9
0.2 0.5 0.5
```

#### Sample Output 2

```output2
2.0000000000
```

#### Sample Input 3

```input3
8
435.249 -494.71 -539.356
455.823 -507.454 -539.257
423.394 -520.682 -538.858
446.507 -501.953 -539.37
434.266 -503.664 -560.631
445.059 -549.71 -537.501
449.65 -506.637 -513.778
456.05 -499.715 -561.329
```

#### Sample Output 3

```output3
49.9998293198
```

### 题意简述

在空间直角坐标系下给出一些点, 考察其在三个坐标平面下的正射影, 分别计算能覆盖其所有点的最小圆直径, 输出这三个直径的最小值

### 解题思路

最小圆覆盖板子题

对$x,y,z$方向分别求一遍，再取最小值即可

## B - Code Names

### 原始题面

<div style="width:30.00%" class="illustration">
  <img src="B-1.png" alt="">
</div>

You are given $W$, a set of $N$ words that are anagrams of each other. There are no duplicate letters in any word. A set of words $S⊆W$ is called "swap-free" if there is no way to turn a word $x∈S$ into another word $y∈S$ by swapping only a single pair of (not necessarily adjacent) letters in $x$. Find the size of the largest swap-free set $S$ chosen from the given set $W$

#### Input

The first line of input contains an integer $N (1≤N≤500)$. Following that are $N$ lines each with a single word. Every word contains only lowercase English letters and no duplicate letters. All $N$ words are unique, have at least one letter, and every word is an anagram of every other word

#### Output

Output the size of the largest swap-free set

#### Sample Input 1

```input1
6
abc
acb
cab
cba
bac
bca
```

#### Sample Output 1

```output1
3
```

#### Sample Input 2

```input2
11
alerts
alters
artels
estral
laster
ratels
salter
slater
staler
stelar
talers
```

#### Sample Output 2

```output2
8
```

#### Sample Input 3

```input3
6
ates
east
eats
etas
sate
teas
```

#### Sample Output 3

```output3
4
```

### 题意简述

称一个由若干字符串构成的集合$S$为可交换的, 若任取其中的两个字符串, 只交换其中一个字符串中的任意一对字符后, 均不能得到另一个字符串

给出一些

- 等长
- 只由小写英文字符构成
- 内部没有重复字符
- 互异

的字符串, 求其最大可交换集的元素个数

### 解题思路

建图, 若两个字符串是可交换的, 就在这两个字符串间加一条边, 之后求最大流即可

### 复杂度

## C - New Maths

### 原始题面

<div style="width:30.00%" class="illustration">
  <img src="C-1.png" alt="">
</div>

"Drat!" cursed Charles. "This stupid carry bar is not working in my Engine! I just tried to calculate the square of a number, but it's wrong; all of the carries are lost."

"Hmm," mused Ada, "arithmetic without carries! I wonder if I can figure out what your original input was, based on the result I see on the Engine."

Carryless addition, denoted by $⊕$, is the same as normal addition, except any carries are ignored (in base $10$). Thus, $37⊕48$ is $75$, not $85$

Carryless multiplication, denoted by $⊗$, is performed using the schoolboy algorithm for multiplication, column by column, but the intermediate additions are calculated using carryless addition. More formally, Let $a_ma_{m-1}…a_1a_0$ be the digits of $a$, where $a_0$ is its least significant digit. Similarly define $b_nb_{n-1}…b_1b_0$ be the digits of $b$. The digits of $c=a⊗b$

are given by the following equation:
$$c_k=(a_0b_k⊕a_1b_{k-1}⊕⋯⊕a_{k-1}b_1⊕a_kb_0)\bmod10$$

where any $a_i$ or $b_j$ is considered zero if $i>m$ or $j>n$. For example, $9⊗1234$ is $9876$, $90⊗1234$ is $98760$, and $99⊗1234$ is $97536$

Given $N$, find the smallest positive integer $a$ such that $a⊗a=N$

#### Input

The input consists of a single line with a positive integer $N$, with at most $25$ digits and no leading zeros

#### Output

Print, on a single line, the least positive number a such that $a⊗a=N$. If there is no such $a$, print `-1` instead

#### Sample Input 1

```input1
6
```

#### Sample Output 1

```output1
4
```

#### Sample Input 2

```input2
149
```

#### Sample Output 2

```output2
17
```

#### Sample Input 3

```input3
123476544
```

#### Sample Output 3

```output3
11112
```

#### Sample Input 4

```input4
15
```

#### Sample Output 4

```output4
-1
```

### 题意简述

定义:

- $\oplus$: 无进位的十进制"加法"

  如: $37⊕48=75$, 而不是$85$

- $\otimes$: 设$a=\overline{\def\enum#1{a_{ #1}}\enum{n}...\enum{1}\enum{0}},~b=\overline{\def\enum#1{b_{ #1}}\enum{m}...\enum{1}\enum{0}},~a\otimes b=c$, 其中$~c=\overline{\def\enum#1{c_{ #1}}\enum{l}...\enum{1}\enum{0}},~l=m+n$

  则
  $$c_k=\sum_{i=0}^ka_ib_{k-i}\bmod10,~\forall k=\def\enum#1{ { #1}}\enum{0},\enum{1},...,\enum{m+n}$$

  其中$\forall i>n,a_i=0;~\forall j>m,b_j=0$

给定$N$, 求满足$a\otimes a=N$的最小值$a$

### 解题思路

设$N$的位数为$l$, 则$a$的位数为$k=\lceil\frac{l}{2}\rceil$

注意到, $N_i$由$\def\enum#1{a_{ #1}}\enum{0},\enum{1},...,\enum{i}$决定, $i<k$, 故我们有一个简单的想法, 就是对$N_i$枚举可能的$a_i$

但是我们肯定不能去无脑 DFS

首先, 由 $a_k^2\equiv N_{2k}{\equiv}\llap{/\,}0\pmod{10}$ 可知: 若$l$为偶数则必无解

注意到

$$
\exist a_0~s.t.~a_0^2\equiv N_0\pmod{10}\iff\begin{cases}
  N_0{\equiv}\llap{/\,}\pm 2\pmod{5}\\
  a_0\in\begin{cases}
    \{0\},&N_0=0\\
    \{1,9\},&N_0=1\\
    \{2,8\},&N_0=4\\
    \{5\},&N_0=5\\
    \{4,6\},&N_0=6\\
    \{3,7\},&N_0=9
  \end{cases}
\end{cases}
$$

$$2a_0a_1\equiv N_1\pmod{10}$$
$$2a_0a_2+a_1^2\equiv N_2\pmod{10}$$
$$...$$

令$M_s=\sum_{i=1}^{s-1}a_ia_{s-i}\bmod10$, 则我们可以根据$2a_0$和$M_s$的值来确定$a_s$的值, 具体如下表:

```plaintext
+----------+----------------------------------+
|          |                M_s               |
|    a_s   +------+------+------+------+------+
|          |   0  |   2  |   4  |   6  |   8  |
+------+---+------+------+------+------+------+
|      | 0 | 0..9 |  --  |  --  |  --  |  --  |
|      +---+------+------+------+------+------+
|      | 2 | 0, 5 | 1, 6 | 2, 7 | 3, 8 | 4, 9 |
|      +---+------+------+------+------+------+
| 2a_0 | 4 | 0, 5 | 3, 8 | 1, 6 | 4, 9 | 2, 7 |
|      +---+------+------+------+------+------+
|      | 6 | 0, 5 | 2, 7 | 4, 9 | 1, 6 | 3, 8 |
|      +---+------+------+------+------+------+
|      | 8 | 0, 5 | 4, 9 | 3, 8 | 2, 7 | 1, 6 |
+------+---+------+------+------+------+------+
```

所以我们在任何一层枚举的$a_i$绝大多数情况下均不会超过$2$个, 唯一需要枚举$10$个的情况就是$2a_0$和$M_s$均为$0$的情况, 容易得知这种情况不会密集出现

### 复杂度

懒得搞数学证明了, 就打表搞一下吧

- 最坏情况  
  $\def\arraystretch{1.5}
    \begin{array}{lllll}
    l & n_1 & n_2 & n_{10} & e.g.      \\ \hline
    1 & 0   & 1   & 0      & 1         \\ \hdashline
    3 & 1   & 0   & 1      & 100       \\ \hdashline
    5 & 1   & 0   & 3      & 12100     \\ \hdashline
    7 & 1   & 0   & 12     & 1000000   \\ \hdashline
    9 & 1   & 0   & 32     & 101040000 \\ \hline\hline
    11 & 1 & 0 & 122   & 10000000000   \\ \hdashline
    13 & 1 & 0 & 322   & 1002001000000 \\ \hdashline
    15 & 1 & 0 & 1222  & 100000000000000   \\ \hdashline
    17 & 1 & 0 & 3222  & 10104010100000000 \\ \hdashline
    19 & 1 & 0 & 12222 & 1000000000000000000   \\ \hdashline
    21 & 1 & 0 & 32222 & 101040101040000000000 \\
  \end{array}$

  其中:

  - $n_1$: 枚举$1$个情况的总数
  - $n_2$: 枚举$2$个情况的总数
  - $n_{10}$: 枚举$10$个情况的总数
  - $e.g.$: 例子
  - 双横线后的数据不保证其为最坏情况 ~~实在是算不动啊~~

  应用回归分析推测复杂度为$O(1.765948^l)$

- 平均情况

  $$
  \def\arraystretch{1.5}
  \begin{array}{llll}
    l & n_1     & n_2      & n_{10}   \\ \hline
    1 & 1\over3 & 2\over3  & 0        \\ \hdashline
    3 & 1\over3 & 4\over3  & 1\over30 \\ \hdashline
    5 & 1\over3 & 2        & 1\over15 \\ \hdashline
    7 & 1\over3 & 8\over3  & 1\over10 \\ \hdashline
    9 & 1\over3 & 10\over3 & 2\over15
  \end{array}
  $$

  其中:

  - $n_1$: 枚举$1$个情况的期望
  - $n_2$: 枚举$2$个情况的期望
  - $n_{10}$: 枚举$10$个情况的期望

  推测均摊复杂度为 $O(k)$

## D - Some Sum

### 原始题面

<div style="width:50.00%" class="illustration">
  <img src="D-1.png" alt="">
  <div class="description">
    illustration by Larry Pyeatt
  </div>
</div>

Your friend has secretly picked $N$ consecutive positive integers between $1$ and $100$, and wants you to guess if their sum is even or odd

If the sum must be even, output `Even`. If the sum must be odd, output `Odd`. If the sum could be even or could be odd, output `Either`

#### Input

The input is a single integer $N$ with $1≤N≤10$

#### Output

Output a single word. The word should be `Even`, `Odd`, or `Either`, according to the rules given earlier

#### Sample Input 1

```input1
1
```

#### Sample Output 1

```output1
Either
```

#### Sample Input 2

```input2
2
```

#### Sample Output 2

```output2
Odd
```

### 题意简述

从$[1,100]$中任取$N$个连续的正整数, 问这$N$个数的和是否一定全为奇数或全为偶数

### 解题思路

签到题

首先我们不难得出这$N$个数和的通式为 $\frac{N(N+1)}{2}+kN$

容易得出:

- 这$N$个数的和保持奇偶不变当且仅当$N$为偶数
- $2\mid\frac{N(N+1)}{2}\iff N\equiv0\pmod4$
- $2\nmid\frac{N(N+1)}{2}\iff N\equiv2\pmod4$

## E - Early Orders

### 原始题面

<div style="width:30.00%" class="illustration">
  <img src="E-1.png" alt="">
</div>

You are given a list of integers $x_1,x_2,…,x_n$ and a number $k$. It is guaranteed that each $i$ from $1$ to $k$ appears in the list at least once

Find the lexicographically smallest subsequence of $x$ that contains each integer from $1$ to $k$ exactly once

#### Input

The first line contains two integers $n$ and $k$, with $1≤k≤n≤200000$. The following $n$ lines each contain an integer $x_i$ with $1≤x_i≤k$

#### Output

Write out on one line, separated by spaces, the lexicographically smallest subsequence of $x$ that has each integer from $1$ to $k$ exactly once

#### Sample Input 1

```input1
6 3
3
2
1
3
1
3
```

#### Sample Output 1

```output1
2 1 3
```

#### Sample Input 2

```input2
10 5
5
4
3
2
1
4
1
1
5
5
```

#### Sample Output 2

```output2
3 2 1 4 5
```

### 题意简述

给出$n,k$和$n$个在$[1,k]$中的正整数, 在这$n$个数中找到一个子序列, 使得其为$1..k$的一个排列且其字典序最小

### 解题思路

我们按顺序从前往后在这$n$个数之中选$k$个数出来, 一个自然的想法就是每次尽量选取字典序最小的数, 让较大的数在答案序列中尽量靠后

我们可以用类似单调队列的思想去实现:

用`ans[]`存储答案, 当枚举到第$i$个数$a_i$的时候, 当`ans[]`之中没有$a_i$时, 将其与`ans[]`的最后一位$b$做比较, 如果$a_i<b$且$a_i$之后还有$b$, 那么删去$b$, 接着比较, 直到在`ans[]`中找到不满足条件的数为止, 此时插入$a_i$, 枚举下一个数

## F - Pulling Their Weight

### 原始题面

<div style="width:30.00%" class="illustration"><img src="F-1.jpg" alt="">
  <div class="description">
    <a href="https://en.wikipedia.org/wiki/File:American_bison_k5680-1.jpg">Buffalo</a>, <a href="https://commons.wikimedia.org/wiki/File:Water_Vole_(6038169781).jpg">
    vole</a>, and <a href="https://commons.wikimedia.org/wiki/File:Miniature_schnauzer.jpg">schnauzer</a>. Original images from Wikipedia.
  </div>
</div>

To save money, Santa Claus has started hiring other animals besides reindeer to pull his sleigh via short term 'gig' contracts. As a result, the actual animals that show up to pull his sleigh for any given trip can vary greatly in size

Last week he had $2$ buffalo, $37$ voles and a schnauzer. Unfortunately, both buffalo were hitched on the left side and the entire sleigh flipped over in mid-flight due to the weight imbalance

To prevent such accidents in the future, Santa needs to divide the animals for a given trip into two groups such that the sum of the weights of all animals in one group equals the sum of the weights of all animals in the other. To make the hitching process efficient, Santa is seeking an integer target weight $t$ such that all animals that are lighter than $t$ go in one group and those heavier than $t$ go into the other. If there are multiple such $t$, he wants the smallest one. There's one small wrinkle: what should be done if there some animals have weight exactly equal to $t$? Santa solves the problem this way: if there are an even number of such animals, he divides them equally among the two groups (thus distributing the weight evenly). But if there are an odd number of such animals, then one of those animals is sent to work with the elves to make toys (it is not put in either group), and the remaining (now an even number) are divided evenly among the two groups

#### Input

Input describes a list of animals' weights. The first line contains an integer $m (2≤m≤10^5$), indicating the number of animals. The next $m$ lines each have a positive integer. These are the weights of the animals (in ounces). Animals weighing more than $20000$ ounces are too big to pull the sleigh so no given weight exceeds this maximum

#### Output

Output the smallest integer target weight $t$, as described above. It's guaranteed that it is possible to find such an integer

#### Sample Input 1

```input1
4
3
6
1
2
```

#### Sample Output 1

```output1
4
```

#### Sample Input 2

```input2
4
11
8
3
10
```

#### Sample Output 2

```output2
10
```

#### Sample Input 3

```input3
2
99
99
```

#### Sample Output 3

```output3
99
```

### 题意简述

给出$n$个数$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 问如何选取最小的$t$使得$\sum_{a_i<t}a_i=\sum_{a_i>t}a_i$, 保证有解

### 解题思路

考虑应用前缀和

设 $\operatorname{sum}(x)=\sum_{a_i\leqslant x}a_i$, $A=\max_{1\leqslant i\leqslant n}\{a_i\}$, 则所求即为满足
$$\operatorname{sum}(x-1)=\operatorname{sum}(A)-\operatorname{sum}(x)$$
的$x$的最小值

预处理出$\operatorname{sum}(1)..\operatorname{sum}(A)$, 之后由低到高枚举$x$验证即可

### 复杂度

$O(\max\{n,A\})$

## G - Birthday Paradox

### 原始题面

<div style="width:40.00%" class="illustration">
  <img src="G-1.png" alt="">
  <div class="description">
    The probability of <span class="katex"><span class="mord mathdefault">n</span></span>
    unique birthdays among <span class="katex"><span class="mord mathdefault">n</span></span> people.
  </div>
</div>

The Birthday Paradox is the name given to the surprising fact that if there are just $23$ people in a group, there is a greater than $50\%$ chance that a pair of them share the same birthday. The underlying assumptions for this are that all birthdays are equally likely (which isn't quite true), the year has exactly $365$ days (which also isn't true), and the people in the group are uniformly randomly selected (which is a somewhat strange premise). For this problem, we'll accept these assumptions

Consider what we might observe if we randomly select groups of $P=10$ people. Once we have chosen a group, we break them up into subgroups based on shared birthdays. Among many other possibilities, we might observe the following distributions of shared birthdays:

- all $10$ have different birthdays, or
- all $10$ have the same birthday, or
- $3$ people have the same birthday, $2$ other people have the same birthday (on a different day), and the remaining $5$ all have different birthdays

Of course, these distributions have different probabilities of occurring

Your job is to calculate this probability for a given distribution of people sharing birthdays. That is, if there are $P$ people in a group, how probable is the given distribution of shared birthdays (among all possible distributions for $P$ people chosen uniformly at random)?

#### Input

The first line gives a number $n$ where $1≤n≤365$. The second line contain integers $c_1$ through $c_n$, where $1≤c_i≤100$ for all $c_i$. The value $c_i$ represents the number of people who share a certain birthday (and whose birthday is distinct from the birthdays of everyone else in the group)

#### Output

Compute the probability $b$ of observing a group of people with the given distribution of shared birthdays. Since b may be quite small, output instead $\log_{10}(b)$. Your submission's answer is considered correct if it has an absolute or relative error of at most $10^{-6}$ from the judge's answer

#### Explanations

The first sample case shows $P=2$ people with distinct birthdays. The probability of this occurring is $b=364/365≈0.9972602740$, and $\log_{10}(b)≈-0.001191480807419$

The second sample case represents the third example in the list given earlier with $P=10$ people. In this case, the probability is $b≈0.0000489086$, and $\log_{10}(b)≈-4.310614508857128$

#### Sample Input 1

```input1
2
1 1
```

#### Sample Output 1

```output1
-0.001191480807419
```

#### Sample Input 2

```input2
7
1 1 2 1 3 1 1
```

#### Sample Output 2

```output2
-4.310614508857128
```

### 题意简述

对任意$k$个人来说, 他们可按照生日划分成若干等价类, 设一共有$n$个, 第$i$个等价类内元素个数为$c_i$, 一年按$365$天记

给出$n$和$\def\enum#1{c_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 问满足该限制条件的概率, 最后结果以$10$为底取对数

### 解题思路

我们知道

- 如果$n$个元素可划分为$k$个等价类, 第$i$个等价类内元素个数为$n_i$, 则这$n$个元素的全排列个数为
  $${n!\over\prod_{i=1}^k(n_i!)}$$
- 将$n$个互异元素划分为$k$组, 第$i$组内元素个数为$n_i$, 则总划分数为
  $${n!\over\prod_{i=1}^k(n_i!)}$$

所求概率即为: 满足条件的总方案数除以$365^k$

设$f_k=\sum_{i=1}^n[c_i=k]$

求满足条件的总方案数时, 我们这样考虑:

- 首先需要从$365$天中取出$n$个不同的日子, 取法为$\displaystyle\binom{365}{n}$
- 然后我们需要让等价类与日子一一对应, 这样的总方法数为$\displaystyle{n!\over\prod_{i=1}^n(f_i!)}$
- 最后我们要让所有等价类中的元素和人一一对应, 这样的总方法数为$\displaystyle{k!\over\prod_{i=1}^k(c_i!)}$

因此由乘法原理, 所求概率为

$$\frac{1}{365^k}\binom{365}{n}{n!\over\prod_{i=1}^n(f_i!)}{k!\over\prod_{i=1}^k(c_i!)}$$

### 复杂度

$O(k)$

## H - On Average They're Purple

### 原始题面

<div style="width:30.00%" class="illustration">
  <img src="H-1.png" alt="">
</div>

Alice and Bob are playing a game on a simple connected graph with $N$ nodes and $M$ edges

Alice colors each edge in the graph red or blue

A path is a sequence of edges where each pair of consecutive edges have a node in common. If the first edge in the pair is of a different color than the second edge, then that is a "color change."

After Alice colors the graph, Bob chooses a path that begins at node $1$ and ends at node $N$. He can choose any path on the graph, but he wants to minimize the number of color changes in the path. Alice wants to choose an edge coloring to maximize the number of color changes Bob must make. What is the maximum number of color changes she can force Bob to make, regardless of which path he chooses?

#### Input

The first line contains two integer values $N$
and $M$ with $2≤N≤100000$ and $1≤M≤100000$. The next $M$ lines contain two integers $a_i$ and $b_i$ indicating an undirected edge between nodes $a_i$ and $b_i$ ($1≤a_i,b_i≤N, ai≠bi$)

All edges in the graph are unique

#### Output

Output the maximum number of color changes Alice can force Bob to make on his route from node $1$ to node $N$

#### Sample Input 1

```input1
3 3
1 3
1 2
2 3
```

#### Sample Output 1

```output1
0
```

#### Sample Input 2

```input2
7 8
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
```

#### Sample Output 2

```output2
3
```

### 题意简述

给出图$G\lang N,M\rang$, 每条边均可染成红色或蓝色, 问如何染色使得从$1$到$N$的最适路径中颜色改变次数最大, 输出最大值

从$1$到$N$的最适路径指: 从$1$到$N$的所有路径中, 颜色改变次数最小的路径

### 解题思路

我们发现, 要想使最适路径的变换颜色次数最大, 只需要让最适路径中连接任意非起讫点的两条边颜色不同即可

这样问题便转化成了求无向图上从$1$到$N$的最短路, 答案即为最短路长度$-1$

直接用 BFS 求最短路就行, 下面给出的是用 Dijkstra 求的

## I - Full Depth Morning Show

### 原始题面

<div style="width:30.00%" class="illustration">
  <img src="I-1.png" alt="">
</div>

All boring tree-shaped lands are alike, while all exciting tree-shaped lands are exciting in their own special ways. What makes Treeland more exciting than the other tree-shaped lands are the raddest radio hosts in the local area: Root and Leaf. Every morning on FM $32.33$(repeating of course), Root and Leaf of The Full Depth Morning Show serve up the hottest celebrity gossip and traffic updates

The region of Treeland is made of $n$ cities, connected by $n-1$ roads such that between every pair of cities there is exactly one simple path. The $i$th road connects cities $u_i$ and $v_i$, and has a toll of $w_i$

To reward their loyal listeners, The Full Depth Morning Show is giving away a number of travel packages! Root and Leaf will choose $n-1$ lucky residents from the city that sends them the most fan mail. Each of those residents then gets a distinct ticket to a different city in Treeland

Each city in Treeland has its own tax on prizes: $t_i$. Let $d_{u,v}$ be the sum of the tolls on each road on the only simple path from city $u$ to $v$. For a trip from city $u$ to city $v$, the cost of that trip is then $(t_u+t_v)d_{u,v}$

<div class="figure">
  <center>
    <img src="I-2.png" alt="" style="width:70.00%">
    <div class="caption">
      <b>Figure 1</b>: The map of Treeland corresponding to the
      first sample input.
    </div>
  </center>
</div>

The shock jocks haven't quite thought through how much their prize is worth. They need to prepare a report to the radio executives, to summarize the expected costs. For each city that could win the prize, what is the total cost of purchasing all the tickets?

#### Input

The first line of input is a single integer $n$ $(1≤n≤100000)$. The next line has $n$ space-separated integers $t_i$ $(1≤t_i≤1000)$, the tax in each city. The following $n-1$ lines each have $3$ integers, $u_i$,$v_i$,$w_i$, meaning the $i$th road connects cities $u_i$ and $v_i$ $(1≤u_i,v_i≤n)$, with a toll of $w_i$ $(1≤w_i≤1000)$

#### Output

Output $n$ lines. On the $i$th line, output a single integer: the cost of purchasing tickets if city $i$ wins the contest

#### Sample Input 1

```input1
5
2 5 3 4 1
1 2 2
2 4 5
4 3 3
5 2 6
```

#### Sample Output 1

```output1
130
159
191
163
171
```

#### Sample Input 2

```input2
6
4 3 3 4 3 3
1 3 2
2 1 1
1 4 6
4 5 6
6 4 2
```

#### Sample Output 2

```output2
209
206
232
209
336
232
```

### 题意简述

给出一个有$n$个结点的树, 每个点$v$有点权$t_v$, 每个边有边权, 设为点$u$到点$v$经过的所有边的边权和, $d_{u,u}=0$, 对所有的结点$u$, 求
$$\sum_{v}(t_u+t_v)d_{u,v}$$

### 解题思路

设该树的根结点为$u$, 则
$$a_u=\sum_{v}d_{u,v}$$
$$b_u=\sum_{v}t_vd_{u,v}$$

则对于结点$u$, 答案即为$t_ua_u+b_u$

考虑与$u$相邻的结点$u'$, 设以$u'$为根结点的子树结点集(包括自身)为$S(u')$, 我们有

$$a_{u'}=a_u+(n-2|S(u')|)d_{u,u'}$$
$$b_{u'}=b_u+\left(\sum_{v}t_v-2\sum_{v\in S(u')}t_v\right)d_{u,u'}$$

## J - This Ain't Your Grandpa's Checkerboard

### 原始题面

<div style="width:20.00%" class="illustration">
  <img src="J-1.png" alt="">
</div>

You are given an $n$-by-$n$ grid where each square is colored either black or white. A grid is correct if all of the following conditions are satisfied:

- Every row has the same number of black squares as it has white squares
- Every column has the same number of black squares as it has white squares
- No row or column has $3$ or more consecutive squares of the same color

Given a grid, determine whether it is correct

#### Input

The first line contains an integer $n$
($2≤n≤24$; $n$ is even). Each of the next $n$ lines contains a string of length $n$ consisting solely of the characters `B` and `W`, representing the colors of the grid squares

#### Output

If the grid is correct, print the number $1$ on a single line. Otherwise, print the number $0$ on a single line

#### Sample Input 1

```input1
4
WBBW
WBWB
BWWB
BWBW
```

#### Sample Output 1

```output1
1
```

#### Sample Input 2

```input2
4
BWWB
BWBB
WBBW
WBWW
```

#### Sample Output 2

```output2
0
```

#### Sample Input 3

```input3
6
BWBWWB
WBWBWB
WBBWBW
BBWBWW
BWWBBW
WWBWBB
```

#### Sample Output 3

```output3
0
```

#### Sample Input 4

```input4
6
WWBBWB
BBWWBW
WBWBWB
BWBWBW
BWBBWW
WBWWBB
```

#### Sample Output 4

```output4
1
```

### 题意简述

给出只有黑格和白格的方阵, 问是否同时满足如下条件

- 每行的黑格数等于白格数
- 每列的黑格数等于白格数
- 任一行或列上没有三个相邻的格子颜色相同

### 解题思路

签到题

直接模拟即可

## K - Solar Energy

### 原始题面

<div style="width:30.00%" class="illustration">
  <img src="K-1.png" alt="">
</div>

You are planning to travel in interstellar space in the hope of finding habitable planets. You have already identified $N$ stars that can recharge your spaceship via its solar panels. The only work left is to decide the orientation of the spaceship that maximizes the distance it can travel

Space is modeled as a $2$D plane, with the Earth at the origin. The spaceship can be launched from the Earth in a straight line, in any direction. Star $i$ can provide enough energy to travel $T_i$ distance if the spaceship is launched at an angle of $a_i$ with the $x$-axis. If the angle is not perfectly aligned, then the spaceship gets less energy. Specifically, if the launch direction makes an angle of a with the $x$-axis, then it gets enough energy to travel distance of
$$\max(0,T_i-s_i⋅\operatorname{dist}(a_i,a))$$

from star $i$, where $\operatorname{dist}(a,b)$ is the minimum radians needed to go from angle $a$ to $b$. The distance that the spaceship can travel is simply the sum of the distances that each star contributes. Find the maximum distance $T$ that the starship can travel

#### Input

The first line contains the value $N$, $1≤N≤10^5$. Following this are $N$ lines each containing three real numbers $T_i$, $s_i$, and $a_i$, with $0<Ti≤1000$, $0≤s_i≤100$, and $0≤a_i<2π$. All real numbers in the input have at most $6$ digits after the decimal point

#### Output

On a single line output the maximum distance the spacecraft can travel. Your answer is considered correct if it has an absolute or relative error of at most $10^{-6}$

#### Sample Input 1

```input1
2
100 1 1
100 1 1.5
```

#### Sample Output 1

```output1
199.500000
```

#### Sample Input 2

```input2
4
100 1 0.5
200 1 1
100 0.5 1.5
10 2 3
```

#### Sample Output 2

```output2
405.500000
```

### 题意简述

给出$n$组数对$(T_i,s_i,a_i)$, 其中$0\leqslant a_i< 2\pi,i=1,2,...,n$, 令
$$f_i(a)=\max\{0,T_i-s_i|a_i-a|,T_i-s_i|2\pi-|a_i-a||\},~i=1,2,...,n$$

$$f(a)=\sum_{i=1}^nf_i(a)$$
求$f_{max}$

### 解题思路

注意到$f_i(a)$是由一系列一次函数和常函数构成的分段函数, $f(a)$自然也是, 而且$f(a)$的分界点集$D$即为所有$f_i(a)$分界点集$D_i$的并集

显然答案为

$$\max_{x\in D}f(x)$$

接下来我们只需考虑如何快速求$f(a)$分界点的函数值了

令$D=\{\def\enum#1{d_{ #1}}\enum{1},\enum{2},...,\enum{m}\}$, $k_i$为$f|_{x\in[d_i,d_{i+1}]}$的斜率

则$f(d_{i+1})=f(d_i)+k_i(d_{i+1}-d_i)$

而$k_i$实际上是很容易求的, 这样我们便可以$O(m)=O(n)$递推了

下面举一个例子

输入:

```plaintext
3
10 0 0.5
10 2 1
10 4 1.5
```

我们列出对应函数

$$
\begin{aligned}
  f_1(a)&=\max\{0,10\}\\
  f_2(a)&=\max\{0,10-2|a-1|,10-2|2\pi-|a-1||\}\\
  f_3(a)&=\max\{0,10-4|a-1.5|,10-4|2\pi-|a-1.5||\}\\
\end{aligned}
$$

画个图

![](K-sol-1.png)

其中<font color="#2d70b2">蓝色</font>图像为$f_1$, <font color="#c74440">红色</font>图像为$f_2$, <font color="#388c46">绿色</font>图像为$f_3$

我们把$f$也加进去

![](K-sol-2.png)

其中<font color="#6042a6">紫色</font>图像为$f\over3$

放大一些

![](K-sol-3.png)

可以证明$f$的图像存在"局部周期", 即
$$\big(\exist a,t\in\R,\forall x\in[a,a+t)\big),~f(x)=f(x+t)$$
而且在不考虑$f\equiv0$的那些情况下, 只有有限组$a,t$

因此我们没有必要枚举所有的$d_i$, 只需要取遍其所有函数值不恒为$0$的"局部周期"即可, 我们可以通过选择$f_i$的一部分进行加和来完成该操作

一种可行的操作是只选$f_i$沿$a$正方向的后两个"峰", 即

- 对`_/\_/\_/\_`型图像, 只需取`/\_/\_`部分即可
- 对`_/W\_`型图像, 只需取`^/\_`部分即可

记录对应间断点和斜率变化, 即可$O(n)$递推
