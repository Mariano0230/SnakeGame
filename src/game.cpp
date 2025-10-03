#include "game.hpp"
#include "food.hpp"
#include "snake.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

Game::Game(int width, int height)
    : width(width), height(height), currentDirection(Direction::Right), gameOver(false), score(0), rng(std::random_device{}()) {
    reset();
}
void Game::reset() {
    snake.clear();
    snake.push_back({width / 2, height / 2}); // Inicia la serpiente en el centro del tablero
    currentDirection = Direction::Right;
    gameOver = false;
    score = 0;
    spawnFood();
}
void Game::changeDirection(Direction dir) {
    // Evita que la serpiente se mueva en la dirección opuesta directamente
    if ((currentDirection == Direction::Up && dir != Direction::Down) ||
        (currentDirection == Direction::Down && dir != Direction::Up) ||
        (currentDirection == Direction::Left && dir != Direction::Right) ||
        (currentDirection == Direction::Right && dir != Direction::Left)) {
        currentDirection = dir;
    }
}
void Game::update() {
    if (gameOver) return;

    // Calcula la nueva posición de la cabeza de la serpiente
    auto head = snake.front();
    switch (currentDirection) {
        case Direction::Up:    head.second--; break;
        case Direction::Down:  head.second++; break;
        case Direction::Left:  head.first--;  break;
        case Direction::Right: head.first++;  break;
    }

    // Verifica colisiones con paredes o consigo misma
    if (checkCollision(head)) {
        gameOver = true;
        return;
    }

    // Mueve la serpiente
    snake.push_front(head);

    // Verifica si ha comido la comida
    if (head == food) {
        score += 10; // Incrementa la puntuación
        spawnFood(); // Genera nueva comida
    } else {
        snake.pop_back(); // Remueve la cola si no ha comido
    }
}
bool Game::isGameOver() const { // Verifica si el juego ha terminado
    return gameOver;
}
int Game::getScore() const { // Devuelve la puntuación actual
    return score;
}
const std::deque<std::pair<int, int>>& Game::getSnake() const { // Devuelve la posición de la serpiente
    return snake;
}
std::pair<int, int> Game::getFood() const { // Devuelve la posición de la comida
    return food;
}
