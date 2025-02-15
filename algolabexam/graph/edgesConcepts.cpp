#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, dis, fin, pi;

int t;

void dfs(int u)
{
    vis[u] = 1;
    t += 1;
    dis[u] = t; // Record discovery time

    for (auto v : adj[u])
    {
        if (!vis[v]) // Tree Edge
        {
            cout << "Tree Edge: " << u << " -> " << v << "\n";
            pi[v] = u;
            dfs(v);
        }
        else if (vis[v] == 1 && v != pi[u]) // Back Edge
        {
            cout << "Back Edge: " << u << " -> " << v << "\n";
        }
        else if (vis[v] == 2 && fin[v] < dis[u]) // Cross Edge
        {
            cout << "Cross Edge: " << u << " -> " << v << "\n";
        }
        else if (vis[v] == 2 && dis[u] < dis[v]) // Forward Edge
        {
            cout << "Forward Edge: " << u << " -> " << v << "\n";
        }
    }

    t += 1;
    fin[u] = t; // Record finish time
    vis[u] = 2; // Mark as finished
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    dis.resize(n + 1, 0);
    fin.resize(n + 1, 0);
    pi.resize(n + 1, -1);

    t = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    return 0;
}
