#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>
#include "Grid.h"
#include "Action.h"

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("2048 Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

   
    TTF_Font* font = TTF_OpenFont("C:/Users/micka/Documents/Dev/C++/Games/2048/SDLgame/Fonts/InriaSans-BoldItalic.ttf", 24);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }

    Grid grid;
    Action action(grid);

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        action.moveLeft();
                        break;
                    case SDLK_RIGHT:
                        action.moveRight();
                        break;
                    case SDLK_UP:
                        action.moveUp();
                        break;
                    case SDLK_DOWN:
                        action.moveDown();
                        break;
                }
                action.addRandomBlock();
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        grid.render(renderer, font);  

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
