---
title: '题解 - [Luogu P1337] [JSOI2004]平衡点 / 吊打XXX'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 省选
  - JSOI
  - 数学
  - 三分
date: 2021-11-09 14:02:15
---
[题目链接](https://www.luogu.com.cn/problem/P1337)

<!-- more -->

## 原始题面

### 题目描述

如图：有n个重物, 每个重物系在一条足够长的绳子上. 每条绳子自上而下穿过桌面上的洞, 然后系在一起. 图中X处就是公共的绳结. 假设绳子是完全弹性的 (不会造成能量损失), 桌子足够高 (因而重物不会垂到地上), 且忽略所有的摩擦

问绳结X最终平衡于何处

注意：桌面上的洞都比绳结X小得多, 所以即使某个重物特别重, 绳结X也不可能穿过桌面上的洞掉下来, 最多是卡在某个洞口处

![](1.jpg)

### 输入输出格式

#### 输入格式

文件的第一行为一个正整数n (1≤n≤1000), 表示重物和洞的数目. 接下来的n行, 每行是3个整数：Xi.Yi.Wi, 分别表示第i个洞的坐标以及第 i个重物的重量. (-10000≤x,y≤10000, 0<w≤1000)

#### 输出格式

你的程序必须输出两个浮点数 (保留小数点后三位), 分别表示处于最终平衡状态时绳结X的横坐标和纵坐标. 两个数以一个空格隔开

### 输入输出样例

#### 输入样例 #1

```input1
3
0 0 1
0 2 1
1 1 1
```

## 输出样例 #1

```output1
0.577 1.000
```

### 说明

[JSOI]

## 题意简述

对给定的 $x_{1..n}$, $y_{1..n}$, $w_{1..n}$, 求
$$f(x,y)=\sum_iw_i\sqrt{(x-x_i)^2+(y-y_i)^2}$$

的极值点 $(x,y)$

## 解题思路

不难发现其 Hasse 矩阵是恒正定的, 也就是说其有且仅有一个极值点

故直接三分即可

不明白为啥一堆人非要模拟退火

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-09 14:02:15
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

struct Node {
    long double x, y, w;
} a[N];

int n;
inline long double f(const long double& x, const long double& y) {
    long double ans = 0;
    _for(i, 1, n) ans += a[i].w * sqrt((x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y));
    return ans;
}

long double thry(long double l, long double r, const long double& x) {
    long double loss, _l, _r;
    long double f_l, f_r;
    _for(i, 1, 128) {
        loss = (r - l) / 3;
        _l = l + loss;
        _r = r - loss;
        f_l = f(x, _l);
        f_r = f(x, _r);
        f_l < f_r ? r = _r : l = _l;
    }
    return l + (r - l) / 2;
}
tuple<long double, long double> thr(const long double& l_x, const long double& r_x, const long double& l_y, const long double& r_y) {
    long double l = l_x, r = r_x;
    long double loss, _l, _r;
    long double f_l, f_r;
    long double _yl, _yr;
    _for(i, 1, 128) {
        loss = (r - l) / 3;
        _l = l + loss;
        _r = r - loss;
        f_l = f(_l, _yl = thry(l_y, r_y, _l));
        f_r = f(_r, _yr = thry(l_y, r_y, _r));
        f_l < f_r ? r = _r : l = _l;
    }
    return make_tuple(l + (r - l) / 2, _yl + (_yr - _yl) / 2);
}

int main() {
    cin >> n;
    _for(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].w;
    long double mx = 1e5, Mx = -1e5, my = 1e5, My = -1e5;
    _for(i, 1, n) {
        mx = min(mx, a[i].x);
        Mx = max(Mx, a[i].x);
        my = min(my, a[i].y);
        My = max(My, a[i].y);
    }
    long double x, y;
    tie(x, y) = thr(mx, Mx, my, My);
    cout << fixed << setprecision(3) << x << " " << y;
    return 0;
}
```

</details>