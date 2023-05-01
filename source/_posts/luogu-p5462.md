---
title: 题解 - [Luogu P5462]【X龙珠】
categories:
  - 算法竞赛
  - 题解
tags:
  - 算法竞赛
  - 数据结构
  - 题解
  - 洛谷
  - 线段树
  - 链表
date: 2019-07-15 01:29:34
---

[题目](https://www.luogu.com.cn/problem/P5462)

我太菜了, 只会用线段树+双向链表做 QwQ

<!--more-->

在读入时直接将序列转化成可能输出的数对

如样例 1 为`(3,1),(1,4),(4,2)`

线段树维护**全局最大数对**, 双向链表**便于寻找前驱后继**

每次直接输出最大数对并删除与它有交集的数对

另外有一点需要注意:

如果最大数对出现在中间时, 在删除自身、前驱和后继后会产生一个新的数对

例如`(3,4),(4,2),(2,1)`删除之后会产生数对`(3,1)`

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P5462 Luogu/P5462/0.cpp %}

</details>
