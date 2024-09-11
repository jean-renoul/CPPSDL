#ifndef GAMESFML_HPP
#define GAMESFML_HPP

#include <vector>
#include "Window.hpp"
#include "Tile.h"
#include "Game.h"

class GameSFML : public Game {
    private:
        bool moveLeft() override;
        bool moveRight() override;
        bool moveUp() override;
        bool moveDown() override;
        std::vector<Animation> animations;

    public:
        GameSFML();
        void play() override;
};

#endif
