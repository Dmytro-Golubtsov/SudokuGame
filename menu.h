#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "consoleFunctions.h"
#include "globalVariables.h"
#include "menu.h"
#include <fstream>
#include "displayFunctions.h"


class menu {
private:
    int difficultyMenu();
    void displayRules();
    void displayScoreboard();
public:
    menu() {

    }
    ~menu() = default;

    int mainMenu();
};



#endif