# 🌳 Heaps And Segment Trees

This folder contains problems solved using **Heaps** and **Segment Trees**, two powerful data structures for efficiently managing and querying collections of data. These algorithms enable fast operations on priorities, ranges, and dynamic updates.

---

## 📚 What are Heaps and Segment Trees?

### Heaps

A **heap** is a specialized tree-based data structure that satisfies the heap property:
- **Max Heap:** Parent node ≥ all children
- **Min Heap:** Parent node ≤ all children

**Key Operations:**
- Insert: O(log n)
- Extract min/max: O(1) access, O(log n) removal
- Heapify: O(n)

**Applications:** Priority queues, finding extremes, heap sort

### Segment Trees

A **segment tree** is a tree structure optimized for:
- **Range Queries:** Find metrics (min, max, sum) over a range in O(log n)
- **Point Updates:** Update a single element in O(log n)
- **Space Complexity:** O(n)

**Key Features:**
- Built bottom-up from array elements
- Each node represents a range and stores aggregate data
- Enables efficient interval-based computations

---

## 📋 Problems in This Folder

### 1. 🌳 Building a Treap Using Recursion

**File:** [BuildingTreaps_UsingRecursion.c](BuildingTreaps_UsingRecursion.c) | [BuildingTreaps_UsingRecursion.md](BuildingTreaps_UsingRecursion.md)

**Problem:**
- A **Treap** (Tree + Heap) is a hybrid structure combining a Binary Search Tree and a Max Heap
- Each node contains a label (BST key) and a priority (heap criterion)
- Must satisfy both BST property (left < root < right) and heap property (parent priority ≥ children)
- **Goal:** Construct and print a treap from given nodes

**Approach:**
- Sort nodes by label to ensure BST property
- Recursively select the node with maximum priority as root
- Build left and right subtrees on sorted sublists
- Output in parenthesized format: `(left root right)`

**Time Complexity:** O(n²) worst case (scanning for max priority each recursion level)

**When to Use:**
- Small to medium datasets (n < 1000)
- When simplicity and clarity are priorities

---

### 2. 🌳 Building a Treap Using Segment Tree

**File:** [BuildingTreaps_UsingSegmentTree.c](BuildingTreaps_UsingSegmentTree.c) | [BuildingTreaps_UsingSegmentTree.md](BuildingTreaps_UsingSegmentTree.md)

**Problem:**
- Same treap construction problem as above, but with optimized performance
- Build a treap while handling large numbers of nodes efficiently

**Optimization:**
- Use a **segment tree** to store indices of maximum priority nodes for any range
- Query maximum priority in O(log n) instead of O(n)
- Reduces overall construction time from O(n²) to O(n log n)

**Approach:**
1. Sort nodes by label
2. Build segment tree indexing maximum priority elements
3. Use segment tree queries to recursively construct treap
4. Each query finds max priority in range in O(log n)

**Time Complexity:** O(n log n) - significantly faster for large inputs

**When to Use:**
- Large datasets (n > 1000)
- Competitive programming with tight time limits

**Key Learning:** Demonstrates how segment trees accelerate recursive operations

---

### 3. 💳 Supermarket Promotion Using Heap

**File:** [SupermarketPromotion_UsingHeap.c](SupermarketPromotion_UsingHeap.c) | [SupermarketPromotion_UsingHeap.md](SupermarketPromotion_UsingHeap.md)

**Problem:**
- A supermarket runs a multi-day promotion collecting customer receipts
- Each day at closing time:
  - Identify the receipt with maximum cost
  - Identify the receipt with minimum cost
  - Award a prize worth: `max_cost - min_cost`
  - Permanently remove both receipts
  - Keep remaining receipts for next day
- **Goal:** Calculate the total prize money awarded during the entire promotion

**Heap-Based Solution:**
- Maintain a **max heap** for quick access to maximum costs
- Maintain a **min heap** for quick access to minimum costs
- Each day: extract from both heaps, accumulate differences, add new receipts
- Mark extracted receipts as used to handle duplicates across days

**Time Complexity:** O(k log k) per day, where k = receipts that day

**Constraints:**
- Days: 1 to 5000
- Total receipts: up to 1,000,000
- Cost values: up to 1,000,000

**When to Use:**
- Finding min and max repeatedly in dynamic collections
- Multi-source min/max tracking problems

**Key Learning:** Two heaps pattern for tracking extremes efficiently

---

### 4. 📊 Maximum Pair Sum Using Segment Tree

**File:** [TwoSums_UsingSegmentTree.c](TwoSums_UsingSegmentTree.c) | [TwoSums_UsingSegmentTree.md](TwoSums_UsingSegmentTree.md)

**Problem:**
- An array contains up to 1,000,000 elements
- Support two operations:
  1. **Range Query:** Find the sum of the two largest elements in range [L, R]
  2. **Update:** Change an element at a specific index
- **Goal:** Efficiently handle both queries and updates

**Approach:**
- Build a **segment tree** where each node stores:
  - `max_sum`: The sum of the two largest elements in the range
  - `max_element`: The largest element in the range
- When merging two segments, compute max pair sum from their max elements
- Support O(log n) updates that rebuild only affected nodes

**Operations:**
| Operation | Time | Space |
|-----------|------|-------|
| Build Tree | O(n) | O(n) |
| Range Query | O(log n) | - |
| Update | O(log n) | - |

**When to Use:**
- Finding top-2 contributors in ranges
- Dynamic weighted pair scoring
- Range-based optimization problems requiring top-k elements

**Key Learning:** Segment trees enable complex aggregation queries with updates

---

## 🎯 Key Learning Points

- ✅ **Heaps** provide O(log n) insert/delete while maintaining min/max in O(1)
- ✅ **Two Heaps** pattern solves many min/max problems elegantly
- ✅ **Segment Trees** enable O(log n) range queries on dynamic data
- ✅ **Treaps** combine BST balance with heap ordering
- ✅ **Optimization** through different data structures: O(n²) → O(n log n)
- ✅ **Recursive construction** patterns with sorted data and priority selection

---

## 🔗 Related Concepts

- **Binary Search Trees:** Ordered collections with O(log n) operations
- **Priority Queues:** Heap implementations for priority-based processing
- **Range Queries:** Interval analysis and aggregate computations
- **Dynamic Data Structures:** Handling updates while maintaining properties
- **Recursion:** Tree construction and divide-and-conquer strategies
