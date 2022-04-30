cmake_minimum_required(VERSION 3.16.3)
project(DTS)

set(CMAKE_CXX_STANDARD 17)

include_directories(DTSLib)

add_executable(DTS
        DTSLib/TestVector.cpp
        DTSLib/Vector.h)