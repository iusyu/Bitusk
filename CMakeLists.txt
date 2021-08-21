cmake_minimum_required(VERSION 3.12)
project(Bitusk CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(BINARY_NAME bik)
add_executable(${BINARY_NAME} main.cpp)
target_link_libraries(${BINARY_NAME} libbik)

add_subdirectory(src)