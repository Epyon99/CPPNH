#include <iostream> 
#include <stdexcept> //los tipos de error de sistema
int main(){
    try{
        throw std::runtime_error("Error");
        //double f = 15/0;
        std::cout << "Fin del programa";

    }
    catch (const std::runtime_error& e){
        std::cerr << "Error de runtime";
    }
    catch (...){
        std::cerr << "Error general";
    }
    return 0;
}