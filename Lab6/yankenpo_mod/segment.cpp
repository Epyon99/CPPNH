#include <iostream>
#include <string>

struct clientInfo
{
    std::string client;
    std::string a;
    std::string b;
};

void modifyClientArray(clientInfo **arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        // Modify clientInfo elements here
        if ((*arr)[i].a.empty())
        {
            (*arr)[i].a = "default_a";
        }
        if ((*arr)[i].b.empty())
        {
            (*arr)[i].b = "default_b";
        }
        (*arr)[i].a += " (modified)";
        (*arr)[i].b += " (updated)";
    }
}

int main()
{
    clientInfo *clients[3];
    for (size_t i = 0; i < 3; ++i)
    {
        clients[i] = new clientInfo();
        clients[i]->client = "Client" + std::to_string(i + 1);
        clients[i]->a = "ValueA_" + std::to_string(i);
        clients[i]->b = "ValueB_" + std::to_string(i);
    }

    // Call the function to modify the array
    modifyClientArray(clients, 3);

    // Print modified values
    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << clients[i]->client
                  << ": a = " << clients[i]->a
                  << ", b = " << clients[i]->b << std::endl;
        delete clients[i]; // Clean up allocated memory
    }

    return 0;
}