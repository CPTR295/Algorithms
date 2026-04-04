# Maze Mice Exit Problem - Dijksta's Alg

## 📌 Problem Overview

A maze consists of **cells** connected by **passages**. Each passage takes a certain **amount of time** to travel.

In **each cell**, there is a **lab mouse** trained to reach the **exit cell** as quickly as possible.

The objective is to determine **how many mice can reach the exit within a given time limit**.

---

## 🎯 Problem Goal

Given:

* Number of cells
* Exit cell
* Time limit
* Passages with travel times

Determine:

```
How many mice reach the exit cell within time limit
```

---

## 🧠 Key Observations

* Each **cell contains one mouse**
* Each mouse starts from **its own cell**
* Passages are **directed**
* Passage **A → B** is different from **B → A**

---

## 📥 Input Format

```
T

n
e
t
m

(a b time)
(a b time)
...
```

Where:

| Variable | Description            |
| -------- | ---------------------- |
| T        | Number of test cases   |
| n        | Number of cells (≤100) |
| e        | Exit cell              |
| t        | Time limit             |
| m        | Number of passages     |

Next **m lines**:

```
a b time
```

Where:

* `a` = starting cell
* `b` = destination cell
* `time` = time to travel

---

## 📤 Output Format

For each test case:

```
Number of mice reaching exit
```

Separate test cases with a **blank line**.

---

## 📊 Constraints

| Parameter      | Limit |
| -------------- | ----- |
| Cells          | ≤ 100 |
| Time           | ≥ 0   |
| Directed graph | Yes   |

---

## 🧠 Approach

### Algorithm Used

The solution uses:

* **Dijkstra's Algorithm**
* **Adjacency List**
* **Shortest Path Calculation**

---

## 🔎 Key Idea

1. Treat each **cell as a node**
2. Treat each **passage as directed edge**
3. For each mouse (cell):

   * Find shortest path to exit
4. Count mice that reach within time limit

---

## ⚙️ Implementation Details

### Data Structure

```c
typedef struct edge
{
    int to_cell;
    int length;
    struct edge *next;
} edge;
```

Adjacency list used to store graph.

---

### Key Functions

### `find_time()`

* Implements **Dijkstra's algorithm**
* Finds shortest path from source to exit

---

### Main Logic

For each cell:

```
Run Dijkstra
Check if time ≤ limit
Count mouse
```

---

## ⏱️ Time Complexity

```
O(V × (V + E))
```

Where:

* V = Cells
* E = Passages

Since max **100 cells**, this is efficient.

---

## 🚀 Features

* Directed graph support
* Dijkstra shortest path
* Multiple test cases
* Efficient computation

---

## 📚 Concepts Used

* Graph Theory
* Dijkstra Algorithm
* Adjacency List
* Shortest Path

---
