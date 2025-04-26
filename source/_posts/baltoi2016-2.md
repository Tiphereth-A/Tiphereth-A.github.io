---
title: "题解 - [BalticOI 2016 day1] [Luogu P4675] [LOJ 2781] Park"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - BalticOI
  - 洛谷
  - LOJ
  - 数据结构
  - 并查集
  - 离线
date: 2018-06-09 21:23:48
---

题目链接

- [Luogu P4675](https://www.luogu.com.cn/problem/P4675)
- [LOJ 2781](https://loj.ac/p/2781)

<!-- more -->

## 原始题面

### 题目描述

In the capital of Byteland, there is a fenced park whose area is a rectangle. The trees and the visitors in the park are represented as circles.

There are four entrances in the park, one in each corner (1 = bottom-left, 2 =bottom-right, 3 = top-right, 4 = top-left). The visitors can enter and exit the park only through the entrances.

Visitors can enter and exit the park when they touch both sides of a corner of the corresponding entrance. Visitors can move freely in the park, but they cannot overlap any of the trees or the fence.

Your task is to calculate for each visitor, given the entrance they will enter the park,through which entrances they can exit the park.

### 输入格式

The first input line contains two integers $w$ and $h$ : the number of trees in the park and the number of visitors.

The second input line contains two integers $w$ and $h$ : the width and the height of the park area. The bottom-left corner is $(0,0)$, and the top-right corner is $(w,h)$.

After this, there are lines that describe the trees. Each line contains three integers, $x,y$ and $r$ : the center of the tree is $(x,y)$ and its radius is $r$. The trees do not overlap each other or the fence.

Finally, there are $m$ lines that describe the visitors. Each line contains two integers $r$ and $e$ : the radius of the visitor and the entrance they will enter the park.

In addition, no tree overlaps a square area of $2k\times2k$ in each corner, where $k$ is the radius of the largest visitor.

### 输出格式

You should output for each visitor a single line containing the entrances through which they can exit the park, in sorted order without spaces in between.

### 样例 #1

#### 样例输入 #1

```input1
5 3
16 11
11 8 1
6 10 1
7 3 2
10 4 1
15 5 1
1 1
2 2
2 1
```

#### 样例输出 #1

```output1
1234
2
14
```

### 提示

Two objects touch if they have one common point. Two objects overlap if they have more than one common point.

#### 样例解释

The following figure shows the entrance areas and possible routes for each visitor:

![](1.webp)

#### Subtasks

In all subtasks $4k\leq w,h\leq10^9$ where $k$ is the radius of the largest visitor.

##### Subtask 1 (27 points)

- $1\leq n\leq2000$

- $m=1$

##### Subtask 2 (31 points)

- $1\leq n\leq200$

- $1\leq m\leq10^5$

##### Subtask 3 (42 points)

- $1\leq n\leq2000$

- $1\leq m\leq10^5$

## 题意简述

给一个矩形, 矩形内部有若干障碍, 游客可以从矩形的四角进出, 游客可以在不碰到障碍的前提下在矩形内任意活动, 游客和障碍均为圆, 每次询问给出游客的直径和入口, 问游客可以从哪些地方出去

## 解题思路

不难发现我们可以考虑离线, 按直径升序排序, 这样我们就可以把游客直径的增加转为障碍直径的增加

接下来的思路就类似 NOIP2017 的奶酪, 考虑并查集, 若障碍相切或相交就合并, 之后考虑矩形的边界是否在同一集合即可

## 复杂度

$O(m(\log m+\alpha(n))+n^2)$

## 代码参考

{% icodeweb blog lang:cpp baltoi2016-2/std.cpp %}
