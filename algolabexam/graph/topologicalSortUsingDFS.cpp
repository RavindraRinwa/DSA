#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> st;

void dfs(int u, int n)
{
    vis[u] = 1;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v, n);
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

    for (int j = 0; j < m; j++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, n);
    }

    cout << "topological order:";
    while (!st.empty())
    {
        cout << (st.back()) << " ";
        st.pop_back();
    }
}