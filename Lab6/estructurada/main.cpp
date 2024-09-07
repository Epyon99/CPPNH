#include <iostream>
#include <fstream>
struct Persona
{
    Persona() {}
    char nombre[30];
    int nacionalidad;
    int edad;
};

void guardarToFile(Persona* p)
{
    std::cout << "Memoria guardarToFile-*p:" << &p<< std::endl;
    std::ofstream archivo;
    archivo.open("C:\\Proyectos\\Educativos\\CursoDeCpp\\Laboratorios\\Lab6\\estructurada\\bd.txt", std::ios_base::app);
    archivo << p->nombre << ";" << p->nacionalidad << ";" << p->edad << std::endl;
    archivo.close();
};

void guardarDatos(Persona* p)
{
    std::cout << "Memoria guardarDatos-p:" << &p << std::endl;
    std::cout << "Guardando:";
    std::cout << p->nombre << "-";
    std::cout << p->nacionalidad << "-";
    std::cout << p->edad << std::endl;
    guardarToFile(p);
};

void recolectarDatos(Persona *persona)
{
    std::cout << "Memoria recolectarDatos-*persona:" << persona<< std::endl;
    std::cout << "Ingrese el nombre:" << std::endl;
    std::cin >> persona->nombre;
    std::cout << "Ingrese la nacionalidad 1. Para nacional, 2. Para extranjero" << std::endl;
    std::cin >> persona->nacionalidad;
    std::cout << "Ingrese su edad:" << std::endl;
    std::cin >> persona->edad;
}
int main()
{
    Persona *persona = new Persona();
    recolectarDatos(persona);
    guardarDatos(persona);
}