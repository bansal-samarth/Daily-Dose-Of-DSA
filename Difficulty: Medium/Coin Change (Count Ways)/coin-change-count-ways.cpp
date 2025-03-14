//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int>& coins, int sum, int idx) {
        if(sum == 0)
            return 1;
        if(idx == coins.size())
            return 0;
        
        if(dp[sum][idx] != -1)
            return dp[sum][idx];
        
        int skip = solve(coins, sum, idx+1);
        
        int take = 0;
        if(sum >= coins[idx])
            take = solve(coins, sum - coins[idx], idx);
        
        return dp[sum][idx] = skip + take;
    }
    int count(vector<int>& coins, int sum) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, sum, 0);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends