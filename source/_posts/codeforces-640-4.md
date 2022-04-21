---
title: '题解 - Codeforces Round #640 Div. 4'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - CodeForces
  - 数学
  - 数论
  - 模拟
  - 枚举
  - 暴力
  - 构造
date: 2020-05-10 01:03:23
---

[比赛链接](https://codeforces.com/contest/1352)

菜 我 菜

<!-- more -->

## A - Sum of Round Numbers

### 题意

把一个不超过$10^4$的数分成个十百千万

### 思路&做法

直接做就行

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-10 01:17:42
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    int n, _ = 1;
    cin >> n;
    vector<int> ans;
    while (n) {
      if (n % 10) ans.push_back(n % 10 * _);
      n /= 10;
      _ *= 10;
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
  }
  return 0;
}
```

</details>

## B - Same Parity Summands

### 题意

输入$n,k$, 要求将$n$拆分成$k$个奇偶性相同, 且和为$n$的数

### 思路&做法

按$n,k$的奇偶性讨论有解情况

首先$k$必定小于等于$n$

其次只有奇数个奇数的和才会是奇数, 所以$n$为奇数时$k$必为奇数

然后因为能拆分出来的偶数最小为$2$, 所以需要拆分成偶数列时必有$n\geqslant2k$

另外$n=k$时需要特判一下

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-09 22:57:28
 * @Description:
 */
void print_odd(int n,int k) {
  cout << "YES" << endl;
  for (int i = 1; i < k; ++i) cout << 1 << " ";
  cout << n - k + 1 << endl;
}

void print_even(int n,int k) {
  cout << "YES" << endl;
  for (int i = 1; i < k; ++i) cout << 2 << " ";
  cout << n - 2 * (k - 1) << endl;
}

int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    int n, k;
    cin >> n >> k;
    if (k > n) {
      cout << "NO" << endl;
      continue;
    }

    if (n == k) {
      print_odd(n, k);
      continue;
    }

    if (n % 2) {
      if (k % 2 == 0) {
        cout << "NO" << endl;
        continue;
      }

      print_odd(n, k);
    } else {
      if (k % 2 && n < k * 2) {
        cout << "NO" << endl;
        continue;
      }

      if (n < k * 2) 
        print_odd(n, k);
      else 
        print_even(n, k);
    }
  }
  return 0;
}
```

</details>

## C - K-th Not Divisible byn

### 题意

输入$n,k$, 输出第$k$个不能被$n$整除的数

### 思路&做法

人傻了, 比赛时愣是没推出来

列个表, 绿色代表不被$n$整除的数, 红色代表被$n$整除的数

绿色的数一共$k$个, 所以最后一个绿色数即为所求

当$k\operatorname{mod}(n-1)>0$时

$$
\def\K{\lfloor\frac{k}{n-1}\rfloor}
\def\arraystretch{1.5}
   \begin{array}{c:c:c:c:c|c}
   \color{green}1 & \color{green}2 & \color{green}... & \color{green}... & \color{green}n-1 & \color{red}n \\ \hdashline
   \color{green}n+1 & \color{green}n+2 & \color{green}... & \color{green}... & \color{green}2n-1 & \color{red}2n \\ \hdashline
   \color{green}\vdots & \color{green}\vdots & \color{green}... & \color{green}... & \color{green}\vdots & \color{red}\vdots \\ \hdashline
   \color{green}\K n+1 & \color{green}\K n+2 & \color{green}... & \color{green}\K n+ k\operatorname{mod}(n-1) &
\end{array}
$$

此时的答案为$\lfloor\frac{k}{n-1}\rfloor n+ k\operatorname{mod}(n-1)$

当$k\operatorname{mod}(n-1)=0$时,

$$
\def\K{\lfloor\frac{k}{n-1}\rfloor}
\def\arraystretch{1.5}
   \begin{array}{c:c:c:c|c}
   \color{green}1 & \color{green}2 & \color{green}... & \color{green}n-1 & \color{red}n \\ \hdashline
   \color{green}n+1 & \color{green}n+2 & \color{green}... & \color{green}2n-1 & \color{red}2n \\ \hdashline
   \color{green}\vdots & \color{green}\vdots &  & \color{green}\vdots & \color{red}\vdots \\ \hdashline
   \color{green}(\K-1) n+1 & \color{green}(\K-1) n+2 & \color{green}... & \color{green}\K n-1 & \color{red}\K n
\end{array}
$$

此时的答案为$\lfloor\frac{k}{n-1}\rfloor n-1$

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-10 00:48:44
 * @Description:
 */
