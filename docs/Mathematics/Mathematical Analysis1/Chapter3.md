---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter3 微分

***

## 3.1 微分和导数

### 微分

对函数$y=f(x)$定义域中的一点$x_0$,若存在一个只与$x_0$有关，而与$\Delta x$无关的数$g(x_0)$，使得当$\Delta x\rightarrow 0$时恒成立关系式

$$\Delta y=g(x_0)\Delta x+o(\Delta x)$$

则称函数$y=f(x)$在$x_0$处**可微**。

$\Delta x$称为**自变量的微分**，记作**dx**。

$\Delta y$称为**因变量的微分**，记作**dy**。

### 导数

若函数$f(x)$在其定义域上的一点$x_0$处极限

$$\lim\limits_{\Delta x\rightarrow 0}\frac{\Delta y}{\Delta x}=\lim\limits_{\Delta x\rightarrow 0}\frac{f(x_0+\Delta x)-f(x_0)}{\Delta x}=f'(x_0)$$

存在，则称$f(x)$在$x_0$处**可导**。

我们易知微分关系式中的$g(x_0)$即为$f'(x_0)$。

$f(x)$在$x_0$处可导的充要条件是相应的左极限和右极限存在且相等。

!!! Note
    可微一定可导，可导一定可微；可微一定连续，可导一定连续；连续不一定可微，连续不一定可导。

***

## 3.2 导数的运算法则

### 常见初等函数的导数

$$(\tan x)'=\frac{1}{\cos^2x}=\sec^2x$$

$$(\cot x)'=-\frac{1}{\sin^2x}=-\csc^2x$$

$$(\arcsin x)'=\frac{1}{\sqrt{1-x^2}}$$

$$(\arccos x)'=-\frac{1}{\sqrt{1-x^2}}$$

$$(\arctan x)'=\frac{1}{1+x^2}$$

### 反函数求导定理

若函数$y=f(x)$在$(a,b)$上严格单调、可导且$f'(x)\neq 0$,记值域为$(\alpha ,\beta)$,则它的反函数$x=f^{-1}(y)$在$(\alpha ,\beta)$上可导，且

$$[f^{-1}(y)]'=\frac{1}{f'(x)}$$

!!! Example
    **例:求$y=arctanx$的导函数。**

    设反函数$x=\tan y$  
    $(\arctan x)'=\frac{1}{(\tan y)'}=\frac{1}{\frac{1}{\cos^2y}}=\frac{1}{1+\tan^2y}=\frac{1}{1+x^2}$

### Leibniz公式

$$[f(x)·g(x)]^{(n)}=\sum\limits_{k=0}^{n}C_{n}^{k}f^{(n-k)}(x)g^{(k)}(x)$$

### 参数形式函数的求导法则

设自变量$x$和因变量$y$的函数关系由参数形式

$$\begin{cases}
x=\phi(t)\\\
y=\psi(t)
\end{cases}$$

确定，$\phi(t)$严格单调且$\phi'(t)\neq 0$

则

$$\frac{dy}{dx}=\frac{\psi'(t)}{\phi'(t)}$$

记上式为$\xi(t)$,则求$\frac{d^2y}{dx^2}$实际上是在求

$$\begin{cases}
 x=\phi(t)\\\
 \frac{dy}{dx}=\xi(t)
\end{cases}$$

的导函数，则

$$\frac{d^2y}{dx^2}=\frac{\xi'(t)}{\phi'(t)}$$

!!! Note
    $\frac{d^2y}{dx^2}\neq\frac{\psi''(t)}{\phi''(t)}$

!!! Example
    **例：求摆线  
    $\begin{cases}   
      x=t-\sin t\\\  
      y=1-\cos t\\\  
    \end{cases}$  
    的一阶导数和二阶导数。($0\leqslant t\leqslant 2\pi$)**

    设$x=\phi (t)$  
    则$\phi '(t)=1-\cos t$  
    设$y=\psi (t)$  
    则$\psi '(t)=\sin t$  
    所以$\frac{dy}{dx}=\frac{\sin t}{1-\cos t}$  
    记为$\xi (t)$  
    $\xi '(t)=\frac{1}{\cos t-1}$  
    则$\frac{d^2y}{dx^2}=-\frac{1}{(\cos t-1)^2}$  
