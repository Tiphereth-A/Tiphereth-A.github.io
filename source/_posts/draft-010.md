---
title: "随笔 - MATLAB 练习: 频谱分析之寻找峰值"
categories:
  - 随笔
  - MATLAB
tags:
  - 随笔
  - MATLAB
  - 频谱分析
  - 寻找峰值
date: 2021-04-12 19:56:47
---

`findpeaks` 用法一例

<!-- more -->

## 题目

给出 13 个 DNA 频谱的数据, 分割出这些频谱的特征

数据 [SpecData.mat](SpecData.mat) 包含如下变量

- `Spcetra`: 13 行 328 列矩阵, 每一行代表一个 DNA 频谱
- `xAxis`: 328 维向量, 表示采集数据的波长位置

## 主要命令用法简介

### findpeaks

#### 用途

寻找峰值

#### 本例中涉及的用法

- `[pks,locs] = findpeaks(data)`: 对给定数据, 寻找峰值
  - `pks`: 所有满足条件的峰值
  - `loc`: 其对应的 `x` 坐标
- `findpeaks(data, name, value)`: 更改指定属性
  - `MinPeakProminence`: 最小峰 Prominence, 大致可以理解为最小峰面积, 具体参见 [Prominence](https://ww2.mathworks.cn/help/signal/ref/findpeaks.html#buff2uu)
  - `MinPeakDistance`: 最小峰间距

## 代码与结果

> [SpecData.mat](SpecData.mat)

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:matlab draft-010/main.m %}

</details>

![](fig1.svg)

---

## 主要参考资料

- [在数据中查找峰值 - MATLAB & Simulink - MathWorks 中国](https://ww2.mathworks.cn/help/signal/ug/find-peaks-in-data.html)
- [Find local maxima - MATLAB findpeaks - MathWorks 中国](https://ww2.mathworks.cn/help/signal/ref/findpeaks.html)
- [峰值分析 - MATLAB & Simulink Example - MathWorks 中国](https://ww2.mathworks.cn/help/signal/ug/peak-analysis.html)
