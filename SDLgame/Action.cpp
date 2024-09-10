#include "Action.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

Action::Action(Grid& g) : grid(g) {
    srand(static_cast<unsigned int>(time(0)));
}

void Action::slideAndMerge(std::vector<int>& line) {
    std::vector<int> newLine(line.size(), 0);
    int pos = 0;

    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] != 0) {
            if (pos > 0 && newLine[pos - 1] == line[i]) {
                newLine[pos - 1] *= 2;
            } else {
                newLine[pos++] = line[i];
            }
        }
    }

    line = newLine;
}

void Action::moveLeft() {
   
    for (int j = 0; j < grid.getGridSize(); ++j) {
        std::vector<int> column;
        for (int i = 0; i < grid.getGridSize(); ++i) {
            column.push_back(grid.getBlock(i, j).getValue());
        }
        slideAndMerge(column);
        for (int i = 0; i < grid.getGridSize(); ++i) {
            grid.setBlock(i, j, Bloc(column[i]));
        }
    }
}

void Action::moveRight() {
   
    for (int j = 0; j < grid.getGridSize(); ++j) {
        std::vector<int> column;
        for (int i = 0; i < grid.getGridSize(); ++i) {
            column.push_back(grid.getBlock(i, j).getValue());
        }
        std::reverse(column.begin(), column.end());
        slideAndMerge(column);
        std::reverse(column.begin(), column.end());
        for (int i = 0; i < grid.getGridSize(); ++i) {
            grid.setBlock(i, j, Bloc(column[i]));
        }
    }
}

void Action::moveUp() {
   
    for (int i = 0; i < grid.getGridSize(); ++i) {
        std::vector<int> row;
        for (int j = 0; j < grid.getGridSize(); ++j) {
            row.push_back(grid.getBlock(i, j).getValue());
        }
        slideAndMerge(row);
        for (int j = 0; j < grid.getGridSize(); ++j) {
            grid.setBlock(i, j, Bloc(row[j]));
        }
    }
}

void Action::moveDown() {
   
    for (int i = 0; i < grid.getGridSize(); ++i) {
        std::vector<int> row;
        for (int j = 0; j < grid.getGridSize(); ++j) {
            row.push_back(grid.getBlock(i, j).getValue());
        }
        std::reverse(row.begin(), row.end());
        slideAndMerge(row);
        std::reverse(row.begin(), row.end());
        for (int j = 0; j < grid.getGridSize(); ++j) {
            grid.setBlock(i, j, Bloc(row[j]));
        }
    }
}

void Action::addRandomBlock() {
    std::vector<std::pair<int, int>> emptyPositions;
    for (int i = 0; i < grid.getGridSize(); ++i) {
        for (int j = 0; j < grid.getGridSize(); ++j) {
            if (grid.getBlock(i, j).isEmpty()) {
                emptyPositions.push_back(std::make_pair(i, j));
            }
        }
    }

    if (!emptyPositions.empty()) {
        int index = rand() % emptyPositions.size();
        int value = (rand() % 10 == 0) ? 4 : 2;
        grid.setBlock(emptyPositions[index].first, emptyPositions[index].second, Bloc(value));
    }
}
