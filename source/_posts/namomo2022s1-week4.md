---
title: Namomo Spring Camp 2022 Div1 每日一题记录 (Week 4)
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 代码源
  - CodeForces
  - JZOJ
  - ICPC
  - UVa
  - BZOJ
  - 暴力
  - 数学
  - 分治
  - 数据结构
  - 组合数学
  - 贪心
  - 数据结构
  - 差分
  - 树状数组
  - 生成函数
  - 前缀和
  - 单调栈
  - Fibonacci数列
date: 2022-03-19 16:00:56
---

Namomo Spring Camp 2022 Div1 每日一题记录 (2022.03.19-2022.03.25)

<!-- more -->

## 401 - 蜗蜗的数列 (CF1634F)

[题目链接](https://oj.daimayuan.top/course/10/problem/562)

2s, 512MB

### 题目背景

原题: CF1634F

进行了几个没有任何意义的加强

### 题目描述

蜗蜗有两个长度都为 $n$​ 的数列 $A,B$​​​, 同时他会进行 $q$​ 次操作

对于每一次操作, 他会先选择其中一个数列 $(A/B)$, 再选择一个区间 $[l,r](1\le l\le r\le n)$, 将选定的序列 $[l,r]$ 中的数对位加上Fibonacci数列

换句话说, 就是将选定数列的第 $l$ 项加上 $1$, 第 $l+1$ 项加上 $1$, 第 $l+2$ 项加上 $2$, 第 $l+3$ 项加上 $3\dots$ 第 $r$ 项加上 $Fib(r-l+1)$​​, 即 Fibonacci 数列的第 $r-l+1$ 项

在每次操作结束的时候, 蜗蜗都会变得非常好奇. 他想知道此时 $A$​ 和 $B$​ 两个序列是否相同, 由于他一看到比较长的数就会头晕, 所以你只需要判断 $A$​ 和 $B$​ 在模 $M$​ 的意义下是否相同即可

### 输入格式

第一行三个数 $n,q,M$, 分别表示数列的长度, 操作的总次数和模数

第二行和第三行各输入 $n$​ 个整数, 表示 $A$ 和 $B$ 的初始值

接下来 $q$ 行每行包含一个字符 $c$ 和两个整数 $l,r$​, 描述一次操作. 具体细节见样例

### 输出格式

输出 $q$​ 行, 每行一个字符串 Yes 或 No, 表示此时两个数列是否在模 $M$ 的意义下相同

### 样例1输入

```input1
3 5 3
2 2 1
0 0 0
A 1 3
A 1 3
B 1 1
B 2 2
A 3 3
```

### 样例1输出

```output1
Yes
No
No
No
Yes
```

### 样例2输入

```input2
5 3 10
2 5 0 3 5
3 5 8 2 5
B 2 3
B 3 4
A 1 2
```

### 样例2输出

```output2
No
No
Yes
```

### 数据规模

对于 $100\%$​ 的数据, $1\le n\le 10^6,1\le q\le 10^6,1\le M\le 10^9+7$​. 且对于 $1\le i\le n,0\le|A_i|,|B_i|\le 10^9$​​

### 解题思路

> 差分数组

这题做法很妙

首先, 我们考虑两数列是否相同, 相当于考虑两数列的差是否为 $0$

又因为题目只有区间修改和全局查询, 所以我们可以用差分数组来将区间修改转为单点修改, 然后再用个计数器统计下全局非 $0$ 的数的个数即可

妙处在于差分数组

一般的差分数组能发挥作用的时候, 区间修改都是区间加上同一个数, 也就是增量 $D_n$ 满足 $D_n=D_{n-1}$, 但本题区间修改的增量 $F_n$ 满足 $F_n=F_{n-1}+F_{n-2}$, 所以我们差分数组也应该取成这个形式, 即

令 $d_i=A_i-B_i$,

$$\Delta_n=\begin{cases}
  d_1,&n=1\\
  d_2-d_1,&n=2\\
  d_n-d_{n-1}-d_{n-2},&n>2
\end{cases}$$

此时对区间 $[l,r]$ 加 Fibonacci 数列的操作便转为:

- $\Delta_l\leftarrow\Delta_l+1$
- $\Delta_{r+1}\leftarrow\Delta_{r+1}-F_{r-l+2}$
- $\Delta_{r+2}\leftarrow\Delta_{r+2}-F_{r-l+1}$

### 复杂度

$O(n+q)$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const uint32_t N = 1e6 + 5;

int a[N];
int diff[N], fibo[N];
int cnt_positive;

auto modify = [](uint32_t pos, uint32_t val, int mod) -> void {
    cnt_positive -= !!diff[pos];
    if ((diff[pos] += val) >= mod) diff[pos] -= mod;
    cnt_positive += !!diff[pos];
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n, q, mod;
    cin >> n >> q >> mod;
    _for(i, 1, n) cin >> a[i];
    _for(i, 1, n, x) {
        cin >> x;
        if ((a[i] -= x) < 0) a[i] += mod;
        if (a[i] < 0) a[i] += mod;
    }
    diff[1] = a[1];
    _for(i, 2, n + 2) diff[i] = (a[i] - a[i - 1] + mod * 2 - a[i - 2]) % mod;
    _for(i, 1, n + 2) cnt_positive += !!diff[i];
    fibo[1] = 1;
    _for(i, 2, n + 2) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % mod;
    char op;
    _for(i, 1, q, l, r) {
        cin >> op >> l >> r;
        if (op == 'A') {
            modify(l, 1, mod);
            modify(r + 1, mod - fibo[r - l + 2], mod);
            modify(r + 2, mod - fibo[r - l + 1], mod);
        } else {
            modify(l, mod - 1, mod);
            modify(r + 1, fibo[r - l + 2], mod);
            modify(r + 2, fibo[r - l + 1], mod);
        }
        cout << (cnt_positive ? "No\n" : "Yes\n");
    }
    return 0;
}
```

</details>

## 402 - 最大公约数 (JZOJ4922)

[题目链接](https://oj.daimayuan.top/course/10/problem/131)

1s, 1024MB

### 题目描述

你有一个环, 环上有$n$个正整数. 你能将环切成$k$段, 每段包含一个或者多个数字

对于一个切分方案, 优美程度为每段数字和的最大公约数, 你想使切分方案的优美程度最大, 对于$k=1,2,\dots, n$输出答案

### 输入格式

第一行一个整数$n$, 表示环上的数字个数

接下来一行包含$n$个正整数, 第$i$个数$a_i$表示环上第$i$个数

### 输出格式

输出$n$行, 第$i$行表示切成$i$段时的最大优美程度

### 样例输入1

```input1
7
2 3 3 3 3 3 3
```

### 样例输出1

```output1
20
5
2
2
1
1
1
```

### 样例输入输出2

见 [下发文件](problem_131.zip)

### 数据规模

共10个测试点

测试点$1, 2$满足$n\leq 20$

测试点$3, 4, 5$满足$a_i\leq 5$

对于所有数据, 满足$1\leq n\leq 2000, 1\leq a_i\leq 5\times 10^7$

### 解题思路

令 $S=\sum_i a_i$, 则显然无论如何划分, 结果一定是 $S$ 的因子, 而 $S$ 的因子个数不超过 $2\sqrt S$, 对于本题来说可以直接枚举

对于当前枚举的因子 $d$, 不难发现其最多能划分的段数即为 $a_i$ 前缀和在模 $d$ 意义下最多相等的个数, 所以开个 `std::unordered_map` 计数然后取最大值即可

### 复杂度

$O(n\sqrt{\sum_i a_i})$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const uint32_t N = 2e3 + 5, M = 2e4 + 5;

int a[N];
i64 factor[M];
int cnt_factor;
i64 ans[N];

int main() {
    int n;
    cin >> n;
    _for(i, 1, n) cin >> a[i];
    i64 sum_a = 0;
    _for(i, 1, n) sum_a += a[i];
    _for(i, 1, (int)sqrt(sum_a)) if (sum_a % i == 0) {
        factor[++cnt_factor] = i;
        if (sum_a / i != i) factor[++cnt_factor] = sum_a / i;
    }

    _for(i, 1, cnt_factor) {
        i64 now_factor = factor[i];
        i64 sum = 0;
        unordered_map<i64, int> cnt_slice;
        int max_slice = 0;
        _for(i, 1, n) chkmax(max_slice, ++cnt_slice[sum = (sum + a[i]) % now_factor]);
        chkmax(ans[max_slice], now_factor);
    }
    _rfor(i, n - 1, 1) chkmax(ans[i], ans[i + 1]);
    _for(i, 1, n) cout << ans[i] << '\n';

    return 0;
}
```

</details>

## 403 - 平方计数

[题目链接](https://oj.daimayuan.top/course/10/problem/607)

1s, 1024MB

### 题目描述

给$N$个正整数, 第$i$个数用$a_i$来表示, 求出有多少对$(i, j)$ 使得$a_i^2 + a_j$是一个完全平方数

### 输入格式

第一行一个正整数$n$ 第二行$n$个数, 表示$a_1, a_2, a_3 ... a_n$

### 输出格式

一行一个整数, 表示答案

### 数据范围

对于所有测试数据 满足$1 \leq n \leq 10^6$, 且$1 \leq a_i \leq 10^6$

### 样例输入

```input1
5
1 2 3 4 5
```

### 样例输出

```output1
2
```

### 解题思路一

> 想半天 $O(n\log n)$ 结果直接暴力就能过, 蚌埠住了

注意到 $a_i$ 不大, 故暴力枚举完全平方数即可

常数很小, 可以过

### 复杂度一

$O(n\max_{i\ne j}\{\sqrt{a_i^2+a_j}-a_i\})=O(n\max_i\sqrt{a_i})$

### 代码参考一

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const uint32_t N = 1e6 + 5;

int a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    _for(i, 1, n) cin >> a[i];
    _for(i, 1, n)++ cnt[a[i]];
    int max_a = 0;
    _for(i, 1, n) chkmax(max_a, a[i]);
    i64 ans = 0;
    _for(i, 1, n) for (int j = 1; (2 * a[i] + j) * j <= max_a; ++j) ans += cnt[(2 * a[i] + j) * j];
    cout << ans;

    return 0;
}
```

</details>

### 解题思路二

不难发现
$$a_i^2+a_j=x^2\iff a_j=(x+a_i)(x-a_i)$$

所以枚举 $x\in 1..\max_i a_i$ 和其倍数 $y$, 若 $2\mid (y/x-x)$, 且

- $\displaystyle a_i={ {y\over x}-x\over 2}$
- $a_j=y$

则找到了一组解

### 复杂度二

$\displaystyle O\left(\sum_{i=1}^{\max_i a_i}\left\lfloor {\max_i a_i\over i}\right\rfloor\right)=O\left(\max_i\{a_i\log a_i\}\right)$

### 代码参考二

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const uint32_t N = 1e6 + 5;

int a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    _for(i, 1, n) cin >> a[i];
    _for(i, 1, n)++ cnt[a[i]];
    int max_a = 0;
    _for(i, 1, n) chkmax(max_a, a[i]);
    i64 ans = 0;
    _rfor(i, max_a, 1) for (int j = i, d; j <= max_a; j += i) {
        if((d = abs(j / i - i)) & 1) continue;
        ans += 1ll * cnt[j] * cnt[d / 2];
    }
    cout << ans;

    return 0;
}
```

</details>

## 404 - 字典序最小 (ICPC North Central NA 2019 E)

[题目链接](https://oj.daimayuan.top/course/10/problem/608)

1s, 1024MB

从序列 $M$ 个数中顺序选出 $N$ 个不同的数, 使得这 $N$ 个数的字典序最小

### 输入格式

第一行两个整数 $M$, $N$ 分别表示序列长度, 顺序选取数据的个数 (其中$1 < N \leq M \leq 10^6$)

接下来 $M$ 行, 第 $i$ 行输入为第 $a_i$, 表示序列 $M$ 中第 $i$ 个数, 其中 $1 \leq a_i \leq N$, 数据保证 $[1, N]$ 范围内每个数至少出现一次

### 输出格式

输出 $N$ 个数, 用空格隔开, 表示最小字典序 （最后一个输出不能有多余空格)

### 样例输入

```input1
6 3
3
2
1
3
1
3
```

### 样例输出

```output1
2 1 3
```

### 题目说明

求解的最小字典序不必在序列 $M$ 中连续

### 解题思路

题解以前写过, 参见 [此处](/article/icpc-ncna2019/#%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF-5)

## 405 - 拆拆

[题目链接](https://oj.daimayuan.top/course/10/problem/611)

1s, 1024MB

多组数据

每组给定两个数 $X, Y$, 问有多少个长度为 $Y$ 的整数序列之乘积为 $X$, 即

$$\prod_{i = 1}^Y f_i = X$$

注意: 两序列不同, 当且仅当至少有一个下标相同的位置不同. 如 $(1, 2), (2, 1)$ 被视作不同的序列

答案可能很大, 将其模以 $10^9 + 7$ 输出

例如: 给定 $(X, Y) = (6, 2)$. 可以将 $6$ 分成 $(\pm1, \pm6), (\pm2, \pm3), (\pm3, \pm2), (\pm6, \pm1)$ 八种长度为 $2$ 的序列, 因此答案是 $8$

### 输入格式

第一行一个整数 $T$, 表示接下来有 $T$ 组数据

每组数据包含两个数字 $X, Y$

### 输出格式

对于每组数据, 输出一行, 表示答案

### 样例输入

```input1
4
6 2
6 3
6 4
1 4
```

### 样例输出

```output1
8
36
128
8
```

解释: 对于数据四, 相当于将偶数个负号分配给 $1$, 因此答案为 $\displaystyle\binom{4}{0} + \displaystyle\binom{4}{2} + \displaystyle\binom{4}{4} = 8$

### 数据规模

- $1 \le T \le 10^5$
- $1 \le X, Y \le 10^6$

### 解题思路

首先, 考虑符号的话显然就是在答案最后乘个 $2^{Y-1}$ 即可

其次, 我们考虑 $X=p^\alpha$ 的情况, 其中 $p$ 为质数

设 $f(\alpha,Y)$ 为不考虑符号时的答案, 显然有

- $f(1,x)=f(x,1)=1$
- $f(x,y)=f(x-1,y)+f(x,y-1)$

由简单的生成函数知识不难得出
$$f(\alpha,Y)={\alpha+Y-1\choose\alpha}$$

<details>
<summary><font color='orange'>推导过程</font></summary>

> 考虑二元OGF
> $$F(x,y)=\sum_{m=1}^\infty\sum_{n=1}^\infty f(m,n)x^my^n$$
>
> 整理一下
> $$\begin{aligned}
    F(x,y)&=x\sum_{n=1}^\infty y^n+y\sum_{m=1}^\infty x^m-xy+\sum_{m=2}^\infty\sum_{n=2}^\infty f(m,n)x^my^n\\
    &=x\sum_{n=1}^\infty y^n+y\sum_{m=1}^\infty x^m-xy+\sum_{m=2}^\infty\sum_{n=2}^\infty(f(m-1,n)+f(m,n-1))x^my^n\\
    &=x\sum_{n=1}^\infty y^n+y\sum_{m=1}^\infty x^m-xy+x\left(F(x,y)-\sum_{m=1}^\infty x^my\right)+y\left(F(x,y)-\sum_{n=1}^\infty xy^n\right)\\
    &=(x+y)F(x,y)+xy\left({1\over 1-y}+{1\over 1-x}-1-{y\over 1-y}-{x\over 1-x}\right)
  \end{aligned}$$
>
> 即
>
> $$F(x,y)={xy\over 1-x-y}$$
>
> 从而
>
> $$f(m,n)=[x^my^n]F(x,y)={m+n-1\choose m}$$

</details>

最后对于一般情况, 设 $X$ 的唯一分解式为
$$X=\prod_{i=1}^{\omega(X)}p_i^{\alpha_i}$$

显然答案为

$$2^{Y-1}\prod_{i=1}^{\omega(X)}{\alpha_i+Y-1\choose\alpha_i}$$

### 复杂度

$O(X+T\max\omega(X))$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const int N = 1e6 + 5;
const uint32_t MOD = 1e9 + 7;

inline constexpr i64 qpow(i64 a, i64 b = MOD - 2, const i64& mod = MOD) {
    i64 res(1);
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (res *= a) %= mod;
    return res;
};

i64 fact[N * 2], inv_fact[N];
auto __STATIC__ = []() {
    static i64 ffact[N];
    ffact[0] = fact[0] = inv_fact[0] = fact[1] = inv_fact[1] = 1;
    _for(i, 2, N * 2 - 1) fact[i] = fact[i - 1] * i % MOD;
    _for(i, 1, N - 1) ffact[i] = ffact[i - 1] * fact[i] % MOD;
    i64 _ = qpow(ffact[N - 1]);
    _rfor(i, N - 1, 2) {
        inv_fact[i] = _ * ffact[i - 1] % MOD;
        _ = _ * fact[i] % MOD;
    }
    return 0.0;
}();
auto m_choose_n = [](int m, int n, i64 mod = MOD) -> i64 { return m < n ? 0 : fact[m] * inv_fact[n] % mod * inv_fact[m - n] % mod; };

auto f = [](int x, int y) -> i64 {
    i64 ans = 1;
    _for(i, 2, (int)sqrt(x), cnt) {
        if (i > x) break;
        if (x % i) continue;
        cnt = 0;
        while (x % i == 0) {
            ++cnt;
            x /= i;
        }
        ans = (ans * m_choose_n(cnt + y - 1, cnt)) % MOD;
    }
    if (x != 1) ans = (ans * y) % MOD;
    return ans;
};

int main() {
    int _t;
    cin >> _t;
    while (_t--){
        int x, y;
        cin >> x >> y;
        cout << f(x, y) * qpow(2, y - 1) % MOD << '\n';
    }
    return 0;
}
```

</details>

## 406 - "Z"型矩阵 (CF628E)

[题目链接](https://oj.daimayuan.top/course/10/problem/614)

5s, 1024MB

对于一个只包含 `.` 和 `z` 的矩阵, 当以下条件满足时:

1. 该矩阵的行数列数相等
1. 该矩阵的第一行与最后一行的字符全是 z
1. 该矩阵从右上角到左下角的对角线上的字符全是 z

我们称其为 Z 矩阵

现在给定一个 $n \times m$ 的矩阵, 请你计算它有多少个子矩阵是 Z 矩阵

### 输入格式

第一行两个整数 $n$ , $m$ 分别表示矩阵的行数和列数 $(1 \leq n , m \leq 3 \times 10^3 )$

接下来 $n$ 行, 每行包含 $m$ 个字符, 表示该矩阵

### 输出格式

输出一行一个整数表示 Z 矩阵的数量

### 样例输入

```input1
4 4
zzzz
z.z
.zz
zzzz
```

### 样例输出

```output1
14
```

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
const int N = 3e3 + 5;

int tr[N * N];
int cnt_a;
void add(int x, int v) { for (; x <= cnt_a; x += x & -x) tr[x] += v; }
int query(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += tr[x];
    return res;
}

struct node {
    int id, num;
    bool operator<(const node& rhs) const { return num < rhs.num; }
} a[N * N];

struct note {
    int pre, suf, id, val;
    bool operator<(const note& rhs) const { return val < rhs.val; }
} b[N * N];

int pre[N][N], suf[N][N], diag[N][N], id[N][N];
bool maps[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    _for(i, 1, n) _for(j, 1, m) {
        char ch;
        cin >> ch;
        maps[i][j] = ch == 'z';
    }
    _for(i, 1, n) _for(j, 1, m) if (maps[i][j]) pre[i][j] = pre[i][j - 1] + 1;
    _for(i, 1, n) _rfor(j, m, 1) if (maps[i][j]) suf[i][j] = suf[i][j + 1] + 1;
    _rfor(i, n, 1) _for(j, 1, m) if (maps[i][j]) diag[i][j] = diag[i + 1][j - 1] + 1;

    _for(k, 1, m) for (int i = 1, j = k; j >= 1 && i <= n; ++i, --j) a[id[i][j] = ++cnt_a] = {cnt_a, i - suf[i][j] + 1};
    _for(k, 2, n) for (int i = k, j = m; j >= 1 && i <= n; ++i, --j) a[id[i][j] = ++cnt_a] = {cnt_a, i - suf[i][j] + 1};
    sort(a + 1, a + 1 + cnt_a);

    int cnt_b = 0;
    _for(i, 1, n, len) _for(j, 1, m) {
        if (!(len = min(pre[i][j], diag[i][j]))) continue;
        b[++cnt_b] = {id[i][j], id[i + len - 1][j - len + 1], cnt_b, i + 1};
    }
    sort(b + 1, b + 1 + cnt_b);

    i64 ans = 0;
    _for(i, 1, cnt_b, k = 1) {
        while (k <= cnt_a && a[k].num < b[i].val) {
            add(a[k].id, 1);
            ++k;
        }
        ans += query(b[i].suf) - query(b[i].pre - 1);
    }
    cout << ans << '\n';
    return 0;
}
```

</details>

## 407 - 好序列 (UVa1608, BZOJ4059)

[题目链接](https://oj.daimayuan.top/course/10/problem/613)

3s, 1024MB

有一个长为$n$的序列$A_1, A_2, \dots, A_n$. 定义一个序列$\{A\}$是好的, 当且仅当他的每一个子区间$[l,r]$满足, 至少存在一个元素$x$仅出现了一次

### 输入格式

多组数据

第一行有一个整数T($1\leq T\leq 10000$), 描述数据组数

对于每组数据, 第一行有一个整数$n$, 第二行有$n$个整数$A_i$
输出格式

对于每组数据, 你需要判断给出的序列是不是好的, 如果是好的输出non-boring, 否则输出boring

### 样例输入

```input1
4
5
1 2 3 4 5
5
1 1 1 1 1
5
1 2 3 2 1
5
1 1 2 1 1
```

### 样例输出

```output1
non-boring
boring
non-boring
boring
```

### 数据规模

所有数据保证 $1\leq n \leq 2\times 10^5,\sum n \leq 10^6, 1 \leq A_i\leq 10^9$

### 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
int a[N], pre[N], suf[N];

bool dc(int L, int R) {
    if (L == R) return 1;
    int k = -1;
    for (int i = 0; L + i <= R - i; ++i) {
        if (pre[L + i] < L && suf[L + i] > R) {
            k = L + i;
            break;
        }
        if (pre[R - i] < L && suf[R - i] > R) {
            k = R - i;
            break;
        }
    }
    if (k == -1) return 0;
    bool f1 = 1, f2 = 1;
    if (L < k) f1 = dc(L, k - 1);
    if (k < R) f2 = dc(k + 1, R);
    return f1 & f2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _t;
    cin >> _t;
    while (_t--) {
        int n;
        cin >> n;
        {
            map<int, int> m;
            _for(i, 1, n) cin >> a[i];
            _for(i, 1, n) {
                pre[i] = m.count(a[i]) ? m[a[i]] : -1;
                m[a[i]] = i;
            }
        }
        {
            map<int, int> m;
            _rfor(i, n, 1) {
                suf[i] = m.count(a[i]) ? m[a[i]] : n + 1;
                m[a[i]] = i;
            }
        }
        cout << (dc(1, n) ? "non-boring\n" : "boring\n");
    }
    return 0;
}
```

</details>
