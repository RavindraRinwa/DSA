#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<vector<bool>> vis;
vector<int> pathsCost;

int main()
{
    int x, y, n, m;
    cin >> x >> y >> n >> m;

    a.resize(n, vector<int>(m));
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) // Input the grid
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; // Queue holds (x, y) and number of flips
    q.push({a[x][y] == 0, {x, y}});                                                                                     // Start from (x, y) with 0 flips

    while (!q.empty())
    {
        auto front = q.top();
        q.pop();

        pair<int, int> cur = front.second; // Get (row, col)
        int flips = front.first;           // Get number of flips

        int row = cur.first, col = cur.second;

        if (row == n - 1 && col == m - 1) // Reached destination
        {
            cout << "Minimum cost is: " << flips << endl;
            return 0;
        }

        vector<int> dr = {1, 0, -1, 0}; // Down, Left, Up, Right
        vector<int> dc = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int r = row + dr[i];
            int c = col + dc[i];

            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c])
            {
                vis[r][c] = true;
                int newFlips = flips + (a[r][c] == 0); // Count the flip if the cell is 1
                q.push({newFlips, {r, c}});            // Push new position with updated flip count
            }
        }
    }

    cout << "No path found\n";
    return 0;
}
