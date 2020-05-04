---
title: "题解 - [Luogu P5285] [十二省联考2019]骗分过样例"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 算法
  - 洛谷
  - 省选
  - 多省联考
  - 数学
  - 数论
  - 素数/质数
  - Miller-Rabin算法
  - 快速幂
  - 打表
  - 筛法
  - Euler筛
  - Möbius函数
  - 原根
date: 2021-11-18 17:48:03
---

[题目链接](https://www.luogu.com.cn/problem/P5285)

<!-- more -->

## 原始题面

### 题目背景

这是一道**传统题**

"我的程序需要完成什么功能呀? ......"

"我也不知道......"

"啊? 那我怎么写呀......"

"已经有人给你写好测试了, 只要你通过这些测试就可以了......"

"啊? ......"

"所有的测试数据都在题目目录下, 请做好备份, 避免误删!"

"这......"

"哦, 我还可以把输入格式告诉你......不过都有完整的数据了, 知道输入格式可能也没太大用处吧......"

### 题目描述

题目数据详见附加文件

### 输入输出格式

#### 输入格式

第一行输入一个字符串, 表示需要运行的软件功能编号. 两个编号越相似, 说明对 应的两个功能的算法越接近

接下来根据功能的不同, 可能有任意长度的输入, 详见每个功能的文档

#### 输出格式

详见每个功能的文档

### 输入输出样例

无

### 说明

#### 子任务

" '每个功能的文档' 在哪里呀?"

"我也没有, 就像我没有题目描述一样......"

"好吧......那我是不是打表就可以了呀......"

"**代码长度限制是 $\bold{102400}$ 字节** ($100$KB), 直接打肯定是不行的! 不过, 需要的话倒是可以稍微打一些小的表......"

"唔......"

"另外, 我们会给你的程序对于每个测试点分别评分, 求和后得到总分. 按照传统 的规矩, 每个测试点正确得满分, 错误得 $0$ 分. **每个测试点的分值不全相同, 测试点的分值, 顺序与难度没有必然联系** ."

| 测试点 |         功能编号          | 分值 |
| :----: | :-----------------------: | :--: |
|  $1$   |  $\texttt{1\_998244353}$  | $4$  |
|  $2$   |  $\texttt{1\_998244353}$  | $4$  |
|  $3$   |  $\texttt{1\_998244353}$  | $4$  |
|  $4$   |       $\texttt{1?}$       | $7$  |
|  $5$   |      $\texttt{1?+}$       | $9$  |
|  $6$   | $\texttt{1wa\_998244353}$ | $6$  |
|  $7$   | $\texttt{1wa\_998244353}$ | $7$  |
|  $8$   |       $\texttt{2p}$       | $4$  |
|  $9$   |       $\texttt{2p}$       | $6$  |
|  $10$  |       $\texttt{2p}$       | $8$  |
|  $11$  |       $\texttt{2u}$       | $5$  |
|  $12$  |       $\texttt{2u}$       | $6$  |
|  $13$  |       $\texttt{2u}$       | $9$  |
|  $14$  |       $\texttt{2g}$       | $5$  |
|  $15$  |       $\texttt{2g}$       | $7$  |
|  $16$  |      $\texttt{2g?}$       | $9$  |

#### 提示

在你使用 C/C++ 的 `int` 类型时, 如果发生了溢出, 比较可能的情况是按照模 $2^{32}$ 同余的前提下, 在 `int` 范围内取一个合理的值. 例如在计算 $2147483647 + 2$ 时, 较有可能会得到 -$2147483647$

然而, C/C++ 标准将这种情况归类为"未定义行为". 当你的程序试图计算会溢 出的 `int` 运算时, 除了上述结果外, 编译器还可能会让你的程序在此时计算出错误结果, 死循环, 运行错误等, 这也是符合 C/C++ 标准的

如果你的程序希望利用 `int` 的自然溢出的特性, 请转换为 `unsigned` 类型运算. 例如将 `a + b` 改写为 `(int) ((unsigned) a + (unsigned) b)`, 以避免出现不预期的错误

### 附件

[data.7z](data.7z) 4.16MB

## 解题思路

| 编号                      | 功能                                                         |
| ------------------------- | ------------------------------------------------------------ |
| $\texttt{1\_998244353}$   | 求 $19^n\bmod p$, $p=998244353$                              |
| $\texttt{1?}$             | 求 $19^n\bmod p$, $p=1145141$                                |
| $\texttt{1?+}$            | 求 $19^n\bmod p$, $p=5211600617818708273$                    |
| $\texttt{1wa\_998244353}$ | 求 $19^n\bmod p$, $p=998244353$, 但是要写成 `int` 溢出的代码 |
| $\texttt{2p}$             | 对给定的区间求区间中所有的素数                               |
| $\texttt{2u}$             | 对给定的区间求区间中所有的 Möbius 函数值                     |
| $\texttt{2g}$             | 对给定的区间和模数求区间中所有的原根                         |
| $\texttt{2g?}$            | 对给定的区间和模数求区间中所有的原根, `?` 代表 $1515343657$  |

全是板子题, 就不细讲了

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-18 17:48:03
 * @Description: Luogu P5285
 */
#include <bits/stdc++.h>
using namespace std;

namespace Util {
inline constexpr int64_t mul_mod(int64_t a, int64_t b, const int64_t& mod) {
    int64_t d = floor(1.0l * a * b / mod + 0.5l), ret = a * b - d * mod;
    return ret < 0 ? ret + mod : ret;
}
inline constexpr int64_t pow_mod(int64_t a, int64_t b, const int64_t& mod) {
    int64_t res(1);
    a %= mod;
    for (; b; b >>= 1, a = mul_mod(a, a, mod))
        if (b & 1) res = mul_mod(res, a, mod);
    return res;
}
inline constexpr int64_t qpow(int64_t a, int64_t b, const int64_t& mod) {
    int64_t res(1);
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (res *= a) %= mod;
    return res;
}

inline int64_t string2int(const string& s, const int64_t& mod) {
    if (s.size() < 18) return stoll(s) % mod;
    int64_t ans = 0;
    for (auto it = s.begin(); it != s.end(); ++it) ((ans *= 10) += (*it) - '0') %= mod;
    return ans;
}

namespace Primetest_miller_rabin {
constexpr uint64_t bases[] = {2, 3};

inline constexpr bool is_prime(uint64_t n) {
    if (n <= 1) return false;
    for (uint64_t a : bases)
        if (n == a) return true;
    if (n % 2 == 0) return false;

    uint64_t d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (uint64_t a : bases) {
        uint64_t t = d, y = pow_mod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = mul_mod(y, y, n);
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) return false;
    }
    return true;
}
} // namespace Primetest_miller_rabin
using Primetest_miller_rabin::is_prime;

// primitive root
const int64_t pr_998244353 = 3,
              pr_13123111 = 6,
              pr_1515343657 = 5;

// prime factors
const int64_t pf_998244352[] = {2, 7, 17},
              pf_13123110[] = {2, 3, 5, 7, 11, 13, 19, 23},
              pf_1515343656[] = {2, 3, 4003, 15773};
} // namespace Util

