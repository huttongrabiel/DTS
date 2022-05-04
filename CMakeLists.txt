cmake_minimum_required(VERSION 3.16.3)
project(DTS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++2a -Werror -D CMAKE_CXX_COMPILER=/usr/bin/g++-11")

include_directories(DTSLib)

add_executable(DTS
        DTSLib/Stack.h
        DTSLib/Array.h
        DTSLib/Vector.h)