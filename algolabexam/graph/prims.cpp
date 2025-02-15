#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;

void prims(int n)
{
    vector<bool> vis(n + 1, false);
    vector<int> key(n + 1, 1e9);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[1] = 0;
    pq.push({0, 1}); // {weight, node}

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = true;

        for (auto neighbor : adj[node])
        {
            int adjNode = neighbor.first;
            int edgeW = neighbor.second;

            if (!vis[adjNode] && key[adjNode] > edgeW)
            {
                key[adjNode] = edgeW;
                parent[adjNode] = node;
                pq.push({edgeW, adjNode});
            }
        }
    }

    int totalWeight = 0;
    cout << "MST Edges:\n";
    for (int i = 2; i <= n; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - " << i << "\n";
            totalWeight += key[i];
        }
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims(n);
}