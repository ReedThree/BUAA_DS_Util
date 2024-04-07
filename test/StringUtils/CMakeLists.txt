add_executable(testStringUtils testStringUtils.c)
target_link_libraries(testStringUtils PRIVATE asan ubsan util_compiler_flags StringUtils)

add_test(NAME testStringUtils COMMAND bash -c "${CMAKE_CURRENT_SOURCE_DIR}/outputCompare.sh ${CMAKE_CURRENT_BINARY_DIR}/testStringUtils X ${CMAKE_CURRENT_SOURCE_DIR}/StringUtils.out")
