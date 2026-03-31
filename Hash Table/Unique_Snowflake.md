# ❄️ Unique Snowflakes Problem (Hash Table Solution in C)

## 📌 Problem Statement

We are given a collection of snowflakes, and we must determine whether **any two snowflakes are identical**.

Each snowflake is represented by **six integers**, describing its arms. Two snowflakes are considered **identical** if one can be rotated **clockwise or counter-clockwise** to match the other.

---

## 📥 Input

* The first line contains an integer **n** (1 ≤ n ≤ 100,000), representing the number of snowflakes.
* The next **n lines** each contain **six integers**
* Each integer is in the range **0 to 10,000,000**

### Example Input

```
3
1 2 3 4 5 6
4 5 6 1 2 3
10 20 30 40 50 60
```

---

## 📤 Output

Print **exactly one** of the following:

* If **no identical snowflakes exist**:

```
No two snowflakes are alike.
```

* If **at least two identical snowflakes exist**:

```
Twin snowflakes found.
```

---

## ⚡ Constraints

* n ≤ 100,000
* Time Limit: **2 seconds**
* Efficient solution required (O(n) expected)

---

## 🧠 Approach

This solution uses:

* **Hash Table**
* **Linked List (Chaining)**
* **Rotation Comparison (Clockwise + Counter-Clockwise)**

### Steps

1. Read each snowflake (6 integers)
2. Generate a **hash code** using sum of values
3. Insert snowflake into hash table bucket
4. Compare with existing snowflakes in same bucket
5. Check for **rotational equality**
6. If match found → print result immediately

---

## 🔑 Key Functions

### `code()`

Generates hash index using sum of snowflake arms.

```
hash = (sum of 6 integers) % SIZE
```

---

### `identical_right()`

Checks clockwise rotation match

---

### `identical_left()`

Checks counter-clockwise rotation match

---

### `are_identical()`

Calls both rotation functions to determine match

---

### `identify_identical()`

Traverses hash table and checks for duplicates

---

## 🧩 Data Structure Used

```
typedef struct snowflake_node
{
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;
```

* Uses **separate chaining**
* Handles hash collisions efficiently

---

## 🚀 Time Complexity

| Operation   | Complexity       |
| ----------- | ---------------- |
| Hash insert | O(1) average     |
| Comparison  | O(1)             |
| Overall     | **O(n)** average |

---

## 💾 Memory Usage

* Hash table size: **100000**
* Linked list nodes for collision handling

---

## ▶️ Compile & Run

### Compile

```
gcc Unique_Snowflake.c -o snowflake
```

### Run

```
./snowflake
```

---

## 🧪 Example

Input:

```
2
1 2 3 4 5 6
4 5 6 1 2 3
```

Output:

```
Twin snowflakes found.
```

---

## 📚 Algorithm Type

* Hashing
* Collision Handling
* Rotation Matching
* Algorithmic Thinking
