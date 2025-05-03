//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        vector<vector<int>> dp(W+1, vector<int>(n+1, 0));
        
        for(int w = 0; w <= W; w++) {
            for(int idx = n-1; idx >= 0; idx--) {
                
                int skip = dp[w][idx + 1];
                
                int take = 0;
                if(w >= wt[idx])
                    take = dp[w - wt[idx]][idx + 1] + val[idx];
                
                dp[w][idx] = max(skip, take);
            }
        }
        
        return dp[W][0];
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