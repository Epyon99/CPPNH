#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int b = 7;
    float c = 3;
    float d = 7;

    int suma = a + b;                    // resultado es 10
    int resta = a - b;                   // resultado es -4
    unsigned int resta_us = a - b;       // resultado es 4294967292
    int multiplicacion_producto = a * b; // resultado es 21
    int division = a / b;                // resultado es 0
    float presicion = c / d;             // resultado es 0.428571
    int modulo = a % b;                  // resultado es 3
    float modulop = a % b;               // resultado es 3 (auncon el cambio de tipo)

    cout << suma << endl;
    cout << resta << endl;
    cout << multiplicacion_producto << endl;
    cout << division << endl;
    cout << presicion << endl;
    cout << modulo << endl;
    cout << modulop << endl;

    float md = 35 * 15 / 20;
    float md2 = 35 / 15 * 20;

    float operacion = 5 / 9 * (34 / .2);
    float operacion2 = (34 / 0.2) * 5 / 9;
    cout << "Operacion1:" << operacion << endl;
    cout << "Operacion2:" << operacion2 << endl;
}