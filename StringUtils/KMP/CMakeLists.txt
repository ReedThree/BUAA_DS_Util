add_library(KMP_Search KMP_Search.c)
target_link_libraries(KMP_Search PRIVATE util_compiler_flags)
target_include_directories(KMP_Search INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
