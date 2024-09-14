#ifndef CONSOLE_FUNCTIONS_H
#define CONSOLE_FUNCTIONS_H

#include <iostream>
#include <windows.h>

using namespace std;

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue = 9, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

inline HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(Color text = White, Color background = Black);

void GoToXY(short x, short y);

void ConsoleCursorVisible(bool show, short size = 100);

void SetConsoleFont();


#endif
