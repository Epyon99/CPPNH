#include <iostream>
using namespace std;
int main()
{
    int a = 1270000000;
    short b = a;
    float c = a;
    float d = c / true;
    cout << b << endl;
    cout << c << endl;


    double pi = 3.14;
    int valorInt = static_cast<int>(pi);
    int valorIntD = pi;
    cout << valorInt << endl;
    cout << valorIntD;
}