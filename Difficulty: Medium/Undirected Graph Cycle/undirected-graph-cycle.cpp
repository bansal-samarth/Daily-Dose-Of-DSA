//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, int curr, int prev, vector<bool> &vis, vector<bool> &res) {
        vis[curr] = 1;
        res[curr] = 1;
        
        for(int next : adj[curr]) {
            if(!vis[next]) {
                if(dfs(adj, next, curr, vis, res))
                    return 1;
            } else {
                if(prev != next) {
                    if(res[next])
                        return 1;
                }
            }
        }
        
        res[curr] = 0;
        
        return 0;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<bool> res(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i] && dfs(adj, i, -1, vis, res))
                return 1;
        }
        
        return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends