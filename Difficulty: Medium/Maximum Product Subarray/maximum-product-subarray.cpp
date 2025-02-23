//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int maxi = INT_MIN;
        int n = arr.size();
        
        int mul = 1;
        for(int i = 0; i < n; i++) {
            mul *= arr[i];
            
            maxi = max(maxi, mul);
            
            if(mul == 0) mul = 1;
        }
        
        mul = 1;
        for(int i = n-1; i >= 0; i--) {
            mul *= arr[i];
            
            maxi = max(maxi, mul);
            
            if(mul == 0) mul = 1;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends