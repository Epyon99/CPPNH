#include "Student.h"
#include <spdlog/spdlog.h>
Student::Student(const std::string& name, int age, const std::string& major) : Person(name,age), major(major){}

std::string Student::getMajor() const{
    spdlog::info("Call get Major");
    return major;
}