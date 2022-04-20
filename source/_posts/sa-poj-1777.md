---
title: '题解 - [POJ 1777 等] Vivian''s Problem'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - POJ
  - UVa
  - 数学
  - 数论
  - Mersenne素数
  - 状态压缩
  - 状压DP
date: 2020-07-27 22:58:08
---
题目链接

- [POJ 1777](http://poj.org/problem?id=1777)
- [UVA 1323](https://vjudge.net/problem/UVA-1323/origin)

<!-- more -->

## 原始题面

### Description

The desire to explore the unknown has been a driving force in human history since the dawn of time. From the earliest documented accounts, ancient civilizations had explored the earth by sailing around. Early adventurers were motivated by religious beliefs, the desire conquest, the need to establish trade routes, and hunger for gold

You never know what will happen before the exploration. Neither does Bruce Lee. Someday, Mr.Lee entered a desolate tropical rainforest. And after several days' exploring, he came in front of a cave with something blinking in it. A beautiful girl named Vivian came out just before he tried to go into the cave. And Vivian told Mr. Lee that he must answer some questions before he entered the cave. As the best friend of Mr. Lee, you should help him to work it out

You will get $k$ positive integers $p_1, p_2 ... p_i ... p_k$ ($1 \leqslant i \leqslant k$) from Vivian. From these numbers, you can calculate $N, N=\prod_{i=1}^k p_i^{e_i}$ ($0 \leqslant ei \leqslant 10, \sum_{i=1}^ke_i\geqslant1, 1 \leqslant i \leqslant k$); you may decide the integers eias you wish. From one N, you can calculate corresponding $M$, which equals to the sum of all divisors of $N$. Now, you should tell Vivian whether or not there is an $M$ which is the power of $2$ ($1,2, 4, 8$, and $16$ … so on). If there's no $N$ can make M equal to the power of 2, tell Vivian "NO". If $M$ equals to some $2^x$, then show her the exponent ($x$). And if there are several $x$, only show her the largest one

### Input

Input contains several testcases. For each testcase, the first line contains only one integer $k$ ($0 < k \leqslant  100$), representing the number of positive integers. Then there are $k$ positive integers $p_1, p_2 ... p_i ... p_k$ ($1 < pi < 2^{31}, 1 \leqslant  i \leqslant  k$) in the second line, representing the given numbers

Input is terminated by end of file

### Output

For each testcase, you should output your result in a single line. If you can find N from the given numbers, output the largest exponent. Otherwise, output "NO". Extra spaces are not allowed

### Sample Input

```input1
1
2
3
2 3 4
```

### Sample Output

```output1
NO
2
```

### Source

Asia Guangzhou 2003

## 题意简述

给出一组数$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{k}$, 设$N=\prod_{i=1}^kp_i^{e_i}$, 其中$0\leqslant e_i\leqslant 10,i=1,2,...,k,~\sum_{i=1}^ke_i\geqslant 1$, $M$为$N$的因子和, 问是否有一组数$\def\enum#1{e_{ #1}}\enum{1},\enum{2},...,\enum{k}$使得$\log_2M\in\N$, 如果有, 输出可能的$x$中的最大值

## 解题思路

我们首先有这样一条定理

### <a href="#end-t-1" id="t-1">定理 - 1</a>

$$M=2^{\sum_{i=1}^sx_i}\iff N=\prod_{i=1}^s(2^{x_i}-1),~2^{x_i}-1~\text{is}~\text{mersenne}~\text{prime}, i=1,2,...,s$$

<a href="#t-1" id="end-t-1">$\Box$</a>

其正确性是显然的

由这条定理, 我们只需判断能否选取一组数$\def\enum#1{e_{ #1}}\enum{1},\enum{2},...,\enum{k}\in\{0,1\}$使得$N$为几个不同的Mersenne素数的乘积, 即在$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{k}$中选取一些数使得$N$为几个不同的Mersenne素数的乘积

我们注意到在$[1,2^{31}]$中只有$8$个Mersenne素数, 分别为$\def\enum#1{2^{ #1}-1}\enum{2},\enum{3},\enum{5},\enum{7},\enum{13},\enum{17},\enum{19},\enum{31}$

因为$N$与这些Mersenne素数之间的整除关系的状态种数较少, 所以这里我们可以考虑使用状压DP

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-27 22:58:08
 * @Description: POJ 1777, UVA 1323
 */
const int S = 1 << 8, mers_exp[] = {2, 3, 5, 7, 13, 17, 19, 31};

#define mers_pri(i) ((1 << mers_exp[i]) - 1)

int judge(int n) {
  int ans = 0;
  for (int i = 0; i < 8; ++i)
    if (n % mers_pri(i) == 0) {
      ans |= (1 << i);
      n /= mers_pri(i);
    }
  return n == 1 ? ans : 0;
}

bool f[S];
int  status[S];

int main() {
  int k;
  while (~scanf("%d", &k)) {
    memset(f, 0, sizeof(f));
    int cnt_status = 0;
    for (int i = 1, _; i <= k; ++i) {
      scanf("%d", &_);
      if (_ = judge(_)) f[status[++cnt_status] = _] = 1;
    }
    for (int i = 1; i <= cnt_status; ++i)
      for (int j = 0; j < S; ++j)
        if (f[j] && !(j & status[i])) f[j | status[i]] = 1;
    int ans = 0;
    for (int i = S - 1, _ = 0; i; --i, _ = 0)
      if (f[i]) {
        for (int j = 0; j < 8; ++j)
          if ((1 << j) & i) _ += mers_exp[j];
        ans < _ ? ans = _ : 0;
      }
    if (ans)
      printf("%d\n", ans);
    else
      puts("NO");
  }
}
```

</details>
