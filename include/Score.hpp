#ifndef SCORE_HPP
#define SCORE_HPP
#include <string>
#include <fstream>
#include <iostream>

class Score {
    public:
        static int readScore(std::string filename);
        static void writeScore(int score, std::string filename);
};

#endif