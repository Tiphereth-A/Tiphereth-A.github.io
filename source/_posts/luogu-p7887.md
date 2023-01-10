---
title: 题解 - [Luogu P7887]「MCOI-06」Existence of Truth
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - 数论
  - 逆元
  - 递推
date: 2021-10-05 23:23:44
---

[题目链接](https://www.luogu.com.cn/problem/P7887)

<!-- more -->

## 原始题面

### 题目描述

可能存在一个非负整数数序列 $a_1,a_2,\dots,a_n$ 使得 $0\le a_i<10^9+7$

给定 $x_1,x_2,\dots,x_n$, $y_1,y_2,\dots,y_n$, $z_1,z_2,\dots,z_n$, 已知对于 $1\le i\le n$ 满足:

$$
x_i\left(\sum_{j=1}^ia_j\right)+y_i\left(\sum_{j=i}^na_j\right)\equiv z_i\pmod{10^9+7}
$$

求 $a_1,a_2,\dots,a_n$

### 输入输出格式

#### 输入格式

> **本题有多组数据**

第一行一个正整数 $T$, 表示表示数据的组数. 对于每一组数据:

第一行一个正整数 $n$

接下来 $n$ 行, 每行三个正整数 $x_i,y_i,z_i$

#### 输出格式

对于每一组数据, 依次输出:

第一行一个非负整数 $k$, 为合法解数量

如果 $k=1$, 第二行输出 $n$ 个非负整数, 依次为 $a_1,a_2,\dots,a_n$

### 输入输出样例

#### 输入样例 #1

```input1
2
3
3 1 9
2 2 16
1 3 15
6
3 6 246
5 7 283
2 7 179
4 6 214
8 7 337
3 5 151
```

#### 输出样例 #1

```output1
1
1 2 3
1
8 8 0 6 7 8
```

#### 说明

##### 数据规模与约定

> **本题采用捆绑测试**

- Subtask 1 (10 pts): $n=1$
- Subtask 2 (19 pts): $\sum n\le100$
- Subtask 3 (19 pts): $x_i=y_i=1$
- Subtask 4 (22 pts): 保证有**唯一解**
- Subtask 5 (30 pts): 无特殊限制

对于所有数据:

- $1\le n,\sum n\le 2\times10^5$;
- $1\le x_i,y_i<10^9+7$;
- $0\le z_i<10^9+7$

## 解题思路

令

- $A_0=0$
- $A_n=\sum_{i=1}^na_i$
- $Y_i=-y_ix_i^{-1}$
- $Z_i=z_ix_i^{-1}$

则原式变为

$$
x_iA_i+y_i(A_n-A_{i-1})\equiv z_i\pmod{10^9+7}
$$

有

$$
A_i\equiv Z_i+Y_i(A_n-A_{i-1})\pmod{10^9+7}
$$

不难观察出 $\exists \{Z'_n\},\{Y'_n\}$ 使得

$$
A_i=Z'_i+Y'_iA_n
$$

顺次递推求出 $\{Z'_n\}$, $\{Y'_n\}$ 之后求出 $\{A_n\}$, $\{a_n\}$ 即可

另外注意由 $A_n=Z'_n+Y'_nA_n$ 来判断解的个数

## 时间复杂度

$O(n+\log p)=O(n)$, 其中 $p=1e9+7$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P7887 Luogu/P7887/0.cpp %}

</details>
