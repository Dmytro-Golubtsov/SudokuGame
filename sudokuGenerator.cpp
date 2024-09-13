#include "sudokuGenerator.h"
#include <iostream>

const int n3 = 3;

// Function to transpose the matrix
void sudokuGenerator::transposeMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result(cols, vector<int>(rows));

    // Transpose the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }

    // Copy the transposed matrix back to the original
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = result[i][j];
        }
    }
}

// Function to swap two small rows within the same area
void sudokuGenerator::swapRowsSmall(vector<vector<int>> &table) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist_area(0, n3 - 1);
    uniform_int_distribution<int> dist_line(0, n3 - 1);

    int area = dist_area(gen);
    int line1 = dist_line(gen);

    int N1 = area * n3 + line1;

    int line2 = dist_line(gen);
    while (line1 == line2) {
        line2 = dist_line(gen);
    }

    int N2 = area * n3 + line2;

    swap(table[N1], table[N2]);
}

// Function to swap two small columns within the same area
void sudokuGenerator::swapColumnsSmall(vector<vector<int>> &matrix) {
    transposeMatrix(matrix);
    swapRowsSmall(matrix);
    transposeMatrix(matrix);
}

// Function to swap two row areas
void sudokuGenerator::swapRowsArea(vector<vector<int>> &table) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist_area(0, n3 - 1);

    int area1 = dist_area(gen);
    int area2 = dist_area(gen);
    while (area1 == area2) {
        area2 = dist_area(gen);
    }

    // Swap the rows in the two areas
    for (int i = 0; i < n3; ++i) {
        int N1 = area1 * n3 + i;
        int N2 = area2 * n3 + i;
        swap(table[N1], table[N2]);
    }
}

// Function to swap two column areas
void sudokuGenerator::swapColumnsArea(vector<vector<int>> &matrix) {
    transposeMatrix(matrix);
    swapRowsArea(matrix);
    transposeMatrix(matrix);
}

// Function to mix the Sudoku grid
void sudokuGenerator::mix(vector<vector<int>> &table, int amt) {
    vector<function<void()>> mixFuncs = {
        [this, &table]() { transposeMatrix(table); },
        [this, &table]() { swapRowsSmall(table); },
        [this, &table]() { swapColumnsSmall(table); },
        [this, &table]() { swapRowsArea(table); },
        [this, &table]() { swapColumnsArea(table); }
    };

    random_device rd;
    mt19937 g(rd());
    srand(static_cast<unsigned int>(time(nullptr)));
    int randI = 3000 + rand() % 1500;

    // Randomly apply mixing functions
    for (int i = 0; i < randI; ++i) {
        shuffle(mixFuncs.begin(), mixFuncs.end(), g);
        mixFuncs[0]();
    }
}

// Function to generate a complete Sudoku puzzle
void sudokuGenerator::shuffleSudoku() {
    vector<vector<int>> grid = sudokuToSolve;
    mix(sudokuToSolve);
    solvedSudoku = sudokuToSolve;
}

void sudokuGenerator::generatePuzzle(int difficulty) {
    shuffleSudoku();
    // Создаем копию решенного поля, которое будем модифицировать
    vector<vector<int>> puzzle = solvedSudoku;

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    int size = puzzle.size();  // Размер поля Судоку (обычно 9x9)
    int removed = 0;

    int toRemove;
    if (difficulty == 1) {
        toRemove = 40;
    } else if (difficulty == 2) {
        toRemove = 50;
    } else if (difficulty == 3) {
        toRemove = 60;
    }


    // Пока не удалили нужное количество значений
    while (removed < toRemove) {
        // Случайные координаты ячейки
        int row = rand() % size;
        int col = rand() % size;

        // Если ячейка не пустая, удаляем значение
        if (puzzle[row][col] != 0) {
            puzzle[row][col] = 0;  // Устанавливаем 0, чтобы обозначить пустую ячейку
            removed++;
        }
    }

    for (vector<int> column : puzzle) {
        for (int value : column) {
            if (value != 0)
                progress++;
        }
    }

    sudokuToSolve = puzzle;
}

vector<vector<int>> sudokuGenerator::getSolvedSudoku() {
    return solvedSudoku;
}

vector<vector<int> > sudokuGenerator::getSudokuToSolve() {
    return sudokuToSolve;
}

