#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Window.hpp"
#include "Tile.h"

class Game {
private:
    std::vector<std::vector<int>> grid;
    void spawnTile();   
    bool moveLeft();    
    bool moveRight();   
    bool moveUp();      
    bool moveDown();    
    bool canMove();
    int score; 

public:
    Game();             
    void play();
    void playSFML();        
    void printGrid();
};

#endif 


