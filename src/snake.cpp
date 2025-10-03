#include "snake.hpp" // Incluye el archivo de cabecera de la clase Snake
#include <cstddef>
Snake::Snake(): directionX(0), directionY(0) {
    body.push_back({5, 5}); // Inicializa la serpiente en la posición (5, 5)
}
void Snake::move(int deltaX, int deltaY) {
    directionX = deltaX; // Actualiza la dirección X
    directionY = deltaY; // Actualiza la dirección Y
    for (size_t i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1]; // Mueve cada segmento del cuerpo a la posición del segmento anterior
    }
    body[0].first += directionX; // Mueve la cabeza en la dirección X
    body[0].second += directionY; // Mueve la cabeza en la dirección Y
}
void Snake::grow() {
    body.push_back(body.back()); // Añade un nuevo segmento al final del cuerpo en la posición del último segmento
}
const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body; // Devuelve una referencia constante al vector que almacena el cuerpo de la serpiente
}
bool Snake::checkSelfCollision() const {
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[0] == body[i]) {
            return true; // Si la cabeza colisiona con cualquier otro segmento del cuerpo, devuelve true
        }
    }
    return false; // No hay colisión
}
