cmake_minimum_required(VERSION 3.16)
project(10550_Combination_Lock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Match the repo's usual manual builds (g++ -O2) when no build type is given.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(
        # General warnings
        -Wall
        -Wextra
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wdouble-promotion
        -Wextra-semi
        -Wfloat-equal
        -Wformat=2
        -Wimplicit-fallthrough
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wshadow
        -Wswitch-default
        -Wswitch-enum
        -Wundef
        -Wunused
        -Wunused-macros
        -Wvla
        -Wzero-as-null-pointer-constant
        # Extra warnings that only GCC has
        -Walloca
        -Warray-bounds=2
        -Wclass-memaccess
        -Wctor-dtor-privacy
        -Wdangling-pointer
        -Wdangling-reference
        -Wdeprecated-copy
        -Wdeprecated-copy-dtor
        -Wduplicated-branches
        -Wduplicated-cond
        -Wformat-overflow=2
        -Wformat-signedness
        -Wformat-truncation=2
        -Wlogical-op
        -Wmissing-declarations
        -Wmissing-format-attribute
        -Wmissing-include-dirs
        -Wnoexcept
        -Wnull-dereference
        -Wrestrict
        -Wself-move
        -Wshift-overflow
        -Wstrict-aliasing
        -Wstringop-overflow
        -Wstringop-truncation
        -Wuseless-cast
    )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(
        # General warnings
        -Wall
        -Wextra
        -Wpedantic
        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wdouble-promotion
        -Wextra-semi
        -Wfloat-equal
        -Wformat=2
        -Wimplicit-fallthrough
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wshadow
        -Wswitch-default
        -Wswitch-enum
        -Wundef
        -Wunused
        -Wunused-macros
        -Wvla
        -Wzero-as-null-pointer-constant
        # Extra warnings that only Clang has
        -Wdocumentation
        -Wpadded
    )
endif()

add_executable(10550_Combination_Lock main.cpp)
