#pragma once

#include <utility> // para std::pair
#include <random>
#include "board.hpp"
#include "snake.hpp"

// Clase que representa la comida en el juego
class Food {
public:
    using Position = std::pair<int, int>; // Tipo para la posición de la comida

    // Constructor que recibe el tamaño del tablero
    Food(int boardWidth, int boardHeight)
        : width(boardWidth), height(boardHeight), rng(std::random_device{}()) {
        pos = {0, 0}; // Inicializa la posición de la comida
    }

    // Genera una nueva posición para la comida que no se superponga con la serpiente
    void spawn(const Snake& snake) {
        std::uniform_int_distribution<int> distX(0, width - 1);
        std::uniform_int_distribution<int> distY(0, height - 1);

        // Busca una posición aleatoria que no esté ocupada por la serpiente
        do {
            pos.first = distX(rng);
            pos.second = distY(rng);
        } while (snake.isOnPosition(pos));
    }

    // Devuelve la posición actual de la comida
    Position getPosition() const {
        return pos;
    }

private:
    int width, height;      // Dimensiones del tablero
    Position pos;           // Posición actual de la comida
    std::mt19937 rng;       // Generador de números aleatorios
};

#pragma once

#include <vector>
#include <utility>

// Clase que representa la serpiente en el juego
class Snake {
public:
    using Position = std::pair<int, int>;

    // ... otros métodos y miembros ...

    // Comprueba si la posición dada está ocupada por la serpiente
    bool isOnPosition(const Position& pos) const {
        for (const auto& segment : body) {
            if (segment == pos) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<Position> body; // segmentos de la serpiente
};