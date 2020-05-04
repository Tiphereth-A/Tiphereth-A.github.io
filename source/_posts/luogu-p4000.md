---
title: "模板 & 题解 - [Luogu P4000] 斐波那契数列"
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 模板
  - 算法
  - 数学
  - 数论
  - Fibonacci数列
  - Lucas数列
  - Fibonacci数列循环节
  - 二次剩余
  - 最大公约数
  - 最小公倍数
  - 高精度
  - 矩阵快速幂
  - 科技
date: 2021-12-22 20:54:01
---

[题目链接](https://www.luogu.com.cn/problem/P4000)

<!-- more -->

## 原始题面

### 题目描述

大家都知道, 斐波那契数列是满足如下性质的一个数列:

- $f_1 = 1$
- $f_2 = 1$
- $f_n = f_{n-1} + f_{n-2}$ ($n \geq 2$ 且 $n$ 为整数)
  请你求出 $f_n \mod p$ 的值

### 输入格式

- 第 1 行: 一个整数 $n$
- 第 2 行: 一个整数 $p$

### 输出格式

- 第 1 行: $f_n \mod p$ 的值

### 输入输出样例

#### 输入 #1

```input1
5
1000000007
```

#### 输出 #1

```output1
5
```

#### 输入 #2

```input2
10
1000000007
```

#### 输出 #2

```output2
55
```

### 说明/提示

对于 $100\%$ 的数据, $n \leq 10^{30000000}, p<2^{31}$

## 解题思路

科技题

先摆个论文: [The Period of the Fibonacci Sequence Modulo j](https://gradprogram.math.arizona.edu/~ura-reports/071/Campbell.Charles/Final.pdf)

这篇论文给出了找 Fibonacci 数列和 Lucas 数列循环节的方法 (实际上所有二阶递推数列都可以这样做)

简单来说就是这样:

- 考虑 $p$ 的唯一分解

  $$p=\prod_{i=1}^{\omega(p)}p_i^{\alpha_i}$$

  令 $l(p)$ 为 $F_n$ 模 $p$ 的循环节, 则

  $$l(p)=\operatorname{lcm}\{\def\enum#1{l(p_{ #1}^{\alpha_{ #1}})}\enum{1},\enum{2},...,\enum{\omega(p)}\}$$

- 对素数 $p$, 有如下定理:
  - $$l(p^n)\mid l(p)p^{n-1}$$
  - 若 $\left(\frac{5}{p}\right)=1$, 即 $p\equiv\pm 1\pmod{5}$, 则
    $$l(p)\mid p-1$$
  - 若 $\left(\frac{5}{p}\right)=-1$, 即 $p\equiv\pm 2\pmod{5}$, 则
    $$l(p)\mid 2(p+1)$$

> 代码里还有一些别的科技, 推荐看一看

## 复杂度

$O(\max\{\lg n,\sqrt p\})$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-12-22 20:54:01
 * @Description: Luogu P4000
 */
#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
u64 p;

struct Mat {
    u128 data[2][2];

    Mat() {}
    template <typename Up>
    Mat(Up a = 0, Up b = 0, Up c = 0, Up d = 0) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    template <typename Up>
    constexpr Mat& operator=(Up&& rhs) noexcept {
        (*this)(0, 0) = forward<Mat>(rhs)(0, 0);
        (*this)(0, 1) = forward<Mat>(rhs)(0, 1);
        (*this)(1, 0) = forward<Mat>(rhs)(1, 0);
        (*this)(1, 1) = forward<Mat>(rhs)(1, 1);
        return *this;
    }

    inline constexpr u128& operator()(size_t x, size_t y) noexcept { return this->data[x][y]; }

    Mat operator*(Mat& rhs) noexcept {
        return Mat(((*this)(0, 0) * rhs(0, 0) % p + (*this)(0, 1) * rhs(1, 0) % p) % p,
                   ((*this)(0, 0) * rhs(0, 1) % p + (*this)(0, 1) * rhs(1, 1) % p) % p,
                   ((*this)(1, 0) * rhs(0, 0) % p + (*this)(1, 1) * rhs(1, 0) % p) % p,
                   ((*this)(1, 0) * rhs(0, 1) % p + (*this)(1, 1) * rhs(1, 1) % p) % p);
    }
};

inline constexpr uint64_t dec2uint_mod(const char* const num, const u128 mod) {
    size_t len = strlen(num);
    if (len == 0) return 0;
    u128 ans = 0;
    for (size_t i = 0; i + 8 <= len; i += 8) {
        uint64_t res = *((uint64_t*)(num + i));
        res = (res & 0x0F0F0F0F0F0F0F0F) * 2561 >> 8;
        res = (res & 0x00FF00FF00FF00FF) * 6553601 >> 16;
        res = (res & 0x0000FFFF0000FFFF) * 42949672960001 >> 32;
        ans = (ans * 100000000 + res) % mod;
    }
    for (auto pch = num + (len / 8 * 8); pch < num + len;) ans = (ans * 10 + (u128)(*(pch++) & '\x0f')) % mod;
    return ans;
}

inline u128 period(u64 p) {
    auto g = [](u128 p) -> u128 {
        static const u128 _[6] = {0, 1, 3, 8, 6, 20};
        if (p <= 5) return _[p];
        return (p % 5 == 1 || p % 5 == 4) ? (p - 1) : ((p + 1) * 2);
    };
    auto gcd = [](u128 n, u128 m) -> u128 {
        while (m ^= n ^= m ^= n %= m);
        return n;
    };

    u128 res = 1;
    for (u128 i = 2; i * i <= p; ++i)
        if (p % i == 0) {
            p /= i;
            u128 x = g(i), _ = p;
            while (p % i == 0) p /= i;
            x *= _ / p;
            res = res / gcd(res, x) * x;
        }
    if (p > 1) {
        u128 x = g(p);
        res = res / gcd(res, x) * x;
    }
    return res;
}

char s[50000007];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s >> p;
    if (p < 2) {
        cout << '0';
        return;
    }
    cout << [](Mat a, u64 b) -> u64 {
        Mat res(1, 0, 0, 1);
        for (; b; b >>= 1, a = a * a)
            if (b & 1) res = res * a;
        return (u64)res(0, 1);
    }({1, 1, 1, 0}, dec2uint_mod(s, period(p)));
    return 0;
}
```

</details>
