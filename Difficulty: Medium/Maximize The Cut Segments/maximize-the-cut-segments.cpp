//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int solve(int n, int x, int y, int z) {
    //     if(n == 0)
    //         return 0;
        
    //     int first = INT_MIN, second = INT_MIN, third = INT_MIN;
    //     if(n >= x)
    //         first = solve(n - x, x, y, z) + 1;
    //     if(n >= y)
    //         second = solve(n - y, x, y, z) + 1;
    //     if(n >= z)
    //         third = solve(n - z, x, y, z) + 1;
        
    //     return max({first, second, third});
    // }
    int maximizeTheCuts(int n, int x, int y, int z) {
        // int res = solve(n, x, y, z);
        // return max(0, res);
        
        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            int first = INT_MIN, second = INT_MIN, third = INT_MIN;
            if(i >= x)
                first = dp[i - x] + 1;
            if(i >= y)
                second = dp[i - y] + 1;
            if(i >= z)
                third = dp[i - z] + 1;
            
            dp[i] = max({first, second, third});
        }
        
        return max(0, dp[n]);
    }
};

//{ Driver Code Starts.
int main() {

    // taking testcases
    int t;
    cin >> t;
    while (t--) {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends