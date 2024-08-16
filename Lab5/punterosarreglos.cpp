#include <iostream>
#include <format> // Para std::format (C++20)

void getValue(int* ptr, int xpos, int ypos, int ylength, int xlegth){
    int value = *(ptr + (ypos * ylength) + xpos); // desreferencia y obtiene el valor
    // La aritmetica de punteros sucede aca
    // ptr es la posicion original.
    // ptr + int , suma las posiciones segun el tamaño de referencia (en este caso entero)
    std::cout << std::format("Elemento en arr[{}][{}]:{}", xpos, ypos, value) << std::endl;
}

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},        {5, 6, 7, 8},        {9, 10, 11, 12}
    };

    int* ptr = &arr[0][0]; // Puntero al primer elemento del arreglo bidimensional

    // Acceder a diferentes elementos usando aritmética de punteros
    getValue(ptr,0,0,3,4);
    getValue(ptr,1,2,3,4);
    getValue(ptr,2,3,3,4);
    return 0;
}