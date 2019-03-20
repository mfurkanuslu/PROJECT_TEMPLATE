cmake_minimum_required(VERSION 3.9.2)

project(PROJECT_NAME)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(src)

#option(BUILD_DOC "Build documentation" OFF)
#if(BUILD_DOC)
#    add_subdirectory(doc)
#endif()

option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    set(BUILD_TESTING ON)
endif()

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()
