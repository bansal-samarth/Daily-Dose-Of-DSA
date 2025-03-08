//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        
        for(string word : words) {
            for(char ch : word) {
                adj[ch] = unordered_set<char>();
                indegree[ch] = 0;
            }
        }
        
        for(int i = 0; i < words.size()-1; i++) {
            string a = words[i];
            string b = words[i+1];
            
            int len = min(a.size(), b.size());
            if(a.substr(0, len) == b.substr(0, len) && a.size() > b.size())
                return "";
            
            int k = 0;
            while(k < len) {
                if(a[k] != b[k]) {
                    if (adj[a[k]].find(b[k]) == adj[a[k]].end()) {
                        adj[a[k]].insert(b[k]);
                        indegree[b[k]]++;  // Increase indegree for b[k]
                    }
                    break;
                }
                k++;
            }
        }
        
        queue<char> q;
        for(auto i : indegree) {
            if(i.second == 0)
                q.push(i.first);
        }
        
        string res = "";
        while(q.size()) {
            char ch = q.front();
            q.pop();
            
            res += ch;
            
            for(char letter : adj[ch]) {
                if(--indegree[letter] == 0)
                    q.push(letter);
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends