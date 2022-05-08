---
title: 模板 - 光速幂
categories:
  - 程序设计
  - 模板
tags:
  - 程序设计
  - 模板
  - 数学
  - 光速幂
date: 2021-10-24 20:34:44
---

光速幂是一种针对固定底数和模数的高速求幂算法, 其基本思路和 BSGS 相同

<!-- more -->

基本思路和 BSGS 相同, 就是分成两块 $y=a\lfloor\sqrt p\rfloor+b$ 然后就有
$$x^y=\left(x^{\lfloor\sqrt p\rfloor}\right)^a+x^b$$

当然也可以分成长度为 256 的四个块来卡 cache

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp rpow/rpow.hpp %}

</details>
