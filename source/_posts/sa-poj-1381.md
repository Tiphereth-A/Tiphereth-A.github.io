---
title: '题解 - [POJ 1381 等] Secret Code'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - POJ
  - ZOJ
  - 数学
  - 复数
  - Gauss整数
date: 2020-07-27 22:58:52
---
题目链接

- [POJ 1381](https://vjudge.net/problem/POJ-1381/origin)
- [ZOJ 2011](https://vjudge.net/problem/ZOJ-2011/origin)

<!-- more -->

## 原始题面

### Description

The Sarcophagus itself is locked by a secret numerical code. When somebody wants to open it, he must know the code and set it exactly on the top of the Sarcophagus. A very intricate mechanism then opens the cover. If an incorrect code is entered, the tickets inside would catch fire immediately and they would have been lost forever. The code (consisting of up to $100$ integers) was hidden in the Alexandrian Library but unfortunately, as you probably know, the library burned down completely

But an almost unknown archaeologist has obtained a copy of the code something during the 18th century. He was afraid that the code could get to the ``wrong people'' so he has encoded the numbers in a very special way. He took a random complex number B that was greater (in absolute value) than any of the encoded numbers. Then he counted the numbers as the digits of the system with basis $B$. That means the sequence of numbers $a_n, a_{n-1}, ..., a_1, a_0$ was encoded as the number $X = a_0 + a_1B + a_2B^2 + ...+ a_nB^n$

Your goal is to decrypt the secret code, i.e. to express a given number $X$ in the number system to the base B. In other words, given the numbers $X$ and Byou are to determine the ``digit'' $a_0$ through $a_n$

### Input

The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case consists of one single line containing four integer numbers $X_r, X_i, B_r, B_i$ ($|X_r|,|X_i| <= 1000000, |B_r|,|B_i| <= 16$). These numbers indicate the real and complex components of numbers $X$ and $B$, i.e. $X = X_r + iX_i, B = B_r + iB_i$. B is the basis of the system ($|B| > 1$), $X$ is the number you have to express

### Output

Your program must output a single line for each test case. The line should contain the ``digits'' $a_n, a_{n-1}, ..., a_1, a_0$, separated by commas. The following conditions must be satisfied:

- $0 \leqslant ai < |B|, i=0,1,...,n$
- $X = a_0 + a_1B + a_2B^2 + ...+ a_nB^n$
- $n > 0\implies a_n \ne 0$
- $n \leqslant 100$

If there are no numbers meeting these criteria, output the sentence "The code cannot be decrypted.". If there are more possibilities:For the uniqueness of the answer,only print the one with smallest lexicographical order. For example, if the two sets are `(4, 3, 18, 9)` and `(7, 1, 14, 8)`, then just output the first since its has smaller lexicographical order

### Sample Input

```input1
4
-935 2475 -11 -15
1 0 -3 -2
93 16 3 2
191 -192 11 -12
```

### Sample Output

```output1
8,11,18
1
The code cannot be decrypted.
16,15
```

### Source

Central Europe 1999

## 题意简述

给出Gauss整数$X$和$B$, 求是否存在一组数$\def\enum#1{a_{ #1}}\enum{1},\enum{2},...,\enum{n}$满足

- $0 \leqslant ai < |B|, i=0,1,...,n$
- $X = a_0 + a_1B + a_2B^2 + ...+ a_nB^n$
- $n > 0\implies a_n \ne 0$
- $n \leqslant 100$

## 解题思路

$X = a_0 + a_1B + a_2B^2 + ...+ a_nB^n\implies B\mid(X-a_0)$

而$|B|$很小, 故可以考虑枚举$a_0$

接下来便可$X\leftarrow\displaystyle{X-a_0\over B}$, 递归枚举$a_1$,..., 直到$X$为$0$或递归层数过深

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-27 20:48:42
 * @Description: POJ 138, ZOJ 2011
 */
const int N = 1005;
struct Complex {
  int re, im;
};
int ans[N];

int main() {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    Complex x, b;
    scanf("%d%d%d%d", &x.re, &x.im, &b.re, &b.im);
    int len_b = b.re * b.re + b.im * b.im;
    int cnt_ans = 0;
    do {
      bool f = 0;
      for (int a = 0, re, im; a < sqrt(len_b + 1e-8); ++a) {
        re = (x.re - a) * b.re - x.im * (-b.im);
        im = (x.re - a) * (-b.im) + x.im * b.re;
        if (re % len_b == 0 && im % len_b == 0) {
          x.re = re / len_b;
          x.im = im / len_b;
          ans[++cnt_ans] = a;
          f = 1;
          break;
        }
      }
      if (!f || cnt_ans >= 100) break;
    } while (x.re || x.im);
    if (x.re || x.im) puts("The code cannot be decrypted.");
    else {
      printf("%d", ans[cnt_ans]);
      for (int i = cnt_ans - 1; i; --i) printf(",%d", ans[i]);
      puts("");
    }
  }
}
```

</details>