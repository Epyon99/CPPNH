#include <iostream>

using namespace std;

int sumar(int a, int b){
    a+=1;
    b+=2;
    return a + b;
}

int main()
{
    int a = 10;
    int b = a; // 10
    int c = sumar (a,b); // ?
    int d = a + b; // 20
    cout << "A:" << a << endl;
    cout << "B:" << b << endl;
    cout << "C:" << c << endl;
    cout << "D:" << d << endl;
}
