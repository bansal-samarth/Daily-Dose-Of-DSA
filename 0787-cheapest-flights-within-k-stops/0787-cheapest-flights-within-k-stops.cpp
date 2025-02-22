class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int,int>> q;
        q.push({0, src});

        while(!q.empty() && k-- >= 0) {
            int size = q.size();

            for(int t = 0; t < size; t++) {
                int cost = q.front().first;
                int curr = q.front().second;
                q.pop();

                for(auto edge : adj[curr]) {
                    int next = edge.first;
                    int wt = edge.second;

                    if(wt + cost < dist[next]) {
                        dist[next] = wt + cost;
                        q.push({dist[next], next});
                    }
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};