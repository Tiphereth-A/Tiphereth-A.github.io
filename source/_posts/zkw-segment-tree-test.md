---
title: 「线段树的扩展之浅谈zkw线段树」一文的测试代码与结果更新
tags:
  - 算法竞赛
  - 洛谷日报
  - 测试
date: 2020-02-10 02:04:18
comments: false
---

更新的原因主要是笔者觉得以前的码风很乱 QwQ

<!--more-->

测试平台:

- 系统: Ubuntu 18.04 LTS 64 位

- CPU: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz

所有代码均使用基于`fread`和`fwrite`的快读快写模板, 并在编译时使用 C++98 标准和 O3 优化

结果 (单位: s):

|           | 递归线段树 | zkw 线段树 | 树状数组 |
| :-------: | :--------: | :--------: | :------: |
| 1e6(5 组) |  0.31803   |  0.20853   | 0.17850  |
| 5e6(5 组) |  2.04103   |  0.96225   | 1.45518  |
| 1e7(5 组) |  6.47973   |  3.73674   | 3.76717  |
| 2e7(5 组) |  14.7163   |  8.07310   | 7.91748  |

可以注意到, 正如 @[frankchenfu](https://www.luogu.com.cn/user/23398) 在原文评论里所说, 开了 O3 优化后, zkw 线段树得到了更显著的优化, 速度与树状数组更加接近(毕竟依 zkw julao 所说, 二者理论上速度应该差不多)

而且笔者自认为 zkw 线段树更优美, 所以还是推荐各位学习 zkw 线段树 QwQ

测试代码:

1. 递归线段树:

   <details open>
   <summary><font color='orange'>Show code</font></summary>

   {% icodeweb blog lang:cpp zkw-segment-tree-test/seg-r.cpp %}

   </details>

2. zkw 线段树:

   <details open>
   <summary><font color='orange'>Show code</font></summary>

   {% icodeweb blog lang:cpp zkw-segment-tree-test/seg-zkw.cpp %}

   </details>

3. 树状数组:

   <details open>
   <summary><font color='orange'>Show code</font></summary>

   {% icodeweb blog lang:cpp zkw-segment-tree-test/bit.cpp %}

   </details>

4. 数据生成器:

   <details open>
   <summary><font color='orange'>Show code</font></summary>

   {% icodeweb blog lang:cpp zkw-segment-tree-test/data_gen.cpp %}

   </details>

{% post_link zkw-segment-tree 回到原文 %}
