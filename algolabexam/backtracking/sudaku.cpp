#include <bits/stdc++.h>
using namespace std;

const int n = 9;

void print(int arr[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int num, int row, int col, int grid[n][n])
{
    for (int i = 0; i < n; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }
    int startR = row - row % 3, startC = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startR + i][startC + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudaku(int grid[n][n], int r, int c)
{
    if (r == n - 1 && c == n)
    {
        return true;
    }
    if (c == n)
    {
        r++;
        c = 0;
    }
    if (grid[r][c] > 0)
    {
        return solveSudaku(grid, r, c + 1);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(i, r, c, grid))
        {
            grid[r][c] = i;
            if (solveSudaku(grid, r, c + 1))
            {
                return true;
            }
            grid[r][c] = 0; // Backtrack
        }
    }
    return false; // No solution found for this path
}

int main()
{
    int grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSudaku(grid, 0, 0))
    {
        print(grid);
    }
    else
    {
        cout << "No solution exists!" << endl;
    }
}
