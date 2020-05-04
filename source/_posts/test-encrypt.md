---
title: 测试文章 - 加密
tags:
  - 测试
password: 123456
theme: flip
date: 1000-01-01 00:00:03
comments: false
---

## 测试

```mermaid
graph LR;
A-->B
```

$$\KaTeX$$

<script>
  if (document.querySelectorAll('pre.mermaid').length) {
    NexT.utils.getScript('//cdn.jsdelivr.net/npm/mermaid@8/dist/mermaid.min.js', () => {
      mermaid.initialize({
        theme    : 'forest',
        logLevel : 3,
        flowchart: { curve     : 'linear' },
        gantt    : { axisFormat: '%m/%d/%Y' },
        sequence : { actorMargin: 50 }
      });
    }, window.mermaid);
  }
  
  // location.reload(false);
  // pjax.reload('#测试');
</script>
