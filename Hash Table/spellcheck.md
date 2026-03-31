# ✂️ Spell Check - Delete One Character Problem (String Matching in C)

## 📌 Problem Statement

We are given **two strings**, where:

* The **first string** has **exactly one more character** than the second string
* Our task is to determine **how many ways** we can **delete one character** from the first string to make it equal to the second string

---

## 🧠 Example

### Example 1

Input:

```text
favour
favor
```

Output:

```text
1
4
```

Explanation:

* Remove **'u'** (index 4) from **favour**
* Result becomes **favor**

---

### Example 2

Input:

```text
abcdxxxef
abcdxxef
```

Output:

```text
3
5 6 7
```

Explanation:

* Remove any one of the **three 'x' characters**
* Three possible deletions

---

## 📥 Input

* Two lines of input:

  * First line → First string (longer string)
  * Second line → Second string (shorter string)
* Maximum string length: **1,000,000 characters**

Example:

```text
bizzarre
bizarre
```

---

## 📤 Output

If **no valid deletion exists**:

```text
0
```

Otherwise:

* First line → Number of ways
* Second line → Space-separated list of **indices (1-based)**

Example:

```text
2
3 4
```

---

## ⚡ Constraints

| Constraint                         | Value     |
| ---------------------------------- | --------- |
| Max string length                  | 1,000,000 |
| Time limit                         | 2 seconds |
| Memory efficient solution required | Yes       |

---

## 🧠 Approach

Instead of brute-force deletion (which is slow), we use:

* **Prefix Matching**
* **Suffix Matching**
* **Efficient String Comparison**

### Steps

1. Find **prefix match length**
2. Find **suffix match length**
3. Calculate overlapping deletion positions
4. Print valid indices

---

## 🔑 Key Functions

### `prefix_length()`

Finds how many characters match from the **beginning**

```c
int prefix_length(char s1[],char s2[])
```

Example:

```
bizzarre
bizarre
```

Prefix match = **"biz"**

---

### `suffix_length()`

Finds how many characters match from the **end**

```c
int suffix_length(char s1[],char s2[], int len)
```

Example:

```
bizzarre
bizarre
```

Suffix match = **"arre"**

---

## 🧮 Formula Used

```c
total = (prefix + 1) - (len - suffix) + 1;
```

This calculates **valid deletion positions**

---

## ⚙️ Algorithm Efficiency

| Operation   | Complexity |
| ----------- | ---------- |
| Prefix scan | O(n)       |
| Suffix scan | O(n)       |
| Overall     | **O(n)**   |

Works efficiently for **1 million characters**

---

## 💾 Memory Usage

* Two string arrays
* Minimal extra memory

---

## ▶️ Compile & Run

### Compile

```bash
gcc delete_char.c -o delete
```

### Run

```bash
./delete
```

---

## 🧪 Example

### Input

```text
abcdxxxef
abcdxxef
```

### Output

```text
3
5 6 7
```

---

## 📚 Algorithm Type

* String Processing
* Two-pointer Technique
* Prefix-Suffix Matching
* Efficient String Comparison

---

## 🎯 Why This Approach?

### ❌ Brute Force

* Try deleting each character
* Compare strings
* Time Complexity → **O(n²)** (Too slow)

### ✅ Optimized Approach

* Prefix + Suffix matching
* Time Complexity → **O(n)**
