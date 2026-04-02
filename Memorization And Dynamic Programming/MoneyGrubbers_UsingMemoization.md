# 🍎 Money Grubbers Problem — Dynamic Programming (Memoization)

## 📌 Problem Statement

You want to **buy apples as cheaply as possible**.

The store offers:

* Price for **one apple**
* **m pricing schemes** (bulk offers)

Each pricing scheme gives:

* `n` apples for price `p`

Your goal:

* Buy **at least k apples**
* Spend **minimum money**

---

## 🧠 Example

### Input

```text
1.75 2
3 4.00
2 2.50
1 4
```

### Explanation

* Single apple → $1.75
* 3 apples → $4.00
* 2 apples → $2.50

Find cheapest price for:

* At least **1 apple**
* At least **4 apples**

---

## 📥 Input Format

Each test case contains:

1. First line:

```text
unit_price m
```

* `unit_price` → price for one apple
* `m` → number of pricing schemes (max 20)

2. Next `m` lines:

```text
n p
```

* `n` → number of apples
* `p` → price

3. Last line:

```text
k1 k2 k3 ...
```

* Each `k` → desired apples (0–100)

### Constraints

| Parameter | Limit                     |
| --------- | ------------------------- |
| m         | ≤ 20                      |
| n         | 1–100                     |
| k         | 0–100                     |
| Price     | 2 decimal floating number |

---

## 📤 Output Format

For each test case:

```text
Case c:
Buy k for $d
```

Where:

* `c` → test case number
* `k` → apples requested
* `d` → minimum cost

---

## 🧠 Approach

This solution uses:

* **Dynamic Programming**
* **Memoization**
* **Recursion**

We compute **minimum price** for buying **at least k apples**.

---

## 🧩 DP Definition

```text
memo[i] = minimum cost to buy i apples
```

### Base Case

```text
memo[0] = 0
```

### Recurrence

For each apple count:

* Buy single apple
* Try all pricing schemes
* Take minimum cost

---

## 🔑 Key Functions

### `solve_k()`

Recursive memoized function:

```c
double solve_k(...)
```

* Finds minimum cost for `k` apples
* Uses memoization
* Avoids recomputation

---

### `solve()`

* Finds minimum cost for **at least k apples**
* Checks values beyond `k`

---

### `get_number()`

* Reads multiple values from input line
* Parses integers efficiently

---

## 🧠 Algorithm Type

* Dynamic Programming
* Memoization
* Recursion
* Optimization

---

## ⏱️ Time Complexity

| Operation      | Complexity                    |
| -------------- | ----------------------------- |
| DP computation | O(k × schemes)                |
| Overall        | **Efficient for constraints** |

---

## 💾 Memory Usage

| Structure  | Size   |
| ---------- | ------ |
| Memo array | 10,000 |
| Schemes    | 20     |

Memory usage is minimal.

---

## ⭐ Notes

* Handles floating-point prices
* Supports multiple test cases
* Efficient memoized recursion
* Finds **minimum cost for at least k apples**
* Optimized dynamic programming solution

---

## 🔄 Problem Type

| Category   | Type                       |
| ---------- | -------------------------- |
| Algorithm  | Dynamic Programming        |
| Technique  | Memoization                |
| Difficulty | Medium                     |
| Pattern    | Unbounded Knapsack Variant |

---
