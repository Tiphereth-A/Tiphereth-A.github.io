---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 5)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - CodeForces
  - 贪心
date: 2022-03-26 16:00:57
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.03.26-2022.04.01)

<!-- more -->

## 社交圈 (CF1060D)

[题目链接](https://oj.daimayuan.top/problem/606)

1 s, 256 MB

现在有 $N$ 个人,每一个人都不想周围的人坐得离他很近,所以在他的左边要放 $L_i$ 张空椅子,右边要放 $R_i$ 张空椅子, 同时每个人自己要坐 $1$ 张椅子

现在他们要坐成若干个圈,请问最少要放多少张椅子 (包括每个人自己坐的椅子)?

### 输入格式

第 $1$ 行一个整数 $N$

第 $2$ 行至第 $N+1$ 行每行两个整数 $L_i$ 和 $R_i$

### 输出格式

一个整数, 表示最少需要的椅子数量

### 样例输入

```input1
4
1 2
2 1
3 5
5 3
```

### 样例输出

```output1
15
```

### 数据规模

$1 \leq N \leq 1 \times 10^5$

$0 \leq L_i,R_i \leq 1\times10^9$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1060D CodeForces/1060D/0.cpp %}

</details>

## 区间和

[题目链接](https://oj.daimayuan.top/problem/609)

1 s, 512 MB

### 题目描述

小红有一个秘密的数组 $A$, 你知道这个数组 $A$ 的长度是 $N$. 小红会给你 $Q$ 个提示, 第 $i$ 个提示是告诉你数组 $A$ 中 $L_i$ 到 $R_i$ 连续元素的区间和. 问你能否根据小红的这 $Q$ 个提示知道数组 $A$ 中所有元素的和? 如果能, 输出 Yes; 否则, 输出 No

### 输入格式

第一行两个整数 $N$ 和 $q$, 接下来有 $Q$ 行, 每行两个整数 $L_i$ 和 $R_i$

### 输出格式

Yes 或 No, 表示能不能

### 样例输入

```input1
4 3
1 3
1 2
2 3
```

### 样例输出

```output1
No
```

### 数据规模

$1\leq N\leq 2 \times 10^5$

$1\leq Q\leq \min(2 \times 10^5,\frac{N(N+1)}{2})$

$1\leq L_i\leq R_i\leq N$

$(L_i, R_i)\neq (L_j, R_j)(i\neq j)$

### 解题思路

不难发现给出的区间相当于是 $S_{R_i}-S_{L_i-1}$, 然后问能否求出 $S_n-S_0$

不难发现就是建图然后判 $n$ 和 $0$ 是否连通即可

### 复杂度

$O(n\alpha (n))$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Daimayuan_609 Daimayuan/609/0.cpp %}

</details>

## 选数 2 ([40th Petrozavodsk Programming Camp, Winter 2021, day 1, M](https://qoj.ac/problem/862))

