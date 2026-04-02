# 🏒 Hockey Rivalry — Maximum Goals Problem (Recursive)

## 📌 Problem Statement

Two hockey teams:

* **Geese**
* **Hawks**

Each team played **n games**.

For every game, we know:

* Whether they **won (W)** or **lost (L)**
* Number of **goals scored**

However:

* We **don't know** which games were played against each other
* Some games may be against **other teams**

A **rivalry game** is when:

> **Geese played against Hawks**

Your task:

👉 Determine the **maximum number of goals** scored in possible rivalry games.

---

## 🧠 Key Idea

A rivalry game is valid only if:

* One team **wins**
* The other team **loses**
* Winner scored **more goals**

Then:

```text
Total goals = Geese goals + Hawks goals
```

We must **maximize total goals**.

---

## 📥 Input Format

Input consists of **5 lines**:

### Line 1

```text
n
```

* Number of games (1 ≤ n ≤ 1000)

---

### Line 2

```text
Geese Outcomes
```

Example:

```text
WLLW
```

---

### Line 3

```text
Geese Goals
```

Example:

```text
4 1 2 3
```

---

### Line 4

```text
Hawks Outcomes
```

Example:

```text
LWLW
```

---

### Line 5

```text
Hawks Goals
```

Example:

```text
3 2 1 4
```

---

## 📤 Output

Single integer:

```text
Maximum goals in rivalry games
```

---

## ⚙️ Approach

This solution uses:

* Recursion
* Dynamic Programming pattern
* Similar to **Longest Common Subsequence (LCS)**

At each step:

We check:

* Match both games
* Skip Geese game
* Skip Hawks game
* Take best possible

---

## 🧩 Recursive Definition

```text
solve(i, j)
```

Where:

* `i` → Geese game index
* `j` → Hawks game index

---

### Base Case

```text
if i == 0 or j == 0
    return 0
```

---

### Match Condition

Valid rivalry game when:

```text
Geese Win & Hawks Lose & goals1 > goals2
OR
Geese Lose & Hawks Win & goals1 < goals2
```

Then:

```text
goals = goals1 + goals2 + solve(i-1, j-1)
```

---

### Other Choices

Try:

* Skip both
* Skip Geese
* Skip Hawks

Take maximum.

---

## 🔑 Key Function

### `solve()`

```c
int solve(...)
```

* Recursive function
* Calculates maximum rivalry goals
* Uses comparison logic

---

## 🧠 Algorithm Type

* Recursion
* Dynamic Programming Pattern
* LCS Variant
* Optimization

---

## ⏱️ Time Complexity

| Approach                    | Complexity  |
| --------------------------- | ----------- |
| Recursive                   | Exponential |
| With DP (Optimized version) | O(n²)       |

This version uses **pure recursion**.

---

## 💾 Memory Usage

| Structure       | Size     |
| --------------- | -------- |
| Arrays          | 1000     |
| Recursion stack | Variable |

---

## ⭐ Notes

* LCS-style recursion
* No memoization
* Works for smaller inputs
* Can be optimized using DP table

---

## 🔄 Problem Category

| Category   | Type                |
| ---------- | ------------------- |
| Algorithm  | Dynamic Programming |
| Pattern    | LCS Variant         |
| Difficulty | Medium-Hard         |
| Technique  | Recursion           |

---
