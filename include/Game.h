#ifndef GAME_H
#define GAME8H

#include "Tile.h"
#include <vector>

class Game {
public:   
    Game();
    void initialize();
    void printBoard() const;
    bool move(char direction);
    bool isGameOvr() const;
    void addReandomTile();

private:
    std::vector<std::vector<Tile>> board;
    bool gameOver;

    void slideleft();
    void slideRight();
    void slideUp();
    void slideDown();
    void mergeLeft();
    void mergeRight();
    void mergeUp();
    void mergeDown();
    bool canMove() const;
    void rotateBoard();
};
#endif // GAME_H



