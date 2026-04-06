# Maximum Pair Sum Segment Tree (With Updates) — README

## 📌 Overview

This program implements a **Segment Tree** to efficiently support:

* **Range Query** → Find **maximum pair sum** in a given range
* **Update Query** → Update an element in the array

The **maximum pair sum** is defined as:

> **Sum of the two largest elements in a given range**

---

## 🚀 Features

* Efficient **Segment Tree** implementation
* Supports **dynamic updates**
* Fast **range queries**
* Handles up to **1,000,000 elements**
* Time-efficient operations

---

## 📂 Data Structures Used

### `segtree_node`

```c
typedef struct segtree_node{
    int left,right;
    int max_sum,max_element;
}segtree_node;
```

| Field       | Description               |
| ----------- | ------------------------- |
| left        | Left index of segment     |
| right       | Right index of segment    |
| max_sum     | Maximum pair sum in range |
| max_element | Maximum element in range  |

---

### `node_info`

```c
typedef struct node_info{
    int max_sum,max_element;
}node_info;
```

Used for returning values during recursion.

---

## ⚙️ Operations Supported

### 1. Build Segment Tree

```c
fill_segtree()
```

Builds segment tree and calculates:

* Maximum element
* Maximum pair sum

Time Complexity: **O(N)**

---

### 2. Query Segment Tree

```c
query_segtree()
```

Returns maximum pair sum in range `[L, R]`

Time Complexity: **O(log N)**

---

### 3. Update Segment Tree

```c
update_segtree()
```

Updates element at index and rebuilds affected nodes

Time Complexity: **O(log N)**

---

## 📥 Input Format

```
N
A1 A2 A3 ... AN
Q
Operation X Y
Operation X Y
...
```

Where:

| Symbol | Meaning                     |
| ------ | --------------------------- |
| N      | Number of elements          |
| Ai     | Array elements              |
| Q      | Number of operations        |
| U X Y  | Update index X to value Y   |
| Q X Y  | Query max pair sum in range |

---

## 📤 Output Format

For each **Query (Q)** operation:

```
Maximum Pair Sum
```

---

## 🧪 Example

### Input

```
5
1 2 3 4 5
3
Q 1 5
U 2 10
Q 1 5
```

### Output

```
9
15
```

### Explanation

```
Initial array: 1 2 3 4 5
Max pair sum (1-5): 5 + 4 = 9

After update:
1 10 3 4 5
Max pair sum (1-5): 10 + 5 = 15
```

---

## 🧠 Algorithm Logic

Each node stores:

```
max_element = max(left.max_element , right.max_element)

max_sum = max(
    left.max_sum,
    right.max_sum,
    left.max_element + right.max_element
)
```

---

## ⏱️ Complexity Analysis

| Operation | Complexity |
| --------- | ---------- |
| Build     | O(N)       |
| Query     | O(log N)   |
| Update    | O(log N)   |
| Memory    | O(4N)      |

---

## 🎯 Use Cases

* Competitive Programming
* Range Queries Problems
* Dynamic Array Updates
* Data Analytics
* Real-time Systems

---

## 🏁 Summary

This implementation provides:

✅ Fast queries
✅ Fast updates
✅ Large input support
✅ Clean recursive implementation

---
