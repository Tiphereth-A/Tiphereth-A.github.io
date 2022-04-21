---
title: '题解 - [Luogu P4861] 按钮 (aka 模板 - 阶)'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 模板
  - 数学
  - 数论
  - 阶
date: 2021-06-03 14:00:59
---

[题目链接](https://www.luogu.com.cn/problem/P4861)

<!-- more -->

## 原始题面

### 题目背景

Ada被关在了一个房间里

### 题目描述

房间的铁门上有一个按钮, 还有一个显示屏显示着"1"

旁边还有一行小字: "这是一个高精度M进制计算器, 每按一次按钮, 屏幕上的数便会乘以K. 当个位数再次变为1时, 门就开了. "

由于Ada急于出去, 所以你要在1s之内求出她的最小按键次数

### 输入输出格式

#### 输入格式

一行, 两个整数M和K

#### 输出格式

一行一个数字, 表示最小按键次数.  如果无论Ada按多少次都无法让门打开, 输出"Let's go Blue Jays!" (不含引号)

### 输入输出样例

#### 输入样例 #1

```input1
11 2
```

#### 输出样例 #1

```output1
10
```

#### 输入样例 #2

```input2
6 26
```

#### 输出样例 #2

```output2
Let's go Blue Jays!
```

### 说明

对于30%的数据, $2\leq M,K\leq10^4$

对于100%的数据, $2\leq M,K\leq2\times 10^{9}$

update: 我们不认为个位为11,21,...为问题的解 (例如, 11在16进制下记为B)

## 解题思路

即求 $\operatorname{ord}_m(k)$, 可以用扩展 BSGS 或暴力, 此处选用暴力做法

## 时间复杂度

$$\begin{aligned}
  \Theta\Bigg(\sqrt{K}+\sum_{d\mid\varphi(K);~d\leqslant\sqrt{\varphi(K)}}\log\varphi(K)\Bigg)&=O\left(\sqrt{K}+\frac{\varphi(K)-\varphi(\varphi(K))}{2}\log\varphi(K)\right)\\
  &=O\left(\sqrt{K}+\sqrt{\varphi(K)}\log\varphi(K)\right)
\end{aligned}$$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-06-03 14:00:59
 * @Description: Luogu P4861
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
i64 qpow(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
i64 phi(i64 n) {
    i64 ans = n;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main() {
    i64 m, k;
    cin >> m >> k;
    if (__gcd(m, k) > 1) {
        cout << "Let's go Blue Jays!" << endl;
        return 0;
    }
    i64 phim = phi(m);
    i64 ans = INT64_MAX;
    for (i64 i = 1; i <= sqrt(phim); ++i)
        if (phim % i == 0) {
            if (qpow(k, i, m) == 1) {
                ans = min(ans, i);
                break;
            } else if (qpow(k, phim / i, m) == 1)
                ans = min(ans, phim / i);
        }
    cout << ans;
}
```

</details>
