---
title: '题解 - [Luogu P3183] [HAOI2016]食物链'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 省选
  - HAOI
  - 图论
  - 搜索
  - DFS
  - 记忆化搜索
date: 2020-01-15 10:59:32
---
[题目链接](https://www.luogu.com.cn/problem/P3183)

<!-- more -->

## 原始题面

### 题目描述

![](1.png)

如图所示为某生态系统的食物网示意图, 据图回答第1小题

现在给你$n$个物种和$m$条能量流动关系, 求其中的食物链条数.

物种的名称为从$1$到$n$编号

$m$条能量流动关系形如$a_1\to b_1, a_2\to b_2, a_3\to b_3, ..., a_{m-1}\to b_{m-1}, a_m\to b_m$其中$a_i\to b_i$表示能量从物种$a_i$流向物种$b_i$

注意单独的一种孤立生物不算一条食物链

### 输入输出格式

#### 输入格式

第一行两个整数$n$和$m$

接下来$m$行, 每行两个整数$a_i$, $b_i$, 描述$m$条能量流动关系.

数据保证输入数据符号生物学特点, 且不会有重复的能量流动关系出现

$1\leqslant n\leqslant 100000, 0\leqslant m\leqslant 200000$

#### 输出格式

一个整数, 即食物网中的食物链条数

### 输入输出样例

#### 输入样例 #1

```input1
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 5
7 6
7 9
8 5
9 8
10 6
10 7
10 9
```

#### 输出样例 #1

```output1
9
```

## 解题思路

很显然就是一dfs

从入度为$0$的点开始, 每一个点对应的食物链条数是所有出度的食物链条数之和, 出度为$0$的点食物链条数为$1$

注意所有点不一定连通 (当时漏看这个直接20pts)

但是直接暴搜肯定不行, 需要记忆化

## 时间复杂度

$O(m+n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-01-15 10:59:32
 * @Description:
 */
i64 n, m;
struct edge {
    i64 to, next;
} e[M];
i64 head[N], cnt;
void add(i64 u, i64 v) {
    e[++cnt] = {v, head[u]};
    head[u] = cnt;
}
int in[N], out[N];

i64 f[N];
i64 dfs(i64 pos) {
    if (f[pos]) return f[pos];
    if (in[pos] && !out[pos]) return f[pos] = 1;
    for (i64 i = head[pos]; i; i = e[i].next) f[pos] += dfs(e[i].to);
    return f[pos];
}

int main() {
    read(n, m);
    for (i64 i = 1, x, y; i <= m; ++i) {
        read(x, y);
        add(x, y);
        ++in[y];
        ++out[x];
    }
    i64 ans = 0;
    _for(i, 1, n) if (!in[i]) ans += dfs(i);
    print(ans);
    FastIO::flush();
    return 0;
}
```

</details>