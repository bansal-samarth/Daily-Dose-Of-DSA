class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 1 && n == 1) return abs(grid[m-1][n-1] - 1);
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return 0;
        }
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1] = 1;
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) continue;
                
                if(grid[i][j] == 1) continue;
                
                if(j+1 != n)
                    dp[i][j] += dp[i][j+1];
                if(i+1 != m)
                    dp[i][j] += dp[i+1][j];
            }
        }
        
        return dp[0][0];
    }
};