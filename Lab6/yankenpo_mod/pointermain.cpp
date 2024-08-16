#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

enum Eleg
{
    Piedra = 0,
    Papel = 1,
    Tijera = 2
};

struct Jugador
{
    Eleg valor;
    int nombre;
};

struct Resultados
{
    int NumeroJugadores;
    Jugador **jugadores;
};
Eleg generarEleccion()
{
    const std::string choices[] = {"Piedra", "Papel", "Tijera"};
    // Generar un índice aleatorio entre 0 y 2
    int index = std::rand() % 3;
    return static_cast<Eleg>(index);
}
// Función para determinar el ganador
Resultados determinarGanador(Jugador **jugadores, int arrayLength)
{
    int nameholder = 0;
    // Mapeo de elecciones a contadores
    std::map<Eleg, int> conteo;
    conteo[Piedra] = 0; // Piedra
    conteo[Papel] = 0;  // Papel
    conteo[Tijera] = 0; // Tijera

    // Contar las elecciones de cada jugador
    for (int i = 0; i < arrayLength; ++i)
    {
        Eleg el = generarEleccion();
        conteo[el]++;
        (*jugadores)[i].valor = el;
        (*jugadores)[i].nombre = nameholder;
        nameholder++;
    }
    nameholder = 0;
    if (conteo[Piedra] > 0 && conteo[Papel] > 0 && conteo[Tijera] > 0)
    {
        Resultados r = Resultados();
        r.NumeroJugadores = arrayLength;
        r.jugadores = new Jugador *[arrayLength];
        for (int i = 0; i < r.NumeroJugadores; ++i)
        {
            r.jugadores[i] = new Jugador();
            std::cout << "Valor antes de salir: J" <<(*jugadores)[i].nombre;
            r.jugadores[i]->nombre = nameholder;
            r.jugadores[i]->valor = (*jugadores)[i].valor;
            nameholder++;
        }
        return r;
    }
    for (auto it = conteo.begin(); it != conteo.end();)
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
    if (maxElement->second == minElement->second && maxElement->second > 1)
    {
        Resultados r = Resultados();
        r.NumeroJugadores = arrayLength;
        r.jugadores = new Jugador *[arrayLength];
        for (int i = 0; i < r.NumeroJugadores; ++i)
        {
            r.jugadores[i] = new Jugador();
            r.jugadores[i]->nombre = (*jugadores)[i].nombre;
            r.jugadores[i]->valor = (*jugadores)[i].valor;
        }
        return r;
    }
    Eleg ganador = Piedra;
    int numeroGanadores = 0;
    if (maxElement->first == Piedra && minElement->first == Papel)
    {
        ganador = minElement->first;
        numeroGanadores = minElement->second;
    }
    if (maxElement->first == Piedra && minElement->first == Papel)
    {
        ganador = maxElement->first;
        numeroGanadores = maxElement->second;
    }
    if (maxElement->first == Papel && minElement->first == Tijera)
    {
        ganador = minElement->first;
        numeroGanadores = minElement->second;
    }
    if (maxElement->first == Papel && minElement->first == Piedra)
    {
        ganador = maxElement->first;
        numeroGanadores = maxElement->second;
    }
    if (maxElement->first == Tijera && minElement->first == Papel)
    {
        ganador = maxElement->first;
        numeroGanadores = maxElement->second;
    }
    if (maxElement->first == Tijera && minElement->first == Piedra)
    {
        ganador = minElement->first;
        numeroGanadores = minElement->second;
    }

    Resultados r = Resultados();
    r.NumeroJugadores = numeroGanadores;
    r.jugadores = new Jugador *[numeroGanadores];
    for (int i = 0; i < numeroGanadores; i++)
    {
        for (int j = 0; j < arrayLength; j++)
        {
            if ((*jugadores)[j].valor == ganador)
            {
                if ((i - 1 >= 0) && (*r.jugadores)[i - 1].nombre == (*jugadores)[j].nombre)
                {
                    continue;
                }
                Jugador local = (*jugadores)[j];
                r.jugadores[i] = new Jugador();
                r.jugadores[i]->valor = local.valor;
                r.jugadores[i]->nombre = local.nombre;
                break;
            }
        }
    }
    return r;
}

int main()
{
    // Ejemplo de uso
    bool jugando = true;
    int numeroJugadores = 4;
    Jugador *jugadores[4];
    for (int i = 0; i < 4; ++i)
    {
        jugadores[i] = new Jugador();
        jugadores[i]->valor = Piedra;
        jugadores[i]->nombre = i;
        std::cout << "J" << jugadores[i]->nombre << std::endl;
    }
    while (jugando)
    {
        Resultados r = determinarGanador(jugadores, numeroJugadores);
        if (r.NumeroJugadores == 1)
        {
            jugando = false;
            Jugador g = (*r.jugadores)[0];
            std::cout << "Ganador:J" << g.nombre << std::endl;
        }
        else
        {
            for (int it = 0; it < r.NumeroJugadores; it++)
            {
                Jugador g = (*(r.jugadores))[it];
                std::cout << "J" << g.nombre << ":" << g.valor << std::endl;
            }
            std::cout << "Siguen jugando:" << r.NumeroJugadores << std::endl;
        }
        // Reordenar.
        for (int i = 0; i < r.NumeroJugadores; ++i)
        {
            jugadores[i] = r.jugadores[i];
        }
        numeroJugadores = r.NumeroJugadores;
    }
    return 0;
}
