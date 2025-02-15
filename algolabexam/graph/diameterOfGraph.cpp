#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

pair<int, int> maximumDistNode(int s, int n)
{
    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    vector<int> dist(n + 1, 0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto v : adj[node])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                dist[v] = dist[node] + 1;
                q.push(v);
            }
        }
    }

    int maxN = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dist[maxN] < dist[i])
        {
            maxN = i;
        }
    }

    return {maxN, dist[maxN]};
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s = 1;
    pair<int, int> n1 = maximumDistNode(s, n);
    pair<int, int> n2 = maximumDistNode(n1.first, n);
    cout << n1.first << " " << n2.first << " dist:" << n2.second << "\n";
}