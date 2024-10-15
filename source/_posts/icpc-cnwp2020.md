---
title: 题解 - ICPC 西北区域省赛 2020
categories:
  - 算法竞赛
  - 题解
  - ICPC
tags:
  - 算法竞赛
  - 题解
  - ICPC
  - 数学
  - 数论
  - Iverson括号
  - 最小公倍数
  - 三分
  - 爬山算法
  - 图论
  - 团
  - hash
  - 前缀和
  - DP
  - 随机化
  - 虚树
  - LCA
date: 2020-11-01 00:57:43
---

感谢两位神仙队友带我

<!-- more -->

## 一些碎碎念

众所周知, 陕西不在西北地区, 云南广西都在西北地区

比赛体验极差, 开始两分钟才发密码, 比赛还一堆锅, 包括但不限于不给数据范围, 样例错误, SPJ 出锅, 数据弱, 出原题

MD 绝了

![](1.webp)

## 题目概览

| 题号[^1] | 标题[^2]                                                      | 时空限制          | AC / Total | 做法         |
| -------- | ------------------------------------------------------------- | ----------------- | ---------- | ------------ |
| A        | 披荆斩棘                                                      | 1000 ms / 256 MB  | 405 / 551  | 签到         |
| B        | 帅的研究                                                      | 2000 ms / 64 MB   | 11 / 237   | hash         |
| C        | [聚会](https://www.luogu.com.cn/problem/P3524)                | 2000 ms / 64 MB   | 7 / 298    | 思维题       |
| \*D      | 初春饰利与完美图                                              | 1000 ms / 256 MB  | 0 / 48     |              |
| E        | 御坂妹妹的芯片                                                | 1300 ms / 256 MB  | 215 / 1296 | 签到, 前缀和 |
| F        | 上条当麻与考试                                                | 2500 ms / 512 MB  | 9 / 529    | 找规律       |
| G        | 常盘台中学                                                    | 1000 ms / 256 MB  | 246 / 855  | 签到         |
| H        | Run                                                           | 1000 ms / 512 MB  | 229 / 2109 | 签到         |
| \*I      | 小 P 的烦恼                                                   | 3000 ms / 64 MB   | 0 / 7      |              |
| \*J      | 领地扩充                                                      | 1000 ms / 256 MB  | 38 / 425   | DP / 搜索    |
| K        | Tate 的魔法                                                   | 2000 ms / 256 MB  | 190 / 1475 | 签到         |
| \*L      | [藤本树与树](https://codeforces.com/problemset/problem/809/E) | 8000 ms / 512 MB  | 0 / 14     | 虚树         |
| \*M      | 作曲家                                                        | 5000 ms / 1024 MB | 2 / 47     |              |

[^1]: 打\*的是还没写的题

[^2]: 带超链接的是找到了原题或原型

## A - 披荆斩棘

### Description

早安, ACMer

一条路落叶无迹

走过我走过你我想问你的足迹

山无言水无语

走过春天 走过四季

走过春天 走过我自己

你已经是一名成熟的 ACMer, 在算法比赛中披荆斩棘, 留下属于你的足迹吧！

### Input

无

### Output

ACduck

### Sample Input 1

无

### Sample Output 1

```output1
ACduck
```

## B - 帅的研究

### Description

帅最近在研究统计, 嗯, 主要就是看看室友们的消费金额他把室友们每天的消费金额如实的统计在小本本上, 现在他看着室友们的消费记录, 他决定来整个活. 他将室友的消费记录分成很多段, 使得每段恰好有 $k$ 天($k>0$),如果这个室友消费记录统计的天数不是 $k$ 的倍数, 最后一块时间长度小于 $k$ 的时间段就被丢弃了. 帅想知道, 选择什么数字 $k$ 可以得到最多的不同的段. 注意这里的段是可以反转的, 即, 子串 `1,2,3` 和 `3,2,1` 被认为是一样的

### Input

第一行一个正整数 $n$, 表示时间的天数. 第二行 $n$ 个空格隔开的正整数 $a_1,a_2,...a_n$, 描述每天的消费金额

### Output

第一行两个空格隔开的正整数, 第一个表示能获得的最大不同的段的个数, 第二个表示能获得最大值的 $k$ 的个数. 第二行若干空格隔开的正整数 $k$, 表示所有能够取得最大值的 $k$, 请将 $k$ 按照从小到大的顺序输出

### Sample Input 1

```input1
21
1 1 1 2 2 2 3 3 3 1 2 3 3 1 2 2 1 3 3 2 1
```

### Sample Output 1

```output1
6 1
2
```

### Hint

对于 $100\%$ 的数据, $1\leq n\leq 2*10^5$, 且对于所有的 $1\leq i \leq n$, 有 $1 \leq a_i \leq n$

### 解题思路

> 比赛时:
>
> 我(思索一番): emm 这好像是关于 $k$ 的单峰函数 blablabla...
>
> 队友: emm 好像是, 那就三分
>
> 我: 等下, 这个好像不是严格单调的, 我想想怎么证
>
> 然后直到比赛结束我们都没碰这题
>
> 出考场后:
>
> 旁边队: 这就是三分+hash 啊 blablabla...
>
> 如何看待自己嘴出正解之后把自己否了的行为.txt

用 hash 是显然的, 之后有两种做法

1. 暴力枚举 $k$

   对于当前的 $k$, 一共有 $\lfloor\frac{n}{k}\rfloor$ 个段, 分别正序和逆序计算 hash 统计个数即可

   可以用进制 hash 预处理前缀 hash 和后缀 hash, 这样即可 $O(1)$ 求任意段 hash

   我们也可以加个剪枝: 记录最大种数 $S$, 如果当前 $k$ 对应的种数小于 $S$, 则后面所有的 $k$ 对应的种数都必然小于 $S$

   时间复杂度为

   $$
   \Theta\left(n+\sum_{i=1}^n\left\lfloor\frac{n}{i}\right\rfloor \right)=O(n\log n)
   $$

1. 三分, 爬山...

   显然段的种数是 $k$ 的单峰函数, 所以即使不用三分也可以爬山

   > 淦我比赛时候咋就没想起来

   也可以加个优化:

   我们知道 $\lfloor\frac{n}{k}\rfloor$ 的取值最多只有 $2\lfloor\sqrt n\rfloor$ 种

   我们记录这 $2\lfloor\sqrt n\rfloor$ 种对应的最小原象, 再对其三分

   举个例子: $n=21$, $\lfloor\frac{n}{k}\rfloor\in\{1,2,3,4,5,7,10,21\}$, 对应的最小原象构成的集合为 $\{11,8,6,5,4,3,2,1\}$, 只需在该集合上找种数最大值, 最后小范围暴力枚举答案即可

## C - 聚会

### Description

帅打算举行一次聚会. 他自然想要这次聚会成功进行. 此外, 帅确信只要邀请的嘉宾都互相认识就可以了. 他目前在试着写一份邀请名单. 帅有 $n$ 个朋友, 这里 $n$ 可以被 $3$ 整除. 幸运的是, 帅的朋友大部分都互相认识. 并且帅想起了一次他参加的聚会, 那次聚会有 $\frac{2}{3}n$​ 个他的朋友参加, 并且他们都互相认识. 不幸的是, 关于那次聚会的具体细节他不记得了... 总的来说, 他忘了是他的哪些朋友参加了. 帅认为他没有义务举办一个大型聚会, 但他想邀请至少 $\frac{n}{3}$​ 个他的朋友. 他不知道邀请谁, 所以请你帮他

### Input

输入的第一行包含两个整数 $n, m$, 表示帅的朋友数和互相认识的朋友对数

接下来 $m$ 行, 每行两个整数 $a_j,b_j$, 表示朋友 $a_j,b_j$​ 互相认识. 每一对数最多在输入中出现一次

### Output

按编号升序, 输出一行 $\frac{n}{3}$​​ 个数, 表示帅要邀请的朋友编号. 如果有多组解, 输出任意一组均可

### Sample Input 1

```input1
6 10
2 5
1 4
1 5
2 4
1 3
4 5
4 6
3 5
3 4
3 6
```

### Sample Output 1

```output1
2 4
```

### Hint

对于全部数据, $3\leq n\leq 3000,~{ \frac{2}{3}n(\frac{2}{3}n-1)\over2}\leq m\leq\frac{n(n-1)}{2},~1\leq a_i<b_i\leq n$

### 题意简述

给定一张 n 个点 m 条边的图($3\mid n$), 保证存在一个大小为 $\frac{2}{3}n$ 的团, 要求输出一个大小为 $\frac{n}{3}$​ 的团

> 来自 <https://www.luogu.com.cn/problem/P3524>

### 解题思路

> 比赛时上来就交了发并查集, 然后自然没过
>
> 后来想了个假做法交了三发没过就扔了
>
> 不过在洛谷上能过就离谱

---

> 2020.11.02 upd: 出题人没写 spj 就更离谱

先说说正解

设数组`vis[1..n]`, 其中`vis[i]`表示点`i`是否被标记

1. 令`vis[i]=0`, $\forall i\in[1,n]\cap\mathbb{N}$
1. 从`1`到`n`枚举`i`
   1. 如果`vis[i]==0`, 则
      1. 从`i+1`到`n`枚举`j`
      1. 如果`vis[j]==1`且`i`,`j`间没有边, 则
         1. `vis[i]=vis[j]=1` (因为图足够稠密, 所以这样是可行的)
         1. 跳出该循环
1. 输出 $n\over 3$ 个满足`vis[i]==0`的数`i`

然后说说我们的假做法

统计每个结点的度数, 之后按度数降序排序, 取前 $n\over 3$ 个点按编号升序排序后输出

为什么是假做法呢

我们可以构造这样的图

<details open>
<summary><font color='orange'>Show sample</font></summary>

```input1
9 24
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
2 1
2 3
6 3
4 1
2 4
4 5
4 6
7 9
8 9
9 3
9 2
9 5
9 4
9 6
1 7
1 8
```

</details>

画出来是这样的:

![](s-C-1.webp)

我们发现 $1$ 和 $9$ 的度是 $7$, $7$ 和 $8$ 的度是 $2$, 其余点的度是 $6$

按这样的做法就会输出

```output1
1 x 9
```

其中 $x\in\{2,3,4,5,6\}$

而 $1$ 和 $9$ 没有边, 所以这是错误答案

但我们看图发现, 如果改成在前 $2n\over 3$ 个点里随机取 $n\over3$ 的点就有很大概率正确, 所以加个随机化取点多交几发就过了, 也可以加个校验多次随机化取点(Las Vegas 随机)

### 复杂度

- 正解: $O(n^2)$
- 乱搞: $O(n\log n)$

### 代码参考

- 正解
  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb blog lang:cpp icpc-cnwp2020/C0.cpp %}

  </details>

- 乱搞
  <details open>
  <summary><font color='orange'>Show code</font></summary>

  {% icodeweb blog lang:cpp icpc-cnwp2020/C1.cpp %}

  </details>

## D - 初春饰利与完美图

### Description

初春饰利喜欢画画. 作为学园都市的最强黑客, 她的数据结构学的很好. 她经常画大量的有向图和无向图. 最近她定义了一个新的图类型——完美图. 如果一个无向图的所有点都只被 $1$ 个环经过且只被经过 $1$ 遍, 那么这个图就可以被称为完美图

她已经画了图的点和部分边. 但是这并没有结束. 怎么通过添加边使这个图变成完美图才是最重要的. 初春非常严格, 她不仅要求你的答案是数量最少, 并且是字典序最小的边集

### Input

第一行包含两个整数 $n$ 和 $m$($1 \leq n \leq 50, 0 \leq m \leq 2500$), 代表总共的点和初春已经画的边数. 接下来 $m$ 行, 每行有两个整数 $x_i$​ 和 $y_i$($1 \leq x_i,y_i \leq n$), 代表初春已经画的边. 初春的初始图可能包括重边和自环

### Output

第一行输出`YES`或者`NO`: 代表能不能构建一个完美图. 如果能输出`YES`, 并且在接下来一行输出一个整数 $k$, 代表了需要添加的边的数量. 再在接下来 $k$ 行, 每行输出两个整数 $x_j$​ 和 $y_j$​, 代表这些边. 结果可能包含重边和自环, $k$ 可能等于 $0$

### Sample Input 1

```input1
3 2
1 2
2 3
```

### Sample Output 1

```output1
YES
1
1 3
```

### Sample Input 2

```input2
2 0
```

### Sample Output 2

```output2
YES
2
1 2
1 2
```

### Hint

边集 $(x_1,y_1),(x_2,y_2),...,(x_n,y_n),~x_i\leq y_i$ 字典序小于边集 $(u_1,v_1),(u_2,v_2),...,(u_n,v_n),~u_i\leq v_i$​ 的条件是序列 $x_1,y_1,x_2,y_2,...,x_n,y_n$ 字典序小于序列 $u_1,v_1,u_2,v_2,...,u_n,v_n$

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/D.cpp %}

</details>

## E - 御坂妹妹的芯片

### Description

一方通行把许多御坂美琴的克隆人杀了并且获得许多芯片(数量为 $n$). 一方通行把芯片编号从 $1$ 到 $n$. 摧毁每个芯片需要花 $v_i$​ 的资源. 一方想要考考你, 他会问以下两类问题:

1. 他会告诉你两个整数, $l$ 和 $r$($1 \leq l \leq r \leq n$). 你必须告诉他 $\sum_{i=l}^r v_i$
1. 让 $u_i$​ 成为第 $i$ 少花费资源的芯片(指在非降序的排序下, 第 $i$ 个芯片). 这次他依然告诉你两个整数, $l$ 和 $r$($1 \leq l \leq r \leq n$). 你必须告诉他 $\sum_{i=1}^r u_i$​​

### Input

第一行包含一个整数 $n(1 \leq n \leq 10^5)$

第二行包含 $n$ 个整数: $v_1,v_2,v_3,....,v_n(1 \leq v_i \leq 10^9)$, 代表摧毁芯片需要的资源

第三行包含一个整数 $m(1 \leq m \leq 10^5)$, 代表一方的问题个数. 接下来 $m$ 行, 每行包含三个整数 $\textrm{type}$, $l$ 和 $r$($1\leq l\leq r\leq n;~1\leq \textrm{type}\leq 2$), 如果 $\textrm{type}=1$ 你需要回复第一个问题, 如果 $\textrm{type}=2$ 你需要回复第二个问题

### Output

输出 $m$ 行. 每行包含一个整数, 代表对一方问题的答案

### Sample Input 1

```input1
6
6 4 2 7 2 7
3
2 3 6
1 3 4
1 1 6
```

### Sample Output 1

```output1
24
9
28
```

### 题意简述

给一组数 $v_1,v_2,\dots,v_n$, $m$ 组询问, 每次询问以下之一

1. $\sum_{i=l}^r v_i$
1. $\sum_{i=l}^r u_i$, 其中 $u_1,u_2,\dots,u_n$ 是 $v_1,v_2,\dots,v_n$ 按升序排序后的数列

### 解题思路

前缀和, 没啥好说的

## F - 上条当麻与考试

### Description

上条当麻今天很早就来到学校, 因为他有一场数学考试, 没错学园都市也得学数学

这场测试是关于基础的加减法的. 小萌老师去照顾受伤的茵蒂克丝了, 没来的时间出题目

所以今天的测试只有 $1$ 道题

这道题的第一行有 $n$ 个整数. 当麻必须对这每对相邻整数进行交替的加减法, 并在下一行写下它们的和或差. 他必须重复这些步骤直到最后一行只剩下 $1$ 个整数. 题目要求第一次先加

注意哦, 如果在上一行最后是加法, 那么这一行应该是从减法开始, 反之亦然

如果最后的结果是对的, 当麻会得到满分, 如果是错的, 那么他只能得到零蛋

请你计算正确答案给当麻参考参考, 这个数字会很大, 所以最后结果请模 $10^9+7$

### Input

第一行输入一个整数 $n(1 \leq n \leq 200000)$, 代表题目第一行的数字个数

接下来一行输入 $n$ 个整数 $a_1,a_2,a_3,...,a_n$($1 \leq a_i \leq 10^9$)

### Output

输出结果模 $10^9+7$ 的答案(非负余数)

### Sample Input 1

```input1
5
3 6 9 12 15
```

### Sample Output 1

```output1
36
```

### Sample Input 2

```input2
4
3 7 5 2
```

### Sample Output 2

```output2
1000000006
```

### Hint

$$
\global\def\add#1#2{\textcolor{00ff00}{\overset{\sf\bf{ #1+#2}}{\sf\bf{+}}}}
\global\def\minus#1#2{\textcolor{ff0000}{\overset{\sf\bf{ #1-#2}}{\sf\bf{-}}}}
\begin{matrix}
    \sf\bf3& &\sf\bf6& &\sf\bf9& &\sf\bf12& &\sf\bf15\\
    &\add 3 6& &\minus 6 9& &\add 9 {12}& &\minus{12}{15}& \\
    &\sf\bf9& &\sf\bf-3& &\sf\bf21& &\sf\bf-3& \\
    & &\add 9 {(-3)}& &\minus{(-3)}{21}& &\add{21}{(-3)}& & \\
    & &\sf\bf6& &\sf\bf-24& &\sf\bf18& & \\
    & & &\minus 6 {(-24)}& &\add{(-24)}{18}& & & \\
    & & &\sf\bf30& &\sf\bf-6& & & \\
    & & & &\minus{30}{(-6)}& & & & \\
    & & & &\sf\bf36& & & & \\
\end{matrix}
$$

### 解题思路

设当前行的数为 $a_1,a_2,\dots,a_n$

我们注意到如果 $n$ 为奇数, 则经过一轮运算后变为 $a_1+a_2,a_2-a_3,...,a_{n-1}-a_n$, 当前行长度变为偶数

如果 $n$ 为偶数, 则经过两轮运算后变为 $a_1+a_3,a_2+a_4,...,a_{n-2}+a_n$, 长度仍为偶数, 且下一轮运算从减法开始

所以这个规律可细分为 4 种情况, 不过不细分也行

最后我们会发现可按照类似杨辉三角的思路解决

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/F.cpp %}

</details>

## G - 常盘台中学

### Description

在学园都市常盘台高中, 学生有五种超能力等级从 $1$ 到 $5$, 学生权力被等级所量化

在过去, 常盘台中学分为两类学生, $\texttt{science}$ 侧学生和 $\texttt{magic}$ 侧学生. 这两类学生的人数都是 $n$ 个

校长想要重新分配 $\texttt{science}$ 侧和 $\texttt{magic}$ 侧的学生, 使他们势均力敌. 用另一种话说就是让他们两侧所有等级的学生人数相等

为了实现这一点, 校长实行了交换制度, 在两侧学生中各选一名进行交换. 当然每次交换需要耗费校长一枚炮姐硬币

请问校长至少要多少枚炮姐硬币才能平衡 $\texttt{science}$ 侧和 $\texttt{magic}$ 侧？

### Input

第一行输入一个整数 $n(1 \leq n \leq 100)$, 代表了两侧的学生个数

第二行输入一串数字 $a_1,a_2,a_3...,a_n$($1 \leq a_i \leq 5$), 代表 $\texttt{science}$ 侧的每位超能力等级

第三行输入一串数字 $b_1,b_2,b_3...,b_n$($1 \leq b_i \leq 5$), 代表 $\texttt{magic}$ 侧的每位超能力等级

### Output

如果校长能平衡, 输出校长最少花费的炮姐硬币数量. 如果不能, 请输出 $-1$

### Sample Input 1

```input1
4
5 4 4 4
5 5 4 5
```

### Sample Output 1

```output1
1
```

### Sample Input 2

```input2
1
5
3
```

### Sample Output 2

```output2
-1
```

### 解题思路

设 $(c_i,d_i)=\sum_{j=1}^n([a_j=i],[b_j=i])\in\mathbb{Z}^2,~i=1,2,3,4,5$

如果 $2\nmid c_i+d_i,~i=1,2,3,4,5$, 则一定无解

否则答案就是 $\sum_{i=1}^5\frac{|c_i-d_i|}{2}$

## H - Run

### Description

Sports are definitely an integral part of the students' lives. In response to the school's call, the students decided to run in the morning. However, for various reasons, it was not practical to get up early to run every day, so Eric decided to run once a day. In other words, if Eric woke up early one day to go running, he would take $a-1$ day off, and then continue to run on day $a$, and so on

Eric's good friends, Delia and Agnes, were so inspired by Eric's commitment to exercise that they decided to do their own morning runs. In order to suit their own circumstances, Delia decided to get up early and run every day $b$, while Agnes decided to get up early and run every day $c$. One morning, Eric, Delia, Agnes and Eric decided to go for a run

One morning, Eric, Delia and Agnes met during their early morning run, and they were very excited and encouraged each other to complete a perfect morning run together. For ease of presentation, let's count the day the three students met as day $0$. Assuming that the three students run the same route and time period each time, they want to know how many days will pass before they meet on the next run. Since none of them can count, they want you to tell them the answer

### Input

Enter a line containing three positive integers $a,b,c$, which means Eric runs every $a$, Delia runs every $b$ and Agnes runs every $c$ morning

### Output

The output consists of one line with a positive integer $x$, indicating that the three students will meet on day $x$ next time

### Sample Input 1

```input1
2 3 5
```

### Sample Output 1

```output1
30
```

### Sample Input 2

```input2
3 4 6
```

### Sample Output 2

```output2
12
```

### Sample Input 3

```input3
10 100 1000
```

### Sample Output 3

```output3
1000
```

### Hint

$1\leq a,b,c\leq 100000$

### 题意简述

### 解题思路

> 比赛时:
>
> 我们仨: wc 英文题
>
> 1 秒后
>
> 我: 等下我看眼样例...emm 这不就把仨数乘起来, 啊不对, 求个 lcm 就完事了
>
> 真·面向样例编程

就是求三个数的 lcm, 搞不懂为啥开了 512MB 空间

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/H.cpp %}

</details>

## I - 小 P 的烦恼

### Description

小 P 在 A 城的首都拥有一家商店. 最近在首都的犯罪活动有所增加, 因此小 P 正在考虑在其商店的仓库中建立更好的安全性

仓库可以表示为具有 $n$ 行和 $m$ 列的矩阵. 矩阵的每个元素均为 `.`(一片空白区域)或 `x` (一堵墙)

小 P 希望雇用一些警卫人员(可能为 $0$ )来监视仓库. 每个守卫将在矩阵的某个单元中, 并将保护每个单元在其自己单元的右侧, 每个单元在其自己单元的底部, 直到最近的墙为止. 更正式地讲, 如果守卫站在牢房 $(x_0, y_0)$ 中, 那么如果满足以下所有条件, 他就会保护牢房

$(x_1, y_1)$ 中:

1. $(x_1, y_1)$ 是一个空单元格
1. $x_0 = x_1$ 且 $y_0 \leq y_1$ 或 $x_0 \leq x_1$ 且 $y_0 = y_1$
1. $(x_0, y_0)$ 和 $(x_1, y_1)$ 之间没有墙. 这些单元之间可以有一个守卫, 守卫可以互相看

警卫只能放置在空的牢房中(并且只能保护空的牢房). 放置警卫的计划是将放置警卫的一组单元格(当然, 如果第一个计划中包含至少一个单元格, 但第二个计划中不包含至少一个单元格, 则两个计划是不同的, 反之亦然). 如果不多于一个不受保护的空单元, 小 P 认为该计划是合适的

小 P 想知道合适计划的数量. 由于它可能非常大, 因此必须模 $10^7$ 输出

### Input

第一行包含两个数字 $n$ 和 $m$——仓库的长度和宽度($1 \leq n, m \leq250, 1\leq nm\leq 250$)

接着是 $n$ 行, 第 $i$ 行包含一个由 $m$ 个字符组成的字符串——代表仓库的矩阵的第 $i$ 行. 每个字符要么是 `.` , 要么是 `x`

### Output

对于每组测试数据, 一行输出一个整数代表答案

### Sample Input 1

```input1
1 3
.x.
```

### Sample Output 1

```output1
3
```

### Sample Input 2

```input2
2 2
..
..
```

### Sample Output 2

```output2
10
```

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/I.cpp %}

</details>

## J - 领地扩充

### Description

Eric 喜欢一款游戏, 游戏是在一个长方形的场地上玩. 在游戏过程中, Eric 可以扩充他的领地, 每一次(个)扩充都会将其中一个领地的大小扩大一定的倍数. 形式上, 有 $n$ 次(个)扩充, 其中第 $i$ 次(个)扩充将宽度或长度(由 Eric 选择)乘以 $a_i$​. 每从次(个)扩充不能使用一次以上, 扩充可以以任何顺序使用

现在 Eric 的领地的大小为 $h\times w$. 他想把它放大, 以便可以在上面放置一个大小为 $a\times b$ 的矩形(沿宽或沿长, 边与场边平行). 求达到 Eric 的目标所需的最小扩充数

### Input

第一行包含五个整数 $a,b,h,w$ 和 $n$($1\leq a,b,h,w,n\leq 100000$)——需要放置的矩形的大小, 领地的初始大小和可扩充次数

第二行包含 $n$ 个整数 $a_1, a_2, ..., a_n$($2\leq a_i\leq 100000$), 其中 $a_i$​ 等于应用第 $i$ 次扩充时 $a$ 面乘以的整数

### Output

打印达到 Eric 目标所需的最小扩充数. 如果不可能将矩形放置在所有延长线的区域上, 则打印 $-1$; 如果可以将矩形放置在初始区域上, 则打印 $0$

### Sample Input 1

```input1
3 3 2 4 4
2 5 4 10
```

### Sample Output 1

```output1
1
```

### Sample Input 2

```input2
3 4 1 1 3
2 3 2
```

### Sample Output 2

```output2
3
```

### 题意简述

### 解题思路

> 一个队友写 DP 漏了种情况, 另一个队友写了个折半搜索然后`sort`用错了
>
> 2020.11.02 upd: 出题人造了个锤子数据, 瞎贪心(最小边乘最大数乘到满足要求)都能过

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/J.cpp %}

</details>

## K - Tate 的魔法

### Description

Tate 对魔法非常感兴趣, 他可以通过超自然力量的干预和解释了任何奇怪而怪异的现象. 但是谁能想到, 即使按固定的数字排列, Tate 也能看到美丽而神奇的东西. Tate 偶然拿到了一块纸, 上面写着一系列数字. 他立即发现这组数字不是随机的. 经过一系列研究的结果, Tate 得出了一个奇妙的属性, 这个神奇的数组应该具有这个性质: 如果这个数组中的最大值和最小值一样的, 则说明这组子数组是有魔力的. Tate 决定与你分享这个杰出的发现, 但他请求你的帮助. 所以你必须完成他的工作. 你所要做的就是数写在纸上的原始数字数组有多少个神奇的子数组. 子数组定义为连续元素的非空序列

### Input

输入数据的第一行包含一个整数 $n$($1 \leq n \leq 10^5$). 第二行 $n$ 个数代表原始数组中的值 $a_1,a_2,....a_n$($-10^9 \leq a_i \leq 10^9$)

### Output

输出为一行: 有多少个有魔力的子数组

### Sample Input 1

```input1
4
2 1 1 4
```

### Sample Output 1

```output1
5
```

### Sample Input 2

```input2
5
-2 -2 -2 0 1
```

### Sample Output 2

```output2
8
```

### 题意简述

给一组数 $a_1,a_2,\dots,a_n$, 我们把相邻且值相同的数合成一段并统计长度, 得到新数列 $l_1,l_2,\dots,l_m$, 求 $\sum_{i=1}^m\frac{l_i(l_i+1)}{2}$

如对于样例 2, 可分为 $\{-2,-2,-2\},\{0\},\{1\}$,则 $l_1=3,l_2=1,l_3=1$

### 解题思路

$O(n)$ 直接求

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/K.cpp %}

</details>

## L - 藤本树与树

### Description

镰池和马和藤本树受够了学校无聊的时光, 于是他们决定玩一场游戏

藤本树发现了一颗带有 $n$ 个结点且从结点 $1$ 到 $n$ 的树. 这棵树是无向无环图. 每个树的结点 $v$ 都有一个值 $a_v$. 每个结点的值都不相同并且值的范围在 $1$ 到 $n$

这个游戏是这样的, 镰池和马选择一个结点 $u$, 然后轮到藤本树的回合, 藤本树选择剩下结点中的一个 $v$. 很明显总共有 $n(n-1)$ 种选法. 之后计算函数值 $f(u,v)=\varphi(a_ua_v)d(u,v)$, $\varphi(x)$ 是欧拉函数, $d(x,y)$ 是点 $x$ 和 $y$ 的在树上的最短距离

