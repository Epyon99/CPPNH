#include <iostream>
struct Cola
{ // queue
    int frente, final, capacidad;
    int *almacen;

    Cola(int size)
    {
        capacidad = size;
        frente = final = -1;
        almacen = new int[capacidad];
    }

    ~Cola()
    {
        delete[] almacen;
    }

    bool estaVacia()
    {
        return (frente == -1);
    }
    bool estaLlena()
    {
        return ((final + 1) % capacidad == frente);
    }

    void encolar(int valor)
    {
        if (estaLlena())
        {
            std::cout << "La cola esta llena no se puede guardar valor '" << valor << std::endl;
            return;
        }
        if (estaVacia())
        {
            frente = final = 0;
        }
        else
        {
            final = (final + 1) % capacidad;
        }
        almacen[final] = valor;
    }

    int desencolar()
    {
        if (estaVacia())
        {
            std::cout << "La cola esta vacia\n";
            return -1;
        }
        int valor = almacen[frente];
        if (frente == final)
        {
            frente = final = -1;
        }
        else
        {
            frente = (frente + 1) % capacidad;
        }
        return valor;
    }

    int peek()
    {
        if (estaVacia())
        {
            std::cout << "La cola esta vacia\n";
            return -1;
        }
        int valor = almacen[frente];
        return valor;
    }
};

int main() {
    Cola cola(5);

    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cola.encolar(5);
    cola.encolar(6);
    cola.encolar(7);
    
    std::cout << "Elemento del Frente:" << cola.desencolar() << std::endl;
    std::cout << "Elemento del Frente:" << cola.desencolar() << std::endl;
    std::cout << "Elemento del Frente:" << cola.desencolar() << std::endl;
    
    std::cout << "Elemento del Frente:" << cola.peek() << std::endl;
    std::cout << "Elemento del Frente:" << cola.peek() << std::endl;
    std::cout << "Elemento del Frente:" << cola.peek() << std::endl;
    
    std::cout << "Elemento del Frente:" << cola.desencolar() << std::endl;
    std::cout << "Elemento del Frente:" << cola.desencolar() << std::endl;
    
    cola.encolar(6);
    cola.encolar(7);
    
    return 0;
}