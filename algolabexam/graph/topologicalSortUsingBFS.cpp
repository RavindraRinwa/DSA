#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> indegree;

void BFS(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> tlo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        tlo.push_back(node);

        for (auto neighbor : adj[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // Check if all nodes are processed
    if (tlo.size() != n)
    {
        cout << "The graph has a cycle. Topological sorting is not possible.\n";
        return;
    }

    cout << "Topological Order: ";
    for (auto it : tlo)
    {
        cout << it << " ";
    }
    cout << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;

    if (n == 0)
    {
        cout << "No nodes to process.\n";
        return 0;
    }

    adj.resize(n + 1);
    indegree.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    BFS(n);
}
