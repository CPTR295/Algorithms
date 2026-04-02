# 🏒 Hockey Rivalry — Bottom-Up Dynamic Programming

## 📌 Problem Statement

Two hockey teams:

* **Geese**
* **Hawks**

Each team played **n games**. For every game we know:

* Result → **Win (W)** or **Loss (L)**
* Number of **goals scored**

However:

* We **don't know** which games were against each other
* Some games may be against **other teams**

A **rivalry game** is when:

> **Geese played against Hawks**

Your task:

👉 Find the **maximum number of goals** scored in possible rivalry games.

---

## 🧠 Rivalry Game Rules

A rivalry game is valid when:

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

```
n
```

* Number of games (1 ≤ n ≤ 1000)

---

### Line 2

```
Geese outcomes
```

Example:

```
WLLW
```

---

### Line 3

```
Geese goals
```

Example:

```
4 1 2 3
```

---

### Line 4

```
Hawks outcomes
```

---

### Line 5

```
Hawks goals
```

---

## 📤 Output

```
Maximum goals in rivalry games
```

---

## ⚙️ Approach

This solution uses:

* **Bottom-Up Dynamic Programming**
* **2D DP Table**
* **LCS-style optimization**

We build a **DP table**:

```
dp[i][j]
```

Where:

* `i` → Geese games considered
* `j` → Hawks games considered
* `dp[i][j]` → Maximum rivalry goals

---

## 🧩 DP Definition

```
dp[i][j] = maximum goals using first i geese games and j hawks games
```

---

## 🔁 Transition

At each `(i, j)`:

### Option 1 — Match rivalry game

If valid:

```
dp[i-1][j-1] + goals1[i] + goals2[j]
```

---

### Option 2 — Skip both

```
dp[i-1][j-1]
```

---

### Option 3 — Skip Geese

```
dp[i-1][j]
```

---

### Option 4 — Skip Hawks

```
dp[i][j-1]
```

Take maximum:

```
dp[i][j] = max(all options)
```

---

## 🔑 Key Function

### `solve()`

```c
int solve(...)
```

* Builds DP table
* Computes optimal rivalry goals
* Returns final answer

---

## 🧠 Algorithm Type

* Dynamic Programming
* Bottom-Up DP
* LCS Variant
* Optimization

---

## ⏱️ Time Complexity

| Operation      | Complexity |
| -------------- | ---------- |
| DP table build | O(n²)      |
| Overall        | **O(n²)**  |

Efficient for:

```
n ≤ 1000
```

---

## 💾 Memory Usage

| Structure | Size        |
| --------- | ----------- |
| DP table  | 1000 × 1000 |
| Arrays    | 1000        |

Memory is acceptable.

---

## ⭐ Notes

* Most efficient solution
* No recursion overhead
* Uses bottom-up DP
* Works for large inputs

---

## 🔄 Approach Comparison

| Approach     | Performance |
| ------------ | ----------- |
| Recursive    | Slow        |
| Memoization  | Faster      |
| Bottom-Up DP | **Fastest** |

This implementation uses **Bottom-Up Dynamic Programming** for optimal performance.
