---
title: '题解 - Codeforces Round #641 Div. 2 (A-E)'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - DP
  - LIS
  - 数学
  - 数论
  - BFS
  - 最大公约数
  - 最小公倍数
  - 模拟
  - 构造
date: 2020-06-02 23:20:27
---
[比赛链接](https://codeforces.com/contest/1350)

<!-- more -->

## A - Orac and Factors

### 题意

对给定的$n$做$k$次累加, 每次均加上当前$n$的最小非$1$因子

### 思路&做法

显然, 如果$n$是奇数, 累加一次后变为偶数

如果$n$是偶数, 每次加$2$即可

## B - Orac and Models

### 题意

给出一个数组`s[1..n]`, 求满足如下要求的最长子序列`l[]`长度

- `l[]`严格递增
- 对`l[]`中任意相邻两项均满足: 其在原数组中对应下标满足后一项为前一项的倍数

### 思路&做法

多了个限制条件的LIS, 做法自然也是dp

设`f[i]`为`s[i..n]`中的最大值

则我们有

$$f_i=\max\left(1,f_i,\max_{i|j,~1\leqslant j\leqslant n}\{f_j+1\}\right)$$

答案即为$\displaystyle\max_{1\leqslant i\leqslant n}\{f_i\}$

我们也可以设`f[i]`为`s[1..i]`中的最大值

则我们有

$$f_i=\max\left(1,f_i,\max_{j|i,~1\leqslant j\leqslant i}\{f_j+1\}\right)$$

答案也是$\displaystyle\max_{1\leqslant i\leqslant n}\{f_i\}$

接下来就看怎么枚举了, 不同的枚举方法其复杂度也不同

下面介绍两种方法

法一:

先在`[1..n/2]`里枚举`i`, 再枚举`i`的倍数`j` (因为最小的`j`肯定是`2*i`, 所以`i`没必要枚举到`n`)

法二:

先在`[1..n]`里枚举`i`, 再枚举`i`的因子`j`

如果处理得好, 复杂度就是 $\Theta(n\sqrt{n})$, 否则就是 $\Theta(n^2)$

### 复杂度

法一: $\displaystyle\Theta\left(\sum_{i=1}^n\left\lfloor{n\over i}\right\rfloor\right)=O(nH_n)=O(n\log n)$

法二: $\Theta(n\sqrt{n})$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-06-02 23:56:48
 * @Description:
 */
int s[N], f[N];

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    int n, ans = 1;
    cin >> n;
    _for(i, 1, n) f[i] = 1;
    _for(i, 1, n) cin >> s[i];
#if 1
    // O(n*log(n))
    _fd(i, n / 2, 1) for (int j = i; j <= n; j += i) if (s[j] > s[i]) ans = max(ans, f[i] = max(f[i], f[j] + 1));
    // 或
    // _for(i, 2, n / 2) for (int j = i * 2; j <= n; j += i) if (s[j] > s[i]) ans = max(ans, f[j] = max(f[j], f[i] + 1));

#else
    // O(n*sqrt(n))
    _for(i, 2, n)
      for (int j = 1; j <= sqrt(i); ++j)
        if (i % j == 0) {
          if (s[i] > s[j]) ans = max(ans, f[i] = max(f[i], f[j] + 1));
          if (s[i] > s[i / j]) ans = max(ans, f[i] = max(f[i], f[i / j] + 1));
        }
#endif
    cout << ans << endl;
  }
}
```

</details>

## C - Orac and LCM

### 题意

给一组数, 求任意两个数的最小公倍数构成的数组的最大公约数

### 思路&做法

#### 法一(不推荐)

设$a_i=\displaystyle\sum_{j=1}^{\pi(n)}p_j^{\alpha_{ij}}$

结果即为$\displaystyle\sum_{j=1}^{\pi(n)}p_j^{\min\{\max_{1\leqslant k<l\leqslant n}\{\alpha_{kj},\alpha_{lj}\}\}}$

设$\def\enum#1{\alpha_{ #1i}}\enum{1},\enum{2},...,\enum{n}$中的非严格次小值为$b_i$

> 例如: $1,1,2,3,2$的非严格次小值为$1$

结果便为$\displaystyle\sum_{j=1}^{\pi(n)}p_j^{b_i}$

对每个数进行标准分解, 然后取对应指数的非严格次小值即可

不推荐这么做的原因是处理很麻烦, 细节贼多, 而且很容易写丑 ~~交了十几次才A, 我太菜了~~

#### 法二

首先我们有如下引理:

##### <a href="#end-lm-C-1" id="lm-C-1">引理 - C-1</a>

设结果为$S$, 则$\forall p\in\{prime\},k\in\N,p^k\mid S\iff |\{a_i|p^k\mid a_i,~1\leqslant i\leqslant n\}|\geqslant n-1$

###### <a href="#lm-C-1" id="p-lm-C-1">证明</a>

若 $|\{a_i|p^k\mid a_i,~1\leqslant i\leqslant n\}|<n-1$, 则$\exist a_x\ne a_y,~s.t.~p^k\nmid a_x,p^k\nmid a_y$

故 $p^k\nmid[a_x,a_y],~p^k\nmid S$

反之,  
$|\{a_i|p^k\mid a_i,~1\leqslant i\leqslant n\}|\geqslant n-1\iff\forall1\leqslant i<j\leqslant n,p^k\mid[a_i,a_j]\iff p^k\mid S$

<a href="#p-lm-C-1" id="end-lm-C-1">$\Box$</a>

所以设

$$d_i=\begin{cases}
  \gcd_{2\leqslant j\leqslant n}\{a_j\},&i=1\\
  \gcd\{\gcd_{1\leqslant j\leqslant i-1}\{a_j\},\gcd_{i+1\leqslant j\leqslant n}\{a_j\}\},&1<i<n\\
  \gcd_{1\leqslant j\leqslant n-1}\{a_j\},&i=n\\
\end{cases}$$

则$S=\operatorname{lcm}_{1\leqslant i\leqslant n}\{a_i\}$

求`d[]`我们可以维护前缀和`pre[1..n]`和后缀和`suf[1..n]`,  
则$d_i=\begin{cases}
  suf_{2},&i=1\\
  \gcd\{pre_{i-1},suf_{i+1}\},&1< i< n\\
  pre_{n-1},&i=n
\end{cases}$

#### 法三

设 $d_{ij}=\gcd\{a_i,a_j\}$, 则

$$\begin{aligned}
  \gcd_{1\leqslant i<j\leqslant n}\{\operatorname{lcm}(a_i,a_j)\}&=\gcd_{1\leqslant i\leqslant n}\{\gcd_{i<j\leqslant n}\{\operatorname{lcm}(a_i,a_j)\}\}\\
  &=\gcd_{1\leqslant i\leqslant n}\Bigg\{\gcd_{i<j\leqslant n}\bigg\{ {a_ia_j\over d_{ij} }\bigg\}\Bigg\}\\
\end{aligned}$$

固定$a_i$, 考虑 $\displaystyle\gcd_{i<j\leqslant n}\left\{ {a_ia_j\over d_{ij}}\right\}$

$$\begin{aligned}
  \gcd_{i<j\leqslant n}\left\{ {a_ia_j\over d_{ij}}\right\}&=a_i\gcd_{i<j\leqslant n}\left\{ {a_j\over d_{ij}}\right\}\\
  &=a_i{\gcd_{i<j\leqslant n}\{a_j\}\over\gcd_{i<j\leqslant n}\{d_{ij}\}}\\
  &={a_i\gcd_{i<j\leqslant n}\{a_j\}\over\gcd\{a_i,\gcd_{i<j\leqslant n}\{a_j\}\}}\\
  &=\operatorname{lcm}\{a_i,\gcd_{i<j\leqslant n}\{a_j\}\}
\end{aligned}$$

故

$$\gcd_{1\leqslant i<j\leqslant n}\{\operatorname{lcm}(a_i,a_j)\}=\gcd_{1\leqslant i\leqslant n}\{\operatorname{lcm}\{a_i,\gcd_{i<j\leqslant n}\{a_j\}\}\}$$

### 复杂度

#### 法一

设 $m=\max_{1\leqslant j\leqslant \pi(n)}\{p_j|\exist a_k,~p_j\mid a_k\}$

则复杂度为 $\Theta(n+\pi(n)+\sum_{i=1}^n\sum_{j=1}^{\pi(n)}\alpha_{ij})=O(n\log m)$

#### 法二&法三

$O(n\log n)$

### 代码

#### 法一

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-06-03 20:49:18
 * @Description:
 */
int  prime[N], cnt_prime, d[N], idx_p[N];
bool vis[N];
priority_queue<int, vector<int>, greater<int>> mins[N];

i64 gcd(i64 a, i64 b) { return b == 0 ? a : gcd(b, a % b); }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

int main() {
  _for(i, 2, N) {
    if (!vis[i])
      prime[idx_p[i] = ++cnt_prime] = d[i] = i;
    _for(j, 1, cnt_prime) {
      if (i * prime[j] >= N) break;
      vis[i * prime[j]] = 1;
      d[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
  int n;
  cin >> n;
  if (n == 2) {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);
    return 0;
  }
  for (int j = 1, _; j <= n; ++j) {
    cin >> _;
    while (_ > 1) {
      int now_p = d[_], cnt = 0;
      while (_ % now_p == 0) {
        ++cnt;
        _ /= now_p;
      }
      mins[now_p].push(cnt);
    }
  }
  i64 ans = 1;
  for (int i = 1, sec_min = 0; i < N; ++i, sec_min = 0) {
    if (mins[i].size() == n) {
      mins[i].pop();
      sec_min = mins[i].top();
    } else if (mins[i].size() == n - 1)
      sec_min = mins[i].top();
    while (sec_min--) ans *= i;
  }
  cout << ans;
}
```

</details>

#### 法二

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-06-03 09:49:44
 * @Description:
 */
i64 gcd(i64 a, i64 b) { return b == 0 ? a : gcd(b, a % b); }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

int a[N], pre[N], suf[N];

int main() {
  int n;
  cin >> n;
  _for(i, 1, n) cin >> a[i];
  pre[1] = a[1];
  suf[n] = a[n];
  _for(i, 2, n) pre[i] = gcd(pre[i - 1], a[i]);
  _repr(i, n - 1, 1) suf[i] = gcd(suf[i + 1], a[i]);
  i64 ans = lcm(suf[2], pre[n - 1]);
  _rep(i, 2, n) ans = lcm(ans, gcd(pre[i - 1], suf[i + 1]));
  cout << ans;
}
```

</details>

#### 法三

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
// from wzx
int main() {
  read(n);
  _for(i, 1, n) read(a[i]);
  _repr(i, n, 0) suf[i] = gcd(suf[i + 1], a[i]);
  _for(i, 1, n) ans = gcd(ans, lcm(a[i], suf[i + 1]));
  print(ans);
  return 0;
}
```

</details>

## D - Orac and Medians

### 题意

定义可重集$\{\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}\}$的中位数为第$\left\lfloor{n+1\over2}\right\rfloor$小的数

例如$\{1,4,4,6,5\}$的中位数为$4$, $\{1,7,5,8\}$的中位数为$5$

给出一数组`a[1..n]`和一数`k`, 每次你可以选取其中一段区间, 并将区间内的数替换为区间中位数, 问是否可以在有限次内将所有数均换为`k`

### 思路&做法

显然数组中没有$k$的时候是不可能的

其次考虑选取任意两个相邻的数, 则替换后这两个数均变为两数中的较小者

接着考虑选取任意三个相邻的数, 其中这三个数中有两个数$m_1,m_2$满足$m_1=m_2=m$, 则替换后这三个数均变为$m$

另外在上两种情况下, 经过上述变换, 则在原序列中将出现**至少两个**相邻的大于等于$k$的数, 将这段序列设为$M=\{m,m,...,m\}$, 我们接下来要证明通过有限步可让$M=\underbrace{\{k,k,...,k\}}_{n}$

考虑这段数两边与之相邻的数, 设左端和右端的数分别为$l,r$  
因为左端和右端的处理方法一样, 故以左端为例

先假设$l\ne k$

选取$\{l,m,m\}$,若$l=m$, 则可将$l$并入$M$中, 否则, 该序列可变为$\{m,m,m\}$, 自然可以并入$M$中

如果$l=k$, 则选取$\{l,m\}$, 该段序列可变为$\{k,k\}$, 可推知经有限步之后$M$可变为$\{k,k,...,k\}$, 此时可将$l$并入$M$

