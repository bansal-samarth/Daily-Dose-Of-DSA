// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses); 
//         vector<int> indegree(numCourses, 0); 
        
//         for(auto& prerequisite : prerequisites) {
//             int course = prerequisite[0];
//             int prereq = prerequisite[1];
//             adj[prereq].push_back(course);
//             indegree[course]++;
//         }

//         queue<int> q;

//         for(int i = 0; i < numCourses; i++) {
//             if(indegree[i] == 0)
//                 q.push(i);
//         }

//         vector<int> order;
//         while(!q.empty()) {
//             int val = q.front();
//             q.pop();
//             order.push_back(val);

//             for(int course : adj[val]) {
//                 if(--indegree[course] == 0) {
//                     q.push(course);
//                 }
//             }
//         }

//         if(order.size() == numCourses)
//             return true;
//         return false;
//     }
// };


class Solution {
public:
    bool isCycle(int node,vector<int> &vis,vector<int> adj[],vector<int> &rec) {  
        vis[node]=1;
        rec[node]=1;

        for(int child : adj[node]) {
            if(vis[child] == 0) {
                if(isCycle(child,vis,adj,rec))
                    return true;
            }
            else {
                if(rec[child]) return true;
            }
        }

        rec[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> rec(numCourses,0);
        vector<int> vis(numCourses, 0);
       
        for(int i=0;i<prerequisites.size();i++) {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a); 
        }
        
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                if(isCycle(i,vis,adj,rec))
                    return false;
            }
        } 
        return true;
    }
};
