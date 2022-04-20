---
title: '题解 - [Luogu P2277] [HNOI2003]24点游戏'
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

为了培养小孩的计算能力, 大人们经常给小孩玩这样的游戏：从1付扑克牌中任意抽出4张扑克, 要小孩用 "+", "-", "*", " /"和括号组成一个合法的表达式, 并使表达式的值为24点. 这种游戏就是所谓的"24点游戏"

请你编程求出对于给出的任意4个正整数 a, b, c, d, 请你编程求出这4个整数能组成多少个值为24的不同表达式

### 输入输出格式

#### 输入格式

输入文件名：input.txt

输入文件共一行, 为4个正整数a, b, c, d. (0<=a,b,c,d<=100)

#### 输出格式

输出文件名：output.txt

输出文件为由a, b, c, d组成的值为24表达式个数, 如没有, 输出0

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

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2021-11-05 01:01:36
 * @Description: Luogu P2277, macro
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

#define _RM3(_1, _2, _3, ...) __VA_ARGS__
#define RM3(...) _RM3(__VA_ARGS__)
#define _RM4(_1, _2, _3, _4, ...) __VA_ARGS__
#define RM4(...) _RM4(__VA_ARGS__)

#define _SEL3(_1, _2, _3, ...) _1, _2, _3
#define SEL3(...) _SEL3(__VA_ARGS__)
#define _SEL4(_1, _2, _3, _4, ...) _1, _2, _3, _4
#define SEL4(...) _SEL4(__VA_ARGS__)

#define _CPROD1_4_HELPER(a, b, c, d, ...) a, __VA_ARGS__, b, __VA_ARGS__, c, __VA_ARGS__, d, __VA_ARGS__
#define _CPROD2_4_HELPER(a, b, c, d, ...) _CPROD1_4_HELPER(a, b, c, d, a, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, b, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, c, __VA_ARGS__), _CPROD1_4_HELPER(a, b, c, d, d, __VA_ARGS__)
#define CPROD3_4(a, b, c, d) _CPROD2_4_HELPER(a, b, c, d, a), _CPROD2_4_HELPER(a, b, c, d, b), _CPROD2_4_HELPER(a, b, c, d, c), _CPROD2_4_HELPER(a, b, c, d, d)

