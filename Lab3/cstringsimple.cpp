#include <iostream>
#include <cstring>

int main(){
    char stf1[] = "Hola";
    char stf2[] = "Mundo";
    char buffer[50];

    // copia de string en buffer
    strcpy(buffer, stf1);
    // concatena los datos de str a buffer.
    strcat(buffer, stf2);

    std::cout << buffer << std::endl;

    std::cout << std::strlen(buffer) << std::endl;
}