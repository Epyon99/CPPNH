cmake_minimum_required(VERSION 3.10)
# el nombre del proyecto
project(multiclass VERSION 0.1 LANGUAGES CXX)

#donde estan las dependencias
include_directories(include external/nlohmann)
# lo que se va a compilar en un ejecutable
add_executable(multiclass
    src/main.cpp
    src/Person.cpp
    src/Teacher.cpp
    src/Student.cpp
)
# especifica la version de C++
set_target_properties(multiclass PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED YES)
