cmake_minimum_required(VERSION 3.2.0)
project(math_problems VERSION 0.1.0)

find_package(gtest REQUIRED)

add_executable(task1 task1.cpp)
add_executable(task2_gcd task2_gcd.cpp)
add_executable(task3_lcm task3_lcm.cpp)
add_executable(task4 task4.cpp)
add_executable(task5 task5_sexy_primes.cpp)


# Find all test files in the directory
file(GLOB TEST_FILES "*.g.cpp")
# Create a test target for each test file
foreach(TEST_FILE ${TEST_FILES})
  # Extract the test name from the file name
  message("Found gtest file: ${TEST_FILE}")
  get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
  set(TEST_TARGET "${TEST_NAME}.g")

  # Create a test target for this file
  add_executable(${TEST_TARGET} ${TEST_FILE})
  target_link_libraries(${TEST_TARGET} GTest::gtest_main)

  # Register this test with CTest
  add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET})
endforeach()




