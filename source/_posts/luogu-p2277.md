---
title: "题解 - [Luogu P2277] [HNOI2003]24点游戏"
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 省选
  - HNOI
  - 暴力
  - 模拟
  - hash
  - 排列
  - 全排列
  - Cartesian积/Descartes积
date: 2021-11-05 01:01:36
---

[题目链接](https://www.luogu.com.cn/problem/P2277)

<!-- more -->

## 原始题面

### 题目描述

为了培养小孩的计算能力, 大人们经常给小孩玩这样的游戏：从 1 付扑克牌中任意抽出 4 张扑克, 要小孩用 "+", "-", "\*", " /"和括号组成一个合法的表达式, 并使表达式的值为 24 点. 这种游戏就是所谓的"24 点游戏"

请你编程求出对于给出的任意 4 个正整数 a, b, c, d, 请你编程求出这 4 个整数能组成多少个值为 24 的不同表达式

### 输入输出格式

#### 输入格式

输入文件名：input.txt

输入文件共一行, 为 4 个正整数 a, b, c, d. (0<=a,b,c,d<=100)

#### 输出格式

输出文件名：output.txt

输出文件为由 a, b, c, d 组成的值为 24 表达式个数, 如没有, 输出 0

### 输入输出样例

#### 输入样例 #1

```input1
5 5 5 5
```

#### 输出样例 #1

```output1
1
```

## 解题思路

整点 nasty 的花活

显然枚举所有可能的式子然后去重就行

即 [这个代码](enum.cpp)

当然, 这代码都 700+ KB 了, 没有一个 OJ 会接受这么大的代码, 所以我们可以用宏定义折叠一下 (实际上这个 700+ KB 的代码就是宏定义展开得到的)

我们思考一下需要哪些宏定义

1. 我们需要一个能枚举 $\{a,b,c,d\}^3$ (乘法为 Descartes 积) 的宏定义来枚举所有运算符的情况

   <details>
   <summary><font color='orange'>Show code</font></summary>

   ```c
   #define _CPROD1_4_HELPER(a, b, c, d, ...) a, __VA_ARGS__, b, __VA_ARGS__, c, __VA_ARGS__, d, __VA_ARGS__

   #define _CPROD2_4_HELPER(a, b, c, d, ...) _CPROD1_4_HELPER(a, b, c, d, a, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, b, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, c, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, d, __VA_ARGS__)

   #define CPROD3_4(a, b, c, d) _CPROD2_4_HELPER(a, b, c, d, a), _CPROD2_4_HELPER(a, b, c, d, b), _CPROD2_4_HELPER(a, b, c, d, c), _CPROD2_4_HELPER(a, b, c, d, d)

   // use this
   #define OPANDS CPROD3_4(+, -, *, /)
   ```

   </details>

   然后我们需要这样的宏定义来得到每一组运算符

   <details>
   <summary><font color='orange'>Show code</font></summary>

   ```c
   #define _RM3(_1, _2, _3, ...) __VA_ARGS__
   #define _SEL3(_1, _2, _3, ...) _1, _2, _3

   // use this
   // remove first 3 elements
   #define RM3(...) _RM3(__VA_ARGS__)
   // use this
   // select first 3 elements
   #define SEL3(...) _SEL3(__VA_ARGS__)
   ```

   </details>

1. 我们需要一个能枚举 $\{a,b,c,d\}$ 全排列的宏定义来枚举所有数的情况 (实际上, 因为这样会让编译时间过长甚至让编译器爆栈, 所以这个并没有用上)

   <details>
   <summary><font color='orange'>Show code</font></summary>

   ```c
   #define _P2_HELPER(a, b, ...) a, b, __VA_ARGS__, b, a, __VA_ARGS__

   #define _P3_HELPER(a, b, c, ...) _P2_HELPER(a, b, c, __VA_ARGS__), _P2_HELPER(b, c, a, __VA_ARGS__), _P2_HELPER(c, a, b, __VA_ARGS__)

   // use this
   #define P4 _P3_HELPER(a, b, c, d), _P3_HELPER(b, c, d, a), _P3_HELPER(c, d, a, b), _P3_HELPER(d, a, b, c)
   ```

   </details>

   然后我们需要这样的宏定义来得到每一组数

   <details>
   <summary><font color='orange'>Show code</font></summary>

   ```c
   #define _RM4(_1, _2, _3, _4, ...) __VA_ARGS__
   #define _SEL4(_1, _2, _3, _4, ...) _1, _2, _3, _4

   // use this
   // remove first 4 elements
   #define RM4(...) _RM4(__VA_ARGS__)
   // use this
   // select first 4 elements
   #define SEL4(...) _SEL4(__VA_ARGS__)
   ```

   </details>

1. 我们需要枚举 5 种运算方式

   - $(((a\odot b)\odot c)\odot d)$
   - $((a\odot (b\odot c))\odot d)$
   - $(a\odot ((b\odot c)\odot d))$
   - $(a\odot (b\odot (c\odot d)))$
   - $((a\odot b)\odot (c\odot d))$

   其中 $\odot\in\{+,-,\times,\div\}$

   这个写成宏定义就很简单

     <details>
     <summary><font color='orange'>Show code</font></summary>

   ```c
   #define ___CALC0(a, b, c, d, opab, opbc, opcd) Node(0, a, b, c, d, #opab, #opbc, #opcd, ((double(a) opab double(b))opbc double(c))opcd double(d))

   #define ___CALC1(a, b, c, d, opab, opbc, opcd) Node(1, a, b, c, d, #opab, #opbc, #opcd, (double(a) opab(double(b) opbc double(c)))opcd double(d))

   #define ___CALC2(a, b, c, d, opab, opbc, opcd) Node(2, a, b, c, d, #opab, #opbc, #opcd, double(a) opab((double(b) opbc double(c))opcd double(d)))

   #define ___CALC3(a, b, c, d, opab, opbc, opcd) Node(3, a, b, c, d, #opab, #opbc, #opcd, double(a) opab(double(b) opbc(double(c) opcd double(d))))

   #define ___CALC4(a, b, c, d, opab, opbc, opcd) Node(4, a, b, c, d, #opab, #opbc, #opcd, ((double(a) opab double(b))opbc(double(c) opcd double(d))))

   #define ___CALC(a, b, c, d, opab, opbc, opcd) ___CALC0(a, b, c, d, opab, opbc, opcd), ___CALC1(a, b, c, d, opab, opbc, opcd), ___CALC2(a, b, c, d, opab, opbc, opcd), ___CALC3(a, b, c, d, opab, opbc, opcd), ___CALC4(a, b, c, d, opab, opbc, opcd)

   // use this
   #define __CALC(...) ___CALC(__VA_ARGS__)
   ```

     </details>

接下来就是把这三部分拼接起来就好了

定义个结构体 `Node` 存 hash 和 运算结果, 去重用 `std::set<Node>` 即可

- Q1: 为什么变长参数宏定义使用了 C 风格的 `__VA_ARGS__`

- A1: 因为这样能实现的功能多

  比如 `g++` 对 `#define EXPAND(args...) ##args` 会报错, 而 `#define EXPAND(...) __VA_ARGS__` 不会

- Q2: 为什么不把去重和 hash 也宏定义化?

- A2: 两个原因
  - 用了这些宏定义之后, 代码就已经 17 KB 了, 已经能交了
  - 不同编译器对宏定义的支持程度不同, 因此宏定义不一定是图灵完备的, 比如我这边的 `gcc` 不支持宏定义递归, 所以无法实现纯宏定义的循环

另外, 由于代码中一定要用到列表初始化来构造容器, 所以不能在一次构造中塞太多元素, 否则会让编译时间大幅增加甚至让编译器爆栈 ~~从而得到一个没有编译信息的 CE 记录~~

这也就是为什么我代码里向 `std::set` 加元素是分了 24 次 `merge`, 而不是一步到位, 直接将 7680 个元素一起塞进去

而且即使是这样, 洛谷的编译器也会炸掉, 所以只能将全排列枚举部分换成 `std::next_permutation`

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa lang:cpp Luogu/2277/0.cpp %}

</details>
