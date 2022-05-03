cmake_minimum_required(VERSION 3.16.3)
project(DTS)

set(CMAKE_CXX_STANDARD 20)

include_directories("../DTSLib"
                    "${CMAKE_SOURCE_DIR}/")

find_package(Catch2 3 REQUIRED)

set(TEST_SOURCE
        TestVector.cpp)

set(SOURCE_HEADERS
        ../DTSLib/Vector.h)

add_executable(DTSTests
        ${TEST_SOURCE}
        ${SOURCE_HEADERS})

target_link_libraries(DTSTests PRIVATE Catch2::Catch2WithMain)
