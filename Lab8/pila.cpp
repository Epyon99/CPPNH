#include <iostream>
struct Pila // stack
{ 
    int cima, capacidad;
    int *almacen;

    Pila(int size)
    {
        capacidad = size;
        cima = -1;
        almacen = new int[capacidad];
    }

    ~Pila()
    {
        delete[] almacen;
    }

    bool estaVacia()
    {
        return (cima == -1);
    }
    bool estaLlena()
    {
        return (cima + 1 >= capacidad);
    }

    void apilar(int valor)
    {
        if (estaLlena())
        {
            std::cout << "La Pila esta llena no se puede guardar valor '" << valor << std::endl;
            return;
        }
        if (estaVacia())
        {
            cima = 0;
        }
        else
        {
            cima++;
        }
        almacen[cima] = valor;
    }

    int pop()
    {
        if (estaVacia())
        {
            std::cout << "La Pila esta vacia\n";
            return -1;
        }
        int valor = almacen[cima];
        cima--;
        return valor;
    }

    int peek()
    {
        if (estaVacia())
        {
            std::cout << "La Pila esta vacia\n";
            return -1;
        }
        int valor = almacen[cima];
        return valor;
    }
};

int main()
{
    Pila pila(5);

    pila.apilar(1);
    pila.apilar(2);
    pila.apilar(3);
    pila.apilar(4);
    pila.apilar(5);
    pila.apilar(6);
    
    
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    
    std::cout << "Elemento del Frente:" << pila.peek() << std::endl;
    std::cout << "Elemento del Frente:" << pila.peek() << std::endl;
    std::cout << "Elemento del Frente:" << pila.peek() << std::endl;

    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Elemento del Frente:" << pila.pop() << std::endl;
    std::cout << "Fin del programa";
    return 0;
}