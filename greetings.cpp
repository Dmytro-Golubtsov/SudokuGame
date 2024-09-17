#include "greetings.h"
#include "consoleFunctions.h"
#include <iostream>

using namespace std;

/*
 SSSS  U   U  DDDD   OOO  K   K  U   U
S      U   U  D   D O   O K  K   U   U
 SSS   U   U  D   D O   O KKK    U   U
    S  U   U  D   D O   O K  K   U   U
SSSS    UUU   DDDD   OOO  K   K   UUU
 */

// Function to display the greetings screen
void greetings() {
    // Clear the screen
    system("cls");

    // Set initial position for the text
    int posX = 4, posY = 7;

    // Display border and the text line by line with specific colors
    GoToXY(posX, posY++);
    setColor(Magenta);
    cout << "********************************************";
    GoToXY(posX, posY++);
    cout << "*                                          *";
    GoToXY(posX, posY++);
    cout << "*  ";
    setColor(LightGreen);
    cout << " SSSS  U   U  DDDD   OOO  K   K  U   U";
    setColor(Magenta);
    cout << "  *";
    GoToXY(posX, posY++);
    cout << "*  ";
    setColor(LightGreen);
    cout << "S      U   U  D   D O   O K  K   U   U";
    setColor(Magenta);
    cout << "  *";
    GoToXY(posX, posY++);
    cout << "*  ";
    setColor(LightGreen);
    cout << " SSS   U   U  D   D O   O KKK    U   U";
    setColor(Magenta);
    cout << "  *";
    GoToXY(posX, posY++);
    cout << "*  ";
    setColor(LightGreen);
    cout << "    S  U   U  D   D O   O K  K   U   U";
    setColor(Magenta);
    cout << "  *";
    GoToXY(posX, posY++);
    cout << "*  ";
    setColor(LightGreen);
    cout << "SSSS    UUU   DDDD   OOO  K   K   UUU ";
    setColor(Magenta);
    cout << "  *";
    GoToXY(posX, posY++);
    cout << "*                                          *";
    GoToXY(posX, posY++);
    cout << "********************************************";
    posY++;

    // Display the author's name in dark gray color
    setColor(DarkGray);
    GoToXY(posX+7, posY+1);

    linkedList createdBy;
    createdBy.push_back("Created");
    createdBy.push_back("by");
    createdBy.push_back("Dmytro");
    createdBy.push_back("Golubtsov");
    createdBy.print();

    // Reset the color to white
    setColor(White);

    // Pause for 3 seconds to allow the user to read the message
    Sleep(3000);
}
