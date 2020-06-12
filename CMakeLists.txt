cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_COMPILER $ENV{CC})
set(CMAKE_CXX_COMPILER $ENV{CXX})
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(A SHARED a.cpp)

add_library(B SHARED b.cpp)

add_executable(main "main.cpp")

target_link_libraries(main A B)
