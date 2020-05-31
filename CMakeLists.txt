cmake_minimum_required(VERSION 3.15)
project(lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(lib main.cpp Book.cpp Book.h Library.cpp Library.h User.cpp User.h Client.cpp Client.h Administrator.cpp Administrator.h)