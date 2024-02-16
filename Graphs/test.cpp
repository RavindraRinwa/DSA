//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  void BFS(unordered_map<int, vector<int>> ad, unordered_map<int, bool> &visited,
           vector<int> &ans) {
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
      int ele = q.front();
      q.pop();

      ans.push_back(ele);

      // Process neighbors in the order they were added
      for (int i = 0; i < ad[ele].size(); i++) {
        int neigh = ad[ele][i];
        if (!visited[neigh]) {
          q.push(neigh);
          visited[neigh] = true;
        }
      }
    }
  }

  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<int> ans;
    // creating graph
    unordered_map<int, vector<int>> ad;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
         ad[i].push_back(adj[i][j]);
        // ad[adj[i][j]].push_back(i);
      }
    }

    unordered_map<int, bool> visited;
    // intial sub false hoge

    // now BFS
    // for loop for disconnect graph
    for (int i = 0; i < n; i++) {
      if (visited[i] == false) {
        BFS(ad, visited, ans);
      }
    }

    return ans;
  }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends