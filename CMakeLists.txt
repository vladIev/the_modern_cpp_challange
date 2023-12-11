cmake_minimum_required(VERSION 3.20)
project(hello VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include CTest-specific macros and functions
include(CTest)
include("${CMAKE_SOURCE_DIR}/cmake/cmake_utils.cmake")
enable_testing()

find_package(GTest REQUIRED)
find_package(fmt REQUIRED)
find_package(Boost REQUIRED asio)
include_directories(${Boost_INCLUDE_DIR})
include_directories(${fmt_INCLUDE_DIRS})
include_directories(${GTest_INCLUDE_DIRS})


set(LIBS_PATH "${CMAKE_SOURCE_DIR}/libs")

include_directories(${CMAKE_SOURCE_DIR}/src/utils)

add_subdirectory("${CMAKE_SOURCE_DIR}/libs/ZipLib")

add_subdirectory("${CMAKE_SOURCE_DIR}/src/math_problems")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/language_features")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/strings_and_regexps")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/streams_and_filesystem")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/date_and_time")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/algorithms_and_data_structures")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/concurrency")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/design_patterns")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/data_serialization")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/archives_images_databases")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/cryptography")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/networking_and_services")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
