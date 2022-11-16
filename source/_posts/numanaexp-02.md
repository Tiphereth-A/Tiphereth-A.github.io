---
title: 数值分析实验 - 函数插值方法
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
  - 分治
  - 插值
  - 分段插值
  - Lagrange插值
  - Neville插值
  - Newton插值
  - 三次样条插值
date: 2021-04-16 20:49:47
---

数值分析实验 2 - 函数插值方法

<!-- more -->

## 实验要求

- 问题 1

  对如下结点构造五次插值多项式和分段三次插值多项式

  | $x_i$ | 0.4     | 0.55    | 0.65    | 0.80 | 0.95 | 1.05    |
  | ----- | ------- | ------- | ------- | ---- | ---- | ------- |
  | $y_i$ | 0.41075 | 0.57815 | 0.69675 | 0.90 | 1.00 | 1.25382 |

  并计算 $f(0.596),f(0.99)$

- 问题 2

  对如下结点构造六次插值多项式和分段三次插值多项式

  | $x_i$ | 1     | 2     | 3     | 4     | 5     | 6     | 7     |
  | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
  | $y_i$ | 0.368 | 0.135 | 0.050 | 0.018 | 0.007 | 0.002 | 0.001 |

  并计算 $f(1.8),f(6.15)$

## 计算公式

本博客分别使用 MATLAB 实现了 Lagrange 插值, Neville 插值, Newton 插值和三次样条插值

- Lagrange 插值
  $$L(x)=\sum_{k=0}^ny_k\prod_{i=0;~i\ne k}^n\frac{x-x_i}{x_k-x_i}\tag{1}$$
- Neville 插值

  令 $N\in\mathbb{R}^{(n+1)\times (n+1)}[x]$ 满足

  - $$N_{i,1}(x)=y_{i-1}$$
  - $$N_{i,j}(x)={(x-x_{i-1})N_{i-1,j-1}(x)+(x_{i-j}-x)N(i,j-1)\over x_{i-j}-x_{i-1}}$$

  则结果即为
  $$N_{n+1,n+1}(x)\tag{2}$$

- Newton 插值

  $$N(x)=f(x_0)+\sum_{k=1}^nf[x_0,x_1,...,x_k]\prod_{i=0}^{k-1}(x-x_i)\tag{3}$$

  其中

  - $$f[a,b]=\frac{f(a)-f(b)}{a-b}\tag{4}$$
  - $$f[x_0,x_1,...,x_k]={f[x_0,x_1,...,x_{k-1}]-f[x_1,x_2,...,x_k]\over x_0-x_k}\tag{5}$$

- 三次样条插值 (本文采用自然样条插值)

  设结果 $S(x)\in C^2[x_0,x_n]$ 满足

  - $S(x_i)=y_i$
  - $\partial S(x)\leqslant3,x\in[x_{i-1},x_i]$

  令

  - $h_i=x_i-x_{i-1}$
  - $\lambda_i={h_i\over h_i+h_{i+1}}$
  - $\mu_i=1-\lambda_i$
  - $g_i=6f[x_{i-1},x_i,x_{i+1}]$
  - $A_i=6y_{i-1}+M_{i-1}h_i^2$
  - $B_i=6y_i+M_ih_i^2$
  - $\displaystyle S_i(x)={M_{i-1}(x_i-x)^3+M_i(x-x_{i-1})^3\over 6h_i}+{A_i(x_i-x)+B_i(x-x_{i-1})\over 6h_i},~x\in[x_{i-1},x_i],i=1,2,...,n$
  - $\displaystyle S(x)=\sum_{i=1}^nS_i(x)$

  由 $\lim_{x\to k^+}S'(x)=\lim_{x\to k^-}S'(x),~\forall k\in[x_0,x_n]$ 知
  $$\lambda_iM_{i-1}+2M_i+\mu_iM_{i+1}=g_i,~i=1,2,...,n-1\tag{6}$$

  又
  $$S''(x_0)=S''(x_n)=0\tag{7}$$

  联立 $(6),(7)$, 有

  - $M_0=M_n=0$
  - $$
    \begin{bmatrix}
      2&\mu_1&&&&\\
      \lambda_2&2&\mu_2&&&\\
      &\lambda_3&2&\mu_3&&\\
      &&\ddots&\ddots&\ddots&\\
      &&&\lambda_{n-2}&2&\mu_{n-2}\\
      &&&&\lambda_{n-1}&2\\
    \end{bmatrix}\begin{bmatrix}
      M_1\\M_2\\\vdots\\M_{n-1}
    \end{bmatrix}=\begin{bmatrix}
      g_1\\g_2\\\vdots\\g_{n-1}
    \end{bmatrix}\tag{8}
    $$

解出 $M_i,~i=0,1,...,n$, 即求得 $S(x)$

## 程序设计

### 主程序

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/main.m %}

</details>

### 输入数据检查

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/input_check.m %}

</details>

### Lagrange 插值

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/calc_lagrange.m %}

</details>

### Neville 插值

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/calc_neville.m %}

</details>

### Newton 插值

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/calc_newton.m %}

</details>

### 三次样条插值

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/calc_spline3.m %}

</details>

## 结果讨论和分析

### 结果

