---
title: 数值分析实验 - 数值积分与数值微分
categories:
  - 笔记
  - 数学
  - 数值分析
  - 实验报告
tags:
  - 笔记
  - 数学
  - 数值分析
  - 实验报告
  - MATLAB
  - 数值积分
  - Simpson积分
  - 复化Simpson积分
  - 自适应Simpson积分
  - 梯形积分
  - 复化梯形积分
  - 自适应梯形积分
  - Richardson外推
  - Romberg算法
  - 瑕积分
  - 多重积分
  - 二重积分
date: 2021-05-06 23:06:44
---

数值分析实验 4 - 数值积分与数值微分

<!-- more -->

## 目的和意义

### 实验目的

选用复合梯形公式, 复合 Simpson 公式, Romberg 算法, 计算

1. $\displaystyle I=\int_0^\frac{1}{4}\sqrt{4-\sin^2x}\mathrm{d}x$
1. $\displaystyle I=\int_0^1\frac{\sin x}{x}\mathrm{d}x$
1. $\displaystyle I=\int_0^1\frac{e^x}{4+x^2}\mathrm{d}x$
1. $\displaystyle I=\int_0^1\frac{\ln(1+x)}{1+x^2}\mathrm{d}x$

### 要求

1. 编制数值积分算法的程序
1. 分别用两种算法计算同一个积分, 并比较其结果
1. 分别取不同步长 $n$, 试比较计算结果 (如 $n=10,20$ 等)
1. 给定精度要求 $\epsilon$, 试用变步长算法, 确定最佳步长

### 意义

1. 深刻认识数值积分法的意义
1. 明确数值积分精度与步长的关系
1. 根据定积分的计算方法, 可以考虑二重积分的计算问题

## 计算公式

### 梯形积分

$$
\int_a^bf(x)\mathrm{d}x\approx\frac{h}{2}\left(f(a)+2\sum_{i=1}^{n-1}f(x_k)+f(b)\right)
$$

其中

- 步长 $h=\frac{b-a}{n}$
- 等分点 $x_k=a+kh,~k=0,1,2,...,n$; $x_0=a,x_n=b$

### Simpson 积分

$$
\int_a^bf(x)\mathrm{d}x\approx\frac{h}{6}\left(f(a)+4\sum_{i=1}^{n-1}f(x_{k+1/2})+2\sum_{i=1}^{n-1}f(x_k)+f(b)\right)
$$

其中

- 步长 $h=\frac{b-a}{n}$
- 等分点 $x_k=a+kh,~k=0,1,2,...,n$; $x_0=a,x_n=b$
- $x_{k+1/2}={x_k+x_{k+1}\over2},~k=0,1,...,n-1$

### Romberg 算法 (复化梯形)

- Richardson 外推法

  对于

  $$
  T_n=\frac{h}{2}\left(f(a)+2\sum_{i=1}^{n-1}f(x_k)+f(b)\right)\tag{1}
  $$

  有

  $$
  T_n=I+\tau_1h^2+\tau_2h^4+O(h^6)
  $$

  其中

  - $I=\displaystyle\int_a^bf(x)\mathrm{d}x$
  - $\tau_1,\tau_2$ 为与 $h$ 无关的常数

  注意到

  $$
  T_{2n}=I+\tau_1\left(\frac{h}{2}\right)^2+\tau_2\left(\frac{h}{2}\right)^4+O(h^6)\tag{2}
  $$

  $(1)-4\times (2)$, 得

  $$
  S_n:={4T_{2n}-T_n\over3}=I-\frac{\tau_2}{4}h^4+O(h^6)
  $$

- Romberg 算法

  记

  - $h_{k+j}=\frac{1}{2}h_{k+j-1}$
  - $T_{0,0}=\frac{b-a}{2}(f(a)+f(b))$
  - $\displaystyle T_{0,k+1}=\frac{1}{2}T_{0,k}+\frac{h_k}{2}\sum_{i=0}^{n-1}f(x_{i+1/2})$
  - $\displaystyle T_{j,k}={4^jT_{j-1,k+1}-T_{j-1,k}\over4^j-1}$

  则 $T_{n,0}$ 即为答案

### 关于多重积分

只需嵌套进行数值积分即可

### 一些特殊处理

- 由于积分 2 为瑕积分, 故编写程序时将积分区间取为 `[eps, 1]`
- 根据文献[^1]的结果, 编写自适应积分程序时, 对自适应梯形积分和自适应 Simpson 积分进行了常数优化. 如对自适应 Simpson 积分, 终止条件改为 $|S-(S_l+S_r)|<15\epsilon$, 返回值改为 $S_l+S_r+\frac{S-(S_l+S_r)}{15}$

[^1]: J N Lyness. Notes on the Adaptive Simpson Quadrature Routine[J]. Journal of the ACM, 1969, 16(3): 483–495

## 程序设计

### 主程序

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-04/main.m %}

</details>

### 输入数据检查

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-04/input_check.m %}

</details>

