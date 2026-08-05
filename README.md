# C++ Practice & Coursework

A collection of C++ programming problems and implementations focused on core data structures, memory management, and algorithms.

---

## Problem Sets

### Topic 1: Pointers & Reference Variables
* **File:** `topic1_pointers.cpp`
* **Description:** Implementation of custom array manipulation returning a reference to modify the maximum element directly in dynamic memory.

---

### Topic 2: Dynamic Memory Management
* **File:** `topic2_dynamic_memory.cpp`
* **Requirements:**
  1. Write helper functions to allocate (`createMatrix`) and deallocate (`freeMatrix`) a 2D dynamic array.
  2. Implement `transposeMatrix(int** matrix, int rows, int cols)` to allocate and populate a transposed $C \times R$ grid.
  3. Manage heap memory cleanly without memory leaks or dangling pointers.

---

### Topic 3: Classes, Objects, & Access Modifiers
* **File:** `topic3_classes.cpp`
* **Requirements:**
  1. Define a `Student` class with `private` attributes (`name`, `rollNumber`, `gpa`).
  2. Implement getter and setter methods with data validation (restricting `gpa` between `0.0` and `4.0`).
  3. Include utility methods `displayInfo()` and `isHonorStudent()`.
  4. Instantiate multiple objects in `main()` to demonstrate encapsulation and accessor safety.

---

### Topic 4: Constructors & Destructors
* **File:** `topic4_constructors.cpp`
* **Requirements:**
  1. Implement a `Matrix` class managing 2D dynamic memory following the RAII pattern.
  2. Use a Parameterized Constructor with Member Initializer Lists for memory allocation.
  3. Implement a Destructor (`~Matrix()`) to eliminate memory leaks upon object destruction.
  4. Provide boundary-checked methods `setElement` and `getElement`.

---

### Topic 5: Copy Constructors & Deep Copying
* **File:** `topic5_copy_constructor.cpp`
* **Requirements:**
  1. Understand Shallow vs. Deep copying and the Rule of Three.
  2. Implement a custom Copy Constructor `Matrix(const Matrix& other)` using pass-by-const-reference.
  3. Ensure independent heap memory allocations to prevent double-free crashes and unintended side effects.

---

## How to Compile and Run

To compile and run any problem set using `g++`:

```bash
g++ -o output_file filename.cpp
./output_file
```
