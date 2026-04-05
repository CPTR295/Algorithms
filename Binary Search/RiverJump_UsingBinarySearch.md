# 🐄 River Rocks — Maximize Minimum Jump Distance

## 📘 Problem Overview

There is a **river of length `L`** with rocks placed along it:

* A rock at **0** (start)
* A rock at **L** (end)
* **n** rocks in between

A **cow jumps from rock to rock** until reaching the end.

### 🦘 Jump Distance

The **minimum jump distance** is the **smallest distance between consecutive rocks**.

### 🎯 Goal

Farmer John can **remove `m` rocks** (except start and end) to:

> **Maximize the minimum jump distance**

---

## 📌 Example

River length:

```
L = 12
```

Rocks:

```
0, 5, 8, 12
```

Minimum jump:

```
min(5-0, 8-5, 12-8) = min(5, 3, 4) = 3
```

If Farmer John removes:

* Remove **5** → jumps = 8, 4 → min = **4**
* Remove **8** → jumps = 5, 7 → min = **5** ✅

### Output

```
5
```

---

## 🧠 Solution Approach

This is a **Binary Search on Answer** problem.

### Why Binary Search?

* If a **minimum distance `d`** is possible
* Then **any smaller distance** is also possible

This monotonic property allows binary search.

---

## 🔍 Algorithm Steps

### Step 1 — Sort Rocks

We sort rock locations:

```
0 → ... → L
```

---

### Step 2 — Binary Search

Search range:

```
low = 0
high = L
```

---

### Step 3 — Check Feasibility

For a given **minimum distance `d`**:

* Traverse rocks
* Remove rocks that violate minimum distance
* Count removals

If removals ≤ `m` → distance possible

---

## 📥 Input Format

```
L n m
rock1
rock2
rock3
...
```

### Example

```
12 2 1
5
8
```

---

## 📤 Output Format

Print:

```
Maximum minimum jump distance
```

Example:

```
5
```

---

## ⚙️ Constraints

| Parameter           | Range             |
| ------------------- | ----------------- |
| River length (L)    | 1 → 1,000,000,000 |
| Rocks (n)           | 0 → 50,000        |
| Removable rocks (m) | 0 → n             |
| Time limit          | 2 seconds         |

---

## 📁 Code Structure

### `can_make_min_distance()`

Checks if minimum distance is possible

```c
int can_make_min_distance(int distance, int rocks[], int num_rocks, int num_remove, int lenght)
```

### Logic

1. Start from rock 0
2. Check next rock
3. If distance < required → remove rock
4. Count removals
5. Verify removals ≤ allowed

---

### `solve()`

Binary search implementation

```c
void solve(int rocks[], int num_rocks, int num_remove, int lenght)
```

Binary search:

```
low = 0
high = length
```

---

### `compare()`

Used for sorting rocks

```c
int compare(const void *v1, const void *v2)
```

---

### `main()`

Handles:

* Input reading
* Sorting
* Calling solve()

---

## 🧪 Example Walkthrough

Input:

```
L = 25
rocks = [2, 11, 14, 17, 21]
remove = 2
```

Try minimum distance = **6**

```
0 → 2 (remove)
0 → 11 (keep)
11 → 14 (remove)
11 → 17 (keep)
17 → 21 (remove)
```

Removed = 3 ❌ Not allowed

Try smaller distance…

Binary search continues.

---

## ⏱️ Time Complexity

| Operation     | Complexity     |
| ------------- | -------------- |
| Sorting       | O(n log n)     |
| Binary Search | O(log L)       |
| Checking      | O(n)           |
| Total         | **O(n log L)** |

Efficient for:

```
n ≤ 50,000
```

---

## 💡 Key Concepts

* Binary Search on Answer
* Greedy Strategy
* Sorting
* Simulation

---