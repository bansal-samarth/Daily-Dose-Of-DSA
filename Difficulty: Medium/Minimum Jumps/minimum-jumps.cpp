//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int maxReach = arr[0];
        int steps = 1;
        
        int k = 1;
        while(maxReach < n-1) {
            int org = maxReach;
            
            for(; k <= org; k++) {
                maxReach = max(maxReach, k + arr[k]);
            }
            
            if(org == maxReach) return -1;
            steps++;
        }
        
        return steps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends