class Solution {
public:
    int solve(int i, int j, int m, int n) {
        if(i == m-1 && j == n-1)
            return 1;
        
        if(i >= m || j >= n)
            return 0;
        
        int right = solve(i, j + 1, m, n);
        int down = solve(i + 1, j, m, n);

        return right + down;
    }
    int uniquePaths(int m, int n) {

        // return solve(0, 0, m, n);

        if(m == 1 || n == 1) return 1;
        
        vector<vector<int>> grid(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }

        return grid[m-1][n-1];
    }
};