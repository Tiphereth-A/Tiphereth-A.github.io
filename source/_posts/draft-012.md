---
title: "随笔 - Arithmetico-geometric Progression (AGP)"
categories:
  - 随笔
  - 数学
tags:
  - 随笔
  - 数学
  - 级数
  - 几何级数
  - AGP/算术-几何级数
comments: false
date: 2021-04-26 00:20:47
---

AGP(Arithmetico-geometric Progression, 没找到中文名, 暂且称为"算术-几何级数") 公式

<!-- more -->

$$
\begin{aligned}
    \sum_{i=0}^n(a+di)r^i & =\begin{cases}
                                  na+\dfrac{n(n-1)}{2}d,                                        & r=1    \\
                                  \dfrac{a(1-r^n)-(n-1)r^nd}{1-r}+\dfrac{1-r^{n-1}}{(1-r)^2}rd, & r\ne 1 \\
                              \end{cases} \\
                          & \to\begin{cases}
                                    \infty,                             & |r|\geq 1 \\
                                    \dfrac{a}{1-r}+\dfrac{rd}{(1-r)^2}, & |r|<1
                                \end{cases}\qquad(n\to+\infty)
\end{aligned}
$$
