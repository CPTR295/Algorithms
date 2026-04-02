# 🏒 Hockey Rivalry — Maximum Goals (Memoization)

## 📌 Problem Statement

Two hockey teams:

* **Geese**
* **Hawks**

Each team played **n games**, and for each game we know:

* Whether the team **won (W)** or **lost (L)**
* Number of **goals scored**

However:

* We **don't know** which games were against each other
* Some games were against **other teams**

A **rivalry game** is when:

> **Geese played against Hawks**

Your task:

👉 Find the **maximum number of goals** that could have been scored in **rivalry games**.

---

## 🧠 Rivalry Game Conditions

A rivalry game is valid if:

### Case 1

* Geese **Win**
* Hawks **Lose**
* Geese goals **>** Hawks goals

### Case 2

* Geese **Lose**
* Hawks **Win**
* Geese goals **<** Hawks goals

If valid:

```text
Total goals = Geese goals + Hawks goals
```

We must **maximize total goals**.

---

## 📥 Input Format

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

```text
Maximum goals scored in rivalry games
```

---

## ⚙️ Approach

This solution uses:

* **Dynamic Programming**
* **Memoization**
* **Recursion**
* **LCS-style comparison**

We compare games between:

* Geese index `i`
* Hawks index `j`

And compute best possible score.

---

## 🧩 DP Definition

```text
memo[i][j] = maximum goals using first i geese games and j hawks games
```

---

## 🔁 Recursive Choices

At each `(i, j)`:

### Option 1 — Match rivalry game

If valid:

```text
solve(i-1, j-1) + goals1[i] + goals2[j]
```

---

### Option 2 — Skip both

```text
solve(i-1, j-1)
```

---

### Option 3 — Skip Geese

```text
solve(i-1, j)
```

---

### Option 4 — Skip Hawks

```text
solve(i, j-1)
```

Take **maximum** of all.

---

## 🔑 Key Function

### `solve()`

```c
int solve(...)
```

* Uses memoization table
* Avoids recomputation
* Improves performance

---

## 🧠 Algorithm Type

* Dynamic Programming
* Memoization
* LCS Variant
* Optimization

---

## ⏱️ Time Complexity

| Approach       | Complexity  |
| -------------- | ----------- |
| Recursive only | Exponential |
| Memoization    | **O(n²)**   |

Efficient for **n ≤ 1000**

---

## 💾 Memory Usage

| Structure  | Size        |
| ---------- | ----------- |
| memo table | 1000 × 1000 |
| arrays     | 1000        |

Memory usage is acceptable.

---

## ⭐ Notes

* Optimized recursion using memoization
* Similar to LCS dynamic programming
* Efficient for large inputs
* Handles up to **1000 games**

---

## 🔄 Approach Comparison

| Approach     | Performance |
| ------------ | ----------- |
| Recursive    | Slow        |
| Memoization  | Faster      |
| Bottom-Up DP | Fastest     |

This implementation uses **Memoization Programming**.
