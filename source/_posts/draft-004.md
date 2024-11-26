---
title: 随笔 - C 语言中的"操作符" "-->"
categories:
  - 随笔
  - C
tags:
  - C
  - 随笔
  - 操作符
date: 2020-06-22 09:33:45
---

在 <https://stackoverflow.com/questions/1642028/what-is-the-operator-in-c> 看到个好玩的东西

<!-- more -->

{% icodeweb blog lang:c draft-003/1.c %}

这段代码的输出是

```text
9 8 7 6 5 4 3 2 1 0
```

这里的`-->`看起来就像操作符一样

实际上`while (x --> 0)`的意义是`while ((x--) > 0)`

类似的, 我们还可以写出 `while (x ----> 0)` -> `8 6 4 2 0`

我们也可以一定程度上假装用 `C` 写 `Pascal` 程序

{% icodeweb blog lang:c draft-004/2.c %}
