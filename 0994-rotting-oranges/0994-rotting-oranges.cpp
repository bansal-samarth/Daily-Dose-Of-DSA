class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {
                    q.push({i,j});
                    vis[i][j] = true;
                } else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dir[5] = {-1,0,1,0,-1};

        int steps = -1;
        while(!q.empty()) {
            int N = q.size();

            for(int k = 0; k < N; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int x = 0; x < 4; x++) {
                    int r = i + dir[x];
                    int c = j + dir[x+1];

                    if(r < 0 || r >= m || c < 0 || c >= n)
                        continue;
                    if(grid[r][c] != 1 || vis[r][c])
                        continue;

                    vis[r][c] = true;
                    q.push({r, c});
                    fresh--;
                }
            }

            steps++;
        }

        if(fresh)
            return -1;

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {

        //         if(grid[i][j] == 1 && !vis[i][j]) {
        //             return -1;
        //         }
        //     }
        // }

        return steps;
    }
};