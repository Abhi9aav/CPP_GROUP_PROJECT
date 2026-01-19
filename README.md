# Student Management System (C++)

A modular, console-based Student Management System built using C++ and Object-Oriented Programming principles.

# Features
- Add, remove, update students and faculty
- Search by ID and case-insensitive name search
- Persistent storage using file handling
- Input validation and error handling
- Clean modular architecture
- Custom template-based list container
- Menu-driven interface

# Technologies Used
- C++
- STL (vector, algorithm)
- File I/O
- CMake
- Git & GitHub

# Project Structure
- `StudentModule` – student CRUD + search
- `FacultyModule` – faculty CRUD + search
- `DatabaseModule` – simulated database connection
- `ListTemplate` – reusable template container
- `MainProject` – system controller

# How to Build & Run
```bash
mkdir build
cd build
cmake ..
cmake --build .
sms.exe
