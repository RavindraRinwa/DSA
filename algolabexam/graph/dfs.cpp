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
        if (!vis[v])
        {
            pi[v] = u;
            dfs(v);
        }
    }
    t += 1;
    fin[u] = t; // Record finish time
}

void print(vector<int> v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << "\n";
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

    dfs(1);

    cout << "discovery time:";
    print(dis);
    cout << "finish time:";
    print(fin);
    return 0;
}
