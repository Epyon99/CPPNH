#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main (){
    ofstream outFile("datos.txt");
    if (outFile.is_open()){
        outFile << "Hola Clase NH!" << endl;
        outFile << "Hola Clase NH2!" << endl;
        outFile.close();
    }
    else {
        cerr << "El archivo esta bloqueado";
    }

    ifstream inFile("datos.txt");
    if (inFile.is_open()){
        string linea;
        while (getline(inFile,linea)){
            cout << "Leido del archivo:" << linea << endl;
        }
        inFile.close();
    }
    else {
        cerr << "El archivo esta bloqueado";
    }
}