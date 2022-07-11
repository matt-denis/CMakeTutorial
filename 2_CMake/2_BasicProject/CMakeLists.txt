# 0) create code and CMake file
# 1) mkdir build
# 2) cd build
# 3) cmake ..  # configure cmake
# 4) cmake --build .

cmake_minimum_required(VERSION 3.16)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

add_library(Library STATIC my_lib.cpp)

add_executable(Executable main.cpp)

# library and main object files need to be linked

target_link_libraries(Executable PUBLIC Library)
