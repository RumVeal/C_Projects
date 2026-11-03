Educational projects written in C.
The repository is divided into **Mini_Projects** (small, single-file programs) and **Big_Projects** (larger applications to be added later).

---

## 📂 Structure
- **Mini_Projects/**
  - **Binary_Conversion_Addition_Subtraction** — program for binary conversion, addition, and subtraction.
  - **Addition_30_Digit** — program that performs addition of 30-digit numbers.
  - **Lotto** — simple lottery number generator. *(WIP)*
  - **Qsort_Sorting** — sorting numbers using the `qsort` function. *(WIP)*
  - **TicTacToe** — console implementation of the Tic Tac Toe game. *(WIP)*

- **Big_Projects/**
  - (to be added later)

---

## ▶️ Build & run
Each mini project is a single file:
```bash
cd Mini_Projects/Addition_30_Digit
gcc -Wall -o main main.c
./main
```
Lotto and TicTacToe use `termios.h`, so they run on macOS / Linux.

---
