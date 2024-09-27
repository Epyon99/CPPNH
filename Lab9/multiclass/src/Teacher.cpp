#include "Teacher.h"
Teacher::Teacher(const std::string& name, int age, const std::string& major) : Person(name,age), subjcet(subjcet){}

std::string Teacher::getSubject() const{
    return subjcet;
}