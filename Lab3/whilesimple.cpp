#include <iostream>
using namespace std;
int main()
{
    int numero;
    cout << "Ingrese un numero" << endl;
    cin >> numero;

    while (numero < 10)
    {
        switch (numero)
        {
        case 1:
        case 3:
            cout << "hola " <<numero ;
            cout << endl;
            numero++;
            break;
        case 2:
            cout << "Saludo";
            cout << endl;
            numero++;
            break;
        default:
            cout << "Despedida";
            cout << endl;
            numero = 10;
            break;
        }
        break;
    }
}