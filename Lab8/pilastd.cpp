#include <iostream>
#include <stack>

int main()
{
    std::stack<int> stack;

    // encolar
    stack.push(10);
    stack.push(20);
    stack.push(30);

    while (!stack.empty()){
        std::cout << "Peek: " << stack.top() << std::endl;
        stack.pop();
    }
    std::cout << "Fin del programa";
}