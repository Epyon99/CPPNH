//inyeccion de dependencias por propiedad
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
        void setServicio(std::shared_ptr<Servicio> serv){
            servicio = serv;
        }
        std::shared_ptr<Servicio> getServicio(){
            return servicio;
        }
        void realizarTarea() {
            servicio->ejecutar();
        }
};

int main() {
    auto servicio = std::make_shared<Servicio>();
    Cliente client;
    client.setServicio(servicio); // se asigna servicio;
    client.realizarTarea();
    return 0;
}