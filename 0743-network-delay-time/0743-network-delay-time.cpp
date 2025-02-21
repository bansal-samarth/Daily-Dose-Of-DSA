class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : times)
            adj[edge[0]-1].push_back({edge[1]-1, edge[2]});
        
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k-1});

        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto node : adj[u]) {
                int v = node.first;
                int time = node.second;

                if(d + time < dist[v]) {
                    dist[v] = d + time;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxi = *max_element(dist.begin(), dist.end());

        return maxi == INT_MAX ? -1 : maxi;
    }
};
