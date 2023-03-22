cmake_minimum_required(VERSION 3.10)

project(petracalltest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(petracalltest SHARED
    PetraRowRef.cpp
    PetraAPILCallTest.cpp
)

target_include_directories(petracalltest
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.
)

