---
title: "随笔 - 最长下降子序列问题的 O(n log n) 解法"
date: 2022-08-09 08:08:08
categories:
  - 随笔
tags:
  - 随笔
  - 算法竞赛
  - DP
  - LIS
---

科普文, 看看就好

<!-- more -->

## 算法流程

设 `a[]` 为原序列, `s[]` 为辅助数组

1. `a` 中第一个元素插入 `s` 的末尾
1. 遍历 `a`, 从第二个元素取到最后一个

   1. 如果当前遍历到的元素小于 `s` 的末尾, 则将其插入 `s` 的末尾
   1. 否则在队内二分查找比当前元素大的最小元素, 将该元素替换为当前遍历到的元素

      如果找不到这样的元素, 则清空 `s` 并将当前遍历到的元素插入 `s` 的末尾即可

      > 因为此时除了 `s` 末尾的元素之外, `s` 内的其余元素不会影响到答案
      >
      > 而当前遍历到的元素更有可能成为最长下降子序列内的元素
      >
      > 故直接替换即可

1. `s` 的长度即为最长下降子序列长度

## 复杂度

令原序列长度为 $n$

- 时间复杂度: $O(n\log n)$
- 空间复杂度: $O(n)$

## 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp draft-021/main.cpp %}

</details>