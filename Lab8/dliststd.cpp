#include <iostream>
#include <list>

int main()
{
    std::list<int> lista;

    // insert
    lista.push_back(10);
    lista.push_front(20);
    lista.push_front(30);
    lista.push_front(30);
    lista.push_back(1000);

    // recorrer
    for (int elemento : lista)
    {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;

    std::cout << lista.front() << std::endl;
    std::cout << lista.back() << std::endl;

    lista.pop_back();
    lista.pop_front();

    std::cout << lista.front() << std::endl;
    std::cout << lista.back() << std::endl;

    for (int elemento : lista){
        if (elemento == 30){
            std::cout << "Se encontro el valor 30" << std::endl;
        }
    }
}