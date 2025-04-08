//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int curr, int prev, vector<bool> &vis, vector<vector<int>>& adj) {
        
        vis[curr] = true;
        
        for(int next : adj[curr]) {
            if(next == prev) continue;
            
            if(vis[next]) continue;
            
            dfs(next, curr, vis, adj);
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        
        for(auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            
            if((a == c && b == d) || (a == d && b == c))
                continue;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<bool> vis(V, false);
        
        dfs(c, -1, vis, adj);
        
        return !vis[d];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends