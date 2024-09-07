#include <iostream>
int main(){
    int numeros [10] = {5,10,20,25,30};
    int suma = 0;
    int a = 5,b = 10,c = 20,d = 25,e = 30; 
    suma += numeros[0];
    suma += numeros[1];
    suma += numeros[2];
    suma += numeros[3];
    suma += numeros[4];
    std::cout << "La suma individual es " << suma;
    suma = 0;
    for (int i = 0; i < 5; i++){
        suma += numeros[i];
    }

    std::cout << "La suma de los valores es:" << suma << std::endl;
}