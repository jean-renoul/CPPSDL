#include "Animation.hpp"

Animation::Animation(sf::Vector2f startPos, sf::Vector2f endPos, float duration) {
    this->startPos = startPos;
    this->endPos = endPos;
    this->duration = duration;
    this->elapsedTime = 0;

    tileShape.setSize(sf::Vector2f(200, 200));
    tileShape.setFillColor(sf::Color(254, 254, 254, 128));

    tileShape.setPosition(startPos);
}

bool Animation::update(float deltaTime) {
    elapsedTime += deltaTime;
    if (elapsedTime > duration) {
        tileShape.setPosition(endPos);
        return true;
    }
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