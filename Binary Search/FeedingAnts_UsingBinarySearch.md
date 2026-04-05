# 🌳 Feeding Ants Problem – Binary Search

## 📘 Problem Overview

Bobi has built a **terrarium shaped like a tree**. Each edge in the tree is a **pipe** through which liquid flows downward.

* Each pipe has a **percentage value** indicating how much liquid flows through it
* Some pipes are **superpipes** that **square** the liquid passing through them (when turned ON)
* Each **leaf node contains an ant** that requires a **minimum amount of liquid**
* Bobi pours liquid into the **root node (node 1)**

🎯 **Goal:**
Find the **minimum amount of liquid** Bobi must pour into the root so **all ants receive their required liquid**

---

## 🔧 How Liquid Flows

If a node receives **L liters**:

* Each outgoing pipe receives:

```
L × (percentage / 100)
```

* If the pipe is a **superpipe**, then:

```
liquid = (liquid)^2
```

---

## 🧠 Solution Approach

This solution uses:

### 1️⃣ Binary Search

We binary search the **minimum root liquid** between:

```
0 → 2,000,000,000
```

Because:

* More root liquid → more liquid reaches leaves
* This is **monotonic**, so binary search works

---

### 2️⃣ DFS / Recursion

For a given root liquid:

* Recursively distribute liquid down the tree
* Check if each leaf gets required amount

---

## 📥 Input Format

```
n
node1 node2 percentage superpipe
node1 node2 percentage superpipe
...
(liquid requirements for each node)
```

### Example

```
6
1 2 20 0
1 3 50 0
1 4 30 1
4 5 50 0
4 6 50 0
-1 2 9 -1 7 8
```

---

## 📤 Output Format

Print:

```
minimum liquid required (4 decimal places)
```

Example:

```
20.0000
```

---

## ⚙️ Constraints

| Parameter       | Value           |
| --------------- | --------------- |
| Nodes           | 1 — 1000        |
| Liquid Required | 1 — 10          |
| Max Answer      | ≤ 2,000,000,000 |
| Time Limit      | 2.5 seconds     |

---

## 📁 Code Structure

### `edge` Structure

```c
typedef struct edge {
    int to_node;
    int percentage;
    int superpipe;
    struct edge *next;
} edge;
```

Stores:

* destination node
* percentage
* superpipe flag
* linked list pointer

---

## 🔍 Core Functions

### `can_feed()`

Checks if all ants can be fed using recursion

```c
int can_feed(int node, double liquid, edge *adj_list[], int liquid_needed[])
```

Steps:

1. If leaf node → check liquid requirement
2. Otherwise:

   * distribute liquid
   * apply superpipe logic
   * recursively check children

---

### `solve()`

Binary search to find minimum liquid

```c
void solve(edge *adj_list[], int liquid_needed[])
```

Binary search range:

```
0 → 2,000,000,000
```

Precision:

```
0.0001
```

---

### `main()`

Handles:

* input reading
* adjacency list building
* liquid requirements
* calling solve()

---

## 🧪 Example Walkthrough

Input:

```
20 liters at root
```

Flow:

```
Node 1
 ├── Node 2 → 20% → 4 liters
 ├── Node 3 → 50% → 10 liters
 └── Node 4 → 30% → 6 liters (superpipe)
                    ↓
                 6² = 36 liters
```

---

## ⏱️ Time Complexity

| Operation     | Complexity     |
| ------------- | -------------- |
| Binary Search | O(log 2e9)     |
| DFS           | O(N)           |
| Total         | O(N log range) |

Efficient for **N ≤ 1000**

---

## 💡 Key Concepts Used

* Binary Search on Answer
* DFS / Tree Traversal
* Floating Point Precision
* Adjacency List

---

## 🚀 Why This Problem is Interesting

This problem combines:

* Tree Traversal 🌳
* Binary Search 🔎
* Simulation ⚙️
* Floating Point Precision 🎯

A great **algorithmic thinking** exercise.

---
