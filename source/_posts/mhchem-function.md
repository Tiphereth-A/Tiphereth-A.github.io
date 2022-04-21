---
title: mhchem指令手册-中文文档
categories:
  - 文档
tags:
  - 文档
top: 0
date: 1020-05-06 16:31:03
---

汉化自[Manual for: mhchem for MathJax, mhchem for KaTeX](https://mhchem.github.io/MathJax-mhchem/)

在将渲染引擎切换为 KaTeX 之后暂未找到开启 mhchem 的方式, 所以效果请参照原文

按笔者习惯调整了顺序

<!-- more -->

## 数学模式(math mode)/斜体

`\ce`支持嵌套`$...$`切换至数学模式(math mode)/使用斜体

$$\ce{X_$i$^$x$}$$

`\ce{X_$i$^$x$}`

$$\ce{$cis${-}[PtCl2(NH3)2]}$$

`\ce{$cis${-}[PtCl2(NH3)2]}`

$$\ce{CuS($hP12$)}$$

`\ce{CuS($hP12$)}`

可使用`~`代表空格

## 直体

- 使用`{...}`嵌套

  $\ce{ {Gluconic Acid} + H2O2}$ `\ce{ {Gluconic Acid} + H2O2}`

- 使用`-`(不应作为化学键)

  $\ce{ {(+)}_589{-}[Co(en)3]Cl3}$ `\ce{ {(+)}_589{-}[Co(en)3]Cl3}`

## 化学方程式(CE)

|                                                |                                                |
| ---------------------------------------------- | ---------------------------------------------- |
| $\ce{CO2 + C -> 2 CO}$                         | `\ce{CO2 + C -> 2 CO}`                         |
| $\ce{Hg^2+ ->[I-] HgI2 ->[I-] [Hg^{II}I4]^2-}$ | `\ce{Hg^2+ ->[I-] HgI2 ->[I-] [Hg^{II}I4]^2-}` |
| $C_p[\ce{H2O(l)}] = \pu{75.3 J // mol K}$      | `C_p[\ce{H2O(l)}] = \pu{75.3 J // mol K}`      |

## 物理单位(PU)

|                       |                       |
| --------------------- | --------------------- |
| $\pu{1.2e3 kJ/mol}$   | `\pu{1.2e3 kJ/mol}`   |
| $\pu{1,2e3 kJ//mol}$  | `\pu{1,2e3 kJ//mol}`  |
| $\pu{1.2E3 kJ mol-1}$ | `\pu{1.2E3 kJ mol-1}` |
| $\pu{1,2E3 kJ*mol-1}$ | `\pu{1,2E3 kJ*mol-1}` |

## 化学式

|              |              |
| ------------ | ------------ |
| $\ce{H2O}$   | `\ce{H2O}`   |
| $\ce{Sb2O3}$ | `\ce{Sb2O3}` |

## 离子

|                 |                 |
| --------------- | --------------- |
| $\ce{H+}$       | `\ce{H+}`       |
| $\ce{CrO4^2-}$  | `\ce{CrO4^2-}`  |
| $\ce{[AgCl2]-}$ | `\ce{[AgCl2]-}` |
| $\ce{Y^99+}$    | `\ce{Y^99+}`    |
| $\ce{Y^{99+}}$  | `\ce{Y^{99+}}`  |

## 带化学计量数

|                  |                  |
| ---------------- | ---------------- |
| $\ce{2 H2O}$     | `\ce{2 H2O}`     |
| $\ce{2H2O}$      | `\ce{2H2O}`      |
| $\ce{0.5 H2O}$   | `\ce{0.5 H2O}`   |
| $\ce{1/2 H2O}$   | `\ce{1/2 H2O}`   |
| $\ce{(1/2) H2O}$ | `\ce{(1/2) H2O}` |

$$\ce{$n$ H2O}$$

`\ce{$n$ H2O}`

## 核素

|                       |                       |
| --------------------- | --------------------- |
| $\ce{^{227}_{90}Th+}$ | `\ce{^{227}_{90}Th+}` |
| $\ce{^227_90Th+}$     | `\ce{^227_90Th+}`     |
| $\ce{^{0}_{-1}n^{-}}$ | `\ce{^{0}_{-1}n^{-}}` |
| $\ce{^0_-1n-}$        | `\ce{^0_-1n-}`        |

上标属于左边还是右边可能是不确定的, mhchem 会自动检测  
可以用`{}`指定

|                |                |
| -------------- | -------------- |
| $\ce{H{}^3HO}$ | `\ce{H{}^3HO}` |
| $\ce{H^3HO}$   | `\ce{H^3HO}`   |

## 反应式箭头

|                                           |                                           |
| ----------------------------------------- | ----------------------------------------- |
| $\ce{A -> B}$                             | `\ce{A -> B}`                             |
| $\ce{A <- B}$                             | `\ce{A <- B}`                             |
| $\ce{A <-> B}$                            | `\ce{A <-> B}`                            |
| $\ce{A <--> B}$                           | `\ce{A <--> B}`                           |
| $\ce{A <=> B}$                            | `\ce{A <=> B}`                            |
| $\ce{A <=>> B}$                           | `\ce{A <=>> B}`                           |
| $\ce{A <<=> B}$                           | `\ce{A <<=> B}`                           |
| $\ce{A ->[{text above}][{text below}] B}$ | `\ce{A ->[{text above}][{text below}] B}` |

$$\ce{A ->[$x$][$x_i$] B}$$

`\ce{A ->[$x$][$x_i$] B`

MathJax 无法正确伸长<->, <=>, <=>>和<<=>箭头 [Issue#1491](https://github.com/mathjax/MathJax/issues/1491)

## 括号

|                        |                        |
| ---------------------- | ---------------------- |
| $\ce{(NH4)2S}$         | `\ce{(NH4)2S}`         |
| $\ce{[\{(X2)3\}2]^3+}$ | `\ce{[\{(X2)3\}2]^3+}` |

`\left`和`\right`应在同一环境内

$$\ce{CH4 + 2 $\left( \ce{O2 + 79/21 N2} \right)$}$$

`\ce{CH4 + 2 $\left( \ce{O2 + 79/21 N2} \right)$}`

## 聚集状态

|                      |                      |
| -------------------- | -------------------- |
| $\ce{H2(aq)}$        | `\ce{H2(aq)}`        |
| $\ce{CO3^2-_{(aq)}}$ | `\ce{CO3^2-_{(aq)}}` |

$$\ce{NaOH(aq,$\infty$)}$$

`\ce{NaOH(aq,$\infty$)}`

## 晶系

$$\ce{ZnS($c$)}$$

`\ce{ZnS($c$)}`

$$\ce{ZnS(\ca$c$)}$$

`\ce{ZnS(\ca$c$)}`

## 含有变量(使用斜体渲染)

|                                                             |                                                             |
| ----------------------------------------------------------- | ----------------------------------------------------------- |
| $\ce{NO_x}$                                                 | `\ce{NO_x}`                                                 |
| $\ce{Fe^n+}$                                                | `\ce{Fe^n+}`                                                |
| $\ce{x Na(NH4)HPO4 ->[\Delta] (NaPO3)_x + x NH3 ^ + x H2O}$ | `\ce{x Na(NH4)HPO4 ->[\Delta] (NaPO3)_x + x NH3 ^ + x H2O}` |

如果未识别, 可使用数学模式(math mode)

## 希腊字母

MathJax 和 KaTeX 均不支持小写直体希腊字母

|                              |                              |
| ---------------------------- | ---------------------------- |
| $\ce{\mu-Cl}$                | `\ce{\mu-Cl}`                |
| $\ce{[Pt(\eta^2-C2H4)Cl3]-}$ | `\ce{[Pt(\eta^2-C2H4)Cl3]-}` |

注意希腊字母后的空格会被忽略, 可使用`{}`分割

|                                    |                                    |
| ---------------------------------- | ---------------------------------- |
| $\ce{\beta +}$                     | `\ce{\beta +}` (`+`识别为上标)     |
| $\ce{^40_18Ar + \gamma{} + \nu_e}$ | `\ce{^40_18Ar + \gamma{} + \nu_e}` |

## 化学键

|                 |                 |
| --------------- | --------------- |
| $\ce{C6H5-CHO}$ | `\ce{C6H5-CHO}` |
| $\ce{A-B=C#D}$  | `\ce{A-B=C#D}`  |

可使用`\bond`指令强制按化学键解析

|                                          |                                          |
| ---------------------------------------- | ---------------------------------------- |
| $\ce{A\bond{~}B\bond{~-}C}$              | `\ce{A\bond{~}B\bond{~-}C}`              |
| $\ce{A\bond{...}B\bond{....}C}$          | `\ce{A\bond{...}B\bond{....}C}`          |
| $\ce{A\bond{->}B\bond{<-}C}$             | `\ce{A\bond{->}B\bond{<-}C}`             |
| $\ce{A\bond{1}B\bond{2}C\bond{3}D}$      | `\ce{A\bond{1}B\bond{2}C\bond{3}D}`      |
| $\ce{A\bond{~--}B\bond{~=}C\bond{-~-}D}$ | `\ce{A\bond{~--}B\bond{~=}C\bond{-~-}D}` |

## 附加化合物

|                           |                           |
| ------------------------- | ------------------------- |
| $\ce{KCr(SO4)2*12H2O}$    | `\ce{KCr(SO4)2*12H2O}`    |
| $\ce{KCr(SO4)2.12H2O}$    | `\ce{KCr(SO4)2.12H2O}`    |
| $\ce{KCr(SO4)2 * 12 H2O}$ | `\ce{KCr(SO4)2 * 12 H2O}` |

## 氧化态

$\ce{Fe^{II}Fe^{III}2O4}$ `\ce{Fe^{II}Fe^{III}2O4}`

## 不成对电子, 自由基

|                   |                   |
| ----------------- | ----------------- |
| $\ce{OCO^{.-}}$   | `\ce{OCO^{.-}}`   |
| $\ce{NO^{(2.)-}}$ | `\ce{NO^{(2.)-}}` |

## Kröger-Vink 表示法

|                  |                  |
| ---------------- | ---------------- |
| $\ce{O''_{i,x}}$ | `\ce{O''_{i,x}}` |
| $\ce{M^{..}_i}$  | `\ce{M^{..}_i}`  |

$$\ce{$V$^{4'}_{Ti}}$$

`\ce{$V$^{4'}_{Ti}}`

$$\ce{V_{V,1}C_{C,0.8}$V$_{C,0.2}}$$

`\ce{V_{V,1}C_{C,0.8}$V$_{C,0.2}}`

$$\ce{Li^x_{Li,1-2x}Mg^._{Li,x}$V$'_{Li,x}Cl^x_{Cl}}$$

`\ce{Li^x_{Li,1-2x}Mg^._{Li,x}$V$'_{Li,x}Cl^x_{Cl}}`

## 方程式操作符

|                |                |
| -------------- | -------------- |
| $\ce{A + B}$   | `\ce{A + B}`   |
| $\ce{A - B}$   | `\ce{A - B}`   |
| $\ce{A = B}$   | `\ce{A = B}`   |
| $\ce{A \pm B}$ | `\ce{A \pm B}` |

## 沉淀与气体

$\ce{A v B (v) -> B ^ B (^)}$  
`\ce{A v B (v) -> B ^ B (^)}`

## 杂项

|                   |                   |
| ----------------- | ----------------- |
| $\ce{NO^*}$       | `\ce{NO^*}`       |
| $\ce{1s^2-N}$     | `\ce{1s^2-N}`     |
| $\ce{n-Pr}$       | `\ce{n-Pr}`       |
| $\ce{iPr}$        | `\ce{iPr}`        |
| $\ce{\ca Fe}$     | `\ce{\ca Fe}`     |
| $\ce{A, B, C; F}$ | `\ce{A, B, C; F}` |

$$\ce{Zn^2+  <=>[+ 2OH-][+ 2H+]  $\underset{\text{amphoteres Hydroxid}}{\ce{Zn(OH)2 v}}$  <=>[+ 2OH-][+ 2H+]  $\underset{\text{Hydroxozikat}}{\ce{[Zn(OH)4]^2-}}$}$$

`\ce{Zn^2+ <=>[+ 2OH-][+ 2H+] $\underset{\text{amphoteres Hydroxid}}{\ce{Zn(OH)2 v}}$ <=>[+ 2OH-][+ 2H+] $\underset{\text{Hydroxozikat}}{\ce{[Zn(OH)4]^2-}}$}`

$$\ce{$K = \frac{[\ce{Hg^2+}][\ce{Hg}]}{[\ce{Hg2^2+}]}$}$$

`\ce{$K = \frac{[\ce{Hg^2+}][\ce{Hg}]}{[\ce{Hg2^2+}]}$}`

$$\ce{$K = \ce{\frac{[Hg^2+][Hg]}{[Hg2^2+]}}$}$$

`\ce{$K = \ce{\frac{[Hg^2+][Hg]}{[Hg2^2+]}}$}`

$$\ce{Hg^2+ ->[I-] $\underset{\mathrm{red}}{\ce{HgI2}}$ ->[I-]
 $\underset{\mathrm{red}}{\ce{[Hg^{II}I4]^2-}}$}$$

`\ce{Hg^2+ ->[I-] $\underset{\mathrm{red}}{\ce{HgI2}}$ ->[I-] $\underset{\mathrm{red}}{\ce{[Hg^{II}I4]^2-}}$}`
