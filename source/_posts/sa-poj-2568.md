---
title: '题解 - [POJ 2568 等] Decode the Tree'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - POJ
  - ZOJ
  - 数据结构
  - 树
  - 无根树
  - Prufer序列
date: 2020-07-30 22:03:55
---
题目链接

- [POJ 2568](https://vjudge.net/problem/POJ-2568/origin)
- [ZOJ 1965](https://vjudge.net/problem/ZOJ-1965/origin)

<!-- more -->

## 原始题面

### Description

A tree (i.e. a connected graph without cycles) with vertices numbered by the integers 1, 2, ..., n is given. The "Prufer" code of such a tree is built as follows: the leaf (a vertex that is incident to only one edge) with the minimal number is taken. This leaf, together with its incident edge is removed from the graph, while the number of the vertex that was adjacent to the leaf is written down. In the obtained graph, this procedure is repeated, until there is only one vertex left (which, by the way, always has number n). The written down sequence of n-1 numbers is called the Prufer code of the tree

Your task is, to reconstruct a tree, given its Prufer code. The tree should be denoted by a word of the language specified by the following grammar:

```text
T ::= "(" N S ")"

S ::= " " T S

    | empty

N ::= number
```

That is, trees have parentheses around them, and a number denoting the identifier of the root vertex, followed by arbitrarily many (maybe none) subtrees separated by a single space character. As an example, take a look at the tree in the figure below which is denoted in the first line of the sample output. To generate further sample input, you may use your solution to Problem 2567

Note that, according to the definition given above, the root of a tree may be a leaf as well. It is only for the ease of denotation that we designate some vertex to be the root. Usually, what we are dealing here with is called an "unrooted tree"

### Input

The input contains several test cases. Each test case specifies the Prufer code of a tree on one line. You will find $n-1$ numbers separated by a single space. Input is terminated by EOF. You may assume that $1\leqslant n\leqslant 50$

### Output

For each test case generate a single line containing the corresponding tree, denoted as described above. Note that, in general, there are many ways to denote such a tree: choose your favourite one

![](1.bmp)

### Sample Input

```input
5 2 5 2 6 2 8
2 3
2 1 6 2 6
```

### Sample Output

```output
(8 (2 (3) (5 (1) (4)) (6 (7))))
(3 (2 (1)))
(6 (1 (4)) (2 (3) (5)))
```

### Source

Ulm Local 2001

## 题意简述

给出一个无根树对应的Prufer序列, 随意令一个结点为根, 按先序遍历输出该树

## 解题思路

板子题, 没啥好说的

具体参见 [学习笔记 - Prufer序列](../prufer-sequence)

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-30 22:03:55
 * @Description: POJ 2568, ZOJ 1965
 */
const int N = 505;

struct Edge {
  int to, next;
} e[N];
int  head[N], cnt_edge;
void addEdge(int x, int y) {
  e[++cnt_edge] = {y, head[x]};
  head[x] = cnt_edge;
}

int  prufer[N], cnt[N];
bool vis[N];

void print(int fa, int now) {
  printf("(%d", now);
  for (int i = head[now], to; i; i = e[i].next) {
    to = e[i].to;
    if (to == fa) continue;
    putchar(' ');
    print(now, to);
  }
  putchar(')');
}

int main() {
  string line;
  while (getline(cin, line)) {
    stringstream ss;
    _set_nul(prufer);
    _set_nul(vis);
    _set_nul(head);
    _set_nul(cnt);
    cnt_edge = 0;
    int n = 0, _;
    ss << line;
    while (ss >> _) ++cnt[prufer[++n] = _];
    ++n;
    priority_queue<int, vector<int>, greater<int>> pq;
    _for(i, 1, n)
      if (!cnt[i]) pq.push(i);
    _rep(i, 1, n) {
      int now = pq.top();
      pq.pop();
      addEdge(prufer[i], now);
      addEdge(now, prufer[i]);
      if (!(--cnt[prufer[i]])) pq.push(prufer[i]);
    }
    if (n == 1) {
      puts("(1)");
      continue;
    }
    print(0, prufer[n - 1]);
    puts("");
  }
}
```

</details>