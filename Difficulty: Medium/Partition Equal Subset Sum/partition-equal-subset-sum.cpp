//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& arr, int idx, int target) {
        if(target == 0)
            return 1;
        if(idx == arr.size())
            return 0;
        
        int skip = solve(arr, idx + 1, target);
        int take = 0;
        if(arr[idx] <= target)
            take = solve(arr, idx + 1, target - arr[idx]);
        
        return skip + take;
    }
    bool equalPartition(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total % 2) return false;
        
        int target = total / 2;
        
        int n = arr.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int goal = 0; goal <= target; goal++) {
                if(arr[idx] <= goal)
                    dp[idx][goal] = dp[idx+1][goal] || dp[idx+1][goal - arr[idx]];
                else
                    dp[idx][goal] = dp[idx+1][goal];
            }
        }
        
        return dp[0][target];
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends