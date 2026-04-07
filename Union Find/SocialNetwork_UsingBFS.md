# Social Network Problem (BFS Solution)

## 📌 Problem Overview

You are asked to build a program that tracks **people and communities** in a social network.

* There are **n people** numbered from **1 to n**
* A **community** consists of:

  * A person
  * Their friends
  * Friends of friends
  * And so on (transitive friendships)

Each person **initially belongs to their own community**.

Communities **grow when friendships are formed**.

---

## ⚙️ Operations Supported

Your program must support **three operations**:

### 1. Add Operation

```
A x y
```

* Makes **person x and person y friends**
* If they belong to different communities:

  * Communities merge
* **Constraint:**

  * Ignore the operation if merged community size **exceeds m**

---

### 2. Examine Operation

```
E x y
```

* Check if **x and y belong to the same community**

**Output:**

```
Yes
```

or

```
No
```

---

### 3. Size Operation

```
S x
```

* Output the **size of the community** that person **x belongs to**

---

## 📥 Input Format

```
n m
q
operations...
```

### Input Description

| Parameter | Description                           |
| --------- | ------------------------------------- |
| n         | Number of people (1 ≤ n ≤ 100000)     |
| m         | Maximum allowed community size        |
| q         | Number of operations (1 ≤ q ≤ 200000) |

### Operations

```
A x y   (Add friendship)
E x y   (Examine)
S x     (Size)
```

---

## 📤 Output Format

* For **Examine operation**:

```
Yes
No
```

* For **Size operation**:

```
<number>
```

---

## 🚀 Approach Used: Breadth‑First Search (BFS)

This solution uses:

* **Adjacency List** for graph representation
* **BFS traversal** to find communities

### Why BFS?

* Communities are connected components
* BFS efficiently finds all reachable nodes
* Used to:

  * Check connectivity
  * Compute community size

---

## 🧠 Algorithm Overview

### Data Structures Used

```
adj_list[]  -> Graph adjacency list
min_moves[] -> Distance / visited tracking
cur_positions[] -> Current BFS level
new_positions[] -> Next BFS level
```

---

### Step‑by‑Step Logic

### Add Operation

1. Run BFS from person1
2. Compute size of community1
3. Check if person2 already connected
4. Run BFS from person2
5. Compute size of community2
6. If:

```
already connected
OR
size1 + size2 <= max community size
```

Then:

* Add edge both ways

---

### Examine Operation

1. Run BFS from person1
2. Check if person2 visited
3. Print YES / NO

---

### Size Operation

1. Run BFS from person
2. Count visited nodes
3. Print size

---

## ⏱️ Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Add       | O(N + E)   |
| Examine   | O(N + E)   |
| Size      | O(N + E)   |

Where:

* N = Number of people
* E = Number of friendships

⚠️ Note:
This BFS solution **may be slow** for worst‑case constraints.

**Optimal solution uses Union‑Find (Disjoint Set)**

However, this implementation demonstrates **graph traversal using BFS**.

---

## 💾 Memory Usage

* Adjacency list
* BFS arrays
* Edge structures

Memory Complexity:

```
O(N + E)
```

---

## 📚 Functions Explained

### `add_position()`

Adds next node in BFS traversal.

```
void add_position(...)
```

---

### `find_distance()`

Performs BFS from given person.

```
void find_distance(...)
```

---

### `size()`

Counts number of people in community.

```
int size(...)
```

---

## 🧪 Example

### Input

```
5 3
5
A 1 2
A 2 3
S 1
E 1 3
A 4 5
```

### Output

```
3
Yes
```

---

## 📌 Key Concepts Used

* Graph Representation
* Breadth‑First Search
* Connected Components
* Dynamic Graph
* Memory Efficient Design

---

## 🏁 Conclusion

This problem demonstrates:

* Social network modeling
* Graph traversal using BFS
* Handling dynamic connectivity
* Constraint‑based merging

Although **Union‑Find** is the optimal solution, this **BFS‑based approach** clearly demonstrates **graph‑based community detection**.

---