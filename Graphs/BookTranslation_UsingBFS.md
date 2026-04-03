# Language Translation Cost Problem - BFS

## 📌 Problem Overview

This problem involves **translating languages** with the **minimum total cost**.

You are given:

* A set of **target languages**
* A set of **translators** between languages
* Each translator has a **translation cost**

The goal is to determine the **minimum total cost** required to translate **English** into **all target languages**.

If any language cannot be reached, output:

```
Impossible
```

---

## 🎯 Problem Objective

Starting from **English**, determine:

* Minimum translation steps to each language
* Minimum cost among shortest paths
* Sum of minimum costs for all languages

---

## 📥 Input Format

```
T R
```

Where:

| Variable | Description                |
| -------- | -------------------------- |
| T        | Number of target languages |
| R        | Number of translators      |

Next Line:

```
Language Names
```

Example:

```
French German Spanish
```

Then **R lines**:

```
from_language to_language cost
```

Example:

```
English French 10
French German 5
German Spanish 8
```

---

## 📤 Output Format

```
Minimum Total Cost
```

OR

```
Impossible
```

---

## 📊 Constraints

| Parameter   | Limit |
| ----------- | ----- |
| Languages   | ≤ 100 |
| Word Length | ≤ 15  |

---

## 🧠 Approach

### Algorithm Used

The solution uses:

* **Breadth First Search (BFS)**
* **Graph traversal**
* **Adjacency list** representation

---

## 🔎 Key Idea

1. Treat each **language as a node**
2. Treat each **translator as an edge**
3. Use **BFS** from English
4. Track:

   * Minimum number of translations
   * Minimum cost among shortest paths

---

## 🧩 Graph Representation

```
English → French (10)
French → German (5)
German → Spanish (8)
```

Graph is **undirected**:

* English ↔ French
* French ↔ German
* German ↔ Spanish

---

## ⚙️ Implementation Details

### Data Structures

```c
typedef struct edge
{
    int to_lang;
    int cost;
    struct edge *next;
} edge;
```

* Adjacency list used for graph
* Linked list for edges

---

### Key Functions

### `read_word()`

* Reads dynamic strings
* Handles variable length input

---

### `find_lang()`

* Finds index of language
* Maps string → integer

---

### `find_distance()`

* BFS traversal
* Calculates:

  * Minimum moves
  * Minimum cost

---

### `solve()`

* Calculates total cost
* Prints result

---

## ⏱️ Time Complexity

```
O(V + E)
```

Where:

* **V** = Number of languages
* **E** = Number of translators

---

## 🚀 Features

* Efficient BFS
* Graph traversal
* Dynamic string handling
* Memory optimized

---

## 📚 Concepts Used

* Breadth First Search (BFS)
* Graph Theory
* Adjacency List
* Shortest Path

---
