---
title: 模板 - 对顶堆
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - C++
  - 数据结构
  - 堆
  - 对顶堆
date: 2021-07-15 19:34:54
---

一个大根堆一个小根堆怼一起, 可以解决动态求中位数问题

<!-- more -->

<details open='open'>
<summary><font color='orange'>Show code</font></summary>

```cpp
template <class _T>
class UD_heap {
  private:
    std::priority_queue<_T> dq;
    std::priority_queue<_T, std::vector<_T>, std::greater<_T>> uq;
    bool _init = 0;

  public:
    void clear() {
        _init = 0;
        dq = decltype(dq)();
        uq = decltype(uq)();
    }
    void init(_T x) {
        if (_init) {
            insert(x);
            return;
        }
        dq.push(x);
        _init = 1;
    }
    void insert(_T x) {
        if (!_init) {
            init(x);
            return;
        }
        (x > dq.top() ? uq.push(x) : dq.push(x));
        if (uq.size() > dq.size() + 1) {
            dq.push(uq.top());
            uq.pop();
        } else if (dq.size() > uq.size() + 1) {
            uq.push(dq.top());
            dq.pop();
        }
    }
    _T get_mid() { return uq.size() > dq.size() ? uq.top() : dq.top(); }
};
```

</details>
