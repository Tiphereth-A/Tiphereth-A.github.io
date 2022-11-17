---
title: 题解 - 2022 CCPC 广州站
categories:
  - 算法竞赛
  - 题解
  - CCPC
tags:
  - 算法竞赛
  - 题解
  - CCPC
  - 数学
  - 计数
  - 组合数学
  - 容斥定理
  - 博弈论
  - 图论
  - DAG
  - 差分约束
  - 拓扑排序
  - 构造
  - 缩点
  - 贪心
  - 前缀和
  - DP
  - 概率DP
  - 树形DP
  - 树上背包
  - 数据结构
  - 并查集
  - 树状数组
date: 2022-11-16 12:46:33
---

[比赛链接](https://codeforces.com/gym/104053)

进度: 7 / 13

<!-- more -->

## 题目概览

| 题号[^1] | 标题[^2]                                            | 做法                                |
| -------- | --------------------------------------------------- | ----------------------------------- |
| \*A      | Alice and Her Lost Cat                              |                                     |
| \*B      | Ayano and sequences                                 |                                     |
| C        | Customs Controls 2                                  | 图论, 构造, 缩点, 并查集 / 差分约束 |
| \*D      | Digits                                              |                                     |
| E        | Elevator                                            | 签到 (前缀和)                       |
| \*F      | Equations                                           |                                     |
| \*G      | Game                                                |                                     |
| H        | GameX                                               | 签到 (博弈论)                       |
| I        | Infection                                           | 树上背包, 概率 DP                   |
| J        | [Math Exam](https://www.luogu.com.cn/problem/P3266) | 容斥, 前缀和, 折线计数              |
| K        | Middle Point Graph                                  | 图论 -> 无向图三元环&四元环计数     |
| L        | Station of Fate                                     | 签到 (组合数学)                     |
| \*M      | XOR Sum                                             |                                     |

[^1]: 打\*的是还没写题解的题
[^2]: 带超链接的是找到了原题或原型

[官方题解](official_solutions.pptx)

{% pdf /archives/ccpc-gzr2022/problems.pdf 600px %}

## A - Alice and Her Lost Cat

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/A.cpp %}

</details>

## B - Ayano and sequences

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/B.cpp %}

</details>

## C - Customs Controls 2

### 解题思路

设从 $1$ 到 $i$ 的答案为 $d_i$

显然若对任意点 $v$, 若有弧 $u_1\to v$, $u_2\to v$, 则 $d_{u_1}=d_{u_2}$

我们用并查集将 $d$ 相同的点缩成一个点, 因为点权是正的, 所以缩点后的图应该也是个 DAG, 否则不满足要求

设点 $i$ 在缩点后的图中对应的点编号为 $s_i$, 之后我们对缩点后的图跑一遍 BFS 求一下每个点的拓扑序 $b_{s_i}$

最后我们只需让所有路径的点权和为 $b_{s_n}$ 即可

要做到这一点, 若有弧 $u\to v$, 我们只需令 $w_v=b_{s_v}-b_{s_u}$ 即可

有一个小技巧: 我们可以将判环和 BFS 合起来, 我们记录一下缩点后的图的每个点的入度 $\deg_{in}(s_i)$, 若 $\deg_{in}(s_1)>0$, 则显然不满足要求, 之后我们 BFS 时遍历到一个点时将这个点的入度减 $1$ (相当于删去刚刚走过的这条弧), 若这个点入度为 $0$ 了则入队, 这样图中没有环当且仅当每个点都被恰好遍历一次

### 复杂度

$O(m\alpha(n)+n)$

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/C.cpp %}

</details>

## D - Digits

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/D.cpp %}

</details>

## E - Elevator

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/E.cpp %}

</details>

## F - Equations

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/F.cpp %}

</details>

## G - Game

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/G.cpp %}

</details>

## H - GameX

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/H.cpp %}

</details>

## I - Infection

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/I.cpp %}

</details>

## J - Math Exam

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/J.cpp %}

</details>

## K - Middle Point Graph

### 解题思路

带讨论, 具体可以参照题解

三元环和四元环的求法可参照 {% post_link count-csgr-graph %} 相关章节

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/K.cpp %}

</details>

## L - Station of Fate

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/L.cpp %}

</details>

## M - XOR Sum

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp ccpc-gzr2022/M.cpp %}

</details>
