cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_MAKE_PROGRAM mingw32-make)
set(CMAKE_CXX_COMPILER c++)
set(CMAKE_MAKE_PROGRAM "/c/msys64/mingw64/bin/mingw32-make")

project(hw_cmake VERSION 1.0.0 LANGUAGES CXX)

add_executable(HelloWorld helloworld.cpp)

include(CTest)
enable_testing()

