//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        
        for(int via = 0; via < V; via++) {
            for(int u = 0; u < V; u++) {
                for(int v = 0; v < V; v++) {
                    if(dist[u][via] == 1e8 || dist[via][v] == 1e8) {
                        continue;
                    }
                    if(dist[u][via] + dist[via][v] < dist[u][v]) {
                        dist[u][v] = dist[u][via] + dist[via][v];
                    }
                }
            }
        }
        
        return;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends