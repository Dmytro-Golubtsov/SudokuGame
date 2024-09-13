#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H
#include <vector>
#include <windows.h>
using namespace std;

class sudokuGrid {
private:
    vector<vector<int>> solvedTable;
    vector<vector<int>> generateSolvedGrid(int n = 3);

public:
    vector<vector<int>> getGrid();

    sudokuGrid() {
        solvedTable = generateSolvedGrid();
    }
    ~sudokuGrid() = default;
};
#endif
