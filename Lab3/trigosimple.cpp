#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    /// Trigo
    double angulo = 45.0;
    double seno = sin(angulo * 3.1416 / 180.0);
    double coseno = cos(angulo);
    double tangente = tan(angulo);
    cout << "Sin:" << seno << endl;
    cout << "cos:" << coseno << endl;
    cout << "tan:" << tangente << endl;

    // Exponenciales
    long base = 1550.5;
    long exponente = -1;
    long r1 = pow(base, exponente);
    cout << "Pow: " << r1;
    
    // Redondeo
    double n1 = 3.77235;
    double r2 = ceil(n1);
    cout << "Redondeo hacia arriba de {" <<n1<<"}: "<< r2 << endl;  //al techo
    cout << "Redondeo hacia abajo de {" <<n1<<"}: "<< floor(n1) << endl; // al piso
    cout << "Redondeo hacia abajo de {" <<n1<<"}: "<< round(n1) << endl; // al numero entero mas cercano
    
    
    return 0;

}