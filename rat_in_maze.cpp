#include <iostream>
#include <vector>
using namespace std;

bool is_safe(int maze[][5], int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool solve_maze(int maze[][5], vector<char>& path, int x, int y, int n) {
    // Base condition: destination reached
    if (x == n - 1 && y == n - 1) {
        for (char dir : path) {
            cout << dir << " ";
        }
        cout << endl;
        return true;
    }

    // Mark the current cell as visited
    if (is_safe(maze, x, y, n)) {
        // Move Right
        path.push_back('R');
        if (solve_maze(maze, path, x, y + 1, n)) {
            return true;
        }
        path.pop_back();

        // Move Down
        path.push_back('D');
        if (solve_maze(maze, path, x + 1, y, n)) {
            return true;
        }
        path.pop_back();
    }

    return false;
}

int main() {
    int maze[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    vector<char> path;
    if (!solve_maze(maze, path, 0, 0, 5)) {
        cout << "No path found!" << endl;
    }

    return 0;
}
