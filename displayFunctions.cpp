#include "displayFunctions.h"

using namespace std;

void displayBorder(Color color = White, int lines = 16) {
    setColor(color);
    int posX = 10, posY = 2;
    GoToXY(posX, posY);
    cout << "*****************************" << endl;
    for (int i = 0; i < lines; ++i) {
        GoToXY(posX, ++posY);
        cout << "*                           *" << endl;
    }
    GoToXY(posX, ++posY);
    cout << "*****************************" << endl;
    setColor(White);
}

void displayProgress(int progress) {
    GoToXY(17, 16);
    cout << "PROGRESS: " << progress << "/81";
}

void displayErrors(int errors, bool isError) {
    if (isError) {
        GoToXY(19, 17);
        setColor(LightRed);
        cout << "ERRORS: " << errors << "/3";
        Sleep(1000);
        GoToXY(19, 17);
        setColor(White);
        cout << "ERRORS: " << errors << "/3";
    } else {
        GoToXY(19, 17);
        setColor(White);
        cout << "ERRORS: " << errors << "/3";
    }
}

void displayWin(int score, int time) {
    system("cls"); // Clear the console
    displayBorder(Yellow, 11);
    GoToXY(17, 7);
    cout << "Congratulations!";
    GoToXY(13, 8);
    cout << "You solved board in " << (int) (time / 60) << ":";
    if (time % 60 < 10)
        cout << '0';
    cout << time % 60;
    GoToXY(16, 9);
    cout << "Your score: " << score << "pts";
}

void displayLoose() {
    system("cls");
    displayBorder(LightRed, 10);
    GoToXY(20, 6);
    cout << "YOU LOOSE!";
    GoToXY(14, 7);
    cout << "BETTER LUCK NEXT TIME";
}

void displayBoard(vector<vector<int> > sudocu, int x, int y) {
    int posX = 14, posY = 4; // Starting position for the board

    for (int i = 0; i < 9; i++) {
        GoToXY(posX, posY);
        posY++;
        if (i == 3 || i == 6) {
            setColor(DarkGray);
            cout << "------+-------+------\n"; // Display board separators
            setColor(White);
            GoToXY(posX, posY++);
        }


        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                setColor(DarkGray);
                cout << "| "; // Display board separators
                setColor(White);
            }
            if (sudocu[i][j] == 0) {
                if (i == x && j == y)
                    setColor(Black, Green); // Highlight selected cell
                cout << " ";
                setColor(White, Black);
                cout << " ";
            } else {
                if (i == x && j == y)
                    setColor(Black, Green); // Highlight selected cell
                cout << sudocu[i][j];
                setColor(White, Black);
                cout << " ";
            }
            if (j == 8) {
                cout << "\n";
            }
        }
        cout << endl;
    }
}
