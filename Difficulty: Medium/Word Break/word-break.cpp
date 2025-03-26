//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(string &s, int idx, unordered_set<string>& dict, unordered_map<int, bool> &memo) {
        if(idx == s.size())
            return true;
        
        if(memo.find(idx) != memo.end())
            return memo[idx];
        
        for(string str : dict) {
            int len = str.size();
            if(s.size() < idx + len) continue;
            
            string sub = s.substr(idx, len);
            
            if(str == sub) {
                if(solve(s, idx + len, dict, memo))
                    return memo[idx] = true;
            }
        }
        
        return memo[idx] = false;
    }
    
    bool wordBreak(string &s, vector<string> &dic) {
        unordered_set<string> dict(dic.begin(), dic.end());
        unordered_map<int, bool> memo;
        
        return solve(s, 0, dict, memo);
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends