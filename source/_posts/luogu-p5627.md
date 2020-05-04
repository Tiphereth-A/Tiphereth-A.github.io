---
title: "题解 - [Luogu P5627] 【AFOI-19】sum与prod"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - 数学
  - 快速幂
date: 2020-08-12 11:31:46
---

[题目链接](https://www.luogu.com.cn/problem/P5627)

<!-- more -->

## 原始题面

### 题目背景

SY 终于整理好了她凌乱的被子, 刚来到教室的她就收到了 QM 传来的一张字条.

To: Dear SY

$~~~~$ 你看看我昨晚梦到的式子, 解出来给你糖吃

From: Your QM

SY 自然是无法拒绝 $C_{6}H_{12}O_{6}$ 的诱惑啦, 不过她看到字条背面花里胡哨的式子时傻眼了. . 但是 SY 还是很想吃糖

### 题目描述

求

$$
\sum_{i=1}^{2^{n}}\log_{2}{(\prod_{j = 1}^{i}lowbit(j))}
$$

的结果

其中 $lowbit(x)$ 意指`x&(~x+1)`的结果

### 输入格式

一行, 一个整数 n

### 输出格式

一行, 一个整数, 为答案模 $10^9+7$ 的结果

### 输入输出样例

#### 输入 #1

```input1
2
```

#### 输出 #1

```output1
5
```

#### 输入 #2

```input2
5
```

#### 输出 #2

```output2
447
```

### 说明/提示

对于前 $20\%$ 的数据, 有 $\leq n \leq 60$

对于前 $50\%$ 的数据, 有 $\leq n \leq 10^4$

对于前 $100\%$ 的数据, 有 $\leq n \leq 2^{62}$

## 解题思路

容易得到, 原式即为

$$
\begin{aligned}
  &+0\\
  &+0+1\\
  &+0+1+2\\
  &+0+1+2+2\\
  &...\\
  &+0+1+2+2+...+\underbrace{k+k+...+k}_{k}+...+\underbrace n_1\\
\end{aligned}
$$

即 $n+(1+2^{n-1})(2^n-n-1)$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P5627 Luogu/P5627/0.cpp %}

</details>
