#include <iostream>
#include <cstdlib>
#include <vector>

int compare(const void *a, const void *b)
{
    std::cout << (*(int*)a) << ":" << (*(int*)b) << std::endl;
    return (*(int *)a - *(int *)b);
    // 0 si son iguales , No mueve
    // <0 si b es mayor que A , Mueve B a la izquierda.
    // >0 si A es mayor que, mueva A a la derecha.
}

int main()
{
    std::vector<int> vec = {10, 7, 8, 9, 1, 5};    
    std::qsort(&vec[0],vec.size(), sizeof(int), compare);

    for (int i : vec)
    {
        std::cout << i << " ";
    }
    return 0;
}
