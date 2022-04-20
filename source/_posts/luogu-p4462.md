---
title: '题解 - [CQOI2018]异或序列'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 省选
  - 洛谷
  - BZOJ
  - LibreOJ
  - CQOI
  - 位运算
  - 异或
  - 莫队
  - 前缀和
  - 差分
  - 位运算
date: 2020-01-27 15:40:12
---

## 题面

- [洛谷 P4462](https://www.luogu.com.cn/problem/P4462)
- [BZOJ 5301](https://vjudge.net/problem/%E9%BB%91%E6%9A%97%E7%88%86%E7%82%B8-5301/origin)
- [LOJ 2534](https://loj.ac/problem/2534)

<!--more-->

## 题解

一句话题意: 查询区间内子区间异或和为一定值的个数

暴力: $O(n^3m)$ (查询:$O(m)$, 枚举子序列: $O(n^2)$, 计算异或和: $O(n)$)

优化:

1. $\Rightarrow O(n^2m)$: 前缀和 (计算异或和: $O(n)\Rightarrow O(1)$)

    令
    $$s_i:=\bigoplus_{i=1}^x a_i$$

    则
    $$\bigoplus_{i=l}^r a_i=s_{l-1}\oplus s_r$$

1. $\Rightarrow O(nm)$: 莫队
    - 转换思路

        注意到
        $$a\oplus b=c\iff a\oplus c=b$$

        用一个桶``cnt[x]``记录当前区间内``s[i]=x``的个数

        则当前区间的结果为$\displaystyle\sum_{i=l}^r\mathrm{cnt}_{s_i\oplus k}$
1. $\Rightarrow O(n\min\{m,\sqrt n\})$: 奇偶化排序优化

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
// 注意异或的性质, 本题将a^b==c转为a^c==b
int n, m, sqrt_n, belongs[N];
i64 k;
i64 xor_num[N];
struct node {
  int l, r, id;
  bool operator<(const node& other) const {
    return (belongs[l] != belongs[other.l]) ? l < other.l : (r > other.r) ^ (belongs[l] & 1);
  }
} query[N];
i64 ans[N];
namespace MO {
i64 cnt[M];
i64 add(int p) {
  i64 ans = cnt[xor_num[p] ^ k];
  ++cnt[xor_num[p]];
  return ans;
}
i64 del(int p) {
  --cnt[xor_num[p]];
  return cnt[xor_num[p] ^ k];
}
}  // namespace MO
using MO::add;
using MO::del;
int main() {
  read(n, m, k);
  sqrt_n = sqrt(n);
  _for(i, 1, n) belongs[i] = (i - 1) / sqrt_n + 1;
  _for(i, 1, n) {
    read(xor_num[i]);
    xor_num[i] ^= xor_num[i - 1];
  }
  for (int i = 1, l, r; i <= m; ++i) {
    read(l, r);
    query[i] = {l - 1, r, i};
  }
  std::sort(query + 1, query + m + 1);
  int l = 1, r = 0;
  i64 now_ans = 0;
  _for(i, 1, m) {
    int now_l = query[i].l, now_r = query[i].r;
    while (l < now_l)
      now_ans -= del(l++);
    while (l > now_l)
      now_ans += add(--l);
    while (r < now_r)
      now_ans += add(++r);
    while (r > now_r)
      now_ans -= del(r--);
    ans[query[i].id] = now_ans;
  }
  _for(i, 1, m) print(ans[i]);
  FastIO::flush();
  return 0;
}
```

</details>
