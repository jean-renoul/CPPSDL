#ifndef TILE_HPP
#define TILE_HPP
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
