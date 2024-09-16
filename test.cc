#include <gtest/gtest.h>
#include "Score.hpp"

TEST(ScoreTest, ReadScore) {
    Score score;
    int highScore = score.readScore("bin/Score.txt");
    EXPECT_EQ(highScore, 0);
}

TEST(ScoreTest, WriteScore) {
    Score score;
    score.writeScore(100, "bin/Score.txt");
    int highScore = score.readScore("bin/Score.txt");
    EXPECT_EQ(highScore, 100);
}