#include <iostream>
using namespace std;
int main()
{
    int numero = 100;
    do
    {
        cout << "Ingrese un numero:" << numero<< endl;
        cin >> numero;
    } while (numero < 10);

    cout << "El numero " << numero << " es mayor a 10" << endl;
}