#include "Tile.h"

Tile::Tile(int val) : value(val) {
    calculateColor();
}

int Tile::getValue() const {
    return value;
}

void Tile::setValue(int val) {
    value = val;
}

bool Tile::isEmpty() const {
    return value == 0;
}

void Tile::calculateColor() {
    color = sf::Color((value * 50) % 255, (value * 100) % 255, (value * 150) % 255);
    setColor(color);
}