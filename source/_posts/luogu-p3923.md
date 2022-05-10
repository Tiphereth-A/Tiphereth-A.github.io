---
title: "题解 - [Luogu P3923] 大学数学题"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 数学
  - 构造
  - 代数
  - 抽象代数
  - 特征
  - 域
  - 素域
  - 有限域
  - 分裂域
  - 同态基本定理
  - 理想
  - 极大理想
  - 多项式
  - 卷积
date: 2021-11-17 13:38:14
---

[题目链接](https://www.luogu.com.cn/problem/P3923)

<!-- more -->

## 原始题面

### 题目背景

琪露诺: 我知道了! 答案一定是 1!

露米娅: 什么鬼啊 (汗), 你还是再想想去吧... 我先把最后一道题给你, 这是一道大学数学题哦

### 题目描述

露米娅: 大妖精想构造一个 $n$ 元有限域, 元素用 $0 \sim n - 1$ 的整数表示 有限域需要满足以下条件

1. 有加法单位元 $o$, 满足对于任意元素$a$, $o + a = a + o = a$
1. 对于任意元素 $a$, 存在加法逆元 $a^{-1}$, 使得 $a + a^{-1} = a^{-1} + a = o$
1. 有不同于加法单位元 $o$ 的乘法单位元 $i$, 满足对于任意元素 $a$, $i \times a = a \times i = a$
1. 对于任意非加法单位元元素 $a$, 存在乘法逆元 $a^{-1}$, 使得 $a \times a^{-1} = a^{-1} \times a = i$
1. 对于任意元素 $x$, $y$, 有加法交换律, 即 $x + y = y + x$
1. 对于任意元素 $x$, $y$, 有乘法交换律, 即 $x \times y = y \times x$
1. 对于任意元素 $x$, $y$, $z$, 有加法结合律, 即 $(x + y) + z = x + (y + z)$
1. 对于任意元素 $x$, $y$, $z$, 有乘法结合律, 即 $(x \times y) \times z = x \times (y \times z)$
1. 对于任意元素 $x$,$y$,$z$, 有乘法分配律, 即 $(x + y) \times z = x \times z + y \times z$

大妖精当然会做啦, 但是他想考考你

在输出中加法单位元 $o$ 即为 $0$, 乘法单位元 $i$ 即为 $1$

### 输入输出格式

#### 输入格式

一个正整数$n$

$2 \leq n \leq 350$

#### 输出格式

第一行输出一个正整数$k$, 若存在$n$元有限域则$k = 0$, 否则$k = -1$

若$k = 0$则

1. 接下来$n$行输出一个$n$元有限域的加法表, 第$i + 1$行第$j + 1$列上的数代表有限域中$i + j$的运算结果
1. 接下来$n$行输出一个$n$元有限域的乘法表, 第$i + 1$行第$j + 1$列上的数代表有限域中$i \times j$的运算结果

共输出$n \times 2 + 1$行

upd1:SPJ 非常严格, 请不要在行末输出多余空格

(答案文件末尾的换行还是会自动忽略的)

upd2:正解文件比较大, 洛谷可能会一直 judging...

如果遇到这种情况请直接提交源代码

### 输入输出样例

#### 输入样例 #1

```input1
2
```

#### 输出样例 #1

```output1
0
0 1
1 0
0 0
0 1
```

### 说明

| 测试点 | [$n$的范围] |      特殊性质      |
| :----: | :---------: | :----------------: |
|   1    |  [$n = 3$]  |     $n$是质数      |
|   2    |  [$n = 4$]  | $n$是 2 的整数次方 |
|   3    |  [$n = 6$]  |         无         |
|   4    |  [$n = 8$]  | $n$是 2 的整数次方 |
|   5    |  [$n = 9$]  |         无         |
|   6    | [$n = 19$]  |     $n$是质数      |
|   7    | [$n = 89$]  |     $n$是质数      |
|   8    | [$n = 181$] |     $n$是质数      |
|   9    | [$n = 233$] |     $n$是质数      |
|   10   | [$n = 25$]  |  $n$是质数的平方   |
|   11   | [$n = 121$] |  $n$是质数的平方   |
|   12   | [$n = 169$] |  $n$是质数的平方   |
|   13   | [$n = 27$]  |         无         |
|   14   | [$n = 143$] |         无         |
|   15   | [$n = 128$] | $n$是 2 的整数次方 |
|   16   | [$n = 81$]  |         无         |
|   17   | [$n = 125$] |         无         |
|   18   | [$n = 243$] |         无         |
|   19   | [$n = 256$] | $n$是 2 的整数次方 |
|   20   | [$n = 343$] |         无         |

## 题意简述

构造一个 $n$ 元有限域 $\mathbb{E}_n$, 不存在时输出 `-1`

## 解题思路

抽代题是吧... 我直接进行一个定理的摆

我们称没有真子域的域为素域

首先域的特征要么为 $0$, 要么为素数 $p$, 进一步我们有

{% note success no-icon %}

**<a id="th-1">定理 - 1</a>** 任意一个域 $\mathbb{F}$ 都含且仅含一个素域

- 当 $\operatorname{char}(\mathbb{F})=0$ 时, $\mathbb{F}$ 的素域与 $\mathbb{Q}$ 同构
- 当 $\operatorname{char}(\mathbb{F})=p$ 时, $\mathbb{F}$ 的素域与 $\Z_p$ 同构

进一步, 两个域的特征相同当且仅当其素域同构

{% note %}

<details open>
<summary>证明</summary>

令

$$\{\mathbb{F}_i|\mathbb{F}_i\leqslant \mathbb{F},i\in I\}$$

为 $\mathbb{F}$ 全体子域构成的集合, 显然其交集 $\mathbb{P}$ 非空,且

- $\mathbb{P}\leqslant\mathbb{F}$
- $\mathbb{P}$ 为 $\mathbb{F}$ 的唯一素域

我们构造如下映射

$$
\begin{aligned}
  \varphi:\Z&\to\mathbb{P}\\
  m&\mapsto me
\end{aligned}
$$

其中 $e$ 为 $\mathbb{F}$ 的幺元, 显然 $\varphi$ 为同态映射

- 若 $\operatorname{char}(\mathbb{F})=0$, 则 $\ker\varphi=\{0\}$, 令
  $$R_e:=\{me|m\in\Z\}$$

  由同态基本定理, $R_e\cong\Z$, $R_e$ 为一整环, 从而其分式域 $\mathbb{F}_e\cong\mathbb{Q}$

  显然

  - $\mathbb{F}_e\leqslant\mathbb{F}$
  - $\mathbb{F}$ 任一素域均包含 $\mathbb{F}_e$

  故 $\mathbb{F}_e$ 即为 $\mathbb{F}$ 同构于 $\mathbb{Q}$ 的素域

- 若 $\operatorname{char}(\mathbb{F})=p$, 则 $\ker\varphi=\{p\}$, 令
  $$R_e:=\{0,e,2e,...,(p-1)e\}$$

  由同态基本定理, $R_e\cong\Z_p$, 而 $\Z_p$ 显然为素域, 故 $R_e$ 即为 $\mathbb{F}$ 同构于 $\Z_p$ 的素域

</details>

{% endnote %}
{% endnote %}

令 $n$ 元有限域为 $\mathbb{E}_n$, 显然其特征必为素数, 故 $n=6$ 和 $n=143$ 的情况直接输出 `-1` 即可

记 $\mathbb{E}_n$ 的素域为 $\mathbb{F}_p$, 其中 $p$ 为 $\mathbb{E}_n$ 的特征

{% note success no-icon %}

**<a id="th-2">定理 - 2</a>** $\forall p\in\text{Prime}^+,m\in\N^+$, $p^m$ 阶有限域必存在且在 $\mathbb{F}_p$-同构意义下是唯一的

{% note %}

<details open>
<summary>证明</summary>

令 $f(x)=x^{p^m}-x\in\mathbb{F}_p[x]$, 作 $\mathbb{F}_p$ 关于 $f(x)$ 的分裂域

$$\mathbb{E}=\mathbb{F}_p(\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{p^m})$$

其中 $\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{p^m}$ 为 $f(x)$ 在 $\mathbb{E}$ 中的根

又由 $\operatorname{char}(\mathbb{F}_p)=p$ 知, $f'(x)=-1$, 从而 $(f(x),f'(x))=1$, 即 $f(x)$ 无重根

