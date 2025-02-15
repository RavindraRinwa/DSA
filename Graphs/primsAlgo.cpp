#include <bits/stdc++.h>
using namespace std;

#define inf 1e9
vector<vector<pair<int, int>>> adj;

void primsAlgo(int s, int n)
{
    vector<int> vis(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    int res = 0;

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;

        vis[u] = true;
        res += wt;

        for (auto v : adj[u])
        {
            if (!vis[v.first])
            {
                pq.push({v.second, v.first});
            }
        }
    }
    cout << res << '\n';
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
    primsAlgo(1, n);
}
