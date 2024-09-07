#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

struct Jugador
{
    Jugador(std::string n) : nombre(n) {}
    std::string eleccion;
    std::string nombre;
    std::string generarEleccion()
    {
        const std::string choices[] = {"Piedra", "Papel", "Tijera"};
        // Generar un índice aleatorio entre 0 y 2
        int index = std::rand() % 3;
        eleccion = choices[index];
        return eleccion;
    }
};

// Función para determinar el ganador
std::vector<Jugador> determinarGanador(std::vector<Jugador> jugadores)
{
    
    // Mapeo de elecciones a contadores
    std::map<std::string, int> conteo;
    conteo["Piedra"] = 0;
    conteo["Papel"] = 0;
    conteo["Tijera"] = 0;

    // Contar las elecciones de cada jugador
    for (int i = 0; i < jugadores.size(); i++)
    {
        conteo[jugadores[i].generarEleccion()]++;
    }


    for (auto it = conteo.begin(); it != conteo.end(); )
    {
        if (it->second == 0)
        {
            it = conteo.erase(it);
        }
        else
        {
            ++it;
        }
    }

    auto maxElement = std::max_element(conteo.begin(), conteo.end());
    auto minElement = std::min_element(conteo.begin(), conteo.end());
    // Verificar si hay un empate total
    if ((conteo["Piedra"] > 0 && conteo["Papel"] > 0 && conteo["Tijera"] > 0) || (maxElement->second == minElement->second && maxElement->second > 1))
    {
        return jugadores;
    }


    std::string ganador = "";
    if (maxElement->first == "Piedra" && minElement->first == "Papel")
    {
        ganador = minElement->first;
    }
    if (maxElement->first == "Piedra" && minElement->first == "Tijera")
    {
        ganador = maxElement->first;
    }
    if (maxElement->first == "Papel" && minElement->first == "Tijera")
    {
        ganador = minElement->first;
    }
    if (maxElement->first == "Papel" && minElement->first == "Piedra")
    {
        ganador = maxElement->first;
    }
    if (maxElement->first == "Tijera" && minElement->first == "Papel")
    {
        ganador = maxElement->first;
    }
    if (maxElement->first == "Tijera" && minElement->first == "Piedra")
    {
        ganador = minElement->first;
    }


    std::vector<Jugador> ganadores;
    for (auto &jugador : jugadores)
    {
        if (jugador.eleccion == ganador)
        {
            ganadores.push_back(jugador);
        }
    }
    return ganadores;
}

int main()
{
    // Crear jugadores
    const int numeroJugadores = 9;
    std::vector<Jugador> jugadores;
    for (int i = 0; i < numeroJugadores; i++)
    {
        jugadores.push_back(Jugador(std::to_string(i)));
    }

    // Ejemplo de uso
    bool jugando = true;
    while (jugando)
    {
        std::vector siguientes = determinarGanador(jugadores);
        if (siguientes.size() == 1)
        {
            jugando = false;
            auto g = siguientes.front();
            std::cout << "Ganador:J" << g.nombre << std::endl;
        }
        else
        {
            for (auto it = siguientes.begin(); it != siguientes.end(); ++it)
            {
                std::cout << "J" << it->nombre << ":" << it->eleccion << std::endl;
            }
            std::cout << "Siguen jugando:" << jugadores.size() << std::endl;
        }
        jugadores = siguientes;
    }
    return 0;
}
