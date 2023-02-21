#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<vector<bool>> board, int row, vector<bool> cols, vector<bool> ndiag, vector<bool> rdiag, string asf)
{
    // base case
    if (row == board.size())
    {
        cout << asf + "." << endl;
        return;
    }
    // loop
    for (int col = 0; col < board.size(); col++)
    {
        if (cols[col] == false && ndiag[row + col] == false && rdiag[row - col + board.size() - 1] == false)
        {
            board[row][col] = true;
            // setting up the constraints
            cols[col] = true;
            ndiag[row + col] = true;
            rdiag[row - col + board.size() - 1] = true;
            solve(board, row + 1, cols, ndiag, rdiag, asf + to_string(row) + "-" + to_string(col) + ", ");
            // removing the constraints while we backtrack
            cols[col] = false;
            ndiag[row + col] = false;
            rdiag[row - col + board.size() - 1] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    // required data variables
    int diagLen = 2 * n - 1;
    vector<bool> ndiag(diagLen, false);
    vector<bool> rdiag(diagLen, false);
    vector<bool> cols(n, false);

    // call
    solve(board, 0, cols, ndiag, rdiag, "");
    return 0;
}