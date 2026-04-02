# 🍎 Money Grubbers Problem — Recursive Solution (Without Memoization)

## 📌 Problem Statement

You want to **buy apples at the lowest possible price**.

The store offers:

* Price for **one apple**
* **m pricing schemes** (bulk offers)

Each pricing scheme provides:

* `n` apples for price `p`

Your goal:

* Buy **at least k apples**
* Spend **minimum amount of money**

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

### First Line

```text
unit_price m
```

* `unit_price` → price for one apple
* `m` → number of pricing schemes (≤ 20)

---

### Next m Lines

```text
n p
```

* `n` → number of apples
* `p` → total price

---

### Last Line

```text
k1 k2 k3 ...
```

* Each integer `k` → number of apples to buy
* Values between **0 and 100**

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

## ⚙️ Approach

This solution uses:

* **Recursion**
* **Brute-force exploration**
* No memoization

The algorithm tries:

1. Buying one apple
2. Buying using each pricing scheme
3. Choosing minimum cost

---

## 🧩 Recursive Definition

```text
solve_k(k) = minimum cost to buy k apples
```

### Base Case

```text
solve_k(0) = 0
```

### Recursive Step

Try:

* Buy one apple
* Try all schemes
* Take minimum cost

---

## 🔑 Key Functions

### `solve_k()`

Recursive function:

```c
double solve_k(...)
```

* Computes minimum cost
* No memoization
* May recompute values

---

### `solve()`

* Finds minimum cost for **at least k apples**
* Checks values beyond `k`

---

### `get_number()`

* Reads multiple values from input
* Parses integers

---

## 🧠 Algorithm Type

* Recursion
* Brute Force
* Optimization

---

## ⏱️ Time Complexity

| Approach   | Complexity  |
| ---------- | ----------- |
| Recursive  | Exponential |
| Worst case | Very Slow   |

This approach is **slower** than memoization or DP.

---

## 💾 Memory Usage

| Structure       | Size     |
| --------------- | -------- |
| Recursion stack | Variable |
| Arrays          | Minimal  |

---

## ⭐ Notes

* Simple recursive implementation
* No memoization
* Slower for large inputs
* Good for understanding recursion

---

## 🔄 Approach Comparison

| Approach     | Performance |
| ------------ | ----------- |
| Recursive    | Slow        |
| Memoization  | Better      |
| Bottom-Up DP | Fastest     |

This implementation uses **pure recursion** for clarity and learning.
