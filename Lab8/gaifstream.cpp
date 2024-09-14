#include <fstream> // Libreria para el manejo de archivos en disco
#include <iostream>

void mostrarArchivo(std::ifstream inFile)
{
    std::string line;
    int contador = 1;
    while (std::getline(inFile, line))
    {
        std::cout << "Linea " << contador++ << ":" << line << std::endl;
    }
    inFile.close();
};

int main()
{
    std::ifstream inFile("example.txt", std::ios_base::openmode::_S_out);    
    if (inFile.is_open())
    {
        std::string line;
        int contador = 1;
        while (std::getline(inFile, line))
        {
            std::cout << "Linea " << contador++ << ":" << line << std::endl;
        }
        inFile.close();
    }
    else
    {
        std::cout << "Error al abrir el archivo" << std::endl;
    }
    return 0;
}