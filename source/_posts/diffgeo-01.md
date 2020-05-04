---
title: 微分几何笔记01 - 曲线论
categories:
  - 笔记
  - 数学
  - 微分几何
tags:
  - 数学
  - 笔记
  - 几何
  - 微分几何
  - 曲线
  - 正则曲线
  - 切向量
  - 法向量
  - 主法向量
  - 副法向量
  - 法平面
  - 从切平面
  - 密切平面
  - 曲率
  - 挠率
  - Frenet标架
  - Frenet公式
  - 曲线论基本定理
date: 2022-01-19 14:20:59
---

本章主要讨论

- 曲线的不变量: 曲率与挠率
- Frenet 标架
- 曲线论基本定理

<!-- more -->

{% post_link diff-geo 返回目录 %}

{% post_link diffgeo-00 上一篇笔记 %}

---

## 曲线的弧长参数

本章主要研究的是曲线的"形状", 所以为了方便起见, 我们最好找一个新参数, 使得曲线随该参数的变化幅度恒定, 也就是说, 对曲线 $\textbf{r}(t)$, 我们要找到 $s=s(t)$ 使得

$$
|\textbf{r}'(s)|=C
$$

其中 $C$ 为常数, 不妨令其为 $1$

不难得出

$$
|\textbf{r}_t|=|\textbf{r}_s|s_t
$$

从而

$$
s(t)=\int_{t_0}^t |\textbf{r}_t|\mathrm{d}t
$$

也就是说, 我们要找的参数 $s$ 就是曲线相对于某定点的弧长

{% note info no-icon %}

**<a id="def-1-1">定义 - 1-1</a>** 曲线的**弧长参数** 对曲线 $\textbf{r}(t)$ 和一定点 $t_0$, 称

$$
s(t)=\int_{t_0}^t |\textbf{r}_t|\mathrm{d}t
$$

为该曲线的 **弧长参数**

该参数有性质 $|\textbf{r}_s|=1$, 同时不难发现对任意正则曲线, 弧长参数都是存在且唯一的

{% endnote %}

## 平面曲线

我们先从简单的部分入手, 先考察 $E^2$ 下的曲线 $\textbf{r}(s)=(x(s),y(s))$

我们令 $\textbf{r}'(s)=:\textbf{t}(s)$, 称其为 $r$ 的**单位切向量**, 接着按右手系的取法取 $\textbf{n}(s)$ 满足

- $$
  \lang\textbf{n}(s),\textbf{n}(s)\rang=1
  $$
- $$
  \lang\textbf{n}(s),\textbf{t}(s)\rang=0
  $$

称其为**单位法向量**

我们考察

$$
{\mathrm{d}\over \mathrm{d}s}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)
\end{bmatrix}=(a_{ij})\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)
\end{bmatrix}
$$

不难得出 (对单位切向量和单位法向量之间的内积求导)

$$
\begin{cases}
  a_{11}=a_{22}=0\\
  a_{12}=-a_{21}
\end{cases}
$$

我们设 $\lang\textbf{t}'(s),\textbf{n}(s)\rang=:\kappa(s)$, 则

$$
{\mathrm{d}\over \mathrm{d}s}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)
\end{bmatrix}=\begin{bmatrix}
  0&\kappa(s)\\
  -\kappa(s)&0
\end{bmatrix}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)
\end{bmatrix}
$$

{% note info no-icon %}

**<a id="def-2-1">定义 - 2-1</a>** 称 $\{\textbf{r}(s);\textbf{t}(s),\textbf{n}(s)\}$ 为曲线的 **Frenet 标架**

{% endnote %}

{% note info no-icon %}

**<a id="def-2-2">定义 - 2-2</a>** 称 $\kappa(s):=\lang\textbf{t}'(s),\textbf{n}(s)\rang$ 为曲线 $\textbf{r}(s)$ 的 **曲率**

不难看出, 曲率表示曲线的弯曲程度

{% endnote %}

{% note info no-icon %}

**<a id="def-2-3">定义 - 2-3</a>** **Frenet 公式**

$$
{\mathrm{d}\over \mathrm{d}s}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)
\end{bmatrix}=\begin{bmatrix}
  0&\kappa(s)\\
  -\kappa(s)&0
\end{bmatrix}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)
\end{bmatrix}
$$

{% endnote %}

不难得出, 对于 $\textbf{r}(t)=(x(t),y(t))$,

- $$
  \textbf{t}(t)={\textbf{r}'(t)\over |\textbf{r}'(t)|}=\left({x'\over\sqrt{x'^2+y'^2}},{y'\over\sqrt{x'^2+y'^2}}\right)
  $$
