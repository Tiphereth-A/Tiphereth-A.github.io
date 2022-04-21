---
title: '题解 - [Luogu P2480] [SDOI2010]古代猪文'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 省选
  - SDOI
  - 数学
  - 数论
  - 逆元
  - 快速幂
  - 中国剩余定理(CRT)
  - Lucas
  - Euler定理
date: 2020-10-20 16:26:05
---
[题目链接](https://www.luogu.com.cn/problem/P2480)

<!-- more -->

## 原始题面

### 题目背景

"在那山的那边海的那边有一群小肥猪. 他们活泼又聪明, 他们调皮又灵敏. 他们自由自在生活在那绿色的大草坪, 他们善良勇敢相互都关心……"

——选自猪王国民歌

很久很久以前, 在山的那边海的那边的某片风水宝地曾经存在过一个猪王国. 猪王国地理位置偏僻, 实施的是适应当时社会的自给自足的庄园经济, 很少与外界联系, 商贸活动就更少了. 因此也很少有其他动物知道这样一个王国

猪王国虽然不大, 但是土地肥沃, 屋舍俨然. 如果一定要拿什么与之相比的话, 那就只能是东晋陶渊明笔下的大家想象中的桃花源了. 猪王勤政爱民, 猪民安居乐业, 邻里和睦相处, 国家秩序井然, 经济欣欣向荣, 社会和谐稳定. 和谐的社会带给猪民们对工作火红的热情和对未来的粉色的憧憬

小猪iPig是猪王国的一个很普通的公民. 小猪今年10岁了, 在大肥猪学校上小学三年级. 和大多数猪一样, 他不是很聪明, 因此经常遇到很多或者稀奇古怪或者旁人看来轻而易举的事情令他大伤脑筋. 小猪后来参加了全猪信息学奥林匹克竞赛(Pig Olympiad in Informatics, POI), 取得了不错的名次, 最终保送进入了猪王国大学(Pig Kingdom University, PKU)深造

现在的小猪已经能用计算机解决简单的问题了, 比如能用P++语言编写程序计算出A + B的值. 这个"成就"已经成为了他津津乐道的话题. 当然, 不明真相的同学们也开始对他刮目相看啦~

小猪的故事就将从此展开, 伴随大家两天时间, 希望大家能够喜欢小猪

### 题目描述

猪王国的文明源远流长, 博大精深

iPig 在大肥猪学校图书馆中查阅资料, 得知远古时期猪文文字总个数为 $n$. 当然, 一种语言如果字数很多, 字典也相应会很大. 当时的猪王国国王考虑到如果修一本字典, 规模有可能远远超过康熙字典, 花费的猪力、物力将难以估量. 故考虑再三没有进行这一项劳猪伤财之举. 当然, 猪王国的文字后来随着历史变迁逐渐进行了简化, 去掉了一些不常用的字

iPig 打算研究古时某个朝代的猪文文字. 根据相关文献记载, 那个朝代流传的猪文文字恰好为远古时期的 $1/k$, 其中 $k$ 是 $n$ 的一个正约数（可以是 $1$ 或 $n$）. 不过具体是哪 $1/k$, 以及 $k$ 是多少, 由于历史过于久远, 已经无从考证了

iPig 觉得只要符合文献, 每一种 $k|n$ 都是有可能的. 他打算考虑到所有可能的 $k$. 显然当 $k$ 等于某个定值时, 该朝的猪文文字个数为 $n/k$. 然而从 $n$ 个文字中保留下 $n/k$ 个的情况也是相当多的. iPig 预计, 如果所有可能的 $k$ 的所有情况数加起来为 $p$ 的话, 那么他研究古代文字的代价将会是 $g^p$

现在他想知道猪王国研究古代文字的代价是多少. 由于 iPig 觉得这个数字可能是天文数字, 所以你只需要告诉他答案除以 $999911659$ 的余数就可以了

### 输入输出格式

#### 输入格式

一行两个正整数 $n,g$

#### 输出格式

输出一行一个整数表示答案

### 输入输出样例

#### 输入样例 #1

```input1
4 2
```

#### 输出样例 #1

```output1
2048
```

### 数据规模与约定

- 对于 $10\%$ 的数据, $1\le n \le 50$；
- 对于 $20\%$ 的数据, $1\le n \le 1000$；
- 对于 $40\%$ 的数据, $1\le n \le 10^5$；
- 对于 $100\%$ 的数据, $1\le n,g \le 10^9$

## 题意简述

给出$n,g$, 求
$$g^{\sum_{d\mid n}\binom{n}{d}}\bmod 999911659$$

## 解题思路

设模数为$M$, 则$M=999911659$

首先如果$g\equiv k\pmod{M}$, 则最后结果为$k,~k=0,1$

之后由Euler定理知

$$g^{\sum_{d\mid n}\binom{n}{d}}\equiv g^{\sum_{d\mid n} \binom{n}{d}\bmod\varphi(M)}\pmod{M}$$

指数部分显然要用Lucas, 不过本题指数部分的模数$\varphi(M)=999911658$较大, 我们可使用中国剩余定理进行优化

> 对$\varphi(M)$做质因数分解
> $$\varphi(M)=999911658=2\times 3\times 4679\times 35617$$

## 复杂度

使用CRT优化后:
$$O\left(\sum_{i=1}^4\bigg(p_i+\sum_{d\mid n}\log_{p_i} d\bigg)\right)=O(\sqrt{n}\log n)$$

其中$p_1=2,~p_2=3,~p_3=4679,~p_4=35617$

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-10-20 16:26:05
 * @Description:
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

const int N = 3.6e4, K = 4;
const int MOD = 999911659, mods[K] = {2, 3, 4679, 35617};

i64 frac[K][N] = {{1}, {1}, {1}, {1}}, inv[K][N];
map<pair<int, int>, i64> comb[K];
i64 c(int m, int n, int k) {
    if (comb[k].count(make_pair(m, n))) return comb[k][make_pair(m, n)];
    if (n > m) return comb[k][make_pair(m, n)] = 0;
    if (m == n || n == 0) return comb[k][make_pair(m, n)] = 1;
    return comb[k][make_pair(m, n)] = frac[k][m] * inv[k][n] % mods[k] * inv[k][m - n] % mods[k];
}
i64 lucas(int m, int n, int k) {
    if (comb[k].count(make_pair(m, n))) return comb[k][make_pair(m, n)];
    if (n > m) return comb[k][make_pair(m, n)] = 0;
    if (m == n || n == 0) return comb[k][make_pair(m, n)] = 1;
    return comb[k][make_pair(m, n)] = 1ll * lucas(m / mods[k], n / mods[k], k) * c(m % mods[k], n % mods[k], k) % mods[k];
}

i64 qpow(i64 a, i64 b, int mod = MOD) {
    i64 res = 1;
    a %= mod;
    for (; b; b >>= 1, (a *= a) %= mod)
        if (b & 1) (res *= a) %= mod;
    return res;
}

void init_frac_inv() {
    for (int k = 0; k < 4; ++k)
        for (int i = 1; i <= mods[k]; ++i) frac[k][i] = frac[k][i - 1] * i % mods[k];
    for (int k = 0; k < 4; ++k)
        for (int i = 1; i <= mods[k]; ++i) inv[k][i] = qpow(frac[k][i], mods[k] - 2, mods[k]);
}

// for CRT
constexpr int a[K] = {499955829, 333303886, 213702 * 1353, 28074 * 31254 % (MOD - 1)};
int n, g;
i64 calc_comb_crt(i64 d) {
    i64 res = 0;
    for (int k = 0; k < 4; ++k) (res += lucas(n, d, 0) * a[0]) %= MOD - 1;
    return res;
}
int main() {
    cin >> n >> g;
    if ((g %= MOD) == 0) {
        cout << 0;
        return 0;
    }
    if (g == 1) {
        cout << 1;
        return 0;
    }
    i64 exp = 0;
    init_frac_inv();
    for (int i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            (exp += calc_comb_crt(i)) %= MOD - 1;
            if (i != n / i) (exp += calc_comb_crt(n / i)) %= MOD - 1;
        }
    cout << qpow(g, exp);
    return 0;
}
```

</details>