#define _RM_1(func, ...) func(__VA_ARGS__)
#define _RM_2(func, ...) _RM_1(func, _RM_1(func, __VA_ARGS__))
#define _RM_3(func, ...) _RM_2(func, _RM_1(func, __VA_ARGS__))
#define _RM_4(func, ...) _RM_2(func, _RM_2(func, __VA_ARGS__))
#define _RM_5(func, ...) _RM_4(func, _RM_1(func, __VA_ARGS__))
#define _RM_6(func, ...) _RM_4(func, _RM_2(func, __VA_ARGS__))
#define _RM_7(func, ...) _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))
#define _RM_8(func, ...) _RM_4(func, _RM_4(func, __VA_ARGS__))
#define _RM_9(func, ...) _RM_8(func, _RM_1(func, __VA_ARGS__))
#define _RM_10(func, ...) _RM_8(func, _RM_2(func, __VA_ARGS__))
#define _RM_11(func, ...) _RM_8(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))
#define _RM_12(func, ...) _RM_8(func, _RM_4(func, __VA_ARGS__))
#define _RM_13(func, ...) _RM_8(func, _RM_4(func, _RM_1(func, __VA_ARGS__)))
#define _RM_14(func, ...) _RM_8(func, _RM_4(func, _RM_2(func, __VA_ARGS__)))
#define _RM_15(func, ...) _RM_8(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))
#define _RM_16(func, ...) _RM_8(func, _RM_8(func, __VA_ARGS__))
#define _RM_17(func, ...) _RM_16(func, _RM_1(func, __VA_ARGS__))
#define _RM_18(func, ...) _RM_16(func, _RM_2(func, __VA_ARGS__))
#define _RM_19(func, ...) _RM_16(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))
#define _RM_20(func, ...) _RM_16(func, _RM_4(func, __VA_ARGS__))
#define _RM_21(func, ...) _RM_16(func, _RM_4(func, _RM_1(func, __VA_ARGS__)))
#define _RM_22(func, ...) _RM_16(func, _RM_4(func, _RM_2(func, __VA_ARGS__)))
#define _RM_23(func, ...) _RM_16(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))
#define _RM_24(func, ...) _RM_16(func, _RM_8(func, __VA_ARGS__))
#define _RM_25(func, ...) _RM_16(func, _RM_8(func, _RM_1(func, __VA_ARGS__)))
#define _RM_26(func, ...) _RM_16(func, _RM_8(func, _RM_2(func, __VA_ARGS__)))
#define _RM_27(func, ...) _RM_16(func, _RM_8(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))
#define _RM_28(func, ...) _RM_16(func, _RM_8(func, _RM_4(func, __VA_ARGS__)))
#define _RM_29(func, ...) _RM_16(func, _RM_8(func, _RM_4(func, _RM_1(func, __VA_ARGS__))))
#define _RM_30(func, ...) _RM_16(func, _RM_8(func, _RM_4(func, _RM_2(func, __VA_ARGS__))))
#define _RM_31(func, ...) _RM_16(func, _RM_8(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))))
#define _RM_32(func, ...) _RM_16(func, _RM_16(func, __VA_ARGS__))
#define _RM_33(func, ...) _RM_32(func, _RM_1(func, __VA_ARGS__))
#define _RM_34(func, ...) _RM_32(func, _RM_2(func, __VA_ARGS__))
#define _RM_35(func, ...) _RM_32(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))
#define _RM_36(func, ...) _RM_32(func, _RM_4(func, __VA_ARGS__))
#define _RM_37(func, ...) _RM_32(func, _RM_4(func, _RM_1(func, __VA_ARGS__)))
#define _RM_38(func, ...) _RM_32(func, _RM_4(func, _RM_2(func, __VA_ARGS__)))
#define _RM_39(func, ...) _RM_32(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))
#define _RM_40(func, ...) _RM_32(func, _RM_8(func, __VA_ARGS__))
#define _RM_41(func, ...) _RM_32(func, _RM_8(func, _RM_1(func, __VA_ARGS__)))
#define _RM_42(func, ...) _RM_32(func, _RM_8(func, _RM_2(func, __VA_ARGS__)))
#define _RM_43(func, ...) _RM_32(func, _RM_8(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))
#define _RM_44(func, ...) _RM_32(func, _RM_8(func, _RM_4(func, __VA_ARGS__)))
#define _RM_45(func, ...) _RM_32(func, _RM_8(func, _RM_4(func, _RM_1(func, __VA_ARGS__))))
#define _RM_46(func, ...) _RM_32(func, _RM_8(func, _RM_4(func, _RM_2(func, __VA_ARGS__))))
#define _RM_47(func, ...) _RM_32(func, _RM_8(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))))
#define _RM_48(func, ...) _RM_32(func, _RM_16(func, __VA_ARGS__))
#define _RM_49(func, ...) _RM_32(func, _RM_16(func, _RM_1(func, __VA_ARGS__)))
#define _RM_50(func, ...) _RM_32(func, _RM_16(func, _RM_2(func, __VA_ARGS__)))
#define _RM_51(func, ...) _RM_32(func, _RM_16(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))
#define _RM_52(func, ...) _RM_32(func, _RM_16(func, _RM_4(func, __VA_ARGS__)))
#define _RM_53(func, ...) _RM_32(func, _RM_16(func, _RM_4(func, _RM_1(func, __VA_ARGS__))))
#define _RM_54(func, ...) _RM_32(func, _RM_16(func, _RM_4(func, _RM_2(func, __VA_ARGS__))))
#define _RM_55(func, ...) _RM_32(func, _RM_16(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))))
#define _RM_56(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, __VA_ARGS__)))
#define _RM_57(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_1(func, __VA_ARGS__))))
#define _RM_58(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_2(func, __VA_ARGS__))))
#define _RM_59(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_2(func, _RM_1(func, __VA_ARGS__)))))
#define _RM_60(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_4(func, __VA_ARGS__))))
#define _RM_61(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_4(func, _RM_1(func, __VA_ARGS__)))))
#define _RM_62(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_4(func, _RM_2(func, __VA_ARGS__)))))
#define _RM_63(func, ...) _RM_32(func, _RM_16(func, _RM_8(func, _RM_4(func, _RM_2(func, _RM_1(func, __VA_ARGS__))))))
#define RMAB(a, b, ...) _RM_##b(RM##a, __VA_ARGS__)

#define OPANDS CPROD3_4(+, -, *, /)

#define OPS0 SEL3(OPANDS)
#define OPS1 SEL3(RMAB(3, 1, OPANDS))
#define OPS2 SEL3(RMAB(3, 2, OPANDS))
#define OPS3 SEL3(RMAB(3, 3, OPANDS))
#define OPS4 SEL3(RMAB(3, 4, OPANDS))
#define OPS5 SEL3(RMAB(3, 5, OPANDS))
#define OPS6 SEL3(RMAB(3, 6, OPANDS))
#define OPS7 SEL3(RMAB(3, 7, OPANDS))
#define OPS8 SEL3(RMAB(3, 8, OPANDS))
#define OPS9 SEL3(RMAB(3, 9, OPANDS))
#define OPS10 SEL3(RMAB(3, 10, OPANDS))
#define OPS11 SEL3(RMAB(3, 11, OPANDS))
#define OPS12 SEL3(RMAB(3, 12, OPANDS))
#define OPS13 SEL3(RMAB(3, 13, OPANDS))
#define OPS14 SEL3(RMAB(3, 14, OPANDS))
#define OPS15 SEL3(RMAB(3, 15, OPANDS))
#define OPS16 SEL3(RMAB(3, 16, OPANDS))
#define OPS17 SEL3(RMAB(3, 17, OPANDS))
#define OPS18 SEL3(RMAB(3, 18, OPANDS))
#define OPS19 SEL3(RMAB(3, 19, OPANDS))
#define OPS20 SEL3(RMAB(3, 20, OPANDS))
#define OPS21 SEL3(RMAB(3, 21, OPANDS))
#define OPS22 SEL3(RMAB(3, 22, OPANDS))
#define OPS23 SEL3(RMAB(3, 23, OPANDS))
#define OPS24 SEL3(RMAB(3, 24, OPANDS))
#define OPS25 SEL3(RMAB(3, 25, OPANDS))
#define OPS26 SEL3(RMAB(3, 26, OPANDS))
#define OPS27 SEL3(RMAB(3, 27, OPANDS))
#define OPS28 SEL3(RMAB(3, 28, OPANDS))
#define OPS29 SEL3(RMAB(3, 29, OPANDS))
#define OPS30 SEL3(RMAB(3, 30, OPANDS))
#define OPS31 SEL3(RMAB(3, 31, OPANDS))
#define OPS32 SEL3(RMAB(3, 32, OPANDS))
#define OPS33 SEL3(RMAB(3, 33, OPANDS))
#define OPS34 SEL3(RMAB(3, 34, OPANDS))
#define OPS35 SEL3(RMAB(3, 35, OPANDS))
#define OPS36 SEL3(RMAB(3, 36, OPANDS))
#define OPS37 SEL3(RMAB(3, 37, OPANDS))
#define OPS38 SEL3(RMAB(3, 38, OPANDS))
#define OPS39 SEL3(RMAB(3, 39, OPANDS))
#define OPS40 SEL3(RMAB(3, 40, OPANDS))
#define OPS41 SEL3(RMAB(3, 41, OPANDS))
#define OPS42 SEL3(RMAB(3, 42, OPANDS))
#define OPS43 SEL3(RMAB(3, 43, OPANDS))
#define OPS44 SEL3(RMAB(3, 44, OPANDS))
#define OPS45 SEL3(RMAB(3, 45, OPANDS))
#define OPS46 SEL3(RMAB(3, 46, OPANDS))
#define OPS47 SEL3(RMAB(3, 47, OPANDS))
#define OPS48 SEL3(RMAB(3, 48, OPANDS))
#define OPS49 SEL3(RMAB(3, 49, OPANDS))
#define OPS50 SEL3(RMAB(3, 50, OPANDS))
#define OPS51 SEL3(RMAB(3, 51, OPANDS))
#define OPS52 SEL3(RMAB(3, 52, OPANDS))
#define OPS53 SEL3(RMAB(3, 53, OPANDS))
#define OPS54 SEL3(RMAB(3, 54, OPANDS))
#define OPS55 SEL3(RMAB(3, 55, OPANDS))
#define OPS56 SEL3(RMAB(3, 56, OPANDS))
#define OPS57 SEL3(RMAB(3, 57, OPANDS))
#define OPS58 SEL3(RMAB(3, 58, OPANDS))
#define OPS59 SEL3(RMAB(3, 59, OPANDS))
#define OPS60 SEL3(RMAB(3, 60, OPANDS))
#define OPS61 SEL3(RMAB(3, 61, OPANDS))
#define OPS62 SEL3(RMAB(3, 62, OPANDS))
#define OPS63 RMAB(3, 63, OPANDS)

#define ___CALC0(a, b, c, d, opab, opbc, opcd) Node(0, a, b, c, d, #opab, #opbc, #opcd, ((double(a) opab double(b))opbc double(c))opcd double(d))
#define ___CALC1(a, b, c, d, opab, opbc, opcd) Node(1, a, b, c, d, #opab, #opbc, #opcd, (double(a) opab(double(b) opbc double(c)))opcd double(d))
#define ___CALC2(a, b, c, d, opab, opbc, opcd) Node(2, a, b, c, d, #opab, #opbc, #opcd, double(a) opab((double(b) opbc double(c))opcd double(d)))
#define ___CALC3(a, b, c, d, opab, opbc, opcd) Node(3, a, b, c, d, #opab, #opbc, #opcd, double(a) opab(double(b) opbc(double(c) opcd double(d))))
#define ___CALC4(a, b, c, d, opab, opbc, opcd) Node(4, a, b, c, d, #opab, #opbc, #opcd, ((double(a) opab double(b))opbc(double(c) opcd double(d))))

#define ___CALC(a, b, c, d, opab, opbc, opcd) ___CALC0(a, b, c, d, opab, opbc, opcd), ___CALC1(a, b, c, d, opab, opbc, opcd), ___CALC2(a, b, c, d, opab, opbc, opcd), ___CALC3(a, b, c, d, opab, opbc, opcd), ___CALC4(a, b, c, d, opab, opbc, opcd)
#define __CALC(...) ___CALC(__VA_ARGS__)

#define _CALC(a, b, c, d) __CALC(a, b, c, d, OPS0), __CALC(a, b, c, d, OPS1), __CALC(a, b, c, d, OPS2), __CALC(a, b, c, d, OPS3), __CALC(a, b, c, d, OPS4), __CALC(a, b, c, d, OPS5), __CALC(a, b, c, d, OPS6), __CALC(a, b, c, d, OPS7), __CALC(a, b, c, d, OPS8), __CALC(a, b, c, d, OPS9), __CALC(a, b, c, d, OPS10), __CALC(a, b, c, d, OPS11), __CALC(a, b, c, d, OPS12), __CALC(a, b, c, d, OPS13), __CALC(a, b, c, d, OPS14), __CALC(a, b, c, d, OPS15), __CALC(a, b, c, d, OPS16), __CALC(a, b, c, d, OPS17), __CALC(a, b, c, d, OPS18), __CALC(a, b, c, d, OPS19), __CALC(a, b, c, d, OPS20), __CALC(a, b, c, d, OPS21), __CALC(a, b, c, d, OPS22), __CALC(a, b, c, d, OPS23), __CALC(a, b, c, d, OPS24), __CALC(a, b, c, d, OPS25), __CALC(a, b, c, d, OPS26), __CALC(a, b, c, d, OPS27), __CALC(a, b, c, d, OPS28), __CALC(a, b, c, d, OPS29), __CALC(a, b, c, d, OPS30), __CALC(a, b, c, d, OPS31), __CALC(a, b, c, d, OPS32), __CALC(a, b, c, d, OPS33), __CALC(a, b, c, d, OPS34), __CALC(a, b, c, d, OPS35), __CALC(a, b, c, d, OPS36), __CALC(a, b, c, d, OPS37), __CALC(a, b, c, d, OPS38), __CALC(a, b, c, d, OPS39), __CALC(a, b, c, d, OPS40), __CALC(a, b, c, d, OPS41), __CALC(a, b, c, d, OPS42), __CALC(a, b, c, d, OPS43), __CALC(a, b, c, d, OPS44), __CALC(a, b, c, d, OPS45), __CALC(a, b, c, d, OPS46), __CALC(a, b, c, d, OPS47), __CALC(a, b, c, d, OPS48), __CALC(a, b, c, d, OPS49), __CALC(a, b, c, d, OPS50), __CALC(a, b, c, d, OPS51), __CALC(a, b, c, d, OPS52), __CALC(a, b, c, d, OPS53), __CALC(a, b, c, d, OPS54), __CALC(a, b, c, d, OPS55), __CALC(a, b, c, d, OPS56), __CALC(a, b, c, d, OPS57), __CALC(a, b, c, d, OPS58), __CALC(a, b, c, d, OPS59), __CALC(a, b, c, d, OPS60), __CALC(a, b, c, d, OPS61), __CALC(a, b, c, d, OPS62), __CALC(a, b, c, d, OPS63),
#define CALC(...) _CALC(__VA_ARGS__)

