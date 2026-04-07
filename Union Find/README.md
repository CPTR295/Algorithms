# 🔗 Union Find (Disjoint Set Union) Algorithms

This folder contains problems solved using **Union Find** (also known as **Disjoint Set Union - DSU**), a data structure that efficiently manages and merges disjoint sets, supporting quick queries about whether two elements belong to the same set.

---

## 📚 What is Union Find?

Union Find is a data structure designed to solve problems involving **grouping elements into connected components** and **quickly determining if two elements are in the same group**.

**Core Operations:**

1. **Find(x):** Determine which set element x belongs to (time: O(α(n)))
2. **Union(x, y):** Merge the sets containing x and y (time: O(α(n)))

where α(n) is the inverse Ackermann function ≈ O(1) in practice.

**Implementation Techniques:**
- **Path Compression:** When finding a root, directly attach nodes to the root
- **Union by Rank/Size:** Attach smaller tree to larger tree to keep it balanced

**Time Complexity:** O(α(n)) per operation ≈ O(1) for practical purposes  
**Space Complexity:** O(n)

---

## 📋 Problems in This Folder

### 1. 🗄️ Drawer Chore Problem

**File:** [DrawerChore_UsingUnionFind.c](DrawerChore_UsingUnionFind.c) | [DrawerChore_UsingUnionFind.md](DrawerChore_UsingUnionFind.md)

**Problem:**
- Mirko has **n items** and **d drawers**
- Each drawer can hold **at most one item**
- Each item can be placed in **two possible drawers (A or B)**
- Follow placement rules in order: try drawer A, then drawer B, otherwise throw away
- **Goal:** Determine which items can be placed and which must be thrown away

**Union Find Application:**
- Track which drawers are connected/equivalent based on placement chains
- Use union operations to merge drawers that become full
- Quickly check if alternative drawer options are available

---

### 2. 🤝 Friends and Enemies Problem

**File:** [FriendsAndEnemies_UsingUnionFind.c](FriendsAndEnemies_UsingUnionFind.c) | [FriendsAndEnemies_UsingUnionFind.md](FriendsAndEnemies_UsingUnionFind.md)

**Problem:**
- Track **n people** (numbered 0 to n-1) and their relationships
- Support two operations:
  - **Friend(x, y):** Declare x and y are friends (reflexive, symmetric, transitive)
  - **Enemy(x, y):** Declare x and y are enemies (and friends of friends become enemies)
- **Goal:** Process operations and detect conflicts in relationships

**Union Find Application:**
- Maintain two sets per person: friends and enemies
- When x and y become friends: union their friend groups
- When x and y become enemies: union x's friend group with y's enemy group
- Detect conflicts when a person is declared both friend and enemy

---

### 3. 👥 Social Network Communities Problem

**File:** [SocialNetwork_UsingUnionFind.c](SocialNetwork_UsingUnionFind.c) | [SocialNetwork_UsingUnionFind.md](SocialNetwork_UsingUnionFind.md)

**Problem:**
- Track **n people** (numbered 1 to n) and their **communities**
- A community consists of a person, their friends, friends of friends, etc.
- Support three operations:
  - **Add(x, y):** Make x and y friends (merge communities if size ≤ m)
  - **Examine(x, y):** Check if x and y are in the same community
  - **Report():** Output the size of the largest community
- **Goal:** Efficiently manage community merges with size constraints

**Union Find Application:**
- Use Union Find to track connected components (communities)
- Store component sizes with each representative
- Check size constraint before merging communities
- Answer community membership queries in nearly O(1) time

---

## 🎯 Key Learning Points

- ✅ **Understand the find() operation** with path compression optimization
- ✅ **Master the union() operation** with union by rank/size heuristic
- ✅ **Identify problems requiring grouping/connectivity** checks
- ✅ **Extend Union Find for complex relationships** (like Friend/Enemy with two sets)
- ✅ **Track metadata with representatives** (like component size)
- ✅ **Optimize for near-constant time operations** through path compression and union heuristics

---

## 🔗 Related Concepts

- **Applications:** 
  - Connectivity problems
  - Cycle detection in graphs
  - Minimum spanning trees (Kruskal's algorithm)
  - Equivalent elements/groups
  - Network connectivity
  
- **Prerequisites:** Basic understanding of sets and graph connectivity

- **Variants:**
  - Weighted Union Find
  - Union Find with additional metadata tracking
  - Reverse offline Union Find

---

## 💡 Implementation Tips

1. **Path Compression:** Make find() more efficient by pointing nodes directly to root
2. **Union by Rank:** Keep the tree shallow by always attaching smaller tree to larger
3. **Rank vs Size:** Rank is cleaner but size is useful when you need to track component sizes
4. **Representative Storage:** Store additional data (size, metadata) only at the root node
