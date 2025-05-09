//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void rec(int i, int k, string& s, string& ans){
        int n = s.length();
        if(k == 0 || i == n){
            ans = max(ans, s);
            return;
        }
        
        for(int idx = i; idx < n; idx++){
            if(s[idx] > s[i]){
                swap(s[i], s[idx]);
                rec(i+1, k-1, s, ans);
                swap(s[i], s[idx]);
            }
        }
        
        rec(i+1, k, s, ans);
    }
    
    string findMaximumNum(string& s, int k) {
        string ans = s;
        rec(0, k, s, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends