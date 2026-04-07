# War Relationships (Friends & Enemies) - Union Find Solution

## 📌 Problem Overview

This problem extends **Union-Find** to support **Friends and Enemies relationships**.

You are given **n people** numbered:

```
0, 1, 2, ... n-1
```

Initially:

* No one is friends
* No one is enemies

You must process operations that define relationships between people.

This is **UVa Problem 10158 — War**.

---

# ⚙️ Operations Supported

You must support **four operations**:

## 1. Set Friends

```
1 x y
```

Record that:

```
x and y are friends
```

### Rules

* Friends belong to same group
* Friendship is:

  * Reflexive
  * Symmetric
  * Transitive

If conflict occurs:

```
Output: -1
```

---

## 2. Set Enemies

```
2 x y
```

Record that:

```
x and y are enemies
```

### Rules

* Enemy is symmetric
* Enemy is NOT transitive

Important rule:

```
Enemy of enemy is friend
```

If conflict occurs:

```
Output: -1
```

---

## 3. Are Friends

```
3 x y
```

Output:

```
1 → If x and y are friends
0 → Otherwise
```

---

## 4. Are Enemies

```
4 x y
```

Output:

```
1 → If x and y are enemies
0 → Otherwise
```

---

# 📥 Input Format

```
n
operations...
0 x y
```

### Description

| Parameter | Description                |
| --------- | -------------------------- |
| n         | Number of people (< 10000) |

Operations:

```
1 x y  → Set Friends
2 x y  → Set Enemies
3 x y  → Are Friends
4 x y  → Are Enemies
0 x y  → End
```

---

# 📤 Output Format

| Operation  | Output       |
| ---------- | ------------ |
| SetFriends | Nothing / -1 |
| SetEnemies | Nothing / -1 |
| AreFriends | 1 / 0        |
| AreEnemies | 1 / 0        |

---

# 🚀 Approach Used

## Union-Find with Enemy Tracking

This solution uses:

* Disjoint Set (Union-Find)
* Enemy mapping
* Path Compression
* Union by Size

---

# 🧠 Data Structures Used

```
parent[]   → stores parent
size[]     → size of set
enemy_of[] → enemy of set
```

---

# 🔧 Core Functions

## 1. Find Function (Path Compression)

```
int find(int person, int parent[])
```

### Purpose

* Find root of set
* Path compression optimization

---

## 2. Union Sets

```
int union_sets(...)
```

### Purpose

* Merge two sets
* Union by size

---

## 3. Set Friends

```
set_friends(...)
```

### Logic

1. Merge both friend sets
2. Merge their enemies
3. Update enemy mapping

---

## 4. Set Enemies

```
set_enemies(...)
```

### Logic

1. Make enemy relationships
2. Merge enemy sets
3. Apply rule:

```
Enemy of enemy = friend
```

---

## 5. Are Friends

```
are_friends(...)
```

Check:

```
find(x) == find(y)
```

---

## 6. Are Enemies

```
are_enemies(...)
```

Check:

```
enemy_of[set(x)] == set(y)
```

---

# ⏱️ Time Complexity

| Operation  | Complexity |
| ---------- | ---------- |
| SetFriends | O(α(N))    |
| SetEnemies | O(α(N))    |
| AreFriends | O(α(N))    |
| AreEnemies | O(α(N))    |

Where:

```
α(N) = Inverse Ackermann Function
```

Nearly constant time.

---

# 💾 Memory Complexity

```
O(N)
```

Efficient memory usage.

---

# 🧪 Example

### Input

```
5
1 0 1
2 1 2
3 0 2
4 0 2
0 0 0
```

### Output

```
0
1
```
---

# 📚 Concepts Used

* Union-Find
* Disjoint Set
* Path Compression
* Union by Size
* Graph Theory
* Enemy Relationships

---

# ⚡ Key Insight

This problem extends Union-Find by tracking:

```
Friend groups
Enemy groups
```

Important identity:

```
Enemy of enemy = friend
```

---

# 🏁 Conclusion

This problem demonstrates:

* Advanced Union-Find usage
* Handling friend/enemy relations
* Conflict detection
* Efficient query handling

This is a **classic advanced Union-Find problem**.

---

