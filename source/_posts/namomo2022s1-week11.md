---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 11)
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 代码源
  - HihoCoder
  - Codeforces
  - 数学
date: 2022-05-07 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.05.07-2022.05.13)

<!-- more -->

## 与 (HihoCoder 1076)

[题目链接](https://oj.daimayuan.top/problem/155)

1 s, 1024 MB

### 题目描述

给定 $n$ 和 $k$. 计算有多少长度为 $k$ 的数组 $a_1,a_2\dots, a_k$, 满足:

-$\sum_{i=1}^k a_i=n, a_i\geq 0$

- 对于任意的 $i=1,\dots,k-1$ 有 $a_i~\mathrm{AND}~a_{i+1}=a_{i+1}$. 其中 AND 是与操作

输出答案对 $10^9+7$ 取模的结果

### 输入格式

第一行两个整数 $k, n$

### 输出格式

一个整数, 表示答案

### 样例输入 1

```input1
4 2
```

### 样例输出 1

```output1
2
```

### 样例输入 2

```input2
1919 810
```

### 样例输出 2

```output2
501617298
```

### 数据规模

共 10 个测试点

测试点 $1, 2$ 满足 $n, k\leq 10$

测试点 $3, 4$ 满足 $n, k\leq 100$

测试点 $5, 6$ 满足 $n, k\leq 1000$

对于所有数据, 满足 $1\leq n, k\leq 10^4$

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 喵~喵~喵~

[题目链接](https://oj.daimayuan.top/problem/865)

1 s, 128 MB

### 题目描述

小 $C$ 养了 $n$ 只猫, 编号从 $1 - n$. 小 $C$ 不喜欢一次只给一头猫喂猫粮, 因此他选择一下喂很多只编号连续的猫, 并且每次喂的猫粮都是 不同种类 的. 现在有 $m$ 次操作, 每次操作给定 $op, \; l, \; r$

- 若 $op = 1$, 代表小 $C$ 会给编号为 $[l,r]$ 的猫进行一次投喂
- 若 $op = 2$, 代表一次询问, 请你回答出编号为 $[l,r]$ 的所有猫一共吃到了多少种猫粮

### 输入格式

第一行两个个数字 $n, \; m$

接下来有 $m$ 行, 每行 $3$ 个整数 $op, \; l , \; r$

### 输出格式

对于每次询问, 请输出 $1$ 行一个整数表示答案

### 样例输入

```input1
5 4
1 1 1
1 2 2
2 1 1
2 1 2
```

### 样例输出

```output1
1
2
```

### 数据规模

所有数据保证 $0\leq n, \, m\leq 100000, 1 \le l \le r \le n$

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 新年的问题 (数据加强版)

[题目链接](https://oj.daimayuan.top/problem/856)

1 s, 1024 MB

### 题目描述

给定一个 $n\times m$ 的矩阵, 要求在每列中恰好选择一个数, 并且这些数里面存在两个数在同一行, 要求使这 $m$ 个数的最小值最大, 输出该值

### 输入格式

第一行输入两个正整数 $n,m$

接下来 $n$ 行, 每行 $m$ 个正整数

### 输出格式

一个正整数

### 样例输入

```input1
2 2
1 2
3 4
```

### 样例输出

```output1
3
```

### 样例解释

$m=2$, 要求选择不超过 $2-1=1$ 行, 即只能选择一行, 选择第一行即 $1,2$, 最小值为 $1$, 选择第二行即 $3,4$, 最小值为 $3$, 所以答案为 $3$

### 数据范围

$2 < n , m \leq 2500$

数据保证所有出现的数不超过 $10^9$

- **进阶**: 二分做法优化输入后可以通过, 但不妨试试 $O(nm)$ 做法

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 删库

[题目链接](https://oj.daimayuan.top/problem/885)

1 s, 1024 MB

### 题目描述

有 $N$ 个字符串, 每一次操作可以任意选择一个字符串 T.(可以为空串并且不一定是题目所给的字符串) 然后考虑所有还没有被删除的字符串 S, 如果 T 是 S 的一个前缀(空串是任意串的前缀), 那么把它加入候选删除集合

但是每一次操作最多删除 $K$ 个字符串, 也就是说如果候选集合中字符串的数量大于 $K$, 那么什么也不会发生. 否则, 删除其中所有的字符串

求出最少需要多少次操作才能删掉所有的字符串

### 输入格式

第一行输入两个正整数 $N$ 和 $K$. 如题意所示

接下来 $N$ 行, 每一行输入一个仅包含小写英文字母的字符串

数据保证没有两个相同的字符串

对于所有数据 满足 $1 \leq N \leq 100$,$1 \leq K \leq 20$,$\sum{len} <= 3 * 10^5$. (所有字符串的长度之和)

### 输出格式

一行输出一个正整数, 表示最少需要多少次操作才能删除所有字符串

### 样例输入 1

```input1
4 2
a
abc
abd
b
```

### 样例输出 1

```input1
2
```

### 样例 1 解释

我们可以第一次操作选择 ab. 删掉 abc 和 abd

第二次操作选择空串. 将剩下的所有字符串删掉

### 样例输入 2

```input2
4 2
d
c
ab
a
```

### 样例输出 2

```output2
2
```

### 样例输入 3

```input3
5 3
please
remove
all
these
files
```

### 样例输出 3

```output3
3
```

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 不朴素的数列 (Bonus) (CF1254B2)

[题目链接](https://oj.daimayuan.top/problem/883)

1 s, 1024 MB

本题是 <https://oj.daimayuan.top/problem/882> 的加强版, 差别仅在于 $n$ 与 $S_i$ 的取值. 已使用红色字体标注题面中的区别

### 题目描述

关于序列 $\{S\}$ 定义 $f(S) = \gcd(S_1, S_2, \cdots, S_n)$

我们熟知 $\gcd$ 运算具有结合律, 即 $\gcd(a, b, c, \cdots) = \gcd(a, \gcd(b, c, \cdots))$, 可以轻松算出 $f(S)$

然而 Patricky 认为, 那些 $f(S) = 1$ 的序列太过朴素. 现在给定 $\{S\}$, 他希望您能用下面的操作修改 $\{S\}$ 使得 $f(S) \ge 2$:

- 选择 $i, i + 1\;(i \ne n)$, 将 $\langle S_i, S_{i + 1}\rangle$ 修改为 $\langle S_i - 1, S_{i + 1} + 1\rangle$
- 选择 $i, i + 1\;(i \ne n)$, 将 $\langle S_i, S_{i + 1}\rangle$ 修改为 $\langle S_i + 1, S_{i + 1} - 1\rangle$

试回答使得 $f(S) \ge 2$ 的 最小 操作次数, 或回答不可能

### 输入格式

输入包含两行, 第一行有一个整数 $n$, 表示 $\{S\}$ 的大小

接下来一行包含 $n$ 个用空格分隔的整数, 依次表示 $S_1, S_2, \cdots, S_n$

### 输出格式

输出使得 $f(S) \ge 2$ 的最小操作次数. 如果不可能, 则在一行中输出 $-1$

### 数据规模

-$1 \le n \le 10 ^ {\color{red}{6}}$ -$S_i \in \color{red}{[0, 10^6]}$ 但保证 $\displaystyle \sum_{i = 1} ^n S_i \ge 1$, 即元素不同时为 $0$

### 样例 1 输入

```input1
3
4 8 5
```

### 样例 1 输出

```output1
9
```

### 解释

$[4, 8, 5] \rightarrow^4 [0, 12, 5] \rightarrow^5 [0, 17, 0]$

### 样例 2 输入

```input2
4
0 5 15 10
```

### 样例 2 输出

```output2
0
```

### 样例 3 输入

```input3
6
1 2 3 4 5 6
```

### 样例 3 输出

```output3
2
```

### 解释

$[1, 2, 3, 4, 5, 6] \rightarrow [0, 3, 3, 4, 5, 6] \rightarrow [0, 3, 3, 3, 6, 6]$

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## 历法 (CF1389E)

[题目链接](https://oj.daimayuan.top/problem/913)

1 s, 1024 MB

### 题目描述

P 国的历法比较特殊, 每一年都有 $m$ 个月 , 每个月有 $d$ 天. 每个星期有 $w$ 天

每年的第一天也是一个星期的第一天

求出有多少对 $(x,y)$,$x < y$ 满足第 $y$ 个月的第 $x$ 天和第 $x$ 个月的第 $y$ 天在一个星期内是同一天

### 输入格式

第一行一个整数 $t$, 表示数据组数.$(1 \leq t \leq 10^3)$

接下来 $t$ 行, 每行输入三个整数 $m,d,w$, 表示序列的长度 $( 1 \leq m,d,w \leq 10^9 )$

### 输出格式

输出 $t$ 行, 每行一个整数, 表示满足要求二元对的数量

### 样例输入

```input1
5
6 7 4
10 7 12
12 30 7
1 1 1
3247834 10298779 625324
```

### 样例输出

```output1
6
9
5
0
116461800
```

### 解题思路

水题, 略

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1389E CodeForces/1389E/0.cpp %}

</details>

## 加加减减

[题目链接](https://oj.daimayuan.top/problem/918)

1 s, 512 MB

### 题目描述

给定一个长度为 $n$ 的数列 $\{A\}$

每次可以选择一个区间 $[l,r]$, 使这个区间内的数都加 $1$ 或者都减 $1$

请问至少需要多少次操作才能使数列中的所有数都一样, 并求出在保证最少次数的前提下, 最终得到的数列有多少种

### 输入描述

一行一个整数 $n(n\leq 10^6)$ 表示数组长度

一行 $n$ 个整数, 第 i 个数表示 $A_i(|A_i|在int范围内)$

### 输出描述

第一行输出最少操作次数 第二行输出最终能得到多少种结果

### 输入样例

```input1
4
1 1 2 2
```

### 输出样例

```output1
1
2
```

### 原题链接

[戳我](https://www.luogu.com.cn/problem/P4552)

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>
