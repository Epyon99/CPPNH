#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "Person.h"

class Teacher : public Person{
public:
    Teacher(const std::string& name, int age, const std::string& subject);
    
    std::string getSubject() const;
protected:
    std::string subjcet;
};
#endif // TEACHER_H