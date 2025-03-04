//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int count(vector<int> &stalls, int dis) {
        int total = 1;
        
        int curr = stalls[0];
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] >= curr + dis) {
                curr = stalls[i];
                total++;
            }
        }
        
        return total;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int left = 1;
        int right = stalls[stalls.size() - 1] - stalls[0];
        
        int ans = 0;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(count(stalls, mid) >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends