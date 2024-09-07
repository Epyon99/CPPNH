#include <iostream>

using namespace std;
int globala = 10;

void incrementar(int* a){
    a+=1;
}
void incrementar2(int* a){
    (*a)+=1;
}


int main()
{
    int a = 10;
    incrementar(&a);
    cout << "A:" << a << endl;
    cout << "A:" << &a << endl;
    incrementar2(&a);
    cout << "A:" << a << endl;
    cout << "A:" << &a << endl;
}
