---
title: "关于本博客 & FAQ"
comments: false
sticky: 2147483647
date: 2020-05-04 19:07:23
---

一个数学系 ACMer 的小站, 主要记录与数学和算法竞赛相关的内容

如果**出现页面加载错误** (如 **评论区丢失**) 请刷新

<div style="text-align: center;"><div>{% button /article/about/#目录汇总 ,目录汇总, th fa-fw %}{% button /frilinks ,友链, th fa-users %}</div></div>

<!-- more -->

## 目录汇总

这里列出所有目录的链接

{% note warning %}
如无特殊说明, 除随笔外, 其余所有在目录列表中出现的文章的参考资料均在目录页
{% endnote %}

- {% post_link 高等代数 advanced-algebra %}
- {% post_link 随笔 draft %}
- {% post_link 集合论 set-theory %}
- {% post_link 生成函数 gfology %}
- {% post_link 微分几何 diff-geo %}

## 代码起手式

<details>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:cpp about/init.cpp %}

</details>

## 本博客采用的部分非通用记号/名称等

| 记号                      | 含义                                   | 例子                                                                   |
| ------------------------- | -------------------------------------- | ---------------------------------------------------------------------- |
| $\exist_1$                | 存在唯一                               | [集合论 01 定义 - 1-4](/article/set-theory/0001/#def-1-4) 中的性质 8   |
| $[a,b]_A$                 | $\{x\in A:a\leqslant x\leqslant b\}$   | {% post_link jsc2021 %}                                                |
| $a..b$                    | $[a,b]_\N$                             | [随笔 - Laplace 算子的旋转不变性](/article/draft/0019/)                |
| $\operatorname{Base}_a^b$ | $(10^b)_a$                             |
| $\operatorname{And}$      | 按位与                                 | {% post_link luogu-p2915 %}                                            |
| $\operatorname{Or}$       | 按位或                                 |
| $\operatorname{Not}$      | 按位取反                               |
| 算术-几何级数             | Arithmetico-geometric Progression, AGP | [随笔 - Arithmetico-geometric Progression (AGP)](/article/draft/0014/) |
| $\text{Prime}^+$          | $\{p\in\N/\{1\}:\varphi(p)=p-1\}$      | {% post_link powerful-num %}                                           |
| $\text{Prime}^-$          | $-1\cdot\text{Prime}^+$                |                                                                        |
| $\text{Prime}$            | $\text{Prime}^+\cup\text{Prime}^-$     |                                                                        |

## FAQ

1. 源代码缺失头文件等内容

   早期文章中可能出现该问题, 缺失的头文件等内容默认为上面的代码起手式

1. 文章缺失内容, 未填坑等

   可能是笔者忘了, 希望读者能在评论区提醒一下, 或在本博客对应的 GitHub repo 发 issue
