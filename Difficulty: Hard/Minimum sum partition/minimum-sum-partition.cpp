//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int target = sum / 2;
        
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for(int i = n-1; i >= 0; i--) {
            for(int curr = 1; curr < target+1; curr++) {
                if(curr >= arr[i])
                    dp[i][curr] = dp[i + 1][curr] || dp[i + 1][curr - arr[i]];
                else
                    dp[i][curr] = dp[i + 1][curr];
            }
        }
        
        int diff = -1;
        for(int i = target; i >= 0; i--) {
            if(dp[0][i]) {
                diff = i;
                break;
            }
        }
        
        return sum - 2*diff;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends