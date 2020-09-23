cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(game_tests C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(description "Game Tests")
set(source_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include ../game/include)

# add_definitions(-DALPHA_PRINT_PASS=1)
add_definitions(-DALPHA_PRINT_FAIL=1)

file(GLOB project_source
  "${source_dir}/main.c"
)

set(project_source
  "${source_dir}/main.c"
)

message(STATUS "")
message(STATUS "====== ${PROJECT_NAME} ======")
message(STATUS "Source dir: ${source_dir}")
message(STATUS "include dir: ${include_dir}")
message(STATUS "Sources: ${project_source}")
message(STATUS "")

add_executable(game_tests ${project_source})

target_include_directories(game_tests PUBLIC ${include_dir})
if (NOT(MSVC))
  target_link_libraries(game_tests "m")
else()
  target_link_libraries(tests "Ws2_32")
endif()