//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int>& arr, int idx, int prev) {
        if(idx == arr.size())
            return 0;
        
        if(prev != -1 && dp[idx][prev] != -1)
            return dp[idx][prev];
        
        int skip = solve(arr, idx + 1, prev);
        int take = 0;
        if(prev == -1 || arr[idx] > arr[prev])
            take = solve(arr, idx + 1, idx) + 1;
        
        if(prev != -1) dp[idx][prev] = max(skip, take);
        
        return max(skip, take);
    }
    
    int lis(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, -1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends