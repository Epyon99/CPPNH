//inyeccion de dependencias por constructor
#include <iostream>
#include <memory>

class Servicio{
    public:
        void ejecutar(){
            std::cout << "Servicio ejecutado" << std::endl;
        }
};

class Cliente{
    std::shared_ptr<Servicio> servicio;
    public:
        Cliente(std::shared_ptr<Servicio> serv) : servicio(serv){}
        void realizarTarea() {
            servicio->ejecutar();
        }
};

int main() {
    auto servicio = std::make_shared<Servicio>();
    Cliente client(servicio);
    client.realizarTarea();
    return 0;
}