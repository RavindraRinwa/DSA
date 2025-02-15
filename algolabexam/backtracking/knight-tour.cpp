#include <bits/stdc++.h>
using namespace std;

int n;

bool isSafe(int r, int c, vector<vector<int>> &board)
{
    return r >= 0 && r < n && c >= 0 && c < n && board[r][c] == -1;
}

bool knight_move(int row, int col, int moveCount, vector<vector<int>> &board)
{
    if (moveCount == n * n)
    {
        return true;
    }

    vector<int> dr = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> dc = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++)
    {
        int r = row + dr[i];
        int c = col + dc[i];
        if (isSafe(r, c, board))
        {
            board[r][c] = moveCount;
            if (knight_move(r, c, moveCount + 1, board))
            {
                return true;
            }
            board[r][c] = -1; // Backtrack
        }
    }

    return false;
}

int main()
{
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0] = 0; // Starting position

    if (knight_move(0, 0, 1, board))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << setw(3) << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists for the given board size." << endl;
    }
}
