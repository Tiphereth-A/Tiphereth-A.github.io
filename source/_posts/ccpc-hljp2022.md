---
title: VP记录 - 2022 CCPC 黑龙江省赛
author: "Tifa & Foi"
coauthor:
  - Foi
categories:
  - 算法竞赛
  - 题解
  - CCPC
tags:
  - 算法竞赛
  - 题解
  - CCPC
  - 数据结构
  - 数学
  - 数论
  - 字符串
  - 模拟
  - 贪心
  - 图论
  - DP
  - 二分
  - 计算几何
  - Möbius反演
  - KMP
  - Hash
  - 可持久化线段树/主席树
  - 概率
  - 概率DP
  - 期望
  - 最短路
  - 树
  - 背包DP
  - 树状数组
  - 并查集
date: 2022-05-19 22:01:18
---

[比赛链接](https://codeforces.com/gym/103688)

<!-- more -->

## 题目概览

| 题号 | 标题                      | 做法              |
| ---- | ------------------------- | ----------------- |
| A    | Bookshelf Filling         | 二分              |
| B    | Lovely Fish               |                   |
| C    | Tree Division             | 贪心 + DP         |
| D    | Collision Detector        | 计算几何          |
| E    | Exclusive Multiplication  | Möbius 反演       |
| F    | 342 and Xiangqi           | 最短路            |
| G    | Chevonne's Necklace       | 背包              |
| H    | Kanbun                    | 模拟              |
| I    | Equal Sum Arrays          | 签到              |
| J    | JOJO's Happy Tree Friends |                   |
| K    | Monkey Joe                | 树状数组 + 主席树 |
| L    | Let's Swap                | KMP / Hash        |

{% pdf /archives/ccpc-hljp2022/problems.pdf 600px %}

## 官方题解

{% pdf /archives/ccpc-hljp2022/official-solutions.pdf 600px %}

## A - Bookshelf Filling

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/A.cpp %}

</details>

## B - Lovely Fish

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/B.cpp %}

</details>

## C - Tree Division

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/C.cpp %}

</details>

## D - Collision Detector

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/D.cpp %}

</details>

## E - Exclusive Multiplication

### 解题思路

不妨设 $b_i$ 无平方因子, 则所求即为

$$\sum_{i=1}^m\sum_{j=1}^mf(i,j)\frac{ij}{(i,j)^2}$$

其中

- $m=\max\{b_1,...,b_n\}$
- $f(i,j)=[i,j\in \{b_1,...,b_n\}]$

然后就是经典莫反, 可化为

$$\sum_{d=1}^mF(d)(\mu*\{n^{-2}\})(d)$$

其中

$$F(d)=\left(\sum_{i=1}^n b_i[d|b_i]\right)^2$$

### 复杂度

$O(n\log n)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/E.cpp %}

</details>

## F - 342 and Xiangqi

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/F.cpp %}

</details>

## G - Chevonne's Necklace

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/G.cpp %}

</details>

## H - Kanbun

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/H.cpp %}

</details>

## I - Equal Sum Arrays

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/I.cpp %}

</details>

## J - JOJO's Happy Tree Friends

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/J.cpp %}

</details>

## K - Monkey Joe

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/K.cpp %}

</details>

## L - Let's Swap

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-hljp2022/L.cpp %}

</details>
