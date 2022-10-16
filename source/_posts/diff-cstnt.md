---
title: 学习笔记 - 差分约束
categories:
  - 算法竞赛
  - 算法
tags:
  - 算法竞赛
  - 笔记
  - 算法
  - 数学
  - 图论
  - 最短路
  - 负环
  - 不等式
  - 差分约束
date: 2020-05-11 14:39:55
---

求解如下形式不等式组的方法

$$
\begin{cases}
  x_i-x_j\leqslant c_k\\
  c_k=constant\\
  1\leqslant i,j\leqslant n\\
  k=1,2,...,m\\
\end{cases}
$$

<!-- more -->

## 差分约束系统

差分约束系统指的是一类特殊的$n$元不等式组, 该不等式组包含$n$个变量$x_1,x_2,...,x_n$和$m$条约束条件$x_i-x_j\leqslant c_k,~c_k$为常数

本博客将差分约束系统记作$\operatorname{SDC}\lang x,C\rang$,  
其中$x:=(x_1,x_2,...,x_n)\in\mathbb{P}^n, C:=\{(i,j,c_k)|c_k\in\mathbb{P},i,j\in\mathbb{N}\cap[1,n],k=1,2,...,m\}$

定义$[\operatorname{SDC}\lang x,C\rang]:=\displaystyle\bigwedge_{\mathclap{(i,j,c_k)\in C}}[x_i-x_j\leqslant c_k]$,  
显然$(\forall k\in\mathbb{P}),[\operatorname{SDC}\lang\alpha,C\rang]=[\operatorname{SDC}\lang\alpha+k\epsilon,C\rang]$

- 称$\operatorname{SDC}\lang x,C\rang$有解, 当且仅当$(\exists\alpha\in\mathbb{P}^n),[\operatorname{SDC}\lang\alpha,C\rang]=0$

- 称$\operatorname{SDC}\lang x,C\rang$无解, 当且仅当$(\forall\alpha\in\mathbb{P}^n),[\operatorname{SDC}\lang\alpha,C\rang]=0$

- 称$\operatorname{SDC}\lang x,C\rang$有无穷组解, 当且仅当$(\forall\alpha\in\mathbb{P}^n),[\operatorname{SDC}\lang\alpha,C\rang]=1$

## 差分约束

差分约束即寻找差分约束系统是否有解的方法

观察约束条件的形式, 可以发现$x_i-x_j\leqslant c_k\iff x_j\leqslant x_i+c_k$

这个形式正好与求解最短路中出现的三角不等式$dis[v]\leqslant dis[u]+w(u,v)$相对应, 这启发我们以解决最短路的方法来求解差分约束系统

我们这样建图: 对$C$中的每个三元组$(i,j,k)$, 在图中插入边$i\xrightarrow{k}j$, 另插入$n$条边$0\xrightarrow{0}i,i=1,2,...,n$(即相当于插入$n$条约束条件$x_i-x_0\leqslant0$), 令$dis[0]=0$(即相当于令$x_0=0$, 此时上一步插入的约束条件不影响结果, 求出来的解可看作非正数解)

然后即可以$0$为起点求单源最短路, 若图中无负环, 则$(dis[1],dis[2],...,dis[n])$即为一组解, 否则无解

正确性容易验证

### 常用变形技巧

- $x_i-x_j\geqslant c_k\to x_j-x_i\leqslant-c_k$
- $x_i-x_j=c_k\to\begin{cases}
  x_i-x_j\leqslant c_k\\
  x_j-x_i\leqslant-c_k
\end{cases}$
- 若$\mathbb{P}=\mathbb{Z}$
  - $x_i-x_j<c_k\to x_i-x_j\leqslant c_k-1$
  - $x_i-x_j>c_k\to x_j-x_i\leqslant -c_k-1$

## 例题

### 洛谷 P5960 [【模板】差分约束算法](https://www.luogu.com.cn/problem/P5960)

<details>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb cpa_cpp title:Luogu_P5960 Luogu/P5960/0.cpp %}

</details>

## 参考资料

- [OI Wiki - 差分约束](https://oi-wiki.org/graph/diff-constraints/)
