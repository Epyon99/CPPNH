#include <iostream>
using namespace std;
int main (){
    int numero;
    cout << "Ingrese un numero" << endl;
    cin >> numero;
    int operacion = numero % 2;
    int validacion = operacion == 0;
    if (validacion){
        cout << "El numero "<< numero << " es % 2" << endl;
    }
    else if (numero % 2 == 0) {
        cout << "El numero "<< numero << " es % 4"<< endl;
    }
    else if (numero %2 == 0){
        cout << "El numero "<< numero << " es % 8"<< endl;
    }

    if (numero % 2 == 0){
        cout << "El numero "<< numero << " es % 16"<< endl;
    }
    if (numero % 2 == 0){
        cout << "El numero "<< numero << " es % 32"<< endl;
    }
}