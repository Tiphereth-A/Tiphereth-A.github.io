---
title: 题解 - 2020 ICPC 亚洲区域赛(南京)
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
  - 概率
  - 期望
  - 三分
  - 排序
  - 打表
  - DP
  - 树形DP
  - 构造
  - 抽屉原理
date: 2020-12-20 20:46:33
---

[比赛链接](https://ac.nowcoder.com/acm/contest/10272)

<!-- more -->

## 题目概览

| 题号[^1] | 标题[^2]                          | 做法         |
| -------- | --------------------------------- | ------------ |
| A        | Ah, It's Yesterday Once More      | 构造         |
| \*B      | Baby's First Suffix Array Problem |              |
| \*C      | Certain Scientific Railgun        |              |
| \*D      | Degree of Spanning Tree           |              |
| E        | Evil Coordinate                   | 排序         |
| F        | Fireworks                         | 三分         |
| \*G      | Go                                |              |
| H        | Harmonious Rectangle              | 打表         |
| \*I      | Interested in Skiing              |              |
| \*J      | Just Another Game of Stones       |              |
| K        | K Co-prime Permutation            | 签到(找规律) |
| L        | Let's Play Curling                | 签到(找规律) |
| \*M      | Monster Hunter                    | 树形 DP      |

[^1]: 打\*的是还没写题解的题
[^2]: 带超链接的是找到了原题或原型

[官方题解](https://zhuanlan.zhihu.com/p/338249705)

{% pdf /article/icpc-anjr2020/problems.pdf 600px %}

## A - Ah, It's Yesterday Once More

### 解题思路

我 TM 直接好家伙

附[checker](https://github.com/Tiphereth-A/2020-icpc-nanjing-A-checker)

## B - Baby's First Suffix Array Problem

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## C - Certain Scientific Railgun

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## D - Degree of Spanning Tree

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## E - Evil Coordinate

### 题意简述

有个机器人在二维平面上按给定指令走, 初始位置是$(0,0)$, 指令包括如下四种:

- `U`: 从$(x,y)$走到$(x,y+1)$
- `D`: 从$(x,y)$走到$(x,y-1)$
- `L`: 从$(x,y)$走到$(x-1,y)$
- `R`: 从$(x,y)$走到$(x+1,y)$

在$(m_x,m_y)$处有个坑, 机器人走到坑那里就动不了了, 问能否通过改变指令顺序使得机器人避开坑

### 解题思路

显然如果坑在$(0,0)$或者是终点则避不开, 之后我们发现将相同方向排在一起的所有序列中至少有一个是满足条件的, 则枚举四种指令的全排列即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int N = 1e5 + 5;

struct Node {
    char dir;
    int num;

    bool operator<(const Node& rhs) const { return dir < rhs.dir; }
};
array<Node, 5> a;

char s[N];

int x, y;
bool chk(int len) {
    i64 _x = 0, _y = 0;
    for (int i = 1; i <= len; ++i) {
        switch (s[i]) {
            case 'U': ++_y; break;
            case 'D': --_y; break;
            case 'L': --_x; break;
            case 'R': ++_x; break;
        }
        if (_x == x && _y == y) return 0;
    }
    return 1;
}

void solve() {
    scanf("%d%d\n", &x, &y);
    scanf("%s", s + 1);
    if (x == 0 && y == 0) {
        puts("Impossible");
        return;
    }
    a[1].num = a[2].num = a[3].num = a[4].num = 0;
    a[1].dir = 'U';
    a[2].dir = 'D';
    a[3].dir = 'L';
    a[4].dir = 'R';
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) switch (s[i]) {
            case 'U': ++a[1].num; break;
            case 'D': ++a[2].num; break;
            case 'L': ++a[3].num; break;
            case 'R': ++a[4].num; break;
        }
    sort(a.begin() + 1, a.end());
    do {
        int now = 0;
        for (int i = 1; i <= a[1].num; ++i) s[++now] = a[1].dir;
        for (int i = 1; i <= a[2].num; ++i) s[++now] = a[2].dir;
        for (int i = 1; i <= a[3].num; ++i) s[++now] = a[3].dir;
        for (int i = 1; i <= a[4].num; ++i) s[++now] = a[4].dir;
        if (chk(len)) {
            puts(s + 1);
            return;
        }
    } while (next_permutation(a.begin() + 1, a.end()));
    puts("Impossible");
}

int main() {
    int _t;
    scanf("%d", &_t);
    while (_t--) solve();
    return 0;
}
```

</details>

## F - Fireworks

### 题意简述

Kotori 可以花费时间$n$制作一个烟花, 也可以花费时间$m$点燃所有没点燃的烟花, 每个烟花完美绽放的概率为$p$, 如果在某次点燃中有至少一个烟花完美绽放, 则 Kotori 停止, 问 Kotori 停止的最小时间期望

### 解题思路

> 因为把`ld`打成`ll`导致罚时+2, 我是 SB

假设最优解是制作了$k$个烟花, 耗时为$t$, 则有
$$t=(nk+m)\left(1-(1-p)^k\right)+(t+nk+m)(1-p)^k$$
解得
$$t=\frac{nk+m}{1-(1-p)^k}$$
不难发现$t$是$k$的严格单峰函数, 直接三分即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ldb = long double;

i64 n, m;
ldb p;

ldb f(ldb k) { return (n * k + m) / (1 - pow(1 - p, k)); }

void solve() {
    i64 _p;
    scanf("%lld%lld%lld", &n, &m, &_p);
    p = _p * 1e-4;
    ldb ans = DBL_MAX;

    ldb l = 1, r = 1e15;
    while ((r - l) > 5e2) {
        ldb lm = (l * 2 + r) / 3, rm = (l + 2 * r) / 3;
        ldb lf = f(floor(lm)), rf = f(floor(rm));
        if (lf > rf)
            l = lm;
        else
            r = rm;
    }
    for (ldb i = l - 1; i <= r + 1; i += 1) ans = min(ans, f(floor(i)));
    printf("%.10Lf\n", ans);
}

int main() {
    int _t;
    scanf("%d", &_t);
    while (_t--) solve();
    return 0;
}
```

</details>

## G - Go

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## H - Harmonious Rectangle

### 题意简述

### 解题思路

> 沉迷搞 A 题导致没去打表, 难受

由抽屉原理, 如果$m,n>9$则任意矩阵均满足要求, 结果为$3^{mn}$

剩下的打表即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
// from dny
#include <bits/stdc++.h>
using namespace std;
#define debug                                  \
    printf("%d %s\n", __LINE__, __FUNCTION__); \
    fflush(stdout)
using ll = int64_t;
using ld = double;
using pii = pair<int, int>;
using vi = vector<int>;
using qi = queue<int>;
using pqi = priority_queue<int>;
using si = set<int>;
#define pb push_back
#define mk make_pair
#define ins insert
#define era erase
#define fi first
#define se second
#define lowbit(x) x & -x
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
int _w, _t;
FILE* _f;
#define MULTI_CASES

const int MOD = 1e9 + 7;

int n, m, f[10][10], edge[2500][2500];

int plu(int u, int v) {
    return (u + v) % MOD;
}

int mul(int u, int v) {
    return (int)(1LL * u * v % MOD);
}

int qpow(int u, int v) {
    int tmp = 1;
    while (v > 0) {
        if (v & 1) {
            tmp = mul(tmp, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return tmp;
}

int A(int u, int v) {
    int tmp = 1;
    for (int i = u, j = 1; j <= v; i--, j++) {
        tmp = mul(tmp, i);
    }
    return tmp;
}

vector<vi> ans[8][8];

bool check(vi va, vi vb, int u) {
    int tmp = 0;
    for (int i = 0; i < u; i++) {
        tmp += (va[i] == vb[i] ? 1 : 0);
    }
    if (tmp > 1) {
        return 0;
    }
    for (int i = 0; i < u; i++) {
        for (int j = i + 1; j < u; j++) {
            if (va[i] == va[j] && vb[i] == vb[j]) {
                return 0;
            }
        }
    }
    return 1;
}

vi trans3(int u, int v) {
    vi tmp(v);
    for (int i = 0; i < v; i++) {
        tmp[i] = u % 3;
        u /= 3;
    }
    return tmp;
}

void work(int u, int v) {
    int mx = qpow(3, u);
    for (auto p : ans[u][v - 1]) {
        int lst = p[v - 2];
        p.pb(0);
        for (int i = lst + 1, flag; i < mx; i++) {
            flag = 1;
            for (int j = 0; j < v - 1; j++) {
                if (!check(trans3(p[j], u), trans3(i, u), u)) {
                    flag = 0;
                }
            }
            if (flag) {
                p[v - 1] = i;
                ans[u][v].pb(p);
            }
        }
    }
    f[u][v] = (int)ans[u][v].size();
    for (int i = 1; i <= v; i++) {
        f[u][v] = mul(f[u][v], i);
    }
}

void triprint(int u, int v) {
    printf("(");
    stack<int> tmp;
    for (int i = 0; i < v; i++) {
        tmp.push(u % 3);
        u /= 3;
    }
    for (int i = 0; i < v; i++) {
        printf("%d ", tmp.top());
        tmp.pop();
    }
    printf(")");
}

void pre(int u) {
    int mx = qpow(3, u);
    memset(edge, 0, sizeof edge);
    for (int i = 0; i < mx; i++) {
        vi bit[2];
        bit[0] = trans3(i, u);
        for (int j = i + 1; j < mx; j++) {
            bit[1] = trans3(j, u);
            if (!check(bit[0], bit[1], u)) {
                continue;
            }
            edge[i][j] = edge[j][i] = 1;
        }
    }
    vi tmp(1);
    for (int i = 0; i < mx; i++) {
        tmp[0] = i;
        ans[u][1].pb(tmp);
    }
    for (int i = 2, lst; i < u; i++) {
        for (auto v : ans[u][i - 1]) {
            lst = v[i - 2];
            for (int j = lst + 1, flag; j < mx; j++) {
                flag = 1;
                for (auto w : v) {
                    if (!edge[w][j]) {
                        flag = 0;
                    }
                }
                if (flag) {
                    vi pa = v;
                    pa.pb(j);
                    ans[u][i].pb(pa);
                }
            }
        }
    }
}

void init() {
    for (int i = 2; i < 8; i++) {
        f[2][i] = plu(mul(3 * i, A(6, i - 1)), A(6, i));
    }
    for (int i = 3; i < 8; i++) {
        pre(i);
    }
    for (int i = 3; i < 8; i++) {
        printf("f[%d][%d]=%d\n", i, i - 1, (int)ans[i][i - 1].size());
        for (int j = i; j < 8; j++) {
            work(i, j);
        }
    }
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            printf("%d%c", f[i][j], " \n"[j == 7]);
        }
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        printf("0\n");
        return;
    }
    if (m > 7) {
        printf("%d\n", qpow(3, n * m));
        return;
    } else {
        printf("%d\n", plu(qpow(3, n * m), MOD - f[n][m]));
    }
}

void newinit() {
    f[2][2] = 66;
    f[2][3] = 390;
    f[2][4] = 1800;
    f[2][5] = 6120;
    f[2][6] = 13680;
    f[2][7] = 15120;
    f[3][3] = 3198;
    f[3][4] = 13176;
    f[3][5] = 27000;
    f[3][6] = 13680;
    f[3][7] = 15120;
    f[4][4] = 24336;
    f[4][5] = 4320;
    f[5][5] = 4320;
}

int main() {
    // init();
    newinit();
#ifdef MULTI_CASES
    _w = scanf("%d", &_t);
    while (_t--)
#endif
        solve();
    return 0;
}
```

</details>

## I - Interested in Skiing

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## J - Just Another Game of Stones

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## K - K Co-prime Permutation

### 题意简述

找到$1..n$的一个排列$\def\enum#1{p_{ #1}}\enum{1},\enum{2},...,\enum{n}$满足恰有$k$个数$\def\enum#1{i_{ #1}}\enum{1},\enum{2},...,\enum{k}$满足
$$(i_k,p_{i_k})=1$$

### 解题思路

首先$k$一定大于$1$, 之后对$2..k$做一次轮换即可(因为相邻两数一定互质, 且$2$和$k$互质当且仅当$k$为奇数)

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (!k) {
        printf("-1\n");
        return 0;
    }
    printf("%d ", k);
    for (int i = 2; i <= k; i++) printf("%d%c", i - 1, " \n"[i == n]);
    for (int i = k + 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
    return 0;
}
```

</details>

## L - Let's Play Curling

### 题意简述

给定整数$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$和$\def\enum#1{b_{ #1}}\enum{1},\enum{2},...,\enum{m}$, 令
$$f(c)=\left|\left\{i\mid\forall j\in[1,m]\cap\N,~|c-a_i|<|c-b_j|\right\}\right|$$
求 $\displaystyle\max_{c\in\R} f(c)$

### 解题思路

先排序, 如果$c$在$b_i,b_{i+1}$之间, 则$f(c)$最大值即为两数 2 之间夹的$a$个数

所以$O(m)$跑一遍即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void qread(int& xx) {
    xx = 0;
    int ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        xx = xx * 10 + ch - '0';
        ch = getchar();
    }
}

int n, m, a[N], b[N], ans;
void solve() {
    ans = 0;
    qread(n);
    qread(m);
    for (int i = 1; i <= n; i++) qread(a[i]);
    for (int i = 1; i <= m; i++) qread(b[i]);
    b[m + 1] = 0x3f3f3f3f;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 0, l, r; i <= m; i++)
        if (b[i] ^ b[i + 1]) {
            l = upper_bound(a + 1, a + n + 1, b[i]) - a;
            r = lower_bound(a + 1, a + n + 1, b[i + 1]) - a;
            ans = max(ans, r - l);
        }
    if (ans)
        printf("%d\n", ans);
    else
        printf("Impossible\n");
}

int main() {
    int _t;
    scanf("%d", &_t);
    while (_t--) solve();
    return 0;
}
```

</details>

## M - Monster Hunter

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>
