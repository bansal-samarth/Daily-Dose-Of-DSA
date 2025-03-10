//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == n+1)
                swap(arr[i], arr[n-1]);
                
            while(arr[i] < n+1 && arr[i] != arr[arr[i]-1])
                swap(arr[i], arr[arr[i]-1]);
        }
        
        for(int i = 0; i < n; i++) {
            if(i+1 != arr[i])
                return i+1;
        }
        
        return n+1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends