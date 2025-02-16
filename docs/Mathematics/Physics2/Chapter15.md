---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter15 物质波

***

**物质波函数：**

$$y(x,t)=y_0\sin(kx-\omega t),~k=\frac{2\pi}{\lambda},~\omega=2\pi\nu$$

复数形式：

$$y(x,t)=y_0e^{i(kx-\omega t)}$$

薛定谔给出的波函数：

$$\psi(x,t)=\psi_0e^{i(kx-\omega t)}=\psi_0e^{\frac{i}{\hbar}}(px-Et)$$

!!! Note
    $\hbar\omega=E$，$\hbar k=p$

**波函数的物理解释：**

$\psi\overline{\psi}dx$表示在$x$到$x+dx$这一段距离内找到这个粒子的概率。

**几率密度：**

$$p(x)=\psi\overline{\psi}=|\psi_0^2|$$

为常数，说明在任何地方找到这个粒子的概率有一样。

在$x_1$到$x_2$之间找到该粒子的几率：

$$\int_{x_1}^{x_2}p(x)dx=\int_{x_1}^{x_2}\psi\overline{\psi}dx$$

归一化：

$$\int_{-\infty}^{+\infty}p(x)dx=\int_{-\infty}^{+\infty}\psi\overline{\psi}dx=1$$

在量子力学中，动量和位置不能同时确定，如果写出了波函数，那么动量就已确定（公式中的$p$），但位置不确定。

**预期值：**

$$\overline{x}=\frac{\int_{-\infty}^{+\infty}xp(x)dx}{\int_{-\infty}^{+\infty}p(x)dx}=\int_{-\infty}^{+\infty}xp(x)dx$$

由

$$p(x)=\psi\overline{\psi}$$

$$\overline{x}\int_{-\infty}^{+\infty}x\psi\overline{\psi}dx=\int_{-\infty}^{+\infty}\overline{\psi}x\psi dx\equiv\langle\psi|x|\psi\rangle=\langle|x|\rangle$$

势能平均值：

$$\overline{U}=\int_{-\infty}^{+\infty}\overline{\psi}U(x)\psi dx\equiv\langle\psi|U(x)|\psi\rangle$$

**动量算符与能量算符：**

考虑波函数

$$\psi=\psi_0e^{i(kx-\omega t)}$$

其中，$p=\hbar k$，$E=\hbar \omega$，现要求动量平均值。

两边微分：

$$\frac{\partial \psi}{\partial x}=ik\psi_0e^{i(kx-\omega t)}$$

两边同时乘上$-i\hbar$：

$$-i\hbar\frac{\partial\psi}{\partial x}=(-i\hbar)ik\psi_0e^{i(kx-\omega t)}=\hbar k\psi_0e^{i(kx-\omega t)}=p\psi_0e^{i(kx-\omega t)}=p\psi$$

因此可得到**动量算符**：

$$p\leftrightarrow-i\hbar\frac{\partial}{\partial x}$$

对于平均值：

$$\overline{p}=\int_{-\infty}^{+\infty}\overline{\psi}(-i\hbar\frac{\partial}{\partial x})\psi dx$$

$$=\int_{-\infty}^{+\infty}\overline{\psi}(-i\hbar\frac{\partial}{\partial x})\psi_0e^{i(kx-\omega t)}dx$$

$$=\int_{-\infty}^{+\infty}\overline{\psi}(-i\hbar)ik\psi_0e^{i(kx-\omega t)}dx$$

$$=\hbar k\int_{-\infty}^{+\infty}\overline{\psi}\psi_0e^{i(kx-\omega t)}dx$$

$$=\hbar k\int_{-\infty}^{+\infty}\overline{\psi}\psi dx$$

$$=\hbar k$$

同理，若波函数两边对时间$t$微分：

$$\frac{\partial \psi}{\partial t}=-i\omega\psi_0e^{i(kx-\omega t)}$$

$$i\hbar\frac{\partial\psi}{\partial t}=\hbar\omega\psi_0e^{i(kx-\omega t)}=E\psi$$

因此可得到**能量算符**：

$$E\leftrightarrow i\hbar\frac{\partial}{\partial t}$$

$$\overline{E}=\hbar\omega$$

**薛定谔方程：**

薛定谔方程告诉我们如何获得一个非自由粒子的波函数。一个粒子的总能量：

$$E=\frac{1}{2}mv^2+U=\frac{p^2}{2m}+U$$

$$E\psi=\frac{p^2}{2m}\psi+U\psi$$

使用动量算符和能量算符：

$$i\hbar\frac{\partial}{\partial t}\psi=\frac{1}{2m}(-i\hbar\frac{\partial}{\partial x})(-i\hbar\frac{\partial}{\partial x})\psi+U\psi$$

$$i\hbar\frac{\partial}{\partial t}\psi=-\frac{\hbar^2}{2m}\frac{\partial^2}{\partial x^2}\psi+U\psi$$

更具体的形式：

$$i\hbar\frac{\partial\psi(x,t)}{\partial t}=[-\frac{\hbar^2}{2m}\frac{d^2}{dx^2}+U(x,t)]\psi(x,t)$$

此即为**一维含时薛定谔方程**。

对于一维，记

$$\hat{H}=-\frac{h^2}{2m}\frac{d^2}{dx^2}+U(x,t)$$

对于三维，记

$$\hat{H}=-\frac{h^2}{2m}\nabla^2+U(x,t)$$

因此有

$$i\hbar\frac{\partial\psi(x,t)}{\partial t}=\hat{H}\psi(x,t)$$

$\hat{H}$即为**哈密顿算符**。

**定态薛定谔方程：**

如果$U$与$t$无关$\rightarrow U(x)$，$\phi(x,t)$写成$\Psi(x)e^{i\omega t}$的形式，带入原本的薛定谔方程可以得到：

$$-\frac{\hbar^2}{2m}\frac{d^2\Psi(x)}{dx^2}+U(x)\Psi(x)=E\Psi(x)$$

**势垒隧道：**

经典力学：粒子运动到高于粒子能量$E$的势垒$U$，则无法通过。

量子力学：例子有一定的概率贯穿势垒。

应用：扫描隧道显微镜