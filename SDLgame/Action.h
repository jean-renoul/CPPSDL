#ifndef ACTION_H
#define ACTION_H

#include "Grid.h"
#include <vector>

class Action {
public:
    Action(Grid& g);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void addRandomBlock();

private:
    void slideAndMerge(std::vector<int>& line);
    Grid& grid;
};

#endif 
