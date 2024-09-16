#ifndef GAMESFML_HPP
#define GAMESFML_HPP

#include <vector>
#include "Window.hpp"
#include "Tile.hpp"
#include "Game.hpp"
#include "Animation.hpp"

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
