# 🍔 Burger Frevor Problem — Memoization

## 📌 Problem Statement

Homer Simpson has **t minutes** to spend eating **burgers** and drinking **beer**.

There are **two types of burgers**:

* First burger takes **m minutes**
* Second burger takes **n minutes**

Homer prefers **burgers over beer**, so he wants to:

* Spend **as much time as possible eating burgers**
* If exact time **t** is not possible, use leftover time for **beer**

Your task is to determine:

* Maximum number of burgers Homer can eat
* Remaining time (if any)

---

## 🧠 Example

### Example 1

Input:

```text
4 9 15
```

Output:

```text
3 3
```

Explanation:

* Best possible: 3 burgers (4 + 4 + 4 = 12 minutes)
* Remaining time = 3 minutes (beer)

---

### Example 2

Input:

```text
3 5 15
```

Output:

```text
5
```

Explanation:

* 3 + 3 + 3 + 3 + 3 = 15 minutes
* No beer needed

---

## 📥 Input

* Multiple test cases
* Each line contains:

```text
m n t
```

Where:

* `m` → Time for first burger
* `n` → Time for second burger
* `t` → Total available time

### Constraints

| Parameter           | Limit     |
| ------------------- | --------- |
| m, n, t             | < 10,000  |
| Multiple test cases | Yes       |
| Time limit          | 3 seconds |

---

## 📤 Output

For each test case:

### Case 1 — Exact Match

```text
<number_of_burgers>
```

### Case 2 — Not Exact Match

```text
<number_of_burgers> <remaining_time>
```

---

## ⚙️ Approach

This optimized solution uses:

* Recursion
* **Dynamic Programming (Memoization)**
* Optimization

### Why Memoization?

The recursive solution recalculates the same values many times.
Using **memoization**, we store previously computed results and reuse them.

This improves performance significantly.

---

## 🔑 Key Functions

### `solve_t()`

Recursive function with memoization:

```c
int solve_t(int m,int n,int t,int memo[])
```

* Stores results in `memo[]`
* Avoids recomputation
* Improves efficiency

---

### Memo Array Values

| Value | Meaning          |
| ----- | ---------------- |
| -2    | Not computed yet |
| -1    | Not possible     |
| >=0   | Maximum burgers  |

---

### `solve()`

* Initializes memo array
* Handles output formatting
* Finds best solution

---

### `max()`

Returns maximum of two values

---

## 🧠 Algorithm Type

* Dynamic Programming
* Memoization
* Recursion
* Optimization

---

## ⏱️ Time Complexity

| Approach                 | Complexity  |
| ------------------------ | ----------- |
| Recursive (without memo) | Exponential |
| With Memoization         | **O(t)**    |

This makes the solution efficient for **t < 10,000**

---

## 💾 Memory Usage

* Memo array size = **10,000**
* Minimal additional memory
