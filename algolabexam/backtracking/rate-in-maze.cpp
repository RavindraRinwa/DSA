#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<vector<bool>> vis;
vector<string> paths;

void findPath(int row, int col, int n, int m, string path)
{
    if (row == n - 1 && col == m - 1)
    {
        paths.push_back(path);
        return;
    }

    vis[row][col] = true;

    vector<int> dr = {1, 0, -1, 0}; // Down, Left, Up, Right
    vector<int> dc = {0, -1, 0, 1};
    string moves = "DLUR";

    for (int i = 0; i < 4; i++)
    {
        int r = row + dr[i];
        int c = col + dc[i];

        if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && a[r][c] == 1)
        {
            findPath(r, c, n, m, path + moves[i]);
        }
    }

    vis[row][col] = false; // Backtracking
}

int main()
{
    int n, m;
    cin >> n >> m;

    a.resize(n, vector<int>(m));
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    if (a[0][0] == 0 || a[n - 1][m - 1] == 0)
    {
        cout << "No paths available\n";
        return 0;
    }

    findPath(0, 0, n, m, "");

    for (const auto &it : paths)
    {
        cout << it << " ";
    }
    cout << "\n";

    if (paths.empty())
    {
        cout << "No paths available\n";
    }

    return 0;
}
