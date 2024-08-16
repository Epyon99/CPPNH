#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main (){
    vector<int> vec = {5,2,9,1,7};
    sort(vec.begin(), vec.end());

    //
    int target = 9;
    auto it = find(vec.begin(), vec.end(), target);
    if (it != vec.end()){
        cout << "Elemento encontrado" << distance(vec.begin(), it) << endl;
    } else {
        cout << "Elemeto no encontrado";
    }

    auto maximo = max(vec.begin(), vec.end());
}