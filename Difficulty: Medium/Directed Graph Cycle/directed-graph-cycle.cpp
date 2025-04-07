//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> degree(V);
        
        queue<int> qu;
        int count = 0;
        
        for(auto &i : edges) {
            int u = i[0], v = i[1];
            if(u == v) return true;
            degree[v]++;
            adj[u].push_back(v);
        }
        
        for(int i = 0; i < V; i++) {
            if(degree[i] == 0) qu.push(i), count++;
        }
        
        while(!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            
            for(auto i : adj[curr]) {
                degree[i]--;
                if(degree[i] == 0) {
                    qu.push(i);
                    count++;
                }
            }
        }
        
        return (count < V);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends