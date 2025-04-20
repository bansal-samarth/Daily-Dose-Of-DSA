//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            
            while(arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
        }
        
        for(int i = 1; i <= n; i++) {
            if(i != arr[i-1])
                return arr[i-1];
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends