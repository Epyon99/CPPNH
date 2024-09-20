//g++ .\xmlmanagement.cpp -ltinyxml2
#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;

int main(){
    XMLDocument doc;

    // Create a new XML document
    XMLElement* root = doc.NewElement("Root");
    doc.InsertFirstChild(root);
    
    // Create a child element
    XMLElement* child = doc.NewElement("Child");
    child->SetText("This is a child element.");
    root->InsertEndChild(child);
    
    // Save the XML to a file
    doc.SaveFile("example.xml");

    // Load the XML from the file
    doc.LoadFile("example.xml");
    root = doc.FirstChildElement("Root");
    if (root) {
        XMLElement* childElement = root->FirstChildElement("Child");
        if (childElement) {
            const char* text = childElement->GetText();
            std::cout << "Child text: " << text << std::endl;
        }
    }

    return 0;
}