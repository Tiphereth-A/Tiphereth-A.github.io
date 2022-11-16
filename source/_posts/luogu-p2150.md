---
title: "题解 - [Luogu P2150] [NOI2015] 寿司晚宴"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 题解
  - 洛谷
  - NOI
  - DP
  - 状压DP
date: 2022-10-22 23:02:15
---

[题目链接](https://www.luogu.com.cn/problem/P2150)

<!-- more -->

## 原始题面

### 题目描述

为了庆祝 NOI 的成功开幕, 主办方为大家准备了一场寿司晚宴. 小 G 和小 W 作为参加 NOI 的选手, 也被邀请参加了寿司晚宴

在晚宴上, 主办方为大家提供了 $n−1$ 种不同的寿司, 编号 $1,2,3,\ldots,n-1$, 其中第 $i$ 种寿司的美味度为 $i+1$. (即寿司的美味度为从 $2$ 到 $n$)

现在小 G 和小 W 希望每人选一些寿司种类来品尝, 他们规定一种品尝方案为不和谐的当且仅当: 小 G 品尝的寿司种类中存在一种美味度为 $x$ 的寿司, 小 W 品尝的寿司中存在一种美味度为 $y$ 的寿司, 而 $x$ 与 $y$ 不互质

现在小 G 和小 W 希望统计一共有多少种和谐的品尝寿司的方案 (对给定的正整数 $p$ 取模). 注意一个人可以不吃任何寿司

### 输入格式

输入文件的第 $1$ 行包含 $2$ 个正整数 $n, p$ 中间用单个空格隔开, 表示共有 $n$ 种寿司, 最终和谐的方案数要对 $p$ 取模

### 输出格式

输出一行包含 $1$ 个整数, 表示所求的方案模 $p$ 的结果

### 样例 #1

#### 样例输入 #1

```input1
3 10000
```

#### 样例输出 #1

```output1
9
```

### 样例 #2

#### 样例输入 #2

```input2
4 10000
```

#### 样例输出 #2

```output2
21
```

### 样例 #3

#### 样例输入 #3

```input3
100 100000000
```

#### 样例输出 #3

```output3
3107203
```

### 提示

【数据范围】

<table style="undefined;table-layout: fixed; width: 450px">
<colgroup>
<col style="width: 100px">
<col style="width: 150px">
<col style="width: 200px">
</colgroup>
<thead>
  <tr>
    <th>测试点编号</th>
    <th>n 的规模</th>
    <th>约定</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td>1</td>
    <td rowspan="3">2 ≤ n ≤ 30<br></td>
    <td rowspan="10">0 &lt; p ≤ 1,000,000,000</td>
  </tr>
  <tr>
    <td>2</td>
  </tr>
  <tr>
    <td>3</td>
  </tr>
  <tr>
    <td>4</td>
    <td rowspan="2">2 ≤ n ≤ 100</td>
  </tr>
  <tr>
    <td>5</td>
  </tr>
  <tr>
    <td>6</td>
    <td rowspan="2">2 ≤ n ≤ 200</td>
  </tr>
  <tr>
    <td>7</td>
  </tr>
  <tr>
    <td>8</td>
    <td rowspan="3">2 ≤ n ≤ 500</td>
  </tr>
  <tr>
    <td>9</td>
  </tr>
  <tr>
    <td>10</td>
  </tr>
</tbody>
</table>

## 解题思路

显然方案合法的充要条件是二人选的质因数集合交集为空

当 $n\leq 30$ 时, 状压 DP 的做法不难得出:

设

- 第 $i$ 个数为 $a_i$, 对应的质因数集合为 $p_i$
- $P=\bigcup_{i=1}^n p_i$
- $f_i(S_1,S_2)$ 为在只考虑前 $i$ 个数的前提下, 两人取的质因数集合分别为 $S_1$, $S_2$ 时的情况数

则转移方式如下:

- $$f_i(S_1\cup p_i,S_2)\leftarrow f_i(S_1\cup p_i,S_2)+f_{i-1}(S_1,S_2)~(p_i\cap S_2=\varnothing)$$
- $$f_i(S_1,S_2\cup p_i)\leftarrow f_i(S_1,S_2\cup p_i)+f_{i-1}(S_1,S_2)~(p_i\cap S_1=\varnothing)$$

答案为

$$\sum_{S_1,S_2\in P; S_1\cap S_2=\varnothing}f_n(S_1,S_2)$$

这个 $f$ 可以滚动数组优化, 时间复杂度为 $O(n4^{\pi(n)})$

---

对于本题的数据范围来说, $\pi(500)=95$, 显然不能直接状压

但是我们不难发现: 任意不超过 $n$ 的数只能有至多一个大于 $\sqrt{n}$ 的质因子

所以我们可以这样优化:

设

- 第 $i$ 个数为 $a_i$, 对应的不超过 $\sqrt{n}$ 的质因数集合为 $p_i$, 对应的超过 $\sqrt{n}$ 的大质数为 $b_i$
- $P=\bigcup_{i=1}^n p_i$
- $f_i(S_1,S_2)$ 为在只考虑前 $i$ 个数的前提下, 两人取的质因数集合分别为 $S_1$, $S_2$ 时的情况数
- $g_i(S_1,S_2)$ 为在只考虑前 $i$ 个数的前提下, 两人取的质因数集合分别为 $S_1$, $S_2$ 且第二个人没选 $b_i$ 时的情况数
- $h_i(S_1,S_2)$ 为在只考虑前 $i$ 个数的前提下, 两人取的质因数集合分别为 $S_1$, $S_2$ 且第一个人没选 $b_i$ 时的情况数

先将 $a$ 按 $b$ 升序排序

则转移方式如下:

- $$g_i(S_1\cup p_i,S_2)\leftarrow g_i(S_1\cup p_i,S_2)+g_{i-1}(S_1,S_2)~(p_i\cap S_2=\varnothing)$$
- $$h_i(S_1,S_2\cup p_i)\leftarrow h_i(S_1,S_2\cup p_i)+h_{i-1}(S_1,S_2)~(p_i\cap S_1=\varnothing)$$

在 $b_i$ 变动或到最后一个数时做如下转移

- $$f_i(S_1,S_2)\leftarrow g_i(S_1,S_2)+h_i(S_1,S_2)-f_i(S_1,S_2)~(S_1\cap S_2=\varnothing)$$
- $$g_i(S_1S_2)\leftarrow g_i(S_1,S_2)+f_i(S_1,S_2)$$
- $$h_i(S_1,S_2)\leftarrow h_i(S_1,S_2)+f_i(S_1,S_2)$$

答案为

$$\sum_{S_1,S_2\in P; S_1\cap S_2=\varnothing}f_n(S_1,S_2)$$

## 复杂度

$O(n4^{\pi(\sqrt{n})})$

## 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P2150 Luogu/P2150/0.cpp %}

</details>
