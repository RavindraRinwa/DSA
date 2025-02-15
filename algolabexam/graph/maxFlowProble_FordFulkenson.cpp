#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// BFS to find an augmenting path
bool bfs(vector<vector<int>> &capacity, vector<vector<int>> &adj, int source, int sink, vector<int> &parent)
{
    int n = capacity.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr])
        {
            // If the edge has capacity left and the node is not visited
            if (!visited[next] && capacity[curr][next] > 0)
            {
                parent[next] = curr;
                visited[next] = true;
                if (next == sink) // Stop as soon as we reach the sink
                    return true;
                q.push(next);
            }
        }
    }
    return false;
}

// Ford-Fulkerson algorithm using Edmonds-Karp approach
int fordFulkerson(vector<vector<int>> &capacity, vector<vector<int>> &adj, int source, int sink)
{
    int n = capacity.size();
    vector<int> parent(n);
    int maxFlow = 0;

    // Augment the flow while there is a path from source to sink
    while (bfs(capacity, adj, source, sink, parent))
    {
        // Find the maximum flow in the augmenting path
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }

        // Update residual capacities of the edges and reverse edges
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }

        // Add path flow to overall flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<vector<int>> adj(n);

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        adj[u].push_back(v);
        adj[v].push_back(u); // Add reverse edge for residual graph
        capacity[u][v] += cap;
    }

    int source, sink;
    cin >> source >> sink;

    int maxFlow = fordFulkerson(capacity, adj, source, sink);
    cout << "The maximum possible flow is: " << maxFlow << endl;

    return 0;
}
