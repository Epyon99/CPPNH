#include <iostream>
int main()
{
    // declarar un string C-Style
    const char *str = "Word";

    const int c = 1;
    const int *pconst = &c;
    std::cout << pconst << std::endl;

    const int d = 2;
    pconst = &d;
    std::cout << pconst << std::endl;
    
    // stop para la clase
    char t;
    std::cin >> t; 

    const int* const pconst2 = &c;
    std::cout << pconst2 << std::endl;

    int e = *pconst2;
    std::cout << e << std::endl;
    std::cout << pconst2 << std::endl;
    std::cout << &e << std::endl;
    


    //pconst2 = &d;
}