// #include <SFML/Graphics.hpp>
// #include "Game.h"
// #include "Window.hpp"

// int main()
// {
//     Game game;
//     game.playSFML();
//     return 0;
// }
#include <iostream>
#include "Game.h"

void showMenu() {
    std::cout << "       2048 Game         " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Jouer en mode texte" << std::endl;
    std::cout << "2. Jouer en mode graphique (SFML)" << std::endl;
    std::cout << "3. Quitter" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "Choisissez une option: ";
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Game game;
                game.play(); 
                break;
            }
            case 2: {
                Game game;
                game.playSFML(); 
                break;
            }
            case 3: {
                std::cout << "Merci d'avoir joué !" << std::endl;
                running = false;
                break;
            }
            default: {
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                break;
            }
        }
    }

    return 0;
}
