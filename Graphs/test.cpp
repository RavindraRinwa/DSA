#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<vector<int>> &adj, vector<int> &visited, int &count, int &maxHeight, int node)
{
    // step 1.
    visited[node] = true;
    //
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            ++count;
            DFS(adj, visited, count, maxHeight, i);
        }
    }

    maxHeight = max(count, maxHeight);
}
int solve(int n, vector<vector<int>> &edges, int x, int k, vector<int> &addNode)
{
    // make tree
    // 1 to n so carefull
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {

        int u = edges[i][0];

        int v = edges[i][1];

        adj[u].push_back(v);

        adj[v].push_back(u);
    }
    int maxHeight = -1;

    vector<int> visited(n + 1, false);

    // k additional node should remove so make true
    for (int i = 0; i < k; i++)
    {
        visited[addNode[i]] = true;
    }

    int count = 0;

    DFS(adj, visited, count, maxHeight, x);

    return maxHeight;
}
int main()
{
    // no.of nodes and queries
    int n, q;
    cin >> n >> q;

    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    int x, k;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> k;
        vector<int> addNode(k);
        for (int j = 0; j < k; j++)
        {
            cin >> addNode[j];
        }
        cout << solve(n, edges, x, k, addNode) << endl;
    }

    return 0;
}