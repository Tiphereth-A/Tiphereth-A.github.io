---
title: 笔记 - Huffman 树与 Huffman 编码
categories:
  - 程序设计
  - 笔记
tags:
  - 程序设计
  - 笔记
  - 模板
  - 算法
  - 数据结构
  - 树
  - Huffman树
  - Huffman编码
date: 2021-07-15 18:41:12
---

Huffman 编码是一种基于 Huffman 树的, 按字符概率构造的, 能保证编码平均长度最短的编码方式

<!-- more -->

## 介绍

Huffman 树即为根结点到所有叶子结点的带权路径长度之和最小的树

### 构建方式

对于一棵 $k$ 叉的 Huffman 树, 我们首先要确保 结点个数 $n$ 满足 $(k-1)\mid(n-1)$, 否则我们可以补充若干个权值为 $0$ 的结点使其成立

首先按结点的权值排序, 然后取出 $k$ 个权值最小的结点合并为一个新结点并插入该序列, 新结点的权值为这 $k$ 个点权值之和, 直到序列中只剩下 $1$ 个结点为止

Huffman 编码通过对 Huffman 树进行层序遍历得到

## 例题

- [UOJ 130 - 【NOI2015】荷马史诗](https://uoj.ac/problem/130)
  
  [题解](../sa-uoj-130/)

## 代码 (K 叉 Huffman 树)

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
template <class _T = std::size_t, const std::size_t _CHILD = K, const std::size_t _N = N, const bool _clear = false>
class Huffman_tree {
  protected:
    struct Node {
        _T w;
        std::size_t child[_CHILD];
        std::size_t cnt_child;
    } nodes[_N];
    bool _build;
    std::size_t cnt_nodes, max_child_size, leaves;

  public:
    Huffman_tree(std::size_t max_child = 2) : max_child_size(max_child) {
        if (_clear) memset(nodes, cnt_nodes = leaves = _build = 0, sizeof(nodes));
    }
    void clear() { memset(nodes, cnt_nodes = leaves = max_child_size = _build = 0, sizeof(nodes)); }

    void build(const std::vector<_T>& frenqucy, std::size_t max_child) {
        if (_build) return;
        max_child_size = max_child;
        cnt_nodes = frenqucy.size();
        for (std::size_t i = 1; i <= cnt_nodes; ++i) {
            nodes[i].w = frenqucy[i - 1];
            nodes[i].cnt_child = 0;
        }
        cnt_nodes += ((max_child - 1) - ((cnt_nodes - 1) % (max_child - 1))) % (max_child - 1);

        std::priority_queue<std::pair<_T, int>, std::vector<std::pair<_T, int>>, std::greater<std::pair<_T, int>>> q;
        for (std::size_t i = 1; i <= cnt_nodes; ++i) q.emplace(nodes[i].w, i);
        while (q.size() > 1) {
            ++cnt_nodes;
            for (std::size_t i = 1; i <= max_child_size; ++i) {
                if (q.empty()) break;
                nodes[cnt_nodes].w += q.top().first;
                nodes[cnt_nodes].child[++nodes[cnt_nodes].cnt_child] = q.top().second;
                q.pop();
            }
            q.emplace(nodes[cnt_nodes].w, cnt_nodes);
        }
        _build = 1;
    }

    // encode(frenqucy, char_set)[i] means the Huffman code of frenqucy[i]
    std::vector<std::string> encode(const std::vector<_T>& frenqucy, const std::string& char_set = "01") {
        if (!_build) build(frenqucy, char_set.length());
        std::vector<std::string> ret;
        ret.resize(frenqucy.size());
        std::queue<std::pair<std::size_t, std::string>> q;
        q.emplace(cnt_nodes, "");
        while (!q.empty()) {
            std::pair<std::size_t, std::string> now = q.front();
            q.pop();
            const Node& now_node = nodes[now.first];
            for (std::size_t i = 1; i <= now_node.cnt_child; ++i) {
                const Node& next_node = nodes[now_node.child[i]];
                if (next_node.cnt_child == 0) {
                    if (now_node.child[i] <= ret.size()) ret[now_node.child[i] - 1] = now.second + char_set[i - 1];
                    continue;
                } else
                    q.emplace(now_node.child[i], now.second + char_set[i - 1]);
            }
        }
        return ret;
    }
};
```

</details>
