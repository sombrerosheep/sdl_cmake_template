cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(game)

set(BUILD_TESTS ON CACHE BOOL "Sets whether or not to build the test executable")

add_subdirectory(game)

if (BUILD_TESTS)
  add_subdirectory(test)
endif()