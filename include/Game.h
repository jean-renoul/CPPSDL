#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {
private:
    std::vector<std::vector<int>> grid;  
    void spawnTile();   
    bool moveLeft();    
    bool moveRight();   
    bool moveUp();      
    bool moveDown();    
    bool canMove();     

public:
    Game();             
    void play();        
    void printGrid();   
};

#endif 


