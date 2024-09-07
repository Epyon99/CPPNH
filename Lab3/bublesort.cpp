#include <iostream>
using namespace std;
int main()
{
    const int size = 10;
    int input[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Agregue un numero para la posicion [" << i << "]:" << endl;
        cin >> input[i];
        cout << endl;
    }

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (input[j] < input[j + 1])
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
    int indice = 0;
    while (indice < size){
        cout << input[indice] << ",";
        indice++;
    }
    cout << endl;
}