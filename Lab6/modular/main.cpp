// main.cpp
#include <iostream>
#include "tasklist.h"

int main() {
    TaskList taskList;

    // Agregar algunas tareas de ejemplo
    taskList.addTask("Comprar leche");
    taskList.addTask("Hacer ejercicio");
    taskList.addTask("Estudiar programación");

    // Mostrar la lista de tareas
    taskList.displayTasks();

    return 0;
}
// Compilar simple
//g++ -o modular .\main.cpp .\tasklist.cpp

// Compilar individual
//g++.exe -c ..\main.cpp -o main.o
//g++.exe -c ..\tasklist.cpp -o tasklist.o
//g++.exe .\main.o .\tasklist.o -o modular