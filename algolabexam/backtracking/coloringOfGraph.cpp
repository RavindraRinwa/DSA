#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<char> nodeColor;

// Function to check if it's safe to color the node with the given color
bool isSafe(int node, char color)
{
    for (int neighbor : adj[node])
    {
        if (nodeColor[neighbor] == color)
        {
            return false;
        }
    }
    return true;
}

bool do_color(int node, int n)
{
    if (node == n)
    {
        return true; // All nodes are colored
    }

    vector<char> colors = {'R', 'G', 'B'};
    for (char color : colors)
    {
        if (isSafe(node, color))
        {
            nodeColor[node] = color;
            if (do_color(node + 1, n))
            {
                return true; // Proceed to the next node
            }
            nodeColor[node] = 'W'; // Backtrack
        }
    }

    return false; // No valid coloring found
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    nodeColor.resize(n, 'W'); // Initialize all nodes as uncolored

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (do_color(0, n))
    {
        for (char color : nodeColor)
        {
            cout << color << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No valid coloring possible" << endl;
    }

    return 0;
}
