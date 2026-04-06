# 🌳 Building a Treap Using Segment Tree (Optimized Version)

## 📘 Problem Overview

We are given **n nodes** where each node contains:

```
label / priority
```

We must construct a **Treap** and print it in **parenthesized format**.

A **Treap** combines:

* **Binary Search Tree** (by label)
* **Max Heap** (by priority)

---

## 🧠 Why This Version?

Previous solution:

* Used recursion
* Found max priority by scanning
* Time complexity **O(n²)** worst case

This version:

✅ Uses **Segment Tree**
✅ Finds maximum priority in **O(log n)**
✅ Total complexity **O(n log n)**

Much faster for **50,000 nodes**

---

# 🧩 Key Idea

### Step 1 — Sort nodes by label

This ensures **BST property**

```
Left < Root < Right
```

---

### Step 2 — Build Segment Tree

Segment tree stores:

```
Index of maximum priority
```

for any range.

---

### Step 3 — Recursively Build Treap

1. Query max priority index
2. Make it root
3. Build left subtree
4. Build right subtree

---

# 📥 Input Format

```
n
label/priority
label/priority
...
```

Example

```
11
A/54
I/16
K/39
E/36
B/42
G/55
D/49
H/56
C/58
J/40
F/5
```

---

# 📤 Output Format

```
(left_subtree root right_subtree)
```

Example:

```
((A/54(B/42))C/58(((D/49(E/36(F/5)))G/55)H/56((I/16)J/40(K/39))))
```

---

# 📁 Data Structures

## Treap Node

```c
typedef struct treap_node {
    char * label;
    int priority;
}treap_node;
```

Stores:

* Label
* Priority

---

## Segment Tree Node

```c
typedef struct segtree_node {
    int left, right;
    int max_index;
} segtree_node;
```

Stores:

* Range
* Max priority index

---

# 🔧 Functions

## `init_seqtree()`

Builds segment tree structure

```c
void init_seqtree(...)
```

Splits range recursively.

---

## `fill_segtree()`

Fills segment tree with max priority indexes

```c
int fill_segtree(...)
```

Returns:

```
Index of max priority
```

---

## `query_segtree()`

Finds max priority in range

```c
int query_segtree(...)
```

Used to find root node.

---

## `solve()`

Builds treap recursively

```c
void solve(...)
```

Steps:

```
1. Find max priority node
2. Print "("
3. Build left subtree
4. Print root
5. Build right subtree
6. Print ")"
```

---

## `read_label()`

Reads label dynamically

```c
char * read_label(int size)
```

Handles variable length labels.

---

## `compare()`

Sort nodes alphabetically

```c
int compare(...)
```

Used by:

```
qsort()
```

---

# ⚙️ Algorithm Flow

```
Read input
Sort by label
Build segment tree
Fill segment tree
Recursively build treap
Print result
```

---

# ⏱️ Time Complexity

| Operation          | Complexity |
| ------------------ | ---------- |
| Sorting            | O(n log n) |
| Build segment tree | O(n)       |
| Queries            | O(log n)   |
| Recursion          | O(n log n) |

### Final Complexity

```
O(n log n)
```

Efficient for:

```
n ≤ 50,000
```

---

# 🧪 Example Walkthrough

Sorted nodes:

```
A B C D E F G H I J K
```

Max priority:

```
C/58
```

Root:

```
C/58
```

Then recursively build:

```
Left subtree → A B
Right subtree → remaining nodes
```

---

# 🧠 Concepts Used

* Treap
* Segment Tree
* Divide & Conquer
* Recursion
* Sorting

---

# 📚 Category

```
Segment Tree + Treap + Recursion
```

---

# ⭐ Difficulty

```
Hard (Competitive Programming)
```

---

# 🔥 Why This Version is Better

| Version         | Complexity |
| --------------- | ---------- |
| Naive recursion | O(n²)      |
| Segment tree    | O(n log n) |
