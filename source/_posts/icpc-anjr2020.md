---
title: 题解 - 2020 ICPC 亚洲区域赛(南京)
categories:
  - 算法竞赛
  - 题解
  - ICPC
tags:
  - 算法竞赛
  - 题解
  - ICPC
  - 数学
  - 数论
  - 互素/互质
  - 概率
  - 期望
  - 三分
  - 排序
  - 打表
  - DP
  - 树形DP
  - 构造
  - 抽屉原理
date: 2020-12-20 20:46:33
---

[比赛链接](https://ac.nowcoder.com/acm/contest/10272)

<!-- more -->

## 题目概览

| 题号[^1] | 标题[^2]                          | 做法         |
| -------- | --------------------------------- | ------------ |
| A        | Ah, It's Yesterday Once More      | 构造         |
| \*B      | Baby's First Suffix Array Problem |              |
| \*C      | Certain Scientific Railgun        |              |
| \*D      | Degree of Spanning Tree           |              |
| E        | Evil Coordinate                   | 排序         |
| F        | Fireworks                         | 三分         |
| \*G      | Go                                |              |
| H        | Harmonious Rectangle              | 打表         |
| \*I      | Interested in Skiing              |              |
| \*J      | Just Another Game of Stones       |              |
| K        | K Co-prime Permutation            | 签到(找规律) |
| L        | Let's Play Curling                | 签到(找规律) |
| \*M      | Monster Hunter                    | 树形 DP      |

[^1]: 打\*的是还没写题解的题
[^2]: 带超链接的是找到了原题或原型

[官方题解](https://zhuanlan.zhihu.com/p/338249705)

{% pdf /archives/icpc-anjr2020/problems.pdf 600px %}

## A - Ah, It's Yesterday Once More

### 解题思路

我 TM 直接好家伙

## B - Baby's First Suffix Array Problem

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## C - Certain Scientific Railgun

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## D - Degree of Spanning Tree

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## E - Evil Coordinate

### 题意简述

有个机器人在二维平面上按给定指令走, 初始位置是 $(0,0)$, 指令包括如下四种:

- `U`: 从 $(x,y)$ 走到 $(x,y+1)$
- `D`: 从 $(x,y)$ 走到 $(x,y-1)$
- `L`: 从 $(x,y)$ 走到 $(x-1,y)$
- `R`: 从 $(x,y)$ 走到 $(x+1,y)$

在 $(m_x,m_y)$ 处有个坑, 机器人走到坑那里就动不了了, 问能否通过改变指令顺序使得机器人避开坑

### 解题思路

显然如果坑在 $(0,0)$ 或者是终点则避不开, 之后我们发现将相同方向排在一起的所有序列中至少有一个是满足条件的, 则枚举四种指令的全排列即可

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:E Gym/102992E/0.cpp %}

</details>

## F - Fireworks

### 题意简述

Kotori 可以花费时间 $n$ 制作一个烟花, 也可以花费时间 $m$ 点燃所有没点燃的烟花, 每个烟花完美绽放的概率为 $p$, 如果在某次点燃中有至少一个烟花完美绽放, 则 Kotori 停止, 问 Kotori 停止的最小时间期望

### 解题思路

假设最优解是制作了 $k$ 个烟花, 耗时为 $t$, 则有

$$
t=(nk+m)\left(1-(1-p)^k\right)+(t+nk+m)(1-p)^k
$$

解得

$$
t=\frac{nk+m}{1-(1-p)^k}
$$

不难发现 $t$ 是 $k$ 的严格单峰函数, 直接三分即可

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:F Gym/102992F/0.cpp %}

</details>

## G - Go

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## H - Harmonious Rectangle

### 题意简述

### 解题思路

> 沉迷搞 A 题导致没去打表, 难受

由抽屉原理, 如果 $m,n>9$ 则任意矩阵均满足要求, 结果为 $3^{mn}$

剩下的打表即可

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:H Gym/102992H/0.cpp %}

</details>

## I - Interested in Skiing

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## J - Just Another Game of Stones

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>

## K - K Co-prime Permutation

### 题意简述

找到 $1..n$ 的一个排列 $p_1,p_2,\dots,p_n$ 满足恰有 $k$ 个数 $i_1,i_2,\dots,i_k$ 满足

$$
(i_k,p_{i_k})=1
$$

### 解题思路

首先 $k$ 一定大于 $1$, 之后对 $2..k$ 做一次轮换即可(因为相邻两数一定互质, 且 $2$ 和 $k$ 互质当且仅当 $k$ 为奇数)

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:K Gym/102992K/0.cpp %}

</details>

## L - Let's Play Curling

### 题意简述

给定整数 $a_1,a_2,\dots,a_n$ 和 $b_1,b_2,\dots,b_m$, 令

$$
f(c)=\left|\left\{i\mid\forall j\in[1,m]\cap\mathbb{N},~|c-a_i|<|c-b_j|\right\}\right|
$$

求 $\displaystyle\max_{c\in\mathbb{R}} f(c)$

### 解题思路

先排序, 如果 $c$ 在 $b_i,b_{i+1}$ 之间, 则 $f(c)$ 最大值即为两数 2 之间夹的 $a$ 个数

所以 $O(m)$ 跑一遍即可

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:L Gym/102992L/0.cpp %}

</details>

## M - Monster Hunter

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

</details>