#define _P2_HELPER(a, b, ...) a, b, __VA_ARGS__, b, a, __VA_ARGS__
#define _P3_HELPER(a, b, c, ...) _P2_HELPER(a, b, c, __VA_ARGS__), _P2_HELPER(b, c, a, __VA_ARGS__), _P2_HELPER(c, a, b, __VA_ARGS__)
#define P4 _P3_HELPER(a, b, c, d), _P3_HELPER(b, c, d, a), _P3_HELPER(c, d, a, b), _P3_HELPER(d, a, b, c)

#define PERM0 SEL4(P4)
#define PERM1 SEL4(RMAB(4, 1, P4))
#define PERM2 SEL4(RMAB(4, 2, P4))
#define PERM3 SEL4(RMAB(4, 3, P4))
#define PERM4 SEL4(RMAB(4, 4, P4))
#define PERM5 SEL4(RMAB(4, 5, P4))
#define PERM6 SEL4(RMAB(4, 6, P4))
#define PERM7 SEL4(RMAB(4, 7, P4))
#define PERM8 SEL4(RMAB(4, 8, P4))
#define PERM9 SEL4(RMAB(4, 9, P4))
#define PERM10 SEL4(RMAB(4, 10, P4))
#define PERM11 SEL4(RMAB(4, 11, P4))
#define PERM12 SEL4(RMAB(4, 12, P4))
#define PERM13 SEL4(RMAB(4, 13, P4))
#define PERM14 SEL4(RMAB(4, 14, P4))
#define PERM15 SEL4(RMAB(4, 15, P4))
#define PERM16 SEL4(RMAB(4, 16, P4))
#define PERM17 SEL4(RMAB(4, 17, P4))
#define PERM18 SEL4(RMAB(4, 18, P4))
#define PERM19 SEL4(RMAB(4, 19, P4))
#define PERM20 SEL4(RMAB(4, 20, P4))
#define PERM21 SEL4(RMAB(4, 21, P4))
#define PERM22 SEL4(RMAB(4, 22, P4))
#define PERM23 RMAB(4, 23, P4)

#define MERGE                           \
    s.merge(decltype(s){CALC(PERM0)});  \
    s.merge(decltype(s){CALC(PERM1)});  \
    s.merge(decltype(s){CALC(PERM2)});  \
    s.merge(decltype(s){CALC(PERM3)});  \
    s.merge(decltype(s){CALC(PERM4)});  \
    s.merge(decltype(s){CALC(PERM5)});  \
    s.merge(decltype(s){CALC(PERM6)});  \
    s.merge(decltype(s){CALC(PERM7)});  \
    s.merge(decltype(s){CALC(PERM8)});  \
    s.merge(decltype(s){CALC(PERM9)});  \
    s.merge(decltype(s){CALC(PERM10)}); \
    s.merge(decltype(s){CALC(PERM11)}); \
    s.merge(decltype(s){CALC(PERM12)}); \
    s.merge(decltype(s){CALC(PERM13)}); \
    s.merge(decltype(s){CALC(PERM14)}); \
    s.merge(decltype(s){CALC(PERM15)}); \
    s.merge(decltype(s){CALC(PERM16)}); \
    s.merge(decltype(s){CALC(PERM17)}); \
    s.merge(decltype(s){CALC(PERM18)}); \
    s.merge(decltype(s){CALC(PERM19)}); \
    s.merge(decltype(s){CALC(PERM20)}); \
    s.merge(decltype(s){CALC(PERM21)}); \
    s.merge(decltype(s){CALC(PERM22)}); \
    s.merge(decltype(s){CALC(PERM23)})

