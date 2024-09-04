#include "Window.hpp"
#include <iostream>
#include <filesystem>

Window::Window() {
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    window = new sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window->setFramerateLimit(144);
    if (!font.loadFromFile("../assets/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    setFont(font);
}

Window::~Window() {
    delete window;
}

void Window::closeWindow() {
    window->close();
}

void Window::setFont(sf::Font font) {
    this->font = font;    
}

void Window::renderTiles(std::vector<std::vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            Tile tile(grid[i][j]);
            tile.setX(j * tile.getWidth());
            tile.setY(i * tile.getHeight());
            drawTile(&tile);
        }
    }
}

void Window::drawTile(Tile* tile) {
    sf::RectangleShape rectangle(sf::Vector2f(tile->getWidth(), tile->getHeight()));
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(tile->getValue()));
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Black);
    text.setPosition((tile->getX() + tile->getWidth() / 2) - text.getLocalBounds().width / 2, (tile->getY() + tile->getHeight() / 4));
    rectangle.setPosition(tile->getX(), tile->getY());
    rectangle.setFillColor(tile->getColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    window->draw(rectangle);
    window->draw(text);
}


