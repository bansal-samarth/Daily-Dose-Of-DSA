//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);
        
        int edge = 0;
        int node = 0;
        int ans = 0;
        
        while(edge < n - 1) {
            edge++;
            
            int nextNode = -1;
            vis[node] = true;
            
            for(int i = 0; i < n; i++) {
                if(node == i || vis[i])
                    continue;
                
                int d = abs(houses[node][0] - houses[i][0])
                        + abs(houses[node][1] - houses[i][1]);
                
                if(d < dist[i])
                    dist[i] = d;
                
                if(nextNode == -1 || dist[nextNode] > dist[i])
                    nextNode = i;
            }
            
            node = nextNode;
            ans += dist[node];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends