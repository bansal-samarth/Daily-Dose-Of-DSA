//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        int ans = arr[0];
        int cnt = 1;
        
        for(int i = 1; i < n; i++) {
            if(ans != arr[i])
                cnt--;
            else
                cnt++;
            
            if(cnt == 0) {
                ans = arr[i];
                cnt = 1;
            }
        }
        
        cnt = 0;
        
        for(int num : arr)
            cnt += num == ans ? 1 : 0;
        
        return cnt > n/2 ? ans : -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends