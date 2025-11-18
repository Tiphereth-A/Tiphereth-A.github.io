---
title: 笔记 - 无向图连通子图 & 环计数
categories:
  - 笔记
  - 算法竞赛
tags:
  - 算法竞赛
  - 笔记
  - Codeforces
  - 洛谷
  - 数学
  - 图论
  - 无向图
  - DAG
  - 子图
  - 导出子图
  - 连通子图
  - 生成树
  - 最小生成树
  - Floyd算法
  - 环
  - 计数
  - DP
  - 状压DP
  - 暴力
date: 2022-11-16 18:18:28
---

总结一些简单无向图的连通子图 & 环计数的方法

<!-- more -->

## 无向图环计数

### 例题 - [Codeforces 11D] A Simple Task

Given a simple graph, output the number of simple cycles in it. A simple cycle is a cycle with no repeated vertices or edges

#### Input

The first line of input contains two integers $n$ and $m$ ($1 \leq n \leq 19, 0 \leq m$) – respectively the number of vertices and edges of the graph. Each of the subsequent m lines contains two integers $a$ and $b$, ($1 \leq a, b \leq n, a \neq b$) indicating that vertices $a$ and $b$ are connected by an undirected edge. There is no more than one edge connecting any pair of vertices

#### Output

Output the number of cycles in the given graph

#### Examples

##### Input

```input1
4 6
1 2
1 3
1 4
2 3
2 4
3 4
```

##### Output

```output1
7
```

##### Note

The example graph is a clique and contains four cycles of length $3$ and three cycles of length $4$

### 做法

无向图环计数问题是 NP 的, 本题可以利用状压 DP 求解

不考虑自环, 令

- $f(V(G'),x)$ 为导出子图 $G'$ 中, 点 $\min V(G')$ 到点 $x$ 的路径条数 ($x\in V(G')$)
- $g(x,y)$ 为边 $(x,y)$ 的重数

则

$$
f(V(G'),x)=\sum_{v\in V(G)}f(V(G')\setminus\{x\},y)g(y,x)
$$

因为是无向图, 我们只需要枚举一下这个最小点然后考虑所有与其关联的边即可, 最后答案即为

$$
\frac{1}{2}\sum_{v\in V(G)}\sum_{S\subseteq V(G);\min S=v}\sum_{x\in S\setminus\{v\}}f(S,x)g(v,x)
$$

### 时间复杂度

$$
\begin{aligned}
  \Theta\left(\sum_{i=1}^{2^n-1}(\operatorname{popcount}(i)-1)^2\right)&=\Theta\left(\sum_{i=0}^n(i-1)^2\binom{n}{i}\right)\\
  &=\Theta\left(2^{n-2}(n^2-3n+4)\right)\\
  &\implies O\left(n^22^n\right)
\end{aligned}
$$

### 参考代码

{% icodeweb cpa_cpp title:Codeforces_11D CodeForces/11D/0.cpp %}

## 简单无向图三元环计数

{% note warning %}
<https://cplib.tifa-233.com/include/graph/ringenum3.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

### 例题 - [Luogu P1989] 无向图三元环计数

无向图 $G$ 的三元环指的是一个 $G$ 的一个子图 $G_0$, 满足 $G_0$ 有且仅有三个点 $u, v, w$, 有且仅有三条边 $\langle u, v \rangle, \langle v, w \rangle, \langle w, u \rangle$. 两个三元环 $G_1, G_2$ 不同当且仅当存在一个点 $u$, 满足 $u \in G_1$ 且 $u \notin G_2$

给定一个 $n$ 个点 $m$ 条边的简单无向图, 求其三元环个数

#### 输入格式

每个测试点有且仅有一组测试数据

输入的第一行是用一个空格隔开的两个整数, 分别代表图的点数 $n$ 和边数 $m$

第 $2$ 到第 $(m + 1)$ 行, 每行两个用空格隔开的整数 $u, v$, 代表有一条连接节点 $u$ 和节点 $v$ 的边

#### 输出格式

输出一行一个整数, 代表该图的三元环个数

#### 样例输入 #1

```input1
3 3
1 2
2 3
3 1
```

#### 样例输出 #1

```output1
1
```

#### 样例输入 #2

```input2
5 8
1 2
2 3
3 5
5 4
4 2
5 2
1 4
3 4
```

#### 样例输出 #2

```output2
5
```

#### 提示

**【样例 2 解释】**

共有 $5$ 个三元环, 每个三元环包含的点分别是 $\{1, 2, 4\}, \{2, 3, 4\}, \{2, 3, 5\}, \{2, 4, 5\}, \{3, 4, 5\}$

**【数据规模与约定】**

**本题采用多测试点捆绑测试, 共有两个子任务**

- Subtask 1 (30 points): $n \le 500$, $m \le {10}^3$
- Subtask 2 (70 points): 无特殊性质

对于 $100\%$ 的数据, $1 \le n \le 10^5$, $1 \le m \le 2 \times {10}^5$, $1 \le u, v \le n$, 给出的图不存在重边和自环, **但不保证图连通**

**【提示】**

- 请注意常数因子对程序效率造成的影响

### 做法

我们不难想到三种暴力做法:

- 枚举三点: $O(n^3)$
- 枚举两边: $O(m^2)$
- 枚举一点和对边: $O(nm)$

{% note primary no-icon %}

另外还可以使用 `std::vector<std::bitset>` 开邻接矩阵来对暴力进行优化, 同时和点 $i$, 点 $j$ 相邻的点集可以通过两个点对应的 `bitset` 的 `&` 得到

若题目卡空间, 可以考虑设置一个阈值 $T$, 将度数不超过 $T$ 的点直接暴力, 度数超过 $T$ 的点用 `bitset` 优化

{% endnote %}

下面我们介绍一种更优的算法, 其时间复杂度为 $O(m\sqrt{m})$, 因为 $O(n)\leq m\leq O(n^2)$, 所以该算法总体来说是优于上述三种暴力算法的

定义严格弱序 $\prec$ 满足

$$
u\prec v:=\begin{cases}
  \deg(u)<\deg(v),&\deg(u)\neq\deg(v)\\
  u<v,&\deg(u)=\deg(v)
\end{cases}
$$

我们对原图 $G$ 赋方向, 若 $(u,v)\in E(G)$ 且 $u\prec v$, 则将该边改为弧 $u\to v$ ($\langle u,v\rangle$)

因为 $\prec$ 是严格弱序, 所以得到的新图 $G'$ 是 DAG, 并且 $G$ 的三元环 $u,v,w$ (顶点按一定顺序排列后) 在 $G'$ 中与 $u\to v$, $u\to w$, $v\to w$ 一一对应

所以在新图中我们只需要枚举 $u$, 接着枚举 $u$ 的邻接点 $v$, 最后看 $v$ 的邻接点 $w$ 是否是 $u$ 的邻接点即可

### 时间复杂度

注意到

- 若 $v$ 在 $G$ 中的度数小于 $\sqrt{m}$, 则在 $G'$ 中也不可能超过 $\sqrt{m}$, 所以 $\deg_{out}(v)=O(\sqrt{m})$
- 若 $v$ 在 $G$ 中的度数不小于 $\sqrt{m}$, 由于 $v$ 在 $G'$ 中只能向度数不小于自身的点连边, 所以 $\deg_{out}(v)=O(\sqrt{m})$

故时间复杂度为

$$
\begin{aligned}
  \Theta\left(\sum_{u\in V(G')}\sum_{\langle u, v\rangle\in E(G')}\deg_{out}(v)\right)&= \Theta\left(\sum_{\langle u, v\rangle\in E(G')}\deg_{out}(v)\right)\\
  &\implies O\left(\sum_{\langle u, v\rangle\in E(G')}O\left(\sqrt{m}\right)\right)\\
  &= O(m\sqrt{m})
\end{aligned}
$$

### 参考代码

{% icodeweb cpa_cpp title:Luogu_P1989 Luogu/P1989/0.cpp %}

## 简单无向图四元环计数

{% note warning %}
<https://cplib.tifa-233.com/include/graph/ringcnt4.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

### 做法

算法和 [简单无向图三元环计数](#简单无向图三元环计数) 类似, 下面简述流程

建图 $G'$ 的方式不变, 只不过这里的四元环 $u,v,w,x$ 在 $G'$ 中可能有以下三种同构形式:

|      形式 1      |      形式 2      |      形式 3      |
| :--------------: | :--------------: | :--------------: |
| ![](cntr4-1.svg) | ![](cntr4-2.svg) | ![](cntr4-3.svg) |

不难发现这三种形式均可以视作如下形式

![](cntr4-mix.svg)

所以此时我们需要枚举 $u\to v-w$, 两条这样的路径即构成一个四元环

### 时间复杂度

$O(m\sqrt{m})$

### 参考代码

{% icodeweb blog lang:cpp count-csgr-graph/cntsr4.cpp %}

---

## 参考资料

- [算法 图中求最小环路径 最小环个数 最大平均环 求简单无向图中环的个数 - 木-天空 - 博客园](https://www.cnblogs.com/TengXunGuanFangBlog/archive/2013/04/19/loop_problem.html)
- [三元环小记(+四元环) - command_block 的博客 - 洛谷博客](https://www.luogu.com.cn/blog/command-block/san-yuan-huan-xiao-ji-si-yuan-huan-post)
- [FJWC2019 子图 (三元环计数、四元环计数) - ghj1222 - 博客园](https://www.cnblogs.com/oier/p/10538811.html)
