---
title: 题解 - 2020 ICPC 江西省大学生程序设计竞赛
categories:
  - 程序设计
  - 题解
  - ICPC
tags:
  - 程序设计
  - 题解
  - ICPC
  - 算法
  - 数据结构
  - 数学
  - 搜索
  - 打表
  - 模拟
  - 数论
  - 计数
  - 组合数学
  - 容斥定理
  - 图论
  - 状态压缩
  - DP
  - 整除
  - 二分
  - 位运算
  - Möbius反演
  - 前缀和
  - 差分
  - Stirling数
  - 第二类Stirling数
  - 生成函数
  - Floyd算法
  - 分块
  - 自动机
  - 后缀自动机
  - 状压DP
  - DFS
  - 线段树
  - 树状数组
date: 2020-11-15 23:01:18
---

[比赛链接](https://ac.nowcoder.com/acm/contest/8827)

<!-- more -->

## 题目概览

| 题号[^1] | 标题[^2]                                                 | AC / total | 做法                   |
| -------- | -------------------------------------------------------- | ---------- | ---------------------- |
| A        | A Simple Math Problem                                    | 15 / 207   | Möbius 反演 / 容斥定理 |
| B        | Apple                                                    | 198 / 562  | 签到                   |
| \*C      | Charging                                                 | 9 / 157    | 线段树/树状数组 + 二分 |
| \*D      | Chinese Valentine's Day                                  | 0 / 195    | 后缀自动机             |
| E        | Color Sequence                                           | 29 / 231   | 位运算                 |
| F        | Magical Number                                           | 3 / 23     | 打表 + DFS             |
| G        | Mathematical Practice                                    | 39 / 64    | 组合数学               |
| H        | Sequence                                                 | 15 / 74    | 分块 / 线段树          |
| I        | Simple Math Problem                                      | 107 / 452  | 签到                   |
| J        | [Split Game](https://vjudge.net/problem/POJ-2311/origin) | 4 / 133    | 博弈论                 |
| K        | Travel Expense                                           | 33 / 280   | Floyd + 二分           |
| \*L      | WZB's Harem                                              | 9 / 97     | 状压 DP                |
| M        | Zoos's Animal Codes                                      | 205 / 241  | 签到                   |

[^1]: 打\*的是还没写题解的题
[^2]: 带超链接的是找到了原题或原型

[官方题解](official_solutions.zip)

{% pdf /archives/icpc-cjxp2020/problems.pdf 600px %}

## A - A Simple Math Problem

### 题意简述

$\forall x=\sum_{i=0}^la_i\cdot 10^i,~a_0,a_1,...,a_l\in[0,9]\cap\N$, 定义$F(x)=\sum_{i=0}^la_i$, 求
$$\sum_{i=1}^n\sum_{j=1}^i[(i,j)=1]F(j)$$

### 解题思路

> 你这咋还和 I 抢上名字了

官方题解是容斥定理, 不过我按 Möbius 反演板子题做的

$$
\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^i[(i,j)=1]F(j)&=\sum_{i=1}^n\sum_{j=1}^iF(j)\sum_{d\mid(i,j)}\mu(d)\\
  &=\sum_{d=1}^n\mu(d)\sum_{i=1}^{\lfloor\frac{n}{d}\rfloor}\sum_{j=1}^iF(jd)\\
  &=\sum_{d=1}^n\mu(d)\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}(n-j+1)F(jd)\\
  &=\sum_{d=1}^n\mu(d)\left((n+1)\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}F(jd)-\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}jF(jd)\right)\\
\end{aligned}
$$

令$g_n(d)=\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}F(jd)$, $h_n(d)=\sum_{j=1}^{\lfloor\frac{n}{d}\rfloor}jF(jd)$

则答案为$\sum_{d=1}^n\mu(d)((n+1)g_n(d)-h_n(d))$

预处理$\mu$, $g_n$, $h_n$即可

### 复杂度

$O(n\log n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:A misc/icpc-cjxp2020/A/0.cpp %}

</details>

## B - Apple

### 解题思路

签到题, 问$n$是否被$m$整除

## C - Charging

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## D - Chinese Valentine's Day

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## E - Color Sequence

### 题意简述

给一个长度为$n$的串, 其中第$i$位的颜色为$c_i$, 求有多少子串满足其上任意一种颜色出现次数均为偶数次

### 解题思路

注意到$c\leqslant 20$, 所以我们可以考虑对子串颜色情况进行状态压缩

令$f(l,r)=\bigoplus_{i=l}^r2^{c_i}$, 其中$\oplus$为异或运算

可知若串$[l,r]$满足条件, 则$f(l,r)=0$

又由异或的性质, 有$f(l,r)=f(1,l-1)\oplus f(1,r)$, 则
$$f(l,r)=0\iff f(1,l-1)=f(1,r)$$

所以我们可以对输入求前缀异或和, 若在求到某处时的结果不为$0$且 之前得出的结果中有$k$个和当前结果相等, 则答案直接加$k$即可, 若结果为$0$则需加$k+1$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:E misc/icpc-cjxp2020/E/0.cpp %}

</details>

## F - Magical Number

### 题意简述

能否恰好用$n$根火柴棍摆出满足如下条件的数$s$, 如果可以, 输出最大的数

令$s=\overline{a_1a_2...a_k}$, 其中$a_1,a_2,...,a_k\in[0,9]\cap\N$, **可以有前导零**, 要求
$$\forall i\in[1,k]\cap\N,~i\mid\overline{a_1a_2...a_i}$$

### 解题思路

首先若$n<2$则一定无解

- 如果不可以有前导零:
  <details open>
  <summary><font color='orange'>Show / Hide</font></summary>

  下面不考虑$s=0$的情况

  设$A_i=\overline{a_1a_2...a_i}$, 则$A_i=10A_{i-1}+a_i$

  设$A_i$满足条件, 令$a_i$取值构成的集合为$S_A(i)$, 不难证明
  $$|S_A(i)|\leqslant\left\lceil\frac{10}{i}\right\rceil$$

  所以满足条件的$A_i$个数必随着$i$的增加而先增加后减小

  容易验证满足条件的$A_i$有限

  </details>

- 如果可以有前导零

  情况稍微复杂一些, 但类似无前导零的情况

  首先我们注意到, 若$6\mid n$则一定有解($n\over6$个$0$即是一种情况)

  > 但是这题数据造弱了, 写成若$n\geqslant 140$则无解也能过

  其次, 若最后解为正数, 则解的前导零个数必不超过$8$

  接下来对这$8$种情况分别讨论即可

  > 官方题解给的是一共有$20456$个数满足条件, 最长的数为$3608528850358400786036725$

所以状态数不是很大, 直接 DFS 即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:F misc/icpc-cjxp2020/F/0.cpp %}

</details>

## G - Mathematical Practice

### 题意简述

在有$n$个元素的集合中有顺序地取$m$个子集, 问这$m$个子集中两两不相交的取法数

### 解题思路

- 正常做法

  不难发现题目等价于: 将至多$n$个不同的小球放到$m$个不同的盒子里, 允许盒子为空

  又等价于将$n$个不同的小球放到$m+1$个不同的盒子里, 允许盒子为空 (多出来的一个盒子用来装没选的球)

  所以答案就是$(m+1)^n$

- 猛男做法

  结合第二类 Stirling 数和排列数的定义不难推出答案为
  $$\sum_{i=0}^n\sum_{j=0}^i{i\brace j}\binom{n}{i}\binom{m}{j}j!\bmod998244353$$

  又
  $$x^i=\sum_{j=0}^i{i\brace j}\binom{x}{j}j!$$

  故答案为
  $$\sum_{i=0}^n\binom{n}{i}m^i=(1+m)^n$$

## H - Sequence

### 题意简述

维护序列$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 对其进行$m$次操作, 共两种:

1. `1 x y`: 将$a_x$修改为$y$
1. `2 x`: 询问以$a_x$为最小值的子串数

保证任意时刻$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$两两不同

### 解题思路

显然分块或者线段树, 我写的分块

块存最小值, 更新就是更新原数组和其所在块, 查询就是从$x$出发, 向左找第一个小于$a_x$的数$a_l$ (找不到就是$a_1$), 向右找第一个小于$a_x$的数$a_r$ (找不到就是$a_n$), 答案就是$(x-l+1)(r-x+1)$

不知道为啥有人就特殊处理全局最小和全局最大, 剩下的情况暴力就过了, 这数据...

### 复杂度

设块长为$l$, 则时间复杂度为$O(n+ml)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:H misc/icpc-cjxp2020/H/0.cpp %}

</details>

## I - Simple Math Problem

### 解题思路

签到题, 注意最后结果转成十进制

## J - Split Game

### 题意简述

有个$n\times m$的矩形网格纸, `Alice`和`Bob`轮流行动, `Alice`先手, 每个人均要选一张纸片并, 沿某条网格线将其剪成两片, 率先剪出$1\times 1$纸片的玩家判**负**, 两人均采取最优行动, 问谁胜

### 解题思路

![](J-1.jpg)

原型是一道经典的博弈论题

我们可以把每张纸片均看作一个有向图游戏, 整张纸看作有向图游戏的和

令$\operatorname{SG}(m,n)$表示$m\times n$纸片对应的$\operatorname{SG}$函数值

显然$1\times 1$, $1\times 2$, $2\times 1$, $3\times 1$, $1\times 3$的纸片是必败局面

另外
$$\operatorname{SG}(m,n)=\operatorname{mex}S$$

其中, $S=S_1\cup S_2$
$$S_1=\bigcup_{i=1+[n=1]}^{\lfloor\frac{m}{2}\rfloor}\{\operatorname{SG}(i,n)\oplus\operatorname{SG}(m-i,n)\}$$
$$S_2=\bigcup_{i=1+[m=1]}^{\lfloor\frac{n}{2}\rfloor}\{\operatorname{SG}(m,i)\oplus\operatorname{SG}(m,n-i)\}$$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:J misc/icpc-cjxp2020/J/0.cpp %}

</details>

## K - Travel Expense

### 题意简述

给出$n$个点$m$条边的无向图, 定义$d(u,v)$为点$u$到点$v$的最短路长度, 有$q$次询问, 每次给定$s,t,b$, 问满足$\sum_{i=1}^{d(s,t)}k^i\leqslant b$的最大的$k$是多少

### 解题思路

显然 Floyd+二分, 需要注意不要去求$k^{d(s,t)}$, 会爆`int64_t`

### 复杂度

$O(n^3+q\log B\log n)$, 其中$B$表示所有询问中最大的$b$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:K misc/icpc-cjxp2020/K/0.cpp %}

</details>

## L - WZB's Harem

### 题意简述

### 解题思路

> 模数出锅还不修是真的 np

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## M - Zoos's Animal Codes

### 解题思路

签到题
