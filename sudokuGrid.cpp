#include "sudokuGrid.h"
#include <windows.h>
vector<vector<int> > sudokuGrid::generateSolvedGrid(int n) {
    vector<vector<int>> table(n * n, vector<int>(n * n));
    for (int i = 0; i < n * n; ++i) {
        for (int j = 0; j < n * n; ++j) {
            table[i][j] = ((i * n + i / n + j) % (n * n)) + 1;
        }
    }
    return table;
}

vector<vector<int> > sudokuGrid::getGrid() {
    return solvedTable;
}
