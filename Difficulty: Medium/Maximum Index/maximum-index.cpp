//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(mini > arr[i])
                mini = arr[i];
            
            left[i] = mini;
        }
        
        int maxi = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            if(maxi < arr[i])
                maxi = arr[i];
            
            right[i] = maxi;
        }
        
        // for(int i = 0; i < n; i++) cout << left[i] <<", " << right[i] << endl;
        
        int i = 0, j = 0;
        int ans = 0;
        while(i < n && j < n) {
            if(left[i] <= right[j]) {
                ans = max(ans, j - i);
                j++;
            } else
                i++;
        }
        
        return ans;
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
        auto ans = ob.maxIndexDiff(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends