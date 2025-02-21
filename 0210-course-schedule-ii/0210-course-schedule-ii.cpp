class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        vector<int> ans;
        while(!q.empty()) {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for(int i : adj[course]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        return ans.size() == n ? ans : {};
    }
};