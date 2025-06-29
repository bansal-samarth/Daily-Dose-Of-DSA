class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        vector<int> ans;

        while(!q.empty()) {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for(int learn : adj[course]) {
                indegree[learn]--;

                if(indegree[learn] == 0)
                    q.push(learn);
            }
        }

        return ans.size() == numCourses;
    }
};