- 问题 1

  ![](fig1.svg)

  | 方法          | 多项式 | $f(0.596)$   | $f(0.99)$   |
  | ------------- | ------ | ------------ | ----------- |
  | Lagrange 插值 | $P_1$  | $0.62573238$ | $1.0542298$ |
  | Neville 插值  | $P_1$  | $0.62573238$ | $1.0542298$ |
  | Newton 插值   | $P_1$  | $0.62573238$ | $1.0542298$ |
  | 三次样条插值  | $S_1$  | $0.62896167$ | $1.0842113$ |

  其中

  - $$P_1=121.62636\,x^5 - 422.75031\,x^4 + 572.56675\,x^3 - 377.25487\,x^2 + 121.97184\,x - 15.084523$$
  - $$
    S_1=\begin{cases}
      -0.56178215\,(x-0.4)^3 + 1.1286401\,(x-0.4) + 0.41075,&x\in[0.4, 0.55)\\
      12.056039\,(x-0.55)^3 - 0.25280197\,(x-0.55)^2 + 1.0907198\,(x-0.55) + 0.57815,&x\in[0.55, 0.65)\\
      -24.508536\,(x-0.65)^3 + 3.3640098\,(x-0.65)^2 + 1.4018406\,(x-0.65) + 0.69675,&x\in[0.65, 0.80)\\
      47.096624\,(x-0.80)^3 - 7.6648315\,(x-0.80)^2 + 0.75671734\,(x-0.80) + 0.9,&x\in[0.80, 0.95)\\
      -45.095498\,(x-0.95)^3 + 13.528649\,(x-0.95)^2 + 1.63629\,(x-0.95) + 1.0,&x\in[0.95, 1.05]
    \end{cases}
    $$

- 问题 2

  ![](fig2.svg)

  | 方法          | 多项式 | $f(1.8)$     | $f(6.15)$      |
  | ------------- | ------ | ------------ | -------------- |
  | Lagrange 插值 | $P_2$  | $0.16476189$ | $0.0012658255$ |
  | Neville 插值  | $P_2$  | $0.16476189$ | $0.0012658255$ |
  | Newton 插值   | $P_2$  | $0.16476189$ | $0.0012658255$ |
  | 三次样条插值  | $S_2$  | $0.17116591$ | $0.0016228947$ |

  其中

  - $$P_2=0.000058333333\,x^6 - 0.0016083333\,x^5 + 0.018583333\,x^4 - 0.11754167\,x^3 + 0.44185833\,x^2 - 0.96835\,x + 0.995$$
  - $$
    S_2=\begin{cases}
      0.036229487\,(x-1)^3 - 0.26922949\,(x-1) + 0.368,&x\in[1,2)\\
      -0.033147436\,(x-2)^3 + 0.10868846\,(x-2)^2 - 0.16054103\,(x-2) + 0.135,&x\in[2,3)\\
      0.0013602564\,(x-3)^3 + 0.0092461538\,(x-3)^2 - 0.04260641\,(x-3) + 0.05,&x\in[3,4)\\
      -0.0042935897\,(x-4)^3 + 0.013326923\,(x-4)^2 - 0.020033333\,(x-4) + 0.018,&x\in[4,5)\\
      0.00081410256\,(x-5)^3 + 0.00044615385\,(x-5)^2 - 0.0062602564\,(x-5) + 0.007,&x\in[5,6)\\
      -0.00096282051\,(x-6)^3 + 0.0028884615\,(x-6)^2 - 0.002925641\,(x-6) + 0.002,&x\in[6,7]
    \end{cases}
    $$

### 分析

1. Lagrange 插值, Neville 插值和 Newton 插值得到的多项式相同
1. 观察图像发现, Lagrange 插值, Neville 插值和 Newton 插值得到的多项式稳定性较差, 尤其在问题 2 中, $x>7$ 时的图像明显偏离预期
1. 博客中所给出的 Lagrange 插值, Neville 插值和 Newton 插值程序的时间复杂度均为 $O(n^2)$, 三次样条插值的时间复杂度为 $O(n^3)$ , 后面将给出 $O(n\log^2 n)$ 的 Lagrange 插值算法
1. 四种方法的优缺点如下
   | 方法 | 优点 | 缺点 |
   | ------------- | ------------------------------------------- | ---------------------------------------------- |
   | Lagrange 插值 | 形式直观简洁, 推导容易 | 增加新结点时, 原有结果不能复用; 数值稳定性问题 |
   | Neville 插值 | 增加新结点时, 原有结果可以复用 | 形式不直观; 数值稳定性问题 |
   | Newton 插值 | 增加新结点时, 原有结果可以复用;形式直观简洁 | 数值稳定性问题 |
   | 三次样条插值 | 数值稳定性好 | 形式复杂, 时间复杂度高 |

## 附: 基于分治的 Lagrange 插值算法

令 $\omega(x)=\prod_{i=0}^n(x-x_i)$ 我们改写式 $(1)$

$$
\begin{aligned}
  L(x)&=\sum_{k=0}^ny_k\frac{\omega(x)}{x-x_k}\lim_{x\to x_k}\frac{x-x_k}{\omega(x)}\\
  &=\sum_{k=0}^n\frac{y_k}{\omega'(x_k)}\frac{\omega(x)}{x-x_k}
\end{aligned}
$$

我们考虑分治求 $L(x)$

令

- $$L_{l,r}(x)=\sum_{k=l}^r\frac{y_k}{\omega'(x_k)}\prod_{i=l;i\ne k}^r(x-x_i)$$
- $$m=\left\lfloor\frac{l+r}{2}\right\rfloor$$

则有
$$L_{l,r}(x)=L_{l,m}(x)\prod_{i=m+1}^r(x-x_i)+L_{m+1,r}(x)\prod_{i=l}^m(x-x_i)$$

基于 FFT 的多项式乘法的时间复杂度为 $O(n\log n)$, 故该算法的时间复杂度为 $O(n\log^2 n)$

### MATLAB 程序实现

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab numanaexp-02/calc_lagrange_fast.m %}

</details>
