
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].push_back(u);
        edge[i].push_back(v);
        edge[i].push_back(w);
    }
    vector<long long> dist(n + 1, 1e18);
    int S = 1;
    dist[S] = 0;
    bool ok = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dist[u] != 1e18 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    // N-th relax session for negative cycle
    for (auto it : edge)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (dist[u] != 1e18 && dist[u] + w < dist[v])
        {
            cout << -1 << "\n";
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << dist[n] << '\n';
    return 0;
}