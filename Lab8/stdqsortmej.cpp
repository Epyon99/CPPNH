#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};

    std::sort(vec.begin(), vec.end());

    std::cout << "Vector ordenado: ";
    for (int i : vec) // para cada elemnto de vector
    {
        std::cout << i << " ";
    }
    return 0;
}