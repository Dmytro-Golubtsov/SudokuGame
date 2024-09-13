#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H

#include "sudokuGrid.h"
#include <random>
#include <functional>
#include <algorithm>
#include <windows.h>
#include <conio.h>

class sudokuGenerator : public sudokuGrid {
private:
    void transposeMatrix(vector<vector<int> > &matrix);

    void swapRowsSmall(vector<vector<int> > &table);

    void swapColumnsSmall(vector<vector<int> > &matrix);

    void swapRowsArea(vector<vector<int> > &table);

    void swapColumnsArea(vector<vector<int> > &matrix);

    void mix(vector<vector<int> > &table, int amt = 20);

    void generatePuzzle(int difficulty = 40);

public:
    sudokuGenerator(): sudokuGrid() {
        this->difficulty = 1;
        this->progress = 0;
        this->sudokuToSolve = getGrid();
        this->solvedSudoku = getGrid();
        generatePuzzle(difficulty);
    }

    sudokuGenerator(int difficulty): sudokuGrid() {
        this->difficulty = difficulty;
        this->progress = 0;
        this->sudokuToSolve = getGrid();
        this->solvedSudoku = getGrid();
        generatePuzzle(difficulty);
    }

    int progress;
    int difficulty;
    vector<vector<int> > sudokuToSolve;
    vector<vector<int> > solvedSudoku;

    void shuffleSudoku();

    vector<vector<int> > getSolvedSudoku();

    vector<vector<int> > getSudokuToSolve();
};


#endif //SUDOKUGENERATOR_H
