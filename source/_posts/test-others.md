---
title: 测试文章 - 杂项
tags:
  - 测试
date: 1000-01-01 00:00:01
comments: false
---

DOC:

- <https://theme-next.js.org/docs/tag-plugins>
- <https://www.u2sb.com/pages/748f02/>

<!--more-->

## 文本居中引用

{% cq %}Elegant in code, simple in core{% endcq %}

## 提示

{% note default %}
Welcome to [Hexo!](https://hexo.io)
{% endnote %}

{% note primary This is a summary %}
Note with summary: `note primary This is a summary`
{% endnote %}

{% note success %}
{% code %}
code block in note tag
code block in note tag
code block in note tag
{% endcode %}
{% endnote %}

## 标签

Lorem {% label @ipsum %} {% label primary@dolor sit %} amet, consectetur {% label success@adipiscing elit, %} sed {% label info@do eiusmod %} tempor incididunt ut labore et dolore magna aliqua.

Ut enim _{% label warning @ad %}_ minim veniam, quis **{% label danger@nostrud %}** exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

Duis aute irure dolor in reprehenderit in voluptate ~~{% label default @velit %}~~ <mark>esse</mark> cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

## 选项卡

{% tabs First unique name %}

<!-- tab -->

**This is Tab 1.**

<!-- endtab -->

<!-- tab -->

**This is Tab 2.**

<!-- endtab -->

<!-- tab -->

**This is Tab 3.**

<!-- endtab -->

{% endtabs %}

## 按钮

{% btn #, Text %}{% btn #, Text & Title,, Title %}

---

Lorem {% btn #, Lorem, home fa-fw fa-lg %} ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident {% btn #, Ipsum, home fa-fw fa-lg %}, sunt in culpa qui officia deserunt mollit anim id est laborum.

---

<style>
div.text-center {
    text-align: center;
}
</style>

<div class="text-center"><div>{% btn #,, heading %}{% btn #,, fab fa-edge %}{% btn #,, times %}{% btn #,, circle-notch %}</div>
<div>{% btn #,, italic %}{% btn #,, fab fa-scribd %}</div>
<div>{% btn #,, fab fa-google %}{% btn #,, fab fa-chrome %}{% btn #,, fab fa-opera %}{% btn #,, gem fa-rotate-270 %}</div></div>

---

<div class="text-center">{% btn #, Previous Chapter, arrow-left fa-fw fa-lg, Previous Chapter (Full Image) %} {% btn #, Next Chapter, arrow-right fa-fw fa-lg, Next Chapter (Label) %}</div>

## Link Grid

{% linkgrid %}
Theme NexT | https://theme-next.js.org/ | Stay Simple. Stay NexT. | /images/apple-touch-icon-next.png
Theme NexT | https://theme-next.js.org/ | Stay Simple. Stay NexT. | /images/apple-touch-icon-next.png
Theme NexT | https://theme-next.js.org/ | Stay Simple. Stay NexT. | /images/apple-touch-icon-next.png
Theme NexT | https://theme-next.js.org/ | Stay Simple. Stay NexT. | /images/apple-touch-icon-next.png
% Theme NexT | https://theme-next.js.org/ | Stay Simple. Stay NexT. | /images/apple-touch-icon-next.png
{% endlinkgrid %}

## 插入 PDF

{% pdf /archives/test-others/test.pdf 600px %}

## 插入视频

### manim 示例 - SquareToCircle

{% mmedia "video" "src:/archives/test-others/SquareToCircle.mp4" %}

### Bilibili 视频 - BV1C4411u7rK

{% mmedia "bilibili" "bvid:1C4411u7rK" "quality:high" "danmaku" "allowfullscreen" %}
