#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {
    private:
        sf::Vector2f startPos;
        sf::Vector2f endPos;
        float duration;
        float elapsedTime;
        sf::RectangleShape tileShape;
    
    public:
        Animation(sf::Vector2f startPos, sf::Vector2f endPos, float duration);
        bool update(float deltaTime);
        sf::Vector2f getStartPos();
        sf::Vector2f getEndPos();
        sf::Vector2f getCurrentPosition();
        sf::RectangleShape getTileShape();
};

#endif