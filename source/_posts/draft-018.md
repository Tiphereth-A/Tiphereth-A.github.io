---
title: "随笔 - Java: 基于 ScriptEngine 和 Swing 的极简科学计算器"
date: 2022-06-11 13:43:17
categories:
  - 随笔
  - Java
tags:
  - 随笔
  - Java
  - Swing
  - ScriptEngine
  - 表达式求值
---

基于 Java 8 编写

因为懒得写 parser, 所以直接用 `javax.script.ScriptEngine#eval()` 来计算表达式了, 最终的代码很短

<!-- more -->

> Nashorn JavaScript Engine 已于 Java 15 移除, 于 Java 11 废弃[^1]

<details open>
<summary><font color='orange'>Show code</font></summary>

{% include_code lang:java draft-018/Main.java %}

</details>

[^1]: [JDK-8236933](https://www.oracle.com/java/technologies/javase/15-relnote-issues.html#JDK-8236933)
