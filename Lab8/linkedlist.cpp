#include <iostream>
struct Nodo
{
    int valor;
    Nodo *next;
};

void insertarInicio(Nodo*&cabeza, int valor){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->valor = valor;
    nuevoNodo->next = cabeza;
    cabeza = nuevoNodo;
}

void eliminarInicio(Nodo*& cabeza){
    if (cabeza != nullptr){
        Nodo* temp = cabeza;
        cabeza = cabeza->next;
        delete temp;
    }
}

void insertarFinal(Nodo*&cabeza, int valor){
    // Crear una nueva posicion de memoria
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->valor = valor;
    nuevoNodo->next = nullptr;

    // Desde el primero objeto. buscar El ultimo
    if (cabeza == nullptr){
        cabeza = nuevoNodo;
    }else {
        Nodo* temp = cabeza;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }
}

void eliminarFinal(Nodo*& cabeza){
    if (cabeza == nullptr) return;
    if (cabeza->next == nullptr){
        delete cabeza;
        cabeza = nullptr;
    }
    else {
        Nodo* temp = cabeza;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        delete temp->next; // elimina el valor en la posicion de memoria de temp->next (0000010)
        temp->next = nullptr;
    }
}

Nodo* buscar(Nodo* cabeza, int filtro){
    Nodo* actual = cabeza;
    while (actual != nullptr){
        if (actual->valor == filtro){
            return actual;
        }else {
            actual = actual->next;
        }
    }
    return actual;
}

void recorrerLista(Nodo* cabeza){
    Nodo* actual = cabeza;
    while (actual != nullptr){
        std::cout << actual->valor << ":" << &actual << "->";
        actual = actual->next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    Nodo* cabeza = new Nodo();
    insertarInicio(cabeza, 10);
    insertarFinal(cabeza, 20);
    insertarFinal(cabeza, 30);
    recorrerLista(cabeza);
    Nodo* busqueda = buscar(cabeza,20);
    std::cout <<"Busqueda:" << busqueda->valor;
}