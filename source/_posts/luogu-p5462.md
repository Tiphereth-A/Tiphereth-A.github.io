---
title: 题解 - Luogu P5462【X龙珠】
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
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

另外有一点需要注意：

如果最大数对出现在中间时, 在删除自身、前驱和后继后会产生一个新的数对

例如`(3,4),(4,2),(2,1)`删除之后会产生数对`(3,1)`

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2019-07-15 01:29:34
 * @Description:
 */
#include <bits/stdc++.h>
#define _fp(i, l, r) for (register int i = (l); i <= (r); ++i)
#define _rep(i, l, r) for (register int i = (l); i < (r); ++i)
const int N = 1e5 + 5;
//为了便于套板子, 所以把线段树放到namespace里了
namespace Seg {
//为了清晰, 用了一些宏定义
#define _now tree[p]
#define _lch tree[p].l
#define _rch tree[p].r

struct node {
  int first, second, pos;  //设pos是为了便于找下标, 从而进行删除/修改操作
} pair[N];                 //存数对

struct segtree {
  node val;
  int  l, r;
  bool operator<(const segtree& a) const {
    return (val.first == a.val.first) ? val.second < a.val.second : val.first < a.val.first;
  }
  void print() { print(val.first, val.second); }  //这里用了快写模板, 注意修改
} tree[N << 2];
int cnt;
//这里用内存池式写法是因为之前写的时候设想的是直接将没删除的儿子直接向上合并到父结点
//后来发现和其他操作搭配起来有点困难
//但我懒得换常见的数组写法了

node _max(const segtree& a, const segtree& b) {
  return a < b ? b.val : a.val;
}
void push_up(int p) { _now.val = _max(tree[_lch], tree[_rch]); }
void build(int& p, int l, int r) {
  p = ++cnt;
  if (l == r) {
    _now = {pair[l], 0, 0};
    return;
  }
  int mid = l + ((r - l) >> 1);  //防溢出
  build(_lch, l, mid);
  build(_rch, mid + 1, r);
  push_up(p);
}
void del(int p, int l, int r, int target) {
  if (_now.val.first == -1) return;
  if (l == r) {
    _now = {pair[target] = {-1, -1, target}, 0, 0};
    return;
  }
  int mid = l + ((r - l) >> 1);
  if (target <= mid)
    del(_lch, l, mid, target);
  else
    del(_rch, mid + 1, r, target);
  push_up(p);
}
void modify(int p, int l, int r, int target, const node& a) {
  if (l == r) {
    _now = {pair[target] = a, 0, 0};  //修改后一定要记得更新原数组
    return;
  }
  int mid = l + ((r - l) >> 1);
  if (target <= mid)
    modify(_lch, l, mid, target, a);
  else
    modify(_rch, mid + 1, r, target, a);
  push_up(p);
}
//以上都是线段树常规操作
}  // namespace Seg
struct list {
  int pre, suc;  //pascal后遗症
} id[N];         //双向链表
int head, rear, a[N], n;

void del_rear(const int& p, const int& pre) {
  Seg::del(1, 1, n, p);
  Seg::del(1, 1, n, pre);
  //链表常规操作
  rear        = id[pre].pre;
  id[pre].pre = id[rear].suc = 0;
}

void del_head(const int& p, const int& suc) {
  Seg::del(1, 1, n, p);
  Seg::del(1, 1, n, suc);
  //链表常规操作*2
  head        = id[suc].suc;
  id[suc].suc = id[head].pre = 0;
}
void del(const int& p, const int& pre, const int& suc) {
  //因为上面的代码中删除也会更新原数组, 所以要把修改操作放到前面
  Seg::modify(1, 1, n, p, {Seg::pair[pre].first, Seg::pair[suc].second, p});

  Seg::del(1, 1, n, pre);
  //链表常规操作*3
  if (!id[pre].pre)
    head = p;
  else
    id[id[pre].pre].suc = p;
  id[p].pre = id[pre].pre;

  Seg::del(1, 1, n, suc);
  //链表常规操作*4
  if (!id[suc].suc)
    rear = p;
  else
    id[id[suc].suc].pre = p;
  id[p].suc = id[suc].suc;
}
int main() {
  read(n);  //这里用了快读模板, 注意修改
  _fp(i, 1, n) read(a[i]);
  --n;  //为了方便后面写代码
  _fp(i, 1, n) {
    Seg::pair[i] = {a[i], a[i + 1], i};
    id[i]        = {i - 1, i + 1};
  }
  int tmp1;
  head      = 1;
  rear      = n;
  id[n].suc = 0;
  Seg::build(tmp1, 1, n);
  _rep(i, 1, (n + 1) >> 1) {
    Seg::tree[1].print();  //输出全局最值
    int tmp = Seg::tree[1].val.pos;
    int suc = id[tmp].suc, pre = id[tmp].pre;  //找前驱和后继
    //删数对
    //如果是表头就删掉当前和后继
    //如果是表尾就删掉当前和前驱
    //如果在中间就删除前驱和后继, 并把当前结点修改一下
    if (tmp == rear)
      del_rear(tmp, pre);
    else if (tmp == head)
      del_head(tmp, suc);
    else
      del(tmp, pre, suc);
  }
  Seg::tree[1].print();  //把它单独提出来是为了省去不必要的操作
  return 0;
}
```

</details>
