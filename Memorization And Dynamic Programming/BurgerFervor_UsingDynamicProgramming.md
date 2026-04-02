# 🍔 Burger Fervor Problem — Dynamic Programming (Bottom-Up)

## 📌 Problem Statement

Homer Simpson has **t minutes** to spend eating **burgers** and drinking **beer**.

There are **two types of burgers**:

* First burger takes **m minutes**
* Second burger takes **n minutes**

Homer prefers **burgers over beer**, so he wants to:

* Spend **as much time as possible eating burgers**
* If exact time **t** is not possible, use remaining time for **beer**

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

* Best possible → 4 + 4 + 4 = 12 minutes
* Remaining time → 3 minutes (beer)

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

| Variable | Meaning                |
| -------- | ---------------------- |
| m        | Time for first burger  |
| n        | Time for second burger |
| t        | Total available time   |

### Constraints

| Parameter           | Limit     |
| ------------------- | --------- |
| m, n, t             | < 10,000  |
| Multiple test cases | Yes       |
| Time limit          | 3 seconds |

---

## 📤 Output

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

This solution uses:

* **Bottom-Up Dynamic Programming**
* Iterative approach
* Optimization

Instead of recursion, we build solutions from **0 → t** using a **DP array**.

---

## 🧩 DP Definition

```text
dp[i] = maximum burgers possible in i minutes
```

### Base Case

```text
dp[0] = 0
```

### Transition

For each time `i`:

```text
dp[i] = max(dp[i-m], dp[i-n]) + 1
```

If both values are invalid:

```text
dp[i] = -1
```

---

## 🔑 Key Function

### `solve()`

* Builds DP table
* Finds optimal burger count
* Handles leftover time

---

## 🧠 Algorithm Type

* Dynamic Programming
* Bottom-Up DP
* Optimization

---

## ⏱️ Time Complexity

| Operation       | Complexity |
| --------------- | ---------- |
| DP computation  | O(t)       |
| Search leftover | O(t)       |
| Overall         | **O(t)**   |

Efficient for **t < 10,000**

---

## 💾 Memory Usage

* DP array size = **10,000**
* Minimal memory usage

---

## 🔄 Comparison of Approaches

| Approach     | Performance |
| ------------ | ----------- |
| Recursion    | Slow        |
| Memoization  | Better      |
| Bottom-Up DP | **Fastest** |

This implementation uses the **Bottom-Up Dynamic Programming approach** for optimal performance.
