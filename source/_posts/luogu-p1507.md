---
title: '题解 - [Luogu P1507] NASA的食物计划'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 模板
  - DP
  - 背包DP
  - 01背包DP
  - 二维01背包DP
date: 2020-01-15 09:54:49
---
[题目链接](https://www.luogu.com.cn/problem/P1507)

<!-- more -->

## 原始题面

### 题目背景

NASA(美国航空航天局)因为航天飞机的隔热瓦等其他安全技术问题一直大伤脑筋, 因此在各方压力下终止了航天飞机的历史, 但是此类事情会不会在以后发生, 谁也无法保证

在遇到这类航天问题时, 解决方法也许只能让航天员出仓维修, 但是多次的维修会消耗航天员大量的能量, 因此NASA便想设计一种食品方案, 让体积和承重有限的条件下多装载一些高卡路里的食物.

### 题目描述

航天飞机的体积有限, 当然如果载过重的物品, 燃料会浪费很多钱

每件食品都有各自的体积、质量以及所含卡路里

在告诉你体积和质量的最大值的情况下, 请输出能达到的食品方案所含卡路里的最大值, 当然每个食品只能使用一次.

### 输入输出格式

#### 输入格式

第一行 两个数 体积最大值($<400$)和质量最大值($<400$)

第二行 一个数 食品总数$N$($<50$).

第三行－第$3+N$行

每行三个数 体积($<400$) 质量($<400$) 所含卡路里($<500$)

#### 输出格式

一个数 所能达到的最大卡路里

### 输入输出样例

#### 输入样例 #1

```input1
320 350
4
160 40 120
80 110 240
220 70 310
40 400 220
```

#### 输出样例 #1

```output1
550
```

### 说明/提示

很简单的背包...

## 解题思路

二维01背包板子题

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-01-15 09:54:49
 * @Description:
 */
int f[N][N];
struct Food {
    int v, m, cal;
} a[M];

int main() {
    int v, m, n;
    read(v, m, n);
    _for(i, 1, n) read(a[i].v, a[i].m, a[i].cal);
    _for(i, 1, n) _rfor(j, v, 0) if (j >= a[i].v) _rfor(k, m, 0) if (k >= a[i].m) f[j][k] = max(f[j][k], f[j - a[i].v][k - a[i].m] + a[i].cal);
    print(f[v][m]);
    FastIO::flush();
    return 0;
}
```

</details>