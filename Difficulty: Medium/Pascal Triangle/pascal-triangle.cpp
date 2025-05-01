//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row(n, 1);

        for (int k = 1; k < (n + 1) / 2; ++k) {
            row[k] = row[n - 1 - k] = (long long)row[k - 1] * (n - k) / k;
        }

        return row;
    }
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends