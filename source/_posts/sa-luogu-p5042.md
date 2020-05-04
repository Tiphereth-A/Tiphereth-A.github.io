---
title: "题解 - [Luogu P5042 等] [集训队互测2015] 丢失的题面（ydc的题面）"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 算法
  - 洛谷
  - UOJ
  - 国家集训队
  - 数学
  - 组合数学
  - 图论
  - 数据结构
  - 倍增
  - 并查集
  - Euler回路
  - Kruskal算法
  - Fibonacci数列
  - Thue-Morse序列
  - 进制
  - 三进制
date: 2021-11-18 00:40:39
---

题目链接

- [洛谷 P5042](https://www.luogu.com.cn/problem/P5042)
- [UOJ #100](https://uoj.ac/problem/100)

<!-- more -->

## 原始题面

曾经, 有一个题面摆在 ydc 的面前没有珍惜, 直到失去时才后悔莫及,

如果上天再给他一次机会, ydc 一定会牢牢的记住这个题面

没办法, 已经失去了, 所以这道题只能让你帮 ydc 做了

已知的信息只有, 这道题是传统题, 采用全文比较的方式, 时间限制 $1\texttt{s}$, 空间限制 $256\texttt{MB}$

ydc 还给你提供了这道题的所有数据

数据下载: <https://pan.baidu.com/s/1kT8Al0r> 密码: cb5y

> 不方便用百度网盘的可以在这边下载 [lost.zip](lost.zip)
>
> —— Tifa

---

> **该题在比赛时显示的成绩就是最终成绩**

### 来源

中国国家集训队互测 2015 - By 于纪平

## 题意简述

看数据猜程序

## 解题思路

首先根据输入数据风格分为 4 类

1. 1-3 组: 输入 1 个数, 让你构造一个序列
1. 4-6 组: 输入一个数组, 输出一个和输入数组构造方式差不多的数组
1. 7-9 组: 输入一个图, 还有若干次查询
1. 第 10 组: 送分的

首先说下第 10 组, 直接输出输出文件那一堆就行

接下来是第 1 类

1. 第 1 组: 不难发现是 Thue-Morse 序列, OEIS: [A010060](https://oeis.org/search?q=A010060)
1. 第 2 组: 不难发现是用类似 Fibonacci 数列构造方式构造的
1. 第 3 组: 三进制版的 POJ 1780, 输出数据即为恰好包含全部 12 位三进制数的字典序最小的序列, 做法为以 n-1 位三进制数为结点建图然后从 `00000000000` 出发找 Euler 回路, 不难发现构造出来的序列长度正好为 $3^{12}+12-1=531452$

然后是第 2 类

1. 第 4 组: 不难发现是组合数的数列, 关键在于求模数, 观察第 4 行即可得到为 104857601, 后面两组数据均以此为模数
1. 第 5 组: 就是把第 4 组的输入输出反过来
1. 第 6 组: 按前两组构造方式猜测与组合数有关, 这里猜测和二项式展开有关

或者这样 (注意到 $104857601 = 25\times 2^{22}+1$)

1. 第 4 组: 给出一个多项式, 对其平方
1. 第 5 组: 给出一个多项式, 对其开方
1. 第 6 组: 给出一个多项式, 对其开立方

但是写 FFT 显然没有写组合数简单, 所以这个看看就好

最后是第 3 类

1. 第 7 组: 观察输出数据发现, 输出只有 0 和 `0x7f7f7f7f`, 猜测是判断两点是否连通, 故直接并查集即可
1. 第 8 组: 观察输出数据发现, 输出均和边权差不多, 而且输入的是树, 这里猜测为输出两点路径中的最大边权, 直接倍增一下即可
1. 第 9 组: 观察输出数据发现其特点综合了以上两种情况, 猜测为求两点路径中边权最大值的最小值, 用 Kruskal 找最小生成森林之后倍增即可 (就是把前两种情况都复制过来改改就行)

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-06-03 14:02:01
 * @Description: Luogu P5042, UOJ 100
 */

#include <bits/stdc++.h>
using namespace std;

namespace Subtask_1 {
void main() {
    vector<bool> vb;
    vb.reserve(1 << 22);
    vb.push_back(false);
    for (int i = 0; i < 22; ++i)
        for (auto it = vb.begin(); it != vb.begin() + (1 << i); ++it) vb.push_back(!*it);
    for (auto i : vb) cout << (i ? '1' : '0');
    cout << '\n';
}
}  // namespace Subtask_1

namespace Subtask_2 {
void main() {
    string a("0"), b("1"), c;
    for (int i = 1; i < 33; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << a << '\n';
}
}  // namespace Subtask_2

namespace Subtask_3 {
const int n = 12;
// 3**(n-1)
const int m = 177147;

int node[m + 1];
stack<int> s;
inline void f(int v) {
    int w;
    while (node[v] < 3) {
        s.push(w = 3 * v + node[v]++);
        v = w % m;
    }
}

// POJ 1780
void main() {
    // if (n == 1) { cout << "012\n"; return; }
    string ans;
    f(0);
    int w;
    while (!s.empty()) {
        w = s.top();
        s.pop();
        ans.push_back(w % 3 + '0');
        f(w / 3);
    }
    ans += string(n - 1, '0');
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
}  // namespace Subtask_3

namespace Subtask_4 {
const int p = 104857601, n = 131072, n2 = n * 2;
int inv[n2 + 1];

void main() {
    inv[1] = 1;
    for (int i = 2; i <= n2; ++i) inv[i] = (int64_t)(p - p / i) * inv[p % i] % p;
    vector<int> v;
    v.reserve(n + 1);
    v.push_back(1);
    for (int i = 1; i <= n; ++i) v.push_back(1ll * v.back() * (n2 - i + 1) % p * inv[i] % p);
    cout << n2 << '\n';
    for (auto i : v) cout << i << '\n';
    for (auto it = v.rbegin() + 1; it != v.rend(); ++it) cout << *it << '\n';
}
}  // namespace Subtask_4

namespace Subtask_5 {
const int p = 104857601, n = 131072, n2 = n * 2;
int inv[n2 + 1];

void main() {
    inv[1] = 1;
    for (int i = 2; i <= n2; ++i) inv[i] = (int64_t)(p - p / i) * inv[p % i] % p;
    vector<int> v;
    v.reserve(n + 1);
    v.push_back(1);
    for (int i = 1; i <= n; ++i) v.push_back(1ll * v.back() * (n - i + 1) % p * inv[i] % p);
    cout << n << '\n';
    for (int i = 0; i <= n; ++i) cout << (i % 2 ? p - v[i] : v[i]) << '\n';
}
}  // namespace Subtask_5

namespace Subtask_6 {
const int p = 104857601, a = 23333333, b = 33333333;

inline constexpr int64_t qpow(int64_t a, int64_t b) {
    int64_t res(1);
    for (; b; b >>= 1, (a *= a) %= p)
        if (b & 1) (res *= a) %= p;
    return res;
}

const int inv_a = qpow(a, p - 2);
const int n = 177147;
int inv[n + 1];

void main() {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (int64_t)(p - p / i) * inv[p % i] % p;
    int64_t res = qpow(a, n);
    cout << n << '\n'
         << res << '\n';
    for (int i = 1; i <= n; ++i) cout << (res = res * inv_a % p * b % p * (n - i + 1) % p * inv[i] % p) << '\n';
}
}  // namespace Subtask_6

namespace Subtask_7 {
const int n = 100000, m = 100000, q = 200000;

int dsu[n + 1];
int find(int x) { return x == dsu[x] ? dsu[x] : dsu[x] = find(dsu[x]); }
void merge(int x, int y) { dsu[find(x)] = find(y); }

void main() {
    for (int i = 1; i <= n; ++i) dsu[i] = i;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        cout << (find(x) == find(y) ? "0\n" : "2139062143\n");
    }
}
}  // namespace Subtask_7

namespace Subtask_8 {
const int n = 100000, m = 99999, q = 200000;
const int lbn = log2(n);

struct Edge {
    int w, to, next;
    Edge(int _w = 0, int _to = 0, int _next = 0) : w(_w), to(_to), next(_next) {}
} e[2 * m + 1];
int head[n + 1], cnt_edge;
void addEdge(int x, int y, int w = 1) {
    e[++cnt_edge] = Edge(w, y, head[x]);
    head[x] = cnt_edge;
}

#define _for_graph(head, e, i, now) for (int i = head[now], to = e[i].to; i; to = e[i = e[i].next].to)

int acstr[n + 1][lbn + 1], max_w[n + 1][lbn + 1], dep[n + 1];

void multiply(int now, int fa) {
    dep[now] = dep[acstr[now][0] = fa] + 1;
    for (int i = 0; i < lbn; ++i) {
        acstr[now][i + 1] = acstr[acstr[now][i]][i];
        max_w[now][i + 1] = max(max_w[now][i], max_w[acstr[now][i]][i]);
    }
    _for_graph(head, e, i, now) {
        if (to == fa) continue;
        max_w[to][0] = e[i].w;
        multiply(to, now);
    }
}

int get_res(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int ans = 0;
    for (int i = lbn; ~i; --i)
        if (dep[acstr[x][i]] >= dep[y]) {
            ans = max(ans, max_w[x][i]);
            x = acstr[x][i];
        }
    if (x == y) return ans;
    for (int i = lbn; ~i; --i)
        if (acstr[x][i] != acstr[y][i]) {
            ans = max(ans, max(max_w[x][i], max_w[y][i]));
            x = acstr[x][i];
            y = acstr[y][i];
        }
    return max(ans, max(max_w[x][0], max_w[y][0]));
}

void main() {
    for (int i = 0, x, y, w; i < m; ++i) {
        cin >> x >> y >> w;
        addEdge(x, y, w);
        addEdge(y, x, w);
    }
    multiply(1, 0);
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        cout << get_res(x, y) << '\n';
    }
}

#undef _for_graph
}  // namespace Subtask_8

namespace Subtask_9 {
const int n = 50000, m = 100000, q = 200000;
const int lbn = log2(n);

struct Edge {
    int w, to, next;
    Edge(int _w = 0, int _to = 0, int _next = 0) : w(_w), to(_to), next(_next) {}
} e[2 * m + 1];
int head[n + 1], cnt_edge;
void addEdge(int x, int y, int w = 1) {
    e[++cnt_edge] = Edge(w, y, head[x]);
    head[x] = cnt_edge;
}

#define _for_graph(head, e, i, now) for (int i = head[now], to = e[i].to; i; to = e[i = e[i].next].to)

int dsu[n + 1];
int find(int x) { return x == dsu[x] ? dsu[x] : dsu[x] = find(dsu[x]); }
void merge(int x, int y) { dsu[find(x)] = find(y); }

int acstr[n + 1][lbn + 1], max_w[n + 1][lbn + 1], dep[n + 1];

void multiply(int now, int fa) {
    dep[now] = dep[acstr[now][0] = fa] + 1;
    for (int i = 0; i < lbn; ++i) {
        acstr[now][i + 1] = acstr[acstr[now][i]][i];
        max_w[now][i + 1] = max(max_w[now][i], max_w[acstr[now][i]][i]);
    }
    _for_graph(head, e, i, now) {
        if (to == fa) continue;
        max_w[to][0] = e[i].w;
        multiply(to, now);
    }
}

int get_res(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int ans = 0;
    for (int i = lbn; ~i; --i)
        if (dep[acstr[x][i]] >= dep[y]) {
            ans = max(ans, max_w[x][i]);
            x = acstr[x][i];
        }
    if (x == y) return ans;
    for (int i = lbn; ~i; --i)
        if (acstr[x][i] != acstr[y][i]) {
            ans = max(ans, max(max_w[x][i], max_w[y][i]));
            x = acstr[x][i];
            y = acstr[y][i];
        }
    return max(ans, max(max_w[x][0], max_w[y][0]));
}

struct Node {
    int x, y, w;

    bool operator<(const Node& rhs) const { return w < rhs.w; }
} data[m];

void main() {
    for (int i = 1; i <= n; ++i) dsu[i] = i;
    for (int i = 0; i < m; ++i) cin >> data[i].x >> data[i].y >> data[i].w;
    sort(data, data + m);
    for (int i = 0; i < m; ++i)
        if (find(data[i].x) != find(data[i].y)) {
            merge(data[i].x, data[i].y);
            addEdge(data[i].x, data[i].y, data[i].w);
            addEdge(data[i].y, data[i].x, data[i].w);
        }
    for (int i = 1; i <= n; ++i)
        if (!dep[i]) multiply(i, 0);
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        if (find(x) != find(y)) {
            cout << "2139062143\n";
            continue;
        }
        cout << get_res(x, y) << '\n';
    }
}

#undef _for_graph
}  // namespace Subtask_9

namespace Subtask_10 {
void main() {
    cout << "Your program should output itself here.\n"
            "Sounds very difficult, yeah?\n"
            "Anyway, good luck!\n";
}
}  // namespace Subtask_10

#define _run_return(expressions) return (expressions), 0

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string _;
    getline(cin, _);
    if (_.front() == 'M') _run_return(Subtask_10::main());
    if (_ == "22") _run_return(Subtask_1::main());
    if (_ == "33") _run_return(Subtask_2::main());
    if (_ == "12") _run_return(Subtask_3::main());
    if (_ == "131072") _run_return(Subtask_4::main());
    if (_ == "262144") _run_return(Subtask_5::main());
    if (_ == "531441") _run_return(Subtask_6::main());
    if (_ == "100000 100000 200000") _run_return(Subtask_7::main());
    if (_ == "100000 99999 200000") _run_return(Subtask_8::main());
    if (_ == "50000 100000 200000") _run_return(Subtask_9::main());
    return 1;
}
```

</details>
