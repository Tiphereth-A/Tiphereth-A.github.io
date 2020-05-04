---
title: "题解 - [Luogu P3396] 哈希冲突"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 算法
  - 分块
date: 2021-11-12 01:55:36
---

[题目链接](https://www.luogu.com.cn/problem/P3396)

> [弱化版](https://codeforces.com/contest/103/problem/D)

<!-- more -->

## 原始题面

### 题目背景

此题约为 NOIP 提高组 Day2T2 难度

### 题目描述

众所周知, 模数的 hash 会产生冲突. 例如, 如果模的数 $p=7$, 那么 $4$ 和 $11$ 便冲突了

B 君对 hash 冲突很感兴趣. 他会给出一个正整数序列 $\text{value}$

自然, B 君会把这些数据存进 hash 池. 第 $\text{value}_k$ 会被存进 $(k \mod p)$ 这个池. 这样就能造成很多冲突

B 君会给定许多个 $p$ 和 $x$, 询问在模 $p$ 时, $x$ 这个池内 **数的总和**

另外, B 君会随时更改 $\text{value}_k$. 每次更改立即生效

保证 ${1\leq p<n}$

### 输入输出格式

#### 输入格式

第一行, 两个正整数 $n$, $m$, 其中 $n$ 代表序列长度, $m$ 代表 B 君的操作次数

第一行, $n$ 个正整数, 代表初始序列

接下来 $m$ 行, 首先是一个字符 $\text{cmd}$, 然后是两个整数 $x,y$

- 若 $\text{cmd}=\text{A}$, 则询问在模 $x$ 时, $y$ 池内 **数的总和**
- 若 $\text{cmd}=\text{C}$, 则将 $\text{value}_x$ 修改为 $y$

#### 输出格式

对于每个询问输出一个正整数, 进行回答

### 输入输出样例

#### 输入样例 #1

```input1
10 5
1 2 3 4 5 6 7 8 9 10
A 2 1
C 1 20
A 3 1
C 5 1
A 5 0
```

#### 输出样例 #1

```output1
25
41
11
```

### 说明

#### 样例解释

`A 2 1` 的答案是 `1+3+5+7+9=25`

`A 3 1` 的答案是 `20+4+7+10=41`

`A 5 0` 的答案是 `1+10=11`

#### 数据规模

对于 $10\%$ 的数据, 有 $n\leq 1000,m\leq 1000$

对于 $60\%$ 的数据, 有 $n\leq 100000.m\leq 100000$

对于 $100\%$ 的数据, 有 $n\leq 150000,m\leq 150000$

保证所有数据合法, 且 $1\leq \text{value}_i \leq 1000$

## 解题思路

> 参见 2014 年国家集训队论文《根号算法——不只是分块》

开个桶存满足 $p \leq\sqrt{n}$ 的模数 $p$ 的所有结果, 修改直接 $O(\sqrt{n})$ 暴力修改, 查询如果在桶里就直接输出, 否则只需暴力枚举 $O(\sqrt{n})$ 即可

> 太巧妙了

## 复杂度

$O((n+m)\sqrt{n})$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-12 01:55:36
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

const int N = 1.5e5 + 5, M = sqrt(N) + 5;

i64 a[N];
i64 block[M][M];

int main() {
    int n, m;
    cin >> n >> m;
    _for(i, 1, n) cin >> a[i];
    int block_len = sqrt(n);
    _for(i, 1, n) _for(p, 1, block_len) block[p][i % p] += a[i];

    char op;
    i64 x, y;
    _for(i, 1, m) {
        cin >> op >> x >> y;
        if (op == 'A') {
            if (x <= block_len) {
                cout << block[x][y] << '\n';
                continue;
            }
            i64 ans = 0;
            for (int i = y; i <= n; i += x) ans += a[i];
            cout << ans << '\n';
            continue;
        }
        _for(p, 1, block_len) block[p][x % p] -= a[x] - y;
        a[x] = y;
    }
    return 0;
}
```

</details>