令 $\mathbb{L}=\{\def\enum#1{\alpha_{ #1}}\enum{1},\enum{2},...,\enum{p^m}\}$, 则 $\forall\alpha_i,\alpha_j\in\mathbb{L}$

- $$(\alpha_i-\alpha_j)^{p^m}=\alpha_i-\alpha_j\in\mathbb{L}$$
- $$\left(\frac{\alpha_i}{\alpha_j}\right)^{p^m}=\frac{\alpha_i}{\alpha_j}\in\mathbb{L},~(\alpha_j\ne 0)$$

故 $\mathbb{L}\leqslant\mathbb{E}$

又 $\mathbb{F}_p\leqslant\mathbb{L}$, 故 $\mathbb{E}\leqslant\mathbb{L}$

从而 $\mathbb{E}=\mathbb{L}$, $|\mathbb{E}|=|\mathbb{L}|=p^m$

</details>

{% endnote %}
{% endnote %}

故其他数据点均可以构造

首先, 我们知道, $\forall p\in\text{Prime}^+$, $(\Z_p,+,\cdot)$ 为一个域

接下来我们尝试构造素数幂次阶的有限域

{% note success no-icon %}

**<a id="th-3">定理 - 3</a>** 令 $p(x)$ 为 $\mathbb{F}_p[x]$ 中一 $m$ 次首 1 不可约多项式 ($m\geqslant 1$), 则

$$\mathbb{F}_p[x]/\lang p(x)\rang=\left\{\sum_{i=0}^{m-1}a_ix^i+\lang p(x)\rang\bigg|a_i\in\mathbb{F}_p,~i=0,1,...m-1\right\}$$

为一阶为 $p^m$ 的有限域

{% note %}

<details open>
<summary>证明</summary>

易得 $\lang p(x)\rang$ 为 $\mathbb{F}_p[x]$ 的极大理想, 从而 $\mathbb{F}_p[x]/\lang p(x)\rang$ 为一域

由 $\mathbb{F}_p$ 为阶为 $p$ 的素域, 易得
$$|\mathbb{F}_p[x]/\lang p(x)\rang|=p^m$$

</details>

{% endnote %}
{% endnote %}

我们将 $\mathbb{F}_p[x]/\lang p(x)\rang$ 中的多项式看作 $p$ 进制数, 不难发现这个操作是同构映射, 故这题我们就做完了

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa title:Luogu_3923 lang:cpp Luogu/3923/0.py %}

</details>
