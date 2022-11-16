---
title: "题解 - [CQOI2018]异或序列"
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
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

     用一个桶`cnt[x]`记录当前区间内`s[i]=x`的个数

     则当前区间的结果为 $\displaystyle\sum_{i=l}^r\mathrm{cnt}_{s_i\oplus k}$

1. $\Rightarrow O(n\min\{m,\sqrt n\})$: 奇偶化排序优化

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P4462 Luogu/P4462/0.cpp %}

</details>
