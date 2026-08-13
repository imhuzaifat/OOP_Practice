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
* Abstract Classes & Pure Virtual Functions
* Templates & Generic Programming
* Exception Handling & Custom Exceptions
* Multi-File Project Structuring & Header Guards

---

## Topics

### Topic 1: Pointers & Reference Variables

* **File:** [`topic001_pointers.cpp`](topic001_pointers.cpp)
* **Requirements:**

  1. Implement custom array manipulation using a reference to modify the maximum element directly in dynamic memory.

---

### Topic 2: Dynamic Memory Management

* **File:** [`topic002_dynamic_memory.cpp`](topic002_dynamic_memory.cpp)
* **Requirements:**

  1. Write helper functions to allocate (`createMatrix`) and deallocate (`freeMatrix`) a 2D dynamic array.
  2. Implement `transposeMatrix(int** matrix, int rows, int cols)` to allocate and populate a transposed `C × R` grid.
  3. Manage heap memory cleanly without memory leaks or dangling pointers.

---

### Topic 3: Classes, Objects, & Access Modifiers

* **File:** [`topic003_classes.cpp`](topic003_classes.cpp)
* **Requirements:**

  1. Define a `Student` class with `private` attributes (`name`, `rollNumber`, `gpa`).
  2. Implement getter and setter methods with data validation, restricting `gpa` between `0.0` and `4.0`.
  3. Include utility methods `displayInfo()` and `isHonorStudent()`.
  4. Instantiate multiple objects in `main()` to demonstrate encapsulation and accessor safety.

---

### Topic 4: Constructors & Destructors

* **File:** [`topic004_constructors.cpp`](topic004_constructors.cpp)
* **Requirements:**

  1. Implement a `Matrix` class managing 2D dynamic memory following the RAII pattern.
  2. Use a parameterized constructor with member initializer lists for memory allocation.
  3. Implement a destructor (`~Matrix()`) to eliminate memory leaks upon object destruction.
  4. Provide boundary-checked methods `setElement` and `getElement`.

---

### Topic 5: Copy Constructors & Deep Copying

* **File:** [`topic005_copy_constructor.cpp`](topic005_copy_constructor.cpp)
* **Requirements:**

  1. Understand shallow vs. deep copying and the Rule of Three.
  2. Implement a custom copy constructor `Matrix(const Matrix& other)` using pass-by-const-reference.
  3. Ensure independent heap memory allocations to prevent double-free crashes and unintended side effects.

---

### Topic 6: Operator Overloading

* **File:** [`topic006_operator_overloading.cpp`](topic006_operator_overloading.cpp)
* **Requirements:**

  1. Overload binary `operator+` for matrix addition.
  2. Overload comparison `operator==` for deep matrix equality checks.
  3. Implement a `friend` stream insertion `operator<<` for clean output syntax (`cout << mat`).

---

### Topic 7: Inheritance & Protected Access

* **File:** [`topic007_inheritance.cpp`](topic007_inheritance.cpp)
* **Requirements:**

  1. Learn the `protected` access specifier for derived class accessibility.
  2. Implement a `SquareMatrix` child class inheriting from the base `Matrix` class.
  3. Chain constructors using member initializer lists (`SquareMatrix(int size) : Matrix(size, size)`).
  4. Implement domain-specific methods `makeIdentity()` and `getTrace()`.

---

### Topic 8: Polymorphism & Virtual Functions

* **File:** [`topic008_polymorphism.cpp`](topic008_polymorphism.cpp)
* **Requirements:**

  1. Use `virtual` functions to achieve runtime dynamic binding.
  2. Implement virtual destructors to prevent memory leaks when deleting derived objects through base pointers.
  3. Apply the `override` keyword (C++11) for explicit function overriding in derived classes.
  4. Demonstrate heterogeneous collections using base class pointers (`Matrix*[]`).

---

### Topic 9: Abstract Classes & Pure Virtual Functions
* **File:** [`topic009_abstract_classes.cpp`](topic009_abstract_classes.cpp)
* **Requirements:**
  1. Define pure virtual functions using `= 0` syntax to form abstract interfaces.
  2. Implement interface contracts in derived concrete classes.
  3. Understand compile-time instantiation restrictions on abstract base classes.

---

### Topic 10: Templates & Generic Programming
* **File:** [`topic010_templates.cpp`](topic010_templates.cpp)
* **Requirements:**
  1. Parameterize class structures using `template <typename T>`.
  2. Implement generic memory allocation for custom types (`T** data`).
  3. Instantiate multiple explicit concrete types (`Matrix<int>`, `Matrix<double>`) from a single template blueprint.

---

### Topic 11: Exception Handling & Custom Exceptions
* **File:** [`topic011_exceptions.cpp`](topic011_exceptions.cpp)
* **Requirements:**
  1. Create custom exception classes by deriving from `std::exception`.
  2. Implement defensive programming using `try`, `throw`, and `catch` blocks.
  3. Override `const char* what() const noexcept` for expressive runtime diagnostics.

---

### Topic 12: Multi-File Project Structuring & Header Files
* **Files:** [`Matrix.h`](Matrix.h), [`Matrix.cpp`](Matrix.cpp), [`topic012_multifile.cpp`](topic012_multifile.cpp)
* **Requirements:**
  1. Separate class interface (`Matrix.h`) from implementation (`Matrix.cpp`).
  2. Protect header declarations against redefinition using preprocessor include guards (`#ifndef` / `#define` / `#endif`).
  3. Link multiple translation units during compilation to generate an executable binary.

---

### Topic 13: Standard Template Library (STL) Fundamentals
* **File:** [`topic013_stl.cpp`](topic013_stl.cpp)
* **Requirements:**
  1. Utilize sequence containers (`std::vector`) and utility pairs (`std::pair`).
  2. Implement range-based loops and iterators for container traversal.
  3. Apply generic algorithms (`std::sort`) for array manipulation.

---

## How to Compile and Run

To compile and run single-file programs using `g++`:

```bash
g++ filename.cpp -o app
.\app.exe