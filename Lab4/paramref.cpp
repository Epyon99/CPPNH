#include <iostream>

using namespace std;

int sumar(int& a, int& b){
    a+=1;
    b+=2;
    return a + b;
}

int main()
{
    int a = 10;
    int *b = &a; // 10
    int c = sumar (a,*b); // ?
    cout << "A:" << a << endl;
    cout << "A:" << &a << endl;
    cout << "B:" << b << endl;
    cout << "C:" << &c << endl;
    cout << "C:" << c << endl;
}
