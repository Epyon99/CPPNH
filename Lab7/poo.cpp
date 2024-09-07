#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Persona
{
private:
    string nombre;
    int edad;

public:
    virtual void comer() {};
    int talla;
    void setPersona(string n, int e)
    {
        nombre = n;
        edad = e;
    };
    void saludar()
    {
        cout << "Hola, mi nombre es " << nombre;
        cout << " y tengo " << edad << " años. " << endl;
    }
    void Envejecer()
    {
        edad = edad * 2;
        cout << edad;
    }
    Persona(string n, int e) : nombre(n), edad(e) {}
    Persona() {}
};

class Empleado : public Persona
{
private:
    string empresa;
    double salario;

public:
    virtual void comer() override{
        talla++;
    }
    void setSalario(double sueldo)
    {
        salario = sueldo;
    }
    double getSalario()
    {
        return salario;
    }
    Empleado(string n, int e) 
    {
        setPersona(n, e);
    }
};
int main()
{
    vector<Empleado> lista;
    string nombres[] = {"Moises", "Florentino", "Tafur", "Paulette", "Fernando", "Diego", "Luis"};
    for (int i = 1; i <= 3; i++)
    {
        lista.push_back(Empleado(nombres[i], i * 10));
    }

    for (auto empleado : lista)
    {
        empleado.saludar();
        empleado.setSalario(1000.0);
        cout << empleado.getSalario();
    }
    return 0;
}