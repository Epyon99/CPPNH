#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Person.h"

class Student : public Person{
public:
    Student(const std::string& name, int age, const std::string& major);
    
    std::string getMajor() const;
protected:
    std::string major;
};
#endif // STUDENT_H