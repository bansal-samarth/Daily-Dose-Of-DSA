//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<int> parent(V, -1);
        vector<bool> ap(V, false);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, disc, low, parent, ap, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (ap[i]) {
                result.push_back(i);
            }
        }

        if (result.empty()) {
            return {-1};
        }

        return result;
    }

private:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }

            if (!visited[v]) {
                parent[v] = u;
                children++;
                dfs(v, adj, visited, disc, low, parent, ap, time);

                low[u] = min(low[u], low[v]);

                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent[u] == -1 && children >= 2) {
            ap[u] = true;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends