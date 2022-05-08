---
title: 笔记 - 线性基
categories:
  - 程序设计
  - 笔记
tags:
  - 程序设计
  - 模板
  - 算法
  - C++
  - 数学
  - 代数
  - 线性代数
  - 高等代数
  - 线性空间
  - 线性基
  - 位运算
  - 异或
date: 2021-11-12 17:59:15
---

令 $V\subseteq\Z_2^n$, 线性基即为线性空间 $V$ 上满足一定条件的一组"基底" $(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$

<!-- more -->

## 线性基

### 定义

令 $V\subseteq\Z_2^n$, 线性基即为线性空间 $V$ 上满足如下条件的一组"基底" $(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})$

1. 排除 $\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n}$ 中所有零向量后的向量组线性无关
1. $\epsilon_i(i+1..n)=0$
1. 若 $\epsilon_i(i)=1$, 则 $\forall j,~\epsilon_j(i)=\delta_{ij}$

> 对 $\alpha\in\mathbb{P}^n$, $\alpha(x)$ 即为 $\alpha$ 第 $x$ 维的元素, $\alpha(x..y)$ 即为 $\alpha$ 第 $x$ 维到第 $y$ 维所有元素构成的向量

写成矩阵来看更直白些, 矩阵看起来就像是缺了几列的三角形

比如这样

$$
(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{6})=\begin{bmatrix}
   & & & & &1\\
   & & & &1& \\
   & & &0&1&1\\
   & &1& & & \\
   &1& & & & \\
  1& & & & & \\
\end{bmatrix}
$$

### 性质

- $\operatorname{span}(\def\enum#1{\epsilon_{ #1}}\enum{1},\enum{2},...,\enum{n})=\operatorname{span}(V)$
- 令 $\alpha[x]=\sum_{i=1}^n\alpha(i)x^{i-1}$, 则
  $$\left[\sum_{i=1}^n\epsilon_i\right](2)=\max_{\alpha\in\operatorname{span}(V)}\alpha[2]$$

  > 在后面的代码实现中可以看到, 这条性质说的是将所有线性基异或起来的值即为 $V$ 的最大子集异或和

### 构造方法

我们以插入元素的方法构造

对前设的 $V$, 设当前我们已完成构建的线性空间为 $V'\subseteq V$, 对应的线性基为 $(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$, 接下来我们在 $V\setminus V'$ 中选取一个向量 $\alpha$, 进行如下操作直到 $|V'|=|V|$ 为止

$\begin{array}{r|l:l}
  1 & \textbf{for}~ i \gets n ~\textbf{downto}~ 1 ~\textbf{do} \\
  2 & \quad \textbf{if}~ \alpha(i) = 1 ~\textbf{then}\\
  3 & \quad \quad \textbf{if}~ \epsilon'_i(i) = 1 ~\textbf{then}~ \alpha\gets\alpha+\epsilon'_i & flip~\alpha(i)\\
  4 & \quad \quad \textbf{else} & prepare~to~replace~\epsilon'_i~with~\alpha\\
  5 & \quad \quad \quad \textbf{for}~ j \gets 0 ~\textbf{to}~ i-1 ~\textbf{do} \\
  6 & \quad \quad \quad \quad \textbf{if}~ \alpha(j) = 1 ~\textbf{then}~ \alpha\gets\alpha+\epsilon'_j & flip~\alpha(j)\\
  7 & \quad \quad \quad \textbf{end}~\textbf{for} \\
  8 & \quad \quad \quad \textbf{for}~ j \gets i+1 ~\textbf{to}~ n ~\textbf{do} \\
  9 & \quad \quad \quad \quad \textbf{if}~ \epsilon'_j(i) = 1 ~\textbf{then}~ \epsilon'_j\gets\alpha+\epsilon'_j & flip~\epsilon'_j(i)\\
  10 & \quad \quad \quad \textbf{end}~\textbf{for} \\
  11 & \quad \quad \quad \epsilon'_i\gets\alpha & replace\\
  12 & \quad \quad \quad \textbf{goto}~ line~ 16 \\
  13 & \quad \quad \textbf{end}~\textbf{if} \\
  14 & \quad \textbf{end}~\textbf{if} \\
  15 & \textbf{end}~\textbf{for} \\
  16 & restore~\alpha~and~insert~\alpha~to~V',~delete~\alpha~from~V
\end{array}$

#### 正确性

可用归纳法证明

- $V'=\varnothing$ 与 $|V'|=1$ 时显然满足条件
- 当 $|V'|>1$ 时
  - 我们尝试插入 $\alpha$ 时, 如果满足第 $3$ 行的条件, 为了保持条件 $2$, 我们需要把对应维反转, 如果 $\alpha$ 被转成 $0$ 了, 说明 $\alpha$ 与 $(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$ 线性相关, 不能插入
  - 如果执行到第 $4$ 行, 说明 $\alpha$ 与 $(\def\enum#1{\epsilon'_{ #1}}\enum{1},\enum{2},...,\enum{n})$ 线性无关, 此时应做一些处理来维持线性基的条件, 之后替换掉 $\epsilon'_i$ 即可 (此时的 $\epsilon'_i=0$)
    - $5\sim 7$ 行是消除 $\alpha$ 中低维的不满足条件 $3$ 的 $1$
    - $8\sim 10$ 行是消除 $\epsilon'_j$ 中第 $i$ 维的 $1$, 同样是为了满足条件 $3$
  - 经过这样的处理之后, 插入 $\alpha$ 后的 "基底" 仍满足条件 $3$

## 复杂度

令 $n$ 为维数

- 时间复杂度:
  - 插入: $O(n)$
- 空间复杂度: $O(n)$

## 代码

众所周知, $\Z_2$ 上的加法即为异或, 故代码实现时可以将 $V$ 中元素写为无符号整形或 `std::bitset`, 加法即为异或

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp xor-basis/Xor_base.hpp %}

</details>

## 例题

- 洛谷 [P3812 【模板】线性基](https://www.luogu.com.cn/problem/P3812) (最大子集异或和)
- 洛谷 [P3857 [TJOI2008]彩灯](https://www.luogu.com.cn/problem/P3857) (子集异或和的种数, 即线性基的秩)
- HDU [3949 XOR](https://vjudge.net/problem/HDU-3949/origin) (子集 k 小异或和)
- 洛谷 [P4869 albus 就是要第一个出场](https://www.luogu.com.cn/problem/P4869) (子集异或和排名)
- 洛谷 [P4151 [WC2011]最大 XOR 和路径](https://www.luogu.com.cn/problem/P4151) (图上最大异或和路径)
- 洛谷 [P3292 [SCOI2016]幸运数字](https://www.luogu.com.cn/problem/P3292) (树上路径点的最大子集异或和)
- HDU [6579 Operation](https://vjudge.net/problem/HDU-6579/origin) (子集 k 小异或和)
