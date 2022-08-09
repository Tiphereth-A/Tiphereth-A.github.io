---
title: "题解 - [Luogu P5177] 签到"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - 位运算
  - 异或
date: 2021-06-03 14:02:01
---

强烈谴责这种起无意义标题的做法

[题目链接](https://www.luogu.com.cn/problem/P5177)

<!-- more -->

## 原始题面

### 题目描述

求 $\sum_{i=1}^n \sum_{j=1}^n i \ xor \ j \in [\min(i,j),\max(i,j)]$

由于答案可能过大, 输出答案对$10^9+7$取模的值

### 输入输出格式

#### 输入格式

第一行, 一个整数$T$, 为数据组数. 下面$T$行, 每行一个整数$n$

#### 输出格式

对于每行数据, 输出答案

### 输入输出样例

#### 输入样例 #1

```input1
3
10
100
1000
```

#### 输出样例 #1

```output1
20
2634
325502
```

### 说明

第一组样例解释: 符合题意的$(i,j)$有$20$对

```plaintext
i=1 j=3 i^j=2
i=1 j=5 i^j=4
i=1 j=7 i^j=6
i=1 j=9 i^j=8
i=2 j=6 i^j=4
i=2 j=7 i^j=5
i=2 j=10 i^j=8
i=3 j=1 i^j=2
i=3 j=6 i^j=5
i=3 j=7 i^j=4
i=3 j=10 i^j=9
i=5 j=1 i^j=4
i=6 j=2 i^j=4
i=6 j=3 i^j=5
i=7 j=1 i^j=6
i=7 j=2 i^j=5
i=7 j=3 i^j=4
i=9 j=1 i^j=8
i=10 j=2 i^j=8
i=10 j=3 i^j=9
```

对于 27%的数据, $T\le 5, n \le 1000$

对于 54%的数据, $T\le 20, n \le 5 \times 10^5$

对于 90%的数据, $T\le 10^5, n \le 10^{18}$

最后一个点, $T=3\times 10^6 \ ,\ n\le 10^{18}$

## 解题思路

首先规范一些记号, 题目要求的是

$$\sum_{i=1}^n\sum_{j=1}^n[\min\{i,j\}\leqslant (i\oplus j)\leqslant \max\{i,j\}]$$

显然, 上式等价于

$$2\sum_{i=1}^n\sum_{j=1}^{i-1}[j\leqslant (i\oplus j)\leqslant i]$$

固定 $i$, 则 $j$ 能产生贡献当且仅当 $j$ 二进制最高位为 $i$ 二进制次高位

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P5177 Luogu/P5177/0.cpp %}

</details>
