---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Chapter1 Logic and Proofs

***

## 1.1 Propositional Logic 

**Logical Connectives:**  

character|abbreviation|English|Chinese  
:---:|:---:|:---:|:---:  
$\neg$|NOT|negation|否定  
$\wedge$|AND|conjunction|合取  
$\vee$|OR|disjunction|析取  
$\oplus$|XOR|exclusive or operator|异或  
$\rightarrow$|IF-THEN|implication|蕴含  
$\leftrightarrow$|IF AND ONLY IF|biconditional|双条件命题  

**Implication:**

p|q|p $\rightarrow$ q  
:---:|:---:|:---:  
T|T|T  
T|F|F  
F|T|T  
F|F|T  

**Different Ways of Expressing $p\rightarrow q$:**

* $q$ unless $\neg p$  
* $p$ only if $q$  
* $p$ is sufficient for $q$  
* $q$ is necessary for $p$  

**Converse, Contrapositive and Inverse:**

* $q\rightarrow p$ is the **converse（逆）** of $p\rightarrow q$  
* $\neg q\rightarrow$$\neg p$ is the **contrapositive（逆否）** of $p\rightarrow q$  
* $\neg p\rightarrow$$\neg q$ is the **inverse（反）** of $p\rightarrow q$

**Precedence of Logic Operators:**

operator|precedence  
:---:|:---  
$\neg$|1  
$\wedge$|2  
$\vee$|3  
$\rightarrow$|4  
$\leftrightarrow$|5  

***

## 1.2 Applications of Propositional Logic

**Consistence:**

A list of propositions is **consistent** if it is 
possible to assign truth values to the proposition 
variables so that each proposition is true. 

对于一连串的命题，可以找到一个变量的赋值方法，使得这些命题都为真。

!!! Example
    * "The diagnostic message is stored in the buffer or it is retransmitted."    
    * "The diagnostic message is not stored in the buffer."    
    * "If the diagnostic message is stored in the buffer, then it is retransmitted."    

    $p$: "The diagnostic message is stored in the buffer"    
    $q$: "The diagnostic message is retransmitted"   
    When $p$ is false and $q$ is true, all three statements are true.   
    So the specification is consistent.  

***

## 1.3 Propositional Equivalences

**Tautologies, Contradictions and Contingencies:**

* **tautology（永真式）**   
  永远为真的命题  
* **contradiction（矛盾式）**   
  永远为假的命题  
* **contingency（可能式）**   
  可能为真可能为假的命题  

如果 $p\leftrightarrow q$ 为永真式，则 $p$ 和 $q$ 逻辑等价。  

**De Morgan's Laws:**

* $\neg(p\wedge q)\equiv\neg p\vee \neg q$  
* $\neg(p\vee q)\equiv\neg p\wedge \neg q$  

**Dual（对偶）:**  

The **dual** of compound proposition that contains only the logical operators $\vee$, $\wedge$ and $\neg$ is the proposition obtained by replacing  each $\vee$ by $\wedge$, each $\vee$ by $\wedge$, each $T$ by $F$ and each $F$ by $T$.   

把 $\wedge$ 换成 $\vee$，把 $\vee$ 换成 $\wedge$，把 $T$ 换成 $F$ ，把 $F$ 换成 $T$，$\neg$ 不变，$S$ 的对偶式用 $S^*$ 表示。

**$\downarrow$（或非）, $|$（与非）:**

**$\downarrow$** 就是或取反，**$|$** 就是与取反。

$\\{\neg,\vee\\}$，$\\{\neg,\wedge\\}$，$\\{|\\}$，$\\{\downarrow\\}$分别都是功能齐全的运算符（functionally complete operators）。

**Satisfiability:**

A compound proposition is **satisfiable** if there is an assignment of truth values to its variables that make it true.  

一个命题能找到某种变量的赋值方法，使得这个命题为真。

**Normal Form（范式）:**

* **析取范式（disjunctive normal form）**  
  每一项内部为与，再把每一项或起来   
* **合取范式（conjunctive normal form）**  
  子句内部为或，再把所有子句与起来  

!!! Example  
    (1) $p$  
    (2) $\neg p\vee q$  
    (3) $\neg p\wedge q\wedge \neg r$  
    (4) $\neg p\vee(q\wedge\neg r)$  
    (5) $\neg p\wedge(q\vee\neg r)\wedge(\neg q\vee r)$  

    (1),(2),(3),(5) are in conjunctive normal forms  
    (1),(2),(3),(4) are in disjunctive normal forms  

***

## 1.4 Predicate and Quantifiers

**Predicate, Quantifier and Uniqueness Quantifier:**

* **predicate（谓词）**：$P(x)$

* **quantifier（量词）**：$\exists$，$\forall$

* **uniqueness quantifier（唯一性量词）**：$\exists !xP(x)$

**Application:**

!!! Example
    **Example1:**  
    “Every student in this class has taken a course in Java.”  
    $U$ is all people, $S(x)$ denotes “$x$ is a student in this class", $J(x)$ denotes “$x$ has taken a course in Java”  
    $\forall x(S(x)\rightarrow J(x))$

!!! Example
    **Example2:**  
    "Some student in this class has taken a course in Java.”  
    $U$ is all people, $S(x)$ denotes “$x$ is a student in this class", $J(x)$ denotes “$x$ has taken a course in Java”  
    $\exists x(S(x)\wedge J(x))$

**De Morgan's Laws for Quantifiers:**

* $\neg\forall xP(x)\equiv\exists x\neg P(x)$  
* $\neg\exists xP(x)\equiv\forall x\neg P(x)$  

***

## 1.5 Rule of Inference

**Modus Ponens（假言推理）:**

$$(p\wedge(p\rightarrow q))\rightarrow q$$

!!! Example  
    Let $p$ be “It is snowing.”  
    Let $q$ be “I will study discrete math.”  

    “If it is snowing, then I will study discrete math.”  
    “It is snowing.”  
    “Therefore , I will  study discrete math."  

**Modus Tollens（取拒式）:**

$$\neg q\wedge(p\rightarrow q)\rightarrow p$$

!!! Example  
    Let $p$ be “it is snowing.”  
    Let $q$ be “I will study discrete math.”  

    “If it is snowing, then I will study discrete math.”  
    “I will not study discrete math.”  
    “Therefore , it is not snowing.”  

**Hypothetical Syllogism（假言三段论）:**

$$((p\rightarrow q)\wedge(q\rightarrow r))\rightarrow(p\rightarrow r)$$

!!! Example  
    Let $p$ be “it snows.”  
    Let $q$ be “I will study discrete math.”  
    Let $r$ be “I will get an A.”  

    “If it snows, then I will study discrete math.”  
    “If I study discrete math, I will get an A.”  
    “Therefore , If it snows, I will get an A.”

**Disjunctive Syllogism（析取三段论）:**

$$(\neg p\wedge(p\vee q))\rightarrow q$$

!!! Example 
    Let $p$ be “I will study discrete math.”  
    Let $q$ be “I will study English literature.”  

    “I will study discrete math or I will study English literature.”  
    “I will not study discrete math.”  
    “Therefore , I will study English literature.”  

**Resolution（消解律）:**

$$(\neg p\vee r)\wedge(p\vee q)\rightarrow(q\vee r)$$

!!! Example 
    Let $p$ be “I will study discrete math.”  
    Let $r$ be “I will study English literature.”  
    Let $q$ be “I will study databases.”  

    “I will not study discrete math or I will study English literature.”  
    “I will study  discrete math or I will study databases.”  
    “Therefore, I will study databases or I will English literature."  

***

## 1.6 Introduction to Proofs

**Terminologies:**

* theorem 定理
* axiom 公理
* lemma 引理
* corollary 推论
* conjecture 猜想

**Proof:**

* **Trivial Proof（平凡证明）**  
如果已知 $q$ 为真，则 $p\rightarrow q$ 也为真
* **Vacuous Proof（空证明）**  
如果已知 $p$ 为假，则 $p\rightarrow q$ 为真
* **Direct Proof（直接证明）**  
假设 $p$ 为真，求证 $q$ 也为真
* **Proof by Contraposition（反证法）**  
假设 $\neq q$ 为真，求证 $\neg p$ 也为真
* **Proof by Contradiction（归谬证明法）**  
为了证明 $p$ 为真，假设 $\neg p$ 为真，推出矛盾
