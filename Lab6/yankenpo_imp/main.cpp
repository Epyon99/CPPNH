#include <iostream>
#include <ctime>   // Para std::time
#include <cstdlib> // Para std::rand y std::srand

// Elecciones posibles
const std::string choices[] = {"Piedra", "Papel", "Tijeras", "exit"};

// Función para obtener la elección de la computadora
std::string getComputerChoice()
{
    // Generar un índice aleatorio entre 0 y 2
    int index = std::rand() % 3;
    return choices[index];
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

std::string getPlayerChoice()
{
    std::string playerChoice;
    while (true)
    {
        // Entrada del jugador
        std::cout << "Elige Piedra, Papel o Tijeras: ";
        std::cin >> playerChoice;

        // Validar la entrada del jugador
        bool validChoice = false;
        for (const std::string &choice : choices)
        {
            if (playerChoice == choice)
            {
                validChoice = true;
                break;
            }
        }

        if (!validChoice)
        {
            std::cout << "Elección inválida. Por favor elige Piedra, Papel o Tijeras." << std::endl;
        }
        else
        {
            break;
        }
    }
    return playerChoice;
}

int main()
{
    // Inicializar la semilla para la generación de números aleatorios
    std::srand(std::time(0));

    std::string playerChoice;
    playerChoice = getPlayerChoice();
    if (playerChoice == "exit")
    {
        return 1;
    }

    // Obtener la elección de la computadora
    std::string computerChoice = getComputerChoice();
    std::cout << "La computadora eligió: " << computerChoice << std::endl;

    // Determinar el resultado
    std::string result = determineWinner(playerChoice, computerChoice);
    std::cout << "Resultado: " << result << std::endl;
    return 0;
}