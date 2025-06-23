class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, int m, int n) {
        if(row == m-1 && col == n-1)
            return grid[row][col];
        
        int right = INT_MAX;
        if(col != n-1)
            right = solve(grid, row, col + 1, m, n);
        
        int down = INT_MAX;
        if(row != m-1)
            down = solve(grid, row + 1, col, m, n);
        
        return grid[row][col] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // return solve(grid, 0, 0, grid.size(), grid[0].size());

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp = grid;

        for(int row = m-1; row >= 0; row--) {
            for(int col = n-1; col >= 0; col--) {
                if(row == m-1 && col == n-1)
                    continue;

                int right = INT_MAX;
                if(col != n-1)
                    right = dp[row][col + 1];
                
                int down = INT_MAX;
                if(row != m-1)
                    down = dp[row + 1][col];
                
                dp[row][col] += min(right, down);
            }
        }

        return dp[0][0];
    }
};