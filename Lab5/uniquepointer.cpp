#include <iostream>
#include <memory>

class MyClass {
    public:
        std::string var1;
    public:
    MyClass() {
        std::cout << "My Class Constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }

    void show() {
        std::cout << "MyClass::show() -" << var1 << std::endl;
    }
    void show(std::string texto) {
        std::cout << texto << std::endl;
    }
};

void process(std::unique_ptr<MyClass> ptr)
{
    ptr->show();
};// Invoca el destructor

int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(); // Llama al constructor
    ptr1->show("llamada en metodo principal");
    ptr1->var1 = "Hola";
    process(std::move(ptr1));
    //
    ptr1->show(); // error
}

