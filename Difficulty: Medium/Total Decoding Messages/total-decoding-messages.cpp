//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int solve(string &num, int idx) {
        if(idx >= num.size())
            return 1;
        
        if(num[idx] == '0')
            return 0;
        
        int one = solve(num, idx+1);
        
        if(idx == num.size()-1) return one;
        
        int two = 0;
        if(num[idx] == '1' || (num[idx] == '2' && num[idx+1] <= '6'))
            two = solve(num, idx+2);
        
        return one + two;
    }
    
    int countWays(string &num) {
        // return solve(num, 0);
        
        int n = num.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int idx = n-1; idx >= 0; idx--) {
            if(num[idx] == '0') {
                dp[idx] = 0;
                continue;
            }
            
            dp[idx] = dp[idx+1];
        
            if(idx == n-1)
                continue;
            
            if(num[idx] == '1' || (num[idx] == '2' && num[idx+1] <= '6'))
                dp[idx] += dp[idx+2];
            
        }
        
        return dp[0];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends