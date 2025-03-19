//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int dp[10001][2][3];

    // int solve(vector<int>& arr, int idx, bool buy, int trans) {
    //     if (trans == 2 || idx == arr.size()) return 0;

    //     if (dp[idx][buy][trans] != -1)
    //         return dp[idx][buy][trans];

    //     int skip = solve(arr, idx + 1, buy, trans);
    //     int profit = 0;

    //     if (buy) {  // Buy stock
    //         profit = solve(arr, idx + 1, false, trans) - arr[idx];
    //     } else {  // Sell stock
    //         profit = solve(arr, idx + 1, true, trans + 1) + arr[idx];
    //     }

    //     return dp[idx][buy][trans] = max(skip, profit);
    // }

    int maxProfit(vector<int> &arr) {
        // if (arr.empty()) return 0;
        // memset(dp, -1, sizeof(dp));
        // return solve(arr, 0, true, 0);
        
        int n=arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int buy = 1; buy >= 0; buy--) {
                for(int trans = 1; trans >= 0; trans--) {
                    int skip = dp[idx+1][buy][trans];
                    int profit = 0;
            
                    if (buy) {  // Buy stock
                        profit = dp[idx+1][0][trans] - arr[idx];
                    } else {  // Sell stock
                        profit = dp[idx+1][1][trans+1] + arr[idx];
                    }
            
                    dp[idx][buy][trans] = max(skip, profit);
                }
            }
        }
        
        return dp[0][1][0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends