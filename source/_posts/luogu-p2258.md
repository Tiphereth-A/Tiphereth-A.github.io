---
title: '题解 - [Luogu P2258] [NOIP2014 普及组] 子矩阵'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - NOIp
  - NOIp普及组
  - DP
  - 状态压缩
  - 区间DP
  - 剪枝
date: 2021-10-29 03:09:51
---
[题目链接](https://www.luogu.com.cn/problem/P2258)

<!-- more -->

## 原始题面

### 题目描述

给出如下定义:

1. 子矩阵: 从一个矩阵当中选取某些行和某些列交叉位置所组成的新矩阵 (保持行与列的相对顺序) 被称为原矩阵的一个子矩阵

    例如, 下面左图中选取第$2$, $4$行和第$2$, $4$, $5$列交叉位置的元素得到一个$2 \times 3$的子矩阵如右图所示

    ```text
    9 3 3 3 9
    9 4 8 7 4
    1 7 4 6 6
    6 8 5 6 9
    7 4 5 6 1
    ```

    的其中一个$2 \times 3$的子矩阵是

    ```text
    4 7 4
    8 6 9
    ```

1. 相邻的元素: 矩阵中的某个元素与其上下左右四个元素 (如果存在的话) 是相邻的

1. 矩阵的分值: 矩阵中每一对相邻元素之差的绝对值之和

本题任务: 给定一个$n$行$m$列的正整数矩阵, 请你从这个矩阵中选出一个$r$行$c$列的子矩阵, 使得这个子矩阵的分值最小, 并输出这个分值

(本题目为2014NOIP普及T4)

### 输入输出格式

#### 输入格式

第一行包含用空格隔开的四个整数$n,m,r,c$, 意义如问题描述中所述, 每两个整数之间用一个空格隔开

接下来的$n$行, 每行包含$m$个用空格隔开的整数, 用来表示问题描述中那个$n$行$m$列的矩阵

#### 输出格式

一个整数, 表示满足题目描述的子矩阵的最小分值

### 输入输出样例

#### 输入样例 #1

```input1
5 5 2 3
9 3 3 3 9
9 4 8 7 4
1 7 4 6 6
6 8 5 6 9
7 4 5 6 1
```

#### 输出样例 #1

```output1
6
```

#### 输入样例 #2

```input2
7 7 3 3
7 7 7 6 2 10 5
5 8 8 2 1 6 2
2 9 5 5 6 1 7
7 9 3 6 1 7 8
1 9 1 4 7 8 8
10 5 9 1 1 8 10
1 3 1 5 4 8 6
```

#### 输出样例 #2

```output2
16
```

### 说明

【输入输出样例1说明】

该矩阵中分值最小的$2$行$3$列的子矩阵由原矩阵的第$4$行, 第$5$行与第$1$列, 第$3$列, 第$4$列交叉位置的元素组成, 为

```text
6 5 6
7 5 6
```

其分值为: |6-5| + |5-6| + |7-5| + |5-6| + |6-7| + |5-5| + |6-6| =6

【输入输出样例2说明】

该矩阵中分值最小的3行3列的子矩阵由原矩阵的第$4$行, 第$5$行, 第$6$行与第$2$列, 第$6$列, 第$7$列交叉位置的元素组成, 选取的分值最小的子矩阵为

```text
9 7 8
9 8 8
5 8 10
```

【数据说明】

对于$50\%$的数据, $1 \leq n \leq 12,1 \leq m \leq 12$, 矩阵中的每个元素$1 \leq a_{ij} \leq 20$

对于$100\%$的数据, $1 \leq n \leq 16,1 \leq m \leq 16$, 矩阵中的每个元素$1 \leq a_{ij} \leq 1,000,1 \leq r \leq n,1 \leq c \leq m$

## 解题思路

显然 DP, 如果是一维的情况, 显然就是个区间DP

令 $f(i,j)$ 表示选第 $i$ 个且已选 $j$ 个时候的最优值, 则

$$f(i,j)=\min\{f(i',j-1)+|a_{i'}-a_i|\}$$

二维的做法相同, 这时候我们要开四维数组

令

- $f(i,j,k,l)$ 表示选第 $i$ 行第 $k$ 列且已选 $j$ 行 $l$ 列时候的最优值
- $I$ 为当前已选的行指标集, 其最大值为 $x$
- $K$ 为当前已选的列指标集, 其最大值为 $y$
- $$S(I,K)=\sum_{\{k_i\}=K;k_i<k_{i+1}}|a_{x,k_i}-a_{x,k_{i-1}}|+\sum_{\{i_k\}=I;i_k<i_{k+1}}|a_{i_k,y}-a_{i_{k-1},y}|$$

则

$$f(i,j,k,l)=\min\left\{f(i',j-1,k',l-1)+\sum_{u\in K}|a_{i',u}-a_{i,u}|+\sum_{v\in I}|a_{v,k'}-a_{v,k}|+S(I,K)\right\}$$

可以使用状态压缩来将DP数组变为三维, 方法是对某一方向上的方案进行状态压缩, 如行的选择方案

注意要剪枝, 如当前选择行的个数不为 $r$ 则跳过

## 复杂度

$O\left({n\choose {n\over 2}}m^3\right)$ 或 $O\left({m\choose {m\over 2}}n^3\right)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-29 03:09:51
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

const int N = 16 + 1;

int a[N][N], f[N][N][(1 << (N - 1)) + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    _for(i, 1, n) _for(j, 1, m) cin >> a[i][j];
    _for(i, 1, m) _for(j, 1, n) memset(f[i][j], 0x3f, sizeof(f[i][j][0]) * (1 << n));

    int ans = INT32_MAX;
    _for(i, 1, m) _for(state_row, (1 << r) - 1, (1 << n) - 1) {
        vector<int*> vec;
        for (int _ = 0; (1 << _) <= state_row; ++_)
            if ((1 << _) & state_row) vec.push_back(a[_ + 1]);
        if (vec.size() != r) continue;

        int score_i = 0;
        for (auto it = vec.begin() + 1; it != vec.end(); ++it) score_i += abs((*it)[i] - (*(it - 1))[i]);

        _for(j, 1, min(i, c)) _for(k, j - 1, i - 1, score) {
            score = 0;
            if (k)
                for (const auto& p : vec) score += abs(p[k] - p[i]);

            f[i][j][state_row] = min(f[i][j][state_row], f[k][j - 1][state_row] + score + score_i);
        }

        ans = min(ans, f[i][c][state_row]);
    }
    cout << ans;
    return 0;
}
```

</details>