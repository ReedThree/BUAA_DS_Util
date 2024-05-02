add_executable(testBitFile testBitFile.c)
target_link_libraries(testBitFile PRIVATE asan ubsan util_compiler_flags BitFile)

add_test(NAME testBitFile COMMAND bash -c "${CMAKE_CURRENT_SOURCE_DIR}/outputCompare.sh ${CMAKE_CURRENT_BINARY_DIR}/testBitFile X ${CMAKE_CURRENT_SOURCE_DIR}/testBitFile.out")
add_test(NAME testBitFileWrite5Bits COMMAND bash -c "diff ${CMAKE_CURRENT_BINARY_DIR}/write_5bits.bin ${CMAKE_CURRENT_SOURCE_DIR}/write_5bits.bin")
add_test(NAME testBitFileWrite17Bits COMMAND bash -c "diff ${CMAKE_CURRENT_BINARY_DIR}/write_17bits.bin ${CMAKE_CURRENT_SOURCE_DIR}/write_17bits.bin")
add_test(NAME testBitFileWrite17itsSeek5Bits COMMAND bash -c "diff ${CMAKE_CURRENT_BINARY_DIR}/write_17bits_seek_5bits.bin ${CMAKE_CURRENT_SOURCE_DIR}/write_17bits_seek_5bits.bin")
add_test(NAME testBitFileWriteTwice5Bits COMMAND bash -c "diff ${CMAKE_CURRENT_BINARY_DIR}/write_twice_5bits.bin ${CMAKE_CURRENT_SOURCE_DIR}/write_twice_5bits.bin")
