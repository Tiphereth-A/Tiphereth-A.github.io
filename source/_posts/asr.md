---
title: 笔记 - Simpson法与自适应Simpson法
categories:
  - 笔记
  - 算法竞赛
tags:
  - 数学
  - 算法竞赛
  - 模板
  - 数值积分
  - Simpson积分
  - 复化Simpson积分
  - 自适应Simpson积分
date: 2020-10-02 22:23:57
---

自适应 Simpson 法是一种基于 Simpson 法的数值积分算法

<!-- more -->

{% note warning %}
<https://cplib.tifa-233.com/src/code/math/simpson.hpp> 存放了笔者对该算法/数据结构的最新实现, 建议前往此处查看相关代码
{% endnote %}

## Simpson 法

Simpson 法是一种常见的数值积分算法, 其思想是用几段抛物线去拟合原曲线, 从而近似求出其面积

放一张从维基拿的图

![](1.webp)

其中 $f(x)$ 为原函数, $P(x)$ 为拟合函数

本篇内容如无特殊说明, 均有如下假定:

- $f(x)$ 在区间 $[a,b]$ 上任意阶可导 (其实没必要这么强, 只是懒得弱化了)

### 流程

1. 对一段区间 $[a,b]$, 取其中点 $m=\frac{a+b}{2}$
1. 设 $P(x)=Ax^2+Bx+C$
1. 令 $P(a)=f(a), P(m)=f(m), P(b)=f(b)$, 显然我们可以解出 $A,B,C$

   > 实际上, 我们有
   >
   > $$
   > P(x)=f(a)\frac{(x-m)(x-b)}{(a-m)(a-b)}+f(m)\frac{(x-a)(x-b)}{(m-a)(m-b)}+f(b)\frac{(x-a)(x-m)}{(b-a)(b-m)}
   > $$

1. 此时便可假定

   $$
   \int_a^bf(x)\mathrm{d}x\approx\int_a^bP(x)\mathrm{d}x=\frac{b-a}{6}(f(a)+4f(m)+f(b))
   $$

   令 $h=\frac{b-a}{2}$, 则有

   $$
   \int_a^bf(x)\approx\frac{h}{3}(f(a)+4f(m)+f(b))
   $$

### Q&A

- Q: 为什么要设这个 $h$

  A: 是因为 Simpson 法是 Newton–Cotes 积分法的特例, 因为不是重点, 这里就不展开讲了

  还有一个数值积分法叫 Simpson 3/8 法, 同样也是 Newton–Cotes 积分法的特例, 式子是这样的:

  $$
  \int_a^bf(x)\approx\frac{h}{8}(f(a)+3f(m_1)+3f(m_2)+f(b))
  $$

  其中 $h=\frac{b-a}{3}$, $m_1,m_2$ 是 $a,b$ 的三等分点

- Q: 此法误差如何

  A: 为 $-\frac{1}{90}(\frac{b-a}{2})^5f^{(4)}(\xi)$, $\xi\in[a,b]$, 证明略

## 复化 Simpson 法

就是把 $[a,b]$ 拆成多个等长小区间, 每个区间应用 Simpson 法后拼合在一起

放一张从维基拿的动图

![](2.webp)

这张动图展示了多次细分应用复化 Simpson 法的拟合效果

### 流程

令

- $h=\frac{b-a}{n}$
- $x_i=a+ih$, $i=0,1,...,n$
- $f_i=f(x_i)$

然后就有

$$
\int_a^bf(x)\mathrm{d}x\approx\frac{h}{3}\sum_{i=1}^\frac{n}{2}(f_{2i-2}+4f_{2i-1}+f_{2i})
$$

误差为 $-\frac{h^4}{180}(b-a)f^{(4)}(\xi)$, $\xi\in[a,b]$

## 自适应 Simpson 法

复化 Simpson 法是把 $[a,b]$ 拆成多个等长小区间, 然而在多数情况下, 有一些拆分是没有必要的. 比如如果 $f(x)$ 在 $[x_i,x_{i+2}]\in[a,b]$ 上已经能够得到较好的拟合效果了, 我们就没必要继续细分成 $[x_i,x_{i+1}]$ 和 $[x_{i+1},x_{i+2}]$ 了

自适应 Simpson 法就能根据函数性质来判断是否要继续细分, 所以其要比复化 Simpson 法快

### 流程

1. 取中点 $m=\frac{a+b}{2}$
1. 分别对区间 $[a,b]$, $[a,m]$, $[m,b]$ 应用 Simpson 法, 设得到的面积分别为 $S$, $S_l$, $S_r$
1. 若 $S$ 与 $S_l+S_r$ 足够接近, 则认为区间 $[a,b]$ 面积的近似值已经求得, 否则分别对区间 $[a,m]$, $[m,b]$ 递归应用本操作

### Q&A

- Q: 什么是足够接近

  A: 当 $|S-(S_l+S_r)|<15\epsilon$ 时认为足够接近

  $\epsilon$ 是根据具体需要设定的误差值, 注意**细分区间**时对应误差值要**减半**

- Q: $15$ 是怎么来的

  A: 是经过一系列误差分析得出的结果, 论文在参考区

### 代码

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp asr/asr.cpp %}

</details>

### 例题

- 洛谷 [P4207 [NOI2005]月下柠檬树](https://www.luogu.com.cn/problem/P4207)
- 洛谷 [P4526 【模板】自适应辛普森法 2](https://www.luogu.com.cn/problem/P4526) (想想怎么处理这个无穷积分)

---

## 参考

- <https://en.wikipedia.org/wiki/Simpson>'s_rule
- <https://en.wikipedia.org/wiki/Newton–Cotes_formulas>
- <https://en.wikipedia.org/wiki/Adaptive_Simpson>'s_method
- J N Lyness. Notes on the Adaptive Simpson Quadrature Routine[J]. Journal of the ACM, 1969, 16(3): 483–495; doi:[10.1145/321526.321537](https://doi.org/10.1145%2F321526.321537)
