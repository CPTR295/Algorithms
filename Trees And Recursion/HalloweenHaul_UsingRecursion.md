# 🌳 Halloween Haul Problem — Binary Tree Analysis

## 📌 Problem Statement

We are given a **binary tree** representing houses and streets.
Each **leaf node** represents a **house containing candies**, and **internal nodes** represent **street connections**.

Our task is to compute:

* Total **number of streets required**
* Total **candies collected** from all houses

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
12
14
```

Explanation:

* Streets calculated based on tree structure
* Candies = **3 + 5 + 2 + 4 = 14**

---

## 📥 Input

* **5 test cases**
* Each test case contains:

  * A **tree string representation**
* Maximum input length = **255 characters**

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

For each test case print:

```
<number_of_streets>
<total_candies>
```

Example Output:

```
12
10
16
18
20
100
...
```

---

## ⚙️ Approach

This solution uses:

* Binary Tree Construction
* Recursive Tree Traversal
* Tree Height Calculation
* Candy Summation

### Steps

1. Parse input string into binary tree
2. Calculate tree height
3. Calculate total streets
4. Calculate total candies
5. Print results

---

## 🧩 Data Structure

### Tree Node

```c
typedef struct node
{
    int candy;
    struct node *left, *right;
} node;
```

---

## 🔑 Key Functions

### `read_tree()`

* Converts string representation into binary tree

---

### `tree_height()`

* Computes **height of tree**
* Used for street calculation

---

### `tree_streets()`

* Calculates total streets in tree
* Each internal node contributes to street count

---

### `tree_candy()`

* Sums candies from all **leaf nodes**

---

### `tree_solve()`

* Combines all calculations
* Prints final result

---

## 🧠 Algorithm Type

* Binary Tree
* Recursion
* Tree Traversal
* Divide & Conquer

---

## ⏱️ Time Complexity

| Operation           | Complexity |
| ------------------- | ---------- |
| Tree parsing        | O(n)       |
| Height calculation  | O(n)       |
| Candy calculation   | O(n)       |
| Streets calculation | O(n)       |
| Overall             | **O(n)**   |

---

## 💾 Memory Usage

* Tree nodes allocated dynamically
* Recursive stack space
