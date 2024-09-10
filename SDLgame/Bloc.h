#ifndef BLOC_H
#define BLOC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Bloc {
public:
    Bloc(int v = 0) : value(v) {}
    void setValue(int v) { value = v; }
    int getValue() const { return value; }
    bool isEmpty() const { return value == 0; }
    void draw(SDL_Renderer* renderer, TTF_Font* font, int x, int y, int width, int height) const;

private:
    int value;
    void drawNumber(SDL_Renderer* renderer, TTF_Font* font, int x, int y, int width, int height) const;
};

#endif 
