cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

aux_source_directory(. SRC_LIST)
add_library(libbik ${SRC_LIST})
