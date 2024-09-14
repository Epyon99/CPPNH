#include <iostream>
#include <cstdlib>

int compare(const void* a, const void* b){
    // std::cout << (*(int*)a) << ":" << (*(int*)b) << std::endl;
    return (*(int*)a - *(int*)b);
    // 0 si son iguales , No mueve
    // <0 si b es mayor que A , Mueve B a la izquierda.
    // >0 si A es mayor que, mueva A a la derecha.
}

int main(){
    int arr[] = {10,7,8,9,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " "; 
    }
    return 0;
}
