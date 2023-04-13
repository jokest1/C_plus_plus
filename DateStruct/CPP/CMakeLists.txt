cmake_minimum_required(VERSION 3.22)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP Test/List.h Test/List1.h algorithm/sort/Sort.h Test/List2.h Test/List3.h Test/vector.h algorithm/sort/Test.cpp algorithm/sort/TestSortPool.cpp algorithm/sort/TestSortPool.h)
