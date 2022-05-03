---
title: 题解 - 兰州大学第一届『飞马杯』程序设计竞赛
author: "Tifa & AgOH(code D)"
coauthor:
  - AgOH
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 校赛
  - 数学
  - 算法
  - 数据结构
  - DP
  - 动态DP
  - 线段树
  - 树链剖分
  - 前缀和
  - 计算几何
  - 概率
  - 期望
  - 图论
  - 二分图
  - 网络流
  - 最大流
  - 模拟
  - 暴力
  - hash
  - 博弈论
  - 光速幂
  - Euler定理
  - 不动点
  - 二次剩余
date: 2021-10-24 20:15:45
---

[比赛链接](https://ac.nowcoder.com/acm/contest/16520)

因为我的做法和官方题解高度重合, 所以略去大多数内容

<!-- more -->

## 题目概览

| 题号 | 标题             | 做法           |
| ---- | ---------------- | -------------- |
| A    | ★★ 比赛新机制 ★★ | 前缀和         |
| B    | ★★ 体育课排队 ★★ | 最大流         |
| C    | ★★ 生命的游戏 ★★ | 模拟           |
| D    | ★★ 飞马祝福语 ★★ | 动态 DP        |
| E    | ★★ 序列大团结 ★★ | hash           |
| F    | ★★ 飞马分隔符 ★★ | 签到           |
| G    | ★★ 糖果魔法阵 ★★ | 数学           |
| H    | ★★ 温暖的力量 ★★ | 签到           |
| I    | ★★ 平形四边行 ★★ | 数学           |
| J    | ★★ 翻滚吧硬币 ★★ | 几何           |
| K    | ★★ 快乐苹果树 ★★ | 期望, 树链剖分 |
| L    | ★★ 星星收集者 ★★ | 博弈论         |

{% pdf /article/lzu-fhc1/problems.pdf 600px %}

## 官方题解

{% pdf /article/lzu-fhc1/official_solutions.pdf 600px %}

## A - ★★ 比赛新机制 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

#define _rfor(i, r, l, vals...) for (decltype(r - l) i = (r), ##vals; i >= (l); --i)

const int OFFSET = 5;
const int N = 5e5 + OFFSET;

template <class T>
bool chkmin(T& a, T b) { return b < a ? a = b, true : false; }

i64 a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    cin >> _t;
    while (_t--) {
        int n;
        cin >> n;
        _for(i, 1, n) cin >> a[i];
        i64 sum = 0;
        _for(i, 1, n) sum += a[i];
        i64 sum1 = 0, sum2 = 0;
        _for(i, 1, n) {
            sum1 += i * a[i];
            sum2 += (n - i + 1) * a[i];
        }
        i64 ans = INT64_MAX;
        _rfor(i, n, 1) chkmin(ans, sum1 += sum - n * a[i]);
        _for(i, 1, n) chkmin(ans, sum2 += sum - n * a[i]);
        cout << ans << '\n';
    }
    return 0;
}
```

</details>

## B - ★★ 体育课排队 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

```

</details>

## C - ★★ 生命的游戏 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

const int OFFSET = 5;
const int N = 100 + OFFSET;

const pii d[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int maps0[N][N], maps[N][N], maps2[N][N];

int n;

int cnt(int i, int j) {
    int ret = 0;
    for (const pii& p : d) ret += maps[(i + p.first + n - 1) % n + 1][(j + p.second + n - 1) % n + 1];
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    cin >> _t;
    while (_t--) {
        int k;
        cin >> n >> k;
        _for(i, 1, n) _for(j, 1, n) cin >> maps[i][j];
        _for(i, 1, n) _for(j, 1, n) maps0[i][j] = maps[i][j];
        _for(t, 1, k, _) {
            _for(i, 1, n) _for(j, 1, n) {
                _ = cnt(i, j);
                maps2[i][j] = (maps[i][j] == 0 && _ == 3) ? 1 : (maps[i][j] == 1 && (_ > 3 || _ < 2)) ? 0 : maps[i][j];
            }
            _for(i, 1, n) _for(j, 1, n) maps[i][j] = maps2[i][j];
            bool f = 1;
            _for(i, 1, n) _for(j, 1, n) f &= maps0[i][j] == maps[i][j];
            if (f) {
                cout << "YES\n"
                     << t << '\n';
                return;
            }
        }
        cout << "NO\n";
    }
    return 0;
}
```

</details>

## D - ★★ 飞马祝福语 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: AgOH
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 998244353;

template <int row, int col>
struct Mat { int ele[row][col]; };
template <int row, int col, int row2>
Mat<row, row2> operator*(const Mat<row, col>& m1, const Mat<col, row2>& m2) {
    Mat<row, row2> matt;
    for (int i = 0; i < row; i++) memset(matt.ele[i], 0, row2 * sizeof(int));
    for (int i = 0; i < row; i++)
        for (int k = 0; k < col; k++)
            for (int j = 0; j < row2; j++)
                matt.ele[i][j] = (matt.ele[i][j] + (int64_t)m1.ele[i][k] * m2.ele[k][j] % mod) % mod;
    return matt;
}

Mat<6, 6> ident = {{
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
}};
Mat<6, 6> M[] = {ident, ident, ident, ident, ident, ident, ident};
char dict[130];
auto ___ = []() {
    M[1].ele[0][5] = M[2].ele[1][0] = M[3].ele[2][1] = M[4].ele[3][2] = M[5].ele[4][3] = 1;
    fill(begin(dict), end(dict), 6);
    dict['F'] = 1;
    dict['e'] = 2;
    dict['i'] = 3;
    dict['M'] = 4;
    dict['a'] = 5;
    return 0.0;
}();

Mat<6, 6> mpow[6][maxn];

char s[maxn];
struct Node {
    int l, r, f;
    Mat<6, 6> val;
} sgt[maxn << 2];

#define ls(k) (k << 1)

#define rs(k) (k << 1 | 1)
inline void push_up(int k) { sgt[k].val = sgt[rs(k)].val * sgt[ls(k)].val; }
inline void push_down(int k) {
    int f = sgt[k].f;
    sgt[k].f = 0;
    sgt[ls(k)].f = sgt[rs(k)].f = f;
    if (f == 6)
        sgt[ls(k)].val = sgt[rs(k)].val = ident;
    else {
        sgt[ls(k)].val = mpow[f][sgt[ls(k)].r - sgt[ls(k)].l + 1];
        sgt[rs(k)].val = mpow[f][sgt[rs(k)].r - sgt[rs(k)].l + 1];
    }
}
void build(int l, int r, int k = 1) {
    sgt[k].l = l, sgt[k].r = r, sgt[k].f = 0;
    if (l == r)
        sgt[k].val = M[(int)dict[(int)s[l - 1]]];
    else {
        int m = (l + r) >> 1;
        build(l, m, ls(k));
        build(m + 1, r, rs(k));
        push_up(k);
    }
}
void modify(int x, int y, int z, int k = 1) {
    int l = sgt[k].l, r = sgt[k].r;
    if (x <= l && y >= r) {
        sgt[k].f = z;
        if (z == 6)
            sgt[k].val = ident;
        else
            sgt[k].val = mpow[z][r - l + 1];
        return;
    }
    if (sgt[k].f) push_down(k);
    int m = (l + r) >> 1;
    if (x <= m) modify(x, y, z, ls(k));
    if (y > m) modify(x, y, z, rs(k));
    push_up(k);
}
auto query(int x, int y, int k = 1) {
    int l = sgt[k].l, r = sgt[k].r;
    if (x <= l && y >= r) return sgt[k].val;
    if (sgt[k].f) push_down(k);
    int m = (l + r) >> 1;
    auto ret = ident;
    if (x <= m) ret = ret * query(x, y, ls(k));
    if (y > m) ret = ret * query(x, y, rs(k));
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 5; i++) mpow[i][0] = ident;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 10001; j++) mpow[i][j] = mpow[i][j - 1] * M[i];
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q >> s;
        build(1, n);
        while (q--) {
            int l, r;
            char c;
            cin >> l >> r >> c;
            modify(l, r, dict[(int)c]);
            cout << query(1, n).ele[4][5] << endl;
        }
    }
    return 0;
}
```

</details>

## E - ★★ 序列大团结 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

const int OFFSET = 5;
const int N = 1e5 + OFFSET;
const int P = 1e9 + 1;

u64 a[N];

u64 qpow(u64 a, u64 b) {
    u64 res(1);
    for (; b; b >>= 1, (a *= a))
        if (b & 1) (res *= a);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    cin >> _t;
    while (_t--) {
        int n, k;
        cin >> n >> k;
        _for(i, 1, n) cin >> a[i];
        map<u64, i64> _ans, cnt;
        _ans[0] = 1;
        i64 ans = 0;
        u64 _hash = 0;
        _for(i, 1ll, n) {
            if (a[i] % k) {
                _hash += ((cnt[a[i]] + 1) % k - cnt[a[i]]) * qpow(P, a[i]);
                cnt[a[i]] = (cnt[a[i]] + 1) % k;
            }
            ans += _ans[_hash]++;
        }
        cout << ans << '\n';
    }
    return 0;
}
```

</details>

## G - ★★ 糖果魔法阵 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

#define _rfor(i, r, l, vals...) for (decltype(r - l) i = (r), ##vals; i >= (l); --i)

template <typename Tp = i64>
class rpow final {
  private:
    uint32_t mod;
    Tp base;
    std::array<Tp, 65536> block1, block2;

  public:
    rpow(const Tp& _base, const uint32_t& _mod) : base(_base), mod(_mod) {
        block1[0] = block2[0] = 1;
        for (uint32_t i = 1; i < 65536; i++) block1[i] = block1[i - 1] * base % mod;
        Tp _(block1.back() * base % mod);
        for (uint32_t i = 1; i < 65536; i++) block2[i] = block2[i - 1] * _ % mod;
    }

    Tp&& get_base() { return std::move(base); }
    uint32_t&& get_mod() { return std::move(mod); }

    Tp operator()(std::make_unsigned_t<Tp>&& exponent) { return block1[exponent & 65535] * block2[exponent >> 16] % mod; }
};

const i64 mod = 998244353;
const i64 sqrt2 = 116195171;
const i64 sqrt2plus1 = sqrt2 + 1, msqrt2plus1 = mod + 1 - sqrt2;
const i64 phi_mod = mod - 1, phi_phi_mod = 402653184;

template <typename Tp = i64>
Tp inv(Tp a) {
    a %= mod;
    Tp b(mod - 2), res(1);
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (res *= a) %= mod;
    return res;
}

rpow<i64> a(sqrt2plus1, mod);
rpow<i64> b(msqrt2plus1, mod);
rpow<i64> _4(4, phi_mod);

int main() {
    i64 s, c, q;
    cin >> s >> c >> q;
    _for(i, 1ll, q, _, ans, t) {
        cin >> _;
        ans = s;
        _for(i, 1, _, k = 0) {
            k += ans / c;
            t = _4(k = k % phi_phi_mod + (k >= phi_phi_mod) * phi_phi_mod);
            ans = ((a(t) + b(t)) * sqrt2 % mod) * i % mod;
        }
        cout << ans * (inv(_) * inv(a(t) - b(t) + mod) % mod) % mod << '\n';
    }
    return 0;
}
```

</details>

## I - ★★ 平形四边行 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), ##vals; i <= (r); ++i)

vector<pii> points;
map<pii, pii> midp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    _for(i, 1, n, x, y) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    for (auto it = points.begin(); it != points.end(); ++it)
        for (auto it2 = points.begin(); it2 != it; ++it2) {
            auto mid = make_pair(it->first + it2->first, it->second + it2->second);
            auto i = it - points.begin(), j = it2 - points.begin();
            if (!midp.count(mid)) {
                midp[mid] = {i, j};
                continue;
            }
            if (midp[mid].first == i || midp[mid].first == j || midp[mid].second == i || midp[mid].second == j) continue;
            cout << "YES\n"
                 << i + 1 << ' ' << j + 1 << ' ' << midp[mid].first + 1 << ' ' << midp[mid].second + 1 << '\n';
            return;
        }
    cout << "NO\n";

    return 0;
}
```

</details>

## J - ★★ 翻滚吧硬币 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ldb = long double;

const ldb PI = acos(-1.0l);

ldb __(i64 a, i64 b, i64 c) {
    ldb _a = a + b, _b = a + c, _c = c + b;
    return ((PI - acos((_a * _a + _b * _b - _c * _c) / (2 * _a * _b))) * _b + (PI - acos((_a * _a + _c * _c - _b * _b) / (2 * _a * _c))) * _c) / (PI * c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _t;
    cin >> _t;
    while (_t--) {
        i64 a, b, c;
        cin >> a >> b >> c;
        cout << fixed << setprecision(12) << min(min(__(a, b, c), __(a, c, b)), min(min(__(b, a, c), __(b, c, a)), min(__(c, a, b), __(c, b, a)))) << '\n';
    }
    return 0;
}
```

</details>

## K - ★★ 快乐苹果树 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

```

</details>

## L - ★★ 星星收集者 ★★

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-10-24 20:15:45
 * @Description:
 */

```

</details>
