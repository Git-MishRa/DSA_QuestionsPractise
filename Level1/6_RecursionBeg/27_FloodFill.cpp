// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
// 4. You are standing in the top-left corner and have to reach the bottom-right corner.
// Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
// 5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

// Note1 -> Please check the sample input and output for details
// Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'

#include <iostream>
#include <vector>

using namespace std;

void floodfill(vector<vector<int>> maze, int row, int col, string psf, vector<vector<bool>> visited)
{
    // base case not to jump out of board
    if (row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1 /*i.e obstacle*/ || visited[row][col] == true)
    {
        return;
    }

    // eureka
    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        cout << psf << endl;
    }

    // marking visited in order to prevent loop of visits
    visited[row][col] = true;

    // movement steps in order
    floodfill(maze, row - 1, col, psf + 't', visited); // up
    floodfill(maze, row, col - 1, psf + "l", visited); // left
    floodfill(maze, row + 1, col, psf + "d", visited); // down
    floodfill(maze, row, col + 1, psf + "r", visited); // right

    // after exploring every move, remove visited, to allow new paths
    visited[row][col] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    string psf = "";
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    floodfill(arr, 0, 0, psf, visited);
}