cmake_minimum_required(VERSION 3.2.0)
project(hello VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include CTest-specific macros and functions
include(CTest)
include("${CMAKE_SOURCE_DIR}/cmake/cmake_utils.cmake")
enable_testing()

find_package(gtest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/utils)


add_subdirectory("${CMAKE_SOURCE_DIR}/src/math_problems")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/language_features")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/strings_and_regexps")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/streams_and_filesystem")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/date_and_time")



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
