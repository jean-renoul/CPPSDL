#include "Tile.h"

Tile::Tile(int value) : value(value) {
    
}

int Tile::getValue() const {
    return value;
}

void Tile::setValue(int value) {
    this->value = value;
}
