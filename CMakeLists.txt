cmake_minimum_required(VERSION 3.15)

project(Util VERSION 1.0)

enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS True)


find_program(BASH_EXECUTABLE NAMES bash REQUIRED)

add_library(util_compiler_flags INTERFACE)
target_compile_features(util_compiler_flags INTERFACE c_std_99)
target_compile_options(util_compiler_flags INTERFACE "-g;-Wall;-Wextra;-Wpedantic;-Wshadow;-Wconversion;-fsanitize=undefined,address;-Wfloat-equal;-Wformat-nonliteral;-Wformat-security;-Wformat-y2k;-Wformat=2;-Wimport;-Winvalid-pch;-Wlogical-op;-Wmissing-declarations;-Wmissing-field-initializers;-Wmissing-format-attribute;-Wmissing-include-dirs;-Wmissing-noreturn;-Wnested-externs;-Wpacked;-Wpointer-arith;-Wredundant-decls;-Wstack-protector;-Wswitch-enum;-Wundef;-Wwrite-strings")
add_subdirectory(StringUtils)
add_subdirectory(BitFile)

add_subdirectory(test/StringUtils)
add_subdirectory(test/BitFile)
