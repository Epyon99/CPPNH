#include <iostream>
#define PI 3.141615926
#define PLUS1(x) x + 1
#define PLUS2(x) (x + 2)

int main(){
    std::cout << PI << std::endl;
    std::cout << PLUS1(10) << std::endl;
    std::cout << PLUS2(20) << std::endl;
    return 0;
}