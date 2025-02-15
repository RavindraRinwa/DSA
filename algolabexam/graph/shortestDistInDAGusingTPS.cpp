#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<int> st;

void dfs(int u, int n)
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (!vis[v.first])
        {
            vis[v.first] = 1;
            dfs(v.first, n);
        }
    }
    st.push_back(u);
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dfs(1, n);

    vector<int> dist(n + 1, 1e9);
    int s = 2;
    dist[s] = 0;

    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << "\n";

    while (!st.empty())
    {
        int node = st.back();
        st.pop_back();
        if (dist[node] != 1e9)
        {
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeW = it.second;
                if (dist[adjNode] > dist[node] + edgeW)
                {
                    dist[adjNode] = dist[node] + edgeW;
                }
            }
        }
    }

    cout << "dist:";
    for (auto it : dist)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}
