---
title: '题解 - [Luogu P3878] [TJOI2010]分金币'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 省选
  - TJOI
  - DP
  - 状压DP
  - 折半
date: 2021-11-11 23:03:58
---

[题目链接](https://www.luogu.com.cn/problem/P3878)

<!-- more -->

## 原始题面

### 题目描述

现在有 $n$ 枚金币, 它们可能会有不同的价值, 第 $i$ 枚金币的价值为 $v_i$

现在要把它们分成两部分, 要求这两部分金币数目之差不超过 $1$, 问这样分成的两部分金币的价值之差最小是多少?

### 输入输出格式

#### 输入格式

> **本题单个测试点内有多组测试数据**

输入的第一行是一个正整数 $T$, 表示该测试点内数据组数

对于每组测试数据的格式为:

每组测试数据占两行

第一行是一个整数 $n$, 表示金币的个数

第二行有 $n$ 个整数, 第 $i$ 个整数表示第 $i$ 个金币的价值 $v_i$

#### 输出格式

对于每组数据输出一行一个整数表示答案

### 输入输出样例

#### 输入样例 #1

```input1
2
3
2 2 4
4
1 2 3 6
```

#### 输出样例 #1

```output1
0
2
```

### 说明

#### 数据规模与约定

- 对 $30\%$ 的数据, 保证 $1 \leq v_i \leq 1000$
- 对于 $100\%$ 的数据, 保证 $1 \leq T \leq 20$, $1 \leq n \leq 30$, $1 \leq v_i \leq 2^{30}$

## 解题思路

看数据范围就知道要折半或者大力模拟退火

> 模拟退火交了两页, 最高 10 分, 气得我直接码正解去了
>
> 今天的爆率那叫一个高啊.jpg

令 `s[][]` 为存所有选取情况的数组, 其中 `s[i]` 表示前一组金币个数为 $i$ 时的所有可能结果 (或者前一组金币个数比后一组多 $i$ 时个数)

先把前 $\lceil{n\over 2}\rceil$ 个金币的所有选取情况存起来, 然后对剩下的 $n-\lceil{n\over 2}\rceil$ 个金币的所有情况在对应数组里二分即可

或者我们直接把二维数组换成一维的 `std::set` 数组也行

## 复杂度

$O(n2^{n\over 2})$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-11 23:03:58
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

i64 a[32];
set<i64> s[64];

int main() {
    int kase;
    cin >> kase;
    while (kase--) {
        int n;
        cin >> n;
        _for(i, 0, n - 1) cin >> a[i];
        int mid = (n + 1) / 2;
        _for(i, 0ll, (1 << mid) - 1, sum, cnt) {
            sum = cnt = 0;
            _for(j, 0, mid - 1) {
                if (i & (1 << j)) {
                    sum += a[j];
                    ++cnt;
                } else {
                    sum -= a[j];
                    --cnt;
                }
            }
            s[cnt + n].insert(sum);
        }
        i64 ans = INT64_MAX;
        _for(i, 0ll, (1 << (n - mid)) - 1, sum, cnt) {
            sum = cnt = 0;
            _for(j, 0, n - mid - 1) {
                if (!(i & (1 << j))) {
                    sum += a[j + mid];
                    ++cnt;
                } else {
                    sum -= a[j + mid];
                    --cnt;
                }
            }
            if (n % 2) {
                if (s[cnt + 1 + n].size()) {
                    auto it1 = s[cnt + 1 + n].lower_bound(sum), it2 = s[cnt + 1 + n].upper_bound(sum);
                    if (it1 != s[cnt + 1 + n].end()) ans = min(ans, abs(*it1 - sum));
                    if (it2 != s[cnt + 1 + n].end()) ans = min(ans, abs(*it2 - sum));
                }
                if (s[cnt - 1 + n].size()) {
                    auto it1 = s[cnt - 1 + n].lower_bound(sum), it2 = s[cnt - 1 + n].upper_bound(sum);
                    if (it1 != s[cnt - 1 + n].end()) ans = min(ans, abs(*it1 - sum));
                    if (it2 != s[cnt - 1 + n].end()) ans = min(ans, abs(*it2 - sum));
                }
            } else if (s[cnt + n].size()) {
                auto it1 = s[cnt + n].lower_bound(sum), it2 = s[cnt + n].upper_bound(sum);
                if (it1 != s[cnt + n].end()) ans = min(ans, abs(*it1 - sum));
                if (it2 != s[cnt + n].end()) ans = min(ans, abs(*it2 - sum));
            }
        }
        cout << ans << '\n';
        for (int i = 0; i < 65; ++i) s[i].clear();
    }
    return 0;
}
```

</details>