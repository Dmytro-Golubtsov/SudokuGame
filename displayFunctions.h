#ifndef DISPLAYFUNCTIONS_H
#define DISPLAYFUNCTIONS_H
#include "consoleFunctions.h"
#include <vector>

void displayBorder(Color color, int lines);
void displayProgress(int progress);
void displayErrors(int errors, bool isError);
void displayWin(int score, int time);
void displayLoose();
void displayBoard(vector<vector<int> > sudocu, int x, int y);
#endif
