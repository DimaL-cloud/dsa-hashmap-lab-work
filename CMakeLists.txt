cmake_minimum_required(VERSION 3.23)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS main.h SeparateChainingHashMap.h OpenAddressingHashMap.h LinkedList.h Minister.h)

set(PROJECT_SOURCES main.cpp SeparateChainingHashMap.cpp OpenAddressingHashMap.cpp Minister.cpp LinkedList.cpp)

add_executable(HashMapTask main.cpp SeparateChainingHashMap.cpp OpenAddressingHashMap.cpp Minister.cpp LinkedList.cpp)

add_executable(rabinKarpAlgorithmTask rabinKarpAlgorithm.cpp)