---
title: "随笔 - MATLAB 练习: 直方图, 归一化和概率分布拟合"
categories:
  - 随笔
  - MATLAB
tags:
  - 随笔
  - MATLAB
  - 直方图
  - 归一化
  - 拟合
  - 概率分布拟合
date: 2021-04-12 19:24:47
---

`histogram` 和 `fitdist` 用法一例

<!-- more -->

## 题目

以 2011 年中国 CPI 的三个增长率 (环比增长率, 同比增长率, 累计增长率) 为例

1. 根据数据做出三个增长率的直方图与折线图
1. 用某一分布拟合归一化后的直方图并给出误差

数据如下

{% include_code lang:matlab draft-009/data.m %}

## 主要命令用法简介

### histogram

#### 用途

画直方图

#### 本例中涉及的用法

- `histogram(data)`: 对给定数据画直方图
- `histogram(data, nbins)`: 指定 `bin` 数目, 对给定数据画直方图
- `histogram(data, [], name, value)`: 更改指定属性
- `Normalization`: 归一化属性, 默认为 `count`
  - `count`: 即不做处理
  - `pdf`: 概率密度函数的估计值, 使用此属性能使直方图总面积 $\leqslant 1$ ($<1$ 当且仅当数据中出现 `NaN` 等)
- `h = histogram(data)`: `h` 为直方图对象, 用于获取和修改直方图数据
- `h.Values`: 即每个 `bin` 对应的值

### fitdist

#### 用途

对给定数据和概率分布类型进行拟合

#### 本例中涉及的用法

- `pd = fitdist(x, distname)`: 对给定数据和概率分布类型进行拟合

> 实际上本题可以使用 `histfit` 命令同时绘制直方图和拟合曲线, 但因为笔者在调取其返回的句柄时出现了问题, 故未使用

## 代码与结果

### 问题 1

<details>
<summary><font color='orange'>Show code 1</font></summary>

{% include_code lang:matlab draft-009/q1.m %}

</details>

![](fig1.svg)

### 问题 2

<details>
<summary><font color='orange'>Show code 2</font></summary>

{% include_code lang:matlab draft-009/q1.m %}

</details>

![](fig2.svg)

---

## 主要参考资料

- 姜启源, 谢金星, 叶俊. 数学模型（第五版）. 高等教育出版社, 2018, 39-40
- [直方图 - MATLAB - MathWorks 中国](https://ww2.mathworks.cn/help/matlab/ref/matlab.graphics.chart.primitive.histogram.html)
- [具有分布拟合的直方图 - MATLAB histfit - MathWorks 中国](https://ww2.mathworks.cn/help/stats/histfit.html)
- [对数据进行概率分布对象拟合 - MATLAB fitdist - MathWorks 中国](https://ww2.mathworks.cn/help/stats/fitdist.html)
- [曲线拟合和分布拟合 - MATLAB & Simulink Example - MathWorks 中国](https://ww2.mathworks.cn/help/stats/curve-fitting-and-distribution-fitting.html)
