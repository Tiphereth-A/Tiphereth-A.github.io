---
title: '题解 - [Luogu P2011] 计算电压'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 数学
  - 物理
  - Kirchhoff定律
  - Kirchhoff第一定律(KCL)
  - 线性方程组
  - Gauss消去法
date: 2021-10-30 00:29:57
---
[题目链接](https://www.luogu.com.cn/problem/P2011)

<!-- more -->

## 原始题面

### 题目背景

相信不少人轻松灭掉 1,2 两题 (蒟蒻无视此句), 我相信, 大家对物理也是很有兴趣的 (众人: 我们对揍人也是很有兴趣的), 那么, 再奉上 100 分给Physicaler 们

### 题目描述

现给定一个电阻网络, 已知其中每条边上的电阻, 和若干个点和负极之间的电压 (电源电压不变), 现在求任意两点之间的电压

### 输入输出格式

#### 输入格式

第一行三个数 $n,m,k,q$, 表示 $n$ 个节点 (可能是几个点用导线相连接, 与一个点等价, 编号为 $1-n$, $0$ 号节点为电源负极), $m$ 个定值电阻, 每个定值电阻连接两个点, $k$ 表示电源正极有 $k$ 个接口, 有 $q$ 个询问

以下 $k$ 行, 每行两整数, 表示电源这 $k$ 个正极的编号与该接线柱与电源负极负极之间的电压 $U_i$

以下 $m$ 行, 每行三个数, $V_i,W_i,R_i$, 表示 $U_i$ 与 $V_i$ 之间添加一条阻值为 $R$ 的电阻丝

以下 $q$ 行, 每行两个整数 $A_i,B_i$, 表示要求 $A_i$ $B_i$ 之间的电压

#### 输出格式

$q$ 行, 每行一个实数, 保留小数点后两位. (若 $A$ 点电压低于 $B$ 点, 输出负值)

### 输入输出样例

#### 输入样例 #1

```input1
3 5 1 3
1 18
1 2 6
1 3 2
2 3 6
3 0 6
2 0 2
1 0
2 3
1 2
```

#### 输出样例 #1

```output1
18.00
-6.00
12.00
```

### 说明

【数据范围】

对于$10\%$的数据, $q=1$

对于$20\%$的数据, $1\leq n\leq 10$,保证电路为串联,并联或混联

对于$40\%$的数据, $1\leq n\leq 40,k\leq 5$

对于$100\%$的数据, $1\leq k\leq n\leq 200,1\leq m\leq 200,000,1\leq R_i,U_i\leq 10,000,1\leq q\leq 1,000,000$

【限制】

时间限制: 2s, 内存限制: 256M

【注释】

样例如图所示

![](1.jpg)

## 解题思路

> 首先 % 罗神

显然直接用 Kirchhoff 第一定律 (KCL) 即可, 设

- 点 $i$ 的电势为 $\varphi_i$
- 已知电势的点 (即与电源正负极直接相连的点) 的指标集为 $\Lambda$
- 电阻网络构成的图为 $G$

则有

$$\begin{cases}
  \varphi_i=U_i,&i\in\Lambda\\
  \displaystyle\sum_{\lang i,j\rang\in G}{\varphi_i-\varphi_j\over R_{ij}}=0,&i\notin\Lambda
\end{cases}$$

另外注意两点

- 加电阻时候是并联, 所以不用处理重边
- 原题的部分数据点有错误 (截至笔者撰此文前), 详见 [此处](https://www.luogu.com.cn/discuss/show/180830)

## 复杂度

$O(n^3+m+q)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-30 00:29:57
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)
#define _rfor(i, r, l, vals...) for (decltype(r - l) i = (r), ##vals; i >= (l); --i)
#define _for_graph(head, e, i, now) for (int i = head[now], to = e[i].to; i; to = e[i = e[i].next].to)

const int N = 200 + 5, M = 4e5 + 5;
const double EPS = 1e-8;

#define _double_equ(x, y) (abs((x) - (y)) <= EPS)

double a[N][N];
void gauss(int n) {
    _for(i, 0, n, m) {
        m = i;

        _for(j, 0, n) if (_double_equ(a[j][i], a[m][i])) m = j;
        if (m != i) _for(j, 0, n + 1) swap(a[m][j], a[i][j]);
        _for(j, i + 1, n) {
            double tmp = a[j][i] / a[i][i];
            _for(k, i, n + 1) a[j][k] -= a[i][k] * tmp;
        }
    }
    _rfor(i, n, 0) {
        _for(j, i + 1, n) a[i][n + 1] -= a[i][j] * a[j][n + 1];
        a[i][n + 1] /= a[i][i];
    }
}

double u[N];

struct Edge {
    double w, to, next;
    Edge(double _w = 0, int _to = 0, int _next = 0) : w(_w), to(_to), next(_next) {}
} e[M];
int head[N], cnt_edge;
int in[N], out[N];
void addEdge(int x, int y, double w) {
    e[++cnt_edge] = Edge(w, y, head[x]);
    head[x] = cnt_edge;
    ++in[y];
    ++out[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    int x, y;
    double z;
    _for(i, 1, k) {
        cin >> x >> z;
        u[x] = z;
    }
    _for(i, 1, m) {
        cin >> x >> y >> z;
        addEdge(x, y, z);
        addEdge(y, x, z);
    }

    a[0][0] = 1;
    _for(i, 1, n) {
        if (_double_equ(u[i], 0)) {
            _for_graph(head, e, j, i) {
                if (to == i) continue;
                a[i][i] += 1.0 / e[j].w;
                a[i][to] -= 1.0 / e[j].w;
            }
            continue;
        }
        a[i][n + 1] = u[i];
        a[i][i] = 1;
        a[i][0] = -1;
    }
    gauss(n);
    cout << fixed << setprecision(2);
    _for(i, 1, q) {
        cin >> x >> y;
        cout << a[x][n + 1] - a[y][n + 1] << '\n';
    }
    return 0;
}
```

</details>