---
title: '题解 - [Luogu P1182] 数列分段 Section II'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 二分
  - 二分答案
date: 2020-01-15 09:47:41
---
[题目链接](https://www.luogu.com.cn/problem/P1182)

<!-- more -->

## 原始题面

### 题目描述

对于给定的一个长度为$N$的正整数数列$A_{1\sim N}$, 现要将其分成$M$ ($M\leqslant N$)段, 并要求每段连续, 且每段和的最大值最小.

关于最大值最小:

例如一数列$4\ 2\ 4\ 5\ 1$要分成$3$段.

将其如下分段:

$$[4\ 2][4\ 5][1]$$

第一段和为 $6$, 第$2$段和为$9$, 第$3$段和为$1$, 和最大值为$9$.

将其如下分段:

$$[4][2\ 4][5\ 1]$$

第一段和为$4$, 第$2$段和为$6$, 第$3$段和为$6$, 和最大值为$6$.

并且无论如何分段, 最大值不会小于$6$.

所以可以得到要将数列$4\ 2\ 4\ 5\ 1$要分成$3$段, 每段和的最大值最小为 $6$.

### 输入输出格式

#### 输入格式

第$1$行包含两个正整数$N,M$.

第$2$行包含$N$个空格隔开的非负整数$A_i$​, 含义如题目所述.

#### 输出格式

一个正整数, 即每段和最大值最小为多少.

### 输入输出样例

#### 输入样例 #1

```input1
5 3
4 2 4 5 1
```

#### 输出样例 #1

```output1
6
```

### 说明/提示

对于$20\%$的数据, $N\leqslant 10$.

对于$40\%$的数据, $N\leqslant 1000$.

对于$100\%$的数据, $1\leqslant N\leqslant 10^5$, $M\leqslant N$, $A_i$之和不超过$10^9$.

## 解题思路

二分答案

查询区间:
$$\displaystyle\bigg[\max_{1\leqslant i\leqslant n}\{A_i\},\sum_{i=1}^n A_i\bigg]$$

另外, 注意左端点, 如果令其为 0 则会WA一个点

## 时间复杂度

$O(n\log(r-l))$, 其中$l,\ r$分别指查询区间左右端点

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-01-15 09:47:41
 * @Description:
 */
i64 n, m, a[N];
bool judge(i64 max) {
    i64 seg = 0, now_sum = 0;
    _for(i, 1, n) {
        if ((now_sum += a[i]) >= max) {
            ++seg;
            now_sum = (now_sum > max) ? a[i] : 0;
        }
        if (seg > m) return 0;
    }
    if (now_sum) ++seg;
    return seg <= m;
}

int main() {
    read(n, m);
    i64 l = 0, r = 0, mid;
    _for(i, 1, n) {
        read(a[i]);
        r += a[i];
        l = std::max(l, a[i]);
    }
    while (l < r) {
        mid = l + (r - l) / 2;
        if (judge(mid))
            r = mid;
        else
            l = mid + 1;
    }
    print(r);
    FastIO::flush();
    return 0;
}
```

</details>