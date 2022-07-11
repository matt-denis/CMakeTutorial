# 0) create code and CMake file
# 1) mkdir build
# 2) cd build
# 3) cmake ..  # configure cmake
# 4) cmake --build .

cmake_minimum_required(VERSION 3.16)

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)



add_subdirectory(src)  # list src first because app depends on src
add_subdirectory(configured)
add_subdirectory(app)
