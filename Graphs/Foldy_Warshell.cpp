#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Distance to itself is zero
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++)
    {
        long long u, v, edgeWeight;
        cin >> u >> v >> edgeWeight;
        dist[u][v] = min(dist[u][v], edgeWeight);
        dist[v][u] = min(dist[v][u], edgeWeight);
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Answer queries
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == INF)
            cout << -1 << "\n";
        else
            cout << dist[u][v] << "\n";
    }
    return 0;
