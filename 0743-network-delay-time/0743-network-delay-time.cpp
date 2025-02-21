class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        for(int i = 1; i <= n; i++) {
            for(auto edge : times) {
                int u = edge[0];
                int v = edge[1];
                int d = edge[2];

                if(dist[u] != INT_MAX && dist[u] + d < dist[v])
                    dist[v] = dist[u] + d;
            }
        }

        int maxi = *max_element(dist.begin()+1, dist.end());

        return maxi == INT_MAX ? -1 : maxi;
    }
};
