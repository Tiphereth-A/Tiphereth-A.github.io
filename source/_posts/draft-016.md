---
title: 随笔 - C 语言宏定义的一些进阶操作
categories:
  - 随笔
  - C
tags:
  - C
  - 随笔
  - 宏
  - 数学
  - 排列
  - 全排列
  - Cartesian积/Descartes积
date: 2021-11-04 20:21:45
---

众所周知, C 中宏定义是几乎图灵完备的, 所以我们可以整些花活, 比如:

- 生成全排列
- 生成 Cartesian 积 (Descartes 积)

<!-- more -->

## 一些工具宏

<details open>
<summary><font color='orange'>Show code</font></summary>

```c
#define _RM4(_1, _2, _3, _4, ...) __VA_ARGS__
#define RM4(...) _RM4(__VA_ARGS__)
#define _SEL4(_1, _2, _3, _4, ...) _1, _2, _3, _4
#define SEL4(...) _SEL4(__VA_ARGS__)
```

</details>

其中 `SEL4` 是取出前 4 个元素, `RM4` 是删除前 4 个元素

这样我们便可以通过这两个宏的嵌套来取出我们想要的一段连续元素了

## 生成排列与全排列

首先我们定义这样的宏

<details open>
<summary><font color='orange'>Show code</font></summary>

```c
#define _P2_HELPER(a, b, ...) a, b, __VA_ARGS__, b, a, __VA_ARGS__
#define _P3_HELPER(a, b, c, ...) _P2_HELPER(a, b, c, __VA_ARGS__), _P2_HELPER(b, c, a, __VA_ARGS__), _P2_HELPER(c, a, b, __VA_ARGS__)
#define P4(a, b, c, d) _P3_HELPER(a, b, c, d), _P3_HELPER(b, c, d, a), _P3_HELPER(c, d, a, b), _P3_HELPER(d, a, b, c)
```

</details>

则 `P4(a, b, c, d)` 即为 `a, b, c, d` 的全排列

效果如下 (为了方便查看, 每 4 个元素后均插入了 `|`, 每 12 个元素后均插入了换行符)

<details open>
<summary><font color='orange'>Show code</font></summary>

```text
P4(a, b, c, d)
=>
a, b, c, d, | b, a, c, d, | b, c, a, d,
c, b, a, d, | c, a, b, d, | a, c, b, d,
b, c, d, a, | c, b, d, a, | c, d, b, a,
d, c, b, a, | d, b, c, a, | b, d, c, a,
c, d, a, b, | d, c, a, b, | d, a, c, b,
a, d, c, b, | a, c, d, b, | c, a, d, b,
d, a, b, c, | a, d, b, c, | a, b, d, c,
b, a, d, c, | b, d, a, c, | d, b, a, c
```

</details>

如何得到 4 个元素中取 3 个元素得到的所有排列呢

只需要稍加修改

<details open>
<summary><font color='orange'>Show code</font></summary>

```c
#define P3(a, b, c) _P2_HELPER(a, b, c), _P2_HELPER(b, c, a), _P2_HELPER(c, a, b)
#define P4_3(a, b, c, d) P3(a, b, c), P3(b, c, d), P3(c, d, a), P3(d, a, b)
```

</details>

## 生成 Cartesian 积

这个就相对好理解一些

<details open>
<summary><font color='orange'>Show code</font></summary>

```c
#define _CPROD1_4_HELPER(a, b, c, d, ...) a, __VA_ARGS__, b, __VA_ARGS__, c, __VA_ARGS__, d, __VA_ARGS__
#define _CPROD2_4_HELPER(a, b, c, d, ...) _CPROD1_4_HELPER(a, b, c, d, a, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, b, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, c, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, d, __VA_ARGS__)
#define CPROD3_4(a, b, c, d) _CPROD2_4_HELPER(a, b, c, d, a), _CPROD2_4_HELPER(a, b, c, d, b), _CPROD2_4_HELPER(a, b, c, d, c), _CPROD2_4_HELPER(a, b, c, d, d)
```

</details>

`CPROD3_4(a, b, c, d)` 即为 $(a,b,c,d)\oplus(a,b,c,d)\oplus(a,b,c,d)$

效果如下 (为了方便查看, 每 3 个元素后均插入了 `|`, 每 12 个元素后均插入了换行符)

<details open>
<summary><font color='orange'>Show code</font></summary>

```text
CPROD3_4(a, b, c, d)
=>
a, a, a, | b, a, a, | c, a, a, | d, a, a,
a, b, a, | b, b, a, | c, b, a, | d, b, a,
a, c, a, | b, c, a, | c, c, a, | d, c, a,
a, d, a, | b, d, a, | c, d, a, | d, d, a,
a, a, b, | b, a, b, | c, a, b, | d, a, b,
a, b, b, | b, b, b, | c, b, b, | d, b, b,
a, c, b, | b, c, b, | c, c, b, | d, c, b,
a, d, b, | b, d, b, | c, d, b, | d, d, b,
a, a, c, | b, a, c, | c, a, c, | d, a, c,
a, b, c, | b, b, c, | c, b, c, | d, b, c,
a, c, c, | b, c, c, | c, c, c, | d, c, c,
a, d, c, | b, d, c, | c, d, c, | d, d, c,
a, a, d, | b, a, d, | c, a, d, | d, a, d,
a, b, d, | b, b, d, | c, b, d, | d, b, d,
a, c, d, | b, c, d, | c, c, d, | d, c, d,
a, d, d, | b, d, d, | c, d, d, | d, d, d
```

</details>
