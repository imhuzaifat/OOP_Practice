# C++ Practice & Coursework

A collection of C++ programming exercises and implementations focused on **core C++ concepts, memory management, Object-Oriented Programming (OOP), and algorithms**.

---

## Concepts Covered

* Pointers & Reference Variables
* Dynamic Memory Management
* Classes & Encapsulation
* Constructors & Destructors
* Copy Constructors & Deep Copying
* Operator Overloading
* Inheritance
* Polymorphism & Virtual Functions

---

## Topics

### Topic 1: Pointers & Reference Variables

* **File:** [`topic1_pointers.cpp`](topic1_pointers.cpp)
* **Requirements:**

  1. Implement custom array manipulation using a reference to modify the maximum element directly in dynamic memory.

---

### Topic 2: Dynamic Memory Management

* **File:** [`topic2_dynamic_memory.cpp`](topic2_dynamic_memory.cpp)
* **Requirements:**

  1. Write helper functions to allocate (`createMatrix`) and deallocate (`freeMatrix`) a 2D dynamic array.
  2. Implement `transposeMatrix(int** matrix, int rows, int cols)` to allocate and populate a transposed `C × R` grid.
  3. Manage heap memory cleanly without memory leaks or dangling pointers.

---

### Topic 3: Classes, Objects, & Access Modifiers

* **File:** [`topic3_classes.cpp`](topic3_classes.cpp)
* **Requirements:**

  1. Define a `Student` class with `private` attributes (`name`, `rollNumber`, `gpa`).
  2. Implement getter and setter methods with data validation, restricting `gpa` between `0.0` and `4.0`.
  3. Include utility methods `displayInfo()` and `isHonorStudent()`.
  4. Instantiate multiple objects in `main()` to demonstrate encapsulation and accessor safety.

---

### Topic 4: Constructors & Destructors

* **File:** [`topic4_constructors.cpp`](topic4_constructors.cpp)
* **Requirements:**

  1. Implement a `Matrix` class managing 2D dynamic memory following the RAII pattern.
  2. Use a parameterized constructor with member initializer lists for memory allocation.
  3. Implement a destructor (`~Matrix()`) to eliminate memory leaks upon object destruction.
  4. Provide boundary-checked methods `setElement` and `getElement`.

---

### Topic 5: Copy Constructors & Deep Copying

* **File:** [`topic5_copy_constructor.cpp`](topic5_copy_constructor.cpp)
* **Requirements:**

  1. Understand shallow vs. deep copying and the Rule of Three.
  2. Implement a custom copy constructor `Matrix(const Matrix& other)` using pass-by-const-reference.
  3. Ensure independent heap memory allocations to prevent double-free crashes and unintended side effects.

---

### Topic 6: Operator Overloading

* **File:** [`topic6_operator_overloading.cpp`](topic6_operator_overloading.cpp)
* **Requirements:**

  1. Overload binary `operator+` for matrix addition.
  2. Overload comparison `operator==` for deep matrix equality checks.
  3. Implement a `friend` stream insertion `operator<<` for clean output syntax (`cout << mat`).

---

### Topic 7: Inheritance & Protected Access

* **File:** [`topic7_inheritance.cpp`](topic7_inheritance.cpp)
* **Requirements:**

  1. Learn the `protected` access specifier for derived class accessibility.
  2. Implement a `SquareMatrix` child class inheriting from the base `Matrix` class.
  3. Chain constructors using member initializer lists (`SquareMatrix(int size) : Matrix(size, size)`).
  4. Implement domain-specific methods `makeIdentity()` and `getTrace()`.

---

### Topic 8: Polymorphism & Virtual Functions

* **File:** [`topic8_polymorphism.cpp`](topic8_polymorphism.cpp)
* **Requirements:**

  1. Use `virtual` functions to achieve runtime dynamic binding.
  2. Implement virtual destructors to prevent memory leaks when deleting derived objects through base pointers.
  3. Apply the `override` keyword (C++11) for explicit function overriding in derived classes.
  4. Demonstrate heterogeneous collections using base class pointers (`Matrix*[]`).

---

### Topic 9: Abstract Classes & Pure Virtual Functions
* **File:** [`topic9_abstract_classes.cpp`](topic9_abstract_classes.cpp)
* **Requirements:**
  1. Define pure virtual functions using `= 0` syntax to form abstract interfaces.
  2. Implement interface contracts in derived concrete classes.
  3. Understand compile-time instantiation restrictions on abstract base classes.

---

## How to Compile and Run

To compile and run any topic using `g++`:

```bash
g++ filename.cpp
.\a.exe
```