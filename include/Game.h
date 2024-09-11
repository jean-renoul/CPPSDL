#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Window.hpp"
#include "Tile.h"

class Game {
protected:
    std::vector<std::vector<int>> grid;
    void spawnTile();   
    virtual bool moveLeft();    
    virtual bool moveRight();   
    virtual bool moveUp();      
    virtual bool moveDown();    
    bool canMove();
    int score; 

public:
    Game();             
    virtual void play();        
    void printGrid();
};

#endif 


