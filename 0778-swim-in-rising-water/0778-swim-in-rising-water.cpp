class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({grid[0][0], {0,0}});

        int dir[5] = {1, 0, -1, 0, 1};

        while(!pq.empty()) {
            auto p = pq.top();
            int cost = p.first;
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();

            for(int x = 0; x < 4; x++) {
                int r = i + dir[x];
                int c = j + dir[x+1];

                if(r < 0 || c < 0 || r >= n || c >= n)
                    continue;
                
                int curr = max(cost, grid[r][c]);
                
                if(r == n-1 && c == n-1) return curr;
                
                if(curr < dist[r][c]) {
                    dist[r][c] = curr;
                    pq.push({curr, {r, c}});
                }
            }
        }

        return -1;
    }
};
