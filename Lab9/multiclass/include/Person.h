#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person{
public:
    Person(const std::string& name, int age);
    virtual ~Person() = default;

    std::string getName() const;
    int getAge() const;
protected:
    std::string name;
    int age;
};
#endif // PERSON_H;