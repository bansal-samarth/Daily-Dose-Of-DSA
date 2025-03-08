//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPS(string &s) {
        int count = s[0] == s[1] ? 1 : 0;
        for(int i = 1 ; i < s.size()-1 ; i++) {
            int left = i - 1;
            int right = i + 1;
            
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            
            left = i;
            right = i + 1;
            
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends