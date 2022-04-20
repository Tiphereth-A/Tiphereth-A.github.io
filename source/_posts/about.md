---
title: "[置顶] 关于本博客 & FAQ"
comments: false
top: 2147483647
date: 2020-05-04 19:07:23
---
一个数学系ACMer的小站, 主要记录与数学和算法竞赛相关的内容

如果**出现页面加载错误** (如 **评论区丢失**) 请刷新

<div style="text-align: center;"><div>{% button /article/about/#目录汇总 ,目录汇总, th fa-fw %}{% button /frilinks ,友链, th fa-users %}</div></div>

<!-- more -->

## 目录汇总

这里列出所有目录的链接

{% note warning %}
如无特殊说明, 除随笔外, 其余所有在目录列表中出现的文章的参考资料均在目录页
{% endnote %}

- [高等代数](/article/contents/advanced-algebra/)
- [随笔](/article/contents/draft/)
- [集合论](/article/contents/set-theory/)
- [生成函数](/article/contents/gfology/)
- [微分几何](/article/contents/diff-geo/)

## 代码起手式

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;
using db = double;
using ldb = long double;
using pii = pair<int, int>;

#define _for(i, l, r, vals...) for (decltype(l + r) i = (l), i##end = (r), ##vals; i <= i##end; ++i)
#define _rfor(i, r, l, vals...) for (make_signed_t<decltype(r - l)> i = (r), i##end = (l), ##vals; i >= i##end; --i)
#define _foreach_val(i, container) for (auto i : container)
#define _foreach_ref(i, container) for (auto& i : container)
#define _foreach_cref(i, container) for (const auto& i : container)
#define _for_graph(head, e, i, now) for (int i = head[now], to = e[i].to; i; to = e[i = e[i].next].to)
#define _ins(a) std::inserter((a), (a).begin())
#define _all(a) (a).begin(), (a).end()
#define _set_nul(a) memset(a, 0, sizeof(a))
#define _set_inf(a) memset(a, 0x3f, sizeof(a))
#define _set_nul_n(a, n) memset(a, 0, sizeof(a[0]) * (n))
#define _set_inf_n(a, n) memset(a, 0x3f, sizeof(a[0]) * (n))
#define _fin goto FINISHED
#define _divb(l, r, n, expressions)                   \
    for (decltype(n) l = 2, r; l <= (n); l = r + 1) { \
        r = (n) / ((n) / l);                          \
        expressions;                                  \
    }
#define _run_exit(expressions) _run_return(expressions, 0)
#define _run_return(expressions, val) return (expressions), val
#define _run_return_void(expressions) \
    {                                 \
        expressions;                  \
        return;                       \
    }
#define _run_fin(expressions) \
    {                         \
        expressions;          \
        _fin;                 \
    }
#define _run_break(expressions) \
    {                           \
        expressions;            \
        break;                  \
    }
#define _run_continue(expressions) \
    {                              \
        expressions;               \
        continue;                  \
    }
#define _mid(l, r) ((l) + (((r) - (l)) >> 1))
#define _len(l, r) ((r) - (l) + 1)
#define _lowbit(x) (1 << __builtin_ctz(x))
#define _lowbit_64(x) (1 << __builtin_ctzll(x))
#define _debug                                              \
    {                                                       \
        fprintf(stderr, "%d %s\n", __LINE__, __FUNCTION__); \
        fflush(stderr);                                     \
    }

template <class T>
bool chkmin(T& a, T b) { return b < a ? a = b, true : false; }
template <class T>
bool chkmax(T& a, T b) { return a < b ? a = b, true : false; }

const int OFFSET = 5;
const int N = 5e5 + OFFSET, M = 2e5 + OFFSET, K = 21;
const int MOD = 1e9 + 7;
const db EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const i64 INFLL = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1.0);
const pii DIR4[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
const pii DIR8[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

#define MULTI_CASES

auto __STATIC__ = []() { return 0.0; }();

void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
    clock_t _CLOCK_ST = clock();
#endif
    //======================================
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef MULTI_CASES
    int _t;
    cin >> _t;
    while (_t--)
#endif
        solve();
    //======================================
FINISHED:
#ifndef ONLINE_JUDGE
    std::cerr << "\n---\n"
              << "Time used: " << clock() - _CLOCK_ST << std::endl;
#endif
    return 0;
}
```

</details>

## 本博客采用的部分非通用记号/名称等

| 记号                      | 含义                                   | 例子                                                                                       |
| ------------------------- | -------------------------------------- | ------------------------------------------------------------------------------------------ |
| $\exist_1$                | 存在唯一                               | [集合论01 定义 - 1-4](/article/set-theory/0001/#def-1-4) 中的性质 8                        |
| $[a,b]_A$                 | $\{x\in A:a\leqslant x\leqslant b\}$   | [题解 - Japanese Student Championship 2021 - D](/article/jsc2021/#题意简述-3)              |
| $a..b$                    | $[a,b]_\N$                             | [随笔 - Laplace算子的旋转不变性](/article/draft/0019/)                                     |
| $\operatorname{Base}_a^b$ | $(10^b)_a$                             |
| $\operatorname{And}$      | 按位与                                 | [题解 - [Luogu P2915] [USACO08NOV]奶牛混合起来Mixed Up Cows](/article/luogu-p2915/)        |
| $\operatorname{Or}$       | 按位或                                 |
| $\operatorname{Not}$      | 按位取反                               |
| 算术-几何级数             | Arithmetico-geometric Progression, AGP | [随笔 - Arithmetico-geometric Progression (AGP)](/article/draft/0014/)                     |
| $\text{Prime}^+$          | $\{p\in\N/\{1\}:\varphi(p)=p-1\}$      | [笔记 - Powerful number 与 Powerful number 筛 - 定理 - 1-1](/article/powerful-num/#th-1-1) |
| $\text{Prime}^-$          | $-1\cdot\text{Prime}^+$                |                                                                                            |
| $\text{Prime}$            | $\text{Prime}^+\cup\text{Prime}^-$     |                                                                                            |

## FAQ

1. 源代码缺失头文件等内容

   早期文章中可能出现该问题, 缺失的头文件等内容默认为上面的代码起手式
1. 文章缺失内容, 未填坑等

   可能是笔者忘了, 希望读者能在评论区提醒一下, 或在本博客对应的 GitHub repo 发 issue