- $$
  \textbf{n}(t)={\textbf{r}''(t)\over |\textbf{r}''(t)|}=\left(-{y'\over\sqrt{x'^2+y'^2}},{x'\over\sqrt{x'^2+y'^2}}\right)
  $$
- $$
  \kappa(t)={|\textbf{r}'(t)\wedge\textbf{r}''(t)|\over|\textbf{r}'(t)|^3}={x'y''-x''y'\over(x'^2+y'^2)^\frac{3}{2}}
  $$

最后我们考察一下曲率的物理意义以及常曲率曲线

- **曲率的物理意义** 曲率代表沿曲线做速率恒为 $1$ 的运动的质点的**加速度**大小

  这个很好理解

- **常曲率曲线** 我们有如下定理

  {% note success no-icon %}

  **<a id="th-2-1">定理 - 2-1</a>** 对于常曲率平面曲线 $\textbf{r}(s)$

  - 若 $\kappa(s)\equiv 0$, 则 $\textbf{r}(s)$ 是直线
  - 若 $\kappa(s)\equiv k\ne 0$, 则 $\textbf{r}(s)$ 是圆, 且圆的半径为 $\frac{1}{|k|}$

  {% note %}

  <details open>
  <summary>证明</summary>

  $$
  \begin{aligned}
    \kappa(s)\equiv 0\iff&\textbf{t}'(s)\equiv 0\\
    \iff&\textbf{t}(s)\equiv \textbf{t}_0\\
    \iff&\textbf{r}(s)=\textbf{r}(s_0)+(s-s_0)\textbf{t}_0
  \end{aligned}
  $$

  $$
  \begin{aligned}
    \kappa(s)\equiv k\ne 0\iff&\textbf{t}'(s)\equiv k\textbf{n}(s)\\
    \xLeftrightarrow{\textbf{r}(s)+\frac{1}{k}\textbf{n}(s)=:\textbf{p}(s)}&\textbf{p}'(s)=0\\
    \iff&\begin{cases}
        \textbf{p}(s)\equiv\textbf{p}_0\\
        |\textbf{r}(s)-\textbf{p}_0|\equiv \frac{1}{k}
    \end{cases}
  \end{aligned}
  $$

  </details>

  {% endnote %}
  {% endnote %}

## 空间曲线

平面曲线的法向量放到 $E^3$ 中构成了一个平面, 称其为 **法平面**, 为了方便和我们上节讨论的内容对接, 我们取

- $\textbf{t}(s)=\textbf{r}'(s)$
- $\textbf{n}(s)={\textbf{t}'(s)\over |\textbf{t}'(s)|}$
- $\textbf{b}(s)=\textbf{t}(s)\wedge\textbf{n}(s)$

这样上一节的 Frenet 公式仍然成立, 且 $\{\textbf{t}(s),\textbf{n}(s),\textbf{b}(s)\}$ 构成右手系

我们称

- $\textbf{n}(s)$ 为 **主法向量**
- $\textbf{b}(s)$ 为 **副法向量**
- $\operatorname{span}\{\textbf{n},\textbf{b}\}$ 为 **法平面**
- $\operatorname{span}\{\textbf{t},\textbf{b}\}$ 为 **从切平面**
- $\operatorname{span}\{\textbf{t},\textbf{n}\}$ 为 **密切平面**

和上一节的讨论一致, 我们有

{% note info no-icon %}

**<a id="def-3-1">定义 - 3-1</a>** 称 $\{\textbf{r}(s);\textbf{t}(s),\textbf{n}(s),\textbf{b}(s)\}$ 为曲线的 **Frenet 标架**

{% endnote %}

{% note info no-icon %}

**<a id="def-3-2">定义 - 3-2</a>**

- 称 $\kappa(s):=\lang\textbf{t}'(s),\textbf{n}(s)\rang$ 为曲线 $\textbf{r}(s)$ 的 **曲率**

- 称 $\tau(s):=\lang\textbf{n}'(s),\textbf{b}(s)\rang$ 为曲线 $\textbf{r}(s)$ 的 **挠率**

不难看出

- 曲率表示曲线的弯曲程度
- 挠率表示曲线偏移密切平面的程度

{% endnote %}

{% note info no-icon %}

**<a id="def-3-3">定义 - 3-3</a>** **Frenet 公式**

$$
{\mathrm{d}\over \mathrm{d}s}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)\\
  \textbf{b}(s)
\end{bmatrix}=\begin{bmatrix}
  0&\kappa(s)&0\\
  -\kappa(s)&0&\tau(s)\\
  0&-\tau(s)&0\\
\end{bmatrix}\begin{bmatrix}
  \textbf{t}(s)\\
  \textbf{n}(s)\\
  \textbf{b}(s)
\end{bmatrix}
$$

{% endnote %}

不难得出, 对于 $\textbf{r}(t)=(x(t),y(t),z(t))$,

- $$
  \textbf{t}(t)={\textbf{r}'(t)\over |\textbf{r}'(t)|}
  $$
- $$
  \textbf{n}(t)={\textbf{r}''(t)\over |\textbf{r}''(t)|}
  $$
- $$
  \textbf{b}(t)={\textbf{r}'(t)\wedge\textbf{r}''(t)\over |\textbf{r}'(t)\wedge\textbf{r}''(t)|}
  $$
- $$
  \kappa(t)={|\textbf{r}'(t)\wedge\textbf{r}''(t)|\over|\textbf{r}'(t)|^3}
  $$
- $$
  \tau(t)={(\textbf{r}'(t),\textbf{r}''(t),\textbf{r}'''(t))\over|\textbf{r}'(t)\wedge\textbf{r}''(t)|^2}
  $$

<details open>
<summary><font color='orange'>Show/Hide</font></summary>

- $$
  \textbf{t}(t)={(x',y',z')\over\sqrt{x'^2+y'^2+z'^2}}
  $$
- $$
  \textbf{n}(t)={(x'',y'',z'')\over\sqrt{x''^2+y''^2+z''^2}}
  $$
- $$
  \textbf{b}(t)={({y'z''-y''z'},{z'x''-x'z''},{x'y''-y'x''})\over\sqrt{(y'z''-y''z')^2+(z'x''-x'z'')^2+(x'y''-y'x'')^2}}
  $$
- $$
  \kappa(t)={\sqrt{(y'z''-y''z')^2+(z'x''-x'z'')^2+(x'y''-y'x'')^2}\over(x'^2+y'^2+z'^2)^\frac{3}{2}}
  $$
- $$
  \tau(t)=\frac{x'''(y'z''-y''z')+y'''(z'x''-x'z'')+z'''(x'y''-y'x'')}{(y'z''-y''z')^2+(z'x''-x'z'')^2+(x'y''-y'x'')^2}
  $$

</details>

对于曲率和挠率均为常数的曲线, 我们有如下定理

{% note success no-icon %}

**<a id="th-3-1">定理 - 3-1</a>** 对于曲率和挠率均为常数的曲线 $\textbf{r}(s)$

- 若 $\kappa(s)\equiv 0$, 则 $\textbf{r}(s)$ 是直线
- 若 $\kappa(s)\equiv k\ne 0$
  - 若 $\tau(s)\equiv 0$, 则 $\textbf{r}(s)$ 是圆, 且圆的半径为 $\frac{1}{|k|}$
  - 若 $\tau(s)\equiv \tau\ne 0$, 则 $\textbf{r}(s)$ 是圆柱螺线, 且 对于圆柱螺线 $\textbf{r}(t)=(a\cos t,a\sin t,bt)$ 有
    - $$
      k=\frac{a}{a^2+b^2}
      $$
    - $$
      \tau=\frac{b}{a^2+b^2}
      $$

直线和圆的证明过程和 <a href="#th-2-1">定理 - 2-1</a> 一致, 圆柱螺线的若按同样的思路证明则要繁琐亿些, 所以推荐用下一节的 <a href="#th-4-1">曲线论基本定理</a> 来证明

{% endnote %}

## 曲线论基本定理

目前为止我们讨论的曲线都是与其所选参数有关的, 而参数的选取又与坐标系的选取有关, 但是我们知道曲线的形状与坐标系无关, 也就是说, 曲线参数并不是能决定曲线的内蕴量

我们接下来的目标就是找到一些量使得这些量能完全确定曲线的形状, 我们注意到曲线的曲率和挠率能够量化曲线的形状, 一个自然的想法就是: 给定曲率和挠率, 能否唯一确定曲线的形状. 曲线论基本定理就证明了这一点

首先我们给出一个引理

{% note danger no-icon %}

**<a id="lm-4-1">引理 - 4-1</a>** 对任意的正则曲线 $\textbf{r}(s):D\to\mathbb{R}^3$ ($s$ 为弧长参数) 和任意的刚体运动 $\mathcal{T}:\mathbb{R}^3\to\mathbb{R}^3;\mathcal{T}(X)=XT+P$, 考虑 $\tilde\textbf{r}(s):=\mathcal{T}(\textbf{r}(s))$, 有

- $s$ 为 $\tilde\textbf{r}(s)$ 的弧长参数
- $\tilde\textbf{r}(s)$ 的曲率和挠率与 $\textbf{r}(s)$ 相同
- $\tilde\textbf{r}(s)$ 的 Frenet 标架为 $\{\tilde\textbf{r}(s);\textbf{t}(s)T,\textbf{n}(s)T,\textbf{b}(s)T\}$

<details open>
<summary>证明</summary>

$$
{\mathrm{d}\tilde\textbf{r}\over\mathrm{d}s}={\mathrm{d}\textbf{r}\over\mathrm{d}s}T\implies\left\lang{\mathrm{d}\tilde\textbf{r}\over\mathrm{d}s},{\mathrm{d}\tilde\textbf{r}\over\mathrm{d}s}\right\rang={\mathrm{d}\textbf{r}\over\mathrm{d}s}T\left({\mathrm{d}\textbf{r}\over\mathrm{d}s}T\right)^T=1
$$

故 $s$ 为 $\tilde\textbf{r}(s)$ 的弧长参数

考虑 $\tilde\textbf{r}(s)$ 的 Frenet 标架 $\{\tilde\textbf{r}(s);\tilde\textbf{t}(s),\tilde\textbf{n}(s),\tilde\textbf{b}(s)\}$, 其中 $\tilde\textbf{t}(s)=\textbf{t}(s)T$, 则

- $$
  \tilde\kappa(s)=\left|{\mathrm{d}\tilde\textbf{t}\over\mathrm{d}s}(s)\right|=\left|{\mathrm{d}\textbf{t}\over\mathrm{d}s}(s)\right|=\kappa(s)
  $$
- $$
  \tilde\textbf{n}(s)=\frac{1}{\tilde\kappa(s)}{\mathrm{d}\tilde\textbf{t}\over\mathrm{d}s}(s)=\textbf{n}(s)T
  $$
- $$
  \tilde\textbf{b}(s)=\tilde\textbf{t}(s)\wedge\tilde\textbf{n}(s)=\det T(\textbf{t}(s)\wedge\textbf{n}(s))T=\textbf{b}(s)T
  $$
- $$
  \tilde\tau(s)=\left\lang{\mathrm{d}\tilde\textbf{n}\over\mathrm{d}s}(s),\tilde\textbf{b}(s)\right\rang=\tau(s)
  $$

</details>

{% endnote %}

{% note success no-icon %}

**<a id="th-4-1">定理 - 4-1</a>** (**曲线论基本定理**)

对任意函数 $\kappa(s):D\to\mathbb{R}^+$, $\tau(S):D\to\mathbb{R}$ 且 $\kappa,\tau\in C^{\infty}(D)$, 给定等价关系 $\sim:\textbf{x}\sim\textbf{y}\iff\textbf{x}=\mathcal{T}(\textbf{y})$, 其中 $\mathcal{T}$
为刚体运动, 则

- (存在性) 存在曲线 $\textbf{r}(s)$ 使得
  - $s$ 为 $\textbf{r}(s)$ 的弧长参数
  - $\kappa(s)$ 为 $\textbf{r}(s)$ 的曲率
  - $\tau(s)$ 为 $\textbf{r}(s)$ 的挠率
- (唯一性) $\textbf{r}_1(s)$ 与 $\textbf{r}_2(s)$ 均满足上条当且仅当 $\textbf{r}_1\sim\textbf{r}_2$

<details open>
<summary>证明</summary>

唯一性由 <a href="#lm-4-1">引理 - 4-1</a> 不难得证, 下证存在性

考虑 ODE

$$
{\mathrm{d}F\over\mathrm{d}s}=\begin{bmatrix}
  0&\kappa&0\\
  -\kappa&0&\tau\\
  0&-\tau&0
\end{bmatrix}F
$$

其中 $F$ 为 3 阶方阵

我们知道该 ODE 有解, 且在给定初值的情况下有唯一解

我们希望存在初值 $F(s_0)$ 使得解出来的 $F$ 是 Frenet 标架, 下证: $F(s_0)\in\textrm{SO}(3)\implies F\in\textrm{SO}(3)$

注意到

$$
{\mathrm{d}\over\mathrm{d}s}(FF^T)={\mathrm{d}F\over\mathrm{d}s}F^T+{\mathrm{d}F^T\over\mathrm{d}s}F=0
$$

从而

$$
FF^T=F(s_0)F^T(s_0)\implies F\in\textrm{O}(3)
$$

进而由连续性得 $\det F=\det F(s_0)=1$, 即 $F\in\textrm{SO}(3)$

接下来只需设

$$
F(s)=\begin{bmatrix}
  \textbf{t}(s)\\\textbf{n}(s)\\\textbf{b}(s)
\end{bmatrix}
$$

则曲线

$$
\textbf{r}(s)=\int_{s_0}^s\textbf{t}(v)\mathrm{d}v+\textbf{r}(s_0)
$$

即是我们要找的, 其中 $\textbf{r}(s_0)$ 为选定的初始值

</details>

{% endnote %}

---

{% post_link diff-geo 返回目录 %}

{% post_link diffgeo-02 下一篇笔记 %}
