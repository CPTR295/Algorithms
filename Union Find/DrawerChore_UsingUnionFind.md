# Drawer Problem (LADICA) - Union Find Solution

## 📌 Problem Overview

Mirko has **n items** and **d drawers**.

* Items numbered: `1 → n`
* Drawers numbered: `1 → d`
* Each drawer can hold **at most one item**

Each item can be placed in **two possible drawers**:

```
Drawer A
Drawer B
```

Your task is to determine whether each item can be placed in a drawer or must be thrown away.

This is the **COCI "LADICA" Problem**.

---

# ⚙️ Placement Rules

For each item, apply these rules in order:

### Rule 1

If **Drawer A is empty**:

```
Place item in Drawer A
```

---

### Rule 2

If **Drawer B is empty**:

```
Place item in Drawer B
```

---

### Rule 3

If **Drawer A is full**:

* Move existing item to its other drawer
* Continue shifting items
* If chain ends → place item

---

### Rule 4

If **Drawer B is full**:

* Same shifting process

---

### Rule 5

If all fail:

```
Throw item away
```

---

# 📥 Input Format

```
n d
A1 B1
A2 B2
...
An Bn
```

### Description

| Parameter | Description                  |
| --------- | ---------------------------- |
| n         | Number of items (≤ 300000)   |
| d         | Number of drawers (≤ 300000) |

Each line:

```
a b
```

Where:

* a = drawer A
* b = drawer B

---

# 📤 Output Format

For each item output:

```
LADICA  → Item placed
SMECE   → Item discarded
```

---

# 🚀 Approach Used

## Union-Find (Disjoint Set)

This problem is solved using **Union-Find**.

### Key Idea

* Treat drawers as sets
* If drawer full → use parent drawer
* Merge drawers when used

---

# 🧠 Data Structures Used

```
parent[] → tracks available drawer
```

---

# 🔧 Core Functions

## 1. Find Function

```
int find(int drawer, int parent[])
```

### Purpose

* Find next available drawer
* Path compression optimization

---

## 2. Union Function

```
void union_sets(...)
```

### Purpose

* Merge drawers
* Mark drawer as used

---

# 🔁 Algorithm Flow

For each item:

### Step 1

Check Drawer A

```
find(A)
```

If available → place item

---

### Step 2

Check Drawer B

```
find(B)
```

If available → place item

---

### Step 3

If both used:

Try shifting using union

---

### Step 4

If no space:

```
Print SMECE
```

---

# ⏱️ Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Find      | O(α(N))    |
| Union     | O(α(N))    |
| Total     | O(N)       |

Where:

```
α(N) = Inverse Ackermann Function
```

Very fast.

---

# 💾 Memory Complexity

```
O(D)
```

Where:

```
D = number of drawers
```

---

# 🧪 Example

### Input

```
3 2
1 2
1 2
1 2
```

### Output

```
LADICA
LADICA
SMECE
```

---

# 📚 Concepts Used

* Union-Find
* Disjoint Set
* Path Compression
* Greedy Placement
* Optimization

---

# ⚡ Key Insight

Each drawer points to:

```
Next available drawer
```

Union-Find efficiently handles:

* Drawer chaining
* Item shifting

---

# 🏁 Conclusion

This problem demonstrates:

* Advanced Union-Find usage
* Efficient placement strategy
* Large input handling

This is a **classic competitive programming Union-Find problem**.

---
