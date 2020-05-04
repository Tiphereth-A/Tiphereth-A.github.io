---
title: 随笔 - C 语言的泛型
categories:
  - 随笔
  - C
tags:
  - C
  - 随笔
  - 宏
  - 泛型
date: 2020-06-17 09:22:53
---

简要介绍 C11 之前和之后的泛型写法

<!-- more -->

## C11 之前

利用宏实现

```c

#define min(x, y) ({                   \
    typeof(x) _min_1 = (x);            \
    typeof(y) _min_2 = (y);            \
    (void)(&_min_1 == &_min_2);        \
    _min_1 < _min_2 ? _min_1 : _min_2; \
  })
```

其中`(void)(&_min_1 == &_min_2);`利用了不同类型指针做逻辑比较在编译过程会报错来保证两参数类型相同

## C11 之后

C11 中添加了`_Generic`关键字, 使得编写泛型函数更方便了

用法[^1]:

> generic-selection:
>
> `_Generic ( assignment-expression , generic-assoc-list )`
>
> generic-assoc-list:
>
> > generic-association
> >
> > generic-assoc-list , generic-association
>
> generic-association:
>
> > type-name : assignment-expression
> >
> > `default` : assignment-expression

例如[^2]:

```c

#include <math.h>

#include <stdio.h>

#define GENERAL_ABS(x) _Generic((x), \
    int    : abs,                    \
    float  : fabsf,                  \
    double : fabs)(x)

int main(void) {
  printf("intabs:%d\n", GENERAL_ABS(-12));
  printf("floatabs:%f\n", GENERAL_ABS(-12.04f));
  printf("doubleabs:%f\n", GENERAL_ABS(-13.09876));

  int a = 10;
  int b = 0, c = 0;

  _Generic(a + 0.1f, int : b, float : c, default : b)++;
  printf("b=%d,c=%d\n", b, c);

  _Generic(a += 1.1f, int : b, float : c, default : b)++;
  printf("a=%d,b=%d,c=%d\n", a, b, c);
}
```

输出:

```text
intabs:12
floatabs:12.040000
doubleabs:13.098760
b=0,c=1
a=10,b=1,c=1
```

简要讲讲代码的含义

`_Generic(a + 0.1f, int : b, float : c, default : b)++;`

a 为`int`, `a + 0.1f`为`float`, 所以`_Generic`执行`float`对应的操作, 即返回`c`, 最终该语句为`c++`

`_Generic(a += 1.1f, int : b, float : c, default : b)++;`

a 为`int`, `a += 1.1f`**不改变`a`的值**, `_Generic`判断`a`的类型, 执行`int`对应的操作, 即返回`b`, 最终该语句为`b++`

[^1]: [ISO/IEC 9899:201x - N1570 - Programming languages - C](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf)
[^2]: [C11\_百度百科](https://baike.baidu.com/item/C11)
