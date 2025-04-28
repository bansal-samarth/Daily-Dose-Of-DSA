class Solution {
public:
    void dfs(vector<vector<int>>& grid, int node, vector<int>& vis) {
        vis[node] = true;

        for(int i = 0; i < grid.size(); i++) {
            if(!vis[i] && grid[node][i]) {
                dfs(grid, i, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vis(n, false);

        int components = 0;

        for(int i = 0 ; i < n; i++) {
            if(!vis[i]) {
                dfs(grid, i, vis);
                components++;
            }
        }

        return components;
    }
};