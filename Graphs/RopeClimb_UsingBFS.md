# Rope Climbing Problem - BFS

## 📌 Problem Overview

Bob is forced to climb an **infinitely long rope** in gym class. His goal is to reach **at least height `h` meters**.

However, Bob has limited movement abilities and must also avoid **itching powder** spread on certain rope segments.

The objective is to **determine the minimum number of moves** required for Bob to reach **height `h` or higher**.

---

## 🎯 Movement Rules

Bob starts at height:

```
0 meters
```

Bob can perform two types of moves:

### ⬆️ Jump

* Bob can jump **exactly `j` meters upward**
* He **cannot jump any other distance**
* Each jump counts as **1 move**

Example:

If `j = 5`

```
0 → 5 → 10 → 15
```

---

### ⬇️ Fall

* Bob can fall **any number of meters downward**
* Fall must land on a **valid height**
* Each fall counts as **1 move**

Example:

```
10 → 7 → 2 → 0
```

---

## ⚠️ Itching Powder Rules

Alice spreads **itching powder** on segments of rope.

If a segment is from **a to b**, then:

```
[a, b] (inclusive) contains itching powder
```

### Restrictions

Bob **cannot**:

* Jump onto itching powder
* Fall onto itching powder

Bob **can pass over itching powder** — only **landing** matters.

---

## 🏁 Goal

Determine:

* **Minimum number of moves** to reach **height ≥ h**

If impossible:

```
Output -1
```

---

## 📥 Input Format

```
h j n
```

Where:

| Variable | Description                |
| -------- | -------------------------- |
| h        | Target height              |
| j        | Jump distance              |
| n        | Number of itching segments |

Followed by **n lines**:

```
start end
```

Each line defines a segment with itching powder.

---

## 📤 Output Format

Print:

```
Minimum number of moves
```

Or

```
-1 (if impossible)
```

---

## 📊 Constraints

| Parameter | Limit       |
| --------- | ----------- |
| h         | ≤ 1,000,000 |
| j         | ≤ h         |
| n         | ≤ 1,000,000 |

---

## 🧠 Approach

### Algorithm Used

The solution uses:

* **Breadth First Search (BFS)**
* **Graph traversal on heights**

---

## 🔎 Key Idea

Each **height** is treated as a **node**.

From any height:

Possible moves:

* Jump → `height + j`
* Fall → `0 ... height-1`

BFS is used to find the **minimum number of moves**.

---

## ⚙️ Implementation Details

### Main Functions

### `add_position()`

* Adds valid height positions
* Checks:

  * Bounds
  * Itching powder
  * Already visited

---

### `find_distance()`

* BFS traversal
* Computes minimum moves
* Stores result in `min_moves[]`

---

### `solve()`

* Finds best result
* Prints minimum moves

---

## ⏱️ Time Complexity

Worst Case:

```
O(N)
```

Where:

* N = height range (up to 2,000,000)

Optimized BFS ensures solution within **4 seconds**.

---

## 🚀 Features

* Efficient BFS
* Handles large constraints
* Memory optimized
* Fast execution

---

## 📚 Concepts Used

* Breadth First Search (BFS)
* Graph Traversal
* State Space Search
* Shortest Path

---