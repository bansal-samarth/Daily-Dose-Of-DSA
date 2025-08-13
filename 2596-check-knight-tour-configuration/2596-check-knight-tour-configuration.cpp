class Solution {
public:
    vector<vector<int>> dir;

    bool solve(vector<vector<int>>& grid, unordered_map<int, pair<int,int>>& map, int i, int j, int n) {
        int val = grid[i][j];

        if(val == n * n - 1)
            return true;
        
        auto [row, col] = map[val + 1];

        for(int x = 0; x < 8; x++) {
            int r = i + dir[x][0];
            int c = j + dir[x][1];

            if(r == row && c == col)
                return solve(grid, map, r, c, n);
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        unordered_map<int, pair<int,int>> map;

        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[grid[i][j]] = {i, j};
            }
        }

        dir = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

        return solve(grid, map, 0, 0, n);
    }
};