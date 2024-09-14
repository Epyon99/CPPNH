#include <vector>
#include <iostream>
int partition(std::vector<int> &vec, int low, int high)
{
    int pivot = vec[high];
    std::cout << "Valor del pivote" << pivot << std::endl;
    //
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (vec[j] <= pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
            std::cout << "Swap interno: Bajo: " << vec[i] << std::endl;
            std::cout << "Swap interno: Alto: " << vec[j] << std::endl;
        }
    }
    std::swap(vec[i + 1], vec[high]);
    std::cout << "Swap externo: recorrido" << vec[i+1] << std::endl;
    std::cout << "Swap externo: recorrido" << vec[high] << std::endl;
    return (i + 1);
}

void quicksort(std::vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pi = partition(vec, low, high);
        std::cout << "Valor de pi:" << pi << std::endl;
        quicksort(vec, low, pi - 1);
        quicksort(vec, pi + 1, high);
    }
}

int main()
{
    std::vector<int> vec = {10, 0, 7, 1, 5};
    int n = vec.size();

    quicksort(vec, 0, n - 1);
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    return 0;
}
