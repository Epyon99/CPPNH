#include <iostream>
#include <array>

using namespace std;
int main()
{
    array<int, 5> vec ;
    vec = {1, 2, 3, 4, 5};

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Posicion [" << i << "]:" << vec[i] << endl;
    }

    vec.fill(10);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Posicion [" << i << "]:" << vec[i] << endl;
    }
}