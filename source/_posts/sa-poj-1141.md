---
title: '题解 - [POJ 1141 等] Brackets Sequence'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - POJ
  - ZOJ
  - Ural
  - UVa
  - DP
  - 区间类DP
  - 记忆化搜索
date: 2020-07-25 22:14:38
---
题目链接

- [POJ 1141](https://poj.org/problem?id=1141)
- [ZOJ 1463](https://vjudge.net/problem/ZOJ-1463/origin)
- [UVa 1626](https://vjudge.net/problem/UVA-1626/origin)
- [Ural 1183](https://acm.timus.ru/problem.aspx?space=1&num=1183)

<!-- more -->

## 原始题面

Let us define a regular brackets sequence in the following way:

1. Empty sequence is a regular sequence
2. If S is a regular sequence, then (S) and [S] are both regular sequences
3. If A and B are regular sequences, then AB is a regular sequence

For example, all of the following sequences of characters are regular brackets sequences:

`(), [], (()), ([]), ()[], ()[()]`

And all of the following character sequences are not:

`(, [, ), )(, ([)], ([(]`

Some sequence of characters '(', ')', '[', and ']' is given. You are to find the shortest possible regular brackets sequence, that contains the given character sequence as a subsequence. Here, a string $a_1~a_2~...~a_n$ is called a subsequence of the string $b_1~b_2~...~b_m$, if there exist such indices $1 = i_1 < i_2 < ... < i_n = m$, that $a_j = b_{i_j}$ for all $1 \leqslant j \leqslant n$

### Input

The input file contains at most $100$ brackets (characters '(', ')', '[' and ']') that are situated on a single line without any other characters among them

### Output

Write to the output file a single line that contains some regular brackets sequence that has the minimal possible length and contains the given sequence as a subsequence

### Sample Input

```input1
([(]
```

### Sample Output

```output1
()[()]
```

### Source

Northeastern Europe 2001

## 题意简述

对一个字符串, 按如下规则定义**合法的括号序列**:

1. 空字符串为合法的括号序列
1. 若`A`为合法的括号序列, 则`(A)`, `[A]`也为合法的括号序列
1. 若`A`, `B`为合法的括号序列, 则`AB`也为合法的括号序列

给出由`(`, `)`, `[`, `]`构成的字符串, 添加尽量少的`(`, `)`, `[`, `]`使其变为合法的括号序列, 并输出结果

## 解题思路

一道区间类DP题, 我们这样考虑状态转移方程

记给定字符串$s$, $s_i$为其第$i$位的字符, $s_{i\to j}$为其第$i$位第$j$位构成的子串

设$f(i,j)$为: 使$s_{i\to j}$合法化所需插入的最少字符数

我们很容易能发现几个特例

1. 如果$i>j$, 子串不存在, 自然有$f(i,j)=0$
1. 如果$i=j$, 那么其必定需要最少需要$1$个字符完成合法化
1. 如果$s_i$和$s_j$能够配对的话, $f(i,j)=f(i+1,j-1)$

而一般情况下的$f(i,j)$, 我们可以将其拆分成两个子串分别计算再求和, 从而可以得出
$$f(i,j)=\min_{i\leqslant k\leqslant j}\{f(i,k)+f(k+1,j)\}$$

总结一下就是

$$f(i,j)=\begin{cases}
  0,&i>j\\
  1,&i=j\\
  f(i+1,j-1),&s_i, s_j~\text{are}~\text{matched}\\
  \displaystyle\min_{i\leqslant k< j}\{f(i,k)+f(k+1,j)\},&\text{otherwise}
\end{cases}$$

由于用循环来实现比较困难, 所以这里选用记忆化搜索的方式来实现

本题要求的不是输出$f(1,len_s)$而是合法化后的字符串, 所以我们要根据状态转移方程来做些许改造

1. 如果$i>j$, 子串不存在, 合法化后的字符串自然也不存在, 所以什么也不需要做
1. 如果$i=j$, 那么其必定需要最少需要$1$个字符完成合法化, 直接匹配并输出即可
1. 如果$s_i$和$s_j$能够配对的话, 用两边的字符把$s_{i+1\to j-1}$合法化的字符串夹在中间, 并输出
1. 一般情况下, 如果$f(i,j)=f(i,k)+f(k+1,j)$, 那么直接将$s_{i\to k}$和$s_{k+1\to j}$合法化的字符串拼接起来并输出即可

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-25 22:14:38
 * @Description: POJ 1141, ZOJ 1463, Ural 1183, UVA 1626
 */
const int N = 205;

int  f[N][N];
char str[N];

bool match(char a, char b) { return (a == '[' && b == ']') || (a == '(' && b == ')'); }

int dfs(int i, int j) {
  if (i > j) return f[i][j] = 0;
  if (i == j) return f[i][j] = 1;
  if (f[i][j] != 0x3f3f3f3f) return f[i][j];
  int ans = f[i][j];
  if (match(str[i], str[j])) ans = min(ans, dfs(i + 1, j - 1));
  _rep(k, i, j) ans = min(ans, dfs(i, k) + dfs(k + 1, j));
  return f[i][j] = ans;
}

void print(int i, int j) {
  if (i > j) return;
  if (i == j) {
    if (str[i] == '(' || str[i] == ')')
      printf("()");
    else
      printf("[]");
    return;
  }
  int _ = f[i][j];
  if (match(str[i], str[j]) && _ == f[i + 1][j - 1]) {
    putchar(str[i]);
    print(i + 1, j - 1);
    putchar(str[j]);
    return;
  }
  _rep(k, i, j) if (_ == f[i][k] + f[k + 1][j]) {
      print(i, k);
      print(k + 1, j);
      return;
    }
}

int main() {
  while (fgets(str + 1, N - 1, stdin)) {
    int l_min = 0x3f3f3f3f, len = strlen(str + 1);
    if (str[len]) {
      str[len] = '\0';
      --len;
    }
    _set_inf(f);
    dfs(1, len);
    print(1, len);
    putchar('\n');
  }
}
```

</details>