namespace _1_9 {
using namespace ::Util;

const int64_t p = 998244353;
const int64_t phi_p = p - 1;

void main() {
    int n;
    cin >> n;
    string _;
    for (int i = 0; i < n; ++i) {
        cin >> _;
        cout << pow_mod(19, string2int(_, phi_p), p) << '\n';
    }
}
} // namespace _1_9

namespace _1_q {
using namespace ::Util;

const int64_t p = 1145141;
const int64_t phi_p = p - 1;

void main() {
    int n;
    cin >> n;
    string _;
    for (int i = 0; i < n; ++i) {
        cin >> _;
        cout << pow_mod(19, string2int(_, phi_p), p) << '\n';
    }
}
} // namespace _1_q

namespace _1_qp {
using namespace ::Util;

const int64_t p = 5211600617818708273ll;
const int64_t phi_p = p - 1;

void main() {
    int n;
    cin >> n;
    int64_t _;
    for (int i = 0; i < n; ++i) {
        cin >> _;
        cout << pow_mod(19, _ % phi_p, p) << '\n';
    }
}
} // namespace _1_qp

namespace _1_w9 {
using namespace ::Util;

const int p = 998244353;
const int x = 55244, y = 45699;
int res[x + y + 1] = {1};

void main() {
    for (int i = 1; i <= x + y; ++i) res[i] = (int)((unsigned)(res[i - 1]) * 19) % p;
    int n;
    cin >> n;
    int64_t _;
    for (int i = 0; i < n; ++i) {
        cin >> _;
        cout << res[_ <= x ? _ : (_ - x) % y + x] << '\n';
    }
}
} // namespace _1_w9

namespace _2_p {
using namespace ::Util;

const int N = 1e6 + 1, P = 78498 + 1;

bool vis[N];
int64_t prime[P], cnt_prime;
inline void init_prime(const int& n = N - 1) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[++cnt_prime] = i;
        for (int j = 1; j <= cnt_prime && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

bool vis2[N];
void main() {
    init_prime();

    int n;
    cin >> n;
    int64_t l, r;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        if (r < N) {
            for (int i = l; i <= r; ++i) cout << "p."[vis[i]];
        } else {
            for (int i = 1; i <= cnt_prime; ++i)
                for (int64_t j = (int64_t)ceil(1.0l * l / prime[i]) * prime[i]; j <= r; j += prime[i])
                    vis2[j - l] = 1;
            if (r <= (int64_t)(N - 1) * (N - 1))
                for (int i = 0; i <= r - l; ++i) cout << "p."[vis2[i]];
            else
                for (int i = 0; i <= r - l; ++i) cout << "p."[vis2[i] || !is_prime(i + l)];
        }
        cout << '\n';
    }
}
} // namespace _2_p

