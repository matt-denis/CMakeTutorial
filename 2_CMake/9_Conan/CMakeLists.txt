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

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent) # predefined cmake module

add_git_submodule(external/json)

FetchContent_Declare(  # clone repository
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 8.1.1
)
FetchContent_MakeAvailable(fmt)  # create and build the target

FetchContent_Declare(  # clone repository
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.9.2
)
FetchContent_MakeAvailable(spdlog)  # create and build the target

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # defines all variables for all targets
conan_basic_setup()

add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(src)  # list src first because app depends on src
add_subdirectory(app)
