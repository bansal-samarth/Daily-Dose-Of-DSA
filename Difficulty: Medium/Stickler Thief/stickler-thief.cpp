//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return arr[0];
        
        vector<int> dp(n, 0);
        
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        
        return dp[n-1];
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends