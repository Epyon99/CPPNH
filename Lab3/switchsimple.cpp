#include <iostream>
using namespace std;
int main (){
    int numero;
    cout << "Ingrese un numero" << endl;
    cin >> numero;
    switch (numero){
        case 1:
        case 3:
            cout << "hola";
            cout << endl;
            break;
        case 2:
            cout << "Saludo";
            cout << endl;
            break;
        default:
            cout << "Despedida";
            cout << endl;
            break;
    }
}