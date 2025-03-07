//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string s) {
        string res = string(s[0], 1);
        int maxi = 1;
        for(int i = 1 ; i < s.size()-1 ; i++) {
            int left = i - 1;
            int right = i + 1;
            
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                if(maxi < right - left + 1) {
                    maxi = right - left + 1;
                    res = s.substr(left, maxi);
                }
                left--;
                right++;
            }
            
            left = i;
            right = i + 1;
            
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                if(maxi < right - left + 1) {
                    maxi = right - left + 1;
                    res = s.substr(left, maxi);
                }
                left--;
                right++;
            }
        }
        
        return res;
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends