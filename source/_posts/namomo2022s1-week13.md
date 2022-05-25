---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 13)
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 代码源
  - CodeForces
  - BZOJ
  - POI
  - 数学
  - 图论
  - 数据结构
  - 二分
  - 双指针
  - DP
  - 搜索
  - DFS
  - 概率DP
  - 换根DP
  - 树
  - RMQ
  - ST表
  - 期望
  - 二分图
  - 最小生成树
  - 矩阵树定理
date: 2022-05-21 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.05.21-2022.05.27)

<!-- more -->

## 序列中 ab 的个数 (CF908D)

[题目链接](https://oj.daimayuan.top/problem/915)

5 s, 1024 MB

### 题目描述

给三个整数$k,pa,pb$, 最初有一个空序列,每一秒都可以执行以下操作, 以$pa$ $/$ $(pa+pb)$的概率将$a$添加到末尾或者以$pb$ $/$ $(pa+pb)$的概率将$b$添加到末尾, 一旦至少出现 k 个子序列$ab$, 就停止操作, 求最终子序列$ab$的期望次数, 输出一个整数$mod$ $(1e9+7)$

### 输入格式

一行输入三个整数$k,pa,pb$

### 输出格式

一个数, 表示答案

### 样例 1 输入

```input1
3 1 4
```

### 样例 1 输出

```output1
370000006
```

### 样例 2 输入

```input2
1 1 1
```

### 样例 2 输出

```output2
2
```

### 数据规模

所有数据保证 $1 \le k \le 1000 ,1 \le pa,pb \le 1e6$

### 解题思路

> 概率 DP

设 $f(x,y)$ 表示有 $x$ 个 `a`, 且有 $y$ 个子串 `ab` 时的概率, 则

$$f(x,y)=\frac{p_a}{p_a+p_b}f(x-1,y)+\frac{p_b}{p_a+p_b}f(x,y-x)$$

另外, 若 $x+y>k$, 则期望应为 $\sum_{i=0}^{\infty}(\frac{p_a}{p_a+p_b})^i\frac{p_b}{p_a+p_b}(x+y+i)$

然后倒着推即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_908D CodeForces/908D/0.cpp %}

</details>

## 谁才是最终赢家?

[题目链接](https://oj.daimayuan.top/problem/931)

1 s, 256 MB

### 题目描述

小明和小红经常玩一个博弈游戏. 给定一个 $n \times n$ 的棋盘, 一个石头被放指定位置. 他们轮流移动石头. 每一回合, 选手只能把石头向上, 下, 左, 右四个方向移动一格, 并且要求移动到的格子之前不能被访问过. 谁不能移动石头了就算输

假如小明先移动石头, 而且两个选手都以最优策略走步, 问最后谁能赢？

如果小明赢则输出 `Alice`, 否则输出 `Bob`

### 输入格式

第一行一个整数 $n$,表示一个 $n \times n$ 的棋盘

第二行两个整数 $x, y$ 表示起点的位置

### 输出格式

一行一个字符串

### 样例输入

```input1
2
1 1
```

### 样例输出

```output1
Alice
```

### 数据限制

$1 \le n \le 10000, 1 \le x, y \le n$

### 解题思路

>

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## 矩阵游戏 (BZOJ4766)

[题目链接](https://oj.daimayuan.top/problem/956)

1 s, 1024 MB

### 题目描述

小$s$正在玩一个游戏: 他有一个长为$N$, 宽为$M$的棋盘, 其中有一些格子是黑色的 (其余的格子是白色的)

每次操作他可以选择一个长度和宽度均大于$1$的矩形区域, 如果其中 3 个角落的格子是黑色的, 那么他可以把剩余那个角落的白色格子涂成黑色

试求出有多少种不同的长为$N$, 宽为$M$的棋盘, 满足小$s$可以通过有限次操作把整个棋盘变成黑色, 并且黑色格子个数最少. 两个棋盘不同当且仅当存在一个格子在两个棋盘中的颜色不同

你只需要输出这个数字对$998244353$取模后的结果

### 输入格式

第一行一个正整数$T$, 表示数据组数. 对于每组测试数据, 第一行输入两个正整数$N$和$M$

数据范围: 对于所有数据, 满足$1 \leq T \leq 100$, $1 \leq N \leq 100$, $1 \leq M \leq 100$

### 输出格式

对于每组数据, 输出一行一个整数表示答案

### 样例输入

```input1
2
1 1
2 2
```

### 样例输出

```output1
1
4
```

### 解题思路

> 矩阵树定理

题目所求等价于 $K_{n,m}$ 的最小生成树个数, 即 $m^{n-1}n^{m-1}$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:BZOJ_4766 BZOJ/4766/0.cpp %}

</details>

## 最大化深度和 (POI2008 STA-Station)

[题目链接](https://oj.daimayuan.top/problem/921)

1 s, 1024 MB

### 题目描述

给定一个 $n$ 个点的树, 请求出一个结点, 使得以这个结点为根时, 所有结点的深度之和最大, 输出最大的深度之和即可

**注意**: 根的深度为 $1$

### 输入格式

第一行有一个整数, 表示树的结点个数 $n$

接下来 $(n−1)$ 行, 每行两个整数 $u, v$, 表示存在一条连接 $u, v$ 的边

### 输出格式

一个正整数, 表示最大的深度之和

### 样例输入

```input1
8
1 4
5 6
4 5
6 7
6 8
2 4
3 4
```

### 样例输出

```output1
28
```

### 数据规模

$0 \leq n \leq 10^6$. 即可能存在空树

$1 \leq u, v \leq n$, 保证给出的是一棵树

### 解题思路

> 换根 DP

典中典, 设 $f(x)$ 是以 $x$ 为根时的结果, 先随便取个根 $r$ DFS 出结果, 然后

$$f(x)=f(y)-s(x)+n-s(x)$$

其中

- $s(x)$ 代表以 $r$ 为根时 $x$ 的子树大小
- $y$ 是以 $r$ 为根时 $x$ 的父结点

### 复杂度

$O(n)$

### 代码参考 (洛谷 P3478)

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_3478 Luogu/3478/0.cpp %}

</details>

## 稳定数组 (CF1547F)

[题目链接](https://oj.daimayuan.top/problem/923)

2 s, 1024 MB

### 题目描述

给定 $n$ 个正整数 $a_1,a_2,\dots ,a_n$, 每次操作对所有的 $i,1\leq i \leq n$,令 $a_i=gcd(a_i,a_{(i+1)\% n})$, 求最少执行多少次操作, 使得 $a_1=a_2=\dots =a_n$

### 输入格式

第一行一个正整数 $n$

第二行 $n$ 个正整数 $a_1,a_2,\dots ,a_n$

### 输出格式

一个非负整数, 表示最少操作数

### 样例输入

```input1
4
16 24 10 5
```

### 样例输出

```output1
3
```

### 数据规模

$2\leq n \leq 10^6$

$1\leq a_i \leq 10^6$

### 解题思路

> RMQ + 二分/双指针

这里写的 ST 表 + 二分, 因为好写

要注意因为要断环成链所以要开 2 倍空间

### 复杂度

$O(n\log^2 n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:CodeForces_1547F CodeForces/1547F/0.cpp %}

</details>