[题目链接](https://oj.daimayuan.top/problem/618)

1 s, 1024 MB

### 题目描述

有$N$个数, 小 t 准备在这$N$个数中选出若干个.满足这些数的最大值 小于等于 这些数的平均值的 $k$ 倍

小 t 想让自己选的数的个数尽可能多, 试求出有多少数字是不可能被小 t 选到的

我们设$M$为最多能选出的数的个数, 一个数字不可能被选到 当且仅当不出现在任何一个选出$M$个数的方案之中

### 输入格式

第一行一个正整数$N$ 表示数的个数

接下来一行$N$个正整数, 分别表示这$N$个数, 两个数字之间用空格隔开

最后一行两个正整数$p$和$q$, 表示$k$,($k = \frac{p}{q}$ 且 $k > 1$)

### 输出格式

第一行输出$M$, 表示不可能被选到的数的个数

接下来一行输出$M$个正整数, 分别表示不可能被选到的数字在原序列中的下标, 并按升序排序. 两个数字之间用空格隔开

### 数据范围

对于所有数据, 满足$1 \leq n \leq 2 \cdot 10^5$, $0 \leq a_i \leq 10^9$, $1 \leq q < p \leq 1000$
提示

有些做法看起来很对, 但是实际上是不太对的. 感觉可以尝试证明一下再写

### 样例输入 1

```input1
4
1 2 3 4
3 2
```

### 样例输出 1

```output1
0
```

### 样例解释

在样例一中, 我们最多选出 3 个数字. 而对于任何一个数字, 都存在一个选出 3 个数字的方案包含它, 于是没有不可能被选到的数字

### 样例输入 2

```input2
5
1 15 2 5 1
2 1
```

### 样例输出 2

```output2
1
2
```

### 样例输入 3

```input3
5
1 2 3 1000 10000
4 3
```

### 样例输出 3

```output3
2
4 5
```

## 数组划分

[题目链接](https://oj.daimayuan.top/problem/665)

1 s, 256 MB

### 题目描述

给定 $n$ 个整数, 将其划分为恰好 $k$ 个子数组, 求对每个子数组求和后按与运算的最大值

### 输入格式

第一行, 包含两个整数 $n,k$

### 输出格式

输出一行, 表示求和后与运算的最大值

### 样例输入

```input1
3 2
1 2 3
```

### 样例输出

```output1
3
```

### 说明

只有两种情况:

1. $[1,2],[3]$, 答案为 $(1+2)\&3=3$
1. $[1],[2,3]$, 答案为 $1\&(2+3)=1$

所以答案为 $3$

### 数据限制

对于 $100\%$ 的数据, 保证 $1\leq k\leq n \leq 100,0\leq a_i\leq 2^{50}$

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## namonamo

[题目链接](https://oj.daimayuan.top/problem/678)

3 s, 512 MB

### 题目描述

dls 桌面上的两个小女孩除了喜欢亲亲以外, 还喜欢一起共用一副耳机听歌

一天, 她们正在听她们最喜欢的歌, 一首歌的歌词可以看着一个只包含小写字母的字符串, 保证字符串的长度为偶数

不幸的是, 她们的 eirpods 是拼夕夕九块九包邮的, 发生了一些神奇的故障, 使得对于每个字母, 恰好只有一个人能够听到

在一首歌放完后, 她们一边抱怨耳机的质量, 同时惊奇地发现, 她们两个人所听到的字母各自组成的字符串完全相同

给定一首歌的歌词, 判断这种事情是否可能发生

形式化题意: 给定一个长度是偶数, 仅有小写字母构成的字符串, 判断是否能被分成两个完全相同的子序列

### 输入格式

第一行一个正整数 $T$, 表示数据组数

接下来每一行一个字符串 $S$, 表示歌词

### 输出格式

输出共 $T$ 行, 每行一个字符串 possible 或 impossible, 表示该组数据的答案

### 样例输入

```input1
5
aabb
abba
namonamo
arqmpfvvbtltlhufznkldkurrazmgebfxeamrewn
aacfcfqqsmksimkoioeertbrtbhphnpnggddjjll
```

### 样例输出

```output1
possible
impossible
possible
impossible
possible
```

### 样例分析&数据范围

对于第一组样例, 一种可能的故障情况如下:

- 第一个小女孩听到 a
- 第二个小女孩听到 a
- 第一个小女孩听到 b
- 第二个小女孩听到 b

对于第三组样例, 一种可能的故障情况如下:

- 第一个小女孩听到前 $4$ 个字母
- 第二个小女孩听到后 $4$ 个字母

#### 数据范围

对于 $100\%$ 的数据, $T=21,|N|\le 40$

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 体育节

[题目链接](https://oj.daimayuan.top/problem/668)

1 s, 256 MB

### 题目描述

学生会正在为体育节的接力赛做准备. 学生会由 $n$个成员组成, 他们将在比赛中一个一个地跑, 第 $i$ 个人的速度是 $s_i$, 第 $i$次接力会产生一个差异值 $d_i$, 它的值是前 $i$个参与接力赛的人的速度最大值与最小值的差, 也就是说, 我们假设第 $i$个参与比赛的人的速度是 $a_i$, 那么 $d_i = max(a_1, a_2,..., a_i) - min(a_1, a_2,..., a_i)$. 现在你可以任意安排参加比赛的人的顺序, 一个人只能参与一次, 且每个人都必须参与, 请你求出 $d_1 + d_2 + ... + d_n$的最小值

### 输入格式

第一行输入一个正整数 n, 第二行输入 $i$个整数代表 $a_i$

### 输出格式

输出一个整数, 代表答案

### 样例输入

```input1
3
3 1 2
```

### 样例输出

```output1
3
```

### 数据规模

$1 \leq n \leq 2000$, $1 \leq s_i \leq 1e9$

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 测温

[题目链接](https://oj.daimayuan.top/problem/670)

1 s, 1024 MB

### 题目描述

某国进行了连续$n$天的温度测量, 测量存在误差, 测量结果是第$i$天温度在$[l_i,r_i]$范围内. 求温度不下降的最长**连续**天数

### 输入描述

第一行一个整数$n (1\leq n \leq 10^6)$

下面$n$行, 每行两个数$l_i, r_i (-10^9 \leq l_i\leq r_i\leq 10^9)$

### 输出描述

一行, 表示该段的长度

### 样例输入

```input1
6
6 10
1 5
4 8
2 5
6 8
3 5
```

### 样例输出

```output1
4
```

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>
