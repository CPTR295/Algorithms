# 🌳 Building a Treap Using Recursion

## 📘 Problem Overview

A **Treap** is a combination of:

* **Binary Search Tree (BST)** based on **label**
* **Heap** based on **priority**

Each node has:

```text
label / priority
```

Example:

```
A/54
B/42
C/58
```

### Treap Properties

1. **BST Property (by label)**
   Left subtree < Root < Right subtree

2. **Heap Property (by priority)**
   Parent has **higher priority** than children

---

## 🧠 Approach

### Step 1 — Sort by Label

First, sort nodes alphabetically (BST order)

```c
qsort(treap_nodes,num_nodes,sizeof(treap_node),compare);
```

---

### Step 2 — Build Treap Recursively

Algorithm:

1. Find **maximum priority** in range
2. Make it **root**
3. Recursively build:

   * Left subtree
   * Right subtree

This naturally satisfies:

* BST property (sorted input)
* Heap property (max priority root)

---

## 📥 Input Format

```
n
label/priority
label/priority
...
```

Example:

```
11
A/54
I/16
k/39
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

## 📤 Output Format

Treap printed using parentheses:

```
(left_subtree root right_subtree)
```

Example:

```
((A/54(B/42))C/58(((D/49(E/36(F/5)))G/55)H/56((I/16)J/40(k/39))))
```

---

## 📁 Data Structure

```c
typedef struct treap_node {
    char * label;
    int priority;
} treap_node;
```

---

## 🔧 Functions

### `read_label()`

Reads label dynamically:

```c
char * read_label(int size)
```

Example:

```
A/54 → label = A
```

---

### `compare()`

Used for sorting:

```c
int compare(const void *a,const void *b)
```

Sorts alphabetically.

---

### `max_priority_index()`

Finds highest priority node:

```c
int max_priority_index(treap_node treap_nodes[], int left, int right)
```

---

### `solve()`

Recursive treap construction:

```c
void solve(treap_node treap_nodes[], int left, int right)
```

Algorithm:

```
1. Find max priority
2. Print "("
3. Build left subtree
4. Print root
5. Build right subtree
6. Print ")"
```

---

## 🧪 Example Walkthrough

Sorted nodes:

```
A B C D E F G H I J K
```

Highest priority:

```
C/58 → Root
```

Left subtree:

```
A B
```

Right subtree:

```
D E F G H I J K
```

Recursion continues…

---

## ⏱️ Time Complexity

| Step           | Complexity  |
| -------------- | ----------- |
| Sorting        | O(n log n)  |
| Building Treap | O(n²) worst |
| Overall        | O(n²)       |

For:

```
n ≤ 50,000
```

Works fine.

---

## 💡 Treap Visualization

Example:

```
        C/58
       /    \
    A/54    H/56
      \      /  \
      B/42  G/55 J/40
            /
         D/49
           \
           E/36
              \
              F/5
```

---

## 🏁 Output

```
((A/54(B/42))C/58(((D/49(E/36(F/5)))G/55)H/56((I/16)J/40(k/39))))
```

---

## 🧠 Concepts Used

* Treap
* Recursion
* Sorting
* Divide & Conquer

---

## 📚 Category

```
Tree + Recursion + Divide and Conquer
```

---

## ⭐ Difficulty

```
Medium–Hard (Competitive Programming)
```
