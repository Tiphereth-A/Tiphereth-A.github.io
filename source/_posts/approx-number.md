---
title: "【洛谷日报#53】浅谈一些求近似值的方法"
categories:
  - 程序设计
  - 算法
tags:
  - 数学
  - 程序设计
  - 算法
  - 洛谷日报
  - 二分
  - 0.618法
  - Newton迭代法
  - Taylor级数
date: 2018-08-09 09:06:31
---

~~只是为了拿本子随便写的~~

老文章, 可能有很多错误, 懒得修了

<!--more-->

## 前言

对于低于 5 次的多项式方程, 我们有通用的公式解法求零点的精确值

对于一些特殊高次多项式方程 (例如可以因式分解的或者满足一些特定形式的方程) 的和一些特殊的超越方程, 我们也有方法求零点的精确值

但是其余的情况呢？

目前来说我们只能求近似值 QwQ (而且在实际应用中, 精确值往往也会被转换成近似值)

下面简要介绍几种方法

## 二分法

可以说相当常见了

对于**在区间$[l,r]$内单调、连续且有$f(l)\cdot f(r)<0$成立的$f(x)$**, 做如下操作:

1. 计算$mid=\displaystyle\frac{l+r}{2}$
1. 若$f(l)f(mid)<0$, 则令$r=mid$, 否则令$l=mid$
1. 如果达到预定精度, 跳转到 4, 否则跳转到 1
1. 结束

循环次数: $\displaystyle\lceil\log_2 {\frac{r-l}{\epsilon}}\rceil$

附程序:

{% include_code lang:cpp approx-number/binary_search.cpp %}

## 0.618 法\优选法

常用于求**单峰函数最值**

先证明一下它的最优性(摘自人教版高中数学选修 4-7~~没错真的有这本选修~~)

> 为了使每次去掉的区间有一定的规律性, 我们这样来考虑: **每次舍去的区间占舍去前的区间的比例数相同**
>
> 下面进一步分析如何按上述两个原则确定合适的试点. 如图 2-1 设第 1 试点、第 2 试点分别为$x_1$和$x_2$, $x_2<x_1$且$x_1,x_2$关于$[a,b]$的中心对称, 即$x_2-a=b-x_1$
>
> ![](2_1.PNG)
>
> (图 2-1, 由 GeoGebra 生成)
>
> 显然, 不论点$x_2$(或点$x_1$)是好点还是差点, 由对称性, 舍去的区间长度都等于$b-x_1$, 不妨设$x_2$是好点, $x_1$是差点, 于是舍去$(x_1,b]$. 再在存优范围$[a,x_1]$内安排第 3 次试验, 设试点为$x_3$, $x_3$与$x_2$关于$[a,x_1]$的中心对称 (如图 2-2 所示)
>
> ![](2_2.PNG)
>
> (图 2-2, 由 GeoGebra 生成)
>
> 点$x_3$应在点$x_2$左侧, 因为如果点$x_3$在点$x_2$的右侧, 那么当$x_3$是好点, $x_2$是差点时, 要舍去区间$[a,x_2]$, 而它的长度与上次舍去的区间$(x_1,b]$的长度相同, 违背成比例舍去的原则. 于是, 不论点$x_3$ (或点$x_2$) 是好点还是差点, 被舍去的区间长度都等于$x_1-x_2$, 按成比例舍去的原则, 我们有等式
>
> $$\frac{b-x_1}{b-a}=\frac{x_1-x_2}{x_1-a}\tag{1}$$
>
> 其中, 左边是第一次舍去的比例数, 右边是第二次舍去的比例数, 对式(1)变形, 得
>
> $$1-\frac{b-x_1}{b-a}=1-\frac{x_1-x_2}{x_1-a}$$
>
> 即
>
> $$\frac{x_1-a}{b-a}=\frac{x_2-a}{x_1-a}\tag{2}$$
>
> 式(2)两边分别是两次舍弁后的存优范围占舍弃前全区间的比例数, 设每次舍弃后的存优范围占舍弃前全区间的比例数为$t$, 即
>
> $$\frac{x_1-a}{b-a}=t\tag{3}$$
>
> 则由$b-x_2=x_1-a$可得
>
> $$\frac{x_2-a}{b-a}=1-t\tag{4}$$
>
> 由式(2)得
>
> $$\frac{x_1-a}{b-a}=\frac{\frac{x_2-a}{b-a}}{\frac{x_1-a}{b-a}}$$
>
> 把(3)与(4)代入(5), 得
>
> $$t=\frac{1-t}{t}$$
>
> 即
>
> $$t^2+t-1=0$$
>
> 解得$t_1=\displaystyle\frac{-1+\sqrt{5}}{2}, t_2=\frac{-1-\sqrt{5}}{2}$, 其中$t_1$为对本问题有意义的根, 这就是**黄金分割常数**, 用$\varphi$表示 (注: 原文用$\omega$表示)

一句话概括就是在缩小区间后可以只计算一个试点坐标, 从而保证最优

流程如下

1. 计算$mid_1=l\varphi+r(1-\varphi)$, $mid_2=l(1-\varphi)+r\varphi$
1. 若$f(l) f(mid_1)>0$
   1. 则令$l=mid_1,mid_1=mid_2,mid_2=l(1-\varphi)+r\varphi$
   1. 否则令$r=mid_2,mid_2=mid_1,mid_1=l\varphi+r(1-\varphi)$
1. 如果达到预定精度, 跳转到 4, 否则跳转到 2 **(注意这里跳转到 2)**
1. 结束

附程序:

{% include_code lang:cpp approx-number/gold_search.cpp %}

读者们可以在 [洛谷 P3382](https://www.luogu.org/problemnew/show/P3382) 中测试一下(～ o ￣ 3 ￣)～

关于这个还有一个类似方法: 斐波那契法. 有兴趣的读者可以查阅相关资料~~才不是笔者不想写~~`_(:3」∠)_`

## Taylor 公式

> 先讲这个是为了为下文 Newton 迭代法二次收敛的证明做铺垫, 不想看证明的可以略过 QwQ (不过还是推荐了解一下, 挺有趣的)
>
> 这里假定函数$f(x)$在$x_0$处有任意阶导数

我们可以很容易地求出多项式和类指数函数的近似值, 但是像三角函数、对数函数这样的我们又该如何求近似值呢

对了, 就是用**Taylor 公式**QwQ

Taylor 公式的想法很简单, 就是构造一个多项式函数$g(x)=\displaystyle\sum_{k=0}^n{a_kx^k}$, 使得它与函数$f(x)$在$x_0$处的**原函数值和各阶导数**均相等, 即

$$
\begin{aligned}
  f(x_0)&=g(x_0)\\
  f^\prime(x_0)&=g^\prime(x_0)\\
  f^{\prime\prime}(x_0)&=g^{\prime\prime}(x_0)\\
  &...\\
  f^{(n)}(x_0)&=g^{(n)}(x_0)
\end{aligned}
$$

因为
$$g^{(m)}(x)=\sum_{k=m}^n{\frac{k!}{(k-m)!}a_kx^{k-m}}$$

于是便有
$$g(x)=\sum_{k=0}^n{\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k}$$

当$n\rightarrow\infty$时, 我们可以认为$f(x)=g(x)$

而当$n$有一个确定的值时, $f(x)$就可以写成$g(x)+R_n(x)$了

其中$R_n(x)$是余项, 它有好几种不同的写法, 比如 Lagrange 余项

$$R_k(x)=\frac{f^{(k+1)}(\xi_L)}{(k+1)!}(x-x_0)^{k+1}$$

其中$\xi_L$在$x$和$x_0$之间

当$n\rightarrow\infty$时, 有(Taylor 级数)

$$\displaystyle\sum_{k=0}^\infty{\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k}$$

特别地, 当$x_0=0$时, 有(Maclaurin 级数)

$$\displaystyle\sum_{k=0}^\infty{\frac{f^{(k)}(0)}{k!}}x^k$$

另外注意应用 Maclaurin 级数并且$x$在某个范围之外时, 得到的结果可能是发散的(这个不展开讲, 有兴趣的读者可以去学习无穷级数相关知识)

附上 [Wikipedia](https://en.wikipedia.org/wiki/Taylor%27s_theorem) 的动图

![](https://upload.wikimedia.org/wikipedia/commons/3/31/Tayloranimation.gif)

对证明感兴趣的读者可以自行查阅相关资料

下面给出几个常见的 Taylor 级数

$$e^x=\displaystyle\sum_{k=0}^\infty{\frac{x^k}{k!}}$$

$$\sin x=\displaystyle\sum_{k=0}^\infty{(-1)^k\frac{x^{2k+1}}{(2k+1)!}}$$

$$\cos x=\displaystyle\sum_{k=0}^\infty{(-1)^k\frac{x^{2k}}{(2k)!}}$$

(有上面三个式子就可以证明欧拉公式之$e^{i\theta}=\cos\theta+i\sin\theta$了)

$$\ln{(1+x)}=\displaystyle\sum_{k=1}^\infty{(-1)^{k+1}\frac{x^k}{k}}$$

$$\frac{1}{1-x}=\displaystyle\sum_{k=0}^\infty{x^k}$$

$$(1+x)^m=\displaystyle\sum_{k=0}^\infty{\binom{m}{k}x^k}$$

## Newton 迭代法

先说说过程

1. 随便确定一个数$x_0$
1. 求在$f(x_0)$处的切线$l:[y-f(x_0)]=f^\prime(x_0)(x-x_0)$
1. 求切线$l$的零点$x_1$

稍加计算便得到了

$$x_1=x_0-\frac{f(x_0)}{f^\prime(x_0)}$$

既然是迭代, 那么自然就有

$$x_{n+1}=x_n-\frac{f(x_n)}{f^\prime(x_n)}$$

其中$x_n$代表第$n$次迭代

附上 [Wikipedia](https://en.wikipedia.org/wiki/Newton's_method) 的动图

![](https://upload.wikimedia.org/wikipedia/commons/e/e0/NewtonIteration_Ani.gif)

二次收敛证明: (Wikipedia 上的, 笔者翻译 QwQ)

> 根据 [Taylor's theorem](https://en.wikipedia.org/wiki/Taylor%27s_theorem), 任何二阶导数连续的函数$f(x)$ (设$\alpha$是根) 都可以写成
>
> $$f(\alpha)=f(x_n)+f^\prime(x_n)(\alpha-x_n)+R_1\tag{1}$$
>
> 由 [Lagrange form of the Taylor series expansion remainder](https://en.wikipedia.org/wiki/Lagrange_remainder) 得
>
> $$R_1=\frac{1}{2!}f^{\prime\prime}(\xi_n)(\alpha-x_n)^2$$
>
> 其中$\xi_n$在$x_n$和$\alpha$之间
>
> 由于$\alpha$是根, 所以(1)式变为
>
> $$0=f(\alpha)=f(x_n)+f^\prime(x_n)(\alpha-x_n)+\frac{1}{2}f^{\prime\prime}(\xi_n)(\alpha-x_n)^2\tag{2}$$
>
> (2)式两边同时除以$f^\prime(x_n)$, 整理得
>
> $$\frac{f(x_n)}{f^\prime(x_n)}+(\alpha-x_n)=\frac{-f^{\prime\prime}(\xi_n)}{2f^\prime(x_n)}(\alpha-x_n)^2\tag{3}$$
>
> 由于
>
> $$x_{n+1}=x_n-\frac{f(x_n)}{f^\prime(x_n)}\tag{4}$$
>
> 代入(3)式, 有
>
> $$\underbrace{\alpha-x_{n+1}}_{\epsilon_{n+1}}=\frac{-f^{\prime\prime}(\xi_n)}{2f^\prime(x_n)}(\underbrace{\alpha-x_n}_{\epsilon_n})^2$$
>
> 即
>
> $$\epsilon_{n+1}=\frac{-f^{\prime\prime}(\xi_n)}{2f^\prime(x_n)}\epsilon_n^2\tag{5}$$
>
> 两边取绝对值, 有
>
> $$|\epsilon_{n+1}|=\frac{|f^{\prime\prime}(\xi_n)|}{2|f^\prime(x_n)|}\epsilon_n^2\tag{6}$$
>
> (6)式表明, 如果函数满足以下条件, 其为二次收敛
>
> 1. 对于所有的$x\in I$ ($I$为区间$[\alpha-r,\alpha+r]$,$r\geq |\alpha-x_0|$ (即$x_0\in I$) ) , 有$f^\prime(x)\neq 0$
> 1. 对于所有的$x\in I$, $f^{\prime\prime}(x)$连续
> 1. $x_0$足够接近根
>
> "足够接近"意为
>
> 1. Taylor 近似足够准确 (可以忽略高阶项)
> 1. 对于$C<\infty$(原文如此), $\displaystyle\frac{1}{2}\Big|\frac{f^{\prime\prime}(x_n)}{f^\prime(x_n)}\Big|<C\Big|\frac{f^{\prime\prime}(\alpha)}{f^\prime(\alpha)}\Big|$
> 1. 对于$n\in\Bbb{N}$, $\displaystyle C\Big|\frac{f^{\prime\prime}(\alpha)}{f^\prime(\alpha)}\Big|\epsilon_n<1$
>
> 当满足上述条件时, (6)式可以写为:
>
> $$|\epsilon_{n+1}|\leq M\epsilon_n^2$$
>
> 其中
>
> $$M=\displaystyle\sup_{x\in I}{\frac{1}{2}\bigg|\frac{f^{\prime\prime}(x)}{f^\prime(x)}\bigg|}$$
>
> 由条件 3 得$M|\epsilon_0|<1$

程序:

{% include_code lang:cpp approx-number/newton.cpp %}

---

当然, 上述各方法的应用范围远不止于此, 有兴趣的读者可以自行查阅相关资料 QwQ

## 赠品

### $\cos x=x$的解析解

对于 PhOer 来说, $\cos x=x$这个方程应该是相当熟悉了 QwQ

笔者在这里放上解析解 (近似值$x=0.739$) , 详情见参考文献[2] (文献里讲的是$t\sin x=x-m$的解法, 不过笔者太弱了, 实在是看不懂 QwQ)

$$\frac{\pi}{2}\exp\Bigg(\frac{1}{\pi}\int_0^1{\arctan\Big({(\pi x+2)\ln{({\sqrt{1-x^2}+1\over x})}x\over x^2\ln^2({\sqrt{1-x^2}+1\over x})-\pi x-1}\Big)\over x}\mathrm{d}x\Bigg)$$

### 快速求${1\over\sqrt{x}}$

关于这个有一个相当有名的故事: [一个 Sqrt 函数引发的血案](https://diducoder.com/sotry-about-sqrt.html) (这是笔者能找到的最早一篇了 QwQ)

测试程序:

{% include_code lang:cpp approx-number/test.cpp %}

## 后记

这篇文章偏数学一些, 如果不能理解的话请多读几遍 QwQ

其实可写的还有很多, 限于篇幅就到此为止了 (现在在后台打个字都要卡两秒 QwQ)

因为笔者是个蒟蒻, 所以如果有错误, 烦请各位 dalao 不吝赐教

## 主要参考资料

- [1] 人教版高中数学选修 4-7 优选法与试验设计初步
- [2] Siewert C E, Burniston E E. An exact analytical solution of Kepler's equation[J]. Celestial Mechanics, 1972, 6(3):294-304.
- [3] [Newton's method - Wikipedia](https://en.wikipedia.org/wiki/Newton's_method)
- [4] [Taylor's theorem - Wikipedia](https://en.wikipedia.org/wiki/Taylor%27s_theorem)
