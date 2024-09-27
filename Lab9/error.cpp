#include <iostream>
#include <csignal>
#include <cstdlib>

void manejadorSegFault(int signal)
{
    std::cerr << "Error de signal:" << signal << std::endl;
    std::exit(signal);
}

int main()
{
    std::signal(SIGSEGV, manejadorSegFault);
    int *ptr = nullptr; // nullptr valor aleatorio
    std::cout << *ptr << std::endl;
    std::cout << "Hola mundo";
    return 0;
}