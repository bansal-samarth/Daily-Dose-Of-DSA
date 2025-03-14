//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string FirstNonRepeating(string &s) {
        
        vector<int> vis(26, 0);
        queue<char> q;
        
        string res = "";
        
        for(char ch : s) {
            vis[ch-'a']++;
            
            if(vis[ch-'a'] == 1)
                q.push(ch);
            
            while(!q.empty() && vis[q.front()-'a'] > 1)
                q.pop();
            
            res += q.empty() ? '#' : q.front();
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends