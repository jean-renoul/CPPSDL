#include "Window.hpp"
#include <iostream>
#include <filesystem>

Window::Window() {
    window = new sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window->setFramerateLimit(144);
    if (!font.loadFromFile("../assets/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    setFont(font);
    int highScore = Score::readScore("Score.txt");
    this->highScore = highScore;
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
    sf::Text textValue;
    textValue.setFont(font);
    textValue.setString(std::to_string(tile->getValue()));
    textValue.setCharacterSize(100);
    textValue.setFillColor(sf::Color::Black);
    textValue.setPosition((tile->getX() + tile->getWidth() / 2) - textValue.getLocalBounds().width / 2, (tile->getY() + tile->getHeight() / 4));
    rectangle.setPosition(tile->getX(), tile->getY());
    rectangle.setFillColor(tile->getColor());
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    window->draw(rectangle);
    window->draw(textValue);
}

void Window::renderScore(int currentScore) {
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(currentScore));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(1000, 10);
    window->draw(text);
    text.setString("High Score: " + std::to_string(highScore));
    text.setPosition(1000, 60);
    window->draw(text);
}

void Window::renderGameOver(int currentScore) {
    sf::Text text;
    text.setFont(font);
    text.setString("Game Over! Your score : " + std::to_string(currentScore) + "\nPress the spacebar to exit");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setPosition(500, 500);
    window->draw(text);
}
