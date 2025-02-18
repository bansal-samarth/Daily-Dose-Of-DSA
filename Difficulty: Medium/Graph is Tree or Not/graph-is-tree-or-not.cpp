//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, int prev, int parent, vector<bool>& vis) {
        vis[parent] = true;
        
        for(int to : adj[parent]) {
            if(parent == to) return true;
            if(!vis[to]) {
                if(dfs(adj, parent, to, vis))
                    return true;
            } else {
                if(prev != to)
                    return true;
            }
        }
        
        return false;
    }
    
    int isTree(int n, int m, vector<vector<int>> &edges) {
        if(n <= m) return 0;
        
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        
        if(dfs(adj, -1, 0, vis)) return 0;
        
        for(int i = 0; i < n; i++)
            if(!vis[i])
                return 0;
            
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends