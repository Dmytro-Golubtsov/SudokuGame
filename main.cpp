#include <iostream>
#include "game.h"
#include "greetings.h"

int main()
{
    SetConsoleFont();
    system("cls");

    Game game;
    greetings();
    while (true) {
        int score = game.startGame();
    }
    return 0;
}
