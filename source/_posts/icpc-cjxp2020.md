---
title: 题解 - 2020 ICPC 江西省大学生程序设计竞赛
categories:
  - 程序设计
  - 题解
  - ICPC
tags:
  - 程序设计
  - 题解
  - ICPC
  - 算法
  - 数据结构
  - 数学
  - 搜索
  - 打表
  - 模拟
  - 数论
  - 计数
  - 组合数学
  - 容斥定理
  - 图论
  - 状态压缩
  - DP
  - 整除
  - 二分
  - 位运算
  - Möbius反演
  - 前缀和
  - 差分
  - Stirling数
  - 第二类Stirling数
  - 生成函数
  - Floyd算法
  - 分块
  - 自动机
  - 后缀自动机
  - 状压DP
  - DFS
  - 线段树
  - 树状数组
date: 2020-11-15 23:01:18
---
[比赛链接](https://ac.nowcoder.com/acm/contest/8827)

<!-- more -->

## 题目概览

| 题号[^1] | 标题[^2]                                     | AC / total | 做法                   |
| ---- | -------------------------------------------- | ---------- | ---------------------- |
| A    | A Simple Math Problem                        | 15 / 207   | Möbius反演 / 容斥定理  |
| B    | Apple                                        | 198 / 562  | 签到                   |
| *C   | Charging                                     | 9 / 157    | 线段树/树状数组 + 二分 |
| *D   | Chinese Valentine's Day                      | 0 / 195    | 后缀自动机             |
| E    | Color Sequence                               | 29 / 231   | 位运算                 |
| F    | Magical Number                               | 3 / 23     | 打表 + DFS             |
| G    | Mathematical Practice                        | 39 / 64    | 组合数学               |
| H    | Sequence                                     | 15 / 74    | 分块 / 线段树          |
| I    | Simple Math Problem                          | 107 / 452  | 签到                   |
| J    | [Split Game](https://vjudge.net/problem/POJ-2311/origin) | 4 / 133    | 博弈论                 |
| K    | Travel Expense                               | 33 / 280   | Floyd + 二分           |
| *L   | WZB's Harem                                  | 9 / 97     | 状压DP                 |
| M    | Zoos's Animal Codes                          | 205 / 241  | 签到                   |

[^1]: 打*的是还没写题解的题
[^2]: 带超链接的是找到了原题或原型

[官方题解](official_solutions.zip)

{% pdf /article/icpc-cjxp2020/problems.pdf 600px %}

## A - A Simple Math Problem

### 题意简述

$\forall x=\sum_{i=0}^la_i\cdot 10^i,~a_0,a_1,...,a_l\in[0,9]\cap\N$, 定义$F(x)=\sum_{i=0}^la_i$, 求
$$\sum_{i=1}^n\sum_{j=1}^i[(i,j)=1]F(j)$$

### 解题思路

> 你这咋还和I抢上名字了

官方题解是容斥定理, 不过我按Möbius反演板子题做的
$$\begin{aligned}
  \sum_{i=1}^n\sum_{j=1}^i[(i,j)=1]F(j)&=\sum_{i=1}^n\sum_{j=1}^iF(j)\sum_{d\mid(i,j)}\mu(d)\\
  &=\sum_{d=1}^n\mu(d)\sum_{i=1}^{\lfloor{n\over d}\rfloor}\sum_{j=1}^iF(jd)\\
  &=\sum_{d=1}^n\mu(d)\sum_{j=1}^{\lfloor{n\over d}\rfloor}(n-j+1)F(jd)\\
  &=\sum_{d=1}^n\mu(d)\left((n+1)\sum_{j=1}^{\lfloor{n\over d}\rfloor}F(jd)-\sum_{j=1}^{\lfloor{n\over d}\rfloor}jF(jd)\right)\\
\end{aligned}$$

令$g_n(d)=\sum_{j=1}^{\lfloor{n\over d}\rfloor}F(jd)$, $h_n(d)=\sum_{j=1}^{\lfloor{n\over d}\rfloor}jF(jd)$

则答案为$\sum_{d=1}^n\mu(d)((n+1)g_n(d)-h_n(d))$

预处理$\mu$, $g_n$, $h_n$即可

### 复杂度

$O(n\log n)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
* @Author: Tifa
* @LastEditTime: 2020-11-15 23:01:18
* @Description:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

bool vis[N];
int mu[N], prime[N], cnt;

int64_t a[N], b[N], c[N];

int main() {
    int n;
    cin >> n;
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            mu[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1, _; i <= n; ++i) {
        _ = i;
        while (_) {
            a[i] += _ % 10;
            _ /= 10;
        }
    }
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= sqrt(i); ++j)
            if (i % j == 0) {
                b[j] += i / j * a[i];
                c[j] += a[i];
                if (j != i / j) {
                    b[i / j] += j * a[i];
                    c[i / j] += a[i];
                }
            }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) ans += mu[i] * ((n / i + 1) * c[i] - b[i]);
    cout << ans;
    return 0;
}
```

</details>

## B - Apple

### 解题思路

签到题, 问$n$是否被$m$整除

## C - Charging

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## D - Chinese Valentine's Day

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## E - Color Sequence

### 题意简述

给一个长度为$n$的串, 其中第$i$位的颜色为$c_i$, 求有多少子串满足其上任意一种颜色出现次数均为偶数次

### 解题思路

注意到$c\leqslant 20$, 所以我们可以考虑对子串颜色情况进行状态压缩

令$f(l,r)=\bigoplus_{i=l}^r2^{c_i}$, 其中$\oplus$为异或运算

可知若串$[l,r]$满足条件, 则$f(l,r)=0$

又由异或的性质, 有$f(l,r)=f(1,l-1)\oplus f(1,r)$, 则
$$f(l,r)=0\iff f(1,l-1)=f(1,r)$$

所以我们可以对输入求前缀异或和, 若在求到某处时的结果不为$0$且 之前得出的结果中有$k$个和当前结果相等, 则答案直接加$k$即可, 若结果为$0$则需加$k+1$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
* @Author: Tifa
* @LastEditTime: 2020-11-15 23:01:18
* @Description:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;

int cnt[N] = {1};

int main() {
    int n;
    cin >> n;
    int state = 0;
    int64_t ans = 0;
    for (int i = 1, _; i <= n; ++i) {
        cin >> _;
        ans += cnt[state ^= (1 << _)]++;
    }
    cout << ans;
    return 0;
}
```

