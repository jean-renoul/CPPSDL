#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject {
    public:
    GameObject();
    ~GameObject();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setX(int x);
    void setY(int y);
    void setColor(sf::Color color);
    sf::Color getColor();

    
    protected:
    int x;
    int y;
    int width;
    int height;
    sf::RectangleShape rectangle;
    sf::Color color;
};

#endif