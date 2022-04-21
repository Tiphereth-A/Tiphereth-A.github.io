---
title: 题解 - 2020 ICPC 亚洲区域赛(南京) 热身赛
categories:
  - 程序设计
  - 题解
  - ICPC
tags:
  - 程序设计
  - 题解
  - ICPC
  - 贪心
date: 2020-12-19 21:51:29
---

[比赛链接](https://ac.nowcoder.com/acm/contest/10271)

<!-- more -->

## 题目概览

| 题号 | 标题                          | 做法 | 备注                                                                                                                  |
| ---- | ----------------------------- | ---- | --------------------------------------------------------------------------------------------------------------------- |
| A    | Algorithm Course              | 签到 |
| B    | Best Grouping                 | 贪心 | [牛客多校](https://ac.nowcoder.com/acm/contest/5669/H), [CodeForces](https://codeforces.com/problemset/problem/449/C) |
| C    | Computer Science Ability Test | 莽   |

<!-- [官方题解](official_solutions.zip) -->

{% pdf /article/icpc-anjr2020-p/problems.pdf 600px %}

## A - Algorithm Course

### 题意简述

给一个字符串, 问其中子串`cat`和`dog`的总数

### 解题思路

懂了, 这就学 Python

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

```python
s = input()
print(s.count('cat')+s.count('dog'))
```

</details>

## B - Best Grouping

### 题意简述

在$1..n$中选出若干个数, 两两一组, 要求每一组均不互素, 输出组数最大的一个方案

### 解题思路

首先我们$1$和大于$\lfloor\frac{n}{2}\rfloor$的素数肯定不会出现在结果里, 之后剩下的数里我们从大到小枚举质数$p$, 统计所有之前没有匹配过的$p$的倍数, 如果是偶数个就把$2p$剔除, 接下来将其匹配就行[^1]

### 复杂度

$O(n\log n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool vis[N];
int prime[N], cnt_prime;
void init_prime(int n = N - 1) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[++cnt_prime] = i;
        for (int j = 1; j <= cnt_prime && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

using pii = pair<int, int>;
vector<pii> ans;
queue<int> tmp;

int main() {
    init_prime();
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        scanf("%d", &n);
        if (n < 4) {
            puts("0");
            continue;
        }
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
        int _ = upper_bound(prime + 1, prime + cnt_prime + 1, n / 2) - prime;
        for (int i = _; i; --i) {
            for (int j = 3; prime[i] * j <= n; ++j)
                if (!vis[prime[i] * j]) {
                    tmp.push(prime[i] * j);
                    vis[prime[i] * j] = 1;
                }
            if (tmp.size() % 2 == 0 && 2 * prime[i] <= n && !vis[2 * prime[i]]) {
                tmp.push(2 * prime[i]);
                vis[2 * prime[i]] = 1;
            }
            if (tmp.size()) tmp.push(prime[i]);
            while (!tmp.empty()) {
                int a = tmp.front();
                tmp.pop();
                ans.push_back(make_pair(a, tmp.front()));
                tmp.pop();
            }
        }
        printf("%d ", ans.size());
        for (auto it = ans.begin(); it != ans.end(); ++it) printf("%d %d%c", it->first, it->second, " \n"[it == ans.end() - 1]);
        ans.clear();
    }
    return 0;
}
```

</details>

## C - Computer Science Ability Test

### 题意简述

提答题, 判断十个命题的对错

> 1. (线性代数) 向量 $\overrightarrow{v_1}$, $\overrightarrow{v_2}$ 线性相关当且仅当存在标量 $k_1$, $k_2$ 满足$k_1\overrightarrow{v_1}+k_2\overrightarrow{v_2}=\overrightarrow{0}$
> 1. (微积分) ${y\mathrm{d}x-x\mathrm{d}y\over x^2-y^2}=\mathrm{d}(\frac{1}{2}\ln|\frac{x-y}{x+y}|)$
> 1. (离散数学) $\varnothing\subseteq\{\varnothing\}$
> 1. (物理) 在可逆绝热过程中, 一摩尔理想气体从$V_0$膨胀到$2V_0$, 如果气体的温度降低$25\%$, 则该气体可能是一种单原子气体
> 1. (数据结构) Fibonacci 堆插入操作的均摊时间复杂度为$O(1)$
> 1. (近似算法) 若$\texttt{P}\ne\texttt{NP}$, 则对于完全图上的旅行商问题, 不存在 polynomial-time $2$-approximation 算法, 但是存在 polynomial-time $2^n$-approximation 算法
> 1. (量子算法) 存在一种基于比较的量子排序算法, 其时间复杂度优于$\Omega(n\log n)$
> 1. (操作系统) 有一个由 4 个具有相同类型的资源组成的系统. 假设最多有 3 个进程同时使用资源, 每个进程最多使用 2 个资源, 那么该系统是无死锁的
> 1. (计算机理论) 假设$L(M)$是图灵机$M$接受的语言, 则语言  
>    $\{``M"|M\texttt{ is a Turing machine and }L(M)\texttt{ is uncountable}\}$  
>    是递归可枚举而不是递归的
> 1. (编译原理) 存在一种语法满足是 LL(1) 但不是 LALR(1)

### 解题思路

答案是 FTTFTFFTFT

[^1]: 参见 <https://codeforces.com/blog/entry/13112>
