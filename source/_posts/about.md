---
title: "关于本博客 & FAQ"
comments: false
sticky: 2147483647
date: 2020-05-04 19:07:23
---

![](/images/TifaBlog_ba-style@nulla.top.webp)

一个数学系 ACMer 的小站, 主要记录与数学和算法竞赛相关的内容

<div style="text-align: center;"><div>{% button /archives/about/#目录汇总 ,目录汇总, th fa-fw %}{% button /frilinks ,友链, th fa-users %}</div></div>

<!-- more -->

## 目录汇总

- {% post_link drafts 随笔 %}
- {% post_link academic-waste 学术垃圾 %}

## 本博客采用的部分非通用记号/名称等

| 记号                      | 含义                                      | 例子                         |
| ------------------------- | ----------------------------------------- | ---------------------------- |
| $\exists_1$               | 存在唯一                                  | {% post_link setth-01 %}     |
| $[a,b]_A$                 | $\{x\in A:a\leqslant x\leqslant b\}$      | {% post_link jsc2021 %}      |
| $a..b$                    | $[a,b]_\mathbb{N}$                        |                              |
| $\operatorname{Base}_a^b$ | $(10^b)_a$                                |                              |
| $\operatorname{And}$      | 按位与                                    | {% post_link luogu-p2915 %}  |
| $\operatorname{Or}$       | 按位或                                    |                              |
| $\operatorname{Not}$      | 按位取反                                  |                              |
| $\text{Prime}^+$          | $\{p\in\mathbb{N}/\{1\}:\varphi(p)=p-1\}$ | {% post_link powerful-num %} |
| $\text{Prime}^-$          | $-1\cdot\text{Prime}^+$                   |                              |
| $\text{Prime}$            | $\text{Prime}^+\cup\text{Prime}^-$        |                              |

## FAQ

1. 源代码缺失头文件等内容

   早期文章中可能出现该问题, 缺失的头文件等内容默认为上面的缺省源

1. 文章缺失内容, 未填坑等

   可能是笔者忘了, 希望读者能在评论区提醒一下, 或在本博客对应的 GitHub repo 发 issue
