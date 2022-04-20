---
title: '题解 - [POJ 1528 等] Perfection'
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - POJ
  - ZOJ
  - UVa
  - 模拟
date: 2020-07-27 22:55:48
---
题目链接

- [POJ 1528](https://vjudge.net/problem/POJ-1528/origin)
- [ZOJ 1284](https://vjudge.net/problem/ZOJ-1284/origin)
- [UVA 382](https://vjudge.net/problem/UVA-382/origin)

<!-- more -->

## 原始题面

### Description

From the article Number Theory in the 1994 Microsoft Encarta: ``If $a, b, c$ are integers such that $a = bc$, $a$ is called a multiple of $b$ or of $c$, and $b$ or $c$ is called $a$ divisor or factor of $a$. If c is not $1$/$-1$, $b$ is called a proper divisor of $a$. Even integers, which include $0$, are multiples of $2$, for example, $-4, 0, 2, 10$; an odd integer is an integer that is not even, for example, $-5, 1, 3, 9$. A perfect number is a positive integer that is equal to the sum of all its positive, proper divisors; for example, $6$, which equals $1 + 2 + 3$, and $28$, which equals $1 + 2 + 4 + 7 + 14$, are perfect numbers. A positive number that is not perfect is imperfect and is deficient or abundant according to whether the sum of its positive, proper divisors is smaller or larger than the number itself. Thus, $9$, with proper divisors $1, 3$, is deficient; $12$, with proper divisors $1, 2, 3, 4, 6$, is abundant."

Given a number, determine if it is perfect, abundant, or deficient

### Input

A list of $N$ positive integers (none greater than $60,000$), with $1 <= N < 100$. A $0$ will mark the end of the list

### Output

The first line of output should read PERFECTION OUTPUT. The next $N$ lines of output should list for each input integer whether it is perfect, deficient, or abundant, as shown in the example below. Format counts: the echoed integers should be right justified within the first $5$ spaces of the output line, followed by two blank spaces, followed by the description of the integer. The final line of output should read END OF OUTPUT

### Sample Input

```input1
15 28 6 56 60000 22 496 0
```

### Sample Output

```output1
PERFECTION OUTPUT
   15  DEFICIENT
   28  PERFECT
    6  PERFECT
   56  ABUNDANT
60000  ABUNDANT
   22  DEFICIENT
  496  PERFECT
END OF OUTPUT
```

### Source

Mid-Atlantic 1996

## 题意简述

给一组数, 判断是完全(因子和为自身的二倍)的, 充裕(因子和大于自身的二倍)的, 还是不足(因子和小于自身的二倍)的

## 解题思路

直接做就行

写题解是因为突然想到了一个有意思的操作

## 代码参考

<details>
<summary><font color='orange'>Show code</font></summary>

```cpp
/*
 * @Author: Tifa
 * @LastEditTime: 2020-07-27 22:55:48
 * @Description: POJ 1528, ZOJ 1284, UVA 382
 */
const char status[][15] = {"DEFICIENT", "PERFECT", "ABUNDANT"};
int main() {
  puts("PERFECTION OUTPUT");
  int n;
  while (scanf("%d", &n) && n) {
    if (n == 1) {
      puts("    1  DEFICIENT");
      continue;
    }
    int cnt = 1;
    for (int i = 2; i <= sqrt(n + 0.5); ++i)
      if (n % i == 0) {
        cnt += i;
        if (i != n / i) cnt += n / i;
      }
    // look here
    printf("%5d  %s\n", n, status[(n < cnt) + (n <= cnt)]);
  }
  puts("END OF OUTPUT");
}
```

</details>
