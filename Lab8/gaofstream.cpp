#include <fstream>
#include <iostream>

int main()
{
    std::cout << "Escribir datos a guardar";
    std::string datos;
    std::cin >> datos;
    std::ofstream outFile("nuevoExample.txt", std::ios::trunc);
    if (outFile.is_open())
    {
        outFile << datos << std::endl;
        outFile.close();
    }
    else
    {
        std::cout << "Error al abrir el archivo" << std::endl;
    }
    return 0;
}