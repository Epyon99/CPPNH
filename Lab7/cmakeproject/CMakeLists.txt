#pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja
cmake_minimum_required(VERSION 3.10)
project(MyCppProject)

# Add Source files
add_executable(my_program main.cpp helper.cpp)