#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, 0);
    vector<int> pi(n + 1, -1);

    int s = 1;

    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (vis[node])
        {
            cout << "Cycle is present" << "\n";
            return 0;
        }

        vis[node] = 1;

        for (auto neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                q.push(neighbor);
            }
        }
    }
    cout << "parentArray:";
    for (auto it : pi)
    {
        cout << it << " ";
    }
    cout << "\n";

    cout << "distance:";
    for (auto it : dist)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}