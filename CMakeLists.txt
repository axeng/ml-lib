cmake_minimum_required(VERSION 3.16)
project(ml-lib)

set(CMAKE_CXX_STANDARD 17)

# Automatic Compilation Flag to Release
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

############### COMPILATION FLAGS ###############
# General compilation flags
set(CMAKE_CXX_FLAGS "-pedantic -Werror -Wall -Wextra -std=c++17")

# Debug compilation flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")

# Release compilation flags
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -march=native")
##################################################

set(MAIN_TARGET ml-lib)
set(UNIT_TESTS_TARGET unit)

################## DIRECTORIES ##################
include_directories(
        src
        tests)
#################################################

#################### SOURCES ####################
# Main Sources (without exec)
set(MAIN_SOURCES
        )

# Main Full Sources
set(MAIN_EXEC_SOURCES
        ${MAIN_SOURCES}
        src/ml-lib.cc)

# Unit Tests computation sources
set(UNIT_TESTS_COMPUTATION_SOURCES
        tests/unit_tests/computation/statistic.cc)

# Unit Tests data structure sources
SET(UNIT_TESTS_DATA_STRUCTURE_SOURCES
        tests/unit_tests/data_structure/iterator/step_iterator.cc
        tests/unit_tests/data_structure/matrix/matrix_constructor.cc
        tests/unit_tests/data_structure/matrix/matrix_fill.cc
        tests/unit_tests/data_structure/matrix/matrix_sort.cc
        tests/unit_tests/data_structure/matrix/matrix_transpose.cc
        tests/unit_tests/data_structure/matrix/matrix_sub_matrix.cc
        tests/unit_tests/data_structure/matrix/matrix_apply.cc
        tests/unit_tests/data_structure/matrix/matrix_concatenate.cc
        tests/unit_tests/data_structure/matrix/matrix_statistics.cc
        tests/unit_tests/data_structure/matrix/matrix_arithmetic_operations.cc
        tests/unit_tests/data_structure/matrix/matrix_multiplies_matrix.cc
        tests/unit_tests/data_structure/matrix/matrix_comparison.cc
        tests/unit_tests/data_structure/matrix/matrix_at.cc
        tests/unit_tests/data_structure/matrix/matrix_get_broadcast_value.cc
        tests/unit_tests/data_structure/matrix/matrix_print.cc)

set(UNIT_TESTS_GENERATOR_SOURCES
        tests/unit_tests/generator/random/uniform_random.cc)

# Unit Tests Sources
set(UNIT_TESTS_SOURCES
        ${UNIT_TESTS_COMPUTATION_SOURCES}
        ${UNIT_TESTS_DATA_STRUCTURE_SOURCES}
        ${UNIT_TESTS_GENERATOR_SOURCES}
        tests/unit_tests/main.cc
        ${MAIN_SOURCES})
#################################################

# Main Executable
add_executable(${MAIN_TARGET}
        ${MAIN_EXEC_SOURCES})


###############################################################################
#                                 GOOGLE TEST                                 #
###############################################################################

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

# Unit Tests Executable
add_executable(${UNIT_TESTS_TARGET} ${UNIT_TESTS_SOURCES})
target_link_libraries(${UNIT_TESTS_TARGET} gtest_main)
