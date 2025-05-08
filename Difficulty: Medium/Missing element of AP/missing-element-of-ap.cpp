//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int diff = arr[1] - arr[0];
        
        int cnt = 1;
        
        for(int i = 1; i < n-1; i++) {
            if(diff == arr[i+1] - arr[i])
                cnt++;
            else {
                cnt--;
            }
            
            if(cnt == 0) diff = arr[i+1] - arr[i];
        }
        
        int a = arr[0];
        for(int i = 1; i < n; i++) {
            a += diff;
            
            if(arr[i] != a)
                return a;
        }
        
        return a + diff;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends