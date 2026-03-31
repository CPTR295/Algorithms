# 🔗 Compound Words Detection (Hash Table Solution in C)

## 📌 Problem Statement

We are given a **wordlist** where each word is a lowercase string.
Our task is to **identify compound words**.

A **compound word** is defined as:

> A string formed by concatenating **exactly two other words** from the same wordlist.

### Example

Input words:

```text
crea
create
open
te
```

Output:

```text
create
```

Explanation:

* **create = crea + te** ✅
* Other words are not compound words ❌

---

## 📥 Input

* One word per line
* Words are in **alphabetical order**
* Maximum **120,000 words**
* Words contain only **lowercase letters**

### Example Input

```text
crea
create
open
te
```

---

## 📤 Output

Print each **compound word** on its own line in **alphabetical order**

### Example Output

```text
create
```

---

## ⚡ Constraints

| Constraint  | Value                  |
| ----------- | ---------------------- |
| Max words   | 120,000                |
| Word type   | Lowercase strings      |
| Time Limit  | 3 seconds              |
| Word length | Small (≤ 16 initially) |

---

## 🧠 Approach

This solution uses:

* **Hash Table**
* **String Splitting**
* **Fast Hash Function (OAAT)**

### Steps

1. Read all words
2. Insert each word into hash table
3. For each word:

   * Split into two parts
   * Check if both parts exist in hash table
4. If yes → print compound word

---

## 🔑 Key Components

### Hash Function — `oaat()`

Uses **One-at-a-Time Hash** for fast lookup:

```c
unsigned oaat(char *key, unsigned key_len, unsigned num_bits)
```

Advantages:

* Fast
* Low collisions
* Suitable for strings

---

## 🧩 Data Structure Used

### Word Node

```c
typedef struct word_node
{
    char **word;
    struct word_node *next;
} word_node;
```

* Uses **linked list chaining**
* Handles hash collisions efficiently

---

## 🔎 Important Functions

### `in_hash_table()`

Checks if a word exists in hash table

### `identify_compound_words()`

Splits words and checks if compound

### `read_line()`

Reads dynamic input line

---

## ⚙️ Hash Table Details

```c
#define NUM_BITS 17
```

* Hash size = **2¹⁷ = 131072**
* Efficient lookup
* Good distribution

---

## 🚀 Time Complexity

| Operation       | Complexity         |
| --------------- | ------------------ |
| Insert          | O(1) average       |
| Lookup          | O(1) average       |
| Splitting words | O(n × word_length) |
| Overall         | **O(n)** average   |

---

## 💾 Memory Usage

* Words array
* Hash table
* Linked list nodes

Efficient for **120,000 words**

---

## ▶️ Compile & Run

### Compile

```bash
gcc compound_words.c -o compound
```

### Run

```bash
./compound < input.txt
```

---

## 🧪 Example

### Input

```text
cat
cats
dog
catsdog
```

### Output

```text
catsdog
```

Explanation:

* **catsdog = cats + dog** ✅

---

## 📚 Algorithm Type

* Hash Tables
* String Processing
* Algorithmic Thinking
* Fast Lookup

---

## 🎯 Why Hash Table?

Without hashing:

* Brute force → **O(n²)** ❌

With hashing:

* Fast lookup → **O(n)** ✅
