#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};

    vec.push_back(1);
    cout << "Size del vector:" << vec.size() << endl;
    // vec.pop_back();
    cout << "Size del vector:" << vec.size() << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Posicion [" << i << "]:" << vec[i] << endl;
    }

    cout << "Capacidad: " << vec.capacity() << endl;
    for (int i = 0; i < 100; i = i + 10)
    {
        vec.push_back(i);
    }
    cout << "Cantidad:" << vec.size() << endl;
    cout << "Capacidad: " << vec.capacity() << endl;
    vec[20] = 10;
    cout << vec[20] << endl;
    
    cout << "Cantidad:" << vec.size() << endl;
}