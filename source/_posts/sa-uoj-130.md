---
title: "题解 - [UOJ 130 等] 【NOI2015】荷马史诗"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - UOJ
  - BZOJ
  - NOI
  - 数据结构
  - 树
  - Huffman树
date: 2021-07-15 18:57:13
---

题目链接

- [UOJ 130](https://uoj.ac/problem/130)
- BZOJ 4198

<!-- more -->

## 原始题面

{% cq %}追逐影子的人, 自己就是影子. ——荷马{% endcq %}

Allison 最近迷上了文学. 她喜欢在一个慵懒的午后, 细细地品上一杯卡布奇诺, 静静地阅读她爱不释手的《荷马史诗》. 但是由《奥德赛》和《伊利亚特》组成的鸿篇巨制《荷马史诗》实在是太长了, Allison 想通过一种编码方式使得它变得短一些.

一部《荷马史诗》中有 $n$ 种不同的单词, 从 $1$ 到 $n$ 进行编号. 其中第 $i$ 种单词出现的总次数为 $w_i$. Allison 想要用 $k$ 进制串 $s_i$ 来替换第 $i$ 种单词, 使得其满足如下要求:

对于任意的 $1\leqslant i,j\leqslant n$, $i\ne j$, 都有: $s_i$ 不是 $s_j$ 的前缀.

现在 Allison 想要知道, 如何选择 $s_i$, 才能使替换以后得到的新的《荷马史诗》长度最小. 在确保总长度最小的情况下, Allison 还想知道最长的 $s_i$

的最短长度是多少？

一个字符串被称为 $k$ 进制字符串, 当且仅当它的每个字符是 $0$ 到 $k-1$ 之间 (包括 $0$ 和 $k-1$) 的整数.

字符串 $\text{Str1}$ 被称为字符串 $\text{Str2}$ 的前缀, 当且仅当: 存在 $1\leqslant t\leqslant m$, 使得 $\text{Str1}=\text{Str2}[1..t]$. 其中, $m$ 是字符串 $\text{Str2}$ 的长度, $\text{Str2}$[1..t] 表示 $\text{Str2}$ 的前 $t$ 个字符组成的字符串.

### 输入格式

输入文件的第 $1$ 行包含 $2$ 个正整数 $n$, $k$, 中间用单个空格隔开, 表示共有 $n$ 种单词, 需要使用 $k$ 进制字符串进行替换.

接下来 $n$ 行, 第 $i+1$ 行包含 $1$ 个非负整数 $w_i$, 表示第 $i$ 种单词的出现次数.

### 输出格式

输出文件包括 $2$ 行.

第 $1$ 行输出 $1$ 个整数, 为《荷马史诗》经过重新编码以后的最短长度.

第 $2$ 行输出 $1$ 个整数, 为保证最短总长度的情况下, 最长字符串 $s_i$ 的最短长度.

### 样例一

#### input

```input1
4 2
1
1
2
2
```

#### output

```output1
12
2
```

#### explanation

用 $X(k)$ 表示 $X$ 是以 $k$ 进制表示的字符串.

一种最优方案: 令 $00_{(2)}$
替换第 $1$ 种单词, $01_{(2)}$ 替换第 $2$ 种单词, $10_{(2)}$ 替换第 $3$ 种单词, $11_{(2)}$ 替换第 $4$ 种单词. 在这种方案下, 编码以后的最短长度为:

$1\times 2+1\times 2+2\times 2+2\times 2=12$

最长字符串 $s_i$ 的长度为 $2$.

一种非最优方案: 令 $000_{(2)}$ 替换第 $1$ 种单词, $001_{(2)}$ 替换第 $2$ 种单词, $01_{(2)}$ 替换第 $3$ 种单词, $1_{(2)}$ 替换第 $4$ 种单词. 在这种方案下, 编码以后的最短长度为:

$1\times 3+1\times 3+2\times 2+2\times 1=12$

最长字符串 $s_i$ 的长度为 $3$. 与最优方案相比, 文章的长度相同, 但是最长字符串的长度更长一些.

### 样例二

#### input

```input2
6 3
1
1
3
3
9
9
```

#### output

```output2
36
3
```

#### explanation

一种最优方案: 令 $000_{(3)}$
替换第 $1$ 种单词, $001_{(3)}$ 替换第 $2$ 种单词, $01_{(3)}$ 替换第 $3$ 种单词, $02_{(3)}$ 替换第 $4$ 种单词, $1_{(3)}$ 替换第 $5$ 种单词, $2_{(3)}$ 替换第 $6$ 种单词.

### 样例三

见样例数据下载.

### 限制与约定

| 测试点编号 | $n$ 的规模 | $k$ 的规模 | 备注                       | 约定                     |
| ---------- | ---------- | ---------- | -------------------------- | ------------------------ |
| $1$        | $n=3$      | $k=2$      |                            | $0<w_i\leqslant 10^{11}$ |
| 2          | $n=5$      | $k=2$      |
| 3          | $n=16$     | $k=2$      | 所有 $w_i$ 均相等          |
| 4          | $n$=1000   | $k=2$      | $w_i$ 在取值范围内均匀随机 |
| 5          | $n=1000$   | $k=2$      |
| 6          | $n=100000$ | $k=2$      |
| 7          | $n=100000$ | $k=2$      | 所有 $w_i$ 均相等          |
| 8          | $n=100000$ | $k=2$      |
| 9          | $n=7$      | $k=3$      |
| 10         | $n$=16     | $k=3$      | 所有 $w_i$ 均相等          |
| 11         | $n=1001$   | $k=3$      | 所有 $w_i$ 均相等          |
| 12         | $n=99999$  | $k=4$      | 所有 $w_i$ 均相等          |
| 13         | $n=100000$ | $k=4$      |
| 14         | $n=100000$ | $k=4$      |
| 15         | $n=1000$   | $k=5$      |
| 16         | $n=100000$ | $k=7$      | $w_i$ 在取值范围内均匀随机 |
| 17         | $n=100000$ | $k=7$      |
| 18         | $n=100000$ | $k=8$      | $w_i$ 在取值范围内均匀随机 |
| 19         | $n=100000$ | $k=9$      |
| 20         | $n=100000$ | $k=9$      |

对于所有数据, 保证 $2\leqslant n\leqslant 100000$, $2\leqslant k\leqslant 9$.

**选手请注意使用 $64$ 位整数进行输入输出、存储和计算.**

时间限制: 1s

空间限制: 512MB

### 评分方式

对于每个测试点:

若输出文件的第 $1$ 行正确, 得到该测试点 40% 的分数;

若输出文件完全正确, 得到该测试点 100% 的分数.

### 下载

[样例数据下载](https://uoj.ac/download.php?type=problem&id=130)

## 解题思路

K 叉 Huffman 树模板题

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-07-15 18:57:13
 * @Description: UOJ 130, BZOJ 4198
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

#define _for(i, l, r) for (decltype(l + r) i = (l); i <= (r); ++i)
template <class T>
bool chkmax(T& a, T b) { return a < b ? a = b, true : false; }

const int OFFSET = 5;
const int N = 4e5 + OFFSET,K = 10;

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

    std::vector<std::size_t> get_depth(const std::vector<_T>& frenqucy, const std::size_t max_child = 2) {
        if (!_build) build(frenqucy, max_child);
        std::vector<std::size_t> ret;
        ret.resize(frenqucy.size());
        std::queue<std::pair<std::size_t, std::size_t>> q;
        q.emplace(cnt_nodes, 0);
        while (!q.empty()) {
            std::pair<std::size_t, std::size_t> now = q.front();
            q.pop();
            const Node& now_node = nodes[now.first];
            for (std::size_t i = 1; i <= now_node.cnt_child; ++i) {
                const Node& next_node = nodes[now_node.child[i]];
                if (next_node.cnt_child == 0) {
                    if (now_node.child[i] <= ret.size()) ret[now_node.child[i] - 1] = now.second + 1;
                    continue;
                } else
                    q.emplace(now_node.child[i], now.second + 1);
            }
        }
        return ret;
    }
};

Huffman_tree<i64> hf;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<i64> frq;
    i64 _;
    _for(i, 1, n) {
        scanf("%lld", &_);
        frq.push_back(_);
    }

    vector<size_t> dep = hf.get_depth(frq, k);
    size_t len = 0, maxd = 0;
    _for(i, 0, n - 1) {
        len += frq[i] * dep[i];
        chkmax(maxd, dep[i]);
    }
    printf("%lld\n%lld", len, maxd);
    return 0;
}
```

</details>
