#include "Animation.hpp"

Animation::Animation(sf::Vector2f startPos, sf::Vector2f endPos, float duration) {
    this->startPos = startPos;
    this->endPos = endPos;
    this->duration = duration; // duration of the animation
    this->elapsedTime = 0;

    // Create a half transparent white rectangle to represent the tile
    tileShape.setSize(sf::Vector2f(200, 200));
    tileShape.setFillColor(sf::Color(254, 254, 254, 128));
    tileShape.setPosition(startPos);
}

// Update the position of the tile
bool Animation::update(float deltaTime) {
    elapsedTime += deltaTime;
    // If the animation is finished, set the position of the tile to the end position
    if (elapsedTime > duration) {
        tileShape.setPosition(endPos);
        return true;
    }

    // Calculate the position of the tile based on the elapsed time
    float t = elapsedTime / duration;
    float x = startPos.x + (endPos.x - startPos.x) * t;
    float y = startPos.y + (endPos.y - startPos.y) * t;
    tileShape.setPosition(x, y);
    return false;
}

sf::Vector2f Animation::getStartPos() {
    return startPos;
}

sf::Vector2f Animation::getEndPos() {
    return endPos;
}

sf::Vector2f Animation::getCurrentPosition() {
    float t = elapsedTime / duration;
    float x = startPos.x + (endPos.x - startPos.x) * t;
    float y = startPos.y + (endPos.y - startPos.y) * t;
    return sf::Vector2f(x, y);
}

sf::RectangleShape Animation::getTileShape() {
    return tileShape;
}