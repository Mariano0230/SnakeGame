#pragma once

#include <vector>
#include <deque>
#include <utility>
#include <random>

enum class Direction { Up, Down, Left, Right }; // Dirección de movimiento de la serpiente

class Game {
public:
    Game(int width, int height); // Constructor que inicializa el juego con el tamaño del tablero

    void reset(); // Reinicia el juego
    void changeDirection(Direction dir); // Cambia la dirección de la serpiente
    void update(); // Actualiza el estado del juego (mueve la serpiente, verifica colisiones, etc.)
    bool isGameOver() const; // Verifica si el juego ha terminado
    int getScore() const; // Devuelve la puntuación actual
    const std::deque<std::pair<int, int>>& getSnake() const; // Devuelve la posición de la serpiente
    std::pair<int, int> getFood() const; // Devuelve la posición de la comida
    int getWidth() const; // Devuelve el ancho del tablero
    int getHeight() const; // Devuelve la altura del tablero

private:
    void spawnFood(); // Genera una nueva posición para la comida
    bool checkCollision(const std::pair<int, int>& pos) const; // Verifica si la serpiente colisiona con algo

    int width, height; // Dimensiones del tablero
    std::deque<std::pair<int, int>> snake; // Cuerpo de la serpiente
    Direction currentDirection; // Dirección actual de la serpiente
    std::pair<int, int> food; // Posición de la comida
    bool gameOver; // Estado del juego
    int score; // Puntuación del jugador
    std::mt19937 rng; // Generador de números aleatorios
};