很快这个游戏又变得无聊起来, 于是他们又想了个新玩法, 对于所有可能的 $u$ 和 $v$, 计算它们的所有函数 $f$ 的期望值. 让这个值以一个不可约分数 $P\over Q$​ 来表示. 为了更有趣一点, 计算 $PQ^{-1}\pmod{10^9+7}$ 的值

### Input

第一行包含一个整数 $n$($2 \leq n \leq 2\times 10^5$), 代表树的点数

第二行包含 $n$ 个整数 $a_1,a_2,a_3,....,a_n$($1 \leq a_i \leq n$), 代表树上这些点的值

接下来 $n-1$ 行包含 $2$ 个整数 $x$ 和 $y$($1\leq x,y\leq n$), 代表这颗树的连边

### Output

输出一个值等于 $PQ^{-1}\pmod{10^9+7}$

### Sample Input 1

```input1
3
1 2 3
1 2
2 3
```

### Sample Output 1

```output1
333333338
```

### Sample Input 2

```input2
5
5 4 3 1 2
3 5
1 2
4 3
2 5
```

### Sample Output 2

```output2
8
```

### Hint

欧拉函数是小于或等于的正整数中与互质的数的数目

第一个样例:

- $u=1,v=2,f(1,2)=\varphi(a_1a_2)d(1,2)=\varphi(1\cdot2)\cdot1=\varphi(2)=1$
- $u=2,v=1,f(2,1)=f(1,2)=1$
- $u=1,v=3,f(1,3)=\varphi(a_1a_3)d(1,3)=\varphi(1\cdot3)\cdot2=2\varphi(3)=4$
- $u=3,v=1,f(3,1)=f(1,3)=4$
- $u=2,v=3,f(2,3)=\varphi(a_2a_3)d(2,3)=\varphi(2\cdot3)\cdot1=\varphi(6)=2$
- $u=3,v=2,f(3,2)=f(2,3)=2$

所以期望值为 $\frac{1}{6}(1+1+4+4+2+2)=\frac{14}{6}=\frac{7}{3}$

所以最后的值就是 $7\cdot 3^{-1}\equiv 7\cdot 333333336\equiv 333333338\pmod{10^9+7}$

### 题意简述

给定一棵 $n$ 个结点的树, 每个点有一个权值 $a[i]$, 保证 $a[i]$ 是一个 $1..n$ 的排列. 求 $\frac{1}{n(n-1)}\sum_{i=1}^n\sum_{j=1}^n\varphi(a_i*a_j)*\operatorname{dist}(i,j)$ 其中 $\varphi(x)$ 是欧拉函数, $\operatorname{dist}(i,j)$ 表示 $i,j$ 两个结点在树上的距离

> 来自 <https://www.luogu.com.cn/problem/CF809E>

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/L.cpp %}

</details>

## M - 作曲家

### Description

Jasmine 是一位作曲家, 最近她录制了两首非常受欢迎的歌曲. 现在她有很多粉丝在等着她的新歌. 这次 Jasmine 想为她的歌曲组成四个旋律. Jasmine 有一张纸, 上面写着 $n$ 个数. 她想取 $4$ 个这样的非空无交集的子序列使得它们都能组成旋律且长度之和是最大的

子序列是指在不改变其余元素顺序的情况下, 通过删除一些元素可以从另一个序列中得到的序列

当每个相邻的两个音符的绝对值相差 $1$ 或模 $7$ 同余时, 子序列形成一个旋律

你应该写一个程序, 计算四个非空的不相交的子序列的最大长度之和, 使它们全部形成一个旋律

### Input

第一行包含一个整数 $n$($4 \leq n \leq 3000$)第二行包含 $n$ 个整数 $a_1,a_2,....a_n$​($1 \leq a_i \leq 10^5$)——写在纸上的笔记

### Output

输出这四个非空, 非相交的子序列的最大长度和, 使它们全部组成旋律

### Sample Input 1

```input1
4
1 3 5 7
```

### Sample Output 1

```output1
4
```

### Sample Input 2

```input2
4
1 1 1 1
```

### Sample Output 2

```output2
4
```

### 题意简述

### 解题思路

### 复杂度

### 代码参考

<details open>
<summary><font color='orange'>Show code</font></summary>

{% icodeweb blog lang:cpp icpc-cnwp2020/M.cpp %}

</details>
