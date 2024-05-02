add_library(BitFile BitFile.c)
target_link_libraries(BitFile PRIVATE util_compiler_flags)
target_include_directories(BitFile INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
