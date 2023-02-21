#include <bits/stdc++.h>
using namespace std;

// function to display the 2-d array
void display(vector<vector<int>> &chess)
{
    for (int i = 0; i < chess.size(); i++)
    {
        for (int j = 0; j < chess.size(); j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(vector<vector<int>> &chess, int n, int r, int c, int upcomingMove)
{
    // write your code here
    // base case limits
    if (r < 0 || r >= n || c < 0 || c >= n || chess[r][c] > 0)
    {
        return;
    }
    else if (upcomingMove == n * n)
    {
        chess[r][c] = upcomingMove;
        display(chess);
        chess[r][c] = 0;
        return;
    }

    // marking the move
    chess[r][c] = upcomingMove;
    // all possible calls clockwise
    // 8 possibilities
    printKnightsTour(chess, n, r - 2, c + 1, upcomingMove + 1);
    printKnightsTour(chess, n, r - 1, c + 2, upcomingMove + 1);
    printKnightsTour(chess, n, r + 1, c + 2, upcomingMove + 1);
    printKnightsTour(chess, n, r + 2, c + 1, upcomingMove + 1);
    printKnightsTour(chess, n, r + 2, c - 1, upcomingMove + 1);
    printKnightsTour(chess, n, r + 1, c - 2, upcomingMove + 1);
    printKnightsTour(chess, n, r - 1, c - 2, upcomingMove + 1);
    printKnightsTour(chess, n, r - 2, c - 1, upcomingMove + 1);

    // unmarking the move
    chess[r][c] = 0;
}

int main()
{
    // your code
    int n, row, col;
    cin >> n >> row >> col;

    // creating the chess board
    // fixed size of vector n*n with each cell having the value 0
    vector<vector<int>> chess(n, vector<int>(n, 0));

    // calling the function
    printKnightsTour(chess, n, row, col, 1);

    return 0;
}