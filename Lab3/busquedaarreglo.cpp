#include <iostream>
int main (){
    int numeros [5] = {5,10,20,25,30};
    int buscar = 1;
    bool encontrado = false;
    for (int i = 0; i < 5; i++){
        bool encontrado = numeros[i] == buscar;
        if (encontrado){
            std::cout << "El numero " << buscar << "esta en la posicion " << i+1;
            break;
        }
    }
}