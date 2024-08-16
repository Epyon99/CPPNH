#include <iostream>
#include <memory> // Para std::shared_ptr y std::weak_ptr

int main() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(10);
    std::weak_ptr<int> weakPtr = sharedPtr;

    std::cout << "Shared pointer use count: " << sharedPtr.use_count() << std::endl; // 1

    if (!weakPtr.expired()) {
        auto tempPtr = weakPtr.lock();
        std::cout << "Value: " << *tempPtr << std::endl; // 10
    }

    sharedPtr.reset(); // Destruye el objeto

    if (weakPtr.expired()) {
        std::cout << "The resource has been destroyed." << std::endl;
    }

    return 0;
}