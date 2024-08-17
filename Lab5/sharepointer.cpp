#include <iostream>
#include <memory>
#include <string>
class MyClass
{
public:
public:
    std::string var1 = "Defecto";
    MyClass()
    {
        std::cout << "MyClass Constructor" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "MyClass Destructor" << std::endl;
    }
    void show()
    {
        std::cout << "MyClass::show() - " << var1 << std::endl;
    }
};

void printReferenceCount(const std::shared_ptr<MyClass> &ptr)
{
    std::cout << "Reference count: " << ptr.use_count() << std::endl;
};
void process(std::shared_ptr<MyClass> ptr)
{
    ptr->show();
    printReferenceCount(ptr);
}; // Invoca el destructor

int main()
{
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> observador = ptr1;
    process(ptr1);
    ptr1->var1 = "Primer cambio";
    process(ptr1);
    ptr1.use_count();
    printReferenceCount(ptr1); // Imprime 1

    {
        ptr1.reset();
        if (!observador.expired())
        {
            std::shared_ptr<MyClass> ptr2 = ptr1;
            process(ptr2);
            printReferenceCount(ptr2); // Imprime 3
        }
        std::cout << "Numero de observadores:" << observador.use_count() << std::endl;
        printReferenceCount(ptr1); // Imprime 2
        if (!observador.expired())
        {
            std::shared_ptr<MyClass> ptr3 = ptr1;
            ptr3->var1 = "Segundo Cambio";
            process(ptr3);
            printReferenceCount(ptr3);
            std::cout << "Numero de observadores:" << observador.use_count() << std::endl;
        }
        std::cout << "Numero de observadores:" << observador.use_count() << std::endl;
    } // `ptr2` sale del ámbito y se destruye

    printReferenceCount(ptr1); // Imprime 1
    std::cout << ptr1->var1 << std::endl;
    std::cout << "Numero de observadores:" << observador.use_count() << std::endl;
    return 0;
}