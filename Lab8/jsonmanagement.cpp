//g++ .\jsonmanagement.cpp
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
int main(){
    std::ifstream inFile("datos.json");
    if (!inFile.is_open()){
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        return 1;
    }

    json j;
    inFile >> j;

    std::cout << "Nombre: " << j["nombre"] << std::endl;
    std::cout << "Apellido" << j["apellido"] << std::endl;
    inFile.close();
    return 0;
}