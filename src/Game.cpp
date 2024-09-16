#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

// Initialize the grid with two tiles in the constructor
Game::Game() {
    grid = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    srand(static_cast<unsigned int>(time(0)));
    spawnTile();
    spawnTile();
    this->score = 0;
    this->score = 0;
}

// Spawn a new tile with a value of 2 or 4
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

// Print the grid to the console
void Game::printGrid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << grid[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Move the tiles to the left
bool Game::moveLeft() {
    bool moved = false;
    for (int i = 0; i < 4; ++i) {
        int currentPos = 0;
        for (int j = 1; j < 4; ++j) {
            if (grid[i][j] != 0) {

                // If the current position is empty, move the tile to the left
                if (grid[i][currentPos] == 0) {
                    grid[i][currentPos] = grid[i][j];
                    grid[i][j] = 0;
                    moved = true;

                // If the current position is the same as the tile, merge the tiles
                } else if (grid[i][currentPos] == grid[i][j]) {
                    grid[i][currentPos] *= 2;
                    score += grid[i][currentPos];
                    score += grid[i][currentPos];
                    grid[i][j] = 0;
                    currentPos++;
                    moved = true;
                
                // If the current position is not empty and not the same as the tile, move the tile to the left
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

// Check if the game is over
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

// Main game loop
void Game::play() {
    char move;
    bool moved;
    
    while (canMove()) {
        printGrid();
        std::cout << "Enter move (z: up, s: down, q: left, d: right): ";
        std::cin >> move;
        
        switch (move) {
            case 'z': moved = moveUp(); break;
            case 's': moved = moveDown(); break;
            case 'q': moved = moveLeft(); break;
            case 'd': moved = moveRight(); break;
            default: moved = false;
        }
        
        if (moved) {
            spawnTile();
        }
    }
    
    std::cout << "Game Over!" << std::endl;
}