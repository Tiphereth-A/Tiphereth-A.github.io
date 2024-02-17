---
title: "随笔 - 批量重命名 APK 文件的 Python 脚本"
date: 2024-02-17 20:43:13
categories:
  - 随笔
  - Python
tags:
  - 随笔
  - Python
  - 脚本
---

为了方便整理文件, 我简单搓了个 Python 脚本来按一定格式批量重命名 APK 文件

<!-- more -->

## 使用方式

把脚本文件放到想要重命名的文件夹里然后运行即可, 脚本会进行如下操作:

1. 递归遍历当前文件夹和子文件夹
2. 找出文件名为 `*.{apk,1}` 的所有文件
3. 使用 <https://github.com/appknox/pyaxmlparser> 来解析 APK 的文件信息, 并按 `<应用名>-<包名>-<版本名>(<版本号>).apk` 的格式重命名, 若重名则删除文件

## 代码

{% include_code lang:python draft-026/rename_apk.py %}
