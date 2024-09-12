// #ifndef WINDOW_HPP
// #define WINDOW_HPP

// #include <SFML/Graphics.hpp>
// #include "Tile.h"
// #include "Score.hpp"



// class Window {
//     public:
//         Window();
//         ~Window();
//         void setFont(sf::Font font);
//         void renderTiles(std::vector<std::vector<int>> grid);
//         void drawTile(Tile* tile);
//         void closeWindow();
//         sf::RenderWindow* window;
//         sf::Font font;
//         void renderScore(int currentScore);
//         void renderGameOver(int currentScore);

//     private:
//         int highScore;
// };

// #endif
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>  // Ajout de l'inclusion pour la gestion de l'audio
#include "Tile.h"
#include "Score.hpp"
#include "Animation.hpp"

class Window {
    public:
        Window();
        ~Window();
        void setFont(sf::Font font);
        void renderTiles(std::vector<std::vector<int>> grid);
        void drawTile(Tile* tile);
        void closeWindow();
        void renderScore(int currentScore);
        void renderGameOver(int currentScore);
        void renderAnimations(std::vector<Animation> animations);

        sf::RenderWindow* window;  // La fenêtre de rendu SFML
        sf::Font font;             // Police d'écriture utilisée

    private:
        int highScore;             // Le score le plus élevé
        sf::Music backgroundMusic; // Musique de fond
};

#endif
