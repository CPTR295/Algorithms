# 🌲 Descendant Distance Problem — Hierarchical Tree Analysis

## 📌 Problem Statement

We are given a **tree structure** where each node represents a **person/entity** and their **children**.
The goal is to compute a **score** for each node based on the number of descendants at a given **depth (d)**.

After computing scores:

* Sort nodes by **score (descending)**
* Break ties using **alphabetical order**
* Output **top 3 scoring nodes** (including ties)

---

## 🧠 Example

### Input

```text
1
5 2
A 2 B C
B 1 D
C 1 E
D 0
E 0
```

### Tree Representation

```
        A
      /   \
     B     C
    /       \
   D         E
```

### Output

```text
Tree 1:
A 2
B 0
C 0
```

Explanation:

* Depth = 2
* A has **2 descendants** at depth 2 → D and E

---

## 📥 Input Format

* First line → Number of test cases
* For each test case:

  * `n` → number of lines (nodes)
  * `d` → depth to calculate score
  * Next `n` lines:

    * Parent name
    * Number of children
    * Child names

### Example

```text
2
5 2
A 2 B C
B 1 D
C 1 E
D 0
E 0
3 1
X 2 Y Z
Y 0
Z 0
```

---

## 📤 Output Format

For each test case:

```text
Tree <case_number>:
<name> <score>
```

Example:

```text
Tree 1:
A 2

Tree 2:
X 2
```

---

## ⚙️ Approach

This solution uses:

* Tree Construction
* Recursive Traversal
* Score Calculation
* Sorting (qsort)

### Steps

1. Read tree input
2. Build node relationships
3. Calculate score at depth `d`
4. Sort nodes
5. Print top results

---

## 🧩 Data Structure

### Node Structure

```c
typedef struct node
{
    char *name;
    int num_children;
    struct node **children;
    int score;
} node;
```

---

## 🔑 Key Functions

### `read_tree()`

* Builds tree from input
* Creates parent-child relationships

---

### `score_one()`

* Calculates score for a single node
* Uses recursion

---

### `score_all()`

* Calculates scores for all nodes

---

### `compare()`

* Sorts nodes by:

  * Score (descending)
  * Name (ascending)

---

### `output_info()`

* Prints top 3 ranked nodes
* Includes tied scores

---

## 🧠 Algorithm Type

* Tree Traversal
* Recursion
* Sorting
* Hierarchical Analysis

---

## ⏱️ Time Complexity

| Operation         | Complexity     |
| ----------------- | -------------- |
| Tree construction | O(n)           |
| Score calculation | O(n)           |
| Sorting           | O(n log n)     |
| Overall           | **O(n log n)** |

---

## 💾 Memory Usage

* Max nodes: **1000**
* Dynamic memory allocation