int dict[256];
const auto _STATIC_ = []() {
    dict['+'] = 0;
    dict['-'] = 1;
    dict['*'] = 2;
    dict['/'] = 3;
    return 0;
}();

struct Node {
    u64 hash;
    double data;

    Node(const int& type,
         i64 a,
         i64 b,
         i64 c,
         i64 d,
         const char* opab,
         const char* opbc,
         const char* opcd,
         const double& _data) : data(_data) {
        // 0 -> (((a b) c) d)
        // 1 -> ((a (b c)) d)
        // 2 -> (a ((b c) d))
        // 3 -> (a (b (c d)))
        // 4 -> ((a b) (c d))
        switch (type) {
            case 0: break;
            case 1:
                if (!valid(dict[*opab], dict[*opbc])) data = 0;
                break;
            case 2:
                if (!valid(dict[*opab], dict[*opcd])) data = 0;
                break;
            case 3:
                if (!valid(dict[*opab], dict[*opbc]) || !valid(dict[*opbc], dict[*opcd])) data = 0;
                break;
            case 4:
                if (!valid(dict[*opbc], dict[*opcd])) data = 0;
                break;
        }
        hash = 0;
        (hash += a) <<= 7;
        (hash += b) <<= 7;
        (hash += c) <<= 7;
        (hash += d) <<= 2;
        (hash += dict[*opab]) <<= 2;
        (hash += dict[*opbc]) <<= 2;
        (hash += dict[*opcd]) <<= 3;
        hash += type;
    }

    inline constexpr bool valid(const int& a, const int& b) const {
        if (a == 0) return b > 1;
        if (a == 2) return b < 2;
        return true;
    }

    bool operator<(const Node& rhs) const { return hash < rhs.hash; }
};

// for debug
inline void decode(u64 hash) {
#define _decode(val, n) val = hash & ((1 << n) - 1); hash >>= n

    static const char _[] = "+-*/";
    int type, a, b, c, d, opab, opbc, opcd;

    _decode(type, 3);
    _decode(opcd, 2);
    _decode(opbc, 2);
    _decode(opab, 2);
    _decode(d, 7);
    _decode(c, 7);
    _decode(b, 7);
    _decode(a, 7);

    switch (type) {
        case 0: cerr << "(((" << a << " " << _[opab] << " " << b << ") " << _[opbc] << " " << c << ") " << _[opcd] << " " << d << ")" << endl; break;
        case 1: cerr << "((" << a << " " << _[opab] << " (" << b << " " << _[opbc] << " " << c << ")) " << _[opcd] << " " << d << ")" << endl; break;
        case 2: cerr << "(" << a << " " << _[opab] << " ((" << b << " " << _[opbc] << " " << c << ") " << _[opcd] << " " << d << "))" << endl; break;
        case 3: cerr << "(" << a << " " << _[opab] << " (" << b << " " << _[opbc] << " (" << c << " " << _[opcd] << " " << d << ")))" << endl; break;
        case 4: cerr << "((" << a << " " << _[opab] << " " << b << ") " << _[opbc] << " (" << c << " " << _[opcd] << " " << d << "))" << endl; break;
    }

#undef _decode
}

int main() {
    i64 a, b, c, d;
    set<Node> s;
    cin >> a >> b >> c >> d;

    vector<i64> v{a, b, c, d};
    sort(v.begin(), v.end());
    do {
        s.merge(decltype(s){CALC(v[0], v[1], v[2], v[3])});
    } while (next_permutation(v.begin(), v.end()));

    // or
    // MERGE;

    int cnt = 0;
    for (const auto& [hash, data] : s) if (abs(data - 24) <= 1e-7) ++cnt;
    cout << cnt;
    return 0;
}
```

</details>
