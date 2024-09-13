#ifndef GAME_H
#define GAME_H
#include "consoleFunctions.h"
#include "sudokuGenerator.h"
#include "displayFunctions.h"
#include <vector>

class Game {
private:
    int score;
    int difficultyLevel;
public:
    int startGame();

    Game() {
        this->score = 0;
        this->difficultyLevel = 1;
    }

    ~Game() = default;
};


#endif
