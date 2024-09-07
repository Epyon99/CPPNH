#include <iostream>
int main (){
    int numeros [2][2][2] = {
        {
            {
                1,2
            },
            {
                5,4
            }
        },
        {
            {
                2,4
            },
            {
                2,3
            }
        },
    };
    std::cout << numeros[0][1][2] << std::endl;
    std::cout << numeros[1][1][1] << std::endl;
    
}