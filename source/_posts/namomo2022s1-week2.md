---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 2)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - CodeForces
  - CCPC
  - 51Nod
  - 数学
  - 图论
  - 数据结构
  - 期望
  - 概率
  - DP
  - 状压DP
  - 概率DP
  - 最短路
  - 组合数学
  - 前缀和
  - 位运算
  - 递推
  - 容斥定理
  - RMQ
  - ST表
  - Trie
  - 01-Trie
date: 2022-03-05 21:44:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.03.05-2022.03.11)

<!-- more -->

## 摘桃子

[题目链接](https://oj.daimayuan.top/problem/466)

1 s, 1024 MB

桃园里面有 $n$ 个人在摘桃子. 现在 $n$ 个人排成一排, 从左到右每个人拥有的桃子数是 $a_i$. 桃园里有一个免费获得桃子的规则, 如果连续 $x$ 个人的桃子总数除以 $k$ 的余数正好是 $x$, 那么这 $x$ 个人就可以免费获得桃子, 并且每天只有一次免费获得桃子的机会. 请聪明的你算出一共有多少种不同的方案可以使今天有人免费获得桃子

### 输入格式

第一行两个数字 $n$, $k$

接下来一行 $n$ 个整数 $a_1, a_2, \dots, a_n$

### 输出格式

一个数, 表示答案

### 样例输入

```input1
8 4
4 2 4 2 4 2 4 2
```

### 样例输出

```output1
7
```

### NOTE

七个不同方案分别是: $a_1, a_2$, $a_2, a_3$, $a_3, a_4$, $a_4, a_5$, $a_5, a_6$, $a_6, a_7$, $a_7, a_8$. 注: 只要子串有一个边界不同即为不同的方案

### 数据规模

所有数据保证 $1\leq n\leq 2 × 10^5, 1 \leq k \leq 10^9, 1 \leq a_i \leq 10^9$

### 解题思路

这个区间和有个处理的套路: 所有数都减 1, 处理之后要求就变成了 区间和模 $k$ 为 $0$

然后就是经典板子题了

### 复杂度

$O(n\log n)$ (使用 `map`)

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Daimayuan_466 Daimayuan/466/0.cpp %}

</details>

## 路径计数 2 (CF559C)

[题目链接](https://oj.daimayuan.top/problem/467)

1 s, 512 MB

有一个 $n * n$ 的网格, 有些格子是可以通行的, 还有 $m$ 个格子是障碍

一开始你在左上角的位置, 你可以每一步往下或者往右走, 问有多少种走到右下角的方案

由于答案很大, 输出对 $10^9+7$ 取模的结果

### 输入格式

第一行两个数字 $n$, $m$

接下来 $m$ 行, 每行 $2$ 个整数 $x_i , y_i$, 代表第 $i$ 个障碍的坐标

### 输出格式

一个数, 表示答案

### 样例输入

```input1
2 1
2 1
```

### 样例输出

```output1
1
```

### 数据规模

所有数据保证 $1\leq n\leq 10^6,1 \leq m \leq 3000,1 \leq x_i,y_i \leq n$

### 解题思路

显然是容斥

令

- 第 $i$ 个障碍物的坐标为 $(x_i,y_i)$
- $f_i$ 为从 $(1,1)$ 走到第 $i$ 个障碍物合法方案

显然

$$f_i=\binom{x_i+y_i-2}{x_i-1}-\sum_{x_i\geq x_j; y_i\geq y_j}\binom{x_i+y_i-x_j-y_j}{x_i-x_j}f_j$$

### 复杂度

$O(m^2)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_559C CodeForces/559C/0.cpp %}

</details>

## 函数求和

