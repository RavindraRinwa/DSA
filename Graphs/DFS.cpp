#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> d; // discovery time
vector<int> f; // finish time

void dfsVisit(int u, vector<bool> &vis, vector<int> &pi, int &time)
{
    vis[u] = 1;
    time++;
    d[u] = time;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            pi[v] = u;
            dfsVisit(v, vis, pi, time);
        }
    }
    f[u] = time;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);

    d.resize(n + 1);
    f.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> pi(n + 1, -1);
    vector<bool> vis(n + 1, false);

    int time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfsVisit(i, vis, pi, time);
        }
    }
}