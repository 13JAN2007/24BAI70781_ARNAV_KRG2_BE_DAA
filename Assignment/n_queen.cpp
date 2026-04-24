#include <bits/stdc++.h>
using namespace std;

int boardSize;
vector<vector<string>> allSolutions;

void storeSolution(vector<int> &queenPositions) {
    vector<string> boardRepresentation(boardSize, string(boardSize, '.'));

    for (int row = 0; row < boardSize; row++) {
        boardRepresentation[row][queenPositions[row]] = 'Q';
    }

    allSolutions.push_back(boardRepresentation);
}

void solveNQueens(int currentRow, vector<int> &queenPositions,
                  vector<bool> &columnsUsed,
                  vector<bool> &mainDiagonal,
                  vector<bool> &antiDiagonal) {

    if (currentRow == boardSize) {
        storeSolution(queenPositions);
        return;
    }

    for (int column = 0; column < boardSize; column++) {
        if (columnsUsed[column] || 
            mainDiagonal[currentRow - column + boardSize - 1] || 
            antiDiagonal[currentRow + column])
            continue;

        queenPositions[currentRow] = column;
        columnsUsed[column] = 
        mainDiagonal[currentRow - column + boardSize - 1] = 
        antiDiagonal[currentRow + column] = true;

        solveNQueens(currentRow + 1, queenPositions, columnsUsed, mainDiagonal, antiDiagonal);

        columnsUsed[column] = 
        mainDiagonal[currentRow - column + boardSize - 1] = 
        antiDiagonal[currentRow + column] = false;
    }
}

int main() {
    cout << "Enter N: ";
    cin >> boardSize;

    vector<int> queenPositions(boardSize);
    vector<bool> columnsUsed(boardSize, false);
    vector<bool> mainDiagonal(2 * boardSize - 1, false);
    vector<bool> antiDiagonal(2 * boardSize - 1, false);

    solveNQueens(0, queenPositions, columnsUsed, mainDiagonal, antiDiagonal);

    cout << "\nTotal Solutions: " << allSolutions.size() << "\n\n";

    for (auto &solution : allSolutions) {
        for (auto &row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}