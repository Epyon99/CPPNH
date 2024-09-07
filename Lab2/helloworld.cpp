#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg = {"¡Hola", "en C++", "de", "from", "new", "Horizons!"};
    
    for (const string word : msg)
    {
        cout << word << " ";
    }
    std::cout << std::endl;
}