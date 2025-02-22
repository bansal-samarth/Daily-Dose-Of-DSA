//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        int n = s.size();
        stack<int> st;

        vector<int> records(n, 0);
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                st.push(i);
            else {
                if(st.empty())
                    continue;
                int top = st.top();
                st.pop();
                
                records[i] = 2;
                
                if(top > 0)
                    records[i] += records[top - 1];
                
                if(i > 0)
                    records[i] += records[i - 1];
                
                ans = max(ans, records[i]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends