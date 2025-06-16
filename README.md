# Student Management System in C++

This project is a **console-based Student Management System** built using **C++**. It covers essential operations like student admission, course registration, and result management using **linked lists**, **queues**, and **binary search trees**.

## 📚 Features

### 🎓 1. Admission System
- Uses a **doubly linked list**.
- Adds new students with their IDs.
- Removes a student by ID.
- Displays the student list in both forward and backward directions.

### 📑 2. Course Registration System
- Uses a **queue** to manage course registration (FIFO).
- Registers students for specific courses.
- Supports dequeuing (removing the front student once processed).
- Displays the full registration queue.

### 🧠 3. Result Management System
- Uses a **Binary Search Tree (BST)**.
- Inserts students' exam results (ID and marks).
- Displays results using **inorder traversal** (sorted by student ID).

## 🛠️ Technologies Used
- C++
- Object-Oriented Programming (OOP)
- Data Structures:
  - Doubly Linked List
  - Queue
  - Binary Search Tree (BST)

## 🔍 Code Structure

- `class admission`: Handles student admissions using a doubly linked list.
- `class registration`: Manages course registrations using a queue.
- `class resultManagement`: Manages exam results using a binary search tree.

## ▶️ How to Run

1. Copy the source code to a `.cpp` file, for example `main.cpp`.
2. Compile and run using a C++ compiler:
   ```bash
   g++ -o student_system main.cpp
   ./student_system
## 🧪 Sample Output
-student added : 11

#student added : 14

-student added : 15

-student added : 16

-student added : 13

-student removed : 15
-student removed : 16

-student list (forward) :
-11 -> 14 -> 13 ->

-student list (backward) :
-13 -> 14 -> 11 ->

-course registered : 11 - 222
-course registered : 14 - 822
-course registered : 15 - 272
-course registered : 13 - 202
-dequeue : 11 - 222

-course registration queue :
-14 - 822 -> 15 - 272 -> 13 - 202 ->

 exam record inserted : 11
marks: 85
 exam record inserted : 14
marks: 89
 exam record inserted : 15
marks: 55
 exam record inserted : 12
marks: 80
 exam record inserted : 13
marks: 75

Exam result (inorder):
ID: 11 | Result: 85
ID: 12 | Result: 80
ID: 13 | Result: 75
ID: 14 | Result: 89
ID: 15 | Result: 55