[题目链接](https://oj.daimayuan.top/problem/468)

1 s, 1024 MB

给定$n$个整数$a_1, a_2, \dots, a_n$和正整数$k$满足$(0 \leq a_i \leq 2^k - 1)$

定义函数$f(x)$为满足$a_i \& x \neq a_i$的最小的$i$, 当满足条件的$i$不存在时 $f(x)=0$

求$\sum_{i = 0}^{2^k - 1}f(i)$. 由于答案可能很大, 输出答案取模$998244353$后的值

### 输入格式

第一行两个数字$n$, $k$

接下来一行$n$个整数 $a_1, a_2, \dots, a_n$, 表示这$n$个数

### 输出格式

一行一个整数, 表示答案

### 样例输入 1

```input1
2 1
0 1
```

### 样例输出 1

```output1
2
```

### 样例输入 2

```input2
2 2
2 1
```

### 样例输出 2

```output2
4
```

### 样例输入 3

```input3
5 10
389 144 883 761 556
```

### 样例输出 3

```output3
1118
```

### 样例解释

对于样例 1, $f(0) = 2$, $f(1) = 0$, 答案 $= 2$

### 数据规模

所有数据保证 $1\leq n \leq 100, 1 \leq k \leq 60$

### 解题思路

> 今天的题好水

乘法原理拼一下就完事了

### 复杂度

$O(nk)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Daimayuan_468 Daimayuan/468/0.cpp %}

</details>

## XOR Inverse (CF1416C)

[题目链接](https://oj.daimayuan.top/problem/497)

2 s, 512 MB

### 题目描述

给你一个有 $n$ 个非负整数组成的数组 $a$, 你需要选择一个非负整数 $x$, 对数组 $a$ 的每一个 $a_i$ 与 $x$ 进行异或后形成新的数组 $b$, 要求 $b$ 数组的逆序对个数最小, 如果有多个 $x$ 满足条件, 输出最小的 $x$

一个逆序对指 $b$ 数组内对于整数 $i,j$ 满足条件 $1\leq i < j \leq n$ 且 $b_i > b_j$

### 输入格式

第一行一个正整数 $n$

接下来一行 $n$ 个非负整数 $a_1,a_2,\dots,a_n$

### 输出格式

两个数: $b$ 数组的最小逆序对数和此时 $x$ 的最小值

### 样例输入#1

```input1
4
0 1 3 2
```

### 样例输出#1

```output1
1 0
```

### 样例输入#2

```input2
9
10 7 9 10 7 5 5 3 5
```

### 样例输出#2

```output2
4 14
```

### 样例输入#3

```input3
3
8 10 3
```

### 样例输出#3

```output3
0 8
```

### 数据范围

$1\leq n\leq 3\cdot 10^5$, $0\leq a_i\leq 10^9$

### 解题思路

> 01-trie

将数按顺序插入 01-trie 中, 并在插入的结点处记录插入的数的下标, 由于 01-trie 中同一层的右儿子代表的数严格大于左儿子的, 所以可以根据这个来计算逆序对

### 复杂度

$O(n\log n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1416C CodeForces/1416C/0.cpp %}

</details>

## Closest Equals (CF522D)

[题目链接](https://oj.daimayuan.top/problem/469)

2 s, 512 MB

给定一个下标从 $1$ ~ $n$ 的序列 $a$, 然后进行 $m$ 次询问

每次询问给出一对 $[l, r]$, 找到区间中数值相等的且距离最相近的两个数 $a_i$ 和 $a_j$, 求它们的距离

换言之找到一组数 $(a_i, a_j)$ 满足

- $a_i = a_j$;
- $l \leq i, j \leq r$ $(i \neq j)$;

求 $|i - j|$ 的最小值, 如果区间中不存在相等的两个数, 则输出 $-1$

### 输入格式

第一行输入两个整数 $1 \leq n, m \leq 5 \times 10^5$

第二行输入 $n$ 个整数 $1 \leq a_i \leq 10^9$

接下来 $m$ 行, 每行输入两个整数 $1 \leq l \leq r \leq n$

### 输出格式

输出 $m$ 行, 每行包含一个整数作为询问的答案

### 输入样例 1

```input1
5 3
1 1 2 3 2
1 5
2 4
3 5
```

### 输出样例 1

```output1
1
-1
2
```

### 输入样例 2

```input2
6 5
1 2 1 3 2 3
4 6
1 3
2 5
2 4
1 6
```

### 输出样例 2

```output2
2
2
3
-1
2
```

### 解题思路

> RMQ + 二分

首先我们求出全部两端点值相同的线段 $(l,r)$, 然后删去冗余的线段 (若 $l_1\leq l_2$ 且 $r_1\geq r_2$, 那么 $(l_1,r_1)$ 对答案不会产生贡献, 直接删去即可)

然后就是查询区间最短线段长度

{% note warning %}

`std::lower_bound` 和 `std::upper_bound` 对 `comp` 签名要求不一致, 但作用要求一致 (即 若第一参数先序于第二个则返回 `​true`)

- `std::lower_bound<ForwardIter, T>` 要求的是 `bool comp(const ForwardIter& t1, const T& t2)`
- `std::upper_bound<ForwardIter, T>` 要求的是 `bool comp(const T& t1, const ForwardIter& t2)`

详情参见 [^1] [^2]

[^1]: <https://en.cppreference.com/mwiki/index.php?title=cpp/algorithm/lower_bound&oldid=139001>
[^2]: <https://en.cppreference.com/mwiki/index.php?title=cpp/algorithm/upper_bound&oldid=139224>

{% endnote %}

### 复杂度

$O(n\log n+m)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_522D CodeForces/522D/0.cpp %}

</details>

## CCPC Harbin 2021 G, Damaged Bicycle (CodeForces Gym 103447G)

[题目链接](https://oj.daimayuan.top/problem/380)

3 s, 1024 MB

Ring Ring Ring ... The bell rang at half past six in the morning. After turning off the alarm, George went on to sleep again. When he woke up again, it was seven fifty and there were ten minutes left for class!

George immediately got up from bed, dressed, packed his backpack, brushed his teeth and washed his face. Then, he immediately rushed out of the dormitory and embarked on the road to the teaching building. On the way, he turned on his mobile phone to locate and saw several yellow shared bicycles nearby. Therefore, he headed to a bicycle and took out his mobile phone to scan the QR code on the bicycle. Unfortunately, the bicycle wasn't unlocked, and a line of words "this bicycle is damaged and can't be unlocked" was displayed on the screen

Without riding a bicycle, he was late. What a bad day!

Indeed, some bicycles in the school are damaged, but their location will still be displayed on the app. George always rides faster than he walks, but considering that some bicycles are damaged, if George tries one by one, it may take a long time! In this regard, he has made some modeling, and hopes you can help him find the best strategy

The campus can be modeled as a graph of $n$ vertices and $m$ bidirected edges, where the $i$-th edge is $w_i$ meters long. George's dormitory is located at vertex $1$ and Guanghua Tower (the teaching building) is at vertex $n$, so George has to go from vertex $1$ to vertex $n$ to take classes. His walking speed is $t$ meters per second and his riding speed is $r$ meters per second. According to the bicycle sharing app, there are $k$ parked bicycles in the campus. The $i$-th bicycle is located at vertex $a_i$, and of probability $\frac{p_i}{100}$ to be damaged according to George's experience. However, only when George arrives at vertex $a_i$ and scans the QR code, can he determine whether the $i$-th bicycle is damaged or not. As soon as a bicycle is confirmed to be undamaged, George will get on it immediately and will not get off until he reaches vertex $n$

Now George wants to save time to get to the classroom. So you, George's roommate, should help him find an optimal strategy to minimize the mathematical expectation of the time cost on the way, and then output this value. Or you can let him continue sleeping if vertex $n$ is not reachable

In this problem, you should only consider the time of walking and cycling, and you can assume that the other actions(scanning QR code, getting on, getting off, $\cdots$) cost no time

简单中文翻译: 校园可以被看成$n$个点, $m$条无向边的图, 其中第$i$条边的长度是$w_i$. 你的宿舍在$1$号点, 教学楼在$n$号点, 你想从宿舍去教学楼. 你的走路速度是每秒$t$, 骑车速度是每秒$r$. 根据共享单车 app, 校园内一共有$k$个停车点. 第$i$个停车点在$a_i$点, 但是有$\frac{p_i}{100}$的概率, 车可能是坏的. 但是你只有到达$a_i$点, 然后扫描二维码之后才能知道第$i$辆车是不是好的. 如果车是好的, 那就可以骑到终点

问你最优策略下, 你最小的到达终点的期望时间是多少. 如果到达不了$n$号点, 输出-1

### Input

The first line contains two integers $t,r\,(1\le t\le r\le 10^4)$ — the speed of walking and the speed of riding, respectively

The second line contains two integers $n,m\,(1\le n,m\le 10^5)$ — the number of vertices and the number of bidirected edges in the given graph

Following $m$ lines each contains three integers $u_i,v_i,w_i\,(1\le u_i,v_i \le n, u_i \neq v_i, 1 \le w_i\le 10^4)$, denoting that vertices $u,v$ are connected by a $w_i$-meter-long bidirected edge

The next line contains a single integer $k\,(0\le k\le 18)$, denoting the number of bicycles in campus

Following $k$ lines each contains two integers $a_i,p_i\,(1\le a_i \le n, 0\le p_i \le 100)$, denoting the locations of the bicycles and the percentages of damage probabilities respectively

It is guaranteed that no two bicycles are in the same vertex

### Output

If George cannot reach vertex $n$, output one line containing one integer -1, or output one line containing one real number, denoting the minimum expectation of the time cost on the way

As long as the relative or absolute error between your answer and the standard answer is within $10^{-6} $, your answer will be considered correct

### Examples

#### input

```input1
3 15
4 3
1 2 600
1 3 300
2 4 900
1
3 50
```

#### output

```output1
460.000000
```

#### input

```input2
3 15
5 4
1 2 600
1 3 300
2 5 900
3 4 3
2
3 50
4 0
```

#### output

```output2
220.600000
```

#### input

```input3
3 15
5 4
1 2 600
1 3 300
4 5 900
3 2 300
2
3 50
4 0
```

#### output

```output3
-1
```

### Note

For the first test case, one possible strategy is:

- Go along the route $1\rightarrow 3$ and try to ride the only bicycle in the campus
- If the bicycle is damaged, go along the route $3 \rightarrow 1 \rightarrow 2 \rightarrow 4$ on foot, or go by bicycle

Considering the time cost on the way:

- If the bicycle is damaged, George should go along the route $1\rightarrow 3 \rightarrow 1 \rightarrow 2 \rightarrow 4$ on foot, whose total length is 2100 meters. So the time cost is $\frac{2100}{3} = 700$ seconds
- If the bicycle is undamaged, George should go along the route $1\rightarrow 3$ on foot, whose total length is 300 meters, and then go along the route $3 \rightarrow 1 \rightarrow 2 \rightarrow 4$ by bicycle, whose total length is 1800 meters. So the time cost is $\frac{300}{3} + \frac{1800}{15} = 220$ seconds

As given in the input, the only bicycle has $\frac{50}{100}$ probability to be damaged. So the expectation time cost is $\frac{50}{100}\times 700 + (1 - \frac{50}{100})\times 220 = 460$

### 解题思路

> 状压 DP + 最短路

> 官方题解参见 <https://codeforces.com/gym/103447/attachments/download/14826/2021CCPCHarbinSolution.pdf#Outline0.8>

DP 不会写, 写的记搜

思路和官方题解差不多, 略

### 复杂度

$O(m+kn\log n+k^22^k)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_Gym_103447G Gym/103447G/0.cpp %}

</details>

## 拆方块 (CF573B, 51NOD1550)

[题目链接](https://oj.daimayuan.top/problem/501)

1 s, 1024 MB

有$n$堆方块, 第$i$堆方块由$h_i$个方块堆积而成. 具体可以看样例

接下来拆方块. 一个方块称为内部方块当且仅当他的上下左右都是方块或者是地面. 否则方块就是边界方块. 每一次操作都要把边界方块拿掉

问多少次操作之后所有方块会消失

### 输入格式

第一行有一个整数 n($1\leq n\leq 10^5$)

第二行有 n 个整数$h_i$($1\leq h_i\leq 10^9$), 表示第 i 堆方块的数目

### 输出格式

输出使得所有方块消失的操作次数

### 样例输入

```input1
6
2 1 4 6 2 2
```

### 样例输出

```output1
3
```

### 样例解释

[点击查看图片](https://img.51nod.com/upload/000FBF24/08D2B51B62DE30780000000000000008.png)

### 数据规模

所有数据保证 $1\leq n \leq 10^5, 1 \leq h_i\leq 10^9$

### 解题思路

> DP

设 $f(x)$ 为第 $x$ 堆方块最少需要多少次才能清空, 则

$f(1)=f(n)=1$

$$
\begin{align}
  f(x)&=\min\{f(x-1)+1,f(x+1)-1,h(x)\}\\
      &=\min\{\min\{f(x-1)+1,h(x)\},\min\{f(x+1)+1,h(x)\}\}
\end{align}
$$

### 复杂度

$O(n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_573B CodeForces/573B/0.cpp %}

</details>
