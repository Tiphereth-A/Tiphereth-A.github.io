---
title: '题解 - [CodeForces 501 D] Misha and Permutations Summation'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - 数学
  - 组合数学
  - Cantor展开
  - 逆Cantor展开
date: 2020-11-15 00:21:06
---
[题目链接](https://codeforces.com/problemset/problem/501/D)

<!-- more -->

## 原始题面

Let's define the sum of two permutations $p$ and $q$ of numbers $0, 1, ..., (n - 1)$ as permutation $\texttt{Perm}((\texttt{Ord}(p)+\texttt{Ord}(q))\bmod n!)$, where $\texttt{Perm}(x)$ is the x-th lexicographically permutation of numbers $0, 1, ..., (n - 1)$ (counting from zero), and $\texttt{Ord}(p)$ is the number of permutation $p$ in the lexicographical order

For example, $\texttt{Perm}(0) = (0, 1, ..., n - 2, n - 1)$, $\texttt{Perm}(n! - 1) = (n - 1, n - 2, ..., 1, 0)$

Misha has two permutations, $p$ and $q$. Your task is to find their sum

Permutation $a = (a_0, a_1, ..., a_{n - 1})$ is called to be lexicographically smaller than permutation $b = (b_0, b_1, ..., b_{n - 1})$, if for some k following conditions hold:
$$a_0 = b_0, a_1 = b_1, ..., a_{k - 1} = b_{k - 1}, a_k < b_k$$

### Input

The first line contains an integer $n$ ($1 ≤ n ≤ 200 000$)

The second line contains n distinct integers from $0$ to $n - 1$, separated by a space, forming permutation $p$

The third line contains n distinct integers from $0$ to $n - 1$, separated by spaces, forming permutation $q$

### Output

Print $n$ distinct integers from $0$ to $n - 1$, forming the sum of the given permutations. Separate the numbers by spaces

### Examples

#### Input 1

```input1
2
0 1
0 1
```

#### Output 1

```output1
0 1
```

#### Input 2

```input2
2
0 1
1 0
```

#### Output 2

```output2
1 0
```

#### Input 3

```input3
3
1 2 0
2 1 0
```

#### Output 3

```output3
1 0 2
```

### Note

Permutations of numbers from $0$ to $1$ in the lexicographical order: $(0, 1), (1, 0)$

In the first sample $\texttt{Ord}(p) = 0$ and $\texttt{Ord}(q) = 0$, so the answer is $\texttt{Perm}((0+0)\bmod 2)=\texttt{Perm}(0)=(0, 1)$

In the second sample $\texttt{Ord}(p) = 0$ and $\texttt{Ord}(q) = 1$, so the answer is $\texttt{Perm}((0+1)\bmod 2)=\texttt{Perm}(1)=(1, 0)$

Permutations of numbers from $0$ to $2$ in the lexicographical order: $(0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0)$

In the third sample $\texttt{Ord}(p) = 3$ and $\texttt{Ord}(q) = 5$, so the answer is $\texttt{Perm}((3+5)\bmod 6)=\texttt{Perm}(2)=(1, 0, 2)$

## 题意简述

现在有两个长度为$n$的排列, 由 $0,1,2...n-1$ 这$n$个数字组成

对于一个排列 $p$, $\texttt{Ord}(p)$表示$p$是字典序第$\texttt{Ord}(p)$小的排列 (从$0$开始计数)

对于小于 $n!$ 的非负数 $x$, $\texttt{Perm}(x)$表示字典序第 $x$小的排列

给出两个排列 $p$和 $q$, 求 $\texttt{Perm}((\texttt{Ord}(p)+\texttt{Ord}(q))\bmod n!)$

> from <https://www.luogu.com.cn/discuss/show/188178>

## 解题思路

显然是Cantor展开和逆Cantor展开的模板题

但这题的$n$是 `2e5` 的, 我们肯定不能直接套板子

注意到$d(A)=P_Af_n^T$, 对于给出的$p,q$, 我们可以考虑直接将$P_p,P_q$相加并还原即可

另外注意在CF的评测环境是32位的, 即`std::size_t`是`unsigned int`而不是`uint64_t`

## 复杂度

$O(n\log n)$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-11-15 01:07:29
 * @Description: 
 */

#include <bits/stdc++.h>
using namespace std;

namespace Cantor_expansion {
using std::size_t;
const size_t N = 2e5 + 5;

size_t n;

template <const std::size_t N = (std::size_t)1e6 + 5, typename T = std::ptrdiff_t>
class BIT {
  private:
    T tree[N];

    std::size_t lowbit(std::ptrdiff_t x) { return x & (-x); }

  public:
    BIT() { memset(tree, 0, sizeof(tree)); }

    void clear() { memset(tree, 0, sizeof(tree)); }

    void modify(std::size_t pos, T val = 1) {
        for (std::size_t i = pos; i < N; i += lowbit(i)) tree[i] += val;
    }
    T query(std::size_t pos) {
        T ret = 0;
        for (std::size_t i = pos; i; i = (std::ptrdiff_t)i - lowbit(i)) ret += tree[i];
        return ret;
    }
};
BIT<N> tr;

void main(size_t p[], size_t const a[], size_t n) {
    tr.clear();
    for (size_t i = n; i; --i) {
        p[i] = tr.query(a[i]);
        tr.modify(a[i]);
    }
}
}  // namespace Cantor_expansion

namespace inverse_Cantor_expansion {
using std::size_t;
const size_t N = 2e5 + 5;

size_t n;

// based on BIT, need discretization before using
template <const std::size_t N = (std::size_t)1e6 + 5>
class BT {
    std::size_t LOG_N;
    std::size_t tree[N];

    std::size_t lowbit(std::ptrdiff_t x) { return x & (-x); }

    void modify(std::size_t pos, std::size_t val = 1) {
        for (std::size_t i = pos; i < N; i += lowbit(i)) tree[i] += val;
    }
    std::size_t sum(std::size_t pos) {
        std::size_t ret = 0;
        for (std::size_t i = pos; i; i = (std::ptrdiff_t)i - lowbit(i)) ret += tree[i];
        return ret;
    }
    std::size_t query_rk(std::size_t pos) {
        std::size_t idx = 0;
        for (std::size_t i = LOG_N; ~i; --i) {
            idx += 1 << i;
            if (idx >= N || tree[idx] >= pos)
                idx -= 1 << i;
            else
                pos -= tree[idx];
        }
        return idx + 1;
    }

  public:
    BT() {
        memset(tree, 0, sizeof(tree));
        LOG_N = ceil(log2(N));
    }
    void clear() { memset(tree, 0, sizeof(tree)); }
    void insert(std::size_t pos) { modify(pos); }
    void remove(std::size_t pos) { modify(pos, -1); }
    std::size_t get_rank(std::size_t num) { return sum(num - 1) + 1; }
    std::size_t kth_num(std::size_t k) { return query_rk(k); }
    std::size_t pre(std::size_t num) { return query_rk(sum(num - 1)); }
    std::size_t suc(std::size_t num) { return query_rk(sum(num) + 1); }
};
BT<N> tr;

void main(size_t const p[], size_t a[], size_t n) {
    for (size_t i = 1; i <= n; ++i) tr.insert(i);
    for (size_t i = 1; i <= n; ++i) tr.remove(a[i] = tr.kth_num(p[i] + 1));
}
}  // namespace inverse_Cantor_expansion

const size_t N = 2e5 + 5;
size_t a[N], p[N], q[N];

int main() {

#ifndef ONLINE_JUDGE

#   clock_t _CLOCK_ST = clock();
#endif
    //======================================
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%llu", a + i);
        ++a[i];
    }
    Cantor_expansion::main(p, a, n);
    for (int i = 1; i <= n; ++i) {
        scanf("%llu", a + i);
        ++a[i];
    }
    Cantor_expansion::main(q, a, n);
    for (size_t i = n; i; --i) p[i] += q[i];
    for (size_t i = n; i; --i) {
        p[i - 1] += p[i] / (n - i + 1);
        p[i] %= n - i + 1;
    }
    inverse_Cantor_expansion::main(p, a, n);
    for (int i = 1; i <= n; ++i) printf("%lu%c", --a[i], " \n"[i == n]);
        //======================================

#ifndef ONLINE_JUDGE
    std::cerr << "\n---\n"
              << "Time used: " << clock() - _CLOCK_ST << std::endl;

#endif
    return 0;
}
```

</details>
