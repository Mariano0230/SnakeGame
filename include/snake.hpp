#ifndef SNAKE_HPP //Verifica si no ha sido definido
#define SNAKE_HPP // Define SNAKE_HPP
#include <vector> // Incluye la biblioteca vector
#include <utility> // Incluye la biblioteca utility para std::pair

class Snake {
public:
    Snake(int startX, int startY); // Constructor que inicializa la serpiente en una posición dada
    void move(int deltaX, int deltaY); // Mueve la serpiente en una dirección dada
    void grow(); // Hace crecer la serpiente
    const std::vector<std::pair<int, int>>& getBody() const; // Devuelve el cuerpo de la serpiente
    bool checkSelfCollision() const; // Verifica si la serpiente se ha chocado a sí misma
private:
    std::vector<std::pair<int, int>> body; // Vector que almacena las posiciones del cuerpo de la serpiente
    int directionX; // Componente X de la dirección de movimiento
    int directionY; // Componente Y de la dirección de movimiento
    Snake();
};

#endif // SNAKE_HPP
