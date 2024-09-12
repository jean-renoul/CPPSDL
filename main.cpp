// #include <iostream>
// #include "Game.h"

// void showMenu() {
//     std::cout << "       2048 Game         " << std::endl;
//     std::cout << "=========================" << std::endl;
//     std::cout << "1. Jouer en mode texte" << std::endl;
//     std::cout << "2. Jouer en mode graphique (SFML)" << std::endl;
//     std::cout << "3. Quitter" << std::endl;
//     std::cout << "=========================" << std::endl;
//     std::cout << "Choisissez une option: ";
// }

// int main() {
//     int choice;
//     bool running = true;

//     while (running) {
//         showMenu();
//         std::cin >> choice;

//         switch (choice) {
//             case 1: {
//                 Game game;
//                 game.play(); 
//                 break;
//             }
//             case 2: {
//                 Game game;
//                 game.playSFML(); 
//                 break;
//             }
//             case 3: {
//                 std::cout << "Merci d'avoir joué !" << std::endl;
//                 running = false;
//                 break;
//             }
//             default: {
//                 std::cout << "Option invalide. Veuillez réessayer." << std::endl;
//                 break;
//             }
//         }
//     }

//     return 0;
// }
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Game.h"
#include "GameSFML.hpp"

void showMenu(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile("../assets/RowsofSunflowers.ttf")) {
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
        return;
    }

    sf::Text title("2048 Game", font, 50);
    title.setPosition(200, 50);

    sf::Text option1("1. Jouer en mode texte", font, 30);
    option1.setPosition(200, 150);

    sf::Text option2("2. Jouer en mode graphique (SFML)", font, 30);
    option2.setPosition(200, 250);

    sf::Text option3("3. Quitter", font, 30);
    option3.setPosition(200, 350);

    window.clear();
    window.draw(title);
    window.draw(option1);
    window.draw(option2);
    window.draw(option3);
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu 2048");
    bool running = true;

    while (running) {
        showMenu(window);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (mousePos.x >= 200 && mousePos.x <= 600 && mousePos.y >= 150 && mousePos.y <= 180) {
                        Game game;
                        game.play(); 
                    }

                    if (mousePos.x >= 200 && mousePos.x <= 600 && mousePos.y >= 250 && mousePos.y <= 280) {
                        GameSFML game;
                        game.play(); 
                    }

                    if (mousePos.x >= 200 && mousePos.x <= 600 && mousePos.y >= 350 && mousePos.y <= 380) {
                        std::cout << "Merci d'avoir joué !" << std::endl;
                        running = false;
                        window.close();
                    }
                }
            }
        }
    }

    return 0;
}
