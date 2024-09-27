#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Person.h"
#include "nlohmann/json.hpp"
#include <spdlog/spdlog.h>

int main(){ 
    spdlog::info("Inicio del programa");
    
    Student Student("Moises",30,"Ciencias de la computacion");
    Teacher Teacher("Fernando",18,"Matematica");

    nlohmann::json j;
    j["student"] = {{"name",Student.getName()},{"age",Student.getAge()}, {"major",Student.getMajor()}};
    j["teacher"] = {{"name",Teacher.getName()},{"age",Teacher.getAge()}, {"Subject",Teacher.getSubject()}};

    std::cout << j.dump(4) << std::endl;
    return 0;
}