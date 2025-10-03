#include "board.hpp" // Incluye el archivo de cabecera de la clase Board
#include <iostream> // Incluye la biblioteca iostream para entrada y salida
Board::Board(int width, int height) : width(width), height(height) {}
int Board::getWidth() const {
    return width; // Devuelve el ancho del tablero
}
int Board::getHeight() const {
    return height; // Devuelve el alto del tablero
}
bool Board::isInside(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height; // Verifica si (x, y) está dentro de los límites del tablero
}
void Board::draw() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << "."; // Dibuja un punto para cada celda del tablero
        }
        std::cout << std::endl; // Nueva línea al final de cada fila
    }
}
