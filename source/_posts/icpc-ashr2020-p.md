---
title: 题解 - 2020 ICPC 亚洲区域赛(上海) 热身赛
categories:
  - 程序设计
  - 题解
  - ICPC
tags:
  - 程序设计
  - 题解
  - ICPC
  - 数学
  - 数论
  - 互素/互质
  - 期望
  - Euler函数
  - 排序
  - 贪心
  - 思维
date: 2020-12-12 21:24:04
---
[比赛链接](https://ac.nowcoder.com/acm/contest/9731)

<!-- more -->

## 题目概览

| 题号 | 标题       | 做法                |
| ---- | ---------- | ------------------- |
| A    | Game       | Euler函数           |
| B    | Strawberry | 贪心                |
| C    | Circle     | 均分纸牌 / 货仓选址 |

<!-- [官方题解](official_solutions.zip) -->

{% pdf /article/icpc-ashr2020-p/problems.pdf 600px %}

## A - Game

### 题意简述

给定$n$, 不停且等概率地在$1..n$中取出$2$个数直到最后剩下不多于$2$个数, 问取出数对中互质数对个数的期望

### 解题思路

举例说明, 例如$n=5$, 列出所有可能情况并去重
$$
\def\c#1{\color{cyan}{ #1}}
\def\m#1{\color{magenta}{ #1}}
\begin{matrix}
  \m{(1,2)}&\m{(3,4)}\\
  \m{(1,2)}&\m{(3,5)}\\
  \m{(1,2)}&\m{(4,5)}\\
  \m{(1,3)}&\c{(2,4)}\\
  \m{(1,3)}&\m{(2,5)}\\
  \m{(1,3)}&\m{(4,5)}\\
  \m{(1,4)}&\m{(2,3)}\\
  \m{(1,4)}&\m{(2,5)}\\
  \m{(1,4)}&\m{(3,5)}\\
  \m{(1,5)}&\m{(2,3)}\\
  \m{(1,5)}&\c{(2,4)}\\
  \m{(1,5)}&\m{(3,4)}\\
  \m{(2,3)}&\m{(4,5)}\\
  \c{(2,4)}&\m{(3,5)}\\
  \m{(2,5)}&\m{(3,4)}\\
\end{matrix}$$

其中每一行即为一种取法, <font color="magenta">品红色</font>的数对为互质的, <font color="cyan">青色</font>的数对为不互质的

答案即为<font color="magenta">品红色</font>数对个数除以行数

即
$$\begin{aligned}
  &{ {(n-2)!\over 2^{\lfloor{n\over2}-1\rfloor}\lfloor{n\over2}-1\rfloor!}\sum_{i=1}^n\varphi(n)\over{n!\over 2^{\lfloor{n\over2}\rfloor}\lfloor{n\over2}\rfloor!}}\\
  =~&{\lfloor{n\over2}\rfloor\sum_{i=1}^n\varphi(n)\over {n\choose2}}\\
  =~&{\sum_{i=1}^n\varphi(n)\over n-[2\mid n]}
\end{aligned}$$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-12-12 21:24:04
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;

int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a % b); }

bool vis[N];
int prime[N], cnt_prime;
int phi[N];
void init(int n = N - 1) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) phi[prime[++cnt_prime] = i] = i - 1;
        for (int j = 1; j <= cnt_prime && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            phi[i * prime[j]] = phi[i] * prime[j];
            if (i % prime[j] == 0) break;
            phi[i * prime[j]] -= phi[i];
        }
    }
}

int main() {
    init();
    int n;
    cin >> n;
    int64_t a = 0, b = n - (n % 2 == 0);
    for (int i = 1; i <= n; ++i) a += phi[i];
    int64_t g = gcd(a, b);
    cout << a / g << '/' << b / g;
    return 0;
}
```

</details>

## B - Strawberry

### 题意简述

给出$n\times m$的网格, 初始时所有网格上的积分均为$0$, 从$(x,y)$出发, 每一天早上所有格子的积分均+1, 下午你可以选择移动到相邻的格子(上下左右)或不动, 晚上你会获得当前所在格子上的积分, 并将该格积分清零, 经过$k$天后问所获得的最大积分

### 解题思路

我们不难发现, 第$i$天能获得的最大分数不超过$i$

画成图就是这样

![](B-1.svg)

其中横轴为天, 纵轴为某天获得的积分, 显然无论如何走, 结果都会落在该三角形内

当$m,n>1$时
不难发现最优走法为: 先等$t$天 $(\min\{0,k-mn\}\leqslant t\leqslant k)$, 之后一直走 (因为若中间有停顿则积分不会比该走法高)

> 以下图中未画出等待时的积分收益

![](B-2.svg)

![](B-3.svg)

该走法对应的最大积分为
$$\max_{\min\{0,k-mn\}\leqslant t\leqslant k}\sum_{i=0}^{k-t}(t+i)$$

当$t=\min\{0,k-mn\}$时最优

若$m=1$或$n=1$时, 不妨设$m=1$, 此时问题发生退化:

- 网格变为长度为$n$的线段 (在$\N^+$下)
- 初始位置为$x$, 左端点为$1$, 右端点为$n$
  
  则初始位置到左右端点的距离分别为$x-1,~n-x$

  令 $l=\min\{x-1,n-x\}$, $L=\max\{x-1,n-x\}$

  则 $l\leqslant\lfloor{n-1\over 2}\rfloor$, $L=n-l-1\geqslant\lceil{n-1\over 2}\rceil$
- 每天只能选择向左走一格, 向右走一格, 不动

此时的最优走法为: 先向短边方向走$t_1$天 $(0\leqslant t_1\leqslant\max\{0,\min\{l,\lfloor{k-L\over 2}\rfloor\}\})$, 然后等$t_2$天 $(0\leqslant t_2\leqslant\max\{k-2l-L,[k>L][2\nmid k-L]\})$, 最后反方向走到端点

![](B-4.svg)

该走法对应的最大积分为
$$\begin{cases}
  \max_{t_1,t_2}\left(\sum_{i=1}^{t_1}i+t_1t_2+2\sum_{i=1}^{t_1-1}i+\sum_{i=1}^{k-2t_1-t_2}(2t_1+t_2+i)\right),&k>L\\
  \sum_{i=0}^k(k+i),&k\leqslant L
\end{cases}
$$

当
$$\begin{aligned}
  t_1&=\max\left\{0,\min\left\{l,\left\lfloor{k-L\over 2}\right\rfloor\right\}\right\}\\
  t_2&=\max\{k-2l-L,[k>L][2\nmid k-L]\}
\end{aligned}$$
时取得最大值

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-12-12 21:24:04
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int MOD = 998244353, inv2 = (MOD + 1) / 2;

i64 calc(i64 l, i64 r) {
    if (r < l) return 0;
    l %= MOD;
    r %= MOD;
    return (l + r) * (r - l + 1) % MOD * inv2 % MOD;
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        i64 m, n, x, y, k;
        scanf("%lld%lld%lld%lld%lld", &n, &m, &x, &y, &k);
        if (m > n) {
            swap(m, n);
            swap(x, y);
        }
        if (m == 1) {
            i64 l = min(x - 1, n - x), L = max(x - 1, n - x);
            if (k <= L + 1) {
                printf("%lld\n", calc(1, k));
                continue;
            }
            i64 t1 = max(0ll, min(l, (k - L) / 2));
            i64 t2 = max(k - 2 * t1 - L, (k > L) * ((k - L) & 1));
            i64 ans1 = calc(1, t1);
            i64 ans2 = (t1 * t2 % MOD + 2 * calc(1, t1 - 1) % MOD) % MOD;
            i64 ans3 = calc(2 * t1 + t2, k);
            printf("%lld\n", (ans1 + ans2 + ans3) % MOD);
            continue;
        }
        printf("%lld\n", calc(max(0ll, k - m * n) + 1, k));
    }
    return 0;
}
```

</details>

## C - Circle

### 题意简述

给定在半径为$1$的圆上的$n$个点, 现需进行若干次移动使这$n$的点中相邻点距离相等, 且仍在圆上, 问最短移动长度

### 解题思路

均分纸牌/货仓选址

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-12-12 21:24:04
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double pi = acos(-1.0);
double alpha[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lf", alpha + i);
    sort(alpha, alpha + n);
    for (int i = 0; i < n; ++i) alpha[i] = pi / 180 * (360.0 / n * i - alpha[i]);
    sort(alpha, alpha + n);
    double ans = 0;
    for (int i = 0; i < n; ++i) ans += abs(alpha[i] - alpha[n / 2]);
    printf("%.12lf", ans);
    return 0;
}
```

</details>
