#include "Person.h"
#include <spdlog/spdlog.h>
Person::Person(const std::string& name, int age) : name(name), age(age){}

std::string Person::getName() const{
    spdlog::info("Call Get Name Person");
    return name;
}

int Person::getAge() const{
    return age;
}