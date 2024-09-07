#include <iostream>
#include <string>
class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

// Recibe un puntero de acceso MyClass
void func_A(MyClass* mc)
{
    // Para acceder a los miembros de una clase mediante
    // un puntero se utiliza el operador flecha
    // ->
    // Esto va a modificar el objeto.
    mc->num = 3;
}

// Recibe un objeto de MyClass
void func_B(MyClass mc)
{
    // Aca es un objeto regular
    // se usa el operador '.' (punto) para acceder a las propiedades
    // Esto solo modifica la copia local de mc.
    mc.num = 21;
    std::cout << "Local copy of mc:";
    mc.print(); // "Erika, 21"
}

int main()
{
    // Se usa el operador * para declarar un puntero de tipo MyClass
    // Se utiliza new para declarar un nuevo objeto
    // El nuevo objeto se crea en el HEAP
    MyClass* pmc = new MyClass{ 108, "Nick" };

    // Esto permite escribir la direccion de memoria. Solo para ejemplos
    std::cout << "Linea 1:" << pmc << std::endl;

    // Se copia el objeto, dereferenciando el puntero
    // esto mediante la asignacion a una variable de ltipo
    // y permite acceder al contenido.
    // mc es una nueva variable asignada al STACK
    MyClass mc = *pmc;

    // Se declara un puntero que apunta a mc
    // Se utiliza el operador 'addressof' &
    MyClass* pcopy = &mc;

    // Usa el operador -> para acceder al miembro publico del objeto
    pmc->print(); // "Nick, 108"

    // Copia el puntero. Ahora pmc y pmc2 son el mismo objeto
    MyClass* pmc2 = pmc;

    // se usa el puntero para modificar el objeto original.
    pmc2->name = "Erika";
    pmc->print(); // "Erika, 108"
    pmc2->print(); // "Erika, 108"

    // Envia el puntero a func_A
    func_A(pmc);
    pmc->print(); // "Erika, 3"
    pmc2->print(); // "Erika, 3"

    // Dereferencia el puntero y pasa una copia
    // a la funcion.
    
    MyClass pmc3 = *pmc;
    pmc3.name="Moises";
    func_B(pmc3);
    pmc3.print();
    pmc->print(); // "Erika, 3" (original not modified by function)

    delete(pmc); // Libera el puntero.
    delete(pmc2); //crash! Porque ya se habia liberado esta posicion de memoria.
}