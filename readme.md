# CSI2372 — Week 5 Lab Handout

**Topics:** Exception Safety • Error Handling • Templates • Decltype • Modular Design
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---

## 1. Overview

In this lab you will practice advanced C++ design patterns involving error handling, template programming, and modular components.
The lab consists of four graded tasks:

* **Document/Library System** – implement a small document management system.
* **Logger** – design an extensible logging framework.
* **Matrix** – implement a generic 2D matrix that uses `decltype` for type deduction.
* **SafeArray** – explore exception safety guarantees and mixed error-handling strategies.

All work is autograded via CI/CTest. When the GitHub Actions build is green, you earn full marks.

---

## 2. Learning Objectives

By the end of this lab, you should be able to:

* Design modular C++ code with headers, sources, and CMake.
* Implement exception-based vs status-code-based error handling.
* Apply exception safety guarantees (basic, strong, noexcept) in small container designs.
* Use templates and `decltype` to deduce correct result types in arithmetic expressions.
* Practice RAII and clean resource management through small systems.

---

## 3. Task A – Document/Library

You are given `Document.hpp` and `Library.hpp` with partial implementations.
Complete the system so that:

* Documents can be created with a name and content.
* Libraries can add, remove, and list documents.
* Methods return the expected results with const-correctness.
* All tests in `Document_Library_tests.cpp` pass.

---

## 4. Task B – Logger

You are given `Logger.hpp` and `Logfile.hpp`.
Complete the implementation so that:

* Logger supports multiple log levels (info, warning, error).
* Messages can be dispatched to one or more `LogFile` objects.
* Log files append correctly and can be rotated or cleared.
* All tests in `Logger_tests.cpp` pass.

---

## 5. Task C – Matrix with Decltype

You are given `Matrix.hpp` and `Matrix.cpp`.
Implement a generic `Matrix<T>` so that:

* Construction, element access, and printing behave correctly.
* Addition of two matrices deduces the correct result type using `decltype(a+b)`.

  * Example: `Matrix<int> + Matrix<double> → Matrix<double>`.
* All tests in `Matrix_tests.cpp` pass.

---

## 6. Task D – SafeArray with Error Handling

You are given `SafeArray.hpp` and `SafeArray.cpp`.
Implement a small container that:

* Provides exception-based access (`at_exception`) and status-code-based access (`at_status`).
* Ensures `push_back` has the **strong guarantee**.
* Marks destructor as `noexcept`.
* Returns correct error codes for out-of-bounds operations.
* All tests in `SafeArray_tests.cpp` pass.

---

## 7. Building and Running

Recommended portable workflow:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

CI runs on GitHub automatically when you push.

---

## 8. Grading

100% autograded: Passing all provided tests yields full marks.
No manual grading.


















# CSI2372 — Week 5 Lab Handout

**Topics:** Exception Safety • Error Handling • Templates • Decltype • Modular Design
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---

## 1. Overview

In this lab you will practice advanced C++ design patterns involving error handling, template programming, and modular components.
The lab consists of four graded tasks:

* **Document/Library System** – implement a small document management system.
* **Logger** – design an extensible logging framework.
* **Matrix** – implement a generic 2D matrix that uses `decltype` for type deduction.
* **SafeArray** – explore exception safety guarantees and mixed error-handling strategies.

All work is autograded via CI/CTest. When the GitHub Actions build is green, you earn full marks.

---

## 2. Learning Objectives

By the end of this lab, you should be able to:

* Design modular C++ code with headers, sources, and CMake.
* Implement exception-based vs status-code-based error handling.
* Apply exception safety guarantees (basic, strong, noexcept) in small container designs.
* Use templates and `decltype` to deduce correct result types in arithmetic expressions.
* Practice RAII and clean resource management through small systems.

---

## 3. Task A – Document/Library

You are given `Document.hpp` and `Library.hpp` with partial implementations.
Complete the system so that:

* Class **Document**:

  * Constructor takes a title and content.
  * Methods `getTitle()` and `getContent()` return the stored values.
* Class **Library**:

  * `addDocument(const Document&)` adds a new document.
  * `removeDocument(const std::string&)` removes by title.
  * `findDocument(const std::string&)` returns a pointer or reference to the document.
  * `listTitles()` returns a vector of all titles.
* Ensure all methods are const-correct and behave safely.
* All tests in `Document_Library_tests.cpp` must pass.

---

## 4. Task B – Logger

You are given `Logger.hpp` and `Logfile.hpp`.
Implement the logging framework so that:

* **LogFile**:

  * Constructor opens/creates a file.
  * `write(const std::string&)` appends a line to the file.
  * `clear()` removes contents.
* **Logger**:

  * Supports different log levels (`info`, `warning`, `error`).
  * `addLogFile(LogFile*)` attaches a log file to receive messages.
  * `log(LogLevel, const std::string&)` dispatches the formatted message to all attached log files.
* All tests in `Logger_tests.cpp` must pass.

---

## 5. Task C – Matrix with Decltype

You are given `Matrix.hpp` and `Matrix.cpp`.
Implement the template class `Matrix<T>` so that:

* Constructor `Matrix(rows, cols, defaultValue)` initializes all cells.
* `operator()(r, c)` returns element references (const and non-const overloads).
* `rowCount()` and `colCount()` return dimensions.
* `operator+` adds two matrices of possibly different element types. Use:

  ```cpp
  decltype(std::declval<T>() + std::declval<U>())
  ```

  to deduce the correct result element type.
* `print()` prints the matrix row by row.
* All tests in `Matrix_tests.cpp` must pass.

---

## 6. Task D – SafeArray with Error Handling

You are given `SafeArray.hpp` and `SafeArray.cpp`.
Implement a wrapper over `std::vector<T>` that:

* `push_back(const T&)` inserts a value (vector ensures strong exception guarantee).
* `at_exception(size_t)` throws `std::out_of_range` on invalid index.
* `at_status(size_t, T&)` copies the value to output and returns `ErrorCode::SUCCESS`, or returns `ErrorCode::OUT_OF_BOUNDS` if invalid.
* `size()` returns the number of elements, marked `noexcept`.
* Destructor is explicitly declared `noexcept`.
* All tests in `SafeArray_tests.cpp` must pass.

---

## 7. Building and Running

Recommended portable workflow:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

CI runs on GitHub automatically when you push.

---

## 8. Grading

100% autograded: Passing all provided tests yields full marks.
No manual grading.
