#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;

vector<int> bellmanford(int s, int n)
{
    vector<int> dist(n + 1, 1e8);
    dist[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (dist[v] > dist[u] + w)
            {
                // detecting negative cycle
                if (i == n)
                {
                    return {-1};
                }
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
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

    cout << "dist from source:";
    for (auto d : bellmanford(1, n))
    {
        cout << d << " ";
    }
    cout << "\n";
}