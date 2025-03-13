//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // int solve(int W, vector<int> &val, vector<int> &wt, int idx) {
    //     if(idx == val.size())
    //         return 0;
        
    //     int skip = solve(W, val, wt, idx+1);
        
    //     int take = 0;
    //     if(W >= wt[idx]) {
    //         take = solve(W - wt[idx], val, wt, idx+1) + val[idx];
    //     }
        
    //     return max(skip, take);
    // }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for(int idx = n-1; idx >= 0; idx--) {
            for(int wgt = 0; wgt <= W; wgt++) {
                dp[idx][wgt] = dp[idx+1][wgt];
    
                if(wgt >= wt[idx]) {
                    dp[idx][wgt] = max(dp[idx][wgt], dp[idx+1][wgt - wt[idx]] + val[idx]); // Include item
                }
            }
        }
        
        return dp[0][W];
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends