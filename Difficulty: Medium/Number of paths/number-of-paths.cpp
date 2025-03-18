//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int numberOfPaths(int m, int n) {
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1] = 1;
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;
                
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                
                dp[i][j] = right + down;
            }
        }
        
        return dp[0][0];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int m, n;
        cin >> m >> n;
        cin.ignore();
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends