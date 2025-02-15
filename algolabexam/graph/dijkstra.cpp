#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj;

void Dijkstra(int s, int n)
{
    vector<int> dist(n + 1, 1e9);
    dist[s] = 0;
    set<pair<int, int>> st;
    st.insert({0, s});
    while (!st.empty())
    {
        int node = (*st.begin()).second;
        st.erase(st.begin());

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeW = it.second;

            if (dist[adjNode] > dist[node] + edgeW)
            {
                st.erase({dist[adjNode], adjNode});
                dist[adjNode] = dist[node] + edgeW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    cout << "dist from source " << s;
    for (auto it : dist)
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
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int s = 1;
    Dijkstra(s, n);
}