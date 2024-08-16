#include <iostream>
#include <memory>
class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }
    void show() {
        std::cout << "MyClass::show()" << std::endl;
    }
};

void printReferenceCount(const std::shared_ptr<MyClass>& ptr) {
    std::cout << "Reference count: " << ptr.use_count() << std::endl;
}

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();

    printReferenceCount(ptr1); // Imprime 1

    {
        std::shared_ptr<MyClass> ptr2 = ptr1;
        printReferenceCount(ptr1); // Imprime 2
        printReferenceCount(ptr2); // Imprime 2
    } // `ptr2` sale del ámbito y se destruye

    printReferenceCount(ptr1); // Imprime 1

    return 0;
}