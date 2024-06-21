#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string t;
    std::cin >> t; 
    std::cout << t;
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}