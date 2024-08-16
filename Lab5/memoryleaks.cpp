#include <iostream>
const int max = 100000;
void simulateMemoryLeak(bool isEnabledLeak)
{
    long long *leakedMemory = new long long[max]; // Reservar memoria para un array
    if (!isEnabledLeak)
    {
        delete leakedMemory;
    }
}

int main()
{
    char opcion;
    std::cout << "Elije un modo: 'L'eaking o 'N'ormal" << std::endl;
    std::cin >> opcion;
    bool isEnabledLeak = false;
    switch (opcion)
    {
    case 'n':
    case 'N':
        isEnabledLeak = false;
        break;
    case 'L':
    case 'l':
        isEnabledLeak = true;
        break;
    }
    while (true)
    {
        simulateMemoryLeak(isEnabledLeak);
        std::cout << "Validar la memoria del proceso" << std::endl;
    }
    return 0;
}