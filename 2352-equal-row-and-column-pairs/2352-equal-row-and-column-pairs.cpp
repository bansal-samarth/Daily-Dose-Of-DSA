class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> map;

        for(auto row : grid) {
            string line = "";
        
            for(int num : row) {
                string str = to_string(num);

                line += str;
                line += '_';
            }

            map[line]++;
        }

        int cnt = 0;

        int m = grid.size();
        int n = grid[0].size();

        for(int j = 0; j < n; j++) {
            string line = "";

            for(int i = 0; i < m; i++) {
                string str = to_string(grid[i][j]);

                line += str;
                line += '_';
            }

            cnt += map[line];
        }

        return cnt;
    }
};