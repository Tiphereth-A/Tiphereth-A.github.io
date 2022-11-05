---
title: 题解 - 2021 ICPC 亚洲区域赛(沈阳)
categories:
  - 算法竞赛
  - 题解
  - ICPC
tags:
  - 算法竞赛
  - 题解
  - ICPC
  - 启发式算法
  - 数学
  - 数据结构
  - 字符串
  - DP
  - 打表
  - 搜索
  - 模拟
  - 图论
  - 计算几何
  - 动态半平面交
  - 组合数学
  - 线性代数
  - 概率
  - 期望
  - 容斥定理
  - Cramer法则
  - 复数
  - 最短路
  - 二分图
  - 匹配
  - 完美匹配
  - 最大边权匹配
  - 线图
  - 割边/桥
  - Tarjan算法
  - Duval算法
  - 剪枝
  - DFS
  - BFS
  - IDA*
  - 树形DP
  - 并查集
  - 后缀数组
  - 后缀自动机
  - Lyndon分解
  - KMP
date: 2021-11-21 19:33:27
---

要 素 过 多

~~图不错, 建议下回多搞点~~

[比赛链接](https://ac.nowcoder.com/acm/contest/24346)

<!-- more -->

## 题目概览

| 题号[^1] | 标题                             | 做法                         |
| -------- | -------------------------------- | ---------------------------- |
| \*A      | A Bite of Teyvat                 | 动态半平面交                 |
| B        | Bitwise Exclusive-OR Sequence    | 图论 + 并查集                |
| \*C      | Cards of Magic                   | 概率 DP                      |
| \*D      | Cross the Maze                   |                              |
| E        | Edward Gaming, the Champion      | 签到                         |
| F        | Encoded Strings I                | 签到 (模拟)                  |
| \*G      | Encoded Strings II               |                              |
| H        | Line Graph Matching              | Tarjan (割边)                |
| I        | Linear Fractional Transformation | 解线性方程组                 |
| J        | Luggage Lock                     | BFS / IDA\* / ... / 打表     |
| \*K      | Matrix Operations                | 复杂的数据结构, 先鸽了       |
| L        | Perfect Matchings                | 容斥定理 + 树形 DP           |
| M        | String Problem                   | SA / SAM / Lyndon 分解 / KMP |

[^1]: 打\*的是还没写题解的题

[官方题解](official_solutions.pptx)

{% pdf /archives/icpc-asyr2021/problems.pdf 600px %}

## A - A Bite of Teyvat

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## B - Bitwise Exclusive-OR Sequence

### 题意简述

对一个数组 $\{\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}\}$, 给出 $m$ 条限制, 均为 $a_u\oplus a_v=w$, 其中 $\oplus$ 为异或, 问满足限制条件的数组的和最小为多少, 不存在时输出 `-1`

### 解题思路

对每一位分别判断, 将所有限制为 0 的条件都抽出来, 并将其对应端点在并查集里合并, 然后将限制为 1 的条件对应端点在并查集中 `find` 得到的点间连边, 之后找环, 如果找到了含奇数个结点的环就说明条件间有冲突, 直接结束即可, 否则按 dfs 序统计奇偶结点对应并查集秩的大小之和, 将较小的赋为 1 即可

判环用 dfs 即可

### 复杂度

$O((m\alpha(n)+n)\log\max w)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:B Gym/103427B/0.cpp %}

</details>

## C - Cards of Magic

### 题意简述

有一个 HP 为 $n$ 的敌人, 你每回合会等概率获得如下三张卡片的一种

- 水人卡: 使用后召唤一个永久存在的水人, 之后你每使用一张牌, 水人都会对敌人造成 1 点伤害, 水人在场上最多只能存在一个 (即若在水人存在的情况下使用水人卡, 则只会对敌人造成 1 点伤害)
- 火球卡: 使用后对敌人造成 2 点伤害
- 复制卡: 使用后可以获得一张之前使用过的卡, 如果之前没有使用过卡片则不能使用

你每回合可以使用任意张卡 (包括 0 张), 问在采取最优决策的条件下, 击败敌人 (即将敌人的 HP 变为非负数) 的回合数的期望

### 解题思路

显然是个概率 DP 了, 我们先整理一下最优决策

- 若抽到了水人卡, 则直接使用
- 若场上不存在水人, 则除非当前手牌可以一波带走, 否则跳过本回合
- 若场上存在水人
  - 若抽到了火球卡, 则直接使用, 造成 3 点伤害
  - 若抽到了复制卡
    - 若使用过复制卡, 则直接复制复制卡套娃即可
    - 若使用过火球卡, 则复制火球卡, 造成 4 点伤害
    - 若复制卡和火球卡都没使用过
      - 若当前敌人 HP <= 2, 则复制水人卡, 造成 2 点伤害
      - 否则跳过本回合

画出来大概是这样的

![](C-1.svg)

不管你晕没晕, 反正我晕了

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## D - Cross the Maze

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## E - Edward Gaming, the Champion

Python 一行 `print(input().count('edgnb'))` 即可

## F - Encoded Strings I

### 题意简述

对字符串 $S$, 定义如下函数

- $r_S(c)$ 为字符 $c$ 在 $S$ 中最后一次出现的下标, 即 `find_last_of`
- $F_S(c):=\operatorname{chr}(|\{x\in S\mid r_S(x)>r_S(c)\}|)$, 其中 $\operatorname{chr}(i)$ 为第 $i+1$ 个小写英文字母, 即 `i + 'a'`

令 $T_S$ 为将 $S$ 的所有字符 $c$ 同时用 $F_S(c)$ 替换后得到的字符串, 对 $S$ 的全部前缀 $\operatorname{Pre}(S)$, 求

$$\max_{S'\in\operatorname{Pre}(S)}T_{S'}$$

### 解题思路

数据规模小, 直接模拟一遍即可

### 复杂度

$O(n^2)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:F Gym/103427F/0.cpp %}

</details>

## G - Encoded Strings II

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## H - Line Graph Matching

### 题意简述

给出一个简单带权无向连通图, 求其线图的最大权匹配对应的权值和

### 解题思路

结论题

显然, 线图的匹配对应到原图即为若干条路径

因为原图是简单且连通的, 所以

- 如果原图的边为偶数条, 则线图的任意一个最大匹配的权值和就是原图所有边的权值和
- 如果原图的边为奇数条, 则线图最大匹配的权值和就是原图所有边中排除某条边后的权值和, 可以排除的边需要满足以下条件之一
  - 非割边
  - 割边, 且删去这条边之后的两个子图的边均为偶数条 (否则将删去更多边, 就不是最大匹配了)

### 复杂度

$O(n+m)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:H Gym/103427H/0.cpp %}

</details>

## I - Linear Fractional Transformation

### 题意简述

给定一个在 $\mathbb{C}$ 上的函数
$$f(z)=\frac{az+b}{cz+d},~a,b,c,d\in\mathbb{C}^{\infty}$$

又给定其上的三个点 $(z_i,w_i)$, $i=1,2,3$, 给出复数 $z_0$, 问 $f(z_0)$ 为多少

### 解题思路

> 不知道为啥没人做这题, 明明是签到题啊

#### 法一

首先我们假设 $c\ne 0$, 此时在分式上下同时除 $c$, 变为

$$f(z)=\frac{a'z+b'}{z+d'}$$

然后把三个点代入, 即有

$$
\begin{cases}
  z_ia'+b'-w_id'=z_iw_i\\
  i=1,2,3
\end{cases}
$$

如果该方程可解, 那我们直接用 Cramer 法则就做完了, 否则说明 $c=0$, 此时我们在分式上下同时除 $d$, 变为

$$f(z)=a'z+b'$$

解法同上, 这个更好解一些

由于题目保证了这三个点互不相同, 故一定有解

另外复数直接用 C++ 自带的 `complex` 类即可

#### 法二

分式线性变换保交比, 即

$$\frac{(z_0-z_1)(z_3-z_2)}{(z_0-z_2)(z_3-z_1)}=\frac{(w_0-w_1)(w_3-w_2)}{(w_0-w_2)(w_3-w_1)}$$

~~简单的代数知识~~

### 代码参考 (法一)

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:I Gym/103427I/0.cpp %}

</details>

## J - Luggage Lock

### 题意简述

有一个四位数的轮盘, 每次操作你可以选取一段相邻的圆盘使其同时顺时针或逆时针转一下 (即在 $\mathbb{Z}_{10}$ 中加 1 或减 1), 问从状态 $S$ 转到状态 $T$ 至少要几步

### 解题思路

首先我们以状态为点, 两相邻状态为边建图, 此时答案即为点 $S$ 到点 $T$ 的最短路长度

我们定义两点间的减法为每一位分别在 $\mathbb{Z}_{10}$ 下做减法

此时我们发现点 S 到点 T 实际上就是从点 `0000` 到点 $T-S$ 的最短路

然后就随便做了

我们也可以把点 `0000` 到所有点的最短路打个表, 因为最短路长度一定不会超过 $20$ (实际上如果你跑一遍 Floyd 就能发现上确界是 $12$), 所以无论是空间还是代码长度都满足要求

## K - Matrix Operations

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

</details>

## L - Perfect Matchings

### 题意简述

给出 $2n$ 个结点的完全图, 在删除能构成一棵树的 $2n-1$ 条边后, 问该图中的完美匹配方案数

### 解题思路

令 $f_n$ 表示 $2n$ 个结点的完美匹配方案数, 则

$$f_n=\frac{1}{n!}\prod_{i=1}^n\binom{2i}{2}=\frac{(2n)!}{2^nn!}$$

不难得出 $f_n=(2n-1)f_{n-1}$

设在删除的那棵树上选了至少 $k$ 条合法边后的方案数为 $g_n(k)$, 根据容斥原理可得最终所求为

$$\sum_{k=0}^{k=n}(-1)^kg_n(k)$$

接下来考虑用树形 DP 求 $g_n(k)$

令

- $R$ 为删除的树的根结点
- $h_i(r,j)$ 表示在以结点 $r$ 为根的子树上选择 $j$ 条合法边时的方案总数, 其中 $i=0,1$ 表示选择的边中是否包含结点 $r$
- $h(r,j)=h_0(r,j)+h_1(r,j)$
- $S(r)$ 表示以结点 $r$ 为根的子树中的所有非根结点
- $s(r)=|S(r)|+1$ 表示以结点 $r$ 为根的子树的大小

则

$$g_n(k)=f_{n-k}(h_0(R,k)+h_1(R,k))$$

注意到 $k$ 条合法边包含 $2k$ 个结点, 所以状态转移方程如下

$$
h_0(r,j)=\begin{cases}
  0,&j<0\\
  1,&j=0\\
  \displaystyle\sum_{u\in S(r)}\sum_{t=1}^{\lfloor\frac{s(u)}{2}\rfloor}h(u,t)h_0(r,j-t),&j>0\\
\end{cases}
$$

$$
h_1(r,j)=\begin{cases}
  0,&j\leqslant 0\\
  \displaystyle\sum_{u\in S(r)}\left(h_0(r,j-1)+\sum_{t=1}^{\lfloor\frac{s(u)}{2}\rfloor}\left(h(u,t)h_1(r,j-t)+h_0(u,t)h_0(r,j-t-1)\right)\right),&j>0\\
\end{cases}
$$

注意转移结束后更新 $s(r)$, 否则复杂度会出错

### 复杂度

$O(n^2)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:L Gym/103427L/0.cpp %}

</details>

## M - String Problem

### 题意简述

找给定字符串 $s$ 所有前缀的最大后缀

### 解题思路

这里只讲 Lyndon 分解的做法

为方便起见, 我们改一下 Lyndon 串的定义: 若一个字符串 $s$ 的所有非平凡后缀都比 $s$ **小**, 则称 $s$ 为 Lyndon 串

我们用 Duval 算法求出给定字符串的 Lyndon 分解, 并用 `l[]` 存 Lyndon 串的左边界, 注意我们在这里修改了 Lyndon 串的定义, 所以 Duval 算法里的小于号应该改为大于号

显然, 之后我们要找的最大后缀左边界一定在 `l[]` 中且随遍历顺序单调递增, 右边界即为当前前缀的右边界

我们用 `idx` 来记录当前选择的 `l[]` 下标, 在考虑下一个前缀时, 如果该前缀右边界比当前后缀的左边界大, 说明我们要增加 `idx` 了, 只需要让其对应的后缀是第一个比前缀右边界大即可

### 复杂度

$O(|s|)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:M Gym/103427M/0.cpp %}

</details>
