#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Score.hpp"



class Window {
    public:
        Window();
        ~Window();
        void setFont(sf::Font font);
        void renderTiles(std::vector<std::vector<int>> grid);
        void drawTile(Tile* tile);
        void closeWindow();
        sf::RenderWindow* window;
        sf::Font font;
        void renderScore(int currentScore);
        void renderGameOver(int currentScore);

    private:
        int highScore;
};

#endif