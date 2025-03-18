//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
         
        if(totalSum % 2) return false;
         
        int target = totalSum / 2;
         
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, false));
         
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for(int i = n-1; i >= 0; i--) {
            for(int sum = 1; sum <= target; sum++) {
                dp[i][sum] |= dp[i+1][sum];
                
                if(sum >= arr[i])
                    dp[i][sum] |= dp[i+1][sum - arr[i]];
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