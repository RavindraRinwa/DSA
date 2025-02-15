#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
vector<vector<int>> edges;

void floydWarshall(int n)
{
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> pi(n + 1, vector<int>(n + 1, -1));

        for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (auto &it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];
        dist[u][v] = wt;
        pi[u][v] = u;
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }

    // Output shortest distances
    cout << "Distance Matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "inf ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    // Output predecessor matrix
    cout << "-------------\nPredecessor Matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pi[i][j] == -1)
                cout << "nil ";
            else
                cout << pi[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    edges.resize(m);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    floydWarshall(n);

    return 0;
}
