#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "GameSFML.hpp"

// Initialize the grid with two tiles in the constructor
GameSFML::GameSFML() : Game() {
    grid = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    srand(static_cast<unsigned int>(time(0)));
    spawnTile();
    spawnTile();
    this->score = 0;
}

// Move the tiles to the left
bool GameSFML::moveLeft() {
    bool moved = false;
    int tileSize = 200;

    for (int i = 0; i < 4; ++i) {
        int currentPos = 0;
        for (int j = 1; j < 4; ++j) {
            if (grid[i][j] != 0) {
                sf::Vector2f startPos(j * tileSize, i * tileSize);
                sf::Vector2f endPos(currentPos * tileSize, i * tileSize);

                // If the current position is empty, move the tile to the left
                if (grid[i][currentPos] == 0) {
                    grid[i][currentPos] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                    // Add the animation to the list of animations if the tile moved
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                // If the current position is the same as the tile, merge the tiles
                } else if (grid[i][currentPos] == grid[i][j]) {
                    grid[i][currentPos] *= 2;
                    score += grid[i][currentPos];
                    grid[i][j] = 0;
                    currentPos++;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                // If the current position is not empty and not the same as the tile, move the tile to the left
                } else {
                    currentPos++;
                    if (currentPos != j) {
                        sf::Vector2f newEndPos(currentPos * tileSize, i * tileSize);
                        grid[i][currentPos] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                        if (startPos != endPos) {
                            animations.push_back(Animation(startPos, endPos, 0.2f));
                        }
                    }
                }
            }
        }
    }
    return moved;
}

// Move the tiles to the right, same logic as moveLeft but in reverse
bool GameSFML::moveRight() {
    bool moved = false;
    int tileSize = 200;

    for (int i = 0; i < 4; ++i) {
        int currentPos = 3;
        for (int j = 2; j >= 0; --j) {
            if (grid[i][j] != 0) {
                sf::Vector2f startPos(j * tileSize, i * tileSize);
                sf::Vector2f endPos(currentPos * tileSize, i * tileSize);

                if (grid[i][currentPos] == 0) {
                    grid[i][currentPos] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                } else if (grid[i][currentPos] == grid[i][j]) {
                    grid[i][currentPos] *= 2;
                    score += grid[i][currentPos];
                    grid[i][j] = 0;
                    currentPos--;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                } else {
                    currentPos--;
                    if (currentPos != j) {
                        sf::Vector2f newEndPos(currentPos * tileSize, i * tileSize);
                        grid[i][currentPos] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                        if (startPos != endPos) {
                            animations.push_back(Animation(startPos, endPos, 0.2f));
                        }
                    }
                }
            }
        }
    }
    return moved;
}

bool GameSFML::moveUp() {
    bool moved = false;
    int tileSize = 200;

    for (int j = 0; j < 4; ++j) {
        int currentPos = 0;
        for (int i = 1; i < 4; ++i) {
            if (grid[i][j] != 0) {
                sf::Vector2f startPos(j * tileSize, i * tileSize);
                sf::Vector2f endPos(j * tileSize, currentPos * tileSize);


                if (grid[currentPos][j] == 0) {
                    grid[currentPos][j] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                } else if (grid[currentPos][j] == grid[i][j]) {
                    grid[currentPos][j] *= 2;
                    score += grid[currentPos][j];
                    grid[i][j] = 0;
                    currentPos++;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                } else {
                    currentPos++;
                    if (currentPos != i) {
                        sf::Vector2f newEndPos(j * tileSize, currentPos * tileSize);
                        grid[currentPos][j] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                        if (startPos != endPos) {
                            animations.push_back(Animation(startPos, endPos, 0.2f));
                        }
                    }
                }
            }
        }
    }
    return moved;
}

bool GameSFML::moveDown() {
    bool moved = false;
    int tileSize = 200;

    for (int j = 0; j < 4; ++j) {
        int currentPos = 3;
        for (int i = 2; i >= 0; --i) {
            if (grid[i][j] != 0) {
                sf::Vector2f startPos(j * tileSize, i * tileSize);
                sf::Vector2f endPos(j * tileSize, currentPos * tileSize);

                if (grid[currentPos][j] == 0) {
                    grid[currentPos][j] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                } else if (grid[currentPos][j] == grid[i][j]) {
                    grid[currentPos][j] *= 2;
                    score += grid[currentPos][j];
                    grid[i][j] = 0;
                    currentPos--;
                    moved = true;
                    if (startPos != endPos) {
                        animations.push_back(Animation(startPos, endPos, 0.2f));
                    }

                } else {
                    currentPos--;
                    if (currentPos != i) {
                        sf::Vector2f newEndPos(j * tileSize, currentPos * tileSize);
                        grid[currentPos][j] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                        if (startPos != endPos) {
                            animations.push_back(Animation(startPos, endPos, 0.2f));
                        }
                    }
                }
            }
        }
    }
    return moved;
}

// Game loop
void GameSFML::play() {
    Window window;
    window.window->setFramerateLimit(60);
    
    // Event loop
    while (window.window->isOpen() && canMove()) {
        sf::Event event;
        while (window.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.window->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                bool moved;
                switch (event.key.code) {
                    case sf::Keyboard::Z: moved = moveUp(); break;
                    case sf::Keyboard::Up: moved = moveUp(); break;

                    case sf::Keyboard::S: moved = moveDown(); break;
                    case sf::Keyboard::Down: moved = moveDown(); break;
                    
                    case sf::Keyboard::Q: moved = moveLeft(); break;
                    case sf::Keyboard::Left: moved = moveLeft(); break;

                    case sf::Keyboard::D: moved = moveRight(); break;
                    case sf::Keyboard::Right: moved = moveRight(); break;

                    default: moved = false;
                }
                
                if (moved) {
                    spawnTile();
                }
            }
        }
        
        // We start by rendering the tiles and the score then we render the animations
        window.window->clear();
        window.renderTiles(grid);
        window.renderScore(score);

        for (auto it = animations.begin(); it != animations.end();) {
            if (it->update(1.0f / 60.0f)) {
                it = animations.erase(it);
            } else {
                ++it;
            }    
    }
    window.renderAnimations(animations);
    window.window->display();
    }

    // Game over screen
    bool isKeyPressed = false;

    while (window.window->isOpen() && !isKeyPressed) {
        sf::Event event;
        while (window.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.window->close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                isKeyPressed = true;
            }
        }
        
        window.window->clear();
        window.renderGameOver(score);
        window.window->display();
    }
    // Write the score to a file and close the window
    Score::writeScore(score, "Score.txt");
    window.window->close();

}