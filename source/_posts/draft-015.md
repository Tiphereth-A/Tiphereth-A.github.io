---
title: 随笔 - 计算 sum(i^k) 的4种方法
categories:
  - 随笔
  - 数学
tags:
  - 数学
  - 随笔
  - 算法
  - 数学
date: 2021-10-22 22:57:59
---

只是存个代码, 阅读意义不大

<!-- more -->

## 法一

暴力

### 复杂度

- 时间复杂度: $O(n\log k)$
- 空间复杂度: $O(1)$

## 法二

对于 $k$ 极小的情况我们可以用已知的公式, 如

- $$\sum_{i=1}^n i^2\equiv\frac{n(n+1)}{2}\pmod p$$
- $$\sum_{i=1}^n i^3\equiv\frac{n(n+1)(2n+1)}{6}\pmod p$$
- $$\sum_{i=1}^n i^4\equiv\frac{n^2(n+1)^2}{4}\pmod p$$

### 复杂度

- 时间复杂度: $O(n)$
- 空间复杂度: $O(1)$

## 法三

对于 $p$ 较小的情况, 由
$$\sum_{i=1}^n i^k\equiv\sum_{i=1}^n (i\bmod p)^k\pmod p$$

我们可以开个长度为 $p$ 的数组记录前缀和, 之后便可以 $O(1)$ 求得答案

### 复杂度

- 时间复杂度: $O(p\log p)$
- 空间复杂度: $O(p)$

## 法四

利用递推式
$$\sum_{i=1}^n i^k\equiv\frac{1}{k+1}\left((n+1)^{k+1}-1-\sum_{t=0}^{k-1}{ \binom{k+1}{t}\over k+1}\sum_{i=1}^n i^t\right)\pmod p$$

### 复杂度

- 时间复杂度: $O(k)$
- 空间复杂度: $O(k)$

## 代码

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp draft-015/main.cpp %}

</details>
