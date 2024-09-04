#ifndef TILE_H
#define TILE_H
#include "GameObject.hpp"

class Tile : public GameObject {
private:
    int value;

public:
    Tile(int val = 0);  
    
    int getValue() const;
    void setValue(int val);
    bool isEmpty() const;
    void calculateColor();
};

#endif 
