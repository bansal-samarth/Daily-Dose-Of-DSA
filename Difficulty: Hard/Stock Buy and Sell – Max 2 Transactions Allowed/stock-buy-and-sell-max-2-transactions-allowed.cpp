//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2+1, vector<int>(2, 0)));
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int t = 1; t <= 2; t++) {
                for(int buy = 0; buy <= 1; buy++) {
                    int skip = dp[idx+1][t][buy];
        
                    int take = 0;
                    if(buy) {
                        take = dp[idx+1][t][0] - prices[idx];
                    } else {
                        take = dp[idx+1][t-1][1] + prices[idx];
                    }
                    
                    dp[idx][t][buy] = max(skip, take);
                }
            }
        }
        
        return max(dp[0][1][1], dp[0][2][1]);
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