</details>

## F - Magical Number

### 题意简述

能否恰好用$n$根火柴棍摆出满足如下条件的数$s$, 如果可以, 输出最大的数

令$s=\overline{a_1a_2...a_k}$, 其中$a_1,a_2,...,a_k\in[0,9]\cap\N$, **可以有前导零**, 要求
$$\forall i\in[1,k]\cap\N,~i\mid\overline{a_1a_2...a_i}$$

### 解题思路

首先若$n<2$则一定无解

- 如果不可以有前导零:
  <details open>
  <summary><font color='orange'>Show / Hide</font></summary>

  下面不考虑$s=0$的情况

  设$A_i=\overline{a_1a_2...a_i}$, 则$A_i=10A_{i-1}+a_i$
  
  设$A_i$满足条件, 令$a_i$取值构成的集合为$S_A(i)$, 不难证明
  $$|S_A(i)|\leqslant\left\lceil{10\over i}\right\rceil$$

  所以满足条件的$A_i$个数必随着$i$的增加而先增加后减小

  容易验证满足条件的$A_i$有限

  </details>
- 如果可以有前导零
  
  情况稍微复杂一些, 但类似无前导零的情况

  首先我们注意到, 若$6\mid n$则一定有解($n\over6$个$0$即是一种情况)

  > 但是这题数据造弱了, 写成若$n\geqslant 140$则无解也能过

  其次, 若最后解为正数, 则解的前导零个数必不超过$8$

  接下来对这$8$种情况分别讨论即可

  > 官方题解给的是一共有$20456$个数满足条件, 最长的数为$3608528850358400786036725$

所以状态数不是很大, 直接DFS即可

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
* @Author: Tifa
* @LastEditTime: 2020-11-15 23:01:18
* @Description:
*/
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
const int num_stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
 
int n;
i128 max_ans;
bool dfs(i128 ans = 0, int sum = 0, int dep = 0) {
    if (sum > n) return false;
    if (sum == n) {
        max_ans = max(max_ans, ans);
        return true;
    }
    bool f = false;
    for (int i = 0; i < 10; ++i)
        if ((ans * 10 + i) % (dep + 1) == 0) f |= dfs(ans * 10 + i, sum + num_stick[i], dep + 1);
    return f;
}
 
ostream& operator<<(ostream& os, i128 n) {
    if (n < 0) {
        os << '-';
        n = -n;
    }
    if (n > 9) os << (i128)(n / 10);
    os << (int)(n % 10);
    return os;
}
 
int main() {
    cin >> n;
    if (n > 139 || !dfs()) {
        cout << -1;
        return 0;
    }
    cout << max_ans;
    return 0;
}
```

</details>

## G - Mathematical Practice

### 题意简述

在有$n$个元素的集合中有顺序地取$m$个子集, 问这$m$个子集中两两不相交的取法数

### 解题思路

- 正常做法

  不难发现题目等价于: 将至多$n$个不同的小球放到$m$个不同的盒子里, 允许盒子为空

  又等价于将$n$个不同的小球放到$m+1$个不同的盒子里, 允许盒子为空 (多出来的一个盒子用来装没选的球)

  所以答案就是$(m+1)^n$

- 猛男做法

  结合第二类Stirling数和排列数的定义不难推出答案为
  $$\sum_{i=0}^n\sum_{j=0}^i{i\brace j}{n\choose i}{m\choose j}j!\bmod998244353$$

  又
  $$x^i=\sum_{j=0}^i{i\brace j}{x\choose j}j!$$

  故答案为
  $$\sum_{i=0}^n{n\choose i}m^i=(1+m)^n$$

## H - Sequence

### 题意简述

维护序列$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$, 对其进行$m$次操作, 共两种:

1. `1 x y`: 将$a_x$修改为$y$
1. `2 x`: 询问以$a_x$为最小值的子串数

保证任意时刻$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$两两不同

### 解题思路

显然分块或者线段树, 我写的分块

块存最小值, 更新就是更新原数组和其所在块, 查询就是从$x$出发, 向左找第一个小于$a_x$的数$a_l$ (找不到就是$a_1$), 向右找第一个小于$a_x$的数$a_r$ (找不到就是$a_n$), 答案就是$(x-l+1)(r-x+1)$

不知道为啥有人就特殊处理全局最小和全局最大, 剩下的情况暴力就过了, 这数据...

### 复杂度

设块长为$l$, 则时间复杂度为$O(n+ml)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
* @Author: Tifa
* @LastEditTime: 2020-11-15 23:01:18
* @Description:
*/
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
const int N = 1e5 + 5, BLOCK_N = 4e2 + 5;

i64 n, a[N];
i64 block_len, block_cnt;
i64 blocks[BLOCK_N], block_id[N];

i64 block_l(i64 b_id) { return max(1ll, b_id * block_len); }
i64 block_r(i64 b_id) { return min(n, (b_id + 1) * block_len - 1); }
void init() {
    block_len = sqrt(n);
    block_cnt = sqrt(n) + (n != block_len * block_len);
    for (int i = 0; i < block_cnt; ++i) blocks[i] = INT_MAX;
    for (int i = 1; i <= n; ++i) blocks[block_id[i] = i / block_len] = min(a[i], blocks[i / block_len]);
}

void modify(i64 pos, i64 num) {
    if (a[pos] != blocks[block_id[pos]]) {
        blocks[block_id[pos]] = min(a[pos] = num, blocks[block_id[pos]]);
        return;
    }
    blocks[block_id[pos]] = a[pos] = num;
    for (int i = block_l(block_id[pos]); i <= block_r(block_id[pos]); ++i) blocks[block_id[pos]] = min(a[i], blocks[block_id[pos]]);
}
i64 query(i64 pos) {
    i64 l_bid = block_id[pos], r_bid = block_id[pos];
    while (l_bid && blocks[l_bid] >= a[pos]) --l_bid;
    if (l_bid < block_id[pos] && blocks[l_bid] < a[pos]) ++l_bid;
    while (r_bid < n && blocks[r_bid] >= a[pos]) ++r_bid;
    if (r_bid > block_id[pos] && blocks[r_bid] < a[pos]) --r_bid;

    i64 l = block_l(l_bid), r = block_r(r_bid);
    if (l_bid == block_id[pos]) l = pos;
    while (l && a[l] >= a[pos]) --l;
    if (a[l] < a[pos]) ++l;
    if (r_bid == block_id[pos]) r = pos;
    while (r <= n && a[r] >= a[pos]) ++r;
    if (a[r] < a[pos]) --r;
    i64 l_len = pos - l + 1, r_len = r - pos + 1;
    return l_len * r_len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init();
    i64 op, x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            modify(x, y);
        } else
            cout << query(x) << endl;
    }
    return 0;
}
```

</details>

## I - Simple Math Problem

### 解题思路

签到题, 注意最后结果转成十进制

## J - Split Game

### 题意简述

有个$n\times m$的矩形网格纸, `Alice`和`Bob`轮流行动, `Alice`先手, 每个人均要选一张纸片并, 沿某条网格线将其剪成两片, 率先剪出$1\times 1$纸片的玩家判**负**, 两人均采取最优行动, 问谁胜

### 解题思路

![](J-1.jpg)

原型是一道经典的博弈论题

我们可以把每张纸片均看作一个有向图游戏, 整张纸看作有向图游戏的和

