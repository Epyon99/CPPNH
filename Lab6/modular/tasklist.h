// tasklist.h
#ifndef TASKLIST_H
#define TASKLIST_H

#include <vector>
#include <string>

class TaskList {
public:
    void addTask(const std::string& task);
    void displayTasks() const;

private:
    std::vector<std::string> tasks;
};

#endif // TASKLIST_H
