#include <iostream>
#include <ctime>
#include <cstdlib>

class Juego
{
public:
    Juego()
    {
        std::srand(std::time(0));
    }
    void Jugar()
    {
        std::string playerChoice;
        std::cout << "Elige Piedra, Papel o Tijers:";
        std::cin >> playerChoice;

        if (!isValidChoise(playerChoice))
        {
            std::cout << "Eleccion invalida. Por favor elige Piedra, Papel o Tijeras." << std::endl;
        }

        // Obtener la elección de la computadora
        std::string computerChoice = getComputerChoice();
        std::cout << "La computadora eligió: " << computerChoice << std::endl;

        // Determinar el resultado
        std::string result = determineWinner(playerChoice, computerChoice);
        std::cout << "Resultado: " << result << std::endl;
    }

private:
    bool isValidChoise(std::string choice)
    {
        const std::string validChoices[] = {"Piedra", "Papel", "Tijeras"};
        for (auto validChoice : validChoices)
        {
            if (choice == validChoice)
            {
                return true;
            }
        }
        return false;
    }

    // Función para obtener la elección de la computadora
    std::string getComputerChoice()
    {
        const std::string validChoices[] = {"Piedra", "Papel", "Tijeras"};
        // Generar un índice aleatorio entre 0 y 2
        int index = std::rand() % 3;
        return validChoices[index];
    }

    // Función para determinar el ganador
    std::string determineWinner(const std::string &playerChoice, const std::string &computerChoice)
    {
        if (playerChoice == computerChoice)
        {
            return "Empate!";
        }
        if ((playerChoice == "Piedra" && computerChoice == "Tijeras") ||
            (playerChoice == "Papel" && computerChoice == "Piedra") ||
            (playerChoice == "Tijeras" && computerChoice == "Papel"))
        {
            return "Ganaste!";
        }
        return "Perdiste!";
    }
};

int main (){
    Juego juego;
    juego.Jugar();
    return 0;
}