令$\operatorname{SG}(m,n)$表示$m\times n$纸片对应的$\operatorname{SG}$函数值

显然$1\times 1$, $1\times 2$, $2\times 1$, $3\times 1$, $1\times 3$的纸片是必败局面

另外
$$\operatorname{SG}(m,n)=\operatorname{mex}S$$

其中, $S=S_1\cup S_2$
$$S_1=\bigcup_{i=1+[n=1]}^{\lfloor{m\over 2}\rfloor}\{\operatorname{SG}(i,n)\oplus\operatorname{SG}(m-i,n)\}$$
$$S_2=\bigcup_{i=1+[m=1]}^{\lfloor{n\over 2}\rfloor}\{\operatorname{SG}(m,i)\oplus\operatorname{SG}(m,n-i)\}$$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
* @Author: Tifa
* @LastEditTime: 2020-11-15 23:01:18
* @Description:
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 22505, N = 155;

int sg[N][N];
int f(int m, int n) {
    if (~sg[m][n]) return sg[m][n];
    bool vis[M];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m - i; ++i) {
        if ((i == 1 && n == 1) || (m - i == 1 && n == 1)) continue;
        vis[f(i, n) ^ f(m - i, n)] = 1;
    }
    for (int i = 1; i <= n - i; ++i) {
        if ((i == 1 && m == 1) || (n - i == 1 && m == 1)) continue;
        vis[f(m, i) ^ f(m, n - i)] = 1;
    }
    for (int i = 0; i < M; ++i)
        if (!vis[i]) return sg[m][n] = i;
}

int main() {
    int m, n;
    memset(sg, 0xff, sizeof(sg));
    sg[1][1] = sg[1][2] = sg[2][1] = sg[1][3] = sg[3][1] = 0;
    while (cin >> m >> n)
        cout << (f(m, n) ? "Alice" : "Bob") << endl;
    return 0;
}
```

</details>

## K - Travel Expense

### 题意简述

给出$n$个点$m$条边的无向图, 定义$d(u,v)$为点$u$到点$v$的最短路长度, 有$q$次询问, 每次给定$s,t,b$, 问满足$\sum_{i=1}^{d(s,t)}k^i\leqslant b$的最大的$k$是多少

### 解题思路

显然Floyd+二分, 需要注意不要去求$k^{d(s,t)}$, 会爆`int64_t`

### 复杂度

$O(n^3+q\log B\log n)$, 其中$B$表示所有询问中最大的$b$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
* @Author: Tifa
* @LastEditTime: 2020-11-15 23:01:18
* @Description:
*/
#include <bits/stdc++.h>
using namespace std;

template <const std::size_t N = (std::size_t)1e2 + 5, class graph_t = std::ptrdiff_t>
class Floyd {
  private:
    std::size_t n;
    graph_t spath[N][N];

  public:
    Floyd(std::size_t _n = N - 1) : n(_n) {
        memset(spath, 0x3f, sizeof(spath));
        for (std::size_t i = 1; i <= n; ++i) spath[i][i] = 0;
    }
    void resize(std::size_t _n) { n = _n; }
    void clear() { memset(spath, 0, sizeof(spath)); }
    void addedge(std::size_t from, std::size_t to, graph_t w = 1) { spath[from][to] = w; }
    void get_all_spath() {
        for (std::size_t k = 1; k <= n; ++k)
            for (std::size_t i = 1; i <= n; ++i)
                for (std::size_t j = 1; j <= n; ++j)
                    if (spath[i][k] + spath[k][j] < spath[i][j]) spath[i][j] = spath[i][k] + spath[k][j];
    }
    const graph_t& operator()(std::size_t from, std::size_t to) { return spath[from][to]; }
};
Floyd<> f;

bool judge(int64_t k, int64_t l, int64_t b) {
    if (k > 1)
        return  l * log(k) <= log(b + 1 - 1.0 * b / k);
    else if (k == 1)
        return l <= b;
    else
        return b >= 0;
}

int main() {
    int m, n;
    cin >> n >> m;
    f.resize(n);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        f.addedge(u, v);
        f.addedge(v, u);
    }
    f.get_all_spath();
    int q;
    cin >> q;
    for (int i = 1, s, t, b; i <= q; ++i) {
        cin >> s >> t >> b;
        int64_t l = f(s, t);
        int64_t left = 0, right = b, mid, k;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (judge(mid, l, b)) {
                k = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        cout << k << endl;
    }
    return 0;
}
```

</details>

## L - WZB's Harem

### 题意简述

### 解题思路

> 模数出锅还不修是真的np

### 复杂度

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp

```

</details>

## M - Zoos's Animal Codes

### 解题思路

签到题
