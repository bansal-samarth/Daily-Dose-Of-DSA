class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxi = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(matrix[i][j] == '0')
                    continue;

                int up = i == 0 ? 0 : dp[i-1][j];
                int left = j == 0 ? 0 : dp[i][j-1];
                int diag = i == 0 || j == 0 ? 0 : dp[i-1][j-1];

                dp[i][j] = min({up, left, diag}) + 1;

                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi * maxi;
    }
};