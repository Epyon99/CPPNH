#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &vector)
{
    int n = vector.size();

    for (int i = 0; i < n - 1; i++)
    {
        std::cout << "Numero de rondas:" << i << std::endl;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                // std::cout << vector[j] << "-" << vector[j + 1] << std::endl;
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};
    bubbleSort(vec);
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    return 0;
}