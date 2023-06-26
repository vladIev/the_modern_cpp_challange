cmake_minimum_required(VERSION 3.20)
project(79_finding_file_in_a_zip_archive VERSION 0.1.0)

add_main_files(ZipLib)
add_test_files(ZipLib)

add_custom_command(OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/task79.zip
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${CMAKE_SOURCE_DIR}/data/chapter_9/task79.zip ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/task79.zip
                   COMMENT "Copying task79.zip to output directory")
add_custom_target(copy_files ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/task79.zip
)