int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    i64 n, k;
    cin >> n >> k;
    cout << (k / (n - 1)) * n + k % (n - 1) - (k % (n - 1) == 0)<< endl;
  }
  return 0;
}
```

</details>

## D - Alice, Bob and Candies

### 题意

有一堆蛋糕排成一列, Alice和Bob站在两端

要求每个回合只有一人吃蛋糕, 且该回合吃掉的蛋糕总数要严格大于上一个回合, 下一个回合再由另一个人吃蛋糕, 蛋糕吃完后结束

Alice先手吃一块

问总回合数和二人吃掉的蛋糕总数

### 思路&做法

直接模拟

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-09 23:18:59
 * @Description:
 */
i64 a[N];

int main() {
  i64 _T_;
  cin >> _T_;
  while (_T_--) {
    i64 n;
    cin >> n;
    i64 alice = 1, bob = n;
    for (i64 i = 1; i <= n; ++i) cin >> a[i];
    i64 tot_a = 0, tot_b = 0, now_a = 0, now_b = 0, cnt = 0;
    bool turn = 0;
    while (alice <= bob) {
      if (turn) {
        while (now_b <= now_a && alice <= bob) now_b += a[bob--];
        tot_b += now_b;
        now_a = 0;
      } else {
        while (now_a <= now_b && alice <= bob) now_a += a[alice++];
        tot_a += now_a;
        now_b = 0;
      }
      ++cnt;
      turn ^= 1;
    }
    cout << cnt << " " << tot_a << " " << tot_b << " " << endl;
  }
  return 0;
}
```

</details>

## E - Special Elements

### 题意

给出一组数, 要求找出满足 数组中某个数等于该数组一段区间和(长度$\geqslant2$)的数的个数

### 思路&做法

万万没想到直接暴力$O(n^2)$就行~~菜 我 菜~~

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-10 00:56:23
 * @Description:
 */
int  a[N];
bool vis[N];

int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, _; i <= n; ++i) {
      _ = a[i];
      for (int j = i + 1; j <= n; ++j) {
        _ += a[j];
        if (_ > 8000) break;
        vis[_] = 1;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += vis[a[i]];
    cout << cnt << endl;
  }
  return 0;
}
```

</details>

## F - Binary String Reconstruction

### 题意

输入三个数`n0, n1, n2`, 要求构造一段01序列, 满足`00`子串一共`n0`个, `10`和`01`子串一共`n1`个, `11`子串一共`n2`个

保证`n0, n1, n2`至少有一个数非0

### 思路&做法

分情况讨论一下就行

感觉我的写法太丑了, 仅供参考哈

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-09 23:52:40
 * @Description:
 */
int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    string str;
#define _append_10(s) \
  for (int i = s; i < n1; i += 2) str.append("10")
#define _append_01(s) \
  for (int i = s; i < n1; i += 2) str.append("01")
    if (n0) {
      str.append(string(n0 + 1, '0'));
      if (n1) {
        str.push_back('1');
        --n1;
        if (n1 % 2){
          _append_01(2);
          if (n2) str.append(n2, '1');
          str.push_back('0');
        } else {
          _append_01(0);
          if (n2) str.append(n2, '1');
        } 
      }
    } else if (n1) {
      if (n2) {
        str = string(n2 + 1, '1');
        if (n1 % 2) {
          str.push_back('0');
          --n1;
          _append_10(0);
        } else
          _append_01(0);
      } else if (n1 % 2)
        _append_10(0);
      else {
        _append_01(0);
        str.push_back('0');
      }
    } else if (n2)
      str = string(n2 + 1, '1');
    cout << str << endl;
  }
  return 0;
}
```

</details>

## G - Special Permutation

### 题意

找出$n$的一个全排列, 满足相邻两数差的绝对值在2和4之间

### 思路&做法

$n<4$时显然无解

当$n\geqslant4$为奇数时我们可以这样构造

`n n-2 ... 3 1 4 2 6 ... n-3 n-1`

当$n\geqslant4$为偶数时我们可以这样构造

`n-1 n-3 ... 3 1 4 2 6 ... n-2 n`

### 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-05-10 00:00:36
 * @Description:
 */
int main() {
  int _T_;
  cin >> _T_;
  while (_T_--) {
    int n;
    cin >> n;
    if (n < 4) {
      cout << -1 << endl;
      continue;
    }
    if (n % 2) {
      for (int i = n; i >= 1; i -= 2) cout << i << " ";
      cout << "4 2 ";
      for (int i = 6; i < n; i += 2) cout << i << " ";
      cout << endl;
    } else {
      for (int i = n - 1; i >= 1; i -= 2) cout << i << " ";
      cout << "4 2 ";
      for (int i = 6; i <= n; i += 2) cout << i << " ";
      cout << endl;
    }
  }
  return 0;
}
```

</details>
