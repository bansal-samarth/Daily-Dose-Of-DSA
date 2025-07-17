class Solution {
  public:
    int solve(vector<vector<int>>& mat, int r, int c, int m, int n, vector<vector<int>>& dp) {
        if(c == n-1)
            return mat[r][c];
        
        if(dp[r][c] != -1)
            return dp[r][c];
            
        int up = 0, right = 0, down = 0;
        
        if(r != 0)
            up = solve(mat, r - 1, c + 1, m, n, dp);
        
        right = solve(mat, r, c + 1, m, n, dp);
        
        if(r != m-1)
            down = solve(mat, r + 1, c + 1, m, n, dp);
        
        return dp[r][c] = mat[r][c] + max({up, right, down});
    }
    
    int maxGold(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        int maxi = 0;
        
        for(int i = 0; i < m; i++) {
            maxi = max(maxi, solve(mat, i, 0, m, n, dp));
        }
        
        return maxi;
    }
};