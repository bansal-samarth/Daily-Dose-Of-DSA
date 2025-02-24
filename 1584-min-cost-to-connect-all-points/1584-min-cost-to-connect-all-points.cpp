class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        int node = 0;
        int edge = 0;
        int res = 0;

        while(edge < n-1) {
            edge++;
            vis[node] = true;
            int nextNode = -1;
            
            for(int i = 0; i < n; i++) {
                if(vis[i]) continue;

                int cost = abs(points[i][0] - points[node][0])
                            + abs(points[i][1] - points[node][1]);
                
                dist[i] = min(dist[i], cost);

                if(nextNode == -1 || dist[nextNode] > dist[i])
                    nextNode = i;
            }

            res += dist[nextNode];
            node = nextNode;
        }

        return res;
    }
};