#include <iostream>
#include <juego.h>
#include <ctime>   // Para std::time 

int main() { 
    // Inicializar la semilla para la generación de números aleatorios 
    std::srand(std::time(0)); 
    // Elecciones posibles 
    const std::string choices[] = {"Piedra", "Papel", "Tijeras"}; 
    // Entrada del jugador 
    std::string playerChoice; 
    std::cout << "Elige Piedra, Papel o Tijeras: "; 
    std::cin >> playerChoice; 
    // Validar la entrada del jugador 
    bool validChoice = false; 
    for (const std::string& choice : choices) { 
        if (playerChoice == choice) { 
            validChoice = true;
            break;
        } 
    } 
    if (!validChoice) { 
        std::cout << "Elección inválida. Por favor elige Piedra, Papel o Tijeras." << std::endl; 
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