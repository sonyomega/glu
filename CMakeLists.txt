cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(glu)
enable_testing()

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

include_directories(".")
include_directories("./test/external")

add_subdirectory(glu)
add_subdirectory(test)

install(DIRECTORY glu DESTINATION include)
