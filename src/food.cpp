#include "food.hpp" // Incluye el archivo de cabecera de la clase Food
#include <cstdlib> // Incluye la biblioteca cstdlib para funciones de utilidad como rand()
#include <ctime>   // Incluye la biblioteca ctime para funciones relacionadas con el tiempo
Food::Food(int boardWidth, int boardHeight)
    : width(boardWidth), height(boardHeight), rng(std::random_device{}()) {
    pos = {0, 0}; // Inicializa la posición de la comida
}

// Genera una nueva posición para la comida que no se superponga con la serpiente
void Food::spawn(const Snake& snake) {
    std::uniform_int_distribution<int> distX(0, width - 1);
    std::uniform_int_distribution<int> distY(0, height - 1);

    // Busca una posición aleatoria que no esté ocupada por la serpiente
    do {
        pos.first = distX(rng);
        pos.second = distY(rng);
    } while (snake.isOnPosition(pos));
}