//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& prices, int k, int idx, bool buy) {
        if(idx == prices.size() || k == 0)
            return 0;
        
        int skip = solve(prices, k, idx+1, buy);
        
        int take = 0;
        if(buy) {
            take = solve(prices, k, idx+1, false) - prices[idx];
        } else {
            take = solve(prices, k-1, idx+1, true) + prices[idx];
        }
        
        return max(skip, take);
    }
    
    int maxProfit(vector<int>& prices, int k) {
        // return solve(prices, k, 0, true);
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int t = 1; t <= k; t++) {
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
        
        return dp[0][k][1];
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends