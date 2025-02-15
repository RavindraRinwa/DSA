#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        val[i]--;
    }

    vector<vector<int>>adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(val[v]);
        adj[v].push_back(val[u]);
    }

    string ans(n, '0');
    for (int node = 0; node < n; node++) {
        adj[node].push_back(val[node]);
        sort(adj[node].begin(), adj[node].end());
        for (int i = 0; i + 1 < adj[node].size(); i++) {
            if (adj[node][i] == adj[node][i + 1]) {
                ans[adj[node][i]] = '1';
            }
        }
    }

    cout << ans << "\n";

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif


    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}