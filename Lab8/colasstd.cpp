#include <iostream>
#include <queue>

int main()
{
    std::queue<int> cola;

    // encolar
    cola.push(10);
    cola.push(20);
    cola.push(30);

    while (!cola.empty()){
        std::cout << "Peek: " << cola.front() << std::endl;
        cola.pop();
    }
    std::cout << "Fin del programa";
}