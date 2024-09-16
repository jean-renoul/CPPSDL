#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Bloc.h"
#include "Score.hpp" 

const int GRID_SIZE = 4;
const int CELL_SIZE = 100;

class Grid {
public:
    Grid();
    int getGridSize() const;
    Bloc getBlock(int row, int col) const;
    void setBlock(int row, int col, const Bloc& bloc);
    void render(SDL_Renderer* renderer, TTF_Font* font, Score& score); 
    int getHighScore() const;
private:
    void drawBlock(SDL_Renderer* renderer, int x, int y, int value, TTF_Font* font);
    SDL_Color getBlockColor(int value) const;
    Bloc blocks[GRID_SIZE][GRID_SIZE];
    int highScore; 
};

#endif