#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define int long long
#define inf 1e9
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    --a, --b;
    vector<vector<int>>adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>vis(n);
    vector<int>st;
    set<int>cycNode;
    auto dfs = [&](auto && self, int node, int p)->void{
        vis[node] = true;
        st.push_back(node);
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                self(self, adjNode, node);
            }
            else {
                if (p != adjNode) {
                    cycNode.insert(adjNode);
                    while (!st.empty() && st.back() != adjNode) {
                        cycNode.insert(st.back());
                        st.pop_back();
                    }
                }
            }
        }
    };

    dfs(dfs, a, -1);
    st.clear();

    auto dijkstra = [&](int s)->vector<int> {
        vector<int>dist(n, inf);
        dist[s] = 0;
        set<pair<int, int>>stt;
        stt.insert({s, 0});
        while (!stt.empty()) {
            auto [_, node] = *stt.begin();
            stt.erase(stt.begin());
            for (auto adjNode : adj[node]) {
                if (dist[adjNode] > dist[node] + 1) {
                    stt.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dist[node] + 1;
                    stt.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    };

    vector<int>d1 = dijkstra(a);
    vector<int>d2 = dijkstra(b);

    debug(d1);
    debug(d2);

    for (int node : cycNode) {
        if (d1[node] > d2[node]) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}



int32_t main()
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