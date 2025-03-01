//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string decodedString(string &s) {
        stack<string> st;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ']') {
                string word = "";
                while(!st.empty() && st.top() != "[") {
                    word = st.top() + word;
                    st.pop();
                }
                st.pop();
                
                string number = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    number = st.top() + number;
                    st.pop();
                }
                
                int times = stoi(number);
                string full = "";
                for(int t = 0; t < times; t++) {
                    full += word;
                }
                
                st.push(full);
            } else {
                st.push(string(1, s[i]));
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends