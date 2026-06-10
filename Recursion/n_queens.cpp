#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {

    int x = row;
    int y = col;

    // Check left row
    while(y >= 0) {
        if(board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;

    // Upper diagonal
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    x = row;
    y = col;

    // Lower diagonal
    while(x < n && y >= 0) {
        if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col,
           vector<vector<int>>& board,
           vector<vector<vector<int>>>& ans,
           int n) {

    // All queens placed
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {

        if(isSafe(row, col, board, n)) {

            board[row][col] = 1;

            solve(col + 1, board, ans, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {

    int n = 4;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> ans;

    solve(0, board, ans, n);

    for(auto solution : ans) {

        for(auto row : solution) {

            for(int cell : row)
                cout << cell << " ";

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}