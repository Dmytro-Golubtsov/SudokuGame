#include "menu.h"


using namespace std;

void menu::displayRules() {
    system("cls"); // Clear the screen
    displayBorder(Magenta, 20); // Display a border with the specified color and size
    GoToXY(12, 5); // Move cursor to specific position
    cout << "Rule 1 - Each row must";
    GoToXY(13, 6);
    cout << "contain the numbers";
    GoToXY(13, 7);
    cout << "from 1 to 9, without";
    GoToXY(13, 8);
    cout << "repetitions";
    GoToXY(12, 11);
    cout << "Rule 2 - Each column must";
    GoToXY(13, 12);
    cout << "contain the numbers";
    GoToXY(13, 13);
    cout << "from 1 to 9, without";
    GoToXY(13, 14);
    cout <<"repetitions";
    GoToXY(12, 17);
    cout << "Rule 3 - The digits can";
    GoToXY(12, 18);
    cout << "only occur once per block";
    GoToXY(7,23);
    setColor(DarkGray); // Set text color
    cout << "Press any key to go back to main menu";
    setColor(White); // Reset text color to default

    _getch(); // Wait for a key press
    system("cls"); // Clear the screen again
}

// Function to display the main menu
int menu::mainMenu() {
    string menu[] = { "PLAY", "SCORE BOARD", "RULES", "EXIT" }; // Menu options
    int active_menu = 0; // Index of the currently active menu option
    char ch;
    system("cls"); // Clear the screen
    displayBorder(Magenta, 10); // Display a border with the specified color and size
    while (true) {
        int x = 21, y = 6;
        // Display menu options
        for (int i = 0; i < size(menu); i++) {
            if (active_menu == i)
                setColor(LightGreen); // Highlight the active menu option
            GoToXY(x, y++);
            cout << menu[i] << endl;
            setColor(White); // Reset text color to default
        }
        ch = _getch(); // Get a key press
        if (ch == -32) ch = _getch(); // Handle arrow keys
        switch (ch)
        {
            case ESC:
                exit(0); // Exit the program if ESC is pressed

            case UP_ARROW:
                if (active_menu > 0)
                    --active_menu; // Move up in the menu
            break;

            case DOWN_ARROW:
                if (active_menu < size(menu))
                    ++active_menu; // Move down in the menu
            break;

            case ENTER:
                if (active_menu == 0) {
                    int difficulty = difficultyMenu(); // Go to the difficulty menu
                    if (!(difficulty < 1 || difficulty > 3))
                        return difficulty; // Return the chosen difficulty
                } else if (active_menu == 1) {

                } else if (active_menu == 2) {
                    displayRules(); // Display the rules
                    displayBorder(Magenta, 10); // Display the border again after showing the rules
                } else if (active_menu == 3) {
                    exit(0); // Exit the program
                }
            break;
        }
    }
}

// Function to display the difficulty menu
int menu::difficultyMenu() {
    string menu[] = { "EASY", "MEDIUM", "HARD",  "EXIT" }; // Menu options for difficulty levels
    int active_menu = 0; // Index of the currently active menu option
    char ch;
    system("cls"); // Clear the screen
    displayBorder(Magenta, 10); // Display a border with the specified color and size
    while (true) {
        int x = 21, y = 6;
        // Display menu options
        for (int i = 0; i < size(menu); i++) {
            if (active_menu == i)
                setColor(LightGreen); // Highlight the active menu option
            GoToXY(x, y++);
            cout << menu[i] << endl;
            setColor(White); // Reset text color to default
        }
        ch = _getch(); // Get a key press
        if (ch == -32) ch = _getch(); // Handle arrow keys
        switch (ch)
        {
            case ESC:
                exit(0); // Exit the program if ESC is pressed

            case UP_ARROW:
                if (active_menu > 0)
                    --active_menu; // Move up in the menu
            break;

            case DOWN_ARROW:
                if (active_menu < size(menu))
                    ++active_menu; // Move down in the menu
            break;

            case ENTER:
                if (active_menu >= 0 && active_menu <= 2)
                    return active_menu+1; // Return the chosen difficulty level (1-based index)
                else exit(0); // Exit the program
        }
    }
    return 0; // Return 0 as a default (though this should not be reached)
}


void menu::displayScoreboard() {
    ifstream file;
}
