# GrandmaPlanner Problem - Dijkstra's Alg

## 📌 Problem Overview

Bruce is planning a trip to his **grandma’s house** while carrying a **box of cookies**.

There are **n towns**:

* Bruce starts from **Town 1**
* Grandma lives in **Town n**
* Some towns contain **cookie stores**

Bruce **must visit at least one cookie store** on his way to grandma’s house.

---

## 🎯 Problem Goals

You must determine:

1. **Minimum distance** from Town 1 → Town n
2. **Number of minimum-distance routes**
3. Route must pass through **at least one cookie store**

---

## 🧠 Key Observations

* Roads exist **between every pair of towns**
* Distance is **symmetric**
* Must visit **at least one cookie town**
* Need both:

  * **Shortest path**
  * **Count of shortest paths**

---

## 📥 Input Format

```
n
```

Where:

| Variable | Description             |
| -------- | ----------------------- |
| n        | Number of towns (2–700) |

Next **n lines**:

```
Distance Matrix
```

Each line contains **n integers** representing distances.

Then:

```
m
```

Where:

| Variable | Description            |
| -------- | ---------------------- |
| m        | Number of cookie towns |

Then:

```
town1 town2 town3 ...
```

---

## 📤 Output Format

```
minimum_distance number_of_routes
```

Where:

* Routes counted **mod 1,000,000**

---

## 📊 Constraints

| Parameter        | Limit |
| ---------------- | ----- |
| Towns            | ≤ 700 |
| Distance         | ≥ 1   |
| Must visit store | Yes   |

---

## 🧠 Approach

### Algorithm Used

This problem uses:

* **Modified Dijkstra's Algorithm**
* **State-based shortest path**
* **Path counting**

---

## 🔎 Key Idea

Each town has **two states**:

| State | Meaning                 |
| ----- | ----------------------- |
| 0     | No cookie collected yet |
| 1     | Cookie collected        |

We run **Dijkstra with state tracking**:

```
Town + Cookie State
```

Example:

```
Town 5 without cookie → (5,0)
Town 5 with cookie → (5,1)
```

---

## ⚙️ Implementation Details

### Data Structures

```c
typedef struct edge
{
    int to_town;
    int length;
    struct edge *next;
} edge;
```

---

### Key Arrays

```c
min_distances[town][state]
num_paths[town][state]
done[town][state]
```

---

### Algorithm Steps

1. Start from `(Town 1, No Cookie)`
2. Apply **Dijkstra**
3. If town has store → switch to **cookie state**
4. Track:

   * Minimum distance
   * Number of paths
5. Output result at `(Town n, Cookie state)`

---

## ⏱️ Time Complexity

```
O((V^2) * 2)
```

Where:

* V = number of towns

Efficient for **n ≤ 700**.

---

## 📚 Concepts Used

* Graph Theory
* Dijkstra Algorithm
* Dynamic Programming (State Tracking)
* Shortest Path Counting

---