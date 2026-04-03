# Knight Chase Problem - BFS

## 📌 Problem Overview

This problem simulates a board game between **two players**:

* **Pawn**
* **Knight**

The objective is to determine the **best possible outcome for the Knight**:

* **Win**
* **Stalemate**
* **Loss**

Along with the **minimum number of knight moves** required to achieve that outcome.

---

## 🎯 Game Rules

### Board

* The board has **r rows** and **c columns**
* Rows are numbered from **1 (bottom)** to **r (top)**
* Columns are numbered from **1 (left)** to **c (right)**

---

## ♟️ Player Movement Rules

### Pawn Movement

* The pawn **always moves first**
* Pawn **moves up exactly one square** per turn
* Pawn **has no choice** in movement

Example:

```
(row, col) → (row + 1, col)
```

---

### Knight Movement

The knight can move in **8 possible directions**:

* Up 1, Right 2
* Up 1, Left 2
* Down 1, Right 2
* Down 1, Left 2
* Up 2, Right 1
* Up 2, Left 1
* Down 2, Right 1
* Down 2, Left 1

⚠️ Moves that go **outside the board** are **not allowed**.

---

## 🏁 Game Ending Conditions

The game ends in **three possible outcomes**:

### 🥇 Win

The knight **wins** if:

* Knight lands on the **same square** as pawn
* Knight must make the move
* Pawn must **not** reach top row before capture

Output Format:

```
Win in m knight move(s).
```

---

### 🤝 Stalemate

The game is a **stalemate** if:

* Knight lands **one square above** pawn
* Knight must make the move
* Pawn must not reach the top row

Output Format:

```
Stalemate in m knight move(s).
```

---

### ❌ Loss

Knight **loses** if:

* Pawn reaches the **top row**
* Knight neither wins nor stalemates before that

Output Format:

```
Loss in m knight move(s).
```

---

## 📥 Input Format

```
T
r
c
pawn_row
pawn_col
knight_row
knight_col
```

Where:

| Parameter  | Description                |
| ---------- | -------------------------- |
| T          | Number of test cases       |
| r          | Number of rows (3 - 99)    |
| c          | Number of columns (2 - 99) |
| pawn_row   | Pawn starting row          |
| pawn_col   | Pawn starting column       |
| knight_row | Knight starting row        |
| knight_col | Knight starting column     |

Constraints:

* Pawn and knight **start at different positions**
* Knight **always has at least one valid move**

---

## 📤 Output Format

For each test case output one line:

```
Win in m knight move(s).
```

OR

```
Stalemate in m knight move(s).
```

OR

```
Loss in m knight move(s).
```

---

## 🧠 Approach

### Algorithm Used

The solution uses:

* **Breadth First Search (BFS)**
* **Simulation of pawn movement**
* **Distance calculation for knight**

---

### Key Steps

1. Pawn moves upward each turn
2. For each pawn position:

   * Calculate knight shortest distance using **BFS**
3. Check:

   * If knight can capture pawn → **Win**
   * If knight can reach square above pawn → **Stalemate**
4. If neither possible → **Loss**

---

## 🧩 Time Complexity

* BFS per move: **O(R × C)**
* Total complexity: **O(T × R × C)**

Where:

* **T** = Test cases
* **R** = Rows
* **C** = Columns

---

## 🛠️ Implementation Details

### Key Functions

#### `find_distance()`

* Uses BFS
* Finds shortest knight moves to target square

#### `add_positions()`

* Adds valid knight moves
* Avoids revisiting squares

#### `solve()`

* Simulates pawn movement
* Determines win / stalemate / loss

---

## 🚀 Features

* Efficient BFS solution
* Handles multiple test cases
* Supports large boards (99x99)
* Minimal knight moves calculation
