# 🧾 Supermarket Promotion — Total Prize Calculation

## 📘 Problem Overview

A supermarket is running a **promotion for `n` days**.

### How It Works

1. Every shopper gets a **receipt** with total purchase cost
2. Each day's receipts are placed in a **ballot box**
3. At **end of each day**:

   * Remove **maximum-cost receipt (x)**
   * Remove **minimum-cost receipt (y)**
   * Give prize worth:

```
x - y
```

4. Removed receipts are **permanently discarded**
5. Remaining receipts **stay for next day**

🎯 **Goal:**
Compute **total prize money** given during the promotion

---

## 📥 Input Format

```
n
k cost1 cost2 cost3 ...
k cost1 cost2 ...
...
```

### Parameters

| Variable | Meaning                         |
| -------- | ------------------------------- |
| n        | number of days                  |
| k        | number of receipts for that day |
| cost     | receipt values                  |

---

## 📌 Constraints

| Parameter      | Limit                       |
| -------------- | --------------------------- |
| Days (n)       | 1 — 5000                    |
| Total receipts | ≤ 1,000,000                 |
| Cost value     | ≤ 1,000,000                 |
| Time limit     | Efficient solution required |

---

## 🧠 Solution Approach

This problem requires:

> Efficiently finding **minimum and maximum** repeatedly

### Best Data Structure

Use **Two Heaps**:

| Heap     | Purpose              |
| -------- | -------------------- |
| Max Heap | Find maximum receipt |
| Min Heap | Find minimum receipt |

---

## ⚙️ Algorithm Steps

### For each day

1. Add all new receipts to:

   * max heap
   * min heap

2. Extract:

   * maximum receipt
   * minimum receipt

3. Mark them as **used**

4. Add:

```
total += max - min
```

---

## 📁 Data Structures Used

### Heap Element

```c
typedef struct heap_element
{
    int receipt_index;
    int cost;
}heap_element;
```

Why `receipt_index`?

To **avoid removing duplicates incorrectly**
We mark receipts using:

```c
used[receipt_index]
```

---

## 🔧 Functions

### Max Heap Insert

```c
max_heap_insert()
```

* Insert element
* Bubble up

---

### Max Heap Extract

```c
max_heap_extract()
```

* Remove root
* Heapify down

---

### Min Heap Insert

```c
min_heap_insert()
```

* Insert element
* Bubble up

---

### Min Heap Extract

```c
min_heap_extract()
```

* Remove root
* Heapify down

---

## 🔁 Main Logic

```c
for each day
    add receipts
    remove max
    remove min
    mark used
    add difference
```

---

## 🧪 Example

### Input

```
3
3 10 20 30
2 5 15
2 8 25
```

### Process

Day 1:

```
30 - 10 = 20
```

Remaining:

```
20
```

Day 2:

```
20 5 15
20 - 5 = 15
```

Remaining:

```
15
```

Day 3:

```
15 8 25
25 - 8 = 17
```

### Output

```
20 + 15 + 17 = 52
```

---

## ⏱️ Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Extract   | O(log n)   |
| Total     | O(n log n) |

Efficient for:

```
1,000,000 receipts
```

---

## 💡 Key Concepts

* Heap / Priority Queue
* Lazy deletion (used array)
* Efficient min/max tracking

---

## 🧠 Why This Problem is Good

This problem teaches:

* Dual heap usage
* Efficient large input handling
* Lazy deletion technique

---