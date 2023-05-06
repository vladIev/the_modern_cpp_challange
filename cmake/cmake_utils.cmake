function(add_main_files)
    file(GLOB MAIN_FILES "*.m.cpp")
    file(GLOB CPP_FILES "*.cpp")
    # Exclude files with postfix ".m.cpp" or ".g.cpp"
    list(FILTER CPP_FILES EXCLUDE REGEX "\\.m\\.cpp$|\\.g\\.cpp$")

    foreach(MAIN_FILE ${MAIN_FILES})
        message("Found main file: ${MAIN_FILE}")
        
        get_filename_component(MAIN_NAME ${MAIN_FILE} NAME_WE)
        add_executable(${MAIN_NAME} ${MAIN_FILE} ${CPP_FILES})
    endforeach()
endfunction(add_main_files)

function(add_test_files)
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
        target_link_libraries(${TEST_TARGET} GTest::gtest_main)

        # Register this test with CTest
        add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET})
    endforeach()
endfunction(add_test_files)
