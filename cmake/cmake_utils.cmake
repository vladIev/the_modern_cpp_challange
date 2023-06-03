function(add_dirs_as_subdirs)
    # Get a list of all subdirectories in the directory containing the CMakeLists.txt file
    FILE(GLOB CHILD_DIRS ${CMAKE_CURRENT_LIST_DIR}/*)
    # Loop through each subdirectory and add it as a subdirectory of the current project
    foreach(SUBDIR ${CHILD_DIRS})
        if(IS_DIRECTORY ${SUBDIR})
            message("Found directory ${SUBDIR}")
            add_subdirectory(${SUBDIR})
        endif()
    endforeach()
endfunction()

function(add_main_files)
    # Parse function arguments
    set(LIBRARIES ${ARGN} GTest::gtest_main)
    file(GLOB MAIN_FILES "*.m.cpp")
    file(GLOB CPP_FILES "*.cpp")
    # Exclude files with postfix ".m.cpp" or ".g.cpp"
    list(FILTER CPP_FILES EXCLUDE REGEX "\\.m\\.cpp$|\\.g\\.cpp$")

    foreach(MAIN_FILE ${MAIN_FILES})
        message("Found main file: ${MAIN_FILE}")
        
        get_filename_component(MAIN_NAME ${MAIN_FILE} NAME_WE)
        add_executable(${MAIN_NAME} ${MAIN_FILE} ${CPP_FILES})

        if(NOT "${LIBRARIES}" STREQUAL "")
            target_link_libraries(${MAIN_NAME} ${LIBRARIES})
        endif()
    endforeach()
endfunction(add_main_files)

function(add_test_files)
    # Parse function arguments
    set(LIBRARIES ${ARGN} GTest::gtest_main)
    # Find all test files in the directory
    file(GLOB TEST_FILES "*.g.cpp")
    file(GLOB CPP_FILES "*.cpp")
    # Exclude files with postfix ".m.cpp" or ".g.cpp"
    list(FILTER CPP_FILES EXCLUDE REGEX "\\.m\\.cpp$|\\.g\\.cpp$")
    # Create a test target for each test file
    foreach(TEST_FILE ${TEST_FILES})
        # Extract the test name from the file name
        message("Found gtest file: ${TEST_FILE}")
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        set(TEST_TARGET "${TEST_NAME}.g")

        # Create a test target for this file
        add_executable(${TEST_TARGET} ${TEST_FILE}  ${CPP_FILES})
        target_link_libraries(${TEST_TARGET} ${LIBRARIES})

        # Register this test with CTest
        add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET})
    endforeach()
endfunction(add_test_files)
