# SysProg2_Ex4
# **MyContainer Project**

## **Overview**
This project implements a C++ template class called **MyContainer** that represents a dynamic container for comparable objects. The container supports dynamic addition and removal of elements and provides six different iterator types for traversing elements in different orders. The class includes iterators for ascending order, descending order, side-cross order, reverse order, insertion order, and middle-out order traversal.

## **Requirements**
Before running the project, ensure that your system has the following tools:
* C++11 or later
* g++ (C++ compiler)
* Valgrind (for memory leak detection)
* doctest framework (included in project)

## **File Structure**
The project is divided into several files:

### Main Header Files:
* **MyContainer.h** – Header file containing the main `MyContainer` class definition and all basic operations
* **OrderIterator.h** – Iterator for regular order traversal (insertion order)
* **AscendingOrderIterator.h** – Iterator for ascending order traversal
* **DescendingOrder.h** – Iterator for descending order traversal
* **SideCrossOrderIterator.h** – Iterator for side-cross traversal
* **ReverseOrderIterator.h** – Iterator for reverse order traversal
* **MiddleOutOrderIterator.h** – Iterator for middle-out traversal

### Demo and Test Files:
* **main.cpp** – Demonstration file showcasing usage of all iterator types
* **test_MyContainer.cpp** – Unit tests for the main container class
* **test_OrderIteratorTests.cpp** – Tests for regular order iterator
* **test_AscendingOrderIterator.cpp** – Tests for ascending order iterator
* **test_DescendingOrder.cpp** – Tests for descending order iterator
* **test_SideCrossOrderIterator.cpp** – Tests for side-cross iterator
* **test_ReverseOrderIterator.cpp** – Tests for reverse order iterator
* **test_MiddleOutOrderIterator.cpp** – Tests for middle-out iterator

### Utility Files:
* **Makefile** – Makefile for compilation, running tests, and memory leak detection

## **Running the Project**
After downloading all the files, run the following commands in your terminal:

1. **Build and run demonstration**: `make Main`
2. **Run unit tests**: `make test`
3. **Check for memory leaks**: `make valgrind`
4. **Clean up**: `make clean`

## **Function Explanations**

### **Container Basic Operations:**
* **MyContainer()** - Creates an empty container (default constructor)
* **void add(const T& item)** - Adds an element to the container
* **void remove(const T& item)** - Removes all instances of an element from the container (throws exception if element not found)
* **int size() const** - Returns the number of elements in the container
* **operator<<** - Stream output operator for printing the container in format [element1, element2, ...]

### **Iterator Types:**
* **OrderIterator** - Traverses elements in original insertion order
* **AscendingOrderIterator** - Traverses elements in ascending order (smallest to largest)
* **DescendingOrder** - Traverses elements in descending order (largest to smallest)
* **SideCrossOrderIterator** - Alternates between smallest and largest remaining elements from sorted order
* **ReverseOrderIterator** - Traverses elements in reverse insertion order
* **MiddleOutOrderIterator** - Starts from middle element, then alternates left-right from original order

### **Iterator Access Methods:**
* **begin_order() / end_order()** - Returns begin/end iterators for regular order traversal
* **begin_ascebding() / end_ascebding()** - Returns begin/end iterators for ascending traversal
* **begin_descending() / end_descending()** - Returns begin/end iterators for descending traversal
* **begin_sideCross() / end_sideCross()** - Returns begin/end iterators for side-cross traversal
* **begin_revers() / end_revers()** - Returns begin/end iterators for reverse traversal
* **begin_middle() / end_middle()** - Returns begin/end iterators for middle-out traversal

## **Iterator Behavior Examples**
For container `[7, 15, 6, 1, 2]` the traversal orders will be:

* **OrderIterator**: 7, 15, 6, 1, 2
* **AscendingOrderIterator**: 1, 2, 6, 7, 15
* **DescendingOrder**: 15, 7, 6, 2, 1
* **SideCrossOrderIterator**: 1, 15, 2, 7, 6
* **ReverseOrderIterator**: 2, 1, 6, 15, 7
* **MiddleOutOrderIterator**: 6, 15, 1, 7, 2

## **Namespace**
All classes are defined within the `MyNamespace` namespace.

## **Additional Features**
- Support for all comparable data types
- Default template parameter set to `int`
- Error checking and appropriate exception throwing
- Full support for standard iterator operators
- Efficient implementation of all traversal types

## **Contact**
* Email: [avigezerhalel@gmail.com]
* Name: Halel Avigezer
