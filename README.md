# Course Prerequisite Checker System

## Project Overview

The Course Prerequisite Checker System is a C-based program designed to help students verify whether they meet the prerequisites for specific courses. The system stores course relationships and minimum grade requirements, allows users to manage their academic profile, and recursively checks prerequisite chains using graph traversal concepts.

This project demonstrates the use of important data structures and algorithms such as:

* Arrays
* Structs
* Linked Lists
* Graph concepts
* Depth First Search (DFS)
* Recursion
* Dynamic Memory Allocation

---

## Features

* Add and manage completed courses with grades
* Store prerequisite relationships between courses
* Check whether prerequisite requirements are satisfied
* Display prerequisite chains recursively
* Prevent repeated traversal using a visited array

---

## How to Compile and Run

### Compile

Using GCC:

```bash
gcc main.c -o prerequisite_checker
```

### Run

```bash
./prerequisite_checker
```

For Windows:

```bash
prerequisite_checker.exe
```

---

## How to Use

1. Run the program.
2. Choose **Manage Profile** to add completed courses and grades.
3. Return to the main menu.
4. Select **Check Prerequisites**.
5. Enter a course name.
6. The system will display all prerequisites and indicate whether each requirement has been satisfied.

Example:

```text
Prerequisites for CPE112:
- CPE100 (MIN GRADE: C) ✅
```

---

## Concepts Used

* Linked Lists for storing prerequisite relationships
* DFS recursion for traversing prerequisite chains
* Arrays for course and profile storage
* Dynamic memory allocation using malloc()

---

## Future Improvements

* GUI or web-based interface
* Database/file storage support
* Automatic eligible course recommendations
* Circular prerequisite detection
* Better graph visualization


Commit Hash: b70460d
