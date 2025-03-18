class Solution {
public:
    // int solve(vector<vector<int>>& grid, int i, int j) {
    //     if(i == grid.size()-1 && j == grid[0].size())
    //         return 1;
        
    //     if(grid[i][j] == 1) return 0;

    //     int right = 0;
    //     if(j < grid[0].size()-1)
    //         right = solve(grid, i, j+1);
        
    //     int down = 0;
    //     if(i < grid.size()-1)
    //         down = solve(grid, i+1, j);

    //     return right + down;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // return solve(obstacleGrid, 0, 0);

        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] || grid[m-1][n-1]) return 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == 1 && j == 1)
                    continue;
                
                if(grid[i-1][j-1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                int up = dp[i-1][j];
                int left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m][n];
    }
};