#pragma once //Previene inclusiones múltiples del archivo de encabezado

#include <vector> // Incluye la biblioteca vector
#include <utility>// Incluye la biblioteca utility para std::pair

class Board {
public:
    Board(int width, int height); // Constructor que inicializa el tablero con un ancho y alto dados

    int getWidth() const; // Devuelve el ancho del tablero
    int getHeight() const;// Devuelve el alto del tablero
    bool isInside(int x, int y) const;// Verifica si una posición (x, y) está dentro de los límites del tablero

    void draw() const;// Dibuja el tablero (implementación simple para consola)

private:
    int width;// Ancho del tablero
    int height;// Alto del tablero
};
