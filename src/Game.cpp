#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Game.h"

Game::Game() {
    grid = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    srand(static_cast<unsigned int>(time(0)));
    spawnTile();
    spawnTile();
    this->score = 0;
}

void Game::spawnTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 0) {
                emptyTiles.push_back({i, j});
            }
        }
    }

    if (!emptyTiles.empty()) {
        int randIndex = rand() % emptyTiles.size();
        int randValue = (rand() % 2 + 1) * 2; // 2 or 4
        grid[emptyTiles[randIndex].first][emptyTiles[randIndex].second] = randValue;
    }
}

void Game::printGrid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << grid[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool Game::moveLeft() {
    bool moved = false;
    for (int i = 0; i < 4; ++i) {
        int currentPos = 0;
        for (int j = 1; j < 4; ++j) {
            if (grid[i][j] != 0) {
                if (grid[i][currentPos] == 0) {
                    grid[i][currentPos] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                } else if (grid[i][currentPos] == grid[i][j]) {
                    grid[i][currentPos] *= 2;
                    score += grid[i][currentPos];
                    grid[i][j] = 0;
                    currentPos++;
                    moved = true;
                } else {
                    currentPos++;
                    if (currentPos != j) {
                        grid[i][currentPos] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}

bool Game::moveRight() {
    bool moved = false;
    for (int i = 0; i < 4; ++i) {
        int currentPos = 3;
        for (int j = 2; j >= 0; --j) {
            if (grid[i][j] != 0) {
                if (grid[i][currentPos] == 0) {
                    grid[i][currentPos] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                } else if (grid[i][currentPos] == grid[i][j]) {
                    grid[i][currentPos] *= 2;
                    score += grid[i][currentPos];
                    grid[i][j] = 0;
                    currentPos--;
                    moved = true;
                } else {
                    currentPos--;
                    if (currentPos != j) {
                        grid[i][currentPos] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}

bool Game::moveUp() {
    bool moved = false;
    for (int j = 0; j < 4; ++j) {
        int currentPos = 0;
        for (int i = 1; i < 4; ++i) {
            if (grid[i][j] != 0) {
                if (grid[currentPos][j] == 0) {
                    grid[currentPos][j] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                } else if (grid[currentPos][j] == grid[i][j]) {
                    grid[currentPos][j] *= 2;
                    score += grid[currentPos][j];
                    grid[i][j] = 0;
                    currentPos++;
                    moved = true;
                } else {
                    currentPos++;
                    if (currentPos != i) {
                        grid[currentPos][j] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}

bool Game::moveDown() {
    bool moved = false;
    for (int j = 0; j < 4; ++j) {
        int currentPos = 3;
        for (int i = 2; i >= 0; --i) {
            if (grid[i][j] != 0) {
                if (grid[currentPos][j] == 0) {
                    grid[currentPos][j] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;
                } else if (grid[currentPos][j] == grid[i][j]) {
                    grid[currentPos][j] *= 2;
                    score += grid[currentPos][j];
                    grid[i][j] = 0;
                    currentPos--;
                    moved = true;
                } else {
                    currentPos--;
                    if (currentPos != i) {
                        grid[currentPos][j] = grid[i][j];
                        grid[i][j] = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}

bool Game::canMove() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 0) return true;
            if (j < 3 && grid[i][j] == grid[i][j + 1]) return true;
            if (i < 3 && grid[i][j] == grid[i + 1][j]) return true;
        }
    }
    return false;
}

void Game::play() {
    char move;
    bool moved;
    
    while (canMove()) {
        printGrid();
        std::cout << "Enter move (w: up, s: down, a: left, d: right): ";
        std::cin >> move;
        
        switch (move) {
            case 'w': moved = moveUp(); break;
            case 's': moved = moveDown(); break;
            case 'a': moved = moveLeft(); break;
            case 'd': moved = moveRight(); break;
            default: moved = false;
        }
        
        if (moved) {
            spawnTile();
        }
    }
    
    std::cout << "Game Over!" << std::endl;
}

void Game::playSFML() {
    Window window;
    window.window->setFramerateLimit(60);
    
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
                    case sf::Keyboard::S: moved = moveDown(); break;
                    case sf::Keyboard::Q: moved = moveLeft(); break;
                    case sf::Keyboard::D: moved = moveRight(); break;
                    default: moved = false;
                }
                
                if (moved) {
                    spawnTile();
                }
            }
        }
        
        window.window->clear();
        window.renderTiles(grid);
        window.renderScore(score);
        window.window->display();
    }

    Score::writeScore(score, "Score.txt");
    window.renderGameOver();
}