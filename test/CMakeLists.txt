cmake_minimum_required(VERSION 3.24)

project(test_unitask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    main.cpp
    unittest.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE libs
            ../src
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
