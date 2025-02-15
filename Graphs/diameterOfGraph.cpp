#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
#define inf 1e9

vector<int> BFS(int s, int n)
{
    vector<int> d(n + 1, inf);
    vector<bool> vis(n + 1);
    vector<int> pi(n + 1, -1);
    d[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                d[v] = d[u] + 1;
                pi[v] = u;
                q.push(v);
            }
        }
    }

    return d;
    // if you want to print the path from (s to v)
    // printPath(s,v);
    // if(s==v)
    // cout<<s<<'\n'; return;
    // else if(pi[v]==nil)
    //    there is no direct path
    // else
    //  printPath(s,pi(v));
    //     cout<<v<<'\n';
}

int process(int s, int n)
{
    int maxDistV = 1;
    vector<int> d1 = BFS(s, n);
    for (int i = 1; i <= n; i++)
    {
        if (d1[maxDistV] < d1[i])
        {
            maxDistV = i;
        }
    }
    return maxDistV;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int id = process(1, n);
    cout << "HI:";
    cout << id << ' ';
    int id1 = process(id, n);
    cout << id1 << '\n';
}