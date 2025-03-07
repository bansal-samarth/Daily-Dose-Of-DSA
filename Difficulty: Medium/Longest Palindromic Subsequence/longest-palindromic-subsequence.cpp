//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int longestPalinSubseq(string &s) {
        string r = s;
        reverse(r.begin(), r.end());
        
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s[i] == r[j])
                    dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
                
                dp[i][j] = max({dp[i][j], dp[i+1][j], dp[i][j+1]});
            }
        }
        
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends