#include "Bloc.h"
#include <string>

void Bloc::draw(SDL_Renderer* renderer, TTF_Font* font, int x, int y, int width, int height) const {
   
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &rect);

   
    if (!isEmpty()) {
        drawNumber(renderer, font, x, y, width, height);
    }
}

void Bloc::drawNumber(SDL_Renderer* renderer, TTF_Font* font, int x, int y, int width, int height) const {
   
    std::string numberStr = std::to_string(value);

    
    SDL_Color textColor = {0, 0, 0}; 

   
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, numberStr.c_str(), textColor);
    if (textSurface == nullptr) {
       
        return;
    }

   
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);

    
    SDL_Rect textRect;
    textRect.x = x + (width - textWidth) / 2;
    textRect.y = y + (height - textHeight) / 2;
    textRect.w = textWidth;
    textRect.h = textHeight;

 
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    
    SDL_DestroyTexture(textTexture);
}
