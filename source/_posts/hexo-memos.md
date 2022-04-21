---
title: Hexo 配置备忘录
date: 2022-04-21 20:27:33
categories:
  - Hexo
tags:
  - Hexo
---

{% note info %}

版本:

- `hexo@6.1.0`
- `hexo-theme-next@8.11.0`

{% endnote %}

修复 $\KaTeX$ 支持, 自动格式化

<!-- more -->

## 修复 KaTeX 支持

因为 NexT 对 $\KaTeX$ 的支持疏于维护, 而 MathJax 又是出了名的慢, 所以需要进行手动修复以启用 $\KaTeX$

首先, 禁用所有与数学公式支持有关的配置项 (尤其不要启用 MathJax)

如

```yaml NexT config file
# Math Formulas Render Support
# Warning: Please install / uninstall the relevant renderer according to the documentation.
# See: https://theme-next.js.org/docs/third-party-services/math-equations
# Server-side plugin: https://github.com/next-theme/hexo-filter-mathjax
math:
  # Default (false) will load mathjax / katex script on demand.
  # That is it only render those page which has `mathjax: true` in front-matter.
  # If you set it to true, it will load mathjax / katex script EVERY PAGE.
  every_page: false

  mathjax:
    enable: false
    # Available values: none | ams | all
    tags: all

  katex:
    enable: false
    # See: https://github.com/KaTeX/KaTeX/tree/master/contrib/copy-tex
    copy_tex: false
```

然后修改 NexT 设置如下

```yaml NexT config file
# Define custom file paths.
# Create your custom files in site directory `source/_data` and uncomment needed files below.
custom_file_path:
  head: source/_data/head.njk
```

在 `source/_data/head.njk` 中将 [Browser · KaTeX](https://katex.org/docs/browser.html#starter-template) 中加载脚本的三行代码复制进去即可

## 自动格式化

使用 Prettier 对 Markdown 文档进行格式化, 并通过 Git Hooks 实现每次 commit 均会自动格式化一次

如果嫌 commit 时间过长也可以借助 GitHub Action 实现自动格式化并 commit, 这里只列出基于 Git Hooks 的配置步骤

安装 [Husky](https://github.com/typicode/husky) 和 [Prettier](https://github.com/Prettier/Prettier)

{% note info %}

版本:

- `husky@7.0.4`
- `prettier@2.6.2`

{% endnote %}

```shell
npm install husky --save-dev
npm install prettier --save-dev
```

然后执行

```shell
npm set-script prepare "husky install"
npm set-script formatting "prettier --write source/"
npm run prepare
npx husky add .husky/pre-commit "npm run formatting"
```

之后每次 commit 都会格式化 `source` 中的文件了
