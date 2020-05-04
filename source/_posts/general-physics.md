---
title: 课程笔记 - 普通物理
categories:
  - 笔记
  - 物理
tags:
  - 笔记
  - 物理
date: 2021-01-23 20:20:40
---

期末复习写的, 十分粗糙(尤其力学部分)

<!-- more -->

## Ch 1. 质点运动

### 三种坐标系

- 直角坐标系
  - $\bm{r}=x\bm{i}+y\bm{j}+z\bm{k}$
  - $\bm{v}=v_i\bm{i}+v_j\bm{j}+v_k\bm{k}$
  - $\bm{a}=a_i\bm{i}+a_j\bm{j}+a_k\bm{k}$
- 极坐标系

  - $\bm{\rho}=\rho\bm{e_{\rho}}$
  - $\bm{v}=\displaystyle{\mathrm{d}\rho\over\mathrm{d}t}\bm{e_{\rho}}+\rho{\mathrm{d}\theta\over\mathrm{d}t}\bm{e_{\theta}}=:v_{\rho}\bm{e_{\rho}}+v_{\theta}\bm{e_{\theta}}$
  - $\bm{a}=\displaystyle\left({\mathrm{d}^2\rho\over\mathrm{d}t^2}-\rho\left({\mathrm{d}\theta\over\mathrm{d}t}\right)^2\right)\bm{e_{\rho}}+\left(2{\mathrm{d}\rho\over\mathrm{d}t}{\mathrm{d}\theta\over\mathrm{d}t}+\rho{\mathrm{d}^2\theta\over\mathrm{d}t^2}\right)\bm{e_{\theta}}=:a_{\rho}\bm{e_{\rho}}+a_{\theta}\bm{e_{\theta}}$

  定义 $\displaystyle\omega:={\mathrm{d}\theta\over\mathrm{d}t},~\beta:={\mathrm{d}^2\theta\over\mathrm{d}t^2}$

  则

  - $v_{\theta}=\rho\omega$
  - $a_{\rho}=\displaystyle{\mathrm{d}v_{\rho}\over\mathrm{d}t}-\rho\omega^2$
  - $a_{\theta}=2v_{\rho}\omega+\rho\displaystyle{\mathrm{d}\omega\over\mathrm{d}t}=2v_{\rho}\omega+\rho\beta$

- 自然坐标系

  - $\bm{v}=v\bm{e_{\tau}}$
  - $\bm{a}=\displaystyle{\mathrm{d}v\over\mathrm{d}t}\bm{e_{\tau}}+v{\mathrm{d}\theta\over\mathrm{d}t}\bm{e_n}=:a_{\tau}\bm{e_{\tau}}+a_n\bm{e_n}$

  设 $\rho$ 为曲率半径, 则 $a_n=\displaystyle\frac{v^2}{\rho}$

### 万有引力

- $$
  \bm{F}=-G\frac{m_1m_2}{r^3}\bm{r}
  $$
- $$
  \bm{F}=-G\frac{m_1m_2}{\rho^2}\bm{e_{\rho}}
  $$

#### <a href="#end-prob-1.1.1" id="prob-1.1.1">例题 - 1.1.1</a>

证明 Kepler 行星第二定律

##### <a href="#prob-1.1.1" id="p-prob-1.1.1">解</a>

$$
\bm{F}=-\displaystyle G{m_{earth}m\over\rho^2}\bm{e_{\rho}}
$$

$$
\bm{a}=-G\displaystyle{m_{earth}\over\rho^2}\bm{e_{\rho}}=a_{\rho}\bm{e_{\rho}}+a_{\theta}\bm{e_{\theta}}\implies\begin{cases}
  \displaystyle\left({\mathrm{d}^2\rho\over\mathrm{d}t^2}-\rho\left({\mathrm{d}\theta\over\mathrm{d}t}\right)^2\right)=-G\displaystyle{m_{earth}\over\rho^2}\\
  \displaystyle\left(2{\mathrm{d}\rho\over\mathrm{d}t}{\mathrm{d}\theta\over\mathrm{d}t}+\rho{\mathrm{d}^2\theta\over\mathrm{d}t^2}\right)=0
\end{cases}
$$

又单位时间扫过面积为

$$
{\mathrm{d}S\over\mathrm{d}t}=\frac{1}{2}\rho^2{\mathrm{d}\theta\over\mathrm{d}t}
$$

而

$$
{\mathrm{d}^2S\over\mathrm{d}t^2}=\frac{1}{2}\rho\left(2{\mathrm{d}\rho\over\mathrm{d}t}{\mathrm{d}\theta\over\mathrm{d}t}+\rho{\mathrm{d}^2\theta\over\mathrm{d}t^2}\right)=0
$$

故成立

<a href="#p-prob-1.1.1" id="end-prob-1.1.1">$\Box$</a>

## Ch 3. 动量守恒定律

### 质心

$$
\bm{r}_c={\sum_n m_i\bm{r}_i\over\sum_n m_i}=\frac{\sum_n m_ix_i}{\sum_n m_i}\bm{i}+\frac{\sum_n m_iy_i}{\sum_n m_i}\bm{j}+\frac{\sum_n m_iz_i}{\sum_n m_i}\bm{k}
$$

若质量连续分布, 则

$$
\bm{r}_c={\int x\mathrm{d}m\over\int\mathrm{d}m}\bm{i}+{\int y\mathrm{d}m\over\int\mathrm{d}m}\bm{j}+{\int z\mathrm{d}m\over\int\mathrm{d}m}\bm{k}
$$

### 质心运动定理

$$
\sum_n\bm{F}_i=m\bm{a}_c
$$

{% note info %}
电磁场具有动量 (p71)
{% endnote %}

### 变质量系统 (发射火箭)

$$
v-v_0=u\ln N
$$

- $u$: 喷射速度
- $N$: 质量比 $\frac{m_0}{m}$

## Ch 4. 角动量守恒定律

### 力矩

$$
\bm{M}:=\bm{r}\times\bm{F}=\begin{vmatrix}
  \bm{i}&\bm{j}&\bm{k}\\
  x&y&z\\
  F_x&F_y&F_z
\end{vmatrix}=:M_x\bm{i}+M_y\bm{j}+M_z\bm{k}
$$

#### 求分量

1. 利用 $\bm{r},\bm{F}$ 的正射影求 $M_z$
1. 定义

### 角动量

$$
\bm{l}:=\bm{r}\times m\bm{v}
$$

### 角动量定理

$$
\bm{M}={\mathrm{d}\bm{l}\over\mathrm{d}t}
$$

质点对力心的角动量守恒

### 质点系角动量守恒定律

$$
\bm{M}_{out}={\mathrm{d}\bm{L}\over\mathrm{d}t}
$$

## Ch 5. 刚体力学

### 刚体的转动惯量

$$
J=\int r^2\mathrm{d}m=\int r^2\rho\mathrm{d}V
$$

$$
E_k=\frac{1}{2}J\omega^2
$$

#### 影响因素

- 质量
- 转轴位置
- 质量分布

#### 平行轴定理&垂直轴定理

- 平行轴定理

  $$
  J_d=J_c+md^2
  $$

- 垂直轴定理

  $$
  J_x=J_y+J_z+\iiint_Vr^2\mathrm{d}m
  $$

### 转动量与平动量关系

$$
M\longleftrightarrow F
$$

$$
\alpha\longleftrightarrow a
$$

$$
J\longleftrightarrow m
$$

$$
\omega\longleftrightarrow v
$$

$$
L\longleftrightarrow p
$$

---

$$
E_k=\frac{1}{2}J\omega^2
$$

$$
\mathrm{d}A=M_z\mathrm{d}\theta
$$

$$
P=M_z\omega
$$

$$
L_z=J\omega
$$

$$
M_z\mathrm{d}t=\mathrm{d}L_z
$$

### 固体的形变和弹性

比例极限 -> 弹性极限 -> 塑性极限 -> 强度极限

加工硬化

#### 弹性模量和切变模量

$\epsilon_n=\frac{\Delta l}{l}$, $\sigma_n=\frac{F_n}{S}$

$\epsilon_t=\tan\psi\sim\psi~(\psi\to0)$ ($\psi:$ 剪切角), $\sigma_t=\frac{F_t}{S}$ ($S:$ 横截面)

$\sigma_n=E\epsilon_n$

$\sigma_t=G\epsilon_t$

对大多数各向同性且均匀的固体材料, $G\thickapprox 0.4E$

## Ch 6. 流体力学

### 理想流体及其连续性方程

- 理想流体
- 定常流动
- 流线
- 流管

#### 连续性方程

$$
\mathrm{d}Q_V=v\mathrm{d}S
$$

{% note warning %}
流量的量纲为 $L^3$
{% endnote %}

理想流体: $Sv=\texttt{const}$

一般流体: $\rho Sv=\texttt{const}$ (质量)

平均流速: $\bar{v}=\displaystyle\frac{Q_V}{S}$

### Bernouli 方程

$$
\frac{1}{2}\rho v^2+\rho gh+p=\texttt{const}
$$

水平流管: $p+\frac{1}{2}\rho v^2=\texttt{const}$

### 粘性流体

- 层流
- 速率梯度
- 粘度
  - 与温度:
    - 液体: 负相关
    - 气体: 正相关

$$
F=\pm\eta\left({\mathrm{d}v\over\mathrm{d}z}\right)_{z_0}\Delta S
$$

#### 运动规律

$$
p_1+\frac{1}{2}\rho v_1^2+\rho gh_1=p_2+\frac{1}{2}\rho v_2^2+\rho gh_2+w
$$

减小粘性损耗:

- 减小 $p_1-p_2$
- 减小 $h_1-h_2$

#### Poiseuille 定律

$$
Q_V=\frac{\pi}{8\eta}\left(\frac{p_1-p_2}{l}\right)r^4
$$

($l:$ 长度, $r:$ 半径)

水平圆管道: $w=\displaystyle\frac{8\eta l}{r^2}\bar{v}$

#### 湍流和 Reynolds 数

- 湍流: $w\propto \bar{v}^2$
- Reynolds 数: $Re=\displaystyle\frac{\rho vr}{\eta}$
- 临界 Reynolds 数 $Re_c$ (**范围**)
- 临界流速 $v_c=\displaystyle\frac{Re_c\eta}{\rho r}$ (**范围**)

#### Stokes 粘性公式

$$
F=6\pi\eta rv
$$

## Ch 7. 振动和波动

### 简谐振动

$$
x=A\cos(\omega t+\varphi)
$$

$$
v=A\omega\sin(\omega t+\varphi)
$$

$$
E=\frac{1}{2}kA^2
$$

$$
v^2=\omega^2(A^2-x^2)
$$

### 简谐振动的叠加

#### 同一直线同频率

$$
A=\sqrt{A_1^2+A_2^2-2A_1A_2\cos(\varphi_2-\varphi_1)}\in[|A_1-A_2|,A_1+A_2]
$$

$$
\varphi=\frac{A_1\sin\varphi_1+A_2\sin\varphi_2}{A_1\cos\varphi_1+A_2\cos\varphi_2}
$$

#### 同一直线频率相近

$$
A=\sqrt{A_1^2+A_2^2-2A_1A_2\cos((\omega_2-\omega_1)t+\varphi_2-\varphi_1)}\in[|A_1-A_2|,A_1+A_2]
$$

拍频 $\nu=2A\cos(\frac{\omega_2-\omega_1}{2}t)=|\nu_2-\nu_1|$

#### 互相垂直

- 频率相同:

  $x=A\cos(\omega t+\alpha),~y=A\cos(\omega t+\beta)$

  $$
  \frac{x^2}{A^2}+\frac{y^2}{B^2}-\frac{2xy}{AB}\cos(\beta-\alpha)=\sin^2(\beta-\alpha)
  $$

  椭圆

  - $\beta-\alpha=0~or~\pi$: 两条相交线段
  - $\beta-\alpha=\pm\frac{\pi}{2}$: 以坐标轴为主轴的椭圆

- 频率不同:
  - 有整数比: 李萨如图形
  - 无整数比: 准周期运动

## Ch 9. 气体, 固体和液体的基本性质

### 理想气体的压强和温度

$$
p=\frac{1}{3}nm_0\bar{v^2}=\frac{2}{3}n\bar{\epsilon}_k
$$

$$
p=nkT
$$

$$
\bar{\epsilon}_k=\frac{1}{2}m_0\bar{v^2}=\frac{3}{2}kT
$$

## Ch 10. 电荷和静磁场

### 电荷, Coulomb 定律, 电场, 电场强度

#### 电荷守恒定律 (P244)

一个与外界**没有电荷交换**的孤立系统, 无论发生什么变化, 整个系统的电荷**总量**(正负电荷的代数和)保持不变

#### 电偶极子 (P251)

$r\gg l$ 时, 由一对电荷量相等, 符号相反的点电荷组成的系统称作**电偶极子**

由负电荷到正电荷引出的有向线段 $\bm{l}$ 称作电偶极子的**轴**

**电矩**: $\bm{p}:=q\bm{l}$

性质: 电偶极子中垂面上任意一点的电场强度 $E=-{\bm{p}\over 4\pi\epsilon_0r^3}$

#### 无限长均匀带电细棒在某一点处的电场强度 (P252, 258)

$$
\bm{E}=\frac{\lambda}{2\pi\epsilon_0 a}\bm{j}
$$

### Gauss 定理

#### 电场强度通量

- 对非闭合的曲面 $S$: $\Phi_e:=\int_S\bm{E}\cdot\mathrm{d}\bm{S}$
- 对闭合的曲面 $S$: $\Phi_e:=\oint_S\bm{E}\cdot\mathrm{d}\bm{S}$

  规定法线 $\bm{e}_n$ 的正方向为垂直于曲面且指向闭合曲面外部

#### Gauss 定理

$$
\oint_S\bm{E}\cdot\mathrm{d}\bm{S}=\frac{1}{\epsilon_0}\int_V\rho\mathrm{d}V
$$

或

$$
\nabla\cdot\bm{E}=\frac{\rho}{\epsilon_0}
$$

证明: 由 Stokes 公式易得

> Gauss 面内无电荷 $\impliedby\atop{\Longrightarrow}\llap{/\enspamathrm}$ Gauss 面上的电场强度处处为零

#### 均匀带电球体在某一点处的电场强度 (P259)

### 电势及其与电场强度的关系

#### 静电场的环路定理 (P261)

$$
\oint_L\bm{E}\cdot\mathrm{d}\bm{l}=0
$$

> 保守场 $\implies\atop{\Longleftarrow}\llap{/\thickspamathrm}$ 无旋场 (<https://dxwl.bnu.edu.cn/CN/Y1985/V1/I2/48>)

#### 电势, 电势能, 功

$$
V_P=\frac{W_P}{q_0}=\int_P^{\infty}\bm{E}\cdot\mathrm{d}\bm{l}
$$

$$
A_{PQ}=W_P-W_Q
$$

#### 电势的计算

以无穷远点为零电势点

$$
V_p=\frac{1}{4\pi\epsilon_0}\int{\mathrm{d}q\over r}
$$

#### 电势与电场强度的关系

$$
\bm{E}=-\nabla V
$$

- 电势梯度: $\nabla V$, 电势面法线方向的电势变化率, 方向沿电势增大方向

  $$
  \nabla V=\frac{\partial V}{\partial n}\bm{e}_n
  $$

#### 电偶极子 (P267)

$$
V={\bm{p}\cdot\bm{r}\over4\pi\epsilon_0r^3}
$$

$$
E_r=\frac{1}{4\pi\epsilon_0}\frac{2p\cos\theta}{r^3}
$$

$$
E_{\theta}=\frac{1}{4\pi\epsilon_0}\frac{p\sin\theta}{r^3}
$$

### 静电场中的金属导体

#### 处于静电平衡的导体具有的性质 (P269)

1. 整个导体为等势体, 导体表面为等势面
1. 导体表面附近的电场强度处处与表面垂直
1. 导体内部不存在净电荷

#### 导体表面的电荷和电场

- 电场强度大小与电荷面密度成正比
- 尖端放电
- 电晕

#### 导体空腔

1. 内表面不存在净电荷, 所有净电荷只分布在外表面
1. 腔内无电场, 电势处处相等
1. 若腔内存在带电体, 则内表面带有和带电体等量异号的电荷

#### 应用

- 静电屏蔽
- 场致发射显微镜
- Van de Graaff 静电高压起电机
- 避雷针
- Coulomb 平方反比律的精确验证

#### 两平行导体平板电荷面密度 (P274)

### 电容和电容器

#### 电容的计算 (10-6-3)

- 平行板电容器: $C=\frac{\epsilon_0S}{d}$
- 同心球形电容器: $C=\frac{1}{4\pi\epsilon_0}\left(\frac{1}{R_A}-\frac{1}{R_B}\right)$
- 同轴柱形电容器: $C=\frac{2\pi\epsilon_0l}{\ln R_B-\ln R_A}$
- 平行无限长直导线 (单位长度) (P277): $C=\frac{\pi\epsilon_0}{\ln d-\ln a}$

#### 电容器的连接

- 串联: $\frac{1}{C}=\sum_n\frac{1}{C_n}$
- 并联: $C=\sum_nC_n$

### 静电场中的电介质

- 绝缘体都属于电介质
- 在外加电场的作用下, 电介质表面也会产生电荷 (极化)

- 无极分子电介质 ($\mathrm{H_2}, \mathrm{N_2}, \mathrm{CH_4}$) 位移极化
- 有极分子电介质 ($\mathrm{SO_2}, \mathrm{H_2S}, \mathrm{HCl}$) 取向极化

#### 极化强度矢量 (P279)

$$
\bm{P}:={\sum\bm{p}\over\Delta\tau}
$$

单位: $\mathrm{C\cdot m^{-2}}$

- 均匀极化

$$
\sigma'=\bm{P}\cdot\bm{e}_n
$$

$$
\oint_S\bm{P}\cdot\mathrm{d}\bm{S}=-\int_V\mathrm{d}q
$$

- 退极化场

平行板电容器 $\implies$

- 极化率 $\chi_e$

  对各向同性的电介质, $\bm{P}=\chi_e\epsilon_0\bm{E}$ (P281)

- 相对电容率 $\epsilon_r:=1+\chi_e$
- 绝对电容率 $\epsilon:=\epsilon_0\epsilon_r$

**当电容器两极板间电容率变为 $\epsilon_r$ 倍时, 电容变大 $\epsilon_r$ 倍**

#### 电介质存在时的 Gauss 定理

$$
\oint_S\bm{D}\cdot\mathrm{d}\bm{S}=\int_V\rho\mathrm{d}V
$$

$$
\nabla\cdot\bm{D}=\rho
$$

- 电位移 $\bm{D}:=\epsilon_0\bm{E}+\bm{P}$

  对各向同性的电介质: $\bm{D}=\epsilon\bm{E}$

#### 边界条件

- 从一种介质过渡到另一种介质, 电位移的法向分量不变
- 从一种介质过渡到另一种介质, 电场强度的切向分量不变

### 静电场中的能量

- **能量定域于场**

- 平行板电容器极板间能量 $W_e=\frac{Q^2}{2C}=\frac{1}{2}QU_{AB}=\frac{1}{2}CU_{AB}^2$
- 平行板电容器中静电能能量密度 $w_e=\frac{1}{2}DE$

  真空中, $w_e=\frac{1}{2}\epsilon_0E^2$

- 非匀强电场中, $w_e=\frac{1}{2}DE$, $W_e=\int_Vw_e\mathrm{d}V$
- 各向异性电介质中, $w_e=\frac{1}{2}\bm{D}\cdot\bm{E}$, $W_e=\int_Vw_e\mathrm{d}V$

## Ch 11. 电流和恒磁场

### 恒定电流条件和导电规律

- 电流密度

  $$
  \bm{j}={\mathrm{d}I\over\mathrm{d}S}\bm{e}_n
  $$

  单位: $\mathrm{A\cdot m^{-2}}$

- $$
  I=\int_S\bm{j}\cdot\mathrm{d}\bm{S}
  $$

  电流就是电流密度通量

- 电流场
- 电流线
- 电流管

#### 电流连续性方程

单位时间内流出闭合曲面 $S$ 的电荷量等于同一时间内 $S$ 所包围的电荷量的减少, 即

$$
\oint_S\bm{j}\cdot\mathrm{d}\bm{S}=-{\mathrm{d}q\over\mathrm{d}t}=-{\mathrm{d}\over\mathrm{d}t}\int_V\rho\mathrm{d}V
$$

或

$$
\nabla\cdot\bm{j}=-\frac{\partial\rho}{\partial t}
$$

#### 恒定电流

电流场不随时间变化的电流

$$
\oint_S\bm{j}\cdot\mathrm{d}\bm{S}=0
$$

$$
\nabla\cdot\bm{j}=0
$$

- Coulomb 电场: 恒定电场与静电场

- 电导 $G$

#### 电阻率

$$
\rho:=\frac{E}{j}
$$

- $$
  R=\rho\frac{l}{S}
  $$
- 对于金属材料, 通常温度范围内, $\rho=\rho_0(1+\alpha t)$

  - $\rho$: $t\degree\!\mathrm{C}$ 时的电阻率
  - $\rho_0$: $0\degree\!\mathrm{C}$ 时的电阻率
  - $\alpha$: 电阻温度系数

- 电导率 $\sigma$

#### Ohm 定律的微分形式

$$
\bm{j}=\sigma\bm{E}
$$

- 在变化的电流场中依然成立

### Biot-Savart 定律

$$
\mathrm{d}\bm{B}=\frac{\mu_0}{4\pi}{I\mathrm{d}\bm{l}\times\bm{r}\over r^3}
$$

整条导线 $L$: $\bm{B}=\frac{\mu_0}{4\pi}\int_L{I\mathrm{d}\bm{l}\times\bm{r}\over r^3}$

#### 无线长直导线在某一点处产生的磁感应强度 (P306)

$$
B=\frac{\mu_0I}{2\pi a}
$$

#### 环形导线在轴线上某一点处产生的磁感应强度 (P307)

$$
B={\mu_0R^2\over2(R^2+a^2)^\frac{3}{2}}
$$

#### 沿直线运动的电荷在某瞬间在某一点处产生的磁感应强度 (P307)

$$
\bm{B}=\frac{\mu_0}{4\pi}{q\bm{v}\times\bm{r}\over r^3}=\mu_0\epsilon_0\bm{v}\times\bm{E}=\frac{1}{c^2}\bm{v}\times\bm{E}
$$

#### 磁矩

- 圆形电流: $\bm{m}:=nIS\bm{e}_n$

  $\bm{e}_n$ 指向与 $I$ 满足**右螺旋关系**

### 磁场的 Gauss 定理和 Ampère 环路定理

#### 恒定电流磁场的 Gauss 定理

$$
\oint_S\bm{B}\cdot\mathrm{d}\bm{S}=0
$$

$$
\nabla\cdot\bm{B}=0
$$

#### Ampère 环路定理

$$
\oint_L\bm{B}\cdot\mathrm{d}\bm{l}=\bm{\mu}_0\sum_{i}I_i
$$

积分方向与电流方向满足右螺旋时取正值, 满足左螺旋时取负值

又由

$$
\oint_L\bm{B}\cdot\mathrm{d}\bm{l}=\int_S(\nabla\times\bm{B})\cdot\mathrm{d}\bm{S}
$$

$$
\sum_iI_i=\int_S\bm{j}\cdot\mathrm{d}\bm{S}
$$

则有微分形式

$$
\nabla\times\bm{B}=\mu_0\bm{j}
$$

- 磁场不是保守场

#### 螺线管内一点的磁感应强度 (P310)

$$
B=\mu_0nI
$$

- 只适用于真空中或非铁磁材料中

#### 螺绕环内的磁感应强度 (P311)

$$
B=\mu_0nI
$$

- 只适用于真空中或非铁磁材料中

### 磁场对电流的作用

#### Ampère 定律

$$
\mathrm{d}\bm{F}=I\mathrm{d}\bm{l}\times\bm{B}
$$

$$
\bm{F}=\int_LI\mathrm{d}\bm{l}\times\bm{B}
$$

#### 两平行长直导线的相互作用

单位长度所受力

$$
f=\frac{\mu_0}{4\pi}\frac{2I_1I_2}{a}
$$

电流方向相同则相互吸引

#### 磁场对载流线圈的作用

规定线圈平面法向于电流方向满足右螺旋关系

$$
\bm{M}=\bm{m}\times\bm{B}
$$

$\alpha:=\lang\bm{B},\bm{m}\rang$

- 匀强磁场中:
  - $\alpha=0$, $\bm{M}=\bm{0}$, 稳定平衡
  - $\alpha=\pi$, $\bm{M}=\bm{0}$, 不稳定平衡
  - $\alpha=\frac{\pi}{2}$, $\bm{M}$ 最大
  - 向 $\alpha$ 减小方向转动

在非匀强磁场中, 线圈在转动之外, 还会向磁场较强的方向运动

### 带电粒子在磁场中的运动

- 磁聚焦
- Hall 效应

  Hall 系数 $K_H=\frac{1}{nq}$

### 磁介质的磁化

- 磁介质

- 顺磁质
- 铁磁质
- 抗磁质

- 磁化
- 磁化强度: 单位体积内分子磁矩矢量和

  $$
  \bm{M}:={\sum\bm{m}\over\Delta\tau}
  $$

- 均匀磁化

#### 磁化电流

$i'$

螺线管内部:

- $$
  M=i'
  $$
- $$
  \bm{B}=\bm{B}_0+\mu_0\bm{M}
  $$

#### 磁化强度与磁化电流的关系

$$
\oint_L\bm{M}\cdot\mathrm{d}\bm{l}=\sum_{\text{In}~L}I'
$$

- 介质表面: $\bm{M}\times\bm{e}_n=\bm{i}'$

  介质表面磁化电流密度只与磁化强度沿表面的切向分量有关, 而与法向分量无关

#### 有磁介质的 Ampère 环路定理

- 磁场强度
  $$
  \bm{H}:={\bm{B}\over\mu_0}-\bm{M}
  $$

$$
\oint_L\bm{H}\cdot\mathrm{d}\bm{l}=\int_V\bm{j}_0\cdot\mathrm{d}\bm{S}
$$

其中 $\bm{j}_0$ 为传导密度, $S$ 是以 $L$ 为边界的曲面

$$
\nabla\times\bm{H}=\bm{j}_0
$$

- 对于各向同性的顺磁质和抗磁质

  - 磁化率 $\chi_m$
    $$
    \bm{M}=\chi_m\bm{H}
    $$
  - 相对磁导率 $\mu_r:=1+\chi_m$
    $$
    \bm{B}=\mu_0\mu_r\bm{H}
    $$
  - 绝对磁导率 $\mu:=\mu_0\mu_r$

  - 顺磁质: $\chi_m>0,\mu_r\gtrapprox 1$
  - 铁磁质: $\chi_m,\mu_r$ 均很大, 且是 $\bm{M}$ 的非单值函数
  - 抗磁质: $\chi_m<0,\mu_r\lessapprox 1$
  - 真空: $\chi_m=0,\mu_r=1$

#### 边界条件

- 从一种介质过渡到另一种介质, 磁感应强度的法向分量不变
- 从一种介质过渡到另一种介质, 磁场强度的切向分量不变

#### 对比

|                | 电                      | 公式                                                                 | 磁                      | 公式                                                                       |
| -------------- | ----------------------- | -------------------------------------------------------------------- | ----------------------- | -------------------------------------------------------------------------- |
| 物理量         | 极化强度 $\bm{P}$       |                                                                      | 磁化强度 $\bm{M}$       |
|                |                         | $\displaystyle\bm{P}:={\sum\bm{p}\over\Delta\tau}$                   |                         | $\displaystyle\bm{M}:={\sum\bm{m}\over\Delta\tau}$                         |
|                |                         | $\bm{P}\cdot\bm{e}_n=\sigma'$                                        |                         | $\bm{M}\times\bm{e}_n=\bm{i}'$                                             |
|                |                         | $\displaystyle\oint_S\bm{P}\cdot\mathrm{d}\bm{S}=-\int_V\mathrm{d}q$ |                         | $\displaystyle\oint_L\bm{M}\cdot\mathrm{d}\bm{l}=\int_V\bm{j}'\mathrm{d}V$ |
|                | 电位移 $\bm{D}$         |                                                                      | 磁场强度 $\bm{H}$       |
|                |                         | $\bm{D}:=\epsilon_0\bm{E}+\bm{P}$                                    |                         | $\bm{H}:={\bm{B}\over\mu_0}-\bm{M}$                                        |
|                | 极化率 $\chi_e$         |                                                                      | 磁化率 $\chi_m$         |
|                | 相对电容率 $\epsilon_r$ |                                                                      | 相对磁导率 $\mu_r$      |
|                |                         | $\epsilon_r:=1+\chi_e$                                               |                         | $\mu_r:=1+\chi_m$                                                          |
|                | 绝对电容率 $\epsilon$   |                                                                      | 绝对磁导率 $\mu$        |
|                |                         | $\epsilon:=\epsilon_0\epsilon_r$                                     |                         | $\mu:=\mu_0\mu_r$                                                          |
| 各向同性情况下 |                         | $\bm{P}=\chi_e\epsilon_0\bm{E}$                                      |                         | $\bm{M}=\chi_m\bm{H}$                                                      |
| 边界条件       | $\bm{D}$ 的法向分量不变 |                                                                      | $\bm{B}$ 的法向分量不变 |
|                | $\bm{E}$ 的切向分量不变 |                                                                      | $\bm{H}$ 的切向分量不变 |

### 铁磁性

- 自发磁化强度
- 居里温度
  - 铁磁质 -> 顺磁质
- 磁畴
  - 外加磁场较小时
  - 外加磁场较大时
- 磁滞现象

  - 饱和磁化强度 $M_s$
  - 剩余磁化强度 $M_r$
  - 矫顽力 $H_c$
  - 磁滞回线

  - 软磁材料
  - 硬磁材料
  - 矩磁材料
  - 微波磁材料

## Ch 12. 电磁感应和 Maxwell 电磁理论

### 电磁感应及其基本规律

- 感应电荷

  $$
  q_i=\int_{t_1}^{t_2}I_i\mathrm{d}t=\int_{\Phi_1}^{\Phi_2}-\frac{1}{R}\mathrm{d}\Phi=\frac{\Phi_1-\Phi_2}{R}
  $$

- 动生电动势
  - 不闭合导体
    $\epsilon_i=\int_L(\bm{v}\times\bm{B})\mathrm{d}\bm{l}$
  - 闭合导体
    $\epsilon_i=\oint_L(\bm{v}\times\bm{B})\mathrm{d}\bm{l}$
- 感生电动势

  - 不闭合导体
    $\epsilon_i=\int_L\bm{E}_W\mathrm{d}\bm{l}$
  - 闭合导体
    $\epsilon_i=\oint_L\bm{E}_W\mathrm{d}\bm{l}$

- 全电场 $\bm{E}=\bm{E}_C+\bm{E}_W$

  $$
  \oint_L\bm{E}\cdot\mathrm{d}\bm{l}=-\int_S{\partial\bm{B}\over\partial t}\cdot\mathrm{d}\bm{S}
  $$

  $$
  \nabla\times\bm{E}=-{\partial\bm{B}\over\partial t}
  $$

- 感生电场与磁场变化率成**左螺旋**关系

### 互感和自感

#### 互感

$$
\Phi_{12}=M_{12}I_1
$$

- 互感电动势

  $$
  \epsilon_2=-{\mathrm{d}\over\mathrm{d}t}(M_{12}I_1)
  $$

  线圈的**形状**, **大小**和**相对位置**保持不变时

  $$
  \epsilon_2=-M_{12}{\mathrm{d}I_1\over\mathrm{d}t}
  $$

- $M_{12}=M_{21}$
- 当线圈内或周围空间没有**铁磁质**时, $M$ 仅由线圈**几何形状**, **大小**, **匝数**和**相对位置**决定
- 若线圈内或周围空间存在**非铁磁质**时, $M$ 还与磁介质的**磁导率**有关
- 当线圈内或周围空间存在**铁磁质**时, $M$ 还与线圈中的**电流**有关

- 单位: $\mathrm{H}$, $1\mathrm{ H}=1\mathrm{ Wb\cdot A^{-1}}=1\mathrm{ V\cdot s\cdot A^{-1}}$

- 互感干扰

#### 自感

$$
\Phi=LI
$$

- 自感电动势
  $$
  \epsilon=-{\mathrm{d}\over\mathrm{d}t}(LI)
  $$
  线圈的**形状**, **大小**保持不变, 且不存在**铁磁质**时
  $$
  \epsilon=-L{\mathrm{d}I\over\mathrm{d}t}
  $$
- 单位: $\mathrm{H}$, $1\mathrm{ H}=1\mathrm{ Wb\cdot A^{-1}}=1\mathrm{ V\cdot s\cdot A^{-1}}$

- 自感电弧

#### 两嵌套螺线管的互感 (P10)

$$
M=\mu_0\frac{N_1N_2}{l}S
$$

#### 螺线管的自感 (P10)

$$
L=\mu n^2V
$$

#### 两线圈串联后的自感

$L_1,L_2,M$

- 顺接 $L=L_1+L_2+2M$
- 反接 $L=L_1+L_2-2M$

### 涡流和趋肤效应

- 涡流
- 电磁阻尼
- 趋肤效应

### 磁场的能量

- 磁场能量密度 $w_m$

  $$
  w_m=\int_0^BH\mathrm{d}B
  $$

  适用于真空和各向同性的磁介质

  - 各向同性的顺磁质和抗磁质

    $$
    w_m=\frac{1}{2}BH
    $$

    $$
    W_m=\int_Vw_m\mathrm{d}V=\frac{1}{2}\int_VBH\mathrm{d}V
    $$

    - 由各向同性的顺磁质或抗磁质作为磁芯的螺线管 (自感磁能)

      $$
      W_m=\frac{1}{2}LI^2
      $$

- 电磁场
  - 能量密度 $w=\frac{1}{2}(\bm{E}\cdot\bm{D}+\bm{B}\cdot\bm{H})$
  - 能量 $\displaystyle W=\frac{1}{2}\int_V(\bm{E}\cdot\bm{D}+\bm{B}\cdot\bm{H})\mathrm{d}V$

### 超导体的电磁特性

- 临界温度 $T_C$
- 临界磁场

  $$
  B_C(T)=B_0\left(1-\left(\frac{T}{T_C}\right)^2\right)
  $$

- 超导态: $T<T_C$ 且 $B<B_C$

- 临界电流

  $$
  I_C(T)=I_0\left(1-\left(\frac{T}{T_C}\right)^2\right)
  $$

  $I>I_C$ 时, 超导态变为正常态

- 零电阻性
  - 不存在随时间变化的磁场 ($\displaystyle{\partial\bm{B}\over\partial t}=-\nabla\times\bm{E}=0$)
- 完全抗磁性 (Meissner 效应)

> 完全抗磁性与零电阻性是超导体两种**独立**的基本性质

- 同位素效应 $T\propto A_r^{-1/2}$

  电子与晶格之间的相互作用是超导现象中的重要因素

### Maxwell 电磁理论

#### 位移电流

$$
\bm{j}_d:={\partial\bm{D}\over\partial t}=\epsilon{\partial\bm{E}\over\partial t}+{\partial\bm{P}\over\partial t}
$$

- 全电流密度 $\bm{j}:=\bm{j}_0+\bm{j}_d$

#### Maxwell 方程组

适用于恒静和变化的电磁场

- Gauss 定理

  $$
  \oint_S\bm{D}\cdot\mathrm{d}\bm{S}=\int_V\rho_0\mathrm{d}V
  $$

- 电场环路定理

  $$
  \oint_L\bm{E}\cdot\mathrm{d}\bm{l}=-\int_S{\partial\bm{B}\over\partial t}\cdot\mathrm{d}\bm{S}
  $$

- 磁场的 Gauss 定理

  $$
  \oint_S\bm{B}\cdot\mathrm{d}S=0
  $$

- Ampère 环路定理

  $$
  \oint_L\bm{H}\cdot\mathrm{d}\bm{l}=\int_S\left(\bm{j}_0+{\partial\bm{D}\over\partial t}\right)\cdot\mathrm{d}\bm{S}
  $$

##### 积分形式

$$
\begin{cases}
  \oint_S\bm{D}\cdot\mathrm{d}\bm{S}&=\int_V\rho_0\mathrm{d}V\\
  \oint_L\bm{E}\cdot\mathrm{d}\bm{l}&=-\int_S{\partial\bm{B}\over\partial t}\cdot\mathrm{d}\bm{S}\\
  \oint_S\bm{B}\cdot\mathrm{d}S&=0\\
  \oint_L\bm{H}\cdot\mathrm{d}\bm{l}&=\int_S\left(\bm{j}_0+{\partial\bm{D}\over\partial t}\right)\cdot\mathrm{d}\bm{S}
\end{cases}
$$

##### 微分形式

$$
\begin{cases}
  \nabla\cdot\bm{D}&=\rho_0\\
  \nabla\times\bm{E}&=-{\partial\bm{B}\over\partial t}\\
  \nabla\cdot\bm{B}&=0\\
  \nabla\times\bm{H}&=\bm{j}_0+{\partial\bm{D}\over\partial t}
\end{cases}
$$

##### 边界条件

$$
\begin{cases}
  D_{1n}=D_{2n}\\
  E_{1t}=E_{2t}\\
  B_{1n}=B_{2n}\\
  H_{1t}=H_{2t}
\end{cases}
$$

##### 对真空中和各向同性的介质

- 在遇到电磁场与物质的相互作用时需补充
  $$
  \begin{cases}
    \bm{D}&=\epsilon_0\epsilon_r\bm{E}\\
    \bm{B}&=\mu_0\mu_r\bm{H}\\
    \bm{j}_0&=\sigma\bm{E}
  \end{cases}
  $$
- 存在非静电性电场 $K$ 时, $\bm{j}_0=\sigma(\bm{E}+\bm{K})$

### 电磁波的产生和传播

#### LC 振荡电路

$$
f={1\over2\pi\sqrt{LC}}
$$

- 发射电磁波的条件
  - 频率高
  - 电路开放

#### 偶极振子

- 平均能流密度 $\bar{S}=\frac{1}{2}E_0H_0$

  - 性质:

    - 正比于频率的四次方
    - 反比于离开振子中心的平方
    - 正比于 $\sin^2\theta$ ($\theta$ 为传播方向与极轴的夹角), 具有强烈的方向性, 垂直于轴线方向的辐射最强, 沿轴线方向的辐射为 $0$

- 瞬时能流密度 $\bm{S}=\bm{E}\times\bm{H}$

## Ch 13. 电路和磁路

### Kirchhoff 定律

#### Kirchhoff 第一定律

汇集于同一结点的各支路电流代数和为 $0$

- 约定流出结点的电流为正, 流入结点的电流为负

#### Kirchhoff 第二定律

在一个回路中, 电阻电势降代数和等于电源电动势代数和

- 约定
  - 电流沿绕行方向时, 电势降为正
  - 电源电动势沿绕行方向时为正

### 交流电和交流电路的基本概念

#### 物理量

##### 阻抗和相位差

$$
Z:=\frac{U_0}{I_0}=\frac{U}{I}
$$

> 因为相位差, 所以瞬时值不能写成类似关系

$$
\varphi:=\varphi_u-\varphi_i
$$

#### 纯电阻

$$
Z=R,\varphi=0
$$

> 阻抗仅在频率不太高的时候成立 (趋肤效应)

$$
u(t)=U_0\cos\omega t
$$

$$
i(t)=I_0\cos\omega t
$$

#### 纯电感

$$
Z=\omega L,\varphi=\frac{\pi}{2}
$$

$$
u(t)=U_0\cos\omega t
$$

$$
i(t)=I_0\cos(\omega t-\frac{\pi}{2})
$$

#### 纯电容

$$
Z=\frac{1}{\omega C},\varphi=-\frac{\pi}{2}
$$

$$
u(t)=U_0\cos\omega t
$$

$$
i(t)=I_0\cos(\omega t+\frac{\pi}{2})
$$

### 交流电路的矢量图解法

- RL 串联
- RC 并联

### 交流电路的复数解法

$$
\tilde{U}=U_0e^{j(\omega t+\varphi_u)}
$$

$$
\tilde{I}=I_0e^{j(\omega t+\varphi_i)}
$$

$$
\tilde{Z}={\tilde{U}\over\tilde{I}}=Ze^{j\varphi}
$$

#### 电阻

$$
\tilde{Z}_R=R
$$

#### 电感

$$
\tilde{Z}_L=j\omega L
$$

#### 电容

$$
\tilde{Z}_C=\frac{1}{j\omega C}
$$

#### 串联电路

$$
\tilde{U}=\sum_i\tilde{U_i}
$$

$$
\tilde{Z}=\sum_i\tilde{Z_i}
$$

#### 并联电路

$$
\tilde{I}=\sum_i\tilde{I_i}
$$

$$
{1\over\tilde{Z}}=\sum_i{1\over\tilde{Z_i}}
$$

#### Kirchhoff 方程组

$$
\sum\pm\tilde{I}=0
$$

$$
\sum\pm\tilde{I}\tilde{Z}=\sum\pm\tilde{E}
$$

#### RLC 串联电路

$$
\tilde{Z}=R+j\left(\omega L-\frac{1}{\omega C}\right)
$$

- $\omega<{1\over\sqrt{LC}}$: 电压落后电流, 表现为容抗性

### 交流电的功率

#### 瞬时功率

$$
p(t)=u(t)i(t)=\frac{1}{2}U_0I_0(\cos\varphi+\cos(2\omega t-\varphi))=UI(\cos\varphi+\cos(2\omega t-\varphi))
$$

> 和差化积: $\cos\varphi+\cos(2\omega t-\varphi)=2\cos\omega t\cos\varphi$

#### 平均功率

$$
P=\frac{1}{T}\int_0^Tp(t)\mathrm{d}t=UI\cos\varphi
$$

- $\cos\varphi$: 功率因数, 有功功率在视在功率中所占比例

  - 纯电阻电路: $P=UI$
  - 纯电感/纯电容电路: $P=0$, 正值功率等于负值功率

- 视在功率

  $$
  S=UI
  $$

  单位: $\mathrm{V\cdot A}$

  - 额定视在功率 (容量)

- 有功功率

  $$
  P=I^2Z\cos\varphi=I^2\Re\tilde{Z}
  $$

  单位: $\mathrm{W}$

- 无功功率

  $$
  P_q=I^2Z\sin\varphi=I^2\Im\tilde{Z}
  $$

  单位: $\mathrm{Var}$

$$
S^2=P^2+P_q^2
$$

### 磁路和磁路定律

#### 磁介质分界面上磁感应线的折射

$$
\frac{\tan i}{\tan r}={\mu_{r1}\over\mu_{r2}}
$$

#### 磁路

- 漏磁

- 串联磁路
- 并联磁路

#### 磁路定律

- 单回路

  $$
  NI_0=\Phi\sum_i\frac{l_i}{\mu_iS_i}
  $$

  - $NI_0$: 磁通势, $\epsilon_m$
  - $\frac{l_i}{\mu_iS_i}$: 磁阻, $R_{mi}$
  - $\Phi R_{mi}$: 磁势降落

  $$
  \epsilon_n=\Phi\sum_iR_{mi}
  $$

  闭合磁路磁通势等于各段磁路上的磁势降落之和

- 有效磁导率 (与相同空心螺绕环的比值) $\mu_e:=\frac{\Phi}{\Phi_0}$

- 开气隙使磁导率大幅下降, 但能极大改善器件的温度稳定性

## Ch 14. 光学

### 光波及其相干条件

- 波速 $u={1\over\sqrt{\epsilon\mu}}$
- 折射率 $n=\frac{c}{u}=\sqrt{\epsilon_r\mu_r}$
- 能量密度 $w=\frac{1}{2}\epsilon E^2+\frac{1}{2}\mu H^2$
- 能流密度 $S=wu=EH$
  - 坡印廷矢量 $\bm{S}=\bm{E}\times\bm{H}$
- 强度 $I=\bar{S}=\frac{n}{2\mu c}E_0^2$
- 相对强度 $I=E_0^2$

- 沿 $r$ 方向传播的平面电磁波 $\bm{E}=\bm{E}_0\cos(\omega t-\bm{k}\cdot\bm{r}+\varphi_0)$

#### 光程

$l=nx$

- 等光程原理

#### 干涉

- 频率相同
- 存在互相平行的振动分量
- 具有固定的相位关系

- 干涉加强 光程差为半波长偶数倍
- 干涉减弱 光程差为半波长奇数倍

#### 获得相干波的方法

##### 分波前法

- 杨氏双缝干涉

  - 光程差 $\Delta=\frac{2a}{D}x$
  - 亮条纹条件 $2\frac{r_2-r_1}{\lambda}=2k$ (光程差为半波长偶数倍)

    $x=\frac{D}{2a}2k\frac{\lambda}{2}$

  - 暗条纹条件 $2\frac{r_2-r_1}{\lambda}=2k+1$ (光程差为半波长奇数倍)

    $x=\frac{D}{2a}(2k+1)\frac{\lambda}{2}$

##### 分振幅法

- 薄膜干涉

  - 等倾干涉
    - 光程差 $\Delta=2ne\cos r+\frac{\lambda}{2}$
  - 等厚干涉

    - 光程差 $\Delta=2ne+\frac{\lambda}{2}$

    - 空气劈尖
      - 厚度 $h=\frac{\lambda}{2l}L$, $l$ 相邻条纹间距
    - Newton 环
      - 气隙厚度 $e=\frac{r^2}{2R}$
      - 暗环半径 $r=\sqrt{kR\lambda}$

- Michelson 干涉
  - 干涉环移过 $m$ 个条纹, 平移距离 $d=m\frac{\lambda}{2}$

##### 分振动面法

- 偏振光干涉

### 衍射

#### Fresnel 衍射

#### Fraunhofer 衍射

- 单缝

  - 光强 $I_P=I_0(\frac{\sin\alpha}{\alpha})^2$
  - $\alpha=\frac{\delta}{2}=\frac{\pi a}{\lambda}\sin\varphi$

  - $\alpha=0$: 主极大
  - $\alpha=k\pi$: 暗条纹
    - 第一暗条纹的衍射角 $\varphi_0=\arcsin\frac{\lambda}{a}\approx\frac{\lambda}{a}$
  - 次极大 $A_p=A_0\frac{\sin\alpha}{\alpha}$

  - 明纹条件 ${\mathrm{d}A_p\over\mathrm{d}\alpha}=0\implies\tan\alpha=\alpha$

- 圆孔
  - 中央亮斑半角宽度 $1.22\frac{\lambda}{D}$, 半径 $1.22\frac{\lambda f}{D}$
  - Rayleigh 判据
    - 最小分辨角 $\theta_0=1.22\frac{\lambda}{D}$
    - 光学系统分辨率 $1\over\theta_0$

---

## 主要参考资料

- 物理学 (第五版). 刘克哲, 张承琚, 刘建强, 宋洪晓. 2018.8
