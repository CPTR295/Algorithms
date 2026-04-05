# 🏙️ Living Quality — Minimum Median Quality

## 📘 Problem Overview

A city is represented as a **rectangular grid** with:

* **r rows** (0 → r−1)
* **c columns** (0 → c−1)

Each block in the city has a **distinct quality rank** from:

```
1 → r × c
```

Your task is to:

> Find the **minimum median quality rank** among **all rectangles of size `h × w`**

---

## 📊 Example

Given a **7 × 7** city:

```
48 16 15 45 40 28  8
20 11 36 19 24  6 33
22 39 30  7  9  1 18
14 35  2 13 31 12 46
32 37 21  3 41 23 29
42 49 38 10 17 47  5
43  4 34 25 26 27 44
```

If:

```
h = 5
w = 3
```

We examine all **5 × 3 rectangles**

### Result

```
Minimum median quality = 13
```

---

## 🧠 Key Insight

Instead of:

* Computing median for **every rectangle** (too slow)

We use:

> **Binary Search + Prefix Sum / Sliding Window Idea**

---

## 🎯 Solution Strategy

### Step 1 — Binary Search on Answer

We binary search on **median quality value**

```
low = 0
high = r × c
```

---

### Step 2 — Convert Grid to -1 / +1

For a given **quality = mid**

Convert:

```
q[i][j] ≤ mid  →  -1
q[i][j] > mid  →  +1
```

Why?

If sum of rectangle ≤ 0

Then:

```
More elements ≤ mid
```

So **mid is valid median**

---

### Step 3 — Check Rectangles

For every **h × w rectangle**:

* Calculate sum
* If sum ≤ 0 → valid

---

### Step 4 — Binary Search Update

```
If valid → search smaller median
Else → search larger median
```

---

## 📥 Function Signature

```c
int rectangle(int r, int c, int h, int w, int q[3001][3001])
```

### Parameters

| Parameter | Description       |
| --------- | ----------------- |
| r         | number of rows    |
| c         | number of columns |
| h         | rectangle height  |
| w         | rectangle width   |
| q         | quality matrix    |

---

## 📁 Code Structure

### `rectangle()`

Binary search driver

```c
int rectangle(int r, int c, int h, int w, board q)
```

Binary search:

```
low → invalid
high → valid
```

---

### `can_make_quality()`

Checks if given median is possible

```c
int can_make_quality(int quality, int r, int c, int h,int w,board q)
```

Steps:

1. Convert grid → -1 / +1
2. Check all rectangles
3. Return success if found

---

### `median()` (Naive approach)

```c
int median(...)
```

* Extract rectangle
* Sort
* Find median

⚠️ Too slow for large inputs

---

## ⚙️ Constraints

| Parameter   | Value      |
| ----------- | ---------- |
| Rows (r)    | ≤ 3001     |
| Columns (c) | ≤ 3001     |
| Time Limit  | 10 seconds |
| Memory      | Large grid |

---

## ⏱️ Time Complexity

| Approach      | Complexity                 |
| ------------- | -------------------------- |
| Naive         | O(r × c × h × w × log(hw)) |
| Binary Search | O(log(rc) × r × c)         |

Efficient enough.

---

## 💡 Important Observations

* All numbers are **distinct**
* `h` and `w` are **odd**
* Median is **well-defined**

---

## 🚀 Optimization Idea (Future Improvement)

Use **Prefix Sum** for faster rectangle sum:

```
O(1) per rectangle
```

Instead of:

```
O(h × w)
```

---

## 🧠 Concepts Used

* Binary Search on Answer
* 2D Grid Processing
* Median Optimization
* Greedy Logic

---