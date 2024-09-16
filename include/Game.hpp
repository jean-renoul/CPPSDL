#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Window.hpp"
#include "Tile.hpp"
#include "Window.hpp"

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