按此方式可将$M$扩张到原序列左端点, 类似地, 可将$M$扩张到原序列右端点, 即$M$可以替换掉原序列

又由于在此过程中, $m=k$, 某个左端点$=k$, 某个右端点$=k$必然出现至少一次, 故$M$最后可变为$\underbrace{\{k,k,...,k\}}_{n}$

所以如果有两个大于等于$k$的数相邻或间隔$1$, 则一定可以

若任意两个大于等于$k$的数之间的距离超过$1$, 则显然无论如何都不可以

### 复杂度

$\Theta(n)$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-06-03 23:21:20
 * @Description:
 */
int s[N];

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    int n, k;
    cin >> n >> k;
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      flag |= s[i] == k;
    }
    if (!flag) {
      cout << "no\n";
      continue;
    }
    if (n == 1) {
      cout << "yes\n";
      continue;
    }
    flag = 0;
    for (int i = 1; i < n; ++i)
      if (s[i] >= k && s[i + 1] >= k) {
        flag = 1;
        break;
      }
    if (!flag)
      for (int i = 1; i < n - 1; ++i)
        if (s[i] >= k && s[i + 2] >= k) {
          flag = 1;
          break;
        }
    cout << (flag ? "yes\n" : "no\n");
  }
}
```

</details>

## E - Orac and Game of Life

### 题意

给出一个$n\times m$的方阵, 每个格子只有黑色和白色两种状态

如果某方格相邻的方格颜色均与之不同, 则下一时刻不变色, 否则变为与当前时刻不同的颜色

问某些方格在一段时间之后的颜色

### 思路&做法

注意到如果最初有方格是可变色的, 那么经过一段时间之后, 所有的方格都会变为可变色状态(可以证明经过$kmn$个时刻, $k\in[{1\over4},{1\over2}]$)

例外情况是在一开始所有方格均为不可变色, 此时所有方格无论在哪个时刻都是不变色的

所以我们只需求出这段时间有多长即可

我们可以使用BFS求解, 最开始找出所有可变色的方格, 然后慢慢向外扩展

### 复杂度

$O(mn)$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-06-04 00:15:24
 * @Description:
 */
int n, m, g[N][N];

struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  point operator+(const point& oth) {
    return point(x + oth.x, y + oth.y);
  }
};

const point d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool judge(point p) {
  if (p.x > 1 && !(g[p.x][p.y] ^ g[p.x - 1][p.y])) return 1;
  if (p.x < n && !(g[p.x][p.y] ^ g[p.x + 1][p.y])) return 1;
  if (p.y > 1 && !(g[p.x][p.y] ^ g[p.x][p.y - 1])) return 1;
  if (p.y < m && !(g[p.x][p.y] ^ g[p.x][p.y + 1])) return 1;
  return 0;
}
bool legel(point p) { return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m; }

bool extended[N][N];
i64  len_circ[N][N];

int main() {
  int t;
  cin >> n >> m >> t;
  string str;
  getline(cin, str);
  _for(i, 1, n) {
    getline(cin, str);
    _for(j, 1, m) g[i][j] = str[j - 1] - '0';
  }

  queue<point> q;
  _for(i, 1, n) _for(j, 1, m) {
    if (judge({i, j})) {
      q.push({i, j});
      extended[i][j] = 1;
      len_circ[i][j] = 0;
    }
  }

  if (q.empty()) {
    int u, v;
    i64 k;
    _for(i, 1, t) {
      cin >> u >> v >> k;
      cout << g[u][v] << endl;
    }
    return 0;
  }
  
  while (!q.empty()) {
    point now_p = q.front();
    q.pop();
    for (auto& _d : d) {
      point tmp_p = now_p + _d;
      if (legel(tmp_p) && !extended[tmp_p.x][tmp_p.y]) {
        q.push(tmp_p);
        extended[tmp_p.x][tmp_p.y] = 1;
        len_circ[tmp_p.x][tmp_p.y] = len_circ[now_p.x][now_p.y] + 1;
      }
    }
  }

  int u, v;
  i64 k;
  _for(i, 1, t) {
    cin >> u >> v >> k;
    cout << (k <= len_circ[u][v] ? g[u][v] : g[u][v] ^ ((k - len_circ[u][v]) & 1)) << endl;
  }
  return 0;
}
```

</details>
