#include <iostream>
#include <vector>
#include <string>

using namespace std;

int suma(int a, int b){
    return a + b;
}

void func1(int iteracion)
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    cout << "Iteracion:" << iteracion << "-";
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
};

int main()
{
    for (int i = 0; i < 3; i++)
    {
        func1(i);
    }
    cout << suma(1,4) << " valor de la suma";
}
