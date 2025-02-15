#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<int> &board)
{
    for (int c = 0; c < col; c++)
    {
        int r = board[c];
        // Check if two queens are in the same diagonal
        if (abs(r - row) == abs(c - col))
        {
            return false;
        }
    }
    return true;
}

void nQueenUtil(int col, int n, vector<int> &board, vector<vector<int>> &res, vector<bool> &vis)
{
    if (col == n)
    {
        res.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (!vis[row] && isSafe(row, col, board))
        {
            vis[row] = true;
            board[col] = row; // Place queen in this row and column
            nQueenUtil(col + 1, n, board, res, vis);
            board[col] = -1; // Remove queen
            vis[row] = false;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> res;
    vector<int> board(n, -1);          // Initialize board with -1 (no queens placed)
    vector<bool> vis(n, false);        // Track visited rows
    nQueenUtil(0, n, board, res, vis); // Start solving from column 0
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res = nQueen(n);
    for (auto &solution : res)
    {
        for (int row : solution)
        {
            cout << row + 1 << " "; // Convert to 1-based index for output
        }
        cout << "\n";
    }
}
