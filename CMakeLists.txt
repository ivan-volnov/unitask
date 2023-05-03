cmake_minimum_required(VERSION 3.24)

project(unitask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(UNI_TEST "Build tests" OFF)

if (UNI_TEST)
    enable_testing()
    add_subdirectory(test)
endif()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/special_id.hpp
)
