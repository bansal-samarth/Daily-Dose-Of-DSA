//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // int solve(string& s1, string& s2, int i, int j) {
    //     if(i == s1.size() || j == s2.size())
    //         return 0;
        
    //     if(s1[i] == s2[j])
    //         return solve(s1, s2, i+1, j+1) + 1;
        
    //     return max(solve(s1, s2, i, j+1), solve(s1, s2, i+1, j));
    // }
    
    int lcs(string& s1, string& s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
        return dp[0][0];
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends