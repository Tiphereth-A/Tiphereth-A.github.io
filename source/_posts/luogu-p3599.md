---
title: '题解 - [Luogu P3599] Koishi Loves Construction'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 数学
  - 数论
  - 逆元
  - 快速幂
date: 2020-08-03 14:23:09
---
[题目链接](https://www.luogu.com.cn/problem/P3599)

<!-- more -->

## 原始题面

### 题目描述

Koishi决定走出幻想乡成为数学大师！

Flandre听说她数学学的很好, 就给Koishi出了这样一道构造题：

Task1：试判断能否构造并构造一个长度为$n$的$1\dots n$的排列, 满足其$n$个前缀和在模$n$的意义下互不相同

Taks2：试判断能否构造并构造一个长度为$n$的$1\dots n$的排列, 满足其$n$个前缀积在模$n$的意义下互不相同

按照套路, Koishi假装自己根本不会捉, 就来找你帮忙辣

### 输入格式

第一行两个整数$X$和$T$, 分别表示Task类型和测试点内的数据组数

接下来$T$行, 每行一个整数表示每组数据中的$n$

### 输出格式

为了方便SPJ的编写, 您需要遵从以下格式输出

对于每组数据仅包含一行输出：

1. 如果您认为当前数据不存在符合题意的构造, 只需输出一个整数$0$

1. 如果您认为当前数据存在符合题意的构造却不会构造, 只需输出一个整数$1$

1. 如果您认为当前数据存在符合题意的构造并成功构造, 则需要先输出一个整数$2$, 再输出$n$个整数表示构造的方案

每两个整数之间需要有空格作为分隔符

### 输入输出样例

#### 输入 #1

```input1
1 1
8
```

#### 输出 #1

```output1
2 8 7 6 5 4 3 2 1
```

#### 输入 #2

```input2
2 1
11
```

#### 输出 #2

```output2
2 1 2 3 5 10 6 7 4 9 8 11
```

### 说明/提示

对于每组数据

1. 如果您对于构造的存在性判断正确, 您将会得到 $30\%$ 的分数, 若您的构造符合题意或者确实不存在符合题意的构造, 您将会得到剩余的 $70\%$ 的分数

1. 如果您对于构造的存在性判断不正确, 您将不会得到任何分数

对于每组测试点, 您的得分将是本组数据点中得分的最小值

测试点类型1：10分, 满足$X=1,1\leq n\leq 10$

测试点类型2：40分, 满足$X=1,1\leq n\leq10^5$

测试点类型3：10分, 满足$X=2,1\leq n\leq 10$

测试点类型4：40分, 满足$X=2,1\leq n\leq10^5$

对于所有测试点, 满足$1\leq T\leq 10$

## 解题思路

由于$n=1$时的构造方法显然, 故下面的讨论中假设$n>1$

- 对于Task1:

  我们能很容易地发现: 若对$n$可构造出满足要求的数列, 则
    1. 第一个数必为$n$
    1. 之后的数列中的任意子区间$[l,r]$上的和$s_{l,r}$均满足$s_{l,r}{\equiv}\llap{/\,}0\pmod{n}$

  由第二条可推出: 所有非$1$奇数均不可构造, 因为$\sum_{i=1}^{n-1}i=n({n-1\over2})\equiv0\pmod n$

  对于其他情况, 即$n$为偶数时, 我们可以这样构造数列$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$:

  令  
  $$a_i={n\over2}+(-1)^i\left(i-1-{n\over2}\right)=\begin{cases}
    n-i+1,&2\nmid i\\
    i-1,&2\mid i
  \end{cases}$$
  用自然语言描述就是: 奇数项从$n$递减, 步长为$2$; 偶数项从$1$递增, 步长为$2$

  此时有
  $$S_x:=\sum_{i=1}^xa_i\equiv(-1)^x\left\lfloor{x\over2}\right\rfloor\pmod n,~\forall x\in[1,n]\cap\N$$
  换种写法就是$S_1=\overline{0},~S_2=\overline{1}~,S_3=\overline{-1},...,S_{n-1}=\overline{n\over2}~,S_n=\overline{-{n\over2}}$

- 对于Task2:

  我们能很容易地发现: 若对$n$可构造出满足要求的数列, 则
    1. 第一个数必为$1$
    1. 最后一个数必为$n$
    1. 剩下的数中任意子区间$[l,r]$上的积$p_{l,r}$均满足$p_{l,r}{\equiv}\llap{/\,}0,1\pmod{n}$

  由第三条可推出: 所有满足$n\mid\prod_{i=1}^{n-1}i$的数均不可构造, 即所有非$4$合数均不可构造

  对于其他情况
  - 当$n=4$时, 其有唯一解 `1 3 2 4`
  - 当$n\ne4$时, 即当$n$为素数时, 我们令$a_i$为结果的第$i$项, $P_i$为结果的前$i$项积, 我们可以这样构造:

    令
    $$a_i=\begin{cases}
      1,&i=1\\
      iP_{i-1}^{-1}\bmod n,&i>1
    \end{cases}$$
    此时即有$P_i\equiv i\pmod n$,
    $$a_i=\begin{cases}
      1,&i=1\\
      i(i-1)^{-1}\bmod n,&i>1
    \end{cases}$$

    下面证明$a_i$的唯一性

    假设$a_i=a_j,~1\leqslant i,j\leqslant n$

    又$\def\ss#1{a_{ #1}({ #1}-1)\equiv { #1}\pmod n}\ss{i},~~\ss{j}$

    可得$0\equiv a_i(i-1)-a_j(j-1)\equiv i-j\pmod n$, 即$i=j$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-08-03 14:23:09
 * @Description:
 */
const int N = 1e5 + 5;
i64 qpow(i64 a, i64 b, i64 mod) {
  i64 res = 1;
  for (; b; b >>= 1, (a *= a) %= mod)
    if (b & 1) (res *= a) %= mod;
  return res;
}
bool vis[N];
int  prime[N], cnt_prime;
int main() {
  _for(i, 2, n) {
    if (!vis[i]) prime[++cnt_prime] = i;
    for (int j = 1; j <= cnt_prime && i * prime[j] <= n; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  int x, kase;
  cin >> x >> kase;
  while (kase--) {
    int n;
    cin >> n;
    if (x == 1) {
      if (n & 1 && n > 1) {
        cout << "0" << endl;
        continue;
      }
      cout << "2";
      _for(i, 1, n) cout << " " << (i & 1 ? n + 1 - i : i - 1);
      cout << endl;
    } else {
      if (vis[n] ^ (n == 4)) {
        cout << "0" << endl;
        continue;
      }
      if (n == 1) {
        cout << "2 1" << endl;
        continue;
      }
      if (n == 4) {
        cout << "2 1 3 2 4" << endl;
        continue;
      }
      cout << "2";
      for (int i = 1, _ = 1, prod = 1; i < n; ++i) {
        cout << " " << _;
        _ = qpow(prod, n - 2, n) * (i + 1) % n;
        prod = 1ll * prod * _ % n;
      }
      cout << " " << n << endl;
    }
  }
  return 0;
}
```

</details>