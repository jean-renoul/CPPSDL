#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "Tile.h"



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
};

#endif