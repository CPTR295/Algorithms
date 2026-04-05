# 🔍 Binary Search Algorithms

This folder contains problems solved using **Binary Search**, a fundamental algorithm technique for finding values in sorted or monotonic sequences efficiently in **O(log n)** time.

---

## 📚 What is Binary Search?

Binary search is an efficient algorithm that works on **monotonic sequences** (strictly increasing or decreasing). It repeatedly divides the search space in half:

1. **Start** with low and high boundaries
2. **Calculate** the middle value
3. **Compare** the middle value against a condition
4. **Eliminate** half of the search space based on the result
5. **Repeat** until convergence

**Time Complexity:** O(log n)  
**Space Complexity:** O(1)

---

## 📋 Problems in This Folder

### 1. 🌳 Feeding Ants Problem

**File:** [FeedingAnts_UsingBinarySearch.c](FeedingAnts_UsingBinarySearch.c) | [FeedingAnts_UsingBinarySearch.md](FeedingAnts_UsingBinarySearch.md)

**Problem:**
- Bobi has a terrarium shaped like a tree where liquid flows downward through pipes
- Each pipe has a percentage of liquid flow and some are "superpipes" that square the liquid
- Each leaf node has an ant requiring a minimum amount of liquid
- **Goal:** Find the minimum amount of liquid to pour at the root so all ants get their required amount

**Binary Search Application:**
- Binary search on the amount of liquid poured at the root (0 to 2,000,000,000)
- Check if a given liquid amount satisfies all ants' requirements
- The monotonic property: more root liquid → more liquid reaches leaves

---

### 2. 🐄 River Jump Problem

**File:** [RiverJump_UsingBinarySearch.c](RiverJump_UsingBinarySearch.c) | [RiverJump_UsingBinarySearch.md](RiverJump_UsingBinarySearch.md)

**Problem:**
- A river of length L has rocks at position 0, L, and n rocks in between
- A cow jumps from rock to rock to cross the river
- Farmer John can remove m rocks (except start and end)
- **Goal:** Maximize the minimum jump distance after removing rocks

**Binary Search Application:**
- Binary search on the minimum jump distance (0 to L)
- Check if a given distance can be achieved by removing at most m rocks
- The monotonic property: if distance d is achievable, so is any distance < d

---

### 3. 🏙️ Living Quality Problem

**File:** [LivingQuality_UsingBinarySearch.c](LivingQuality_UsingBinarySearch.c) | [LivingQuality_UsingBinarySearch.md](LivingQuality_UsingBinarySearch.md)

**Problem:**
- A city is represented as an r × c rectangular grid
- Each block has a distinct quality rank (1 to r × c)
- **Goal:** Find the minimum median quality rank among all h × w subrectangles

**Binary Search Application:**
- Binary search on the median value (1 to r × c)
- Check if a given median value can be achieved
- The monotonic property: if median m is achievable, so is any median > m

---

## 🎯 Key Learning Points

- ✅ **Identify monotonic properties** in the problem
- ✅ **Define search space** (low and high boundaries)
- ✅ **Implement validation function** to check if a condition is met
- ✅ **Handle edge cases** carefully (loop termination, boundary updates)
- ✅ **Choose correct update strategy** for low and high pointers

---

## 🔗 Related Concepts

- **Binary Search Variants:** Lower Bound, Upper Bound
- **Prerequisites:** Sorted arrays, monotonic sequences
- **Applications:** Finding optimal values, game theory problems, numerical methods
