---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 5)
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 代码源
  - CodeForces
  - 贪心
date: 2022-03-26 16:00:57
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.03.26-2022.04.01)

<!-- more -->

## 501 - 社交圈 (CF1060D)

[题目链接](https://oj.daimayuan.top/course/10/problem/606)

1s, 256MB

现在有 $N$ 个人,每一个人都不想周围的人坐得离他很近,所以在他的左边要放 $L_i$ 张空椅子,右边要放 $R_i$ 张空椅子, 同时每个人自己要坐 $1$ 张椅子

现在他们要坐成若干个圈,请问最少要放多少张椅子 (包括每个人自己坐的椅子)?

### 输入格式

第 $1$ 行一个整数 $N$

第 $2$ 行至第 $N+1$ 行每行两个整数 $L_i$ 和 $R_i$

### 输出格式

一个整数, 表示最少需要的椅子数量

### 样例输入

```input1
4
1 2
2 1
3 5
5 3
```

### 样例输出

```output1
15
```

### 数据规模

$1 \leq N \leq 1 \times 10^5$

$0 \leq L_i,R_i \leq 1\times10^9$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const uint32_t N = 1e5 + 5;

int l[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    _for(i, 1, n) cin >> l[i] >> r[i];
    sort(l + 1, l + n + 1);
    sort(r + 1, r + n + 1);
    i64 ans = n;
    _for(i, 1, n) ans += max(l[i], r[i]);
    cout << ans;
    return 0;
}
```

</details>

## 502 - 区间和

[题目链接](https://oj.daimayuan.top/course/10/problem/609)

1s, 512MB

### 题目描述

小红有一个秘密的数组 $A$, 你知道这个数组 $A$ 的长度是 $N$. 小红会给你 $Q$ 个提示, 第 $i$ 个提示是告诉你数组 $A$ 中 $L_i$ 到 $R_i$ 连续元素的区间和. 问你能否根据小红的这 $Q$ 个提示知道数组 $A$ 中所有元素的和? 如果能, 输出 Yes; 否则, 输出 No

### 输入格式

第一行两个整数 $N$ 和 $q$, 接下来有 $Q$ 行, 每行两个整数 $L_i$ 和 $R_i$

### 输出格式

Yes 或 No, 表示能不能

### 样例输入

```input1
4 3
1 3
1 2
2 3
```

### 样例输出

```output1
No
```

### 数据规模

$1\leq N\leq 2 \times 10^5$

$1\leq Q\leq \min(2 \times 10^5,\frac{N(N+1)}{2})$

$1\leq L_i\leq R_i\leq N$

$(L_i, R_i)\neq (L_j, R_j)(i\neq j)$

### 解题思路

不难发现给出的区间相当于是 $S_{R_i}-S_{L_i-1}$, 然后问能否求出 $S_n-S_0$

不难发现就是建图然后判 $n$ 和 $0$ 是否连通即可

### 复杂度

$O(n\alpha (n))$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const uint32_t N = 1e5 + 5;

int fa[N];
int find(int x) { return x == fa[x] ? fa[x] : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    _for(i, 1, n) fa[i] = i;
    _for(i, 1, q, x, y) {
        cin >> x >> y;
        merge(x - 1, y);
    }
    cout << (find(0) == find(n) ? "Yes" : "No");
    return 0;
}
```

</details>

## 503 - 选数 2 ([40th Petrozavodsk Programming Camp, Winter 2021, day 1, M](https://qoj.ac/problem/862))

[题目链接](https://oj.daimayuan.top/course/10/problem/618)

1s, 1024MB

### 题目描述

有$N$个数, 小 t 准备在这$N$个数中选出若干个.满足这些数的最大值 小于等于 这些数的平均值的 $k$ 倍

小 t 想让自己选的数的个数尽可能多, 试求出有多少数字是不可能被小 t 选到的

我们设$M$为最多能选出的数的个数, 一个数字不可能被选到 当且仅当不出现在任何一个选出$M$个数的方案之中

### 输入格式

第一行一个正整数$N$ 表示数的个数

接下来一行$N$个正整数, 分别表示这$N$个数, 两个数字之间用空格隔开

最后一行两个正整数$p$和$q$, 表示$k$,($k = \frac{p}{q}$ 且 $k > 1$)

### 输出格式

第一行输出$M$, 表示不可能被选到的数的个数

接下来一行输出$M$个正整数, 分别表示不可能被选到的数字在原序列中的下标, 并按升序排序. 两个数字之间用空格隔开
数据范围

对于所有数据, 满足$1 \leq n \leq 2 \cdot 10^5$, $0 \leq a_i \leq 10^9$, $1 \leq q < p \leq 1000$
提示

有些做法看起来很对, 但是实际上是不太对的. 感觉可以尝试证明一下再写

### 样例输入 1

```input1
4
1 2 3 4
3 2
```

### 样例输出 1

```output1
0
```

### 样例解释

在样例一中, 我们最多选出 3 个数字. 而对于任何一个数字, 都存在一个选出 3 个数字的方案包含它, 于是没有不可能被选到的数字

### 样例输入 2

```input2
5
1 15 2 5 1
2 1
```

### 样例输出 2

```output2
1
2
```

### 样例输入 3

```input3
5
1 2 3 1000 10000
4 3
```

### 样例输出 3

```output3
2
4 5
```
