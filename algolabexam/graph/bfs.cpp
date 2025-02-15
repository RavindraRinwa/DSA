#include <bits/stdc++.h>
using namespace std;

void printPath(int node, vector<int> &pi)
{
    vector<int> path;
    while (node != -1)
    {
        path.push_back(node);
        node = pi[node];
    }
    reverse(path.begin(), path.end());
    for (int v : path)
        cout << v << " ";
    cout << "\n";
}

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
    vis[s] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = 1;
                dist[neighbor] = dist[node] + 1;
                pi[neighbor] = node;
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

    for (int i = 1; i <= n; i++)
    {
        cout << "Path to node " << i << ": ";
        if (pi[i] == -1 && i != 1)
            cout << "No path\n";
        else
            printPath(i, pi);
    }

    cout << "\n";
}