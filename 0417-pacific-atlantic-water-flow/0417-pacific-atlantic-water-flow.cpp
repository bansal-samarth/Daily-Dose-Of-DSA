class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int prev) {
        if(i < 0 || j < 0 || i >= vis.size() || j >= vis[0].size())
            return;
        
        if(vis[i][j] || prev > grid[i][j])
            return;
        
        vis[i][j] = true;

        dfs(grid, vis, i+1, j, grid[i][j]);
        dfs(grid, vis, i-1, j, grid[i][j]);
        dfs(grid, vis, i, j+1, grid[i][j]);
        dfs(grid, vis, i, j-1, grid[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            dfs(grid, pac, i, 0, -1);
            dfs(grid, atl, i, n-1, -1);
        }

        for(int i = 0; i < n; i++) {
            dfs(grid, pac, 0, i, -1);
            dfs(grid, atl, m-1, i, -1);
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};