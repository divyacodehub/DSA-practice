#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n,
            vector<vector<int>>& m,
            vector<vector<int>>& visited) {

    return (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && visited[x][y] == 0);
}

void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y,
           vector<vector<int>>& visited,
           string path) {

    // base case
    if(x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    if(isSafe(x + 1, y, n, m, visited))
        solve(m, n, ans, x + 1, y, visited, path + 'D');

    // Left
    if(isSafe(x, y - 1, n, m, visited))
        solve(m, n, ans, x, y - 1, visited, path + 'L');

    // Right
    if(isSafe(x, y + 1, n, m, visited))
        solve(m, n, ans, x, y + 1, visited, path + 'R');

    // Up
    if(isSafe(x - 1, y, n, m, visited))
        solve(m, n, ans, x - 1, y, visited, path + 'U');

    // Backtrack
    visited[x][y] = 0;
}

int main() {

    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int n = maze.size();

    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if(maze[0][0] == 1)
        solve(maze, n, ans, 0, 0, visited, "");

    for(string path : ans)
        cout << path << endl;

    return 0;
}