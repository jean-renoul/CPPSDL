#include "GameObject.hpp"

GameObject::GameObject() {
    x = 0;
    y = 0;
    width = 200;
    height = 200;
    color = sf::Color::White;
    rectangle = sf::RectangleShape(sf::Vector2f(width, height));
}

GameObject::~GameObject() {}

int GameObject::getX() {
    return x;
}

int GameObject::getY() {
    return y;
}

int GameObject::getWidth() {
    return width;
}

int GameObject::getHeight() {
    return height;
}

void GameObject::setX(int x) {
    this->x = x;
}

void GameObject::setY(int y) {
    this->y = y;
}

void GameObject::setColor(sf::Color color) {
    this->color = color;
}

sf::Color GameObject::getColor() {
    return color;
}