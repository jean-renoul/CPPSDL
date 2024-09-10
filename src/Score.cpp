#include "Score.hpp"
#include <filesystem>
#include <iostream>
#include <direct.h>

int Score::readScore(std::string filename) {
    int highScore = 0;
    // Check if the file exists
    if (!std::filesystem::exists(filename)) {
        std::ofstream file(filename);
    }
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 0;
    }
    // Check the file is not empty
    if (file.peek() == std::ifstream::traits_type::eof()) {
        file.close();
        return 0;
    }
    file >> highScore;
    file.close();
    return highScore;
}

void Score::writeScore(int score, std::string filename) {
    int highScore = Score::readScore(filename);
    if (score > highScore) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }
        file << score;
        file.close();
    }
}