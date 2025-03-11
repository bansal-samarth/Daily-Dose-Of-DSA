//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        if(n <= 3)
            return n;
        
        int a = 1;
        int b = 2;
        
        int ans = 0;
        for(int i = 3; i <= n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends