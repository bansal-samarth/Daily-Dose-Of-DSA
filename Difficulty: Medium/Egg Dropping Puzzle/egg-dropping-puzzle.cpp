//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int eggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        int moves = 0;
        while(dp[moves][k] < n) {
            moves++;
            for(int eggs = 1; eggs <= k; eggs++)
                dp[moves][eggs] = dp[moves-1][eggs-1] + dp[moves-1][eggs] + 1;
        }
        
        return moves;
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends