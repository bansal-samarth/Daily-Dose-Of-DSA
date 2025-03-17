//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int dp[10001][201];
    // int solve(vector<int>& arr, int sum, int idx) {
    //     if(sum == 0)
    //         return 1;
    //     if(idx == arr.size())
    //         return 0;
        
    //     if(dp[sum][idx] != -1)
    //         return dp[sum][idx];
        
    //     bool skip = solve(arr, sum, idx+1);
        
    //     bool take = false;
    //     if(sum >= arr[idx])
    //         take = solve(arr, sum - arr[idx], idx+1);
        
    //     return dp[sum][idx] = skip || take;
    // }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // memset(dp, -1, sizeof(dp));
        // return solve(arr, sum, 0);
        
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, false));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int s = 0; s <= sum; s++) {
                bool skip = dp[idx+1][s];
        
                bool take = false;
                if(s >= arr[idx])
                    take = dp[idx+1][s - arr[idx]];
                
                dp[idx][s] = skip || take;
            }
        }
        
        return dp[0][sum];
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends