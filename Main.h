#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include "Grid.h"
#include "Bloc.h"
#include "Action.h"

class Main {
public:
    Main();
    ~Main();
    void run();

private:
    Grid* grid;
    Bloc* bloc;
    Action* action;
    SDL_Window* fenetre;
    SDL_Renderer* renderer;

};

#endif 