### 按步长积分 (复化积分)

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-04/integral_with_h.m %}

</details>

### 按精度积分 (自适应积分)

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-04/integral_with_eps.m %}

</details>

### 辅助函数

#### 梯形积分

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-04/trapez.m %}

</details>

#### Simpson 积分

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:matlab numanaexp-04/simpson.m %}

</details>

## 结果讨论和分析

### 结果 - 复化积分

- 分段数 $n=8$

  <center><b>表</b> 1</center>

  |              | 积分 1                               | 积分 2                               | 积分 3                               | 积分 4                               |
  | ------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ |
  | 参考值       | 0.49871112                           | 0.94608307                           | 0.39081185                           | 0.27219826                           |
  | 梯形公式     | 0.4987<font color="gray">0129</font> | 0.94<font color="gray">569086</font> | 0.390<font color="gray">91099</font> | 0.27<font color="gray">076864</font> |
  | Simpson 公式 | 0.49871112                           | 0.9460830<font color="gray">9</font> | 0.3908118<font color="gray">6</font> | 0.272198<font color="gray">71</font> |
  | Romberg 算法 | 0.49871112                           | 0.94608307                           | 0.39081185                           | 0.27219<font color="gray">672</font> |

- 分段数 $n=16$

  <center><b>表</b> 2</center>

  |              | 积分 1                               | 积分 2                               | 积分 3                               | 积分 4                               |
  | ------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ |
  | 参考值       | 0.49871112                           | 0.94608307                           | 0.39081185                           | 0.27219826                           |
  | 梯形公式     | 0.4987<font color="gray">0866</font> | 0.94<font color="gray">598503</font> | 0.3908<font color="gray">3664</font> | 0.27<font color="gray">184119</font> |
  | Simpson 公式 | 0.49871112                           | 0.94608307                           | 0.39081185                           | 0.2721982<font color="gray">9</font> |
  | Romberg 算法 | 0.49871112                           | 0.94608307                           | 0.39081185                           | 0.2721982<font color="gray">7</font> |

### 结果 - 自适应积分

- 精度要求 $\epsilon=10^{-8}$

  - 结果

    <center><b>表</b> 3</center>

    |              | 积分 1                                   | 积分 2         | 积分 3                                   | 积分 4                                   |
    | ------------ | ---------------------------------------- | -------------- | ---------------------------------------- | ---------------------------------------- |
    | 参考值       | 0.498711117575                           | 0.946083070367 | 0.390811845564                           | 0.272198261288                           |
    | 梯形公式     | 0.498711117575                           | 0.946083070367 | 0.390811845564                           | 0.272198261288                           |
    | Simpson 公式 | 0.49871111757<font color="gray">4</font> | 0.946083070367 | 0.39081184556<font color="gray">2</font> | 0.272198261<font color="gray">327</font> |
    | Romberg 算法 | 0.498711117575                           | 0.946083070367 | 0.3908118455<font color="gray">56</font> | 0.272198261288                           |

  - 步长

    <a id="table-4"><center><b>表</b> 4</center></a>

    |              | 积分 1 | 积分 2 | 积分 3 | 积分 4 |
    | ------------ | ------ | ------ | ------ | ------ |
    | 梯形公式     | 1/512  | 1/1024 | 1/512  | 1/2048 |
    | Simpson 公式 | 1/8    | 1/8    | 1/8    | 1/16   |
    | Romberg 算法 | 1/8    | 1/16   | 1/16   | 1/64   |

- 精度要求 $\epsilon=10^{-10}$

  - 结果

    <center><b>表</b> 5</center>

    |              | 积分 1         | 积分 2         | 积分 3         | 积分 4         |
    | ------------ | -------------- | -------------- | -------------- | -------------- |
    | 参考值       | 0.498711117575 | 0.946083070367 | 0.390811845564 | 0.272198261288 |
    | 梯形公式     | 0.498711117575 | 0.946083070367 | 0.390811845564 | 0.272198261288 |
    | Simpson 公式 | 0.498711117575 | 0.946083070367 | 0.390811845564 | 0.272198261288 |
    | Romberg 算法 | 0.498711117575 | 0.946083070367 | 0.390811845564 | 0.272198261288 |

  - 步长

    <a id="table-6"><center><b>表</b> 6</center></a>

    |              | 积分 1 | 积分 2  | 积分 3 | 积分 4  |
    | ------------ | ------ | ------- | ------ | ------- |
    | 梯形公式     | 1/8192 | 1/16384 | 1/8192 | 1/32768 |
    | Simpson 公式 | 1/32   | 1/16    | 1/32   | 1/64    |
    | Romberg 算法 | 1/8    | 1/16    | 1/32   | 1/64    |

### 分析

- 三种积分方法中, 梯形积分精度最差, 其余两种方法所差无几
- 观察 [表 4](#table-4) 与 [表 6](#table-6) 发现, 积分精度为 $n$ 位时, 三种方法的最小步长分别为: $O(n^{-4})$, $O(n^{-2})$, $O(n^{-2})$
