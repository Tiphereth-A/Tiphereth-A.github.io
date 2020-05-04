---
title: 题解 - 2020 ICPC 亚洲区域赛(济南)
categories:
  - 程序设计
  - 题解
  - ICPC
tags:
  - 程序设计
  - 题解
  - ICPC
  - 数学
  - 矩阵
  - 贪心
  - 位运算
  - 构造
date: 2020-12-27 15:26:45
---

[比赛链接](https://ac.nowcoder.com/acm/contest/10662)

<!-- more -->

## 题目概览

| 题号[^1] | 标题[^2]                 | 做法       |
| -------- | ------------------------ | ---------- |
| A        | Matrix Equation          | 数学       |
| \*B      | Number Game              |            |
| C        | Stone Game               | 签到(贪心) |
| D        | Fight against involution | 签到(贪心) |
| \*E      | Tree Transform           |            |
| \*F      | Gcd Product              |            |
| G        | Xor Transformation       | 签到(构造) |
| \*H      | Path Killer              |            |
| \*I      | Random Walk On Tree      |            |
| \*J      | Tree Constructer         |            |
| \*K      | Kth Query                |            |
| \*L      | Bit Sequence             |            |
| M        | Cook Pancakes!           | 签到       |

[^1]: 打\*的是还没写题解的题
[^2]: 带超链接的是找到了原题或原型

{% pdf /article/icpc-ajnr2020/problems.pdf 600px %}

## 官方题解

<details>
<summary><font color='orange'>Show / Hide</font></summary>

{% pdf /article/icpc-ajnr2020/official_solution.pdf 600px %}

</details>

## A - Matrix Equation

### 题意简述

> **定义** $n$阶 01 方阵
>
> 只由$0$和$1$组成的$n$阶方阵

给出$n$阶 01 方阵$A,B$, 问有多少个$n$阶 01 方阵$C$满足
$$A\times C=B\cdot C\tag{A-1}$$

其中

$$
\begin{aligned}
  A_{n\times n}\times B_{n\times n}&:=\left(\sum_{k=1}^na_{i,k}b_{k,j}\right)_{n\times n}\\
  A_{n\times n}\cdot B_{n\times n}&:=(a_{i,j}b_{i,j})_{n\times n}
\end{aligned}
$$

### 解题思路

令式$\text{A-1}$左边矩阵为$L$, 右边矩阵为$R$

不难发现当$C$是零矩阵时满足条件

之后我们尝试取反$c_{i,j}$, 此时$L$中第$j$行的所有元素均可能发生变化, 而$R$中只有$r_{i,j}$会发生变化, 我们只需要统计奇偶性即可判断取反后的$C$是否满足

设$C$中有$m$个元素在取反后式$\text{A-1}$仍然成立, 则结果即为
$$2^m\bmod M$$
其中$M$为模数 $998244353$

### 复杂度

$\Theta(n^3+\log m)\implies O(n^3)$

## B - Number Game

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## C - Stone Game

### 题意简述

给出$a_i$堆包含$i$个石子的石堆 ($i=1,2,3$), 定义合并操作为: 选取两堆石子, 设其中石子个数分别为$a,b$, 删除这两堆并加入一个新的石堆, 其中石子个数为$a+b$, 定义本次操作的代价为$ab\bmod 3$

问将所有石子合并为一堆的最小代价

### 解题思路

因为答案只与模$3$余数有关, 所以可放在$\Z_3$下考虑

首先合并个数为$1$和个数为$2$的石堆, 然后将剩下的个数为$1$的石堆三个为一组合并, 个数为$2$的石堆三个为一组合并, 再有剩下的就和个数为$0$的石堆合并

## D - Fight against involution

思路挺好想的, 略

## E - Tree Transform

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## F - Gcd Product

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## G - Xor Transformation

### 题意简述

给定$x,y$ ($y<x$), 定义一次操作为: 选取$[0,x)$内的整数$a$并将$x$替换为$x\operatorname{xor}a$

找到一种选取$a$的方案使$x$经过至多$5$次操作后变为$y$

### 解题思路

第一次取$a=\operatorname{not}(x)\operatorname{and}y$, 第二次取$a=x\operatorname{xor}y$

## H - Path Killer

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## I - Random Walk On Tree

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## J - Tree Constructer

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## K - Kth Query

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## L - Bit Sequence

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## M - Cook Pancakes

### 题意简述

给$n$个没煎过的饼和一口最多只能同时煎$k$个饼的锅, 问最少需要煎多少次才能将所有饼煎熟(正反两面均煎过一次)

### 解题思路

显然如果$k\geqslant n$, 答案即为$2$, 否则为$\lceil\frac{2n}{k}\rceil$
