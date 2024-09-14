#include <fstream>
#include <iostream>

int main()
{
    std::cout << "Escribir datos a guardar" << std::endl;
    std::string datos;
    std::cin >> datos;

    std::fstream file("example.txt", std::ios::in | std::ios::out);
    if (file.is_open())
    {
        file << datos << std::endl;

        file.seekg(0);
        datos = "";
        while (std::getline(file, datos))
        {
            std::cout << datos << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Error al abrir el archivo" << std::endl;
    }
    return 0;
}