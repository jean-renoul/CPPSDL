#ifndef TILE_H
#define TILE_H

class Tile {
public:
    Tile(int velue = 0);
    int getValue() const;
    void setValue(int value);

private:
    int value;
};

#endif