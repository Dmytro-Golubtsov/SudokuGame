#include <windows.h>
#include <cwchar>
#include "consoleFunctions.h"

using namespace std;

// Function to set the text and background color in the console
void setColor(Color text, Color background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// Function to set the cursor position in the console
void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x, y });
}

// Function to show or hide the console cursor
void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo); // Get current cursor info
    structCursorInfo.bVisible = show; // Set visibility
    structCursorInfo.dwSize = size; // Set size
    SetConsoleCursorInfo(hStdOut, &structCursorInfo); // Apply new cursor info
}

// Function to set the console font
void SetConsoleFont() {
    SetConsoleTitle("SUDOKU GAME");
    ConsoleCursorVisible(false);
    SetConsoleScreenBufferSize(hStdOut, COORD(50, 24)); // Set screen buffer size
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi); // Size of the structure
    cfi.nFont = 0; // Font number (0 for default)
    cfi.dwFontSize.X = 18; // Width of each character in the font
    cfi.dwFontSize.Y = 28; // Height of each character in the font
    cfi.FontFamily = FF_DONTCARE; // Font family
    cfi.FontWeight = FW_BOLD; // Font weight (bold)
    std::wcscpy(cfi.FaceName, L"Lucida Console"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi); // Apply font settings
}




