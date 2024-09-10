#include "Grid.h"
#include <SDL2/SDL_ttf.h>
#include <string>

Grid::Grid() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            blocks[i][j] = Bloc(0);
        }
    }
}

int Grid::getGridSize() const {
    return GRID_SIZE;
}

Bloc Grid::getBlock(int row, int col) const {
    return blocks[row][col];
}

void Grid::setBlock(int row, int col, const Bloc& bloc) {
    blocks[row][col] = bloc;
}

void Grid::render(SDL_Renderer* renderer, TTF_Font* font) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            drawBlock(renderer, i, j, blocks[i][j].getValue(), font);
        }
    }
}

void Grid::drawBlock(SDL_Renderer* renderer, int x, int y, int value, TTF_Font* font) {
    SDL_Rect cellRect = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };

 
    SDL_SetRenderDrawColor(renderer, getBlockColor(value).r, getBlockColor(value).g, getBlockColor(value).b, 255);
    SDL_RenderFillRect(renderer, &cellRect);

    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &cellRect);

    
    if (value != 0) {
        SDL_Color textColor = { 255, 255, 255, 255 }; 
        std::string text = std::to_string(value);

        SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textWidth = textSurface->w;
        int textHeight = textSurface->h;
        SDL_Rect textRect = { cellRect.x + (CELL_SIZE - textWidth) / 2, cellRect.y + (CELL_SIZE - textHeight) / 2, textWidth, textHeight };

        SDL_FreeSurface(textSurface);

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_DestroyTexture(textTexture);
    }
}

SDL_Color Grid::getBlockColor(int value) const {
    switch (value) {
        case 2:   return { 0x69, 0x69, 0x69, 255 }; // DimGray
        case 4:   return { 0xCD, 0x5C, 0x5C, 255 }; // IndianRed
        case 8:   return { 0xFF, 0x69, 0xB4, 255 }; // HotPink
        case 16:  return { 0x0, 0x64, 0x0, 255 }; // DarkGreen
        case 32:  return { 0x8B, 0x0, 0x8B, 255 }; // DarkMagenta
        case 64:  return { 0x8A, 0x2B, 0xE2, 255 }; // BlueViolet
        case 128: return { 0xD2, 0x69, 0x1E, 255 }; // Chocolate
        case 256: return { 0xB8, 0x86, 0xB, 255 }; // DarkGoldenrod
        case 512: return { 0xFF, 0x8C, 0x0, 255 }; // DarkOrange
        case 1024: return { 0xFF, 0xD7, 0x0, 255 }; // Gold
        case 2048: return { 0x80, 0x0, 0x0, 255 }; // Maroon
        default: return { 0xDD, 0xDD, 0xDD, 255 }; // Color default
    }
}
