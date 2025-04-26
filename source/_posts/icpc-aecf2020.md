---
title: VP记录 - 2020 ICPC Asia EC-final
author: "Tifa & Foi"
coauthor:
  - Foi
categories:
  - 算法竞赛
  - 题解
  - ICPC
tags:
  - 算法竞赛
  - 题解
  - ICPC
  - DP
  - 数学
  - 字符串
  - 线性代数
  - Gauss消元
  - 数据结构
  - 图论
  - 最短路
  - 模拟
  - BFS
  - 二分
  - 三分
  - 数论
  - 计算几何
date: 2022-05-10 19:07:57
---

[比赛链接](https://codeforces.com/gym/103069)

<!-- more -->

## 题目概览

| 题号 | 标题                   | 做法          |
| ---- | ---------------------- | ------------- |
| A    | Namomo Subsequence     | DP            |
| B    | Rectangle Flip 2       |               |
| C    | Random Shuffle         | Gauss 消元    |
| D    | City Brain             | 最短路 + 三分 |
| E    | Tube Master III        |               |
| F    | Rooks                  | (签到)        |
| G    | Prof. Pang's sequence  |               |
| H    | Prof. Pang Earning Aus |               |
| I    | Plants vs Zombies      | 二分          |
| J    | Circle                 | 计算几何      |
| K    | Allin                  | 模拟          |
| L    | Square                 | 数学 (签到)   |
| M    | Fillomino              | 构造          |

[官方题解](https://www.zhihu.com/question/450271220/answer/1841779678)

{% pdf /archives/icpc-aecf2020/problems.pdf 600px %}

## A - Namomo Subsequence

### 题意简述

统计给定字符串 $s$ 中形如 `ABCDCD` 的子串个数

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/A.cpp %}

## B - Rectangle Flip 2

### 题意简述

给定 $n\times m$ 的网格, 有若干次操作, 每次操作均为删去一个格子并询问剩下个格子构成多少个矩形

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/B.cpp %}

## C - Random Shuffle

### 题意简述

根据 `shuffle` 后的数组来计算出随机数种子

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/C.cpp %}

## D - City Brain

### 题意简述

给定一个边权为 1 的简单无向图, 可以选择若干条边, 将第 $i$ 的选择的边的权值变为 $\frac{1}{a_i}$, 其中 $a_i$ 为正整数, 可任意选取, 只需保证 $\sum a_i=k$, 问对两对给定的起讫点的最短路和的最小值

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/D.cpp %}

## E - Tube Master III

### 题意简述

Slitherlink, 连边时有代价, 问最小代价

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/E.cpp %}

## F - Rooks

### 题意简述

在 $n\times m$ 的网格上放若干 Rooks, 一对 Rooks 会相互攻击当且仅当

- 分属不同阵营
- 在一条直线上
- 中间没有其他 Rooks

问哪些 Rooks 会被攻击

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/F.cpp %}

## G - Prof. Pang's sequence

### 题意简述

给定数列 $\{a_n\}$, 若干次询问, 每次询问一段区间中 **数的种类为奇数** 的子区间个数

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/G.cpp %}

## H - Prof. Pang Earning Aus

### 题意简述

有三种物品 $A$, $B$, $C$, $B$ 和 $C$ 最多分别有 $n_b$, $n_c$ 个, 每次交易可以用一个物品 $i$ 换取 $k_{ij}$ 个物品 $j$, ($i,j=A,B,C$, $i\ne j$), 初始只有 1 个 $A$, 问经过若干次交易后最多可获得多少个 $A$

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/H.cpp %}

## I - Plants vs Zombies

### 题意简述

有 $n$ 个僵尸, 第 $i$ 个僵尸会在 $t_i$ s 时出现在第 0 格, 每秒所有存活的僵尸均向前移动 $V$ 格, 受到经过的这 $V$ 格 (不含起始点) 中所有水草的攻击, 之后受到前方的豌豆攻击 (已死亡的僵尸不会受到攻击), 问每个僵尸会在什么时候死亡 (血量不超过 0)

### 解题思路

二分

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/I.cpp %}

## J - Circle

### 题意简述

计算以 $r$ 为半径, 能覆盖住给定凸包的圆的圆心构成的面积

### 解题思路

显然是以凸包顶点为圆心, $r$ 为半径的圆的面积交

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/J.cpp %}

## K - Allin

### 题意简述

德州扑克, 问是否必胜

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/K.cpp %}

## L - Square

### 题意简述

对给定的数列 $\{a_n\}$ 求 $\prod_{i=1}^nt_i$ 的最小值, 其中 $t_ia_it_{i+1}a_{i+1}$, $\forall i=1,2,...,n-1$

### 解题思路

考虑单个素因子 $p$, 设 $p^{\alpha_i}\mid a_i$, $p^{\alpha_i+1}\mid a_i$, 则答案显然为

$$
p^{\min\left\{n-\sum_{i=1}^n(\alpha_i\bmod 2),\sum_{i=1}^n(\alpha_i\bmod 2)\right\}}
$$

然后对每个素因子的答案乘起来就行了

### 复杂度

$O(n\log^2{m})$, 其中 $m$ 为 $\{a_n\}$ 的最大值

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/L.cpp %}

## M - Fillomino

### 题意简述

给定 $n\times m$ 的循环网格, 要求将网格划分成三个给定大小连通块, 且连通块必须包含指定的一个格子

### 解题思路

### 复杂度

### 代码参考

{% icodeweb blog lang:cpp icpc-aecf2020/M.cpp %}
