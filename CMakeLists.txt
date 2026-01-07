cmake_minimum_required(VERSION 3.20)

project(StudentManagementSystem
    VERSION 1.0
    DESCRIPTION "Modern C++ Student Management System"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sms
    src/Main.cpp
    src/MainProject.cpp
    src/StudentModule.cpp
    src/FacultyModule.cpp
    src/DatabaseModule.cpp
)

target_include_directories(sms PRIVATE ${CMAKE_SOURCE_DIR}/include)
