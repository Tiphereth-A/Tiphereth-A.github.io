---
title: 笔记 - 精确覆盖问题, 重复覆盖问题与DLX
categories:
  - 程序设计
  - 笔记
tags:
  - 程序设计
  - 算法
  - 笔记
  - 模板
  - 数据结构
  - 精确覆盖问题
  - X算法
  - DLX
  - 重复覆盖问题
  - 搜索
  - 剪枝
  - 迭代加深搜索
  - IDA*
  - 链表
  - 双向十字链表
date: 2020-10-25 16:54:34
---

DLX(Dancing Links X)是一种用于解决精确覆盖问题的优美算法

<!-- more -->

## 精确覆盖问题

> **定义** 精确覆盖问题
>
> 对有限集$S=\{a_i|i\in[1,n]\cap\N\}$, 给定集合$T=\{T_i\subseteq S|i\in[1,m]\cap\N\}$, 设$T^*:=\{T_i^*|i\in[1,l]\cap\N,l\leqslant m\}\subseteq 2^T$满足
>
> - $\displaystyle\bigcup_{T_i^*\in T^*} T_i^*=S$
> - $\forall A,B\in T^*,A\cap B\ne\varnothing\iff A=B$
>
> 称 寻找$T^*$ 这一问题为**精确覆盖问题**

换句话说就是在给定的$S$若干子集中寻找能精确覆盖$S$的部分

精确覆盖指$S$中任意元素在这些集合中**恰好**出现一次

如设

$$S=\{1,2,3,4,5,6,7\}$$

$$
\begin{matrix}
    T_1 =\{1,4,7\}&T_2 =\{3,5,6\}&T_3 =\{4,5,7\}&T_4 =\{2,7\}\phantom{,1}\\
    T_5 =\{1,4\}\phantom{,1}&T_6 =\{3,6\}\phantom{,1}&T_7 =\{2,3,6\}&T_8 =\{1,4,6\}
\end{matrix}
$$

则$\{T_2,T_4,T_5\}$即是我们要找的解

## X 算法

X 算法即是一种用于解决精确覆盖问题的算法, 在介绍其流程前, 我们先做一些必要的准备工作

以上节例子为例, 我们先画个这样的表格

$$
\def\arraystretch{1.5}
\begin{array}{c|ccccccc}
    \texttt{head}&1&2&3&4&5&6&7\\ \hline
    1&1&0&0&1&0&0&1\\
    2&0&0&1&0&1&1&0\\
    3&0&0&0&1&1&0&1\\
    4&0&1&0&0&0&0&1\\
    5&1&0&0&1&0&0&0\\
    6&0&0&1&0&0&1&0\\
    7&0&1&1&0&1&0&0\\
    8&1&0&0&1&0&1&0\\
\end{array}
$$

其中第$i$行第$j$列表示$T_i$内是否有$a_j$, $1$代表有, $0$代表没有

可以记作

$$
\begin{matrix}
  \texttt{h} & \begin{matrix}
    1&2&3&4&5&6&7
  \end{matrix} \\
  \begin{matrix}
    1\\2\\3\\4\\5\\6\\7\\8
  \end{matrix} & \begin{bmatrix}
    1&0&0&1&0&0&1\\
    0&0&1&0&1&1&0\\
    0&0&0&1&1&0&1\\
    0&1&0&0&0&0&1\\
    1&0&0&1&0&0&0\\
    0&0&1&0&0&1&0\\
    0&1&1&0&1&0&0\\
    1&0&0&1&0&1&0\\
  \end{bmatrix}
\end{matrix}
$$

为了方便查看, 我们省去多余成分, 并将其看作矩阵, 即

$$
\begin{bmatrix}
    1&0&0&1&0&0&1\\
    0&0&1&0&1&1&0\\
    0&0&0&1&1&0&1\\
    0&1&0&0&0&0&1\\
    1&0&0&1&0&0&0\\
    0&0&1&0&0&1&0\\
    0&1&1&0&1&0&0\\
    1&0&0&1&0&1&0\\
\end{bmatrix}
$$

为了方便之后的叙述, 我们做如下约定

| 表达式 | 含义                                                                                        |
| ------ | ------------------------------------------------------------------------------------------- |
| $w$    | 矩阵宽度                                                                                    |
| $h$    | 矩阵高度                                                                                    |
| $N$    | 所有结点构成的集合                                                                          |
| $R(i)$ | 第$i$行的所有结点,<br>或 结点$i$所在行的所有结点,<br>或 结点集$i$中所有结点所在行的所有结点 |
| $C(i)$ | 第$i$列的所有结点,<br>或 结点$i$所在列的所有结点,<br>或 结点集$i$中所有结点所在列的所有结点 |
| $r(i)$ | 结点$i$的对应行                                                                             |
| $c(i)$ | 结点$i$的对应列                                                                             |

X 算法的流程如下

> 此时我们认为矩阵中的元素即为结点

1. 选取$|R(l)|>0$的行$l$
1. 如果没有可选行或尝试了所有可选的行仍未找到可行解, 则无解, 返回上一层
1. 记录$r(l)$
1. 标记并删除$R(l)$, $C(R(l))$和$R(C(R(l)))$
1. 若矩阵为空矩阵
   1. 若$R(l)$里结点全为$1$, 则说明找到了一组可行解, 输出所有标记的编号并退出
   1. 若$R(l)$里结点有$0$, 则不能构成覆盖, 还原删除的结点并返回上一层
1. 对新矩阵递归调用该算法
1. 取消 3 并还原删除的结点

估计看到这里的你们是一脸懵逼的, 下面我们对上例跑一遍流程

> **强烈建议初学者手动模拟一遍**

<details open>
<summary><font color='orange' id="eg-2.1">Show / Hide</font></summary>
<a href="#end-eg-2.1">Go to the end</a>

$$
\begin{bmatrix}
    1&0&0&1&0&0&1\\
    0&0&1&0&1&1&0\\
    0&0&0&1&1&0&1\\
    0&1&0&0&0&0&1\\
    1&0&0&1&0&0&0\\
    0&0&1&0&0&1&0\\
    0&1&1&0&1&0&0\\
    1&0&0&1&0&1&0\\
\end{bmatrix}
$$

- 首先我们定义栈$A$用于存储枚举列的编号, 初始时$A$为空
- 选取第$1$行, $A=\{1\}$
- 标记$R(1)$, $C(R(1))$(第$1,4,7$列), $R(C(R(1)))$ (第$3,4,5,8$列)

  我们将三次标记的部分分别染成<font color="e800e8">暗品红色</font>, <font color="e8e800">暗黄色</font>, <font color="00e8e8">暗青色</font>, 分三次展示

  {% tabs tab,1 %}
  <!-- tab 第一次 -->

  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
    \m 1&\m 0&\m 0&\m 1&\m 0&\m 0&\m 1\\
    0&0&1&0&1&1&0\\
    0&0&0&1&1&0&1\\
    0&1&0&0&0&0&1\\
    1&0&0&1&0&0&0\\
    0&0&1&0&0&1&0\\
    0&1&1&0&1&0&0\\
    1&0&0&1&0&1&0\\
  \end{bmatrix}
  $$

  <!-- endtab -->
  <!-- tab 第二次 -->

  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
    \m 1&\m 0&\m 0&\m 1&\m 0&\m 0&\m 1\\
    \y 0&0&1&\y 0&1&1&\y 0\\
    \y 0&0&0&\y 1&1&0&\y 1\\
    \y 0&1&0&\y 0&0&0&\y 1\\
    \y 1&0&0&\y 1&0&0&\y 0\\
    \y 0&0&1&\y 0&0&1&\y 0\\
    \y 0&1&1&\y 0&1&0&\y 0\\
    \y 1&0&0&\y 1&0&1&\y 0\\
  \end{bmatrix}
  $$

  <!-- endtab -->
  <!-- tab 第三次 -->

  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
    \m 1&\m 0&\m 0&\m 1&\m 0&\m 0&\m 1\\
    \y 0&0&1&\y 0&1&1&\y 0\\
    \y 0&\c 0&\c 0&\y 1&\c 1&\c 0&\y 1\\
    \y 0&\c 1&\c 0&\y 0&\c 0&\c 0&\y 1\\
    \y 1&\c 0&\c 0&\y 1&\c 0&\c 0&\y 0\\
    \y 0&0&1&\y 0&0&1&\y 0\\
    \y 0&1&1&\y 0&1&0&\y 0\\
    \y 1&\c 0&\c 0&\y 1&\c 0&\c 1&\y 0\\
  \end{bmatrix}
  $$

  <!-- endtab -->

  {% endtabs %}

- 删去标记的元素

  新矩阵即为

  $$
  \begin{bmatrix}
      0&1&1&1\\
      0&1&0&1\\
      1&1&1&0\\
  \end{bmatrix}
  $$

- 选取第$1$行, 其在原矩阵中对应编号为$2$, $A=\{1,2\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
      \m 0&\m 1&\m 1&\m 1\\
      \c 0&\y 1&\y 0&\y 1\\
      \c 1&\y 1&\y 1&\y 0\\
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
    &
  \end{bmatrix}
  $$
- 我们得到了空矩阵, 但第一次标记的行非全$1$, 所以返回上一层, $A=\{1\}$
  $$
  \begin{bmatrix}
      0&1&1&1\\
      0&1&0&1\\
      1&1&1&0\\
  \end{bmatrix}
  $$
- 选取第$2$行, 其在原矩阵中对应编号为$6$, $A=\{1,6\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
      \c 0&\y 1&\c 1&\y 1\\
      \m 0&\m 1&\m 0&\m 1\\
      \c 1&\y 1&\c 1&\y 0\\
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
    &
  \end{bmatrix}
  $$
- 我们得到了空矩阵, 但第一次标记的行非全$1$, 所以返回上一层, $A=\{1\}$
  $$
  \begin{bmatrix}
      0&1&1&1\\
      0&1&0&1\\
      1&1&1&0\\
  \end{bmatrix}
  $$
- 选取第$3$行, 其在原矩阵中对应编号为$7$, $A=\{1,7\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
      \y 0&\y 1&\y 1&\c 1\\
      \y 0&\y 1&\y 0&\c 1\\
      \m 1&\m 1&\m 1&\m 0\\
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
    &
  \end{bmatrix}
  $$
- 我们得到了空矩阵, 但第一次标记的行非全$1$, 返回上一层, $A=\{1\}$

  $$
  \begin{bmatrix}
      0&1&1&1\\
      0&1&0&1\\
      1&1&1&0\\
  \end{bmatrix}
  $$

- 我们已经选过所有行但均未找到可行解, 返回上一层, $A=\{\}$
  $$
  \begin{bmatrix}
      1&0&0&1&0&0&1\\
      0&0&1&0&1&1&0\\
      0&0&0&1&1&0&1\\
      0&1&0&0&0&0&1\\
      1&0&0&1&0&0&0\\
      0&0&1&0&0&1&0\\
      0&1&1&0&1&0&0\\
      1&0&0&1&0&1&0\\
  \end{bmatrix}
  $$
- 选取第$2$行, $A=\{2\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
      1&0&\y 0&1&\y 0&\y 0&1\\
      \m 0&\m 0&\m 1&\m 0&\m 1&\m 1&\m 0\\
      \c 0&\c 0&\y 0&\c 1&\y 1&\y 0&\c 1\\
      0&1&\y 0&0&\y 0&\y 0&1\\
      1&0&\y 0&1&\y 0&\y 0&0\\
      \c 0&\c 0&\y 1&\c 0&\y 0&\y 1&\c 0\\
      \c 0&\c 1&\y 1&\c 0&\y 1&\y 0&\c 0\\
      \c 1&\c 0&\y 0&\c 1&\y 0&\y 1&\c 0\\
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
      1&0&1&1\\
      0&1&0&1\\
      1&0&1&0\\
  \end{bmatrix}
  $$
- 选取第$1$行, 其在原矩阵中对应编号为$1$, $A=\{2,1\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
      \m 1&\m 0&\m 1&\m 1\\
      \y 0&\c 1&\y 0&\y 1\\
      \y 1&\c 0&\y 1&\y 0\\
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
    &
  \end{bmatrix}
  $$
- 我们得到了空矩阵, 但第一次标记的行非全$1$, 返回上一层, $A=\{2\}$
  $$
  \begin{bmatrix}
      1&0&1&1\\
      0&1&0&1\\
      1&0&1&0\\
  \end{bmatrix}
  $$
- 选取第$2$行, 其在原矩阵中对应编号为$4$, $A=\{2,4\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
      \c 1&\y 0&\c 1&\y 1\\
      \m 0&\m 1&\m 0&\m 1\\
      1&\y 0&1&\y 0\\
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
    1&1
  \end{bmatrix}
  $$
- 选取第$1$行, 其在原矩阵中对应编号为$5$, $A=\{2,4,5\}$
- 进行三次标记
  $$
  \def\m#1{\color{e800e8} #1}
  \def\y#1{\color{e8e800} #1}
  \def\c#1{\color{00e8e8} #1}
  \begin{bmatrix}
    \m 1&\m 1
  \end{bmatrix}
  $$
- 删去标记的元素
  $$
  \begin{bmatrix}
    &
  \end{bmatrix}
  $$
- 我们得到了空矩阵, 且第一次标记的行全为$1$, 说明我们找到了可行解, 返回$A=\{2,4,5\}$, 即$\{T_2,T_4,T_5\}$是我们要找的解

<a href="#eg-2.1" id="end-eg-2.1">Go back</a>

</details>

## DLX

我们发现 X 算法涉及大量的删除/恢复某行&列, 所以如果只是暴力实现, 即使它很高效, 我们也很难接受其巨大的常数

所幸~~真神~~Donald E. Knuth 设计了一个数据结构(双向十字链表)使得上述操作能高效实现, 同时代码还足够简洁 (原文[点此下载](https://www-cs-faculty.stanford.edu/~knuth/fasc5c.ps.gz))

因为在双向十字链表上进行删除和恢复操作时可看作是指针在不停跳动, 所以这个数据结构又被称为**舞蹈链**(Dancing links), 用舞蹈链优化的 X 算法就被叫做**DLX 算法**(Dancing Links X algorithm)

对于舞蹈链中的一个结点, 其连接方式如下

![](DLX_part.svg)

其删除与恢复自然和双向链表一致

![](DLX_change.svg)

我们看看对下例建立的舞蹈链是什么样子的

$$
\def\arraystretch{1.5}
\begin{array}{c:ccccccc}
    \texttt{head}&1&2&3&4&5&6&7\\ \hline
    1&1&0&0&1&0&0&1\\
    2&0&0&1&0&1&1&0\\
    3&0&0&0&1&1&0&1\\
    4&0&1&0&0&0&0&1\\
    5&1&0&0&1&0&0&0\\
    6&0&0&1&0&0&1&0\\
    7&0&1&1&0&1&0&0\\
    8&1&0&0&1&0&1&0\\
\end{array}
$$

这回我们略去所有的$0$, 因为其不会在链表里出现

$$
\begin{matrix}
    \texttt{head}&1&2&3&4&5&6&7\\
    \texttt{1}&1& & &1& & &1\\
    \texttt{2}& & &1& &1&1& \\
    \texttt{3}& & & &1&1& &1\\
    \texttt{4}& &1& & & & &1\\
    \texttt{5}&1& & &1& & & \\
    \texttt{6}& & &1& & &1& \\
    \texttt{7}& &1&1& &1& & \\
    \texttt{8}&1& & &1& &1& \\
\end{matrix}
$$

对应的舞蹈链就是这样的

![](DLX.svg)

代码具体如何实现呢

> **建议在看完准备工作后自行尝试实现初始化, 删除与恢复操作**

### 准备工作

#### 存储

对于任意一个结点, 其均具有 4 个指针, 也就是

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
struct Node {
    struct Node* up;
    struct Node* down;
    struct Node* left;
    struct Node* right;

    Node(Node* const _up = nullptr,
         Node* const _down = nullptr,
         Node* const _left = nullptr,
         Node* const _right = nullptr) : up(_up), down(_down), left(_left), right(_right) {}
};
```

</details>

我们也可以用内存池存储

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
const std::size_t MAX_SIZE = 1e5 + 5;
struct Node {
    std::size_t up, down, left, right;

    Node(std::size_t _up = 0,
         std::size_t _down = 0,
         std::size_t _left = 0,
         std::size_t _right = 0) : up(_up), down(_down), left(_left), right(_right) {}
} nodes[MAX_SIZE];
std::size_t cnt_node;
```

</details>

其次, 我们还需要记录结点所在行和列的编号, 最后结点的代码如下

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
struct Node {
    std::size_t up, down, left, right;
    std::size_t row, col;

    Node(std::size_t _up = 0,
         std::size_t _down = 0,
         std::size_t _left = 0,
         std::size_t _right = 0,
         std::size_t _row = 0,
         std::size_t _col = 0) : up(_up), down(_down), left(_left), right(_right), row(_row), col(_col) {}
};
```

</details>

除此之外我们还需如下变量

- `width` : 宽度(即$|S|$)
- `height` : 高度(即$|B|$)
- `cnt_col[]` : 每一列的结点数, 用于常数优化

最后代码如下

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
const std::size_t MAX_SIZE = 1e5 + 5;
const std::size_t MAX_EDGE = 5e3 + 5;

struct Node {
    std::size_t up, down, left, right;
    std::size_t row, col;

    Node(std::size_t _up = 0,
         std::size_t _down = 0,
         std::size_t _left = 0,
         std::size_t _right = 0,
         std::size_t _row = 0,
         std::size_t _col = 0) : up(_up), down(_down), left(_left), right(_right), row(_row), col(_col) {}
} nodes[MAX_SIZE];
std::size_t cnt_node;

std::size_t width, height;
std::size_t cnt_col[MAX_EDGE];
```

</details>

- Q: `head`结点, 行首结点和列首结点存在哪里

  A: 实际上

  - 行首结点是虚拟结点, 不需要存

  - `head`结点存为 `node[0]`

  - 第$i$列的首结点存为 `node[i]`

- Q: 常数优化是什么

  A: 见[此节内容](#dance)

另外

- 为了方便后面写代码, 我们做如下宏定义

  <details open>
  <summary><font color='orange'>Show code</font></summary>

  ```cpp
  #define _l(id) node[id].l
  #define _r(id) node[id].r
  #define _u(id) node[id].u
  #define _d(id) node[id].d
  #define _row(id) node[id].row
  #define _col(id) node[id].col
  // 沿某方向遍历一条链
  #define _for(i, start, dir) for (std::size_t i = _##dir(start); i != start; i = _##dir(i))
  ```

  </details>

#### 初始化

分成两步

- 存入`head`结点和列首结点
- 存入其他结点

##### 存入`head`结点和列首结点

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
void init(std::size_t _width, std::size_t _height) {
    width = cnt_node = _width;
    height = _height;
    for (std::size_t i = 1; i <= width; ++i) node[i] = {i - 1, i + 1, i, i, 0, i};
    node[_r(width) = 0] = {width, 1, 0, 0, 0, 0};
}
```

</details>

##### 存入其他结点

在实现中往往是顺次插入$R(1)$到$R(h)$的, 此时当我们插入某个点`x`时, 我们发现:

- `node[x].l`即为上一个插入的结点下标, 即`x-1`
- `node[x].r`即为第一个插入的结点下标
- `node[x].u`即为列首结点上方结点的下标, 即`_u(_col(x))`
- `node[x].d`即为列首结点下标, 即`_col(x)`

代码实现如下

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
/**
  * @param std::size_t  _ln       : i
  * @param std::size_t* _cols     : R(i)中所有结点的列编号
  * @param std::size_t  _len_cols : |R(i)|
  */
void insert_row(std::size_t _ln, std::size_t* const _cols, std::size_t _len_cols) {
    for (std::size_t i = 1; i <= _len_cols; ++i) {
        node[cnt_node + i] = {cnt_node + i - 1, cnt_node + i + 1, _u(_cols[i]), _cols[i], _ln, _cols[i]};
        _d(_u(_cols[i])) = cnt_node + i;
        _u(_cols[i]) = cnt_node + i;
        ++cnt_col[_cols[i]];
        if (_d(_cols[i]) == _cols[i]) _d(_cols[i]) = cnt_node + i;
    }
    _l(cnt_node + 1) = cnt_node + _len_cols;
    _r(cnt_node + _len_cols) = cnt_node + 1;
    cnt_node += _len_cols;
}
```

</details>

### 求解

#### 删除

我们这样定义删除操作`remove`:

- 接收一个参数`_col`: 代表要删除的列
- 功能是删除某一列和与这一列相交的所有行

结合该图我们不难写出代码

![](DLX_change.svg)

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
void remove_col(std::size_t _now_col) {
    _r(_l(_now_col)) = _r(_now_col);
    _l(_r(_now_col)) = _l(_now_col);
    _for(i, _now_col, d) _for(j, i, r) {
        _u(_d(j)) = _u(j);
        _d(_u(j)) = _d(j);
        --cnt_col[_col(j)];
    }
}
```

</details>

#### 恢复

恢复操作和删除操作类似, 在此不再赘述

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
void resume_col(std::size_t _now_col) {
    _r(_l(_now_col)) = _l(_r(_now_col)) = _now_col;
    _for(i, _now_col, u) _for(j, i, r) {
        _u(_d(j)) = _d(_u(j)) = j;
        ++cnt_col[_col(j)];
    }
}
```

</details>

---

上面的都是舞蹈链的操作, 接下来才是重点

#### dance

我们根据舞蹈链的性质, 对 X 算法流程进行一些调整

1. 选取某一列$i$并对其执行`remove`操作
1. 枚举$C(i)$中的结点$j$
   1. 记录$r(j)$, 对$R(j)$中所有结点的列编号执行`remove`操作
   1. 若`node[head].r == head`, 则说明找到了解, 对$R(j)$中所有结点的列编号执行`resume`操作并返回`true`
   1. 对$R(j)$中所有结点的列编号执行`resume`操作
1. 对列$i$中所有结点的列编号执行`resume`操作
1. 返回`false`

我们注意到第一步中选取的列不影响最终答案, 所以我们可以加个常数优化, 即选取$|C(i)|$最小的$i$

值得注意的是, $R(j)$删除的顺序和恢复的顺序是**相反**的, 即若你删除行中结点是**从左向右**删, 则恢复时要**从右向左**恢复 (类比递归和回溯的顺序关系)

如果相同则会显著降低代码速度, 具体在后文讲述

我们可以结合例子模拟一遍

<details open>
<summary><font color='orange' id="eg-3.1">Show / Hide</font></summary>
<a href="#end-eg-3.1">Go to the end</a>

![](DLX.svg)

我们不考虑常数优化, 每次只选取`node[head].r`删除, 则一共会执行$13$次`remove`操作和$6$次`resume`操作

1. `remove 1`

   ![](DLX_1.svg)

1. `remove 4` & `remove 7`

   ![](DLX_2.svg)

1. `remove 2`

   ![](DLX_3.svg)

1. `remove 3` & `remove 5`

   ![](DLX_4.svg)

1. `remove 6`

   ![](DLX_5.svg)

1. `resume 6`

   ![](DLX_4.svg)

1. `resume 5` & `resume 3`

   ![](DLX_3.svg)

1. `resume 2`

   ![](DLX_2.svg)

1. `resume 7` & `resume 4`

   ![](DLX_1.svg)

1. `remove 4`

   ![](DLX_6.svg)

1. `remove 2`

   ![](DLX_7.svg)

1. `remove 7`

   ![](DLX_8.svg)

1. `remove 3`

   ![](DLX_9.svg)

1. `remove 5` & `remove 6`

   ![](DLX_10.svg)

<a href="#eg-3.1" id="end-eg-3.1">Go back</a>

</details>

加上常数优化后, 代码就是这样的

<details open>
<summary><font color='orange'>Show code</font></summary>

```cpp
std::size_t find_min_col() {
    std::size_t res = _r(0);
    _for(i, 0, r) if (cnt_col[i] < cnt_col[res]) res = i;
    return res;
}

/**
  * @param std::size_t* _ans : 答案
  * @param std::size_t& _len : 答案长度
  * @return bool : 是否有解
  */
bool dance(std::size_t* _ans, std::size_t& _len) {
    if (_r(0) == 0) return true;
    std::size_t now_r = find_min_col();
    remove_col(now_r);
    _for(i, now_r, d) {
        _ans[++_len] = _row(i);
        _for(j, i, r) remove_col(_col(j));
        if (dance(_ans, _len)) {
            _for(j, i, l) resume_col(_col(j));
            return true;
        }
        --_len;
        _for(j, i, l) resume_col(_col(j));
    }
    resume_col(now_r);
    return false;
}
```

</details>

### 关于删除和恢复的顺序

我在上面说过: 删除和恢复的方向相同时速度会显著变慢, 这里举一例来具体说明

以下图为例

![](DLX_del_1.svg)

首先我们先删除

|    操作    |        结果        |
| :--------: | :----------------: |
| `remove 1` | ![](DLX_del_2.svg) |
| `remove 3` | ![](DLX_del_3.svg) |
| `remove 4` | ![](DLX_del_4.svg) |

之后我们恢复

|           方向相反[^1]            |           方向相同[^2]           |
| :-------------------------------: | :------------------------------: |
| `resume 4`<br>![](DLX_del_8.svg)  | `resume 1`<br>![](DLX_del_5.svg) |
| `resume 3`<br>![](DLX_del_9.svg)  | `resume 3`<br>![](DLX_del_6.svg) |
| `resume 1`<br>![](DLX_del_10.svg) | `resume 4`<br>![](DLX_del_7.svg) |

[^1]: <font color="e1d5e7">淡紫色</font>的结点是重复恢复的结点, <font color="3700cc">靛蓝色</font>的指针是重复赋值的指针
[^2]: <font color="e1d5e7">淡紫色</font>的结点是重复恢复一次的结点, <font color="b266ff">浅紫色</font>的结点是重复恢复两次的结点, <font color="3700cc">靛蓝色</font>的指针是重复赋值一次的指针, <font color="a50040">枣红色</font>的指针是重复赋值两次的指针

我们注意到这两种方式都是正确的, 但是如果删除和恢复的方向相同, 则会重复恢复更多结点, 连带着也会重复赋值更多指针, 所以就会变慢

比较极端的情况可以在 洛谷 [P1074 靶形数独](https://www.luogu.com.cn/problem/P1074) 中的数据点#13 找到, 两种不同的恢复顺序能使得最后时间相差十多倍

### 时间复杂度

不难发现是$O(c^n)$的, 其中$c$是个接近$1$的数, $n$是舞蹈链中结点个数

在实际应用中, 因为$c$足够接近$1$, 所以 DLX 效率很高

### 例题

- 洛谷 [P4929 【模板】舞蹈链（DLX）](https://www.luogu.com.cn/problem/P4929)

  <details>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb cpa lang:cpp Luogu/4929/0.cpp %}

  </details>

- 洛谷 [P1074 靶形数独](https://www.luogu.com.cn/problem/P1074) -> {% post_link luogu-p1074 题解 %}
- 洛谷 [P4205 [NOI2005]智慧珠游戏](https://www.luogu.com.cn/problem/P4205) -> {% post_link luogu-p4205 题解 %}

## 重复覆盖问题

从字面意思上看, 重复覆盖问题只需要将精确覆盖问题里的**精确覆盖**改为**可重复覆盖**即可

可重复覆盖指$S$中任意元素在这些集合中**至少**出现一次

因为改为可重复覆盖后很容易出现多解, 所以我们更关心用于覆盖的集合个数最小的解

所以我们定义重复覆盖问题如下

> **定义** 重复覆盖问题
>
> 对有限集$S=\{a_i|i\in[1,n]\cap\N\}$, 给定集合$T=\{T_i\subseteq S|i\in[1,m]\cap\N\}$, 设$T^*:=\{T_i^*|i\in[1,l]\cap\N,l\leqslant m\}\subseteq 2^T$满足
>
> - $\displaystyle\bigcup_{T_i^*\in T^*} T_i^*=S$
> - $\displaystyle|T^*|=\min_{T'\in 2^T}\{|T'|\}$
>
> 称 寻找$T^*$ 这一问题为**重复覆盖问题**

### 解法

解决重复覆盖问题时我们只需省去在精确覆盖问题中三次标记中的最后一次标记即可

而这样做会导致状态空间爆炸, 所以我们需要做优化

我们发现这和迭代加深搜索的思想有契合之处, 即预设一个最大深度`max_depth` (在此处即为预设$|B^*|$的最大值$M$), 然后尝试求解, 根据返回情况调整`max_depth`

求解的流程如下

1. 选取使$|C(i)|$最小的列$i$
1. 如果没有可选列或尝试了所有可选列仍未找到可行解, 则返回`false`
1. 枚举$C(i)$中的结点$j$
   1. 记录$r(j)$
   1. 删除$R(j),C(j)$
   1. 若当前已删除了$M$行且仍为找到结果, 则返回`false`
   1. 对当前矩阵递归搜索
      1. 若返回`true`, 则**恢复矩阵**并返回`true`
   1. 取消记录$r(j)$并还原删除的结点
1. 还原删除的结点
1. 返回`false`

我们还可以设计估价函数$H$来加速求解过程, 也就是应用 IDA\*

接下来枚举或者二分`max_depth`即可

附模板, 输入方式与 洛谷 [P4929 【模板】舞蹈链（DLX）](https://www.luogu.com.cn/problem/P4929) 相同

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp dlx/multi_DLX.cpp %}

</details>

### 例题

- POJ [1084 Square Destroyer](https://vjudge.net/problem/POJ-1084/origin)
- FZU [1686 神龙的难题](https://acm.fzu.edu.cn/problem.php?pid=1686)

---

## 参考资料

- <https://www.cnblogs.com/grenet/p/3145800.html>
- <https://leverimmy.top/posts/lectures/dlx>
- <https://blog.csdn.net/whereisherofrom/article/details/79220897>
