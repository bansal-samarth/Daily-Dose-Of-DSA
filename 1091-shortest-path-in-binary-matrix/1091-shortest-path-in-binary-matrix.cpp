class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]) return -1;
        if(n == 1) return 1;

        int dir[] = {1, 0, -1, 0, 1, 1, -1, -1, 1};

        vector<vector<int>> vis = grid;

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({1, {0,0}});

        while(!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(int x = 0; x < 8; x++) {
                int r = i + dir[x];
                int c = j + dir[x + 1];

                if(r < 0 || c < 0 || r == n || c == n) continue;
                if(vis[r][c]) continue;

                if(r == n-1 && c == n-1)
                    return d + 1;

                vis[r][c] = 1;
                pq.push({d + 1, {r,c}});
            }
        }

        return -1;
    }
};