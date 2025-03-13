//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string smallestWindow(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(n < m) return "";
        
        unordered_map<char, int> map;
        for(char ch : s2)
            map[ch]++;
        
        int count = m;
        int mini = INT_MAX;
        int left = 0;
        int start = 0;
        
        for(int right = 0; right < n; right++) {
            char letter = s1[right];
            
            if(map[letter]-- >= 1)
                count--;
            
            if(count == 0) {
                while(left <= right && count == 0) {
                    if(mini > right - left + 1) {
                        mini = right - left + 1;
                        start = left;
                    }
                    map[s1[left]]++;
                    if(map[s1[left]] > 0)
                        count++;
                    left++;
                }
            }
        }
        
        return mini == INT_MAX ? "" : s1.substr(start, mini);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends