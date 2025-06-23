class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if(row == triangle.size())
            return 0;
        
        int left = solve(triangle, row + 1, col);
        int right = solve(triangle, row + 1, col + 1);

        return min(left, right) + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(triangle, 0, 0);

        vector<vector<int>> dp = triangle;
        int r = triangle.size();
        
        for(int row = r - 2; row >= 0; row--) {
            for(int col = 0; col < triangle[row].size(); col++) {
                
                int left = dp[row + 1][col];
                int right = dp[row + 1][col + 1];

                dp[row][col] += min(left, right);
            }
        }

        return dp[0][0];
    }
};