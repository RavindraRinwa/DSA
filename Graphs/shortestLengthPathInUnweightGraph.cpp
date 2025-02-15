#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, vector<bool> &vis, int s, int e)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    vector<int> parent(adj.size(), -1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == e)
        {
            vector<int> path;
            for (int v = e; v != -1; v = parent[v])
            {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                vis[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }
    }
    return {};
}
