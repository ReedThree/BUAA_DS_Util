add_library(StringUtils StringUtils.c)
target_link_libraries(StringUtils PRIVATE KMP_Search util_compiler_flags)
target_include_directories(StringUtils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(KMP)