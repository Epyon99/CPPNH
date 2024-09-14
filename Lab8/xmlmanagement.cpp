#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;

int main(){
    XMLDocument doc;
    XMLError eResult = doc.LoadFile("datos.json");
    if (eResult != XML_SUCCESS){
        std::cerr << "No se pude abrir el archivo:" << eResult << std::endl;
        return 1;
    }

    XMLElement* root = doc.FirstChildElement("persona");
    if (root == nullptr) return XML_ERROR_PARSING_ELEMENT;

    const char* name = root->FirstChildElement("nombre")->GetText();
    std::cout << "Nombre:" << name;
    return 0;
}