namespace _2_u {
using namespace ::Util;

const int N = 1e6 + 1, P = 78498 + 1;

bool vis[N];
int64_t prime[P], cnt_prime;
int mu[N];
inline void init_prime(const int& n = N - 1) {
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) mu[prime[++cnt_prime] = i] = -1;
        for (int j = 1; j <= cnt_prime && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
}

int mu2[N];
int64_t _x[N];
void main() {
    init_prime();

    int n;
    cin >> n;
    int64_t l, r;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        if (r < N) {
            for (int i = l; i <= r; ++i) cout << "-0+"[mu[i] + 1];
        } else {
            for (int i = 0; i <= r - l; ++i) {
                mu2[i] = 1;
                _x[i] = i + l;
            }
            for (int i = 1; i <= cnt_prime; ++i)
                for (int64_t j = (int64_t)ceil(1.0l * l / prime[i]) * prime[i]; j <= r; j += prime[i]) {
                    if (j % (prime[i] * prime[i])) {
                        mu2[j - l] *= -1;
                        _x[j - l] /= prime[i];
                    } else
                        mu2[j - l] = 0;
                }
            if (r <= (int64_t)(N - 1) * (N - 1)) {
                for (int i = 0; i <= r - l; ++i)
                    if (_x[i] != 1) mu2[i] *= -1;
            } else {
                int64_t __ = 0;
                for (int i = 0; i <= r - l; ++i)
                    if (mu2[i] && _x[i] != 1) {
                        __ = sqrtl(_x[i]);
                        if (__ * __ == _x[i])
                            mu2[i] = 0;
                        else if (is_prime(_x[i]))
                            mu2[i] *= -1;
                    }
            }
            for (int i = 0; i <= r - l; ++i) cout << "-0+"[mu2[i] + 1];
        }
        cout << '\n';
    }
}
} // namespace _2_u

namespace _2_g {
using namespace ::Util;

const int p1 = 998244353, p2 = 13123111;

int ord2[p2];
bool not_coprime[p2];
void init() {
    for (int i = 1, p = pr_13123111; i < p2; ++i) {
        ord2[p] = i;
        (p *= pr_13123111) %= p2;
    }
    for (int i : pf_13123110)
        for (int j = i; j < p2; j += i) not_coprime[j] = 1;
}

void main() {
    init();

    int n;
    cin >> n;
    int64_t l, r, p;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r >> p;
        if (p == p2)
            for (auto i = l; i <= r; ++i) cout << "g."[not_coprime[ord2[i]]];
        else
            for (auto i = l; i <= r; ++i) {
                bool f = 0;
                for (auto j : pf_998244352)
                    if (qpow(i, (p1 - 1) / j, p1) == 1) {
                        f = 1;
                        break;
                    }
                cout << "g."[f];
            }
        cout << '\n';
    }
}
} // namespace _2_g

namespace _2_gq {
using namespace ::Util;

const int64_t p1 = 998244353, p2 = 1515343657;

void main() {
    int n;
    cin >> n;
    int64_t l, r;
    string _;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r >> _;
        if (_.front() == '?') {
            for (auto i = l; i <= r; ++i) {
                bool f = 0;
                for (auto j : pf_1515343656)
                    if (qpow(i, (p2 - 1) / j, p2) == 1) {
                        f = 1;
                        break;
                    }
                cout << "g."[f];
            }
        } else {
            for (auto i = l; i <= r; ++i) {
                bool f = 0;
                for (auto j : pf_998244352)
                    if (qpow(i, (p1 - 1) / j, p1) == 1) {
                        f = 1;
                        break;
                    }
                cout << "g."[f];
            }
        }
        cout << '\n';
    }
}
} // namespace _2_gq

const unordered_map<string, function<void(void)>> _main = {
    {"1_998244353", _1_9::main},
    {"1?", _1_q::main},
    {"1?+", _1_qp::main},
    {"1wa_998244353", _1_w9::main},
    {"2p", _2_p::main},
    {"2u", _2_u::main},
    {"2g", _2_g::main},
    {"2g?", _2_gq::main},
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string _;
    getline(cin, _);
    _main.at(_)();
    return 0;
}
```

</details>
