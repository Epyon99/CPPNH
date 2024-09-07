// tasklist.cpp
#include "tasklist.h"
#include <iostream>

void TaskList::addTask(const std::string& task) {
    tasks.push_back(task);
}

void TaskList::displayTasks() const {
    std::cout << "Lista de tareas:" << std::endl;
    for (const auto& task : tasks) {
        std::cout << "- " << task << std::endl;
    }
}
