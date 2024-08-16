#include <iostream> 
#include <cstdlib> // Para std::rand y std::srand 

// Función para obtener la elección de la computadora 
std::string getComputerChoice() { 
    // Opciones posibles 
    const std::string choices[] = {"Piedra", "Papel", "Tijeras"}; 
    // Generar un índice aleatorio entre 0 y 2 
    int index = std::rand() % 3; 
    return choices[index]; 
} 
 
// Función para determinar el ganador 
std::string determineWinner(const std::string& playerChoice, const std::string& computerChoice) { 
    if (playerChoice == computerChoice) { 
        return "Empate!"; 
    } 
    if ((playerChoice == "Piedra" && computerChoice == "Tijeras") || 
        (playerChoice == "Papel" && computerChoice == "Piedra") || 
        (playerChoice == "Tijeras" && computerChoice == "Papel")) { 
        return "Ganaste!"; 
    } 
    return "Perdiste!"; 
} 