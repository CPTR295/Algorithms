# Social Network Communities (Union-Find Solution)

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
YES
```

or

```
NO
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
YES
NO
```

* For **Size operation**:

```
<number>
```

---

# 🚀 Approach Used: Union-Find (Disjoint Set)

This solution uses **Union-Find (Disjoint Set)** data structure.

This is the **optimal solution** for dynamic connectivity problems.

### Why Union-Find?

* Fast connectivity checks
* Fast community merging
* Efficient memory usage
* Works within strict time limits

---

## 🧠 Algorithm Overview

### Data Structures Used

```
parent[]  -> Stores parent of each person
size[]    -> Stores size of each community
```

---

## 🔧 Core Functions

### 1. Find Function

Finds the root community of a person.

```
int find(int person, int parent[])
```

### Logic

* Traverse parent until root found
* Root represents community leader

---

### 2. Union Function

Merges two communities if allowed.

```
void union_communities(...)
```

### Steps

1. Find community of person1
2. Find community of person2
3. If different communities:

Check constraint:

```
size1 + size2 <= max community size
```

If allowed:

* Merge communities
* Update size

---

## 🔁 Operation Handling

### Add Operation

```
A x y
```

* Merge communities using union

---

### Examine Operation

```
E x y
```

* Check if both have same root

```
find(x) == find(y)
```

---

### Size Operation

```
S x
```

* Print size of root community

```
size[find(x)]
```

---

## ⏱️ Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Add       | O(α(N))    |
| Examine   | O(α(N))    |
| Size      | O(α(N))    |

Where:

```
α(N) = Inverse Ackermann Function (Nearly Constant)
```

This is **extremely fast** and suitable for large inputs.

---

## 💾 Memory Complexity

```
O(N)
```

Efficient memory usage using arrays.

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
YES
```

---

## 📚 Concepts Used

* Disjoint Set
* Union-Find
* Dynamic Connectivity
* Community Tracking
* Graph Components

---

## ⚡ Why This Solution Is Better Than BFS

| Approach   | Complexity         | Suitable |
| ---------- | ------------------ | -------- |
| BFS        | O(N + E) per query | ❌ Slow   |
| Union-Find | Near O(1)          | ✅ Fast   |

Union-Find is **recommended solution**.

---

## 🏁 Conclusion

This problem demonstrates:

* Efficient community tracking
* Disjoint Set implementation
* Handling constraints during merge
* Optimized connectivity queries

Union-Find provides **fast and scalable solution** for large datasets.

---
