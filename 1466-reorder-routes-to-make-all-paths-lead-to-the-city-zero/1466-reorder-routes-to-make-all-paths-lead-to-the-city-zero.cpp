class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int& ans, int num) {
        vis[num] = true;

        for(auto& [i,j] : adj[num]) {
            if(!vis[i]) {
                ans += j;
                dfs(adj, vis, ans, i);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<pair<int,int>>> adj(n);

        for (const auto& edge : con) {
            int i = edge[0], j = edge[1];
            adj[i].push_back({j, 1});
            adj[j].push_back({i, 0});
        }

        vector<bool> vis(n, false);
        int ans = 0;

        dfs(adj, vis, ans, 0);

        return ans;
    }
};