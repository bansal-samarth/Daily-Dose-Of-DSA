//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int solve(vector<int>& arr, int idx, int prev) {
    //     if(idx == arr.size())
    //         return 0;
        
    //     int skip = solve(arr, idx+1, prev);
        
    //     int take = 0;
    //     if(prev == -1 || arr[prev] < arr[idx])
    //         take = solve(arr, idx+1, idx) + arr[idx];
        
    //     return max(skip, take);
    // }
    int maxSumIS(vector<int>& arr) {
        // return solve(arr, 0, -1);
        
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev = idx-1; prev >= -1; prev--) {
                
                int skip = dp[idx+1][prev+1];
        
                int take = 0;
                if(prev == -1 || arr[prev] < arr[idx])
                    take = dp[idx+1][idx+1] + arr[idx];
                
                dp[idx][prev+1] = max(skip, take);
            }
        }
        
        return dp[0][-1+1];
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends