#include "game.h"

#include "menu.h"

using namespace std;



int Game::startGame() {
    menu gameMenu;
    difficultyLevel = gameMenu.mainMenu();
    sudokuGenerator sudoku(difficultyLevel);
    displayBorder(Magenta, 20);// Display initial border
    displayProgress(sudoku.progress);// Display initial progress
    clock_t start = clock();// Start the timer
    int cursorX = 0, cursorY = 0;// Initial cursor position
    int score = 0;
    bool error = false;
    int error_counter = 0;
    char ch;
    bool endGame = false;
    displayBoard(sudoku.sudokuToSolve, 0, 0);// Display initial board
    displayErrors(0, false);// Display initial error count

    // Game loop
    while (!endGame) {
        ch = _getch();// Get keyboard input
        if (ch == -32) ch = _getch();// Handle arrow keys

        //keystroke handling (↑, ↓, →, ←, 1, 2, 3, 4, 5, 6, 7, 8, 9, s)
        switch (ch) {
            case UP_ARROW:
                if (cursorX > 0)// Move cursor
                    --cursorX;
                break;

            case DOWN_ARROW:
                if (cursorX < 8)// Move cursor
                    ++cursorX;
                break;

            case LEFT_ARROW:
                if (cursorY > 0)// Move cursor
                    --cursorY;
                break;

            case RIGHT_ARROW:
                if (cursorY < 8)// Move cursor
                    ++cursorY;
                break;

            case KB_ONE:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 1) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 1;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_TWO:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 2) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 2;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_THREE:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 3) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 3;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_FOUR:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 4) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 4;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_FIVE:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 5) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 5;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_SIX:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 6) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 6;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_SEVEN:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 7) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 7;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_EIGHT:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 8) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 8;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_NINE:
                if (sudoku.sudokuToSolve[cursorX][cursorY] == 0) {
                    if (sudoku.solvedSudoku[cursorX][cursorY] == 9) {
                        sudoku.sudokuToSolve[cursorX][cursorY] = 9;
                        sudoku.progress++;
                        displayProgress(sudoku.progress);// Update progress
                    } else {
                        error = true;
                    }
                }

                break;

            case KB_S:// Solve the board
                sudoku.sudokuToSolve = sudoku.solvedSudoku;
                sudoku.progress = 81;
                break;

            default:
                continue;
        }
        displayBoard(sudoku.sudokuToSolve, cursorX, cursorY);// Refresh the board

        if (error) {
            error_counter++;
            displayErrors(error_counter, error);// Display error message
            error = false;
            if (error_counter == 3) {
                displayLoose();// Display loose message if errors reach 3
                endGame = true;
            }
        }


        if (sudoku.progress == 81) {// Check if the board is fully solved
            endGame = true;
            clock_t end = clock();
            int timeS = (int) (end - start) / CLOCKS_PER_SEC;// Calculate time taken
            score = (500 - timeS)  * sudoku.difficulty;// Calculate score

            ofstream file("score.txt", ios::app);
            if (file) {
                file << score << endl;
            }
            file.close();

            displayWin(score, timeS);// Display win message
        }


        if (endGame) {// End game message
            setColor(DarkGray);
            GoToXY(5, 20);
            cout << "Press any key to return to the main menu";
            setColor(White);
            _getch();// Wait for key press
        }
    }
    // Return the final score
    return score;
}
