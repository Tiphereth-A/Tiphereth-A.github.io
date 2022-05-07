---
title: 题解 - [Luogu P4896]【Oier们的烦恼】
categories:
  - 程序设计
  - 题解
tags:
  - 程序设计
  - 题解
  - 洛谷
  - 模拟
  - 位运算
  - 位掩码
date: 2018-11-13 22:35:58
---

[题目](https://www.luogu.com.cn/problem/P4896)

这么好的题怎么能没有"位掩码"题解呢（滑稽

<!--more-->

大致思路就是**用一个 char 来记录老师是否在机房和学生是否被抓到**（一共需要 3+5=8 位来记录, 正好是一个 char）, 再**用一个 char 记录被抓到的学生的编号**, 就像这样：

```plaintext
char in_room, dead;
//in_room的1～3位记录老师, 4～8位记录学生
```

然而为了降低调试难度, 我们可以用两个 char 分别记录老师和学生的状态, 就像这样：

```plaintext
char onlineT, onlineS, deadS;
//按字面意思理解即可
```

我们还需要定义一些函数来对它们进行操作, 就像这样（这里以宏定义为例）：

```plaintext
#define _teacher_in(i) onlineT |= 1 << i      //老师进机房
#define _teacher_out(i) onlineT &= ~(1 << i)  //老师出机房
#define _student_in(i) onlineS |= 1 << i      //学生开始玩游戏
#define _student_out(i) onlineS &= ~(1 << i)  //学生停止玩游戏
#define _dead(i) deadS&(1 << i)               //查询学生是否被发现
#define _kill_student deadS |= onlineS        //学生被发现
```

其他就没什么了, 可以参照其他题解~~没错我就是懒（理直气壮~~
