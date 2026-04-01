# 🍬 Halloween Haul Problem — Binary Tree Traversal (Stack Based)

## 📌 Problem Statement

We are given a **binary tree** represented as a string.
Each **leaf node represents a house** containing candies, and our task is to **calculate the total candies** across all houses.

* **Leaf nodes** → Houses (contain candy values)
* **Internal nodes** → Connect houses (no candy)

The tree is represented using **parentheses notation**.

---

## 🧠 Example

Input:

```text
((3 5) (2 4))
```

Tree Representation:

```
        *
      /   \
     *     *
    / \   / \
   3   5 2   4
```

Output:

```text
14
```

Explanation:

```
3 + 5 + 2 + 4 = 14 candies
```

---

## 📥 Input

* **5 test cases** (defined by `TEST_CASES`)
* Each test case contains:

  * A **tree string**
  * Maximum string length = **255**

Example:

```text
((1 2) (3 4))
(5 (6 7))
((10 20) (30 40))
(1 2)
((2 3) 4)
```

---

## 📤 Output

For each test case:

* Print **total candies** in the tree

Example Output:

```text
10
18
100
3
9
```

---

## ⚙️ Approach

This solution uses:

* **Binary Tree**
* **Stack (Iterative Traversal)**
* **Tree Parsing from String**

### Steps

1. Read tree string
2. Convert string into binary tree
3. Traverse tree using stack
4. Sum candies from leaf nodes
5. Print total

---

## 🧩 Data Structures Used

### Tree Node

```c
typedef struct node
{
    int candy;
    struct node *left, *right;
} node;
```

### Stack

```c
typedef struct stack
{
    node *values[SIZE];
    int highest_used;
} stack;
```

---

## 🔑 Key Functions

### `read_tree()`

Converts string into binary tree

---

### `tree_candy()`

Traverses tree and calculates total candy

* Uses **stack-based traversal**
* Avoids recursion

---

### `push_stack()` / `pop_stack()`

Handles stack operations

---

## 🚀 Algorithm Type

* Binary Tree
* Stack Traversal
* String Parsing
* Iterative Tree Traversal

---

## ⏱️ Time Complexity

| Operation      | Complexity |
| -------------- | ---------- |
| Tree parsing   | O(n)       |
| Tree traversal | O(n)       |
| Overall        | **O(n)**   |

---

## 💾 Memory Usage

* Stack size: **255**
* Tree nodes dynamically allocated

