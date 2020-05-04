---
title: "题解 - Codeforces Round #639 Div. 2 (A-D)"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - DFS
  - 数学
  - 数论
  - 同余
  - 二分
  - 打表
  - 枚举
date: 2020-05-07 00:07:49
---

[比赛链接](https://codeforces.com/contest/1345)

打一半改成 unrated 了海星

惨 Monogon 惨

<!--more-->

## A. Puzzle Pieces

### 题意

有$n\times m$个完全相同的拼图块, 每个均一凹三凸, 如图

![](A_1.bmp)

问对给定的$n$和$m$, 能不能拼出$n\times m$的矩形

### 思路&做法

不妨假设$n\leqslant m$

首先当$n=1$时和$n=m=2$时显然可以

![](A_2.bmp)

![](A_3.bmp)

而如果想拼出$n\times m,2<n\leqslant m$的矩形, 必然需要先拼出$(n-1)\times m$和$n\times(m-1)$的矩形

观察发现, 如果矩形可以拼出, 则每条拼图块的公共边必然为一凹一凸, 可以发现$m=3$和$n=3$时的矩形一共$7$条公共边, 但所有拼图块一共只有$6$个凹边

故可能的情况只有$n=1$时和$n=m=2$时

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-07 00:27:19
 * @Description:
 */
int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1 || (n == 2 && m == 2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
```

</details>

## B. Card Constructions

### 题意

输入$n$, 计算能搭出几个卡牌金字塔

图示即为卡牌金字塔高度$h=1,2,3$时的情况

![](B_1.bmp)

### 思路&做法

易得高度为$h$的卡牌金字塔所消耗的卡牌总数为$\frac{1}{2}(3h^2+h)$

所以直接打个表然后二分查找就好了

其实不用二分也能过, 直接从高到低遍历一遍就行

### 复杂度

不需要二分就可以做到单次$O(\sqrt n)$ (实际上我比赛时的二分做法也是$O(\sqrt{n})$的, 常数反而更大些)

此时的总体复杂度显然是$O(\sum_{i=1}^t\sqrt{n_i})$, 不过可以将其写成更好看的形式

令$N=\displaystyle\sum_{i=1}^tn_i$, 由 Cauchy-Schwarz 不等式可知

$$\sum_{i=1}^t\sqrt{n_i}\leqslant\sqrt{\sum_{i=1}^t1\cdot\sum_{i=1}^tn_i}=\sqrt{tN}$$

所以可以记作$O(\sqrt{tN})$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-07 00:34:48
 * @Description:
 */
u64 f[N];
int main() {
  for (u64 i = 1; i < N; ++i) f[i] = (3 * i * i + i) / 2;
  int _T_;
  cin >> _T_;
  while (_T_--) {
    int n;
    cin >> n;
    if (n < 2) {
      cout << 0 << endl;
      continue;
    }
    int pos = lower_bound(f, f + N, n) - f, cnt = 1;
    while (pos) {
      if (pos == 0 || f[pos] == n) {
        cout << cnt << endl;
        break;
      }
      n -= f[pos - 1];
      if (n < 2) {
        cout << cnt << endl;
        break;
      }
      ++cnt;
      pos = lower_bound(f, f + N, n) - f;
    }
  }
  return 0;
}
```

</details>

## C. Hilbert's Hotel

### 题意

给出$n$和一组数$a_0,a_1,...,a_{n-1}$, 问是否$\exists x,y\in\Bbb{Z}, x\ne y\ s.t.\ x+a_{x\operatorname{mod}n}=y+a_{y\operatorname{mod}n}$

### 思路&做法

首先我们可以发现

- $x=y+kn,k\in\Bbb{Z}\iff x+a_{x\operatorname{mod}n}=y+a_{y\operatorname{mod}n}+kn$
- $x+a_{x\operatorname{mod}n}=y+a_{y\operatorname{mod}n}\impliedby \begin{cases}
  x+a_{x\operatorname{mod}n}\equiv y+a_{y\operatorname{mod}n}\pmod n\\
  x\ne y+kn,k\in\Bbb{Z}
\end{cases}$

所以我们只需在$\Bbb{Z}_n$下考虑即可

若
$$\exists x,y\in\Bbb{Z}_n, x\ne y\ s.t.\ x+a_{x\operatorname{mod}n}\equiv y+a_{y\operatorname{mod}n}\pmod n$$
则
$$\exists x,y\in\Bbb{Z}, x\ne y\ s.t.\ x+a_{x\operatorname{mod}n}=y+a_{y\operatorname{mod}n}$$

### 复杂度

单次$\Theta(n)$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-07 00:37:12
 * @Description:
 */
int a[N];
int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    set<int> s;
    int      n;
    cin >> n;
    if (n == 1) {
      cin >> n;
      cout << "YES" << endl;
      continue;
    }
    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    for (int i = 0; i < n; ++i) {
      if (s.count(((i + a[i % n]) % n + n) % n)) {
        cout << "NO" << endl;
        goto __END;
      }
      s.insert(((i + a[i % n]) % n + n) % n);
    }
    cout << "YES" << endl;
  __END:;
  }
  return 0;
}
```

</details>

## D. Monopole Magnets

### 题意

有个$n\times m$的地图, 每个格子都染成了黑色或白色, 每个格子还可以放单极磁铁(当然这玩意现实中不存在), 如果 N 极和 S 极同行或同列, 则 N 级可以向 S 极方向移动一格, 要求

1. 每行和每列都至少放一个 S 极
1. N 极能经过所有黑格
1. N 极不能有经过白格的可能

问对给定的地图是否存在放置单极磁铁的方案, 如果有的话一共可以放几个 N 极

### 思路&做法

如果有方案的话, N 极个数显然为黑格连通块个数

如果在某行/列出现两个黑格中间有白格的情况, 则中间的白格有可能被经过, 否则该行/列没有 S 极

如果某一行/列全白, 则必有某一列/行全白, 从而 S 极可置于交点处. 否则白格有可能被经过, 或该行/列没有 S 极

所以只需要先遍历看看是否存在上述情况, 如果没有再求个连通块个数就行了

### 复杂度

$\Theta(nm)$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-07 11:47:49
 * @Description:
 */
const int d[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

char _[N][N];
bool vis[N][N];
int  n, m;

bool dfs(int x, int y) {
  if (vis[x][y] || _[x][y] == '.') return 0;
  vis[x][y] = 1;
  for (const int* i : d) {
    int now_x = x + *i, now_y = y + *(i + 1);
    if (now_x <= 0 || now_y <= 0 || now_x > n || now_y > m) continue;
    dfs(now_x, now_y);
  }
  return 1;
}

int main() {
  scanf("%d %d\n", &n, &m);
  _for(i, 1, n) {
    fgets(_[i] + 1, m + 1, stdin);
    if (_[i][1] == 10) fgets(_[i] + 1, m + 1, stdin);
  }

  int while_line = 0, while_col = 0;
  for (int i = 1, f; i <= n; ++i) {
    f = 1;
    _for(j, 1, m) if (_[i][j] == '#') f = 0;
    while_line += f;
  }
  for (int i = 1, f; i <= m; ++i) {
    f = 1;
    _for(j, 1, n) if (_[j][i] == '#') f = 0;
    while_col += f;
  }
  if ((while_line == 0) ^ (while_col == 0)) {
    puts("-1");
    return 0;
  }

  for (int i = 1, l, r; i <= n; ++i) {
    l = r = 0;
    _for(j, 1, m) if (_[i][j] == '#') {
      l = j;
      break;
    }
    _fd(j, m, 1) if (_[i][j] == '#') {
      r = j;
      break;
    }
    _for(j, l, r) if (_[i][j] == '.') {
      puts("-1");
      return 0;
    }
  }
  for (int i = 1, l, r; i <= m; ++i) {
    l = r = 0;
    _for(j, 1, n) if (_[j][i] == '#') {
      l = j;
      break;
    }
    _fd(j, n, 1) if (_[j][i] == '#') {
      r = j;
      break;
    }
    _for(j, l, r) if (_[j][i] == '.') {
      puts("-1");
      return 0;
    }
  }
  int cnt = 0;
  _for(i, 1, n) _for(j, 1, m) cnt += dfs(i, j);
  printf("%d\n", cnt);
  return 0;
}
```

</details>
