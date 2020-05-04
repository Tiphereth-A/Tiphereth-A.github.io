---
title: 笔记 - 原根与指数(离散对数)
categories:
  - 笔记
  - 数学
  - 初等数论
tags:
  - 数学
  - 笔记
  - 数论
  - 阶
  - 原根
  - 离散对数
date: 2020-04-18 22:54:50
---

## 阶

对 $\gcd(a,m)=1$, $\operatorname{ord}_ma:=\min\{l\in\Bbb{N}^+|a^l\equiv1\pmod m\}$

<!--more-->

### 性质

1. $\operatorname{ord}_ma=l\implies\operatorname{ord}_ma^t=\frac{l}{(l,t)}$
   - $espc.\ l\perp t\implies\operatorname{ord}_ma=\operatorname{ord}_ma^t$
1. $a^k\equiv1\pmod m\iff\operatorname{ord}_ma\mid k$
   1. $espc.\ \operatorname{ord}_ma\mid\varphi(m)$
   1. 这条性质给出了求阶的方法, 即在 $\varphi(m)$ 中找出这样的最小因子, 该因子满足定义, 同时**该因子的所有素因子**不满足定义
   1. 设 $\operatorname{ord}_ma=l$, 则 $a^0,...,a^{l-1}$ 两两不同余
   1. 设 $p$ 是素数, 若 $l|\varphi(p)$, 则有 $\varphi(l)$ 个两两不同余的数的阶为 $l$
   1. 若 $m=\displaystyle\prod_{i=1}^kp_i^{\alpha_i}$, 则 $\operatorname{ord}_ma=\operatorname{lcm}(\operatorname{ord}_{p_1}a,...,\operatorname{ord}_{p_k}a)$

## 原根

对 $\gcd(a,m)=1$, 若 $\operatorname{ord}_ma=\varphi(m)$, 则称 $a$ 是模 $m$ 的原根

有原根的群 $\Bbb{Z}_m^*$ 为**循环群**

### 性质

1. 模 $m$ 具有原根 $\iff m\in\{n\in\Bbb{N}^+|(n=p^\alpha)\lor (n=2p^\alpha), p\in\{prime\},\alpha\in\Bbb{N}^+\}$
1. $g$ 是模 $m$ 的原根 $\implies\{g^l|1\leqslant l\leqslant\varphi(m),l\perp\varphi(m)\}\implies$ 模 $m$ 的原根有 $\varphi(\varphi(m))$ 个

## 指数(离散对数)

设 $g$ 为模 $m$ 原根, $\operatorname{ind}_ga=k\iff a\equiv g^k\pmod m$

看定义就知道为什么指数又被叫做离散对数

### 性质

1. 设 $a,b\perp m$,
   1. $a\equiv b\pmod m\iff\operatorname{ind}_ga=\operatorname{ind}_gb$
   1. $\operatorname{ind}_g(ab)\equiv\operatorname{ind}_ga\operatorname{ind}_gb\pmod{\varphi(m)}$ <u>**(注意是 $\varphi(m)$ 不是 $m$)**</u>
      1. $\operatorname{ind}_g(a^n)\equiv n\operatorname{ind}_ga\pmod{\varphi(m)}$
   1. 若 $g_1$ 也是模 $m$ 原根, 则 $\operatorname{ind}_ga\equiv\operatorname{ind}_{g_1}a\operatorname{ind}_gg_1\pmod{\varphi(m)}$
1. 与 $k$ 次剩余的关系, 令 $d=\gcd(k,\varphi(m))$

   1. $a$ 为模 $m$ 的 $k$ 次剩余 $\iff d\mid\operatorname{ind}_ga\iff a^\frac{\varphi(m)}{d}\equiv1\pmod m$
   1. $a$ 为模 $m$ 的 $k$ 次剩余

      $\implies|\{x|x^k\equiv a\pmod m\}|=d,\{x|x^k\equiv a\pmod m\}=\{\overline{g^{(\frac{k}{d})^{-1}{\operatorname{ind}_ga\over d}+i\frac{\varphi(m)}{d}}}|i=0,...,d-1\}$

   1. 模 $m$ 的 $k$ 次剩余共 $\frac{\varphi(m)}{d}$ 个, 分别为 $a\equiv g^{di},i=0,...,\frac{\varphi(m)}{d}-1$
