#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> board;
    int n;
    bool found = false;

    bool isValid(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'M')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'M')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'M')
                return false;
        }

        return true;
    }

    void solve(int row) {
        if (found)
            return;

        if (row == n) {
            found = true;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col)) {
                board[row][col] = 'M';
                solve(row + 1);
                if (found)
                    return;
                board[row][col] = '.';
            }
        }
    }

    vector<string> placeMarkers(int N) {
        n = N;
        board = vector<string>(n, string(n, '.'));
        solve(0);
        return board;
    }
};