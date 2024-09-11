#ifndef GAMESFML_HPP
#define GAMESFML_HPP

#include <vector>
#include "Window.hpp"
#include "Tile.h"
#include "Game.h"
#include "Animation.hpp"

class GameSFML : public Game {
    private:
        bool moveLeft() override;
        bool moveRight() override;
        bool moveUp() override;
        bool moveDown() override;

    public:
        GameSFML();
        void play() override;
};

#endif
