# BrainDuck Interpreter

<^B)  
(\_3\_\_)}

BrainDuck is an extension of BrainFuck written to satisfy the requirements of a school project. All BrainFuck code will run in the BrainDuck interpreter.

| Character | Meaning |
| ---- | :--- |
| > | Increment the [data pointer](https://en.wikipedia.org/wiki/Pointer_(computer_programming) "Pointer (computer programming)") by one (to point to the next cell to the right). |
| < | Decrement the data pointer by one (to point to the next cell to the left). |
| + | Increment the byte at the data pointer by one. |
| - | Decrement the byte at the data pointer by one. |
| . | Output the byte at the data pointer as ASCII. |
| , | Accept one byte of input, storing its value in the byte at the data pointer. |
| [ | If the byte at the data pointer is zero, then instead of moving the [instruction pointer](https://en.wikipedia.org/wiki/Program_Counter "Program Counter") forward to the next command, [jump](https://en.wikipedia.org/wiki/Branch_(computer_science) "Branch (computer science)") it _forward_ to the command after the _matching_ `]` command. |
| ] | If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it _back_ to the command after the _matching_ \[. |
| * | Doubles the current byte at the data pointer. |
| / | Halves the current byte at the data pointer. |
| ? | Generates a random number between 0-255 and sets the current byte to it. |



# Issues

If you find an issue please report it inder the Issues tab. Please use the following template to report the issue:

## Bug Report

**Title:** [Short description of the bug]

**Description:**
[Provide a detailed description of the bug. Include steps to reproduce the bug, what you expected to happen, and what actually happened.]

**Version:**
[The git commit id of the software where the bug was encountered]

**Screenshots:**
[If applicable, add screenshots to help explain your problem.]

**Additional context:**
[Add any other context about the problem here.]

**Possible Solution:**
[If you have a suggestion for fixing the bug